#if !defined(priority_queue_H)
#define priority_queue_H

#include <stdbool.h>
#include "item.h"

void priority_queue_init(int maxN);                     // cria uma min fila de prioridade com capacidade maxN
void priority_queue_insert(int id, double value);       // Insere Item na fila de prioridade. A maior prioridade é a do Item com menor campo 'value'
Item priority_queue_delmin();                           // Remove Item com menor campo 'value' da fila de prioridade
void priority_queue_decrease_key(int id, double value); // Muda a prioridade do nó com identificador 'id' para 'value'
Item priority_queue_minimo();                           // Retorna Item com menor campo 'value' da fila de prioridade
bool priority_queue_empty();                            // Retorna True se a fila de prioridade não tem elementos
int priority_queue_size();                              // Número de elementos na fila de prioridade
void priority_queue_finish();                           // Libera memória da fila de prioridade

#endif // priority_queue_H