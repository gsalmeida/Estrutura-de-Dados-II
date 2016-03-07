#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "info.h"
#include "arvore.h"

int * vetorOcorrenciasCaracters(char arqParametro[]) {
	FILE *arquivoCompresso;

	if ((arquivoCompresso = fopen(arqParametro, "rb")) == NULL) {
		printf("\n\nErro ao abrir arquivoCompresso.\nArquivo não encontrado ou corrompido.\n"); return 0;
	}

	int *vetorOcorrenciasChar = new int[256];
	for (int a = 0; a < 256; a++) vetorOcorrenciasChar[a] = 0;
	unsigned char byteCaracter;
	while (fread(&byteCaracter, 1, 1, arquivoCompresso)) {
		vetorOcorrenciasChar[byteCaracter]++; // o testar o print dentro do while com {}
	}
	fclose(arquivoCompresso);
	printf("\n__________________________________________________________________________________________\n\n");
	printf("\nVETOR DE OCORRÊNCIA DOS CARACTERS:\n\n");
	for (int a = 0; a < 256; a++) if(vetorOcorrenciasChar[a]) printf("\n('%c' ou %d): %d\n", a, a, vetorOcorrenciasChar[a]);
	printf("\n__________________________________________________________________________________________\n\n");
	return vetorOcorrenciasChar;
}

//struct auxiliar somente para armazenar os dados do char com menor ocorrencia.
typedef struct {
  int caracter;
  int ocorrencia;
} EstruturaCharOcorrencias;

EstruturaCharOcorrencias menorCharOcorrencias(int * vetorParametro) {
	int * vetorOcorrencias = vetorParametro;
	int menor = 0;
	int posicaoMenor = 0;
	for(int a = 0; a < 256; a++) {
		if (vetorOcorrencias[a] > 0)
			if(menor == 0) {
				menor = vetorOcorrencias[a];
				posicaoMenor = a;
			} else if(vetorOcorrencias[a] < menor) {
				menor = vetorOcorrencias[a];
				posicaoMenor = a;
			}
	}
	if(!menor) {
		EstruturaCharOcorrencias resultado = {0, 0};
		return resultado;
	}
	EstruturaCharOcorrencias resultado = {posicaoMenor, vetorOcorrencias[posicaoMenor]};
	vetorOcorrencias[posicaoMenor] = 0;
	return resultado;
}

int tamanhoVetorDeArvores(Arvore *arvore) {
	int qtde = 0;
	for(int a = 0; a < 256; a++) {
		Info * info = arvore[a].getInfo();
		if(info) qtde++;
	}
	return qtde;
}

void ordenaVetorArvores(Arvore * arvore) {
	Arvore arvoreAux;
	Info * info1;
	Info * info2;
	for(int a = 0; a < 256; a++) {
		info1 = arvore[a].getInfo();
		info2 = arvore[a+1].getInfo();
		if( (info1) && (info2) ) {
			if(info1->getQtdeOcorrencias() >= info2->getQtdeOcorrencias()) {
				arvoreAux = arvore[a];
				arvore[a] = arvore[a+1];
				arvore[a+1] = arvoreAux;
			}
		}
	}
}

void mostraArvoreComFilhoEsqDirUmNivel(Arvore * vetorArvores) {
	for(int a = 0; a < 256; a++) {
		Info * info = vetorArvores[a].getInfo();
		if(info) {
			printf("\n(PAI) CHAR: %c -> ASCII: %d -> OCORRENCIAS: %d\n", info->getId(), info->getId(), info->getQtdeOcorrencias());
			Arvore * arvoreFilhaDireita = vetorArvores[a].getFilho(DIREITA);
			if(arvoreFilhaDireita) {
				Info * infoFilhoDireita = arvoreFilhaDireita->getInfo();
				if(infoFilhoDireita)
					printf("\n(FILHO DIREITA) CHAR: %c -> ASCII: %d-> OCORRENCIAS: %d\n", infoFilhoDireita->getId(), infoFilhoDireita->getId(), infoFilhoDireita->getQtdeOcorrencias());
			}
			Arvore * arvoreFilhaEsquerda = vetorArvores[a].getFilho(ESQUERDA);
			if(arvoreFilhaEsquerda) {
				Info * infoFilhoEsquerda = arvoreFilhaEsquerda->getInfo();
				if(infoFilhoEsquerda)
					printf("\n(FILHO ESQUERDA) CHAR: %c -> ASCII: %d-> OCORRENCIAS: %d\n", infoFilhoEsquerda->getId(), infoFilhoEsquerda->getId(), infoFilhoEsquerda->getQtdeOcorrencias());
			}
		}
	}
}

void processaVetorArvores(Arvore *vetorArvores) {
	Arvore * primeiroMenor;
	Arvore * segundoMenor;
	Info * info1;
	Info * info2;
	Arvore * nodoPai;
	Info * infoPai;
	for(int a = 0; a < 256; a++) {
		info1 = vetorArvores[a].getInfo();
		if( (a + 1) < (256) ) info2 = vetorArvores[a+1].getInfo();
		if(info1 && info2) {
			primeiroMenor = vetorArvores[a].get();
			segundoMenor = vetorArvores[a+1].get();

			infoPai = new Info(0, info1->getQtdeOcorrencias() + info2->getQtdeOcorrencias());
			nodoPai = new Arvore();
			nodoPai->setInfo(infoPai);
			vetorArvores[a].setInfo(0);

			vetorArvores[a+1].setInfo(0);
			vetorArvores[a+1].setInfo(infoPai);
			vetorArvores[a+1].setFilho(primeiroMenor, ESQUERDA);
			vetorArvores[a+1].setFilho(segundoMenor, DIREITA);

			printf("\n................................ORDENANDO O VETOR DE ÁRVORES................................\n");
			ordenaVetorArvores(vetorArvores);
			printf("\n................................VETOR DE ÁRVORES ORDENADO................................\n");
			mostraArvoreComFilhoEsqDirUmNivel(vetorArvores);
			printf("\n................................FIM ORDENAÇÃO................................\n\n\n");
			break;
		}
	}
}


Arvore * vetorArvoreFinal(char arqParametro[], int * vetorOcorrenciasDosCaracters) {
	Arvore * vetorArvore = new Arvore[256];
	for(int a = 0; a < 256; a++) vetorArvore[a] = new Arvore();
	int posicaoCadastroNaArvore = 0;
//	vetorOcorrenciasDosCaracters = vetorOcorrenciasCaracters(arqParametro);
	EstruturaCharOcorrencias result = menorCharOcorrencias(vetorOcorrenciasDosCaracters);

	printf("\n\nAQUI A STRUCT ABAIXO É CAPITALIZADA COM OS VALORES DO VETOR DE OCORRENCIAS DOS CARACTERS, \nPORÉM ORDENADOS DE MANEIRA CRESCENTE.\n");
	printf("\nAQUI O VETOR DE ÁRVORES TAMBÉM É CRIADO ORDENADO DE MANEIRA CRESCENTE \nEM RELAÇÃO A QTDE DE OCORRENCIA DOS CARACTERS.\n\n");
	printf("\n");
	printf("typedef struct {\n");
	printf("\tint caracter;\n");
	printf("\tint ocorrencia;\n");
	printf("} EstruturaCharOcorrencias;\n\n");
	printf("\nIMPRIMINDO A STRUCT COM OS REGISTROS ORDENADOS PELA OCORRENCIA DOS CARACTERS\n\n");
	printf("ASCII \t\t CHAR \t\t QTDE_OCORRENCIAS\n");

	while(result.caracter) {
		Info *informacao = new Info(result.caracter, result.ocorrencia);
		vetorArvore[posicaoCadastroNaArvore].setInfo(informacao);
		posicaoCadastroNaArvore++;
		printf("%d \t\t (%c) \t\t %d\n", result.caracter, result.caracter, result.ocorrencia);
		result = menorCharOcorrencias(vetorOcorrenciasDosCaracters);
	}
	printf("\n__________________________________________________________________________________________\n");
	printf("\nVETOR DE ÁRVORES CRIADO A PARTIR DAS STRUCTS RETORNADAS COM A FUNÇÃO QUE OBTEM OS \nO MENOR OCORRENTE DO VETOR DE OCORRENCIA DOS CARACTERS E VAI LIMPANDO ESTES REGISTRO.\n");
	mostraArvoreComFilhoEsqDirUmNivel(vetorArvore);

	int tamanhoDoVetorDeArvores = tamanhoVetorDeArvores(vetorArvore);
	while(tamanhoDoVetorDeArvores >= 2) {
		printf("\n\n\nTAMANHO DO VETOR ORDENADO ANTES DO PROCESSAMENTO: %d \n", tamanhoVetorDeArvores(vetorArvore));
		printf("\nprocessaVetorArvores(Arvore *vetorArvores);.....\n");
		processaVetorArvores(vetorArvore);
		printf("\nTAMANHO DO VETOR ORDENADO DEPOIS DO PROCESSAMENTO: %d \n\n", tamanhoVetorDeArvores(vetorArvore));
		tamanhoDoVetorDeArvores--;
	}
	return vetorArvore;
}

int paraInt (char *str) {
	char *valor_str = &str[0];
	int resultado = 0;
	int baseMultiplicador = 0;
	int tamanhoVetorString = strlen(str);
	int achouSinal = 0;
	int achouNumero = 0;
	int sinalNegativo = 0;
	for(int z = (tamanhoVetorString - 1), a = 0; z >= 0 ; a++, z--) {
		//Verifica do ultimo ao primeiro se é número para ir realizando as somas em resultado. Multiplicando por unidade, dezena, centena milhar etc (baseMultiplicador).
		if( (valor_str[z] >= '0') && (valor_str[z] <= '9') ) { // if( (valor_str[z] >= 48) && (valor_str[z] <= 57) ) {
			if( (valor_str[z] - 48 ) > 0) resultado += ( (valor_str[z] - 48) * (baseMultiplicador) );
			else if( (valor_str[z] - 48 == 0) ) resultado += 0;

			if(baseMultiplicador == 0) {
				resultado += (valor_str[z] - 48);
				baseMultiplicador = 10;
			} else baseMultiplicador *= 10;

		}
		//verifica de encontro de sinal. Do primeiro ao ultimo elemento.
		if( (valor_str[a] >= '0') && (valor_str[a] <= '9') ) achouNumero = 1;
		if( (!achouSinal) && (!achouNumero) ) {
			if(valor_str[a] == '-') { //			if(valor_str[a] == 45) {
				achouSinal = 1;
				sinalNegativo = 1;
			}else if(valor_str[a] == '+') { //			}else if(valor_str[a] == 43) {
				achouSinal = 1;
				sinalNegativo = 0;
			}
		}
	}
//	printf("\n SINAL: %d \n", sinalNegativo);
	if(sinalNegativo) resultado *= -1;
	return resultado;
}


void mostraArvorePreOrder(Arvore * arvoreFinal) {
	for(int a = 0; a < 256; a++) {
		Info * info = arvoreFinal[a].getInfo();
		if(info) {
			printf("\n__________________________________________________________________________________________\n");
			printf("\nÁRVORE NA POSIÇÃO %d DO VETOR DE ÁRVORES\n", a);
			printf("\nPRÉ-ORDER:\n");
			arvoreFinal[a].preOrder(&arvoreFinal[a]);
			printf("\n__________________________________________________________________________________________\n");
		}
	}
}


char ** matrizCharValoresFinais (Arvore * vetorArvoreFinal) {
	char **matrizCharValorBinario = new char*[256];
	for(int a = 0; a < 256; a++) {
		Info * info = vetorArvoreFinal[a].getInfo();
		if(info) {
			vetorArvoreFinal[a].processaMatrizCharValoresFinais(&vetorArvoreFinal[a], matrizCharValorBinario);
			break;
		}
	}
	return matrizCharValorBinario;
}

//unsigned char * retornarCharPeloBinarioDaArvore (Arvore * vetorArvoreFinal, char * codigoBinario) {
//	char * strRetorno = new char[256];
//	for(int a = 0; a < 256; a++) {
//		Info * info = vetorArvoreFinal[a].getInfo();
//		if(info) {
//			vetorArvoreFinal[a].retornarCharPeloBinarioDaArvore(&vetorArvoreFinal[a], codigoBinario);
////				return vetorArvoreFinal[a].retornarCharPeloBinarioDaArvore(&vetorArvoreFinal[a], codigoBinario);
//			break;
//		}
//	}
//	return 0;
//}

unsigned int somaQtdeOcorrenciasTodosCaracters (int * vetorOcorrenciasCaracters) {
	unsigned int resultado = 0;
	for(int a = 0; a < 256; a++)  if(vetorOcorrenciasCaracters[a]) resultado += vetorOcorrenciasCaracters[a];
	return resultado;
}

unsigned short int qtdeDeCaractersNoTexto (int * vetorOcorrenciasCaracters) {
	unsigned short int resultado = 0;
	for(int a = 0; a < 256; a++) if(vetorOcorrenciasCaracters[a]) resultado ++;
	return resultado;
}




//char BinarioParaCharASCII(int binarioOitoBits) { //}
unsigned char converterBinarioParaDecimal (int binario) {
	int i, auxiliar, decimal;
	decimal = 0;
	if (binario > 0) {
		for (i = 1; binario > 0; i *= 2) {
			auxiliar = (binario % 10) * i;
			decimal = decimal + auxiliar;
			binario /= 10;
		}
	}
	else {
		binario *= (-1);
		for(i = 1; binario > 0; i *= 2){auxiliar = (binario%10) * i;
			decimal = decimal + auxiliar;
			binario /= 10;
		}
		decimal *= (-1);
	}
	unsigned char resultado = decimal;
	return resultado;
}


//Esta função abaixo foi retirada da internet.
//void converte_DecimalBinario (int decimal){
//	if (decimal / 2 >= 1) {
//		converte_DecimalBinario(decimal / 2);
//		printf ("%d", decimal % 2);
//	}
//	if (decimal == 1) {
//		printf ("1");
//	}
//}


void inverte (char *txt) {
	int tamanhoTexto = strlen(txt);
	char varAux;
	for(int a = 0, z = (tamanhoTexto - 1); a < ((int) (tamanhoTexto / 2)); a++, z--) {
		varAux = txt[a];
		txt[a] = txt[z];
		txt[z] = varAux;
	}
}

//Este deve ser usado na descompressão.
//Este aqui que funciona! Este retornar char * e portanto é o que deve ser utilizado.
char * paraBinario (unsigned valor) {
	char valoresBinarios[] = "01";
	char *resultado = new char[8];
	//se valor igual a zero. 0000 0000
	if(!valor) {
		for(int a = 0; a < 8; a++) resultado[a] = '0';
		return resultado;
	}else if((!(valor - 1))) { // senão se valor igual a 1. 0000 0001
		for(int a = 0; a < 8; a++) {
			resultado[a] = '0';
			if(a == 7) resultado[a] = '1';
		}
		return resultado;
	} else {
		int resultadoInteiroDaDivisao = 0;
		int resto = 0;
		int contador = 0;
		int valorAtual = valor;
//		printf("\n\n VALOR ATUAL %d \n\n", valorAtual);
		while( valorAtual >= 2) {
			resultadoInteiroDaDivisao = ((int) (valorAtual / 2));
			resto = ((int) (valorAtual % 2));
			if(resto <= 1) resultado[contador] = valoresBinarios[resto];
			else resultado[contador] = (resto + 48); // (resto + 0) => Entre 0 e 1
			resultado[contador+1] = '\0';
			contador++;
			valorAtual = resultadoInteiroDaDivisao;
//			printf("\n\n valorAtual %d \n\nresultadoDaDivisao: %d \n resto: %d \n\n", valorAtual, resultadoInteiroDaDivisao, resto);
		}
		if(resultadoInteiroDaDivisao <= 1) resultado[contador] = valoresBinarios[resultadoInteiroDaDivisao];
		else resultado[contador] = resultadoInteiroDaDivisao + 48; // Entre 0 e 9
		resultado[contador+1] = '\0';
	}
	int contador2 = 0;
	while (resultado[contador2]) contador2++;
	for (; (contador2 <= 7); contador2++) resultado[contador2] = '0';
//	printf("\nTamanho Deste Binário: %d\n", contador2);
	inverte(resultado);
	return resultado;
}


//Sem lidar com binários. Usando concatenação de C String.
int comprimirArquivo (char arquivoOriginalParametro[], char arquivoCompressoParametro[]) { //	printf("\n__________________________________________________________________________________________\n");
	FILE *arquivoCompresso;
	if ((arquivoCompresso = fopen(arquivoCompressoParametro, "wb")) == NULL) { printf("\n\nNão foi possível criar o arquivoCompresso.\n\n"); return 0; }
	FILE *arquivoOriginal;
	if ((arquivoOriginal = fopen(arquivoOriginalParametro, "rb")) == NULL) { printf("\n\nErro.\nArquivo não encontrado ou corrompido.\n"); return 0; }

	int * vetorOcorrenciasDosCaracters = vetorOcorrenciasCaracters(arquivoOriginalParametro);
	unsigned int qtdeOcorrenciasTodosCaracteres = somaQtdeOcorrenciasTodosCaracters(vetorOcorrenciasDosCaracters);
	unsigned short int qtdeDeCaractersEncontradosNoTexto = qtdeDeCaractersNoTexto(vetorOcorrenciasDosCaracters);

	//CABEÇALHO DO ARQUIVO COMPRESSO.
	fwrite(&qtdeOcorrenciasTodosCaracteres, sizeof(unsigned int), 1, arquivoCompresso);
	fwrite(&qtdeDeCaractersEncontradosNoTexto, sizeof(unsigned short int), 1, arquivoCompresso);
	unsigned char charAtual = 0;
	unsigned int qtdeOcorrenciasCharAtual = 0;
	for(int a = 0; a < 256; a++)
		if(vetorOcorrenciasDosCaracters[a]) {
			charAtual = a;
			fwrite(&charAtual, sizeof(unsigned char), 1, arquivoCompresso);
			qtdeOcorrenciasCharAtual = vetorOcorrenciasDosCaracters[a];
			fwrite(&qtdeOcorrenciasCharAtual, sizeof(unsigned int), 1, arquivoCompresso);
		}

	Arvore * arvoreFinal = vetorArvoreFinal(arquivoOriginalParametro, vetorOcorrenciasDosCaracters);
//	printf("\nTAMANHO DO VETOR : %d \n", tamanhoVetorDeArvores(arvoreFinal)); printf("\n__________________________________________________________________________________________\n");
	//MOSTRAR ARVORE FINAL
	printf("\n\n\nARVORE FINAL:\n\n\n");
	mostraArvoreComFilhoEsqDirUmNivel(arvoreFinal);
	mostraArvorePreOrder(arvoreFinal);

	printf("\nVALORES FINAIS DOS CARACTERS ENCONTRADOS NO TEXTO PARA SEREM USADOS NA COMPRESSÃO COM HUFFMAN.\n");
	char **matrizCharValorBinario = matrizCharValoresFinais(arvoreFinal);
	printf("\n__________________________________________________________________________________________\n");
	for(int a = 0; a < 256; a++)
		for(int b = 0; b < 1; b++)
			if(matrizCharValorBinario[a]) printf("\n'%c' = '%s'\n", a, &matrizCharValorBinario[a][b]);
	printf("\n__________________________________________________________________________________________\n\n\n");
	printf("\nSOMA DA QTDE DE OCORRENCIAS DE TODOS CARACTERS: %d\n\nQTDE DE CARACTERS NO TEXTO: %d\n", qtdeOcorrenciasTodosCaracteres, qtdeDeCaractersEncontradosNoTexto);
	printf("\n__________________________________________________________________________________________\n\n\n");


	unsigned char charLeituraArqOriginal;
	int qtdeDeslocamentos = 0;
	unsigned char charByte = 0;
	while (fread(&charLeituraArqOriginal, 1, 1, arquivoOriginal)) {
		printf("\n__________________________________________________________________________________________\n");
		printf("'%c' -> %d=%s\n", charLeituraArqOriginal, charLeituraArqOriginal, matrizCharValorBinario[charLeituraArqOriginal]);
		printf("\n__________________________________________________________________________________________\n\n\n");

//		Fiz este teste
//		( (matrizCharValorBinario[charLeituraArqOriginal][a] == '0') || (matrizCharValorBinario[charLeituraArqOriginal][a] == '1') )
//		pq em um texto lorem ipsum um dos caracters teve o char = 17 como atributo na ultima posicao da linha da matriz equivalente (matrizCharValorBinario)
		if(matrizCharValorBinario[charLeituraArqOriginal])
			for(int a = 0; matrizCharValorBinario[charLeituraArqOriginal][a] != '\0' &&
				( (matrizCharValorBinario[charLeituraArqOriginal][a] == '0') || (matrizCharValorBinario[charLeituraArqOriginal][a] == '1') ); a++) {
	//			printf("'%c' -> %d=%s\n", charLeituraArqOriginal, charLeituraArqOriginal, matrizCharValorBinario[charLeituraArqOriginal]);
				printf("\n\n\n\nPOSICAO C STRING: %d -> CHAR NA POSICAO:%c\n\n\n\n\n", a, matrizCharValorBinario[charLeituraArqOriginal][a]);
				int valorBinarioAtual = (matrizCharValorBinario[charLeituraArqOriginal][a] == '0') ? 0 : 1;
	//			if(qtdeDeslocamentos) charByte = (charByte << 1);
				charByte = (charByte << 1);
				if(valorBinarioAtual) charByte = (charByte | 1);
				else charByte = (charByte | 0);
				printf("\n\n\n\n.charByte:%d.\n\n\n\n", charByte);
				qtdeDeslocamentos++;
	//			printf("\n\n\nQUANTIDADE DE DESLOCAMENTOS: %d\n\n",qtdeDeslocamentos);
				printf("\nQUANTIDADE DE DESLOCAMENTOS: %d\n",qtdeDeslocamentos);
				if(qtdeDeslocamentos == 8) {
					printf("\n\n\nGRAVOU CHAR: %d\n\n\n", charByte);
					fwrite(&charByte, sizeof(unsigned char), 1, arquivoCompresso);
					qtdeDeslocamentos = 0;
					charByte = 0;
				}
			}
	}
	if(qtdeDeslocamentos) for(; qtdeDeslocamentos < 8; qtdeDeslocamentos++) charByte = (charByte << 1);
	fwrite(&charByte, sizeof(unsigned char), 1, arquivoCompresso);
	printf("\nGRAVOU CHAR: %d\n", charByte);
	printf(".charByte: %d.", charByte);

	fclose(arquivoOriginal);
	fclose(arquivoCompresso);

	for (int a = 0; a < 256; a++) vetorOcorrenciasDosCaracters[a] = 0;
	for (int a = 0; a < 256; a++) delete [] matrizCharValorBinario[a];
	delete [] matrizCharValorBinario;

}



int descomprimirArquivo (char arquivoCompressoParametro[], char arquivoResultadoParametro[]) {
	FILE *arquivoCompresso;
	if ((arquivoCompresso = fopen(arquivoCompressoParametro, "rb")) == NULL)  printf("Erro ao abrir o arquivoCompresso.\n Arquivo não existe ou há problemas no disco rígido.");
	FILE *arquivoResultado;
	if ((arquivoResultado = fopen(arquivoResultadoParametro, "w")) == NULL)  printf("Erro ao criar o arquivo de resultado.\n Disco rígido cheio ou com problemas.");

	unsigned int qtdeOcorrenciasTodosCaracteres;
	unsigned short int qtdeDeCaractersEncontradosNoTexto;
	int contador = 0;
	//CABEÇALHO DO ARQUIVO COMPRESSO
//	if(!(fread (&qtdeOcorrenciasTodosCaracteres, sizeof(unsigned int), 1, arquivoCompresso))) { printf("\nArquivo compresso com problemas\n"); reutrn 0; }
	printf ("\nQTDE SOMA OCORRENCIAS DE TODOS: %d \n",qtdeOcorrenciasTodosCaracteres, qtdeOcorrenciasTodosCaracteres);
//	if(!(fread (&qtdeDeCaractersEncontradosNoTexto, sizeof(unsigned short int), 1, arquivoCompresso)))  { printf("\nArquivo compresso com problemas\n"); return 0; }
	printf ("\nQTDE DE CHARS ENCONTRADOS: %d \n",qtdeDeCaractersEncontradosNoTexto, qtdeDeCaractersEncontradosNoTexto);
	fread(&qtdeOcorrenciasTodosCaracteres, sizeof(unsigned int), 1, arquivoCompresso);
	fread(&qtdeDeCaractersEncontradosNoTexto, sizeof(unsigned short int), 1, arquivoCompresso);

	int * vetorOcorrenciasChar = new int[256];
	for (int a = 0; a < 256; a++) vetorOcorrenciasChar[a] = 0;

	unsigned char charAtual = 0;
	unsigned int qtdeOcorrenciasCharAtual = 0;
	for(; qtdeDeCaractersEncontradosNoTexto; qtdeDeCaractersEncontradosNoTexto--) {
		fread(&charAtual, sizeof(unsigned char), 1, arquivoCompresso);
		fread(&qtdeOcorrenciasCharAtual, sizeof(unsigned int), 1, arquivoCompresso);
		printf("\nCHAR ATUAL  --- >  QTDE OCORRENCIAS: %c --- > %d\n", charAtual, qtdeOcorrenciasCharAtual);
		vetorOcorrenciasChar[charAtual] = qtdeOcorrenciasCharAtual;
	}

	Arvore * arvoreFinal = vetorArvoreFinal(arquivoCompressoParametro, vetorOcorrenciasChar);
	char **matrizCharValorBinario = matrizCharValoresFinais(arvoreFinal);
	for(int a = 0; a < 256; a++) for(int b = 0; b < 1; b++) if(matrizCharValorBinario[a]) printf("\n'%c' = '%s'\n", a, &matrizCharValorBinario[a][b]);

	//ATÉ AQUI ESTÁ OK. PROBLEMA NA LÓGICA DA DESCOMPRESSÃO.

	printf("\n\nCORPO DO ARQUIVO COMPRESSO\n\n");
	char * stringBits = new char [256];
	for(int c = 255; c >= 0; c--) stringBits[c] = 0;
	stringBits[0] = '\0';
	int contadorStringBits = 0;
	while(fread(&charAtual, sizeof(unsigned char), 1, arquivoCompresso)) {
//		for(int c = 255; c >= 0; c--) stringBits[c] = 0;
		printf("\n__________________________________________________________________________________________\n");
		printf("\nCHAR ATUAL: %d\n", charAtual);
		char * charLidoEmBinario = paraBinario(charAtual);
		printf("\nEM BINARIO: %s\n", charLidoEmBinario);
		printf("\n__________________________________________________________________________________________\n");
//		printf("\nVALOR TESTE (contadorStringBits, VALOR STRING BITS): %d  >> %d\n", contadorStringBits,stringBits[contadorStringBits]);
		for(int a = 0; charLidoEmBinario[a]; a++) {
			printf("\nCONTADOR STRING BITS %d\n", contadorStringBits);
			stringBits[contadorStringBits] = charLidoEmBinario[a];
			contadorStringBits++;
			stringBits[contadorStringBits] = '\0';

//			printf("\nSTRING EM BITS:");
//			for(int i = 0; stringBits[i] != '\0'; i++) printf("%c", stringBits[i]);
//			printf("\n");

			//PERCORRE TODOS OS CARACTESRS DA TABELA ASCII.
			for(int a2 = 0; a2 < 256; a2++) {
				if(matrizCharValorBinario[a2]) {
					if(strlen(stringBits) == strlen(matrizCharValorBinario[a2])) {
						if(!strcmp(stringBits, matrizCharValorBinario[a2])) {
							char byteAGravar = a2;
	//						printf("\nQTDE OCORRENCIAS TODOS CARACTERS: %d\n", qtdeOcorrenciasTodosCaracteres);
							qtdeOcorrenciasTodosCaracteres--;
	//						printf("\nQTDE OCORRENCIAS TODOS CARACTERS: %d\n", qtdeOcorrenciasTodosCaracteres);
							if(qtdeOcorrenciasTodosCaracteres) {
								fputc(byteAGravar, arquivoResultado);
								contadorStringBits = 0;
							} else {
								printf("\nGRAVANDO O ULTIMO CARACTER: %c >>> %s\n", a, matrizCharValorBinario[a2]);
								fputc(byteAGravar, arquivoResultado);
	//							contadorStringBits = 0;
								printf("\nPAROU ESCREVER.\n");
								break; // a2 = 256;
							}
							for(int c = 255; c >= 0; c--) stringBits[c] = 0;
							break; // a2 = 256;
						}
					}
				}

			}

		}
	}

	fclose (arquivoCompresso);
	fclose (arquivoResultado);
	//DESALOCAMENTO DE MEMÓRIA
	for (int a = 0; a < 256; a++) vetorOcorrenciasChar[a] = 0;
	for(int c = 255; c >= 0; c--) stringBits[c] = 0;
	delete [] stringBits;
}

