#include "LinkedList.h"
#include "stdlib.h"


Link createList(void *firstObject){
    Link link;
    link.data = firstObject;
    link.next = NULL;

    return link;
}

void insertLink(Link *startList, Link *insert){
    while((*startList).next != NULL){
        startList = (*startList).next;
    }
    (*startList).next = insert;
}

