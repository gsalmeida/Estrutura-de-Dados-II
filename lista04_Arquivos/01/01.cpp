#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TESTANDO int qtdePalavrasNoTexto (char *texto);
//char texto[] = "	 GABRIEL 	DA 	SILVA 	ALMEIDA  	";
//int qtdeDePalavras = qtdePalavras(texto);
//printf("\n\nQTDE DE PALAVRAS: %d \n\n", qtdeDePalavras);

//int qtdePalavrasNoTexto (char *texto) {
//	int qtdePalavras = 0;
//	int achouCaracter = 0;
//	for(int a = 0; texto != '\0'; a++) {
//		if( ((texto[a] != ' ') && (texto[a] != '\t') && (texto[a] != '\0')) && (!achouCaracter) ) {
//			achouCaracter = 1;
//			qtdePalavras++;
//		} else if ((texto[a] == ' ') || (texto[a] == '\t')) achouCaracter = 0;
//	}
//	return qtdePalavras;
//}

//int qtdeCaracters(char texto[]) {
//	int qtde = 0;
//	for(int a = 0, contador = 0; texto != '\0'; a++)
//		if((texto[a] >= 32) && (texto[a] < 127)) qtde++;
//	return qtde;
//}

//numero de linhas
//quantidade de caracters (exceto os de controle (char >= 32 && < 127)) - TABELA ASCII
//numero de palavras
void conta(char arqParametro[]) {
	char strLinha[1000];
	FILE *arquivo;

	int qtdeLinhas = 0;
	int qtdeCaractersNaoDeControle = 0;
	int qtdePalavras = 0;
//	if (argc < 2) {
//	if (arqParametro[0] == '\0') {
//		printf("\n\nErro: Arquivo não informado.\n\n");
//		return;
//	}
	if ((arquivo = fopen(arqParametro, "r")) == NULL) {
		printf("\n\nErro ao abrir arquivo.\nArquivo não encontrado ou corrompido.\n");
		return;
	};
	printf("\nArquivo: %s\n\n", arqParametro);

	do {
		fgets(strLinha, 999, arquivo);
		printf("%s", strLinha);
		//Incrementa na variável qtdeLinhas
		qtdeLinhas++;
		//Incrementa na variável qtdePalavras
		int achouCaracter = 0;
		for(int a = 0; strLinha[a] != '\0'; a++) {
			if( ((strLinha[a] != ' ') && (strLinha[a] != '\t')) && (!achouCaracter) ) {
//				if( (strLinha[0] != 10) && (strLinha[0] != 13) ) {	//IF DIFERENTE DE ENTER E RETORNO DE CARRO.
				if((strLinha[a] >= 32) && (strLinha[a] != 127)) {	//IF DIFERENTE DE CARACTESRS DE CONTROLE.
					achouCaracter = 1;
					qtdePalavras++;
				}
			} else if ((strLinha[a] == ' ') || (strLinha[a] == '\t')) achouCaracter = 0;
			if((strLinha[a] >= 32) && (strLinha[a] != 127)) qtdeCaractersNaoDeControle++;  //Incrementa na variável qtdeCaractersNaoDeControle
		}
		strcpy(strLinha, "");
	} while(!feof(arquivo));

	printf("\n\n");
	printf("\nQUANTIDADE DE LINHAS: %d\n", (qtdeLinhas));
	printf("\nQUANTIDADE DE PALAVRAS: %d\n", qtdePalavras);
	printf("\nQUANTIDADE DE CARACTERS NÃO DE CONTROLE: %d\n", qtdeCaractersNaoDeControle);
	printf("\n\n");
	fclose(arquivo);
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("\nErro: Digite o nome do arquivo.\n\n");
		return 1;
	}
	conta(argv[1]);
//	for ( int i = 32; i < 127; i++ ) printf( "%c [%d]\n", i , i );
//	for ( int i = 0; ( (i <= 127) && ((i < 32) || (i == 127)) ); i++ ) printf( "%c [%d]\n", i , i );
	return 0;
}
