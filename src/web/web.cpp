/*
 * web.c
 *
 *  Created on: Aug 26, 2014
 *      Author: tangzhihua
 */
#include <time.h> /*用到了time函数，所以要有这个头文件*/
#include "web.h"

//封装网页访问的基本操作

/*
 * web用户函数操作集
 */
//struct user_ops web_user_ops =
//{
//        .builed = web_initConnection,
//        .request = NULL,
//        .receive = web_receive_and_print,
//        .behavior =web_behavior,
//};  //写法二
struct user_ops web_user_ops ={web_initConnection,NULL,web_receive_and_print,web_behavior}; //等价

/*
 * web_initConnection() 与远程服务端建立web链接
 * 参数：[in]  url-->urlstr
 * 返回：[out] socket套接字
 */

int web_initConnection(const char * host)
{
	return (Tcp_connect(host, "80"));
}

void web_request(int sockfd, char *msg, size_t msg_size)
{
	Write(sockfd, msg, msg_size);
}

ssize_t web_receive_and_print(int sockfd, char *buf, size_t buf_size)
{
	ssize_t n;
	while ((n = read(sockfd, buf, buf_size)) > 0)
	{
		buf[n] = '\0';
		printf("%s\n", buf);
	}
	return n;
}

void web_behavior(void * u)
{
	/*初始化用户并加入队列*/
	user_t* user=(user_t*) u;
	srand((unsigned) time(NULL));     //time(NULL) 以当前时间-为随机数种子
	user->time = 1 + rand() % UM_TIME;/*生成[1,UM_TIME+1]间的随机数*/
	user->page_id = 1 + rand() % 2;  /*生成[1,3]间的随机数*/  // 访问的页面id
//    strncpy(user->url, url, strlen(url));
	snprintf(user->url, URL_SIZE,"%s","http://hongyan.cqupt.edu.cn/web/");  //红岩网校 的 地址（有效的）
}
