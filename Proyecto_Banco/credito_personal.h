#pragma once
#ifndef CREDITO_PERSONAL_H
#define CREDITO_PERSONAL_H

#include "servicio.h"
#include <string>

using namespace std;

class CreditoPersonal : public Credito {
private:
    string destino_credito;
    bool seguro_desgravamen;

public:
    // Constructor
    CreditoPersonal(double monto, int plazo, double tasa, string destino, bool seguro)
        : Credito(monto, plazo, tasa), destino_credito(destino), seguro_desgravamen(seguro) {
    }

    // Métodos específicos
    void solicitarCreditoPersonal(double monto) {
        cout << "Solicitando crédito personal por: $" << monto << endl;
        cout << "Destino: " << destino_credito << endl;
        if (seguro_desgravamen) {
            cout << "Incluye seguro de desgravamen" << endl;
        }
    }

    void pagarAdelantado() {
        cout << "Realizando pago adelantado al crédito personal" << endl;
        double interesAhorrado = calcularInteres();
        cout << "Interés ahorrado estimado: $" << interesAhorrado << endl;
    }

    // Getters
    string getDestinoCredito() const { return destino_credito; }
    bool getSeguroDesgravamen() const { return seguro_desgravamen; }

    // Setters
    void setDestinoCredito(string destino) { destino_credito = destino; }
    void setSeguroDesgravamen(bool seguro) { seguro_desgravamen = seguro; }

    // Sobrescribir métodos base
    void desembolsar() override {
        cout << "Desembolsando CRÉDITO PERSONAL" << endl;
        cout << "Destino: " << destino_credito << endl;
        Credito::desembolsar();
    }
};

#endif