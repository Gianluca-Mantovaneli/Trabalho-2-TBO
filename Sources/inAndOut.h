#if !defined(inAndOut_H)
#define inAndOut_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafoListaDeAdjacencia.h"

void LeituraArquivo(const char *entradaPath, const char *saidaPath);
void EscritaArquivo(const char *saidaPath, Inflacao *resultado, int C, int S);

#endif // inAndOut_H
