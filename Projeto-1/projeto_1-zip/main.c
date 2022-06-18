#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "DNA.h"

typedef struct DNA{
	char *genoma;
	long 
};


int main(){
	FILE *genoma, *pos_gen, *frag, *pos_frag, *ativ_genetica;
	
	genoma = fopen("./projeto_1_dados/genoma_medio.txt", "r");
    assert(genoma != NULL);
	pos_gen = fopen("./projeto_1_dados/pos_genes_grande.csv", "r");
    assert(pos_gen != NULL);
	frag = fopen("./projeto_1_dados/fragmentos_grande.txt", "r");
    assert(frag != NULL);
	pos_frag = fopen("./resultados/pos_frag_grande3_2.csv", "w+");
    assert(pos_frag != NULL);///
	ativ_genetica = fopen("./resultados/ariv_genoma_medio3_2.txt", "w");
    assert(ativ_genetica != NULL);////

	ContagemLeituras(
		genoma,
		pos_gen,
		frag,
		pos_frag,
		10000,
		30000,
		ativ_genetica
	);
	
	fclose(genoma);
	fclose(pos_gen);
	fclose(frag);
	fclose(pos_frag);
	fclose(ativ_genetica);

	printf("ok\n");
	return 0;
}