#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void busca(char arqParametro[], char texto[]) {
	char strLinha[1000];
	FILE *arquivo;

	if ((arquivo = fopen(arqParametro, "r")) == NULL) {
		printf("\n\nErro ao abrir arquivo.\nArquivo não encontrado ou corrompido.\n");
		return;
	};
	printf("\nArquivo: %s\n\n", arqParametro);

	int linha = 0;
	do {
		fgets(strLinha, 999, arquivo);
		linha++;
//		printf("%s", strLinha);
		int contadorTexto = 0;
		int posInicialTextoEncontrado = 0;
		int posFinalTextoEncontrado = 0;
		for(int a = 0; ( (strLinha[a] != '\0') && (texto[contadorTexto] != '\0') ); a++) {
//			if((strLinha[a] >= 32) && (strLinha[a] != 127)) {	//IF DIFERENTE DE CARACTESRS DE CONTROLE.
			if(strLinha[a] == texto[contadorTexto]) {
				if(!posInicialTextoEncontrado) posInicialTextoEncontrado = a;
				if(texto[contadorTexto+1] == '\0') {
					contadorTexto = -1;
					posFinalTextoEncontrado = a;

					char textoEncontradoAux[1000];
					strcpy(textoEncontradoAux, "");

					int c = 0;
//					for(int b = (posInicialTextoEncontrado == 1) ? 0 : 1; b <= posFinalTextoEncontrado; b++, c++) textoEncontradoAux[c] = strLinha[b];
					//caso âncora para quando o texto for no inicio da linha, pois está contando a posição 1 o primeiro caracter e não zero(0).
//					if(!(posInicialTextoEncontrado-1)) posInicialTextoEncontrado = 0;
//					for(int b = posInicialTextoEncontrado; b <= posFinalTextoEncontrado; b++, c++) textoEncontradoAux[c] = strLinha[b];
					for(int b = (!(posInicialTextoEncontrado-1)) ? 0: posInicialTextoEncontrado; b <= posFinalTextoEncontrado; b++, c++) textoEncontradoAux[c] = strLinha[b];
					textoEncontradoAux[c] = '\0';
					printf("\nLinha: %d\t\t Texto encontrado: %s\n", linha, textoEncontradoAux);
					printf("\nposições(inicial, final): %d %d\n", posInicialTextoEncontrado, posFinalTextoEncontrado);
					printf("\n__________________________________________\n ");
					posInicialTextoEncontrado = 0;
				}
				contadorTexto++;
			} else {
				contadorTexto = 0;
				posInicialTextoEncontrado = 0;
			}
		}
		strcpy(strLinha, "");
	} while(!feof(arquivo));
	fclose(arquivo);
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("\nErro: Digite o nome do arquivo.\n\n");
		return 1;
	}

	char textoBusca[1000];
	strcpy(textoBusca, "123blablabla");

	busca(argv[1], textoBusca);
//	for ( int i = 32; i < 127; i++ ) printf( "%c [%d]\n", i , i );
//	for ( int i = 0; ( (i <= 127) && ((i < 32) || (i == 127)) ); i++ ) printf( "%c [%d]\n", i , i );
	return 0;
}
