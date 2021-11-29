#include <stdio.h>
// extern int global_int;
int i = 100;

typedef struct gfunc
{
	int global_int;
	int a;
	char c;

}			tfunc;
void printg(void);
// extern tfunc gs; // tfunc の定義がない。もしグローバルでメインで使用したいのならば、型の定義をしなければならない。
	tfunc gs = {100, 90, 80};

int main()
{
	int static num;
	printf("*******\nthis is in main \n%d\n%d\n%c\n*******\n", gs.global_int, gs.a, gs.c);
	printg();
	// printg();
	// printf("*******\nthis is in main \n%d\n*******\n", 9);
	return 0;
}
