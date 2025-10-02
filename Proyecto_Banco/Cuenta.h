#pragma once
#include <string>
#include<iostream>
#include "servicios.h"
using namespace std;

template <typename TInteresTasa, typename TLimRetiro,
	typename TCodigo, typename TSaldo, typename TTitular, typename TCuenta, typename TFApertura>
class Cuenta: public Servicios<TCodigo, TSaldo, TTitular, TCuenta, TFApertura> {
public:
	TInteresTasa tasa_interes;
	TLimRetiro limite_retiro;
public:
	//Constructor
	Cuenta(TInteresTasa tasa_interes, TLimRetiro limite_retiro, TCodigo id_servicio, TSaldo saldo, TTitular titular, TCuenta numero_cuenta, TFApertura fecha_apertura)
		: Servicios(id_servicio, saldo, titular, numero_cuenta, fecha_apertura), tasa_interes(tasa_interes), limite_retiro(limite_retiro) {
	};

	//Metodos
	void generarServicio() override {
		cout << "Cuenta Empresarial ID: " << this->id_servicio
			<< " | Titular: " << this->titular
			<< " | Empresa: " << empresa
			<< " | RUC: " << ruc
			<< " | Saldo: " << this->saldo
			<< " | Tasa interés: " << this->tasa_interes
			<< " | Límite retiro: " << this->limite_retiro
			<< std::endl;
	}
	virtual void depositar(TSaldo monto)=0;
	virtual void retirar(TSaldo monto)=0;
	virtual void calcularInteres()=0;

};