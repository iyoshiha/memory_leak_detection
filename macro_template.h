/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_template.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyoshiha <iyoshiha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:11:05 by iyoshiha          #+#    #+#             */
/*   Updated: 2021/11/29 19:13:44 by iyoshiha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*********************
how to use this macro
*********************

you need to just copy and paste in the files on which
you use malloc and free.

*/
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
