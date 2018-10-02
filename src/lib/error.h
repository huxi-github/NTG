#include    "unp.h"
#include    <stdarg.h>        /* ANSI C header file */
extern int	daemon_proc;		/* set nonzero by daemon_init() */



void err_ret(const char *fmt, ...);
void err_sys(const char *fmt, ...);


void err_dump(const char *fmt, ...);


void err_msg(const char *fmt, ...);

/* Fatal error unrelated to system call
 * Print message and terminate */

void err_quit(const char *fmt, ...);


