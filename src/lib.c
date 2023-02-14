#include "lib.h"

process_t  *init_process(uint8_t id, uint32_t atime,uint32_t btime, size_t qtd)
{
    process_t *process = (process_t*) calloc(qtd,sizeof(process_t));
    process->atime = atime;
    process->btime = btime;
    process->id = id;
    return process;
}

uint32_t   *waiting_process(process_t *process, size_t qtd)
{
    uint32_t *service_time = (uint32_t*)calloc(qtd,sizeof(uint32_t));
    service_time[0] = 0;
    uint32_t *wt = (uint32_t*)calloc(qtd,sizeof(uint32_t));
    for (size_t i = 1; i < qtd; i++)
    {
        wt[i] = service_time[i-1] + process[i-1].atime;
        if(wt[i] < 0)
            wt[i] = 0;
    }
    return wt;
}


uint32_t  *turn_around_time(process_t *process, uint32_t *wt, size_t qtd)
{
    uint32_t *tat = (uint32_t*) calloc(qtd,sizeof(uint32_t));
    for (size_t i = 0; i < qtd; i++)
    {
        tat[i] = process[i].btime + wt[i];
    }
    return tat;
}


double avarage_tat(uint32_t *tat, size_t qtd)
{
    uint32_t turn_around = 0;
    for (size_t i = 0; i < qtd; i++)
    {
        turn_around += tat[i];
    }
    return (double)(turn_around/qtd);
}

double avarage_wt(uint32_t *wt, size_t qtd)
{
    uint32_t waiting_time = 0;
    for (size_t i = 0; i < qtd; i++)
    {
        waiting_time += wt[i];
    }
    return (double)(waiting_time/qtd);
}
