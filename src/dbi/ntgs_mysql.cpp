/*
 * ntgs_mysql.c
 *
 *  Created on: Dec 8, 2014
 *      Author: tangzhihua
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zdb.h"
#include "ntgs_mysql.h"
#include "time.h"
#include "zdb/Connection.h"
#include "../utils/url.h"

#define Con_T Connection_T

//内部方法（private）
static int get_page_id(Connection_T con, url_t * url) ;

ConnectionPool_T init_connection_pool(const char *url_str) {
	ConnectionPool_T pool = NULL;
	URL_T url = URL_new(url_str);
	pool = ConnectionPool_new(url); //新建一个连接池结构体，并分配内存
	ConnectionPool_start(pool);
	return pool;
}

void free_connection_pool(ConnectionPool_T pool) {
	URL_T url = ConnectionPool_getURL(pool);
	ConnectionPool_free(&pool);
	URL_free(&url);
}

int add_page(Connection_T con, page_t * page) {
        int id = -1;
        ResultSet_T rst;

        id = get_page_id(con, page->url);  //是否已经存在
        if (id > 0)
            return id;
        Connection_execute(con, "insert  into page_t value(null, '%s')",url_to_str(page->url));//添加到数据库
    return 0;
}

page_t * get_page(Connection_T con, int index) {
	page_t* page = NULL;
	ResultSet_T rst;
	page = (page_t*)Calloc(1, sizeof(page_t));

	rst = Connection_executeQuery(con, "select url from page_t where id = '%d'",  //page_t 表
			index);
	if (!ResultSet_next(rst))
		goto e_result_set;
	page->url = paser_url(ResultSet_getString(rst, 1),
			(int)ResultSet_getColumnSize(rst, 1));
    
	page->files_result_set = Connection_executeQuery(con,
			"select file_path from resource_t where page_id = '%d'", index);
	return page;

	e_result_set: free(page);
	return NULL;
}

void free_page(page_t * page) {
	if (page->url != NULL)
		free_url(page->url);
	free(page);
}

void insert_log(Connection_T con, void*u, struct timeval *tstart, struct timeval *tend,
		long count) {
	long usec;
	user_t* user;
	user = (user_t*) u;
	usec = (tend->tv_sec - tstart->tv_sec) * 1000000
			+ (tend->tv_usec - tstart->tv_usec);
	Connection_execute(con,
			"insert into log_t value(null, '%d','%d','%s','%ld.%ld','%ld',UNIX_TIMESTAMP())",
			user->id, user->type, user->url, usec / 1000, usec % 1000,
			count / 1024);
}

void insert_user(Connection_T con, int num) {
	Connection_execute(con,
			"insert into offusers_t value(null, '%d',UNIX_TIMESTAMP())", num);
}

void insert_wait_user(Connection_T con, int num, int off_num, int browse_num) {
	Connection_execute(con,
			"insert into users_t value(null, '%d', '%d', '%d', '%d',UNIX_TIMESTAMP())",
			num, off_num, num - off_num, num - off_num - browse_num);
}

#pragma mark - 内部函数实现
//get_page_id 获取指定url的w网页 id 数据库中的序号
int get_page_id(Connection_T con, url_t * url) {
    int p_id = -1;
    ResultSet_T rst;
    char *urlstr=url_to_str(url);
    
    rst = Connection_executeQuery(con, "select id from page_t where url = '%s'",
                                  urlstr);
    if (ResultSet_next(rst)) {
        p_id = ResultSet_getInt(rst, 1);
        return p_id;
    }
    return p_id;
}
