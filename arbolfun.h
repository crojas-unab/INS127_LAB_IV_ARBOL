/************************************************************************************************
*    Programa: Guia de ejercicios                                                           *
*    Objetivo: Libreria                                                                        *
*    Autor/Grupo: Cristian Rojas Saavedra                                                       *
*    Asignatura: Estructura de datos     Sección: 652                                           *
*************************************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct info {
	int num;
	
}Info;

typedef struct nodoArbol{
	Info* elem;
	struct nodoArbol *izq;
	struct nodoArbol *der;
}nodoArbol;


nodoArbol* crear(int praiz){
	nodoArbol *nd=(nodoArbol*) malloc(sizeof(nodoArbol));
	nd->izq=NULL;
	nd->der=NULL;
	Info *dato =(Info*) malloc(sizeof(Info));
	dato->num=praiz;
	nd->elem=dato;
	return nd;	
}

void Hijoizq(nodoArbol* raiz, nodoArbol* num){
    raiz->izq = num;
}

void Hijoder(nodoArbol* raiz, nodoArbol* num){
    raiz->der = num;
}

void nArbol(nodoArbol *n1){
    printf(" %d ",n1->elem->num);
    
}

void preorden(nodoArbol* raiz){
    if(raiz != NULL){
        nArbol(raiz);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void inorden(nodoArbol* raiz){
    if(raiz != NULL){        
        preorden(raiz->izq);
        nArbol(raiz);
        preorden(raiz->der);
    }
}

void postorden(nodoArbol* raiz){
    if(raiz != NULL){        
        preorden(raiz->izq);        
        preorden(raiz->der);
        nArbol(raiz);
    }
}

int busNod(nodoArbol* raiz, int numero){
    int valor = 0;
    if(raiz == NULL){
        return 0;
    }else if(raiz->elem->num == numero){
        return 1;
    }else{
        valor =  busNod(raiz->izq, numero);
        if(valor != 1){
            valor = busNod(raiz->der,numero);
        }
    }
    
    return valor;
    
}

int Peso(nodoArbol* raiz){
    if(raiz == NULL){
        return 0;
    }
    
    return 1 + Peso(raiz->izq) + Peso(raiz->der);
}


int cantHojas(nodoArbol* raiz){
	if(raiz == NULL){
		return 0;
	}
    if(raiz->izq == NULL && raiz->der == NULL){
        return 1;
    }
	else{
        return cantHojas(raiz->izq) + cantHojas(raiz->der);
	}
}

int Full(nodoArbol* raiz){
    int valor = 0;
    
    if(raiz == NULL){
        return 0;
    }
	if((raiz->der == NULL ) + (raiz->izq == NULL) == 1){
        return 1;
    }else{
        valor = Full(raiz->izq);
        if(valor != 1){
            valor = Full(raiz->der);
        }
    }
    return valor;
}

int sumaArbol(nodoArbol* raiz){
    if(raiz == NULL){
        return 0;
    }
    return raiz->elem->num + sumaArbol(raiz->izq) + sumaArbol(raiz->der);
}

int Altura(nodoArbol* nodo){
	int Altizq=0, Altder=0;
	if (nodo==NULL){
		return 0;
	}
	else{
		Altizq= Altura(nodo->izq);
		Altder= Altura(nodo->der);
		if 	(Altizq>Altder){
			return Altizq+1;
		}
		else{
			return Altder+1;
		}
		
	}
	
}

int Profundidad(nodoArbol* nodo){
	int profizq=0, profder=0;
	if (nodo==NULL){
		return 0;/* Arbol vacio*/
	}
	else{
		profizq= Profundidad(nodo->izq);
		profder= Profundidad(nodo->der);
		if 	(profizq>profder){
			return profizq+1;
		}
		else{
			return profder+1;
		}
		
	}
	
}



