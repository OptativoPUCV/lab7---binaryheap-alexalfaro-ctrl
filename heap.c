#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if (pq!=NULL&&pq->size>0){
    return pq->heapArray[0].data;
    
  }
    return NULL;
}


/* Implemente la función `void heap_push(Heap* pq, void* data, int p)`. Esta función inserta un nuevo dato con prioridad `p` en el montículo. Si no recuerda como insertar datos en el montículo puede ver las [diapositivas](https://docs.google.com/presentation/d/1ZjXWMf6g05WdICqvno_oyRvorjAThABgbRGbEqc7mYU/edit#slide=id.g55ac49ed61_0_167).
*/

void swap(heapElem* x, heapElem* y) {
    heapElem temp = *x;
    *x = *y;
    *y = temp;
}

void heap_push(Heap* pq, void* data, int priority){
  if(pq!=NULL&&data!=NULL&&priority<0){
    heapElem nuevonodo;
    nuevonodo.data=data;
    nuevonodo.priority=priority;
    if(pq->capac==pq->size){
      pq->capac=pq->capac*2+1;
      pq->heapArray=realloc(pq->heapArray,pq->capac*sizeof(heapElem));
    }
    int i;
    i=pq->size;
    pq->heapArray[i]=nuevonodo;
    pq->size++;
    while(i!=0 && pq->heapArray[(i - 1) / 2].priority < pq->heapArray[i].priority){
      swap(&(pq->heapArray[i]),&(pq->heapArray[(i - 1) / 2]));
      i=(i - 1) / 2;
    }
    
  }

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap *monticulo=(Heap*)malloc(sizeof(Heap));
  monticulo->capac=3;
  monticulo->size=0;
  monticulo->heapArray=(heapElem*)malloc(monticulo->capac*sizeof(heapElem));
  return monticulo;
}
