#include "SJF.h"

process_t *SJF(process_t *process, size_t qtd)
{
    for (size_t i = 0; i < qtd; i++)
    {
        for (size_t j = 0; j < qtd-1; j++)
        {
            if(process[j].atime > process[j+1].atime)
            {
                process[j].atime = process[j+1].atime;
                uint32_t tmp = process[j].atime;
                process[j+1].atime = tmp;

            }
        }   
    }
    return process;
}