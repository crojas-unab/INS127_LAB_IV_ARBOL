/************************************************************************************************
*    Programa: Guia de ejercicios LAB 04                                                           *
*    Objetivo:                                                                                  *
*    Autor/Grupo: Cristian Rojas Saavedra                                                       *
*    Asignatura: Estructura de datos     Sección: 652                                           *
*************************************************************************************************/ 


#include "arbolfun.h"


int main(int argc, char argv){
	nodoArbol *raiz;
	raiz = crear(15);
	Hijoder(raiz,crear(2));
	Hijoizq(raiz,crear(7));
	Hijoizq(raiz->izq,crear(9));
	Hijoder(raiz->izq,crear(17));
	//Hijoizq(raiz->der,crear(23));
	Hijoder(raiz->der,crear(4));
	Hijoizq(raiz->der->der,crear(5));
	Hijoder(raiz->der->der,crear(13));
	
	
	printf("\n");
	preorden(raiz);
	printf("\n");
	inorden(raiz);
	printf("\n");
	postorden(raiz);
	printf("\n\n");
	
	int busc=0;
	printf("Ingrese el numero a buscar -->");
	scanf("%d",&busc);
	printf("\n");
	
	int resultado=busNod(raiz, busc);
	if (resultado==1){
		printf("El numero %d fue Encontrado\n\n",busc);
	}else{
		printf("El numero %d No existe\n\n",busc);
	}
	
	int peso=Peso(raiz);
	printf("El peso del arbol --> %d\n\n",peso);
	
	int hojas=cantHojas(raiz);
	printf("Las hojas del Arbol son --> %d\n\n",hojas);
	
	int full=Full(raiz);
	if (full==0){
		printf("El Arbol esta Lleno\n\n");
	}else{
		printf("El Arbol no esta Lleno\n\n");
	}
	
	int suma=sumaArbol(raiz);
	printf("La suma del arbol es --> %d\n\n",suma);
	
	
	
	int altura=Altura(raiz);
	printf("La Altura del arbol es --> %d\n\n",altura);
	
	int prof=Profundidad(raiz);
	printf("La Profundida del arbol es --> %d\n\n",prof);
	
	
	return 0;
}



