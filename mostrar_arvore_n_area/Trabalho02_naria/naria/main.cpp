#include <stdio.h>
#include "info.h"
#include "arvoren.h"
#include "lse.h"

int main() {

	ArvoreN* arvoreRaiz = new ArvoreN(new Info(-99));

	//FILHOS - PRIMEIRO NIVEL ABAIXO DA RAIZ.
	ArvoreN* filho1 = new ArvoreN(new Info(-123456789));
	ArvoreN* filho2 = new ArvoreN(new Info(2));
	ArvoreN* filho3 = new ArvoreN(new Info(3));
	ArvoreN* filho4 = new ArvoreN(new Info(4));
	ArvoreN* filho5 = new ArvoreN(new Info(5));
	//FIM FILHOS - PRIMEIRO NIVEL ABAIXO DA RAIZ.

	//NETOS - SEGUNDO NIVEL ABAIXO DA RAIZ.
	ArvoreN* noFilho10 = new ArvoreN(new Info(6));
	ArvoreN* noFilho11 = new ArvoreN(new Info(7));
	ArvoreN* noFilho12 = new ArvoreN(new Info(8));
	ArvoreN* noFilho13 = new ArvoreN(new Info(9));
	ArvoreN* noFilho14 = new ArvoreN(new Info(10));
	ArvoreN* noFilho15 = new ArvoreN(new Info(11));

	ArvoreN* noFilho20 = new ArvoreN(new Info(12));
	ArvoreN* noFilho21 = new ArvoreN(new Info(13));

	ArvoreN* noFilho30 = new ArvoreN(new Info(14));

	ArvoreN* noFilho40 = new ArvoreN(new Info(15));
	ArvoreN* noFilho41 = new ArvoreN(new Info(16));
	ArvoreN* noFilho42 = new ArvoreN(new Info(17));
	ArvoreN* noFilho43 = new ArvoreN(new Info(18));

	ArvoreN* noFilho50 = new ArvoreN(new Info(19));
	ArvoreN* noFilho51 = new ArvoreN(new Info(20));
	ArvoreN* noFilho52 = new ArvoreN(new Info(21));
	ArvoreN* noFilho53 = new ArvoreN(new Info(22));
	ArvoreN* noFilho54 = new ArvoreN(new Info(23));
	ArvoreN* noFilho55 = new ArvoreN(new Info(24));
	ArvoreN* noFilho56 = new ArvoreN(new Info(25));
	ArvoreN* noFilho57 = new ArvoreN(new Info(26));
	//FIM NETOS - SEGUNDO NIVEL ABAIXO DA RAIZ.


	//BISNETOS- TERCEIRO NIVEL ABAIXO DA RAIZ.
	ArvoreN* noFilho100 = new ArvoreN(new Info(27));
	ArvoreN* noFilho101 = new ArvoreN(new Info(28));
	ArvoreN* noFilho102 = new ArvoreN(new Info(29));

	ArvoreN* noFilho110 = new ArvoreN(new Info(30));

	ArvoreN* noFilho130 = new ArvoreN(new Info(31));
	ArvoreN* noFilho131 = new ArvoreN(new Info(32));
	ArvoreN* noFilho132 = new ArvoreN(new Info(33));


	ArvoreN* noFilho200 = new ArvoreN(new Info(34));

	ArvoreN* noFilho210 = new ArvoreN(new Info(35));
	ArvoreN* noFilho211 = new ArvoreN(new Info(36));
	ArvoreN* noFilho212 = new ArvoreN(new Info(37));

	ArvoreN* noFilho300 = new ArvoreN(new Info(38));
	ArvoreN* noFilho301 = new ArvoreN(new Info(39));


	ArvoreN* noFilho410 = new ArvoreN(new Info(54));
	ArvoreN* noFilho411 = new ArvoreN(new Info(55));

	ArvoreN* noFilho420 = new ArvoreN(new Info(56));
	ArvoreN* noFilho421 = new ArvoreN(new Info(57));

	ArvoreN* noFilho520 = new ArvoreN(new Info(58));
	ArvoreN* noFilho521 = new ArvoreN(new Info(59));
	ArvoreN* noFilho522 = new ArvoreN(new Info(60));

	ArvoreN* noFilho550 = new ArvoreN(new Info(61));
	ArvoreN* noFilho551 = new ArvoreN(new Info(62));

	ArvoreN* noFilho570 = new ArvoreN(new Info(63));
	//FIM BISNETOS- TERCEIRO NIVEL ABAIXO DA RAIZ.


	//TATARANETOS - QUARTO NIVEL ABAIXO DA RAIZ.
	ArvoreN* noFilho1000 = new ArvoreN(new Info(40));

	ArvoreN* noFilho1020 = new ArvoreN(new Info(41));
	ArvoreN* noFilho1021 = new ArvoreN(new Info(42));

	ArvoreN* noFilho1300 = new ArvoreN(new Info(43));

	ArvoreN* noFilho1320 = new ArvoreN(new Info(44));
	ArvoreN* noFilho1321 = new ArvoreN(new Info(99999999));
	ArvoreN* noFilho1322 = new ArvoreN(new Info(46));
	ArvoreN* noFilho1323 = new ArvoreN(new Info(47));

	ArvoreN* noFilho2100 = new ArvoreN(new Info(48));
	ArvoreN* noFilho2101 = new ArvoreN(new Info(49));

	ArvoreN* noFilho2120 = new ArvoreN(new Info(50));

	ArvoreN* noFilho3010 = new ArvoreN(new Info(51));
	ArvoreN* noFilho3011 = new ArvoreN(new Info(52));
	ArvoreN* noFilho3012 = new ArvoreN(new Info(53));

	ArvoreN* noFilho4100 = new ArvoreN(new Info(64));
	ArvoreN* noFilho4101 = new ArvoreN(new Info(65));

	ArvoreN* noFilho4210 = new ArvoreN(new Info(66));
	ArvoreN* noFilho4211 = new ArvoreN(new Info(67));

	ArvoreN* noFilho5210 = new ArvoreN(new Info(68));
	ArvoreN* noFilho5211 = new ArvoreN(new Info(69));
	ArvoreN* noFilho5212 = new ArvoreN(new Info(70));
	ArvoreN* noFilho5213 = new ArvoreN(new Info(71));

	ArvoreN* noFilho5700 = new ArvoreN(new Info(72));
	ArvoreN* noFilho5701 = new ArvoreN(new Info(73));

	//FIM TATARANETOS - QUARTO NIVEL ABAIXO DA RAIZ.


	//TATARANETOS 1ªGERAÇÃO- QUARTO NIVEL ABAIXO DA RAIZ.
	ArvoreN* noFilho13210 = new ArvoreN(new Info(74));
	ArvoreN* noFilho13211 = new ArvoreN(new Info(75));
//	ArvoreN* noFilho13210 = new ArvoreN(new Info(76));
	ArvoreN* noFilho13212 = new ArvoreN(new Info(7688888));

	ArvoreN* noFilho21010 = new ArvoreN(new Info(77));
	ArvoreN* noFilho21011 = new ArvoreN(new Info(78));

	ArvoreN* noFilho30110 = new ArvoreN(new Info(79));
	//FIM TATARANETOS 1ªGERAÇÃO- QUARTO NIVEL ABAIXO DA RAIZ.

	//TATARANETOS 2ªGERAÇÃO- QUARTO NIVEL ABAIXO DA RAIZ.
	ArvoreN* noFilho132100 = new ArvoreN(new Info(80));
	ArvoreN* noFilho132101 = new ArvoreN(new Info(81));
	ArvoreN* noFilho132102 = new ArvoreN(new Info(82));

//	ArvoreN* noFilho132120 = new ArvoreN(new Info(83));
	ArvoreN* noFilho132120 = new ArvoreN(new Info(83777777));
	ArvoreN* noFilho132121 = new ArvoreN(new Info(84));

	ArvoreN* noFilho210110 = new ArvoreN(new Info(85));
	ArvoreN* noFilho210111 = new ArvoreN(new Info(86));

	//FIM TATARANETOS 2ªGERAÇÃO- QUARTO NIVEL ABAIXO DA RAIZ.

	//TATARANETOS 3ªGERAÇÃO- QUARTO NIVEL ABAIXO DA RAIZ.
	ArvoreN* noFilho1321200 = new ArvoreN(new Info(899999));

	ArvoreN* noFilho2101110 = new ArvoreN(new Info(87));
	ArvoreN* noFilho2101111 = new ArvoreN(new Info(88));
	//FIM TATARANETOS 3ªGERAÇÃO- QUARTO NIVEL ABAIXO DA RAIZ.


	//TATARANETOS 4ªGERAÇÃO- QUARTO NIVEL ABAIXO DA RAIZ.
	ArvoreN* noFilho13212000 = new ArvoreN(new Info(90));
	//FIM TATARANETOS 4ªGERAÇÃO- QUARTO NIVEL ABAIXO DA RAIZ.





	arvoreRaiz->setFilho(filho1, 0);
	filho1->setPai(arvoreRaiz);
	arvoreRaiz->setFilho(filho2, 1);
	filho2->setPai(arvoreRaiz);
	arvoreRaiz->setFilho(filho3, 2);
	filho3->setPai(arvoreRaiz);
	arvoreRaiz->setFilho(filho4, 3);
	filho4->setPai(arvoreRaiz);
	arvoreRaiz->setFilho(filho5, 4);
	filho5->setPai(arvoreRaiz);


	//FILHO 1: Filhos, netos, bisnetos, tataranetos etc FILHO 1 //
	filho1->setFilho(noFilho10, 0);
	noFilho10->setPai(filho1);
	filho1->setFilho(noFilho11, 1);
	noFilho11->setPai(filho1);
	filho1->setFilho(noFilho12, 2);
	noFilho12->setPai(filho1);
	filho1->setFilho(noFilho13, 3);
	noFilho13->setPai(filho1);
	filho1->setFilho(noFilho14, 4);
	noFilho14->setPai(filho1);
	filho1->setFilho(noFilho15, 5);
	noFilho15->setPai(filho1);

	noFilho10->setFilho(noFilho100, 0);
	noFilho100->setPai(noFilho10);
	noFilho10->setFilho(noFilho101, 1);
	noFilho101->setPai(noFilho10);
	noFilho10->setFilho(noFilho102, 2);
	noFilho102->setPai(noFilho10);

	noFilho100->setFilho(noFilho1000, 0);
	noFilho1000->setPai(noFilho100);

	noFilho102->setFilho(noFilho1020, 0);
	noFilho1020->setPai(noFilho102);
	noFilho102->setFilho(noFilho1021, 1);
	noFilho1021->setPai(noFilho102);

	noFilho11->setFilho(noFilho110, 0);
	noFilho110->setPai(noFilho11);

	noFilho13->setFilho(noFilho130, 0);
	noFilho130->setPai(noFilho13);
	noFilho13->setFilho(noFilho131, 1);
	noFilho131->setPai(noFilho13);
	noFilho13->setFilho(noFilho132, 2);
	noFilho132->setPai(noFilho13);

	noFilho130->setFilho(noFilho1300, 0);
	noFilho1300->setPai(noFilho130);

	noFilho132->setFilho(noFilho1320, 0);
	noFilho1320->setPai(noFilho132);
	noFilho132->setFilho(noFilho1321, 1);
	noFilho1321->setPai(noFilho132);
	noFilho132->setFilho(noFilho1322, 2);
	noFilho1322->setPai(noFilho132);
	noFilho132->setFilho(noFilho1323, 3);
	noFilho1323->setPai(noFilho132);

	noFilho1321->setFilho(noFilho13210, 0);
	noFilho13210->setPai(noFilho1321);
	noFilho1321->setFilho(noFilho13211, 1);
	noFilho13211->setPai(noFilho1321);
	noFilho1321->setFilho(noFilho13212, 2);
	noFilho13212->setPai(noFilho1321);

	noFilho13210->setFilho(noFilho132100, 0);
	noFilho132100->setPai(noFilho13210);
	noFilho13210->setFilho(noFilho132101, 1);
	noFilho132101->setPai(noFilho13210);
	noFilho13210->setFilho(noFilho132102, 2);
	noFilho132102->setPai(noFilho13210);

	noFilho13212->setFilho(noFilho132120, 0);
	noFilho132120->setPai(noFilho13212);
	noFilho13212->setFilho(noFilho132121, 1);
	noFilho132121->setPai(noFilho13212);

	noFilho132120->setFilho(noFilho1321200, 0);
	noFilho1321200->setPai(noFilho132120);

	noFilho1321200->setFilho(noFilho13212000, 0);
	noFilho13212000->setPai(noFilho1321200);


	ArvoreN* arvoreAux99 = new ArvoreN(new Info(99));
	noFilho132100->setFilho(arvoreAux99, 0);
	arvoreAux99->setPai(noFilho132100);

	//FIM FILHO 1: Filhos, netos, bisnetos, tataranetos etc FILHO 1 //


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//FILHO 2: Filhos, netos, bisnetos, tataranetos etc FILHO 2 //
	filho2->setFilho(noFilho20, 0);
	noFilho20->setPai(filho2);
	filho2->setFilho(noFilho21, 1);
	noFilho21->setPai(filho2);

	noFilho20->setFilho(noFilho200, 0);
	noFilho200->setPai(noFilho20);

	noFilho21->setFilho(noFilho210, 0);
	noFilho210->setPai(noFilho21);
	noFilho21->setFilho(noFilho211, 1);
	noFilho211->setPai(noFilho21);
	noFilho21->setFilho(noFilho212, 2);
	noFilho212->setPai(noFilho21);

	noFilho210->setFilho(noFilho2100, 0);
	noFilho2100->setPai(noFilho210);
	noFilho210->setFilho(noFilho2101, 1);
	noFilho2101->setPai(noFilho210);

	noFilho2101->setFilho(noFilho21010, 0);
	noFilho21010->setPai(noFilho2101);
	noFilho2101->setFilho(noFilho21011, 1);
	noFilho21011->setPai(noFilho2101);

	noFilho21011->setFilho(noFilho210110, 0);
	noFilho210110->setPai(noFilho21011);
	noFilho21011->setFilho(noFilho210111, 1);
	noFilho210111->setPai(noFilho21011);


	noFilho210111->setFilho(noFilho2101110, 0);
	noFilho2101110->setPai(noFilho210111);
	noFilho210111->setFilho(noFilho2101111, 1);
	noFilho2101111->setPai(noFilho210111);

	noFilho212->setFilho(noFilho2120, 0);
	noFilho2120->setPai(noFilho212);
	//FIM FILHO 2: Filhos, netos, bisnetos, tataranetos etc FILHO 2 //


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//FILHO 3: Filhos, netos, bisnetos, tataranetos etc FILHO 3 //
	filho3->setFilho(noFilho30, 0);
	noFilho30->setPai(filho3);

	noFilho30->setFilho(noFilho300, 0);
	noFilho300->setPai(noFilho30);
	noFilho30->setFilho(noFilho301, 1);
	noFilho301->setPai(noFilho30);

	noFilho301->setFilho(noFilho3010, 0);
	noFilho3010->setPai(noFilho301);
	noFilho301->setFilho(noFilho3011, 1);
	noFilho3011->setPai(noFilho301);
	noFilho301->setFilho(noFilho3012, 2);
	noFilho3012->setPai(noFilho301);

	noFilho3011->setFilho(noFilho30110, 0);
	noFilho30110->setPai(noFilho3011);
	//FIM FILHO 3: Filhos, netos, bisnetos, tataranetos etc FILHO 3 //


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//FILHO 4: Filhos, netos, bisnetos, tataranetos etc FILHO 4 //
	filho4->setFilho(noFilho40, 0);
	noFilho40->setPai(filho4);
	filho4->setFilho(noFilho41, 1);
	noFilho41->setPai(filho4);
	filho4->setFilho(noFilho42, 2);
	noFilho42->setPai(filho4);
	filho4->setFilho(noFilho43, 3);
	noFilho43->setPai(filho4);

	noFilho41->setFilho(noFilho410, 0);
	noFilho410->setPai(noFilho41);
	noFilho41->setFilho(noFilho411, 1);
	noFilho411->setPai(noFilho41);

	noFilho410->setFilho(noFilho4100, 0);
	noFilho4100->setPai(noFilho410);
	noFilho410->setFilho(noFilho4101, 1);
	noFilho4101->setPai(noFilho410);

	noFilho42->setFilho(noFilho420, 0);
	noFilho420->setPai(noFilho42);
	noFilho42->setFilho(noFilho421, 1);
	noFilho421->setPai(noFilho42);

	noFilho421->setFilho(noFilho4210, 0);
	noFilho4210->setPai(noFilho421);
	noFilho421->setFilho(noFilho4211, 1);
	noFilho4211->setPai(noFilho421);

	//FIM FILHO 4: Filhos, netos, bisnetos, tataranetos etc FILHO 4 //



	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//FILHO 5: Filhos, netos, bisnetos, tataranetos etc FILHO 5 //
	filho5->setFilho(noFilho50, 0);
	noFilho50->setPai(filho5);
	filho5->setFilho(noFilho51, 1);
	noFilho51->setPai(filho5);
	filho5->setFilho(noFilho52, 2);
	noFilho52->setPai(filho5);
	filho5->setFilho(noFilho53, 3);
	noFilho53->setPai(filho5);
	filho5->setFilho(noFilho54, 4);
	noFilho54->setPai(filho5);
	filho5->setFilho(noFilho55, 5);
	noFilho55->setPai(filho5);
	filho5->setFilho(noFilho56, 6);
	noFilho56->setPai(filho5);
	filho5->setFilho(noFilho57, 7);
	noFilho57->setPai(filho5);

	noFilho52->setFilho(noFilho520, 0);
	noFilho520->setPai(noFilho52);
	noFilho52->setFilho(noFilho521, 1);
	noFilho521->setPai(noFilho52);
	noFilho52->setFilho(noFilho522, 2);
	noFilho522->setPai(noFilho52);

	noFilho521->setFilho(noFilho5210, 0);
	noFilho5210->setPai(noFilho521);
	noFilho521->setFilho(noFilho5211, 1);
	noFilho5211->setPai(noFilho521);
	noFilho521->setFilho(noFilho5212, 2);
	noFilho5212->setPai(noFilho521);
	noFilho521->setFilho(noFilho5213, 3);
	noFilho5213->setPai(noFilho521);

	noFilho55->setFilho(noFilho550, 0);
	noFilho550->setPai(noFilho55);
	noFilho55->setFilho(noFilho551, 1);
	noFilho551->setPai(noFilho55);

	noFilho57->setFilho(noFilho570, 0);
	noFilho570->setPai(noFilho57);

	noFilho570->setFilho(noFilho5700, 0);
	noFilho5700->setPai(noFilho570);
	noFilho570->setFilho(noFilho5701, 1);
	noFilho5701->setPai(noFilho570);
	//FIM FILHO 5: Filhos, netos, bisnetos, tataranetos etc FILHO 5 //


//	printf("\n\n\t %d \t\n\n", arvoreRaiz->getInfo()->getId());

	//Teste com filho do filho2
//	ArvoreN* netoFilho1Teste = arvoreRaiz->getFilho(1)->getFilho(1)->getFilho(0);

//	ArvoreN* netoFilho1Teste = arvoreRaiz->getFilho(1)->getFilho(1)->getFilho(0)->getFilho(1);
//	printf("\n\n\t %d \t\n\n", netoFilho1Teste->getInfo()->getId());



	printf("\n\n\n");

	arvoreRaiz->preOrder(arvoreRaiz);
	printf("\n\n\n\n__________________________________________________________________________________________\n");
	arvoreRaiz->preOrder2(arvoreRaiz);


//	arvoreRaiz->preOrder();




	return 0;
}
