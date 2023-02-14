#ifndef __LIB_H__
#define __LIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct process_t
{
    uint32_t atime;
    uint32_t btime;
    uint32_t p;
    uint8_t id;
}process_t;


process_t  *init_process(uint8_t id, uint32_t atime,uint32_t btime, size_t qtd);
uint32_t   *turn_around_time(process_t *process, uint32_t *wt, size_t qtd);
uint32_t   *waiting_process(process_t *process,size_t qtd);
double     avarage_tat(uint32_t *tat, size_t qtd);
double     avarage_wt(uint32_t *wt, size_t qtd);

#endif