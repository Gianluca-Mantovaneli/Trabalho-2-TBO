#if !defined(item_H)
#define item_H

typedef struct
{
    int id;       // identificador do nó
    double value; // valor associado ao nó
} Item;

#define id(A) (A.id)                     // retorna identificador deste nó
#define value(A) (A.value)               // retorna o valor deste nó
#define more(A, B) (value(A) > value(B)) // compara nós, por valor
#define exch(A, B)  \
    {               \
        Item t = A; \
        A = B;      \
        B = t;      \
    } // troca dois nós

#endif // item_H
