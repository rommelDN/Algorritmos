#pragma once
#ifndef CREDITO_EMPRESARIAL_H
#define CREDITO_EMPRESARIAL_H

#include "servicio.h"
#include <string>

using namespace std;

class CreditoEmpresarial : public Credito {
private:
    string nombre_empresa;
    string ruc;
    double linea_credito;

public:
    // Constructor
    CreditoEmpresarial(double monto, int plazo, double tasa, string empresa, string ruc_empresa, double linea)
        : Credito(monto, plazo, tasa), nombre_empresa(empresa), ruc(ruc_empresa), linea_credito(linea) {
    }

    // M�todos espec�ficos
    void solicitarCreditoEmpresarial() {
        cout << "Solicitando cr�dito empresarial para: " << nombre_empresa << endl;
        cout << "RUC: " << ruc << endl;
        cout << "L�nea de cr�dito disponible: $" << linea_credito << endl;
        cout << "Monto solicitado: $" << monto_prestamo << endl;
    }

    void refinanciarDeuda() {
        cout << "Proceso de refinanciaci�n de deuda para: " << nombre_empresa << endl;
        cout << "Saldo actual: $" << saldo_pendiente << endl;

        // Simular refinanciaci�n
        plazo_meses += 12; // Extender plazo
        tasa_interes *= 0.9; // Reducir tasa ligeramente
        cout << "Nuevo plazo: " << plazo_meses << " meses" << endl;
        cout << "Nueva tasa: " << (tasa_interes * 100) << "%" << endl;
    }

    // Getters
    string getNombreEmpresa() const { return nombre_empresa; }
    string getRuc() const { return ruc; }
    double getLineaCredito() const { return linea_credito; }

    // Setters
    void setNombreEmpresa(string empresa) { nombre_empresa = empresa; }
    void setRuc(string ruc_empresa) { ruc = ruc_empresa; }
    void setLineaCredito(double linea) { linea_credito = linea; }

    // Sobrescribir m�todos base
    void desembolsar() override {
        cout << "Desembolsando CR�DITO EMPRESARIAL" << endl;
        cout << "Empresa: " << nombre_empresa << " (RUC: " << ruc << ")" << endl;
        Credito::desembolsar();
    }
};

#endif