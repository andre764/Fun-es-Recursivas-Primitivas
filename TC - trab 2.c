#include<stdio.h> /*-------------------------------LISTA-----------------------------------------------


� Soma (retorna x + y)
� Subtra��o (retorna x - y)
� Multiplica��o (retorna x * y)
� Divis�o (retorna x/y)
� Elevado (retorna x^y)
� Fatorial (retorna x!)
� Maior que (retorna 1 se x > y e 0, caso contr�rio)
� Menor que (retorna 1 se x < y e 0, caso contr�rio)
� Igual a (retorna 1 se x = y e 0, caso contr�rio)
� Maior que ou igual a (retorna 1 se x = y e 0, caso contr�rio)
� Menor que ou igual a (retorna 1 se x = y e 0, caso contr�rio)
� Par (retorna 1 se x � par e 0, caso contr�rio. Considere 0 par)
� �mpar (retorna 1 se x � �mpar e 0, caso contr�rio. Considere 0 par)

------------------------------APRESENTA��O------------------------------------------------

� Maior que (retorna 1 se x > y e 0, caso contr�rio)
� Menor que (retorna 1 se x < y e 0, caso contr�rio)
� Igual a (retorna 1 se x = y e 0, caso contr�rio)
� Maior que ou igual a (retorna 1 se x = y e 0, caso contr�rio)
� Menor que ou igual a (retorna 1 se x = y e 0, caso contr�rio)
� Par (retorna 1 se x � par e 0, caso contr�rio. Considere 0 par)

-----------------------------COME�O DA LISTA----------------------------------*/

//Zero
int zero(int x){
	return 0;
}
// Fun��o sucessora
int sucessora(int x){
	return x+1;
}
// Fun��o antecessora
int antecessor(int x){
	if(x==0)
		return 0;
	else 
		return x-1;
}
//Fun��o proje��o
int pojecao(int x, int y, int p){
	if(p==1){
		return x;
	}else if(p==2){
		return y;
	}
}
/*-------------------------------------------------------------------------*/

//Fun��o soma 
int soma(int x, int y){
	if(y==0){
		return x;
	} else {
		return sucessora(soma(x,y-1));
	}
}
// Fun��o subtra��o
int subtracao(int x, int y){
	if(x==0)
		return 0;
	if(y==0)
		return x;
	else 
		return subtracao(antecessor(x),antecessor(y));
}
//Fun��o multiplica��o
int multiplicacao(int x, int y){
	if(y==0){
		return 0;
	} else {
		return soma(x,multiplicacao(x,y-1));
	}
}
// Fun��o divis�o
int divisao(int x, int y){
	if(x==0)
		return 0;
	else 
		return sucessora(divisao(subtracao(x,y),y));
}
//Fun��o elevado
int elevado(int x, int y){
	if(y==0){
		return 1;
	}else{
		return multiplicacao(x,elevado(x,y-1));
	}
}
//Fatorial (retorna x!)
int fatorial(int x){
	if(x==0){
		return 1;
	}else{
		return multiplicacao(x,fatorial(x-1)); //10*9*8*7*6*5*4*3*2*1
	}
}

//------------------------------------COME�O DA APRESENTA��O------------------------------

//Maior que (retorna 1 se x > y e 0, caso contr�rio)
int M(int x, int y){
	
	if((subtracao(x,y))==1){
		return 0;
	}else{
		return 1;
	}
}
//Menor que (retorna 1 se x < y e 0, caso contr�rio)
int m(int x, int y){
	
	if(subtracao(x,y)==0){
		printf(" = menor ");
		return 1;
	}else{
		printf(" = maior");
		return 0;
	}
}
// Igual a (retorna 1 se x = y e 0, caso contr�rio)
int igual(int x, int y){
	if((x==0)&&(y==0)){
		return 1;
	}else if((x==0)||(y==0)){
		return 0;
	}else{
		return igual(antecessor(x), antecessor(y));
	}
}
// Maior que ou igual a (retorna 1 se x = y e 0, caso contr�rio)
int MI(int x, int y){
	if(x>=y){
		return 1;
	}else{
		return 0;
	}
}
// Menor que ou igual a (retorna 1 se x = y e 0, caso contr�rio)
int mi(int x, int y){
	if(x<=y){
		return 1;
	}else{
		return 0;
	}
}
// Par (retorna 1 se x � par e 0, caso contr�rio. Considere 0 par)
int par(int x){
	if(x==0)
		return 1;
	else
		return impar(x-1);
}
// �mpar (retorna 1 se x � �mpar e 0, caso contr�rio. Considere 0 par)
int impar(int x){
	if(x==0){
		return 0;
	}else
		return par(x-1);
}
//-------------------------------------------------ENUNCIADO 5 Come�a aqui--------------------------------------------------------------------------------------------------------
/*
1. Desenvolva uma m�quina de Post que reconhe�a a Linguagem L, formada sobre
o alfabeto {a, b, c}, de modo que L = {a nb 2nc | n = 0}. Considere que, ao ler e, a m�quina entra em estado de rejei��o (0,8 ponto)
*/
/*
int ord_selecao(int a){
	int i;
	for(i=0;i<){
		
	}
	
}
*/



//---------------------------------------------------------------------------------------------------------------------------------------------------------
/*
2. Usando apenas as fun��es b�sicas, composi��o e recurs�o primitiva, mostre que
as fun��es abaixo s�o recursivas primitivas. Observa��o: todas as fun��es
utilizadas devem estar definidas. (1,2 ponto)
a. Soma_Quadrado(x,y), que retorna o valor de x2+y2.
b. Resto(x), que retorna o resto da divis�o de x por 3.
c. M�nimo(x,y), que retorna o valor m�nimo entre x e y.
*/
//---------------------------------------------------------------------------------------------------------------------------------------------------------

// 2 A
int soma_quadrado(int x, int y){
	if(x==0)
		return 0; // exemplo: 0^2=0
	if(y==0)
		return 1; //Exemplo: 8^0=1
	else 
		return soma((elevado(x,y)),(elevado(x,y)));  //return multiplicacao(x,elevado(x,y-1));
}

//2. B 
int resto(int x, int y){
	int a;
	int b;
	if((divisao(x,y))==0){
		return 0;
	}else if((divisao(x,y))!=0){
		a=divisao(x,y);
		b=a*2-4;
		return b;
	}
}

// 2. C  
// Ex: Valor m�nimo entre 4 e 2 � 2
int minimo(int x, int y){
	return subtracao(x,y);
}



int main(){
	
	int x=4, y=2, z=2, p=1;
	printf("valor de teste\n");
	printf("x: %d \ny: %d \n", x, y);
	printf("\n___________________________________________________________________\n");
	
	printf("\nExercicios da lista:\n");
	printf("\nValores resultantes:\n");
	printf("\nFuncao soma: %d", soma(x, y));
	printf("\nFuncao subtracao: %d",subtracao(x, y));
	printf("\nFuncao multiplicacao: %d",multiplicacao(x, y));
	printf("\nFuncao divisao: %d",divisao(x, y));
	printf("\nFuncao elevado: %d",elevado(x, y));
	printf("\nFuncao fatorial: %d", fatorial(x));

	printf("\n\n___________________________________________________________________\n\n");
	
	printf("valor de teste\n");
	printf("x: %d \ny: %d \n", x, y);
	
	printf("\n\nExercicios para apresentacao:\n");
	printf("\nValores resultantes:\n");
	printf("\nMaior que: %d",M(x, y));
	printf("\nMenor que: %d",m(x, y));
	printf("\nigual a: %d",igual(x, y));
	printf("\nMaior ou igual: %d",MI(x,y));
	printf("\nmenor ou igual: %d",mi(x,y));
	printf("\nPar: %d", par(x));
	printf("\nimpar: %d", impar(x));
	
	
	printf("\n\n___________________________________________________________________\n");
	printf("\nENUNCIADO 5:\n");
	printf("\nParte 1:\n");
	
	
	
	// Quest�o 2 do Enunciado 5
	printf("\nParte 2:\n");
	printf("\nSoma_Quadrado %d",soma_quadrado(x,y)); // 2.A
	printf("\nResto %d",resto(x,y)); //2.B
	printf("\nMinimo %d",minimo(x,y)); //2.C
	
	
	
	printf("\n");	
	printf("\n___________________________________________________________________\n");
	
	
	//AUTORES: Andre Luiz, Lary, Thiago
	
	

	printf("\n\n\n\n\n");
}
