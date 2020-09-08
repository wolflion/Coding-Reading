// 程序清单9.3 位存取函数声明
// bit.h: 用于无符号整型的位函数
#ifndef BIT_H
#define BIT_H

#include <stdio.h>
#include <limits.h>

#define mask1(i)  (lu<<i)
#define mask0(i)  ~(lu<<i)

#define set(n,i)  ((n)|mask1(i))
#define reset(n,i)  ((n)&mask0(i))
#define toggle(n,i)  ((n)^mask1(i))
#define test(n,i)  !!((n)&mask1(i))

#define nbits(x) (sizeof(x)*CHAR_BIT)

unsigned fputb(unsigned, FILE *);
unsigned fgetb(FILE *);
unsigned count(unsigned);

#endif