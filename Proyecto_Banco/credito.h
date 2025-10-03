#pragma once
#ifndef CREDITO_H
#define CREDITO_H

#include <iostream>
#include <string>

using namespace std;

class Credito {
protected:
    double monto_prestamo;
    int plazo_meses;
    double tasa_interes;
    double saldo_pendiente;

public:
    // Constructor
    Credito(double monto, int plazo, double tasa)
        : monto_prestamo(monto), plazo_meses(plazo), tasa_interes(tasa), saldo_pendiente(monto) {
    }

    // Destructor virtual
    virtual ~Credito() {}

    // Métodos
    virtual void desembolsar() {
        cout << "Desembolsando crédito por: $" << monto_prestamo << endl;
        saldo_pendiente = monto_prestamo;
    }

    virtual void pagarCuota(double monto) {
        if (monto <= saldo_pendiente) {
            saldo_pendiente -= monto;
            cout << "Pago realizado. Saldo pendiente: $" << saldo_pendiente << endl;
        }
        else {
            cout << "Monto excede el saldo pendiente" << endl;
        }
    }

    virtual double calcularInteres() const {
        return saldo_pendiente * tasa_interes;
    }

    virtual void generarCronogramaPagos() const {
        cout << "=== CRONOGRAMA DE PAGOS ===" << endl;
        cout << "Monto total: $" << monto_prestamo << endl;
        cout << "Plazo: " << plazo_meses << " meses" << endl;
        cout << "Tasa de interés: " << (tasa_interes * 100) << "%" << endl;

        double cuota = monto_prestamo / plazo_meses;
        double saldo = monto_prestamo;

        for (int i = 1; i <= plazo_meses; i++) {
            double interes = saldo * tasa_interes;
            double amortizacion = cuota - interes;
            saldo -= amortizacion;

            cout << "Mes " << i << ": Cuota $" << cuota
                << " (Interés: $" << interes << ", Amortización: $" << amortizacion << ")" << endl;
        }
    }

    // Getters
    double getMontoPrestamo() const { return monto_prestamo; }
    int getPlazoMeses() const { return plazo_meses; }
    double getTasaInteres() const { return tasa_interes; }
    double getSaldoPendiente() const { return saldo_pendiente; }

    // Setters
    void setTasaInteres(double tasa) { tasa_interes = tasa; }
    void setSaldoPendiente(double saldo) { saldo_pendiente = saldo; }
};



////////////////////////////////////////////////////
// LISTA ENLAZADA PARA GESTIÓN DE CREDITO
////////////////////////////////////////////////////
template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;

    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};

template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;
    int tamano;

public:
    // Constructor
    ListaEnlazada() : cabeza(nullptr), tamano(0) {}

    // Destructor
    ~ListaEnlazada() {
        limpiar();
    }

    // Método 1: Insertar al final
    void insertarFinal(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);

        if (!cabeza) {
            cabeza = nuevoNodo;
        }
        else {
            Nodo<T>* actual = cabeza;
            while (actual->siguiente) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
        tamano++;
    }

    // Método 2: Filtrar con lambda
    ListaEnlazada<T> filtrar(function<bool(T)> criterio) {
        ListaEnlazada<T> resultado;
        Nodo<T>* actual = cabeza;

        auto filtrarElementos = [&](Nodo<T>* actual, function<bool(T)> criterio) {
            while (actual) {
                if (criterio(actual->dato)) {
                    resultado.insertarFinal(actual->dato);
                }
                actual = actual->siguiente;
            }
            };

        filtrarElementos(actual, criterio);
        return resultado;
    }

    // Método 3: Aplicar función a todos los elementos
    void transformar(function<void(T&)> funcion) {
        Nodo<T>* actual = cabeza;
        while (actual) {
            funcion(actual->dato);
            actual = actual->siguiente;
        }
    }

    // Métodos auxiliares
    int getTamano() const {
        return tamano;
    }

    bool estaVacia() const {
        return cabeza == nullptr;
    }

    void limpiar() {
        while (cabeza) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
        tamano = 0;
    }
};
#endif
