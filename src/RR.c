#include "RR.h"

uint32_t  *round_robin(process_t *process, size_t qtd, uint32_t quantum)
{
    uint32_t *bt = calloc(qtd,sizeof(uint32_t));
    uint32_t *wt = calloc(qtd,sizeof(uint32_t));
    for (size_t i = 0; i < qtd; i++)
        bt[i] = process[i].btime;
    

    uint32_t time = 0;
    uint32_t overhead = 1;
    while (true)
    {
        bool finish = true;
        for (size_t i = 0; i < qtd; i++)
        {
            time += overhead;
            if(bt[i] > quantum){
                finish = false;
                time += quantum;
                bt[i] -= quantum;
            }else{
                time += bt[i];
                wt[i] = time - process[i].btime;
                bt[i] = 0;
            }
        }
        if(finish)
            break;        
    }
    free(bt);
    return wt;
}

