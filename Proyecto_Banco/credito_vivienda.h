#pragma once
#ifndef CREDITO_VIVIENDA_H
#define CREDITO_VIVIENDA_H

#include "servicios.h"
#include <string>

using namespace std;

class CreditoVivienda : public Credito {
private:
    string direccion_inmueble;
    double valor_inmueble;
    double subsidio_estado;

public:
    // Constructor
    CreditoVivienda(double monto, int plazo, double tasa, string direccion, double valor, double subsidio)
        : Credito(monto, plazo, tasa), direccion_inmueble(direccion),
        valor_inmueble(valor), subsidio_estado(subsidio) {
    }

    // Métodos específicos
    void registrarHipoteca() {
        cout << "Registrando hipoteca para el inmueble en: " << direccion_inmueble << endl;
        cout << "Valor del inmueble: $" << valor_inmueble << endl;
        cout << "Monto del crédito: $" << monto_prestamo << endl;
    }

    void aplicarSubsidio() {
        cout << "Aplicando subsidio estatal de: $" << subsidio_estado << endl;
        saldo_pendiente -= subsidio_estado;
        if (saldo_pendiente < 0) saldo_pendiente = 0;
        cout << "Nuevo saldo después del subsidio: $" << saldo_pendiente << endl;
    }

    // Getters
    string getDireccionInmueble() const { return direccion_inmueble; }
    double getValorInmueble() const { return valor_inmueble; }
    double getSubsidioEstado() const { return subsidio_estado; }

    // Setters
    void setDireccionInmueble(string direccion) { direccion_inmueble = direccion; }
    void setValorInmueble(double valor) { valor_inmueble = valor; }
    void setSubsidioEstado(double subsidio) { subsidio_estado = subsidio; }

    // Sobrescribir métodos base
    void desembolsar() override {
        cout << "Desembolsando CRÉDITO DE VIVIENDA" << endl;
        cout << "Inmueble: " << direccion_inmueble << endl;
        Credito::desembolsar();
        registrarHipoteca();
    }
};

#endif