#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// r : leitura
// w : escrita
// a : escrita aditiva
// t : arquivo texto
// b : arquivo binario
// + : leitura/gravacao

//
//void comparaBinarios(char arq1Parametro[], char arq2Parametro[]) {
//	char strLinha[1000];
//	FILE *arquivo;
//
//	if ((arquivo = fopen(arq1Parametro, "rb")) == NULL) {
//		printf("\n\nErro ao abrir arquivo.\nArquivo não encontrado ou corrompido.\n");
//		return;
//	};
//	printf("\nArquivo: %s\n\n", arq1Parametro);
//	do {
//		fgets(strLinha, 999, arquivo);
//		printf("%s", strLinha);
//
//		for(int a = 0; strLinha[a] != '\0'; a++) {
//			if((strLinha[a] >= 32) && (strLinha[a] != 127)) int a = 0;
//		}
//		strcpy(strLinha, "");
//	} while(!feof(arquivo));
//
//	//Não sei explicar o pq desta linha abaixo. Sei que a lógica fica com qtdeLinhas
//	printf("\n\n");
//	printf("\nQUANTIDADE DE LINHAS: %d\n", (qtdeLinhas));
//	printf("\nQUANTIDADE DE PALAVRAS: %d\n", qtdePalavras);
//	printf("\nQUANTIDADE DE CARACTERS NÃO DE CONTROLE: %d\n", qtdeCaractersNaoDeControle);
//	printf("\n\n");
//	fclose(arquivo);
//}



void comparaBinarios(char arq1Parametro[], char arq2Parametro[]) {
	FILE *arquivo1;
	FILE *arquivo2;
	int caracter = 0;
	char vetorCharArquivo1[1000];
	char vetorCharArquivo2[1000];
	int contadorA = 0;
	int contadorB = 0;

	if ((arquivo1 = fopen(arq1Parametro, "rb")) == NULL) {
		printf("\n\nErro ao abrir arquivo1.\nArquivo não encontrado ou corrompido.\n"); return;
	}
	if ((arquivo2 = fopen(arq2Parametro, "rb")) == NULL) {
		printf("\n\nErro ao abrir arquivo2.\nArquivo não encontrado ou corrompido.\n"); return;
	}

	while ((caracter = fgetc(arquivo1)) != EOF) { //		if (caracter == 'a') putchar(caracter);
		vetorCharArquivo1[contadorA] = caracter;
		contadorA++;
	}
	vetorCharArquivo1[contadorA] = '\0';
	fclose(arquivo1);


	caracter = 0;
	while ((caracter = fgetc(arquivo2)) != EOF) {
		vetorCharArquivo2[contadorB] = caracter;
		contadorB++;
	}
	vetorCharArquivo2[contadorB] = '\0';
	fclose(arquivo2);

	//IF (Arquivo 1 tem mais caracters que o arquivo 2)
	int saoDiferentes = 0;

	int tamanhoMenor = (contadorA > contadorB) ? contadorB : contadorA;
	int tamanhoMaior = (contadorA > contadorB) ? contadorA : contadorB;
	int a;
	for(a = 0; a < tamanhoMenor; a++) {
		if(vetorCharArquivo1[a] != vetorCharArquivo2[a]) {
			saoDiferentes = 1;
			printf("\n\nArquivo %s(posicao, valor): %d, %c\n", arq1Parametro, a, vetorCharArquivo1[a]);
			printf("\n\nArquivo %s(posicao, valor): %d, %c\n", arq2Parametro, a, vetorCharArquivo2[a]);
		}
	}

	if(contadorA > contadorB)
		for(; a < tamanhoMaior; a++) printf("\n\nArquivo %s(posicao, valor): %d, %c\n", arq1Parametro, a, vetorCharArquivo1[a]);
	else
		for(; a < tamanhoMaior; a++) printf("\n\nArquivo %s(posicao, valor): %d, %c\n", arq2Parametro, a, vetorCharArquivo1[a]);

	if(!saoDiferentes) printf("\n\n\nOs arquivos são idênticos.\n\n\n");

}

int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("\nErro: Digite o nome dos dois arquivos como parâmetro para serem comparados.\n\n");
		return 1;
	}
	comparaBinarios(argv[1], argv[2]);
//	for ( int i = 32; i < 127; i++ ) printf( "%c [%d]\n", i , i );
//	for ( int i = 0; ( (i <= 127) && ((i < 32) || (i == 127)) ); i++ ) printf( "%c [%d]\n", i , i );
	return 0;
}
