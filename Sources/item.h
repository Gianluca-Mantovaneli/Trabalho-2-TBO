#if !defined(item_H)
#define item_H

typedef struct
{
    int id;     // identificador do nó
    char papel; // Papel associado ao nó (S - Servidor| C - Cliente | M - Monitor)
} Item;

#define id(A) (A.id)       // acessa o campo id do nó
#define papel(A) (A.papel) // acessa o campo papel do nó
#define exch(A, B)  \
    {               \
        Item t = A; \
        A = B;      \
        B = t;      \
    } // troca dois nós

#endif // item_H
