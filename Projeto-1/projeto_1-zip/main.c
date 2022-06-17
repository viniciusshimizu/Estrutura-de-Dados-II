#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "./TAD/DNA.h"


void ContagemLeituras(
	FILE *genoma,
	FILE *pos_genes,
	FILE *fragmentos,
	FILE *pos_fragmentos,
	long n_genes,
	long n_fragmentos,
	FILE *saida){
		CtrlF( genoma, fragmentos)
	
	}



int main(){
	FILE *genoma, *pos_gen, *frag, *ativ_gen;
	genoma = fopen("./projeto_1_dados/genoma_grande.txt", "r");
	pos_gen = fopen("./projeto_1_dados/pos_genes_grade.csv", "r");
	frag = fopen("./projeto_1_dados/fragmentos_pequeno.txt", "r");
	ativ_gen = fopen("./projeto_1_dados/pos_genes_pequeno.csv", "w");

	
	


	fclose(genoma);
	fclose(pos_gen);
	fclose(frag);
	fclose(ativ_gen);
	return 0;
}