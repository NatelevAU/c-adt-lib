#pragma once
#include <stdlib.h>



typedef struct singleContainer *SingleContainer;
typedef void* Pointer;



Pointer newSingleContainer();

void deleteSingleContainer(SingleContainer container);
