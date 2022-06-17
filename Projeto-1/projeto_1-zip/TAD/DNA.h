#include <stdio.h>
#ifndef DNA_H
#define DNA_H


void OrdenaDigitos(int A[][], long int n, int posicao);

void OrdenaNumeros(int A, long int n);

void ContagemIntersecoes(FILE *arquivo_A, FILE *arquivo_B, long int nA, long int nB, FILE *arquivo_saida);

void CtrlF(FILE *arquivo_texto, FILE *arquivo_trechos, FILE *arquivo_saida);

#endif
