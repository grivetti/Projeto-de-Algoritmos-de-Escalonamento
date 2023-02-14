#include "EDF.h"

uint32_t hyper_period(process_t *process, size_t qtd)
{
    uint32_t tmp = 0;
    for (size_t i = 0; i < qtd; i++)
    {
        tmp += process[i].btime;
    }
    return tmp;
}

int32_t less_deadline(process_t *process, size_t qtd, uint32_t *deadlines)
{
    uint32_t best = 10000;
    int32_t choosen = -1;
    for (size_t i = 0; i < qtd; i++)
    {
        if (deadlines[i] < best)
        {
            best = deadlines[i];
            choosen = i;
        }
    }
    return choosen;
}

void EDF(process_t *process, int qtd)
{
    int32_t clock = 0;
    uint32_t *deadlines = (uint32_t *)calloc(qtd, sizeof(uint32_t));
    for (size_t i = 0; i < qtd; i++)
        deadlines[i] = process[i].btime;
    uint32_t *periods = (uint32_t *)calloc(qtd, sizeof(uint32_t));
    for (size_t i = 0; i < qtd; i++)
        periods[i] = process[i].p;
    uint32_t *counter = (uint32_t *)calloc(qtd, sizeof(uint32_t));
    while (true)
    {
        int32_t best = less_deadline(process, qtd, deadlines);
        printf("Choosen Process %d\n", best);
        if (periods[best] >= clock)
        {
            clock += process[best].atime;
            printf("Executing process %d...\n", best);
            printf("Clock=%d\n", clock);
            printf("Burst Time of choosen process of id %d=%d\n", best, process[best].id);

            printf("Previous Deadline %d\n", deadlines[best]);
            deadlines[best] += process[best].p;
            printf("After Deadline %d\n", deadlines[best]);

            printf("Previous Period %d\n", periods[best]);
            periods[best] += process[best].p;
            printf("After Period %d\n", periods[best]);
            counter[best]++;
        }
        if (clock >= 20)
            break;
    }
    for (size_t i = 0; i < qtd; i++)
        printf("The Process %d executed %d times", i, counter[i]);
    free(counter);
    free(periods);
    free(deadlines);
}
