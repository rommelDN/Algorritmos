#pragma once
#include <iostream>
#include <string>
using namespace std;

////////////////////////////////////////////////
// CLASE BASE TRANSACCION
////////////////////////////////////////////////
template<typename TInt,typename TString,typename TDouble>
class Transaccion {
private:
	TInt id_transaccion;
	TString tipo; // "depósito" o "retiro"
	TDouble monto;
	TString fecha;
public:
	// Constructor
	Transaccion(TInt id_transaccion, TString tipo, TDouble monto, TString fecha)
		:id_transaccion(id_transaccion), tipo(tipo), monto(monto), fecha(fecha) {};

	void mostrar(){
		cout<<"Transacción ID: "<<id_transaccion
			<<" | Tipo: "<<tipo
			<<" | Monto: $"<<monto
			<<" | Fecha: "<<fecha
			<<endl;
	}
};
////////////////////////////////////////////////
//NODO TRANSACCION
//Cada nodo contiene una transacción y un puntero al siguiente nodo
////////////////////////////////////////////////
template<typename T>
struct NodoTR {
	T* dato;
	NodoTR* siguiente;

	NodoTR(T* t) {
		dato = t;
		siguiente = nullptr;
	};
};
////////////////////////////////////////////////
//Lista Enlazada para manejar Transacciones
////////////////////////////////////////////////
template<typename T>
class Lista {
private:
	NodoTR<T>* cabeza;
public:
	//Constructor
	Lista() { cabeza = nullptr; };

	//Métodos
	void agregar(T* t) {
		NodoTR<T>* nuevo = new NodoTR<T>(t);
		if (cabeza == nullptr) {
			cabeza = nuevo;
		}
		else {
			NodoTR<T>* actual = cabeza;
			while (actual->siguiente != nullptr) {
				actual = actual->siguiente;
			}
			actual->siguiente = nuevo;
		}

	}
	void mostra() {
		if (cabeza == nullptr) {
			cout << "No hay transacciones." <<endl;
			return;
		}
		NodoTR<T>* actual = cabeza;
		while (actual != nullptr) {
			actual->dato->mostrar();
			actual = actual->siguiente;
		}
	}

};


