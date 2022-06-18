#include "DNA.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// FUNCOES INTERNAS PARA O TAD
long int _DNA_max_(long int a, long int b){
	return a > b ? a : b;
}

// FUNCOES DO TAD

void OrdenaDigitos(int A[][2], long int n, int posicao){
	// 	Entrada: A, matriz com duplas de numeros a serem ordenadas.
	// Entrada: n, numero de linhas em A.
	// Entrada: posicao, posicao do dıgito a se considerar (10, 100, 1000, etc.).
	// Saıda: A ordenado a partir do dıgito em posicao.

	int B[10], C[n][2];
	int digito;
	long int i;
	
	for( i = 0; i < 10; ++i){
		B[i] = 0;
	}


	for( i = 0; i < n; ++i){
		digito = A[i][0]/posicao;
		digito = digito % 10;
		++B[digito];
	}

	for( i = 1; i < 10; ++i){
		B[i] = B[i] + B[i-1];
	}

	for( i = n - 1; i > -1; --i){
		digito = A[i][0]/posicao;
		digito = digito % 10;
		--B[digito];
		C[B[digito]][0] = A[i][0];
		C[B[digito]][1] = A[i][1];
	}

	for(i = 0; i < n - 1; ++i){
		A[i][0] = C[i][0];
		A[i][1] = C[i][1];
	}


}

void OrdenaNumeros(int A[][2], long n){

	// Entrada: A[n][2], vetor com pares de numeros a serem ordenados.
	// Entrada: n, numero de elementos em A.
	// Saida: A ordenado pelo primeiro elemento de cada par.
	
	int posicao = 1, maior = A[n-1][0];
	long int i;
	for(i = 0; i < n ; ++i){
		maior = _DNA_max_(A[i][0], A[i+1][0]);
	}

	while((maior/posicao) > 0){
		OrdenaDigitos(A, n, posicao);
		posicao *= 10;
	}

}

void ContagemIntersecoes(FILE *arquivo_A, FILE *arquivo_B, long nA, long nB, FILE *arquivo_saida){
	// Entrada: A.txt e B.txt, nao ordenados
	// Entrada: nA e nB, numeros de linhas em A e B, respectivamente.
	// Saıda: contagens.txt, contagens de intervalos de B em cada intervalo de A

	rewind(arquivo_A);
	rewind(arquivo_B);
	
	int A[nA][2],B[nB][2];
	int contagens[nA];
	char buffer[20];
	long i, iA, iB, primeiro_iB = 0;
	
	for(i = 0; i < nA; ++i){
		contagens[nA] = 0;
	}
	for(i = 0; i < nA; ++i){
		fflush(stdout);
		fgets(buffer, 20, arquivo_A);
		A[i][0] = atoi(strtok(buffer,","));
		A[i][1] = atoi(strtok(NULL,","));
	}
	
	for(i = 0; i < nB; ++i){
		fflush(stdout);
		fgets(buffer, 20, arquivo_B);
		B[i][0] = atoi(strtok(buffer,","));
		B[i][1] = atoi(strtok(NULL,","));
	}
	
	OrdenaNumeros (A, nA);
	OrdenaNumeros (B, nB);
	
	
	for(iA = 0; iA < nA; ++iA){
		for(iB = primeiro_iB; iB < nB; ++iB){
			if(A[iA][1] < B[iB][0] || A[iA][0] > B[iB][1]){
				if(contagens[iA] == 0){
					primeiro_iB = iB;
				}
				
			}
			else{
				++contagens[iA];
			}
		}
	}
	for( i = 0; i < nA; ++i){
		fprintf(arquivo_saida,"%d\n",contagens[i]);
	}
	
	
	printf("contagem ok\n");
}

void CtrlF(FILE *arquivo_texto, FILE *arquivo_trechos, FILE *arquivo_saida){
	char *texto, trecho[5000];
	long tamanho_buffer, inicio, fim;
	
	
	fseek(arquivo_texto, 0, SEEK_END);
  	tamanho_buffer = ftell(arquivo_texto);
  	rewind(arquivo_texto);
	
	texto = (char *) malloc(sizeof(char)*tamanho_buffer);
	assert(texto != NULL);
	fread(texto, sizeof(char), tamanho_buffer, arquivo_texto);
	assert(texto != NULL);
	while(fgets(trecho, 5000, arquivo_trechos) != NULL){
		trecho[strlen(trecho) - 1] = '\0';
		if(strstr(texto, trecho) == NULL){
			inicio = 0;

			fim = 0;
		}
		else{
			inicio = strstr(texto, trecho) - texto;

			fim = inicio + strlen(trecho);
		}

		fprintf(arquivo_saida, "%ld,%ld\n", inicio, fim);
		fflush(stdout);
		memset(trecho,0,5000);
	}

	free(texto);
	
}

void ContagemLeituras(
	FILE *genoma,
	FILE *pos_genes,
	FILE *fragmentos,
	FILE *pos_fragmentos,
	long n_genes,
	long n_fragmentos,
	FILE *saida){
	
		CtrlF( genoma, fragmentos, pos_fragmentos);

		ContagemIntersecoes(pos_genes, pos_fragmentos, n_genes, n_fragmentos, saida);
		
	}