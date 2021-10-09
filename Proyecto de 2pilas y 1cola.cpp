#include<iostream>
#include<stdlib.h>
											/* 		**El proyecto esta terminado** 
												Este programa contiene dos pilas y una cola
												e intercambia elementos entre pilas a pilas
												y de pilas a colas y viceversa tambien elimina 
												elementos de cada uno de ellos y en total tiene 
												273 lineas de codigo totalmente todas hechas por > Leandro Brito Contreras <.*/

struct Nodo{
	int dato;
	Nodo *siguiente;
};

//prototipos de funcion
void opc_mostrar_pila();
void quitar_e_ingresar_elementos_aleatorios();
void eliminar_de_cola(Nodo *&,int);
void opc_eliminar_de_pilas();
void eliminar_de_pila(Nodo *&,int);
void ingresar_pilas();
void mostrar_pila(Nodo *);
void mostrar_cola(Nodo *);
//pilas
void agregar_pila1(Nodo *&,int);
void agregar_pila2(Nodo *&,int);
//colas
void agregar_cola(Nodo *&,Nodo *&,int);
//menu
void menu();


//variables globales

//pilas
Nodo *pila1=NULL,*pila2=NULL;
//colas
Nodo *frente=NULL,*fin=NULL;

int main(){//main
	menu();
}//main


//menu
void menu(){
	char opc,opc2;
	int dato;
	do{
		system("cls");
		std::cout<<"\t.:MENU PRINCIPAL:.\n\n";
		std::cout<<"\n1. Agregar un numero a pila";
		std::cout<<"\n2. Agregar un numero a cola";
		std::cout<<"\n3. Eliminar un numero de pila";
		std::cout<<"\n4. Eliminar un numero de cola";
		std::cout<<"\n5. Quitar e ingresar elementos aleatorios";
		std::cout<<"\n6. mostrar pilas";
		std::cout<<"\n7. mostrar cola";
		std::cout<<"\n8. Salir";
		std::cout<<"\nOpcion: ";std::cin>>opc;
		
		switch(opc){
			case '1': ingresar_pilas();break;
			case '2': std::cout<<"\nDigite el dato: ";std::cin>>dato;agregar_cola(frente,fin,dato);break;
			case '3': opc_eliminar_de_pilas();break;
			case '4': std::cout<<"\nDigite el dato a eliminar: ";std::cin>>dato;eliminar_de_cola(frente,dato);break;
			case '5': quitar_e_ingresar_elementos_aleatorios();break;
			case '6': opc_mostrar_pila();break;
			case '7': mostrar_cola(frente);break;
			case '8': std::cout<<"\nPROGRAMA FINALIZADO\n\n";break;
		}
		std::cout<<"\n";
		system("pause");
	}while(opc!='8');
}

//pilas

//pila #1
void agregar_pila(Nodo *&pila,int dato){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->dato=dato;
	nuevo_nodo->siguiente=pila;
	pila=nuevo_nodo;
}

//cola #1
void agregar_cola(Nodo *&fente,Nodo *&fin,int dato){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->dato=dato;
	nuevo_nodo->siguiente=NULL;
	
	if(frente==NULL){
		frente=nuevo_nodo;
		fin=nuevo_nodo;
	}
	else{
		fin->siguiente=nuevo_nodo;
		fin=nuevo_nodo;
	}
}

//mostrar pila
void mostrar_pila(Nodo *pila){
	if(pila==NULL){
		std::cout<<"\nLa pila esta vacia\n\n";
	}
	else{
		std::cout<<"\nPILA: ";
		while(pila!=NULL){
			std::cout<<pila->dato<<" ";
			pila=pila->siguiente;
		}
	}
}

//mostrar cola
void mostrar_cola(Nodo *frente){
	Nodo *aux=frente;
	if(aux==NULL){
		std::cout<<"\nLa cola esta  vacia\n\n";
	}
	else{
		std::cout<<"\nCOLA: ";
		while(aux!=NULL){
			std::cout<<aux->dato<<" ";
			aux=aux->siguiente;
		}
	}
}

//ingresar en pilas
void ingresar_pilas(){
	int dato;
	char opc;
	std::cout<<"\nDigite el dato: ";std::cin>>dato;
	std::cout<<"\nIngresar en ( 1. pila#1 | 2. pila#2 ): ";std::cin>>opc;
	switch(opc){
		case '1': agregar_pila(pila1,dato);break;
		case '2': agregar_pila(pila2,dato);break;
		default: std::cout<<"\nOpcio incorecta\n\n";break;
	}
}

//elimina un nmero de pilas
void eliminar_de_pila(Nodo *&pila,int dato){
	Nodo *aux=pila,*aux2;
	if(aux==NULL){
		std::cout<<"\nLa pila esta vacia\n\n";
	}
	else{
		while((aux!=NULL) && (aux->dato!=dato)){
			aux2=aux;
			aux=aux->siguiente;
		}
		
		if(aux==NULL){
			std::cout<<"\nDato no encontrado\n\n";
		}
		else if(aux->dato==dato){
			aux2->siguiente=aux->siguiente;
			delete aux;
		}
	}
}

//opcion #3 del menu
void opc_eliminar_de_pilas(){
	int dato;
	char opc;
	std::cout<<"\nDigite el dato: ";std::cin>>dato;
	std::cout<<"\nEliminar de (1. pila#1 | 2. pila#2 ): ";std::cin>>opc;
	switch(opc){
		case '1': eliminar_de_pila(pila1,dato);break;
		case '2': eliminar_de_pila(pila2,dato);break;
		default: std::cout<<"\nOPCION INVALIDA\n\n";
	} 
}

//elimina un elemento de cola
void eliminar_de_cola(Nodo *&frente,int dato){
	Nodo *aux=frente,*aux2;
	if(aux==NULL){
		std::cout<<"\nLA COLA ESTA VACIA\n\n";
	}
	else if(aux->dato==dato){
		frente=frente->siguiente;
		delete aux;
	}
	else{
		while((aux!=NULL) && (aux->dato!=dato)){
			aux2=aux;
			aux=aux->siguiente;
		}
		if(aux==NULL){
			std::cout<<"\nDato no encontrado\n\n";
		}
		else if(aux->dato==dato){
			aux2->siguiente=aux->siguiente;
			delete aux;
		}
	}
}

//pasa un numero de una pila a otra y de una pila a cola
void quitar_e_ingresar_elementos_aleatorios(){
	char opc;
	int dato;
	std::cout<<"\n1. quitar de pila1 a pila2";
	std::cout<<"\n2. quitar de pila1 a cola";
	std::cout<<"\n3. quitar de pila2 a pila1";
	std::cout<<"\n4. quitar de pila2 a cola";
	std::cout<<"\n5. quitar de cola a pila1";
	std::cout<<"\n6. quitar de cola a pila2";
	std::cout<<"\n7. Volver al menu principal";
	std::cout<<"\nOpcion: ";std::cin>>opc;
	
	switch(opc){
		case '1': 
				std::cout<<"\nDigite el dato: ";std::cin>>dato;
				eliminar_de_pila(pila1,dato);//eliminando de pila 1
				agregar_pila(pila2,dato);//agregando a pila 2
				std::cout<<"\nHECHO\n\n";
				break;
		case '2': 
				std::cout<<"\nDigite el dato: ";std::cin>>dato;
				eliminar_de_pila(pila1,dato);//eliminado de pila 1
				agregar_cola(frente,fin,dato);//agregando a cola
				std::cout<<"\nHECHO\n\n";
				break;
		case '3': 
				std::cout<<"\nDigite el dato: ";std::cin>>dato;
				eliminar_de_pila(pila2,dato);//eliminando de pila 2
				agregar_pila(pila1,dato);//agregando a pila 1
				std::cout<<"\nHECHO\n\n";
				break;
		case '4':
				std::cout<<"\nDigite el dato: ";std::cin>>dato;
				eliminar_de_pila(pila2,dato);//eliminado de pila 2
				agregar_cola(frente,fin,dato);//agregando a cola
				std::cout<<"\nHECHO\n\n";
				break;
		case '5':
				std::cout<<"\nDigite el dato: ";std::cin>>dato;
				eliminar_de_cola(frente,dato);//eliminando de cola
				agregar_pila(pila1,dato);//agregando a pila 1
				std::cout<<"\nHECHO\n\n";
				break;
		case '6':
				std::cout<<"\nDigite el dato: ";std::cin>>dato;
				eliminar_de_cola(frente,dato);//eliminando de cola
				agregar_pila(pila2,dato);//agregando a pila 2
				std::cout<<"\nHECHO\n\n";
				break;
		case '7': break;
		default: std::cout<<"\nOPCION INCORECTA\n\n";break;
	}
}

//mostrar pila
void opc_mostrar_pila(){
	char opc;
	std::cout<<"\n1. Mostrar pila 1";
	std::cout<<"\n2. Mostrar pila 2";
	std::cout<<"\n3. Mostrar todas las pilas";
	std::cout<<"\nOpcion: ";std::cin>>opc;
	
	switch(opc){
		case '1': mostrar_pila(pila1);break;
		case '2': mostrar_pila(pila2);break;
		case '3': std::cout<<"\nPILA#1: ";mostrar_pila(pila1);std::cout<<"\n\n";std::cout<<"\nPILA#2: ";mostrar_pila(pila2);break;
		default: std::cout<<"\nOPCION INCORRECTA\n\n";
	}
}