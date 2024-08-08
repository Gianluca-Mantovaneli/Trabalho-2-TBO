#include "priorityQueue.h"

static void swap(PriorityQueue *pq, int i, int j)
{
    exch(pq->pq[i], pq->pq[j]);
    pq->map[id(pq->pq[i])] = i;
    pq->map[id(pq->pq[j])] = j;
}

void fix_up(PriorityQueue *pq, int k)
{
    while (k > 1 && more(pq->pq[k / 2], pq->pq[k]))
    {
        swap(pq, k, k / 2);
        k = k / 2;
    }
}

void fix_down(PriorityQueue *pq, int k)
{
    while (2 * k <= pq->N)
    {
        int j = 2 * k;
        if (j < pq->N && more(pq->pq[j], pq->pq[j + 1]))
        {
            j++;
        }
        if (!more(pq->pq[k], pq->pq[j]))
        {
            break;
        }
        swap(pq, k, j);
        k = j;
    }
}

void PQ_init(PriorityQueue *pq, int maxN)
{
    pq->pq = (Item *)malloc((maxN + 1) * sizeof(Item));
    pq->map = (int *)malloc((maxN + 1) * sizeof(int));
    pq->N = 0;
}

void PQ_insert(PriorityQueue *pq, Item v)
{
    pq->N++;
    pq->pq[pq->N] = v;
    pq->map[id(v)] = pq->N;
    fix_up(pq, pq->N);
}

Item PQ_delmin(PriorityQueue *pq)
{
    Item min = pq->pq[1];
    swap(pq, 1, pq->N);
    pq->N--;
    fix_down(pq, 1);
    return min;
}

Item PQ_min(PriorityQueue *pq)
{
    return pq->pq[1];
}

void PQ_print(PriorityQueue *pq)
{
    for (int i = 1; i <= pq->N; i++)
    {
        printf("%f ", pq->pq[i]);
    }
    printf("\n");
}

void PQ_decrease_key(PriorityQueue *pq, int id, double value)
{
    int i = pq->map[id];
    value(pq->pq[i]) = value;
    fix_up(pq, i);
}

bool PQ_empty(PriorityQueue *pq)
{
    return pq->N == 0;
}

int PQ_size(PriorityQueue *pq)
{
    return pq->N;
}

void PQ_finish(PriorityQueue *pq)
{
    free(pq->pq);
    free(pq->map);
}
