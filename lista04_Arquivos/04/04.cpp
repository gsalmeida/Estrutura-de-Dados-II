#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//argc deve ser o mesmo do método main para que a função
//funcione passando como parâmetros os nomes de todos os arquivos de uma vez apenas.
void concatena1(int argc, char *argvArquivos[]) {
//	printf("\nArgc na função concatena: %d\n", argc);
	FILE *arquivoResutlado;
	if ((arquivoResutlado = fopen(argvArquivos[argc-1], "w+")) == NULL) {
		printf("\n\nErro ao abrir ou criar o arquivo de resultado.\nArquivo não encontrado ou disco com blocos defeituosos.\n"); return;
	}
	//Este for isola o primeiro nome, que este refere-se ao nome do programa em execução, e o ultmo, que trata-se do nome do arquivo resultado (arquivoResutlado).
	for(int a = 1; a < (argc -1); a++) {
		FILE *arquivoAtual;
		if ((arquivoAtual = fopen(argvArquivos[a], "r")) == NULL) {
			printf("\n\nErro ao abrir o arquivo %s.\nArquivo não encontrado ou corrompido.\n", argvArquivos[a]);
			return;
		}
		char strLinha[1000];
		do {
			fgets(strLinha, 999, arquivoAtual);
			fputs(strLinha, arquivoResutlado);
//			for(int a = 0; strLinha[a] != '\0'; a++) {
////				if((strLinha[a] >= 32) && (strLinha[a] != 127)) int qtdeCaractersNaoDeControle = 1;  //Incrementa na variável qtdeCaractersNaoDeControle
//			}
			strcpy(strLinha, "");
		} while(!feof(arquivoAtual));
		fputs("\n", arquivoResutlado);
		fclose(arquivoAtual);
//		printf("\n%s\n", argvArquivos[a]);
	}
	fclose(arquivoResutlado);
}

void concatena2(int argc, char *argvArquivos[]) {
//	printf("\nArgc na função concatena: %d\n", argc);
	FILE *arquivoResutlado;
	FILE *arquivoResutladoAux;
	if ((arquivoResutlado = fopen(argvArquivos[argc-1], "r")) != NULL) {
		if ((arquivoResutladoAux = fopen("arqAuxResultado.txt", "w+")) == NULL) {
			printf("\n\nErro ao abrir ou criar o arquivo auxiliar de resultado.\nArquivo não encontrado ou disco com blocos defeituosos.\n"); return;
		}
		char strLinha[1000];
		do {
			fgets(strLinha, 999, arquivoResutlado);
			fputs(strLinha, arquivoResutladoAux);
//			for(int a = 0; strLinha[a] != '\0'; a++) {
////				if((strLinha[a] >= 32) && (strLinha[a] != 127)) int qtdeCaractersNaoDeControle = 1;  //Incrementa na variável qtdeCaractersNaoDeControle
//			}
			strcpy(strLinha, "");
		} while(!feof(arquivoResutlado));
		fclose(arquivoResutlado);
		fputs("\n", arquivoResutladoAux);
		for(int a = 1; a < (argc -1); a++) {
			FILE *arquivoAtual;
			if ((arquivoAtual = fopen(argvArquivos[a], "r")) == NULL) {
				printf("\n\nErro ao abrir o arquivo %s.\nArquivo não encontrado ou corrompido.\n", argvArquivos[a]);
				return;
			}
			char strLinha[1000];
			do {
				fgets(strLinha, 999, arquivoAtual);
				fputs(strLinha, arquivoResutladoAux);
	//			for(int a = 0; strLinha[a] != '\0'; a++) {
	////				if((strLinha[a] >= 32) && (strLinha[a] != 127)) int qtdeCaractersNaoDeControle = 1;  //Incrementa na variável qtdeCaractersNaoDeControle
	//			}
				strcpy(strLinha, "");
			} while(!feof(arquivoAtual));
			fputs("\n", arquivoResutladoAux);
			fclose(arquivoAtual);
	//		printf("\n%s\n", argvArquivos[a]);
		}
		fclose(arquivoResutladoAux);
		if(remove(argvArquivos[argc-1]))
			rename("arqResultado.txt", argvArquivos[argc-1]);
		//copiar o arquivo arqAuxResultado.txt para o de resultado com o nome original.
		//remover arqAuxResultado.txt

	} else {
		if ((arquivoResutlado = fopen(argvArquivos[argc-1], "w+")) == NULL) {
			printf("\n\nErro ao abrir ou criar o arquivo de resultado.\nArquivo não encontrado ou disco com blocos defeituosos.\n"); return;
		}
		//Este for isola o primeiro nome, que este refere-se ao nome do programa em execução, e o ultmo, que trata-se do nome do arquivo resultado (arquivoResutlado).
		for(int a = 1; a < (argc -1); a++) {
			FILE *arquivoAtual;
			if ((arquivoAtual = fopen(argvArquivos[a], "r")) == NULL) {
				printf("\n\nErro ao abrir o arquivo %s.\nArquivo não encontrado ou corrompido.\n", argvArquivos[a]);
				return;
			}
			char strLinha[1000];
			do {
				fgets(strLinha, 999, arquivoAtual);
				fputs(strLinha, arquivoResutlado);
	//			for(int a = 0; strLinha[a] != '\0'; a++) {
	////				if((strLinha[a] >= 32) && (strLinha[a] != 127)) int qtdeCaractersNaoDeControle = 1;  //Incrementa na variável qtdeCaractersNaoDeControle
	//			}
				strcpy(strLinha, "");
			} while(!feof(arquivoAtual));
			fputs("\n", arquivoResutlado);
			fclose(arquivoAtual);
	//		printf("\n%s\n", argvArquivos[a]);
		}
		fclose(arquivoResutlado);
	}
	//Este for isola o primeiro nome, que este refere-se ao nome do programa em execução, e o ultmo, que trata-se do nome do arquivo resultado (arquivoResutlado).

}

int main(int argc, char *argv[]) {
//	if (argc < 3) {
//		printf("\nErro: Digite o nome dos dois arquivos como parâmetro para serem comparados.\n\n");
//		return 1;
//	}

//	printf("\nArgc no MAIN: %d\n", argc);

	concatena1(argc, argv);


//	comparaBinarios(argv[1], argv[2]);
//	for ( int i = 32; i < 127; i++ ) printf( "%c [%d]\n", i , i );
//	for ( int i = 0; ( (i <= 127) && ((i < 32) || (i == 127)) ); i++ ) printf( "%c [%d]\n", i , i );
	return 0;
}
