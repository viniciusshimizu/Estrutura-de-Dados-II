#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "DNA.h"


int main(){
	FILE *genoma, *pos_gen, *frag, *pos_frag, *ativ_genetica;
	
	genoma = fopen("./projeto_1_dados/genoma_grande.txt", "r");
    assert(genoma != NULL);
	pos_gen = fopen("./projeto_1_dados/pos_genes_grande.csv", "r");
    assert(pos_gen != NULL);
	frag = fopen("./projeto_1_dados/fragmentos_pequeno.txt", "r");
    assert(frag != NULL);
	pos_frag = fopen("./projeto_1_dados/pos_frag_pequeno.csv", "a+");
    assert(pos_frag != NULL);
	ativ_genetica = fopen("./resultados/pos_frag_pequeno.txt", "w");
    assert(ativ_genetica != NULL);

	ContagemLeituras(
		genoma,
		pos_gen,
		frag,
		pos_frag,
		10000,
		300,
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