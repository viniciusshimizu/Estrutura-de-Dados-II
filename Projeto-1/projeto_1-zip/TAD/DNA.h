#ifndef DNA_H
#define DNA_H
#include <stdio.h>

typedef struct {

	FILE *genoma;

	FILE *pos_genes;
	int n_genes;

	FILE *fragmentos;
	int **pos_fragmentos;
	int n_fragmentos;

}DNA;

DNA *criar_DNA(
    char *genoma, 
    char *pos_genes, 
    char *fragmentos, 
    int n_genes, 
    int n_fragmentos
);

int destruir_DNA(DNA *dna);

void OrdenaDigitos(int A[][2], int n, int posicao);

void OrdenaNumeros(int A[][2], int n);

void ContagemIntersecoes(FILE *arquivo_A, int **B, int nA, int nB, FILE *arquivo_saida);

int **CtrlF(FILE *arquivo_texto, FILE *arquivo_trechos, int n_fragmentos);


void ContagemLeituras(DNA *dna, FILE *saida);


#endif
