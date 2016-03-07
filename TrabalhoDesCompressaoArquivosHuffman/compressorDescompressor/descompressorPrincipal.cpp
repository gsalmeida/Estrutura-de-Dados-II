#include "funcoes.h"


/*
 g++ info.cpp arvore.cpp funcoes.h descompressorPrincipal.cpp -o descompressorPrincipal
*/

int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("\nErro: Informe o nome do arquivo com compressão Huffman e o nome de saída para o arquivo sem compressão que será gerado como resultado.\n\n");
		return 1;
	}

	descomprimirArquivo(argv[1], argv[2]);

	return 0;

}
