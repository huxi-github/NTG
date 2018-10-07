/*
 * global.h
 *
 *  Created on: Oct 16, 2014
 *      Author: tangzhihua
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <unistd.h>
#include <time.h>
#include <sys/time.h>
//#include <ConnectionPool.h> 
#include <pthread.h>
#include <zdb.h>
#include "lib/unp.h"
#include "web/web.h"
#include <stddef.h>
#include "types.h"
#include "dbi/ntgs_mysql.h"


#define OFF_LINE_QUEUE_T 1
#define BROWSER_QUEUE_T  0

extern int user_num;

/*
 * 数据库 连接池
 */
extern ConnectionPool_T pool;
extern ConnectionPool_T log_pool;


//#pragma mark 用户的抽象
typedef struct user user_t;

struct user
{
	int id; /*用户ID*/
	int type; /*用户的类型**/
	int state; /*用户的状态**/
	char url[URL_SIZE]; /*用户当前的url*/
	int page_id;
	int time; /*用户进入下一状态的时间*/
	struct user_ops *ops; /*用户函数操作集**/
	struct user *next; /*下一个用户指针*/
};

/*
 * ops 结构是用户函数操作集的通用结构
 */
struct user_ops
{
	int (*builed)(const char * host);/*消息构建函数指针 */
	void (*request)(int sockfd, char *msg, size_t msg_size); /*请求函数指针*/
	ssize_t (*receive)(int sockfd, char *buf, size_t buf_size);/*接收函数指针*/
	void (*behavior)(void * user); /*用户行为函数指针*/
	void * (*error)(void *); /*错误处理函数指针*/
};
/*
 * A队列
 */
typedef struct
{
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	user_t *head;
	user_t *tail;
	user_t *tag_user;/*队列中的标签用户*/
	int cur_size;/*当前队列的大小**/
	int type;
	int temp_value;/*临时的time值*/
	int cycle;/*队列扫描的周期，单位为秒*/
	int shutdown;/*队列销毁的标志*/
} a_queue;

/*
 * B队列
 * 线程池结构
 * 等待发送请求的队列
 */
typedef struct
{
	pthread_mutex_t mutex;
	pthread_cond_t ready;
	user_t *head;
	user_t *tail;
	int cur_size;/*当前队列的大小*/
	/*是否销毁线程池*/
	int shutdown;
	pthread_t *threadid;
	/*线程池中允许的活动线程数目*/
	int max_thread_num;
} b_queue;

//#pragma mark 定义全局队列指针*/
extern a_queue *offline_queue;/*离线队列*/
extern a_queue *browse_queue;/*浏览队列*/
extern b_queue *pool_queue;/*线程池队列*/

/*统计结构*/
//struct statistics{
//	uint64_t total_received;
//	uint64_t total_send;
//	double
//
//};
typedef struct parser_common parser_t;
struct parser_common
{
	//文件类型
	uint32_t type :15;
	//重新建立链接标志
	uint32_t isconnect :1;
	// buffer中的 位置  index   【很少使用】
	uint32_t pos :16;
	// 指向connextion中的buffer  //相应全文 的头
	char *buffer;
	// 解析到的位置
	char *posParse;  // 解析的一行 的 尾部字符  \n\r之前的那个字符
	//感兴趣区域
	char *area;		// 解析的一行 的第一个字符
	/*还应该包含一些处理的函数指针*/
	int (*parse_enter)(void* parser, int size);
};

extern void user_quene_init(void);
extern void insert_queue(void * queue, int type, user_t* user);
extern void set_user_property(user_t *user, int p_type, void * value);
extern void * scan_routine(void *arg);  //却是在 scanroutine.cpp 定义实现

#endif /* GLOBAL_H_ */
