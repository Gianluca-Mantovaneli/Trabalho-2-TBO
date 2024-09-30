#include "dijkstra.h"

void dijkstra(Grafo grafo, int origem, double **distancias) {
    int V = grafo->V;

    // Alocação de estruturas auxiliares
    double *dist = (double *)malloc(V * sizeof(double));
    bool *visitado = (bool *)malloc(V * sizeof(bool));
    
    if (dist == NULL || visitado == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    PriorityQueue pq;
    PQ_init(&pq, V);

    // Inicializando as distâncias e os nós visitados
    for (int i = 0; i < V; i++) {
        dist[i] = INFINITO; // Inicia com infinito
        visitado[i] = false;   // Nenhum nó foi visitado ainda
    }

    dist[origem] = 0.0; // A distância da origem para ela mesma é 0
    PQ_insert(&pq, (Item){.id = origem, .value = 0.0});

    // Algoritmo de Dijkstra
    while (!PQ_empty(&pq)) {
        Item u = PQ_delmin(&pq); // Pega o nó com a menor distância
        int u_id = u.id;

        if (visitado[u_id])
            continue; // Ignora nós já visitados
        visitado[u_id] = true;

        // Itera sobre todos os vizinhos de u
        Node *vizinho = grafo->listaDeAdjacencia[u_id];
        while (vizinho != NULL) {
            int v = vizinho->id;
            double peso = vizinho->peso;

            // Relaxamento da aresta
            if (dist[u_id] + peso < dist[v]) {
                dist[v] = dist[u_id] + peso;
                PQ_insert(&pq, (Item){.id = v, .value = dist[v]});
            }

            vizinho = vizinho->prox;
        }
    }

    // Preenche a matriz de distâncias para a origem
    for (int i = 0; i < V; i++) {
        distancias[origem][i] = dist[i]; // Armazena a distância mínima da origem para todos os outros nós
    }

    // Libera a memória alocada
    free(dist);
    free(visitado);
    PQ_finish(&pq);
}
