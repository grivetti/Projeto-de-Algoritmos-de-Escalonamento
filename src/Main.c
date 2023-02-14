#include "lib.h"
#include "RR.h"
#include "EDF.h"
#include "SJF.h"

size_t fill_qtd(void)
{
    size_t qtd = 1;
    puts("Digit the number of the processes: ");
    scanf("%zd", &qtd);
    return qtd;
}

process_t *fill_process(size_t qtd)
{

    process_t *process = init_process(0, 0, 0, qtd);
    for (size_t i = 0; i < qtd; i++)
    {
        uint32_t bt = 0, p = 0, at = 0;
        printf("Digit the number of at and bt of process number %zu:\n", i);
        scanf("%u %u %u", &at, &bt, &p);
        process[i] = (process_t){at, bt, p, i};
    }
    return process;
}

void Start(void)
{
    uint8_t algol = 0;
    puts("RR -> 0");
    puts("EDF-> 1");
    puts("SJF-> 2");
    puts("FCFS -> 3");
    puts("Digit the number of the ALGOL: ");
    scanf("%d", &algol);
    if (algol >= 4)
    {
        fprintf(stderr, "[ERROR] ALGOL NUMBER MUST BE LESS THAN 3\n");
        Start();
    }
    size_t qtd = fill_qtd();
    process_t *process = fill_process(qtd);
    uint32_t *wt  = NULL;
    uint32_t *tat = NULL;
    uint32_t quantum = 0;
    switch (algol)
    {
    case 0:
        puts("Digit the number of the quantum: ");
        scanf("%u", &quantum);
        wt = round_robin(process, qtd, quantum);
        tat = turn_around_time(process, wt, qtd);
        break;
    case 1:
        EDF(process, qtd);
        wt = waiting_process(process, qtd);
        tat = turn_around_time(process, wt, qtd);
        break;
    case 2:
        SJF(process, qtd);
        wt = waiting_process(process, qtd);
        tat = turn_around_time(process, wt, qtd);
        break;
    case 3:
        wt = waiting_process(process, qtd);
        tat = turn_around_time(process, wt, qtd);
        for (size_t i = 0; i < qtd; i++)
        {
            tat[i] = process[i].atime;
        }
        break;
    }

    double avg_tat = avarage_tat(tat, qtd);
    double avg_wt = avarage_wt(wt, qtd);
    puts("###########");
    for (size_t i = 0; i < qtd; i++)
    {
        printf("ID=%u\nWT=%u\nTAT=%u\n", wt[i], tat[i]);
        puts("###########");
    }
    printf("AVG_TAT=%.2f\nAVG_WT=%.2f\n", avg_tat, avg_wt);
    free(tat);
    free(wt);
    free(process);
}

int main(int argc, char const *argv[])
{
    Start();
    return 0;
}
