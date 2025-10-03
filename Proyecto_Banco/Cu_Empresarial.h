#pragma once
#include <string>
#include<iostream>
#include <sstream>

#include "Cuenta.h"
using namespace std;

template <
    typename TEmpresa,
    typename TRuc,
    typename TCodigo,
    typename TSaldo,
    typename TTitular,
    typename TCuenta,
    typename TFApertura,
    typename TInteresTasa,
    typename TLimRetiro>
class Cu_Empresarial
    : public Cuenta<TInteresTasa, TLimRetiro, TCodigo, TSaldo, TTitular, TCuenta, TFApertura> {
public:
    TEmpresa empresa;
    TRuc ruc;
public:
    //Constructor
    Cu_Empresarial(TEmpresa empresa, TRuc ruc,
        TInteresTasa tasa_interes, TLimRetiro limite_retiro,
        TCodigo id_servicio, TSaldo saldo,
        TTitular titular, TCuenta numero_cuenta,
        TFApertura fecha_apertura)
        : Cuenta<TInteresTasa, TLimRetiro, TCodigo, TSaldo, TTitular, TCuenta, TFApertura>(
            tasa_interes, limite_retiro, id_servicio, saldo, titular, numero_cuenta, fecha_apertura),
        empresa(empresa), ruc(ruc) {
    }


    //Metodos
    void depositar(TSaldo monto, std::string fecha) override {
        this->saldo += monto;
        this->historial.agregar(new Transaccion<int, string, double>(rand() % 1000, "Deposito", monto, fecha));
        cout << "Deposito de " << monto << " realizado. Nuevo saldo: " << this->saldo << endl;
	};

    void retirar(TSaldo monto, std::string fecha) override {
        if (monto <= this->saldo && monto <= this->limite_retiro) {
            this->saldo -= monto;
            this->historial.agregar(new Transaccion<int, string, double>(rand() % 1000, "Retiro", monto, fecha));
            cout << "Retiro de " << monto << " realizado. Nuevo saldo: " << this->saldo << endl;
        }
        else {
            cout << "Error: Retiro no permitido." << endl;
        }
    }

    void generarServicio() override {
        cout << "Cuenta Empresarial ID: " << this->id_servicio
             << " | Empresa: " << this->empresa
             << " | RUC: " << this->ruc
             << " | Titular: " << this->titular
             << " | Saldo: " << this->saldo << std::endl;
	};
    void guardarEnArchivo(const string& nombreArchivo) {
        ofstream archivo(nombreArchivo, ios::app);
        if (archivo.is_open()) {
            archivo << this->id_servicio << ","
                << this->empresa << ","
                << this->ruc << ","
                << this->titular << ","
                << this->saldo << ","
                << this->numero_cuenta << ","
                << this->fecha_apertura << ","
                << this->tasa_interes << ","
                << this->limite_retiro << endl;
            archivo.close();
            cout << "Cuenta empresarial guardada en archivo." << endl;
        }
        else {
            cout << "Error al abrir archivo para guardar." << endl;
        }
    }


    static void leerDesdeArchivo(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            string linea;
            cout << "Leyendo cuentas desde archivo:\n";
            while (getline(archivo, linea)) {
                stringstream ss(linea);
                string id_servicio, empresa, ruc, titular, saldo, numero_cuenta, fecha, tasa, limite;

                getline(ss, id_servicio, ',');
                getline(ss, empresa, ',');
                getline(ss, ruc, ',');
                getline(ss, titular, ',');
                getline(ss, saldo, ',');
                getline(ss, numero_cuenta, ',');
                getline(ss, fecha, ',');
                getline(ss, tasa, ',');
                getline(ss, limite, ',');

                cout << "ID: " << id_servicio
                    << " | Empresa: " << empresa
                    << " | RUC: " << ruc
                    << " | Titular: " << titular
                    << " | Saldo: " << saldo
                    << " | Cuenta: " << numero_cuenta
                    << " | Fecha: " << fecha
                    << " | Tasa: " << tasa
                    << " | Limite: " << limite << endl;
            }
            archivo.close();
        }
        else {
            cout << " Error al abrir archivo para leer." << endl;
        }
    }
};