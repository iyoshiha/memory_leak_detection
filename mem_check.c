/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:53:44 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/11/29 23:01:16 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mem_check.h"

/*
max number of table
*/
#define N 500

/*
table for memory
*/
t_table mem_table[N];

/*
init_table
*/
void mem_table_init(void){
    int i;

    /*
	init table
	*/
    for(i = 0; i < N; i++){
        mem_table[i].ptr = NULL;
        mem_table[i].size = 0;
        mem_table[i].file = NULL;
        mem_table[i].line = 0;
    }
}

/*
get data to table
*/
void *mem_malloc(size_t size, const char *file, unsigned int line){
    int i = 0;
    void *ptr = NULL;

    ptr = malloc(size);

    /*
	if its fale, we dont put data to table
	*/
    if(ptr == NULL){
        return NULL;
    }

    for(i = 0; i < N; i++){
        /*
		seek arry which doesnt have data
		*/
        if(mem_table[i].ptr == NULL){
            mem_table[i].ptr = ptr;
            mem_table[i].size = size;
            mem_table[i].file = file;
            mem_table[i].line = line;
            break;
        }
    }

    /*
	return pointer which was got by malloc
	*/
    return ptr;
}

/*
free memory and delete data from table
*/
void mem_free(void *ptr){
    int i = 0;

    for(i = 0; i < N; i++){
        /*
		seek address we want to free
		*/
        if(mem_table[i].ptr == ptr){
			// delete data
            mem_table[i].ptr = NULL;
            mem_table[i].size = 0;
            mem_table[i].file = NULL;
            mem_table[i].line = 0;
            break;
        }
    }

	// free memroy
    free(ptr);
}

/*
display memory we didnt free yet
*/
void leak_check(void){
    int i = 0;

    for(i = 0; i < N; i++){
        /*
		seek address that exists on table which means wasnt freed
		*/
        if(mem_table[i].ptr != NULL){
            /*
			dispaly data you didn't free
			*/
			puts("**** **** detected leak! **** ****");
            printf("address	: %p\n", mem_table[i].ptr);
            printf("size	:%u\n", (unsigned int)mem_table[i].size);
            printf("where	:%s:%u\n", mem_table[i].file, mem_table[i].line);
			puts("");
        }
    }
}
