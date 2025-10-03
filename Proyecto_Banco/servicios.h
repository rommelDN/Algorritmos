#pragma once
#include <iostream>
#include <string>
#include <functional>

using namespace std;


template <typename TCodigo, typename TSaldo, typename TTitular, typename TCuenta, typename TFApertura>
class Servicios;

////////////////////////////////////////////////////
// CLASE BASE SERVICIOS
////////////////////////////////////////////////////
template <typename TCodigo, typename TSaldo, typename TTitular, typename TCuenta, typename TFApertura>
class Servicios {
public:
    TCodigo id_servicio;
    TSaldo saldo;
    TCuenta numero_cuenta;
    TTitular titular;
    TFApertura fecha_apertura;

public:
    // Constructor
    Servicios(TCodigo id_servicio, TSaldo saldo, TTitular titular, TCuenta numero_cuenta, TFApertura fecha_apertura)
        : id_servicio(id_servicio), saldo(saldo), titular(titular), numero_cuenta(numero_cuenta), fecha_apertura(fecha_apertura) {
    };

    // Destructor
    virtual ~Servicios() {};

    // Métodos
    void consultarSaldo() const {
        cout << "El saldo actual es: $" << saldo << endl;
    }

    void cancelarServicio() const {
        cout << "Servicio cancelado: " << id_servicio << endl;
    }

    void generarEstadoCuenta() const {
        cout << "=== ESTADO DE CUENTA ===" << endl
            << "|   ID Servicio: " << id_servicio << endl
            << "|   Titular: " << titular << endl
            << "|   Número de Cuenta: " << numero_cuenta << endl
            << "|   Saldo: $" << saldo << endl
            << "|   Fecha de Apertura: " << fecha_apertura << endl;
    }

    virtual void generarServicio() = 0;

    // Getters
    TCodigo getIdServicio() const { return id_servicio; }
    TSaldo getSaldo() const { return saldo; }
    TFApertura getFechaApertura() const { return fecha_apertura; }
    TTitular getTitular() const { return titular; }
    TCuenta getNumeroCuenta() const { return numero_cuenta; }

    // Setters
    void setSaldo(TSaldo nuevo_saldo) { saldo = nuevo_saldo; }
    void setTitular(TTitular nuevo_titular) { titular = nuevo_titular; }
};


////////////////////////////////////////////CREDITO////////////////////////////////////////////////////
////////////////////////////////////////////////////
// CLASE CREDITO - Integrada en el sistema de Servicios
////////////////////////////////////////////////////
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
// CLASE SERVICIO_CREDITO - Servicio especializado en créditos
////////////////////////////////////////////////////

template <typename TCodigo, typename TSaldo, typename TTitular, typename TCuenta, typename TFApertura>
class ServicioCredito : public Servicios<TCodigo, TSaldo, TTitular, TCuenta, TFApertura> {
private:
    Credito* credito_asociado;

public:
    // Constructor
    ServicioCredito(TCodigo id_servicio, TSaldo saldo, TTitular titular, TCuenta numero_cuenta,
        TFApertura fecha_apertura, Credito* credito)
        : Servicios<TCodigo, TSaldo, TTitular, TCuenta, TFApertura>(id_servicio, saldo, titular, numero_cuenta, fecha_apertura),
        credito_asociado(credito) {
    }

    // Destructor
    ~ServicioCredito() {
        if (credito_asociado) {
            delete credito_asociado;
        }
    }

    // Implementación del método virtual puro
    void generarServicio() override {
        cout << "=== GENERANDO SERVICIO DE CRÉDITO ===" << endl;
        cout << "ID Servicio: " << this->id_servicio << endl;
        cout << "Titular: " << this->titular << endl;
        cout << "Número de Cuenta: " << this->numero_cuenta << endl;
        cout << "Fecha Apertura: " << this->fecha_apertura << endl;

        if (credito_asociado) {
            cout << "--- INFORMACIÓN DEL CRÉDITO ---" << endl;
            cout << "Monto: $" << credito_asociado->getMontoPrestamo() << endl;
            cout << "Plazo: " << credito_asociado->getPlazoMeses() << " meses" << endl;
            cout << "Tasa: " << (credito_asociado->getTasaInteres() * 100) << "%" << endl;
            cout << "Saldo Pendiente: $" << credito_asociado->getSaldoPendiente() << endl;
        }
    }

    // Métodos específicos para gestión de créditos
    void desembolsarCredito() {
        if (credito_asociado) {
            credito_asociado->desembolsar();
            // Actualizar saldo del servicio
            this->saldo += credito_asociado->getMontoPrestamo();
        }
    }

    void pagarCuotaCredito(double monto) {
        if (credito_asociado) {
            credito_asociado->pagarCuota(monto);
            // Actualizar saldo del servicio
            this->saldo -= monto;
        }
    }

    void generarCronograma() {
        if (credito_asociado) {
            credito_asociado->generarCronogramaPagos();
        }
    }

    // Getters y Setters para el crédito
    Credito* getCreditoAsociado() const { return credito_asociado; }
    void setCreditoAsociado(Credito* credito) {
        if (credito_asociado) delete credito_asociado;
        credito_asociado = credito;
    }
};
//////////////////////////////////////////////////////FIN CREDIDO//////////////////////////////////////////////////


////////////////////////////////////////////////////
// LISTA ENLAZADA PARA GESTIÓN DE SERVICIOS ESTO LO USE PARA LOS TIPOS DE CREDITO
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
    int tamaño;

public:
    // Constructor
    ListaEnlazada() : cabeza(nullptr), tamaño(0) {}

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
        tamaño++;
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
    void mostrar() const {
        Nodo<T>* actual = cabeza;
        while (actual) {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
    }

    int getTamaño() const {
        return tamaño;
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
        tamaño = 0;
    }
};
