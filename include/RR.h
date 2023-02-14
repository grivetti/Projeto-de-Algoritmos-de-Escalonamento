#ifndef __RR_H__
#define __RR_H__

#include "lib.h"

uint32_t  *round_robin(process_t *process, size_t qtd, uint32_t quantum);

#endif