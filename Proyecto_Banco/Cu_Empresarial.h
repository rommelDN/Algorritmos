#pragma once
#include <string>
#include<iostream>
#include "Cuenta.h"
using namespace std;

template <typename TEmpresa,typename TRuc,typename TCodigo, typename TSaldo, typename TTitular, typename TCuenta, typename TFApertura,
    typename TInteresTasa, typename TLimRetiro>
class Cu_Empresarial: public Cuenta<TCodigo, TSaldo, TTitular, TCuenta, TFApertura, TInteresTasa, TLimRetiro> {
public:
    TEmpresa empresa;
    TRuc ruc;
public:
    //Constructor
    Cu_Empresarial(TEmpresa empresa, TRuc ruc, TInteresTasa tasa_interes, TLimRetiro limite_retiro, TCodigo id_servicio, TSaldo saldo, TTitular titular, TCuenta numero_cuenta, TFApertura fecha_apertura)
        : Cuenta(tasa_interes, limite_retiro, id_servicio, saldo, titular, numero_cuenta, fecha_apertura), empresa(empresa), ruc(ruc) {
	};

    //Metodos
    void depositar(TSaldo monto, string fecha) override {
        this->saldo += monto;
        this->historial.agregar(new Transaccion(rand() % 1000, "Deposito", monto, fecha));
        cout << "Deposito de " << monto << " realizado. Nuevo saldo: " << this->saldo << endl;
	};

    void retirar(TSaldo monto, string fecha) override {
        if (monto <= this->saldo && monto <= this->limite_retiro) {
            this->saldo -= monto;
            this->historial.agregar(new Transaccion(rand() % 1000, "Retiro", monto, fecha));
            cout << "Retiro de " << monto << " realizado. Nuevo saldo: " << this->saldo << endl;
        }
        else {
            cout << "Error: Retiro no permitido." << endl;
        }
    }

    void calcularInteres() override {
        TSaldo interes = this->saldo * (this->tasa_interes / 100);
        this->saldo += interes;
        cout << "Interes de " << interes << " calculado. Nuevo saldo: " << this->saldo << endl;
    };

    void generarServicio() override {
        cout << "Cuenta Empresarial ID: " << this->id_servicio
             << " | Empresa: " << this->empresa
             << " | RUC: " << this->ruc
             << " | Titular: " << this->titular
             << " | Saldo: " << this->saldo << std::endl;
	};
};