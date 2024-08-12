#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "inAndOut.h"
#include "grafoListaDeAdjacencia.h"

int main(int argc, char const *argv[])
{
    // Leitura do arquivo de entrada

    clock_t start_time = clock(); // Start the clock

    LeituraArquivo(argv[1], argv[2]);

    clock_t end_time = clock(); // Stop the clock

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Calculate the time taken in seconds

    printf("Tempo de execucao: %.2f segundos\n", time_taken);

    return 0;
}
