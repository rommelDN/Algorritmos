#pragma once
#include <iostream>
#include <string>
#include <functional>
#include "credito.h"

using namespace std;


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
