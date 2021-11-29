#include <stdio.h>
#include <stdlib.h>
#define LEAK_DETECT
#ifdef LEAK_DETECT
#include "mem_check.h"
#define init() mem_table_init()
#define malloc(s) mem_malloc(s, __FILE__, __LINE__)
#define free mem_free
#define check() leak_check()
#else
#define init()	mem_check_init()
#define check() leak_check()
#endif

int main(void){
    int *p[8];
	// int ppp = 10;

    /* メモリ管理配列の初期化 */
   //  init();

    /* メモリの確保 */
    p[0] = (int*)malloc(sizeof(int));
    p[1] = (int*)malloc(sizeof(int));
    p[2] = (int*)malloc(sizeof(int));
    p[3] = (int*)malloc(sizeof(int));
    p[4] = (int*)malloc(sizeof(int));
    p[5] = (int*)malloc(sizeof(int));
    p[6] = (int*)malloc(sizeof(int));
    p[7] = (int*)malloc(sizeof(int));

    /* メモリの解放 */
    free(p[4]);
    free(p[7]);
	// p[0] = &ppp;

    /* メモリの解放忘れを表示 */
	 // leak_check();
    return 0;
}
