#include <iostream>
#include <cstdio>
 
/**
 * 简单打印调试信息
 */
#define DEBUG_SWITCH        1
#ifdef    DEBUG_SWITCH
#define pr_debug(fmt,args...) printf(fmt, ##args)
#else
#define pr_debug(fmt,args...) /*do nothing */
#endif

/**
 * 错误信息打印
 * 自动打印发生错误时代码所在的位置
 */
#define     ERR_DEBUG_SWITCH        1
#ifdef    ERR_DEBUG_SWITCH
#define pr_err(fmt,args...) printf("\nFile:<%s> Fun:[%s] Line:%d\n "fmt, __FILE__, __FUNCTION__, __LINE__, ##args)
#else
#define pr_err(fmt,args...) /*do nothing */
#endif
int main() {
pr_err("ada");
return 0;
}
 
