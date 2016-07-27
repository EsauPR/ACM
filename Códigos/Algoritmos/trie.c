#include <stdio.h>
#include <stdlib.h>
#define T 26

typedef struct nodo{
	struct nodo *nodos[T];
	int prefijo, palabras;
}TRIE;

void inicializar(TRIE *R){
	R->palabras=R->prefijo=0;
	for(int i=0; i<T; i++)
		R->nodos[i]=NULL;
}

void insertar(TRIE * R, char *pal)
{
	if(*pal=='\0')
	{
		R->palabras++;
		return;
	}
	R->prefijo++;
	int k=*pal-'A';
	if(R->nodos[k]==NULL)
	{
		R->nodos[k]=(TRIE *)malloc(sizeof(TRIE));
		inicializar(R->nodos[k]);
	}
	insertar(R->nodos[k], pal+1);
}

int total(TRIE R) //total de palabras
{
	return R.prefijo;
}

int pal_existe(TRIE R, char *pal) //numero de veces que se repite una palabra
{
	if(*pal=='\0')
		return R.palabras;
	int k=*pal-'A';
	if(R.nodos[k]==NULL)
		return 0;
	return pal_existe(*(R.nodos[k]),pal+1);
}

int pal_pref(TRIE R, char *pal) //numero que tienen el mismo prefijo
{
	if(*pal=='\0')
		return R.prefijo;
	int k=*pal-'A';
	if(R.nodos[k]==NULL)
		return 0;
	return pal_pref(*(R.nodos[k]),pal+1);
}

int main()
{
	TRIE R={{NULL},0,0};
	int i,k,done=1;
	char pal[100];
	printf("!: insertar palabra, 2: Veces que se repite una palabra, 3: Numero de palabras con un prefijo en especial, 4: Total de palabras\n\n");
	
	for(i=0; i<1000000; i++)
	{
		scanf("%s", pal);
		insertar(&R,pal);
	}
	for(i=0; i<1000000; i++)
	{
		scanf("%s", pal);
		printf("%d\n",pal_existe(R,pal));
	}
	
	/*
	while(done)
	{
		printf("Caso: ");
		scanf("%d", &i);
		switch(i)
		{
			case 1: printf("Ingresa palabra: "); scanf("%s", pal); printf("\n");
					insertar(&R,pal);
					break;
			case 2: printf("Ingresa palabra: "); scanf("%s", pal);
					k=pal_existe(R,pal);
						printf("Num: %d\n\n", k);
					break;
			case 3: printf("Ingresa prefijo: "); scanf("%s", pal);
					k=pal_pref(R,pal);
						printf("Num: %d\n\n", k);
					break;
					
			case 4: printf("Total: %d\n\n", total(R));
					break;		
			case 0: done=0;
					break;
		}
		
		
	}
	
	*/
	return 0;
}
