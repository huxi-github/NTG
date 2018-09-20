#include    "unp.h"
#include    <stdarg.h>        /* ANSI C header file */
int		daemon_proc;		/* set nonzero by daemon_init() */

static void	err_doit(int, int, const char *,  va_list ap);


void err_ret(const char *fmt, ...);
void err_sys(const char *fmt, ...);


void err_dump(const char *fmt, ...);


void err_msg(const char *fmt, ...)
;

/* Fatal error unrelated to system call
 * Print message and terminate */

void err_quit(const char *fmt, ...)
;

/* Print message and return to caller
 * Caller specifies "errnoflag" and "level" */

static void err_doit(int errnoflag, int level, const char *fmt, va_list ap)
;
