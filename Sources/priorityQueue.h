#if !defined(priorityQueue_H)
#define priorityQueue_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"

// Estrutura para representar a Priority Queue
typedef struct
{
    Item *pq; // Array de itens
    int *map; // Array para mapear IDs
    int N;    // Número de elementos na fila
} PriorityQueue;

void PQ_init(PriorityQueue *pq, int maxN);                     // Cria uma min PQ com capacidade maxN
void PQ_insert(PriorityQueue *pq, Item item);                  // Insere Item na PQ
Item PQ_delmin(PriorityQueue *pq);                             // Remove Item com menor campo 'value' da PQ
void PQ_decrease_key(PriorityQueue *pq, int id, double value); // Muda a prioridade do nó com identificador 'id'
Item PQ_min(PriorityQueue *pq);                                // Retorna Item com menor campo 'value' da PQ
bool PQ_empty(PriorityQueue *pq);                              // Retorna True se a PQ não tem elementos
int PQ_size(PriorityQueue *pq);                                // Número de elementos na PQ
void PQ_finish(PriorityQueue *pq);                             // Libera memória alocada

#endif // priorityQueue_H
