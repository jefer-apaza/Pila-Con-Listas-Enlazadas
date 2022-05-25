#include <iostream>
using namespace std;

struct Nodo{
	int dato; 
	struct Nodo *sig;
};
typedef Nodo *ptrPila; //creacion del nodo tipo puntero

//apilar

void push (ptrPila &p, int valor)
{
	ptrPila aux;
	aux = new(struct Nodo); //apunta al nuevo nodo creado
	aux -> dato = valor;
	 
	aux -> sig = p;
	p = aux;
	
}

//desapilar
int pop(ptrPila &p){
	
	int num;
	ptrPila aux;
	
	aux = p;
	num = aux -> dato; //asignamos el primer valor
	
	p = aux -> sig;
	delete(aux);
	
	return num;
}

//mostrar elementos

void mostrarP(ptrPila p){
	
	ptrPila aux;
	aux = p;
	while(aux != NULL){
		cout<<"\t"<< aux -> dato <<endl;
		aux = aux -> sig;
	}
	
}
 //eliminar pila 
 void destruirP (ptrPila &p){
	
	ptrPila aux;
	
	while(p != NULL){
		aux = p;
		p = aux -> sig;
		delete(aux);
	} 
}
void menu(){
	cout<<"\n\tIngenieria de Sistemas";
	cout<<"\n\tPilas Con Listas\n";
	cout<<"\n1. Push\t";
	cout<<"\n2. Pop\t";
	cout<<"\n3. Mostrar\t";
	cout<<"\n4. Eliminar\t";
	cout<<"\n5. Cerrar\t";
	cout<<"\n\nIngrese Opcion: ";
}

int main(){
	
	ptrPila p = NULL; 
	int dato;
	int op;
	int x;
	
	do
	{
		menu();
		cin>> op;
		switch(op){
			case 1:
				cout<<"\nNumero para apilar: ";
				cin>>dato;
				push(p,dato);
				cout<<"\n\nEl Numero "<<dato<<" ah sido apilado.\n";
			break;
			
			case 2:
				x = pop(p);
				cout<<"\n\nEl Numero "<<x<<" ah sido desapilado.\n";
			break;
			
			case 3:
				cout<<"\nMostrando la Lista: \n";
				if(p != NULL){
					mostrarP(p);
				}
				else{
					cout<<"\nPila Vacia";
				}	
			break;
			
			case 4:
				destruirP(p);
				cout<<"\nPila Eliminada";
			break;
			
			default:
				cout<<"Cerrando"<<endl;			
		}
			cout<<endl;
		
	}while(op != 5);
	
	return 0;
		
}
