/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_check.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:53:27 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/11/29 19:03:13 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MEM_CHECK_H
#define MEM_CHECK_H

#include <stdlib.h>

// max number of memory we can check
#define MAX_NUM 500

// memory table
typedef struct s_table{
    void *ptr;
    size_t size;
    const char *file;
    unsigned int line;
} t_table;

void mem_table_init(void);
void *mem_malloc(size_t, const char*, unsigned int);
void mem_free(void*);
void leak_check(void);

#endif
