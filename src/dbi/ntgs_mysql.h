/*
 * ntgs_mysql.h
 *
 *  Created on: Dec 8, 2014
 *      Author: tangzhihua
 */

#ifndef NTGS_MYSQL_H_
#define NTGS_MYSQL_H_
#include <mysql.h>
#include <pthread.h>
#include <zdb.h>
#include "../global.h"
#include "../utils/url.h"

typedef struct page_st {  //包含一个网页的url和所有的file文件名
	url_t* url;/*页面的url*/
	ResultSet_T files_result_set;/*页面内嵌的资源*/
}page_t;





#ifdef __APPLE__
#pragma mark 虚拟用户表相关 数据库操作
#endif
extern void insert_wait_user(Connection_T con, int num, int off_num , int browse_num);
extern void insert_user(Connection_T con, int num );
extern void insert_log(Connection_T con,  void *user, struct timeval *tstart,struct timeval *tend, long count);

#ifdef __APPLE__
#pragma mark connection_pool 相关 连接/释放
#endif
extern ConnectionPool_T init_connection_pool(const char *url_str);
extern void free_connection_pool(ConnectionPool_T pool);

#ifdef __APPLE__
#pragma mark 目标资源相关 数据库操作
#endif
int add_page(Connection_T con, page_t * page);  //程序中没有使用该接口
extern page_t * get_page(Connection_T con, int index);
extern void free_page(page_t * page);



#endif /* NTGS_MYSQL_H_ */
