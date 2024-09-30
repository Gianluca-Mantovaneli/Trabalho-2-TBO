#include "grafoListaDeAdjacencia.h"

int comparaRTT(const void *a, const void *b)
{
    RTT *rttA = (RTT *)a;
    RTT *rttB = (RTT *)b;
    if (rttA->valor < rttB->valor)
        return -1;
    if (rttA->valor > rttB->valor)
        return 1;
    return 0;
}

Grafo iniciaGrafo(int V, int E)
{
    Grafo grafo = (Grafo)malloc(sizeof(struct grafo));
    grafo->V = V;
    grafo->E = E;
    grafo->listaDeAdjacencia = (Node **)malloc(V * sizeof(Node *));
    for (int i = 0; i < V; i++)
    {
        grafo->listaDeAdjacencia[i] = NULL;
    }
    return grafo;
}

Filter iniciaFilter(int S, int C, int M)
{
    Filter filter = (Filter)malloc(sizeof(struct filter));
    filter->S = S;
    filter->C = C;
    filter->M = M;
    filter->arraryS = (int *)malloc(S * sizeof(int));
    filter->arraryC = (int *)malloc(C * sizeof(int));
    filter->arraryM = (int *)malloc(M * sizeof(int));

    for (int i = 0; i < S; i++)
    {
        filter->arraryS[i] = -1;
    }
    for (int i = 0; i < C; i++)
    {
        filter->arraryC[i] = -1;
    }
    for (int i = 0; i < M; i++)
    {
        filter->arraryM[i] = -1;
    }
    return filter;
}

Filter insereInFilter(int numero, Filter filter, int tipo)
{
    if (tipo == 0) // == servidor
    {
        for (int i = 0; i < filter->S; i++)
        {
            if (filter->arraryS[i] == -1)
            {
                filter->arraryS[i] = numero;
                break;
            }
        }
    }
    else if (tipo == 1) // == cliente
    {
        for (int i = 0; i < filter->C; i++)
        {
            if (filter->arraryC[i] == -1)
            {
                filter->arraryC[i] = numero;
                break;
            }
        }
    }
    else if (tipo == 2) // == monitor
    {
        for (int i = 0; i < filter->M; i++)
        {
            if (filter->arraryM[i] == -1)
            {
                filter->arraryM[i] = numero;
                break;
            }
        }
    }
    return filter;
}

void insereArestaDirecionada(Grafo grafo, int idEmissor, int idReceptor, double peso)
{
    // Insere uma aresta direcionada de idEmissor para idReceptor com peso (Porem não estou verificando se já existe a aresta afim de economizar tempo de execução)
    Node *novoNode = (Node *)malloc(sizeof(Node));
    novoNode->id = idReceptor;
    novoNode->peso = peso;
    novoNode->prox = grafo->listaDeAdjacencia[idEmissor];
    grafo->listaDeAdjacencia[idEmissor] = novoNode;
}

RTT *iniciaInflacao(Filter filter)
{
    int C = filter->C;
    int S = filter->S;
    RTT *inflacao = (RTT *)malloc(C * S * sizeof(RTT));
    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < S; j++)
        {
            inflacao[i * S + j].idCliente = filter->arraryC[i];
            inflacao[i * S + j].idServidor = filter->arraryS[j];
            inflacao[i * S + j].valor = 0.0;
        }
    }
    return inflacao;
}

RTT *ordenaResultado(RTT *resultado, int C, int S)
{
    qsort(resultado, C * S, sizeof(RTT), comparaRTT);
    return resultado;
}

void InsereInflacao(RTT *inflacao, int idCliente, int idServidor, double valor)
{
    for (int i = 0; i < sizeof(inflacao); i++)
    {
        if (inflacao[i].idCliente == idCliente && inflacao[i].idServidor == idServidor)
        {
            inflacao[i].valor = valor;
            break;
        }
    }
}

RTT *calculaInflacao(Grafo grafo, Filter filter, double **distancias)
{
    int C = filter->C;
    int S = filter->S;
    double rtt, rttEstrela, resultado = 0.0; // Variáveis para armazenar os valores de RTT, RTT* e inflação
    RTT *inflacao = iniciaInflacao(filter);  // Inicializa o vetor de inflações

    for (int i = 0; i < C; i++)
    {
        for (int j = 0; j < S; j++)
        {
            int idCliente = filter->arraryC[i];
            int idServidor = filter->arraryS[j];
            rtt = calculaRTT(grafo, filter, idCliente, idServidor, distancias);               // Equivalente a Equação RTT(a, b) = δ(a, b) + δ(b, a)
            rttEstrela = calculaRTTEstrela(grafo, filter, idCliente, idServidor, distancias); // Equivalente a Equação RTT*(a,b) = min (RTT(a, m) + RTT(m, b))
            resultado = rttEstrela / rtt;                                                     // Equivalente a Equação inflação = RTT*(a, b) / RTT(a, b)

            // testando
            printf("RTT*(%d, %d) = %lf\n", idServidor, idCliente, rttEstrela);
            printf("RTT(%d, %d) = %lf\n", idServidor, idCliente, rtt);
            printf("Inflação(%d, %d) = %lf\n", idServidor, idCliente, resultado);
            printf("\n");

            InsereInflacao(inflacao, idCliente, idServidor, resultado);
        }
    }
    inflacao = ordenaResultado(inflacao, C, S); // Ordena o vetor de inflações
    return inflacao;
}

double calculaRTT(Grafo grafo, Filter filter, int idCliente, int idServidor, double **distancias)
{
    return distancias[idCliente][idServidor] + distancias[idServidor][idCliente];
}

double calculaRTTEstrela(Grafo grafo, Filter filter, int idCliente, int idServidor, double **distancias)
{
    double rtt = __DBL_MAX__;  // Inicializa com infinito (ou algum valor muito grande)

    // Percorre todos os monitores
    for (int i = 0; i < filter->M; i++)
    {
        int idMonitor = filter->arraryM[i];

        // Acessa diretamente as distâncias na matriz
        double rttAtual = distancias[idCliente][idMonitor] + distancias[idMonitor][idServidor];
        
        // Atualiza o RTT mínimo
        if (rttAtual < rtt)
        {
            rtt = rttAtual;
        }
    }
    
    return rtt;
}

int *getArrayS(Filter filter)
{
    return filter->arraryS;
}

int *getArrayC(Filter filter)
{
    return filter->arraryC;
}

int *getArrayM(Filter filter)
{
    return filter->arraryM;
}

double **IniciaMatriz(int V)
{
    double **matriz = (double **)malloc(V * sizeof(double *));
    for (int i = 0; i < V; i++)
    {
        matriz[i] = (double *)malloc(V * sizeof(double));
        for (int j = 0; j < V; j++)
        {
            matriz[i][j] = __DBL_MAX__;
        }
    }
    return matriz;
}

void DestroiMatriz(double **matriz, int V)
{
    for (int i = 0; i < V; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

void destroiGrafo(Grafo grafo)
{
    for (int i = 0; i < grafo->V; i++)
    {
        Node *atual = grafo->listaDeAdjacencia[i];
        while (atual != NULL)
        {
            Node *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(grafo->listaDeAdjacencia);
    free(grafo);
}

void destroiFilter(Filter filter)
{
    free(filter->arraryS);
    free(filter->arraryC);
    free(filter->arraryM);
    free(filter);
}

void destroiInflacao(RTT *inflacao)
{
    free(inflacao);
}
