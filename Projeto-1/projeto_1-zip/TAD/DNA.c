#include "DNA.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// FUNCOES INTERNAS PARA O TAD
long int _DNA_max_(long a, long b){
	return a < b ? b : a;
}

// FUNCOES DO TAD

DNA *criar_DNA(char *genoma, char *pos_genes, char *fragmentos, long n_genes, long n_fragmentos){
    DNA *dna;

    dna = (DNA *)malloc(sizeof(DNA));

    dna->genoma = fopen(genoma, "r");
    assert(dna->genoma != NULL);
      
    dna->pos_genes = fopen(pos_genes, "r");
    assert(dna->pos_genes != NULL);
    dna->n_genes = n_genes;
      
    dna->fragmentos = fopen(fragmentos, "r");
    assert(dna->fragmentos != NULL);
    dna->n_fragmentos = n_fragmentos;

    dna->pos_fragmentos = NULL;
    

    return dna;
}

int destruir_DNA(DNA *dna){
    
    fclose(dna->genoma);
      
    fclose(dna->pos_genes);
      
    fclose(dna->fragmentos);

    if(dna->pos_fragmentos != NULL){
        for( int i = 0; i < dna->n_fragmentos; ++i){
            free(dna->pos_fragmentos[i]);
        }
        free(dna->pos_fragmentos);
    }
    
    free(dna);
    
    return 0;
}

void OrdenaDigitos(long A[][2], long n, long posicao){
	// 	Entrada: A, matriz com duplas de numeros a serem ordenadas.
	// Entrada: n, numero de linhas em A.
	// Entrada: posicao, posicao do dıgito a se considerar (10, 100, 1000, etc.).
	// Saıda: A ordenado a partir do dıgito em posicao.

	long B[10], C[n][2];
	long digito;
	long i;
	
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

void OrdenaDigitos_p(long **A, long n, long posicao){
	// 	Entrada: A, matriz com duplas de numeros a serem ordenadas.
	// Entrada: n, numero de linhas em A.
	// Entrada: posicao, posicao do dıgito a se considerar (10, 100, 1000, etc.).
	// Saıda: A ordenado a partir do dıgito em posicao.

	long B[10], C[n][2];
	long digito;
	long i;
	
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

void OrdenaNumeros(long A[][2], long n){

	// Entrada: A[n][2], vetor com pares de numeros a serem ordenados.
	// Entrada: n, numero de elementos em A.
	// Saida: A ordenado pelo primeiro elemento de cada par.
	
	long posicao = 1, maior = A[n-1][0];
	long i;
	for(i = 0; i < n ; ++i){
		maior = _DNA_max_(A[i][0], A[i+1][0]);
	}

	while((maior/posicao) > 0){
		OrdenaDigitos(A, n, posicao);
		posicao *= 10;
	}

}

void OrdenaNumeros_p(long **A, long n){

	// Entrada: A[n][2], vetor com pares de numeros a serem ordenados.
	// Entrada: n, numero de elementos em A.
	// Saida: A ordenado pelo primeiro elemento de cada par.
	
	long posicao = 1, maior = A[n-1][0];
	long i;

	for(i = 0; i < n-1 ; ++i){
		maior = _DNA_max_(A[i][0], A[i+1][0]);
	}
    printf("teste antes while\n");
	while((maior/posicao) > 0){
		OrdenaDigitos_p(A, n, posicao);
		posicao *= 10;
	}

}

void ContagemIntersecoes(FILE *arquivo_A, long **B, long nA, long nB, FILE *arquivo_saida){
	// Entrada: A.txt e B.txt, nao ordenados
	// Entrada: nA e nB, numeros de linhas em A e B, respectivamente.
	// Saıda: contagens.txt, contagens de intervalos de B em cada intervalo de A

	rewind(arquivo_A);
	//rewind(arquivo_B);
	
	long A[nA][2];//B[nB][2]
	long contagens[nA];
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
    printf("a ok \n");
	OrdenaNumeros (A, nA);
    printf("ord a ok \n");
	OrdenaNumeros_p (B, nB);
	printf("ord b ok \n");
	
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
		fprintf(arquivo_saida,"%ld\n",contagens[i]);
	}
	
	
	printf("contagem ok\n");
}

long **CtrlF(FILE *arquivo_texto, FILE *arquivo_trechos, long n_fragmentos){
	char *texto, trecho[5000];
	long tamanho_buffer, inicio, fim, i; 
    long **pos_fragmentos;

    pos_fragmentos = (long **)malloc(sizeof(long *) * n_fragmentos);
    for(i = 0; i < n_fragmentos; ++i){
        pos_fragmentos[i] = (long *)malloc(sizeof(long) * 2);
    }
	
	fseek(arquivo_texto, 0, SEEK_END);
  	tamanho_buffer = ftell(arquivo_texto);
  	rewind(arquivo_texto);
	
	texto = (char *) malloc(sizeof(char)*tamanho_buffer);
	assert(texto != NULL);
	fread(texto, sizeof(char), tamanho_buffer, arquivo_texto);
	assert(texto != NULL);
    i = 0;
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
        pos_fragmentos[i][0] = inicio;
        pos_fragmentos[i][1] = fim;
        ++i;
    }
    
	free(texto);
	return pos_fragmentos;
}

void ContagemLeituras(DNA *dna, FILE *saida){
	
		dna->pos_fragmentos = CtrlF( dna->genoma, dna->fragmentos, dna->n_fragmentos);

		ContagemIntersecoes(dna->pos_genes, dna->pos_fragmentos, dna->n_genes, dna->n_fragmentos, saida);
		printf("ctrsf ok \n");
	}