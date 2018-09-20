/*
 * main.c
 *
 *  Created on: Oct 16, 2014
 *      Author: tangzhihua
 */
#include <zdb.h>
#include "global.h"
#include "lib/unp.h"
#include "utils/threadpool.h"
#include <signal.h>
#include "types.h"
static void print_a_property(a_queue * queue);
void * signal_thread(void *arg);
sigset_t ma;

int ain(int ar, char ** argv)
{

	pthread_t tid;
	int err;

	struct sigaction sa;
	//屏蔽进程信号
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = SIG_IGN;
	if (sigaction(SIGPIPE, &sa, NULL) < 0)
	{
		err_sys("sigaction failed");
	}

	//屏蔽线程信号
	sigemptyset(&mask);
	sigaddset(&mask, SIGHUP);
	sigaddset(&mask, SIGTERM);
	if ((err = pthread_sigmask(SIG_BLOCK, &mask, NULL) != 0))
	{
		err_sys("pthread_sigmask failed");
	}
	if ((err = pthread_create(&tid, NULL, signal_thread, NULL) != 0))
	{
		err_quit("can't create thread");
	}
//	URL_T url = URL_new("mysql://localhost/mysql?user=root&password=123456");
//	 pool = ConnectionPool_new(url); //新建一个连接池结构体，并分配内存
//	ConnectionPool_start(pool); //初始化连接池（建立连接），调用fillpool
//	Connection_T con = ConnectionPool_getConnection(pool); //从连接池获取一个连接
//		ResultSet_T result = Connection_executeQuery(con,
//				"select host,user, password from user"); //使用此连接执行查询数据操作

	FILE *fp = fopen("/home/test/config/config.txt", "r");
	if (fp == NULL)
	{
		printf("open a.txt file failed!\n");
		exit(0);
	}
	while (fscanf(fp, "%d", &user_num))
	{
//		total[label] += value;
		if (feof(fp))
		{
			break;
		}
	}

//	user_num = 2000;
//	fprintf(fp,"%s=%s\n",items[i].key, items[i].value);

	init();
	pool = init_connection_pool(
			"mysql://172.23.22.27/gzb?user=root&password=HPflow123");
	pool_init(MAX_THREAD_NUM);

//	log_pool = init_connection_pool("mysql://localhost/userlog?user=root&password=123456");
//	pool_init(MAX_THREAD_NUM);
	//print_a_property(offline_queque);
	//print_a_property(browse_queue);
	pthread_t *a = calloc(1, sizeof(pthread_t));
	pthread_t *b = calloc(1, sizeof(pthread_t));
	pthread_create(a, NULL, scan_routine, offline_queue);
	pthread_create(b, NULL, scan_routine, browse_queue);

	for (;;)
	{

	}
	return 0;
}

/*
 * 初始化信号
 */
/*
 int ntg_init_signals(void) {
 ngx_signal_t *sig;
 struct sigaction sa;

 for (sig = signals; sig->signo != 0; sig++) {
 ngx_memzero(&sa, sizeof(struct sigaction));
 sa.sa_handler = sig->handler;
 sigemptyset(&sa.sa_mask);
 if (sigaction(sig->signo, &sa, NULL) == -1) {
 ngx_log_error(NGX_LOG_EMERG, log, ngx_errno, "sigaction(%s) failed",
 sig->signame);
 return NGX_ERROR;
 }
 }

 return NGX_OK;
 }
 */
/*
 * signal_thread信号处理线程
 *
 */
void * signal_thread(void *arg)
{
	printf("signal thread have already start\n");
	fflush(NULL);
	int err, signo;
	for (;;)
	{
		err = sigwait(&mask, &signo);
		printf("singo --->%d\n", signo);
		if (err != 0)
			err_quit("sigwait failed:%s", strerror(err));
		switch (signo)
		{
		case SIGHUP:
			break;
		case SIGTERM:
			break;
		default:
			err_quit("unexpected signal %d", signo);
		}
	}
	return 0;
}

void print_a_property(a_queue * queue)
{
	printf("%u,\t%d,\t%d, \t%d, \t%d\n", (unsigned int) queue->head.next,
			queue->cycle, queue->temp_value, queue->shutdown, queue->cur_size);
	return;
}
