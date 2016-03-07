#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
//void inverte (char *txt) {
//	int tamanhoTexto = strlen(txt);
//	char varAux;
//	for(int a = 0, z = (tamanhoTexto - 1); a < ((int) (tamanhoTexto / 2)); a++, z--) {
//		varAux = txt[a];
//		txt[a] = txt[z];
//		txt[z] = varAux;
//	}
//}
//
//
//char * paraHexa (unsigned valor) {
//	char valoresHexadecimal[] = "0123456789ABCDEF";
//	char *resultado = new char[999];
//	if(valor <= 15) {
//		resultado[0] = valoresHexadecimal[valor];
//		resultado[1] = '\0';
//		return resultado;
//	} else {
//		int resultadoInteiroDaDivisao = 0;
//		int resto = 0;
//		int contador = 0;
//		int valorAtual = valor;
////		printf("\n\n VALOR ATUAL %d \n\n", valorAtual);
//		while( valorAtual >= 16) {
//			resultadoInteiroDaDivisao = ((int) (valorAtual / 16));
//			resto = ((int) (valorAtual % 16));
//			if(resto <= 15) resultado[contador] = valoresHexadecimal[resto];
//			else resultado[contador] = (resto + 48); // (resto + 0) => Entre 0 e 9
//			resultado[contador+1] = '\0';
//			contador++;
//			valorAtual = resultadoInteiroDaDivisao;
////			printf("\n\n valorAtual %d \n\nresultadoDaDivisao: %d \n resto: %d \n\n", valorAtual, resultadoInteiroDaDivisao, resto);
//		}
//		if(resultadoInteiroDaDivisao <= 15) resultado[contador] = valoresHexadecimal[resultadoInteiroDaDivisao];
//		else resultado[contador] = resultadoInteiroDaDivisao + 48; // Entre 0 e 9
//		resultado[contador+1] = '\0';
//	}
//	inverte(resultado);
//	return resultado;
//}

void processaHtmlParametros(char arquivoHtml[], char arquivoParametros[], char arquivoResultado[]) {
	char strLinha[1000];
	FILE *arquivoParametrosAux;

	if ((arquivoParametrosAux = fopen(arquivoParametros, "r")) == NULL) {
		printf("\n\nErro ao abrir arquivo de parâmetros.\nArquivo não encontrado ou corrompido.\n");
		return;
	}

	FILE *arquivoHtmlAux;
	if ((arquivoHtmlAux = fopen(arquivoHtml, "r")) == NULL) {
		printf("\n\nErro ao abrir arquivo de HTML.\nArquivo não encontrado ou corrompido.\n");
		return;
	}

	FILE *arquivoResultadoAux;
	if ((arquivoResultadoAux = fopen(arquivoResultado, "w+")) == NULL) {
		printf("\n\nErro ao abrir ou criar arquivo de resultado.\nArquivo não encontrado ou disco com blocos defeitos.\n");
		return;
	}

	char informacoesHexa[256][1000];
	int contador = 0;
	do {
		fgets(strLinha, 999, arquivoParametrosAux);
		char textoLinha[1000];
		strcpy(textoLinha, "");
		if(strlen(strLinha) > 3) {
			for(int a = 0; strLinha[a] != '\0'; a++) {
				textoLinha[a] = strLinha[a];
			}
		}
		strcpy(informacoesHexa[contador], textoLinha);

		strcpy(strLinha, "");
		contador++;

	} while(!feof(arquivoParametrosAux));

	fclose(arquivoParametrosAux);


	for(int a = 0; a < 256; a++) {
		if(informacoesHexa[a][0] != '\0') printf("\nTexto no vetor informacoesHexa: %s\n", informacoesHexa[a]);
	}

	strcpy(strLinha, "");
	do {
		fgets(strLinha, 999, arquivoHtmlAux);

		char strLinhaAux[1000];
		int contadorLinhaAux = 0;
		char codigoIndice[3];
		strcpy(codigoIndice, "");
		for(int a = 0; strLinha[a] != '\0'; a++) {
			if(strLinha[a] == '$') {
				if( (strLinha[a+1] != '\0') && (strLinha[a+1] == '{') ) {
					if( ( (strLinha[a+2] != '\0') && (strLinha[a+3] != '\0') ) && ((strLinha[a+4] != '\0') && (strLinha[a+4] == '}')) ){
						codigoIndice[0] = strLinha[a+2];
						codigoIndice[1] = strLinha[a+3];
						codigoIndice[2] = '\0';
						for(int a = 0; a < 256; a++) {
							if(informacoesHexa[a][0] != '\0') {
								char strAux[1000];
								strcpy(strAux, &informacoesHexa[a][0]);
								for(int b = 0; strAux != '\0'; b++) {
									if( (strAux[a] == codigoIndice[0]) && (strAux[a+1] == codigoIndice[1]) ) {
										strLinhaAux[contadorLinhaAux] = codigoIndice[0];
										contadorLinhaAux++;
										strLinhaAux[contadorLinhaAux] = codigoIndice[1];
										a += 4;
									}
								}
//								if( (informacoesHexa[a][0] == codigoIndice[0]) && (informacoesHexa[a][0] == codigoIndice[1]) ) printf("\nTexto no vetor informacoesHexa: %s\n", informacoesHexa[a]);
							}
						}


					} else strLinhaAux[contadorLinhaAux] = strLinha[a];
				} else strLinhaAux[contadorLinhaAux] = strLinha[a];
			} else strLinhaAux[contadorLinhaAux] = strLinha[a];
			contadorLinhaAux++;
		}
		printf("\nLinha nova: %s\n", strLinhaAux);
		strcpy(strLinha, "");

	} while(!feof(arquivoHtmlAux));

	fclose(arquivoHtmlAux);



}

int main(int argc, char *argv[]) {
	if (argc < 4) {
		printf("\nErro: Informe os seguintes parâmetros: arquivo HTML, arquivo de parâmetros e o nome do arquivo de resultado.\n\n");
		return 1;
	}

	processaHtmlParametros(argv[1], argv[2], argv[3]);

//	conta(argv[1]);

	return 0;
}
