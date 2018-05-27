/*
 * @file lwlog.h
 * @auther Akagi201
 *
 * @date 2014/11/30
 */

#ifndef LWLOG_H_
#define LWLOG_H_ (1)

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifndef LOG_LEVEL
#define LOG_LEVEL (7)
#endif

#ifndef LOG_COLOR
#define LOG_COLOR (1)
#endif

// log levels the same as syslog
#define EMERG (0)
#define ALERT (1)
#define CRIT (2)
#define ERR (3)
#define WARNING (4)
#define NOTICE (5)
#define INFO (6)
#define DEBUG (7)

// colors
#define NONE                 "\033[0m"
#define BLACK                "\033[0;30m"
#define L_BLACK              "\033[1;30m"
#define RED                  "\033[0;31m"
#define L_RED                "\033[1;31m"
#define GREEN                "\033[0;32m"
#define L_GREEN              "\033[1;32m"
#define BROWN                "\033[0;33m"
#define YELLOW               "\033[1;33m"
#define BLUE                 "\033[0;34m"
#define L_BLUE               "\033[1;34m"
#define PURPLE               "\033[0;35m"
#define L_PURPLE             "\033[1;35m"
#define CYAN                 "\033[0;36m"
#define L_CYAN               "\033[1;36m"
#define GRAY                 "\033[0;37m"
#define WHITE                "\033[1;37m"

#define BOLD                 "\033[1m"
#define UNDERLINE            "\033[4m"
#define BLINK                "\033[5m"
#define REVERSE              "\033[7m"
#define HIDE                 "\033[8m"
#define CLEAR                "\033[2J"
#define CLRLINE              "\r\033[K" //or "\e[1K\r"

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

/* safe readable version of errno */
#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define lwlog_emerg(M, ...)   fprintf(stderr, RED    "[EMERG]   " "%s (%s:%d) " NONE M YELLOW " errno: %s\n" NONE, __func__, __FILE__, __LINE__, ##__VA_ARGS__, clean_errno());
#define lwlog_alert(M, ...)   fprintf(stderr, PURPLE "[ALERT]   " "%s (%s:%d) " NONE M YELLOW " errno: %s\n" NONE, __func__, __FILE__, __LINE__, ##__VA_ARGS__, clean_errno());
#define lwlog_crit(M, ...)    fprintf(stderr, YELLOW "[CRIT]    " "%s (%s:%d) " NONE M YELLOW " errno: %s\n" NONE, __func__, __FILE__, __LINE__, ##__VA_ARGS__, clean_errno());
#define lwlog_err(M, ...)     fprintf(stderr, BROWN  "[ERR]     " "%s (%s:%d) " NONE M YELLOW " errno: %s\n" NONE, __func__, __FILE__, __LINE__, ##__VA_ARGS__, clean_errno());
#define lwlog_warning(M, ...) fprintf(stderr, BLUE   "[WARNING] " "%s (%s:%d) " NONE M YELLOW " errno: %s\n" NONE, __func__, __FILE__, __LINE__, ##__VA_ARGS__, clean_errno());
#define lwlog_notice(M, ...)  fprintf(stderr, CYAN   "[NOTICE]  " "%s (%s:%d) " NONE M YELLOW " errno: %s\n" NONE, __func__, __FILE__, __LINE__, ##__VA_ARGS__, clean_errno());
#define lwlog_info(M, ...)    fprintf(stderr, GREEN  "[INFO]    " "%s (%s:%d) " NONE M "\n", __func__, __FILE__, __LINE__, ##__VA_ARGS__);
#define lwlog_debug(M, ...)   fprintf(stderr, GRAY   "[DEBUG]   " "%s (%s:%d) " NONE M "\n", __func__, __FILE__, __LINE__, ##__VA_ARGS__);

/* LOG_LEVEL controls */
#if LOG_LEVEL < DEBUG
#undef lwlog_debug
#define lwlog_debug(M, ...) do{}while(0)
#endif

#if LOG_LEVEL < INFO
#undef lwlog_info
#define lwlog_info(M, ...) do{}while(0)
#endif

#if LOG_LEVEL < NOTICE
#undef lwlog_notice
#define lwlog_notice(M, ...) do{}while(0)
#endif

#if LOG_LEVEL < WARNING
#undef lwlog_warning
#define lwlog_warning(M, ...) do{}while(0)
#endif

#if LOG_LEVEL < ERR
#undef lwlog_err
#define lwlog_err(M, ...) do{}while(0)
#endif

#if LOG_LEVEL < CRIT
#undef lwlog_crit
#define lwlog_crit(M, ...) do{}while(0)
#endif

#if LOG_LEVEL < ALERT
#undef lwlog_alert
#define lwlog_alert(M, ...) do{}while(0)
#endif

#if LOG_LEVEL < EMERG
#undef lwlog_emerg
#define lwlog_emerg(M, ...) do{}while(0)
#endif

/* LOG_COLOR controls */
#if LOG_COLOR < 1

#undef NONE
#define NONE

#undef RED
#define RED

#undef PURPLE
#define PURPLE

#undef YELLOW
#define YELLOW

#undef BROWN
#define BROWN

#undef GREEN
#define GREEN

#undef CYAN
#define CYAN

#undef BLUE
#define BLUE

#undef GRAY
#define GRAY

#endif

#endif // LWLOG_H_
