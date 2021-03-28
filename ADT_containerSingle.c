#include "ADT_containerSingle.h"



struct singleContainer {
    Pointer relation;
    Pointer value;
};



Pointer newSingleContainer() {
    SingleContainer container = malloc(sizeof(struct singleContainer));
    container->relation = NULL;
    container->value = NULL;
    return container;
}

void deleteSingleContainer(SingleContainer container) {
    free(container);
}
