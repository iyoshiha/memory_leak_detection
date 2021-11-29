#include <stdio.h>
// this is just definition of structure gfunc tyep.
// this is NOT global declalation!!

int i = 10;

typedef struct gfunc
{
	int global_int;

}			tfunc;
// tfunc gs; // THIS IS the declalation of global structure gfunc type variable!!
	// gs.global_int = 100; // why I cant assgine val to this member.
void printg(void)
{
	printf("*******\nthis is global g \n%d\n*******\n", gs.global_int);

	gs.global_int += 10;
}
