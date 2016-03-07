#include "funcoes.h"

/*
 g++ info.cpp arvore.cpp funcoes.h compressorPrincipal.cpp -o compressorPrincipal
*/

int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("\nErro: Informe o nome do arquivo a ser compactado e do arquivo compresso a ser gerado como resultado.\n\n");
		return 1;
	}

	comprimirArquivo(argv[1], argv[2]);

	return 0;

}
