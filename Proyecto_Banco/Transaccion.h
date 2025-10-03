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
			<< std::endl;
	}
};
////////////////////////////////////////////////
//NODO TRANSACCION
//Cada nodo contiene una transacción y un puntero al siguiente nodo
////////////////////////////////////////////////
template<typename T>
struct Nodo
{
	T dato;
	Nodo* siguiente;

	Nodo(T* t) {
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
	Nodo<T>* cabeza;
public:
	//Constructor
	Lista() { cabeza = nullptr; };

	//Métodos
	void agregar(T* t) {
		Nodo<T>* nuevo = new Nodo<T>(t);
		if (cabeza == nullptr) {
			cabeza = nuevo;
		}
		else {
			Nodo<T>* actual = cabeza;
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
		Nodo<T>* actual = cabeza;
		while (actual != nullptr) {
			actual->transaccion->mostrar();
			actual = actual->siguiente;
		}
	}

};


