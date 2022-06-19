#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "DNA.h"

int main(){
	DNA *dna;
    FILE *ativ_genetica;

    dna = criar_DNA(
        "./projeto_1_dados/genoma_grande.txt",
        "./projeto_1_dados/pos_genes_grande.csv",
        "./projeto_1_dados/fragmentos_grande.txt",
        10000,
        30000
    );
    /*
	genoma = fopen("./projeto_1_dados/genoma_medio.txt", "r");
    assert(genoma != NULL);
	pos_gen = fopen("./projeto_1_dados/pos_genes_grande.csv", "r");
    assert(pos_gen != NULL);
	frag = fopen("./projeto_1_dados/fragmentos_grande.txt", "r");
    assert(frag != NULL);
	pos_frag = fopen("./resultados/pos_frag_grande3_2.csv", "w+");
    assert(pos_frag != NULL);//*/
	ativ_genetica = fopen("./resultados/ariv_wwww.txt", "w");
    assert(ativ_genetica != NULL);

	ContagemLeituras(
		dna,
		ativ_genetica
	);

	fclose(ativ_genetica);

	printf("ok\n");
	return 0;
}