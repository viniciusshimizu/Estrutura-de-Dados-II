#include <stdio.h>
#ifndef DNA_H
#define DNA_H


void OrdenaDigitos(int A[][2], long n, int posicao);

void OrdenaNumeros(int A[][2], long n);

void ContagemIntersecoes(FILE *arquivo_A, FILE *arquivo_B, long nA, long nB, FILE *arquivo_saida);

void CtrlF(FILE *arquivo_texto, FILE *arquivo_trechos, FILE *arquivo_saida);


void ContagemLeituras(
	FILE *genoma,
	FILE *pos_genes,
	FILE *fragmentos,
	FILE *pos_fragmentos,
	long n_genes,
	long n_fragmentos,
	FILE *saida
);


#endif
