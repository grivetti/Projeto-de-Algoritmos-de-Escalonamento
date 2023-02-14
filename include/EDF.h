#ifndef __EDF_H__
#define __EDF_H__

#include "lib.h"

uint32_t hyper_period(process_t *process,size_t qtd);
int32_t less_deadline(process_t *process,size_t qtd, uint32_t *deadlines);
void EDF(process_t *process,int qtd);


#endif