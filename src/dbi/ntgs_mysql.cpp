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
//MYSQL_RES *res_ptr;
//MYSQL_ROW sqlrow;
#define Con_T Connection_T

//static MYSQL_RES* excute_query(char * query);

static int get_page_id(Connection_T con, char * url);


/*
 * get_page_id 获取指定url的页面id
 */
static int get_page_id(Connection_T con, url_t * url) {
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

ConnectionPool_T init_connection_pool(const char *url_str) {
	ConnectionPool_T pool1 = NULL;
	URL_T url = URL_new(url_str);
	pool1 = ConnectionPool_new(url); //新建一个连接池结构体，并分配内存
	ConnectionPool_start(pool1);
	return pool1;
}

void free_connection_pool(ConnectionPool_T pool) {
	URL_T url = ConnectionPool_getURL(pool);
	ConnectionPool_free(&pool);
	URL_free(&url);
}

int add_page(Connection_T con, page_t * page) {
        int res, id = -1;
        ResultSet_T rst;

        id = get_page_id(con, page->url);  //是否已经存在
        if (id > 0)
            return id;
        Connection_execute(con, "insert  into page_t value(null, '%s')",url_to_str(page->url));
    /*
     * 如果resource不为空，添加到数据库
     */
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
			ResultSet_getColumnSize(rst, 1));
    
	page->result_set = Connection_executeQuery(con,
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


///*
// * database_init   数据库的初始化
// */
//int database_init(mysql_t * mysql, char *name, char * password, char *database) {
//    //    if (mysql->dbconnected)
//    //        return 1;
//    if (mysql == NULL)
//        mysql = (mysql_t *)Calloc(1, sizeof(mysql_t));
//
//    mysql_library_init(0, NULL, NULL);
//
//    mysql_init(&mysql->conn);
//    pthread_mutex_init(&mysql->mysql_lock, 0);
//    pthread_cond_init(&mysql->mysql_cond, 0);
//
//    if (!mysql_real_connect(&mysql->conn, "localhost", name, password, "foo",
//            0, NULL, 0)) {
//        fprintf(stderr, "Connection failed\n");
//        if (mysql_errno(&mysql->conn)) {
//            fprintf(stderr, "Connection error %d:%s\n",
//                    mysql_errno(&mysql->conn), mysql_error(&mysql->conn));
//        }
//        return -1;
//    }
//    printf("Connection success\n");
//    return 0;
//}/*database_init*/

//void database_free() {
//    mysql_close(&db->conn);
//}/*database_free*/

//int add_page(page_t * page) {
//    MYSQL_RES *res_ptr;
//    MYSQL_ROW mysqlrow;
//    int res, id = -1;
//    char qs[384];
//    char es[256];
//
//    con=init_connection_pool(<#const char *url_str#>)
//    id = get_page_id(con,page->url);
//    if (id > 0)
//        return id;
////    mysql_real_escape_string(&db->conn, es, page->url, strlen(url_to_str(page->url)));
//    sprintf(qs, "insert  into page_t value(null, '%s')", es);
//    res = mysql_query(&db->conn, qs);
//    if(res) return id;
//    id = get_page_id(con,page->url);
//    /*
//     * 如果resource不为空，添加到数据库
//     */
//    return 0;
//}
//int delete_page_of_id(int page_id);
//int delete_page_of_url(char *url);
//int get_page(page_t* page);

/**  //不用zdb 直接连接
static MYSQL_RES* excute_query(char * query) {
	int res;
	MYSQL_RES * res_ptr = NULL;
//    if (!db->conn)
        return res_ptr;
	pthread_mutex_lock(&db->mysql_lock);
	res = mysql_query(&db->conn, query);
	if (res) {
		fprintf(stderr, "select error:%s\n", mysql_error(&db->conn));
		pthread_mutex_unlock(&db->mysql_lock);
		return res_ptr;
	}
	res_ptr = mysql_store_result(&db->conn);
	pthread_mutex_unlock(&db->mysql_lock);
	return res_ptr;
}

static int excute_update(char *update) {
	MYSQL_RES* res_ptr;
	int rows = -1;
	int res;
	res = mysql_query(&db->conn, update);
	if(res) {
		fprintf(stderr, "select error:%s\n", mysql_error(&db->conn));
		return rows;
	}
	res_ptr = excute_query("SELECT ROW_COUNT()");

	return rows;
}
 **/

//int add_resource(int page_id, char *rs_path);
//int delete_resource(char *rs_path);
//void* get_resource(int page_id);

