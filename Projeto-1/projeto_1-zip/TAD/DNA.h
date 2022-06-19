#ifndef DNA_H
#define DNA_H
#include <stdio.h>

typedef struct {

	FILE *genoma;

	FILE *pos_genes;
	long n_genes;

	FILE *fragmentos;
	long **pos_fragmentos;
	long n_fragmentos;

}DNA;

DNA *criar_DNA(
    char *genoma, 
    char *pos_genes, 
    char *fragmentos, 
    long n_genes, 
    long n_fragmentos
);

int destruir_DNA(DNA *dna);

void OrdenaDigitos(long A[][2], long n, long posicao);

void OrdenaNumeros(long A[][2], long n);

void ContagemIntersecoes(FILE *arquivo_A, long **B, long nA, long nB, FILE *arquivo_saida);

long **CtrlF(FILE *arquivo_texto, FILE *arquivo_trechos, long n_fragmentos);


void ContagemLeituras(DNA *dna, FILE *saida);


#endif
