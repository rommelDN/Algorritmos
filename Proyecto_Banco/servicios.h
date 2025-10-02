#include <ctime> // Agrega esta línea al inicio del archivo si no está incluida
#include <string>
#include<iostream>

using namespace std;

template <typename TCodigo,typename TSaldo, typename TTitular,typename TCuenta,typename TFApertura>
class Servicios {
public:
    TCodigo id_servicio;
    TSaldo saldo;
    TCuenta numero_cuenta;
    TTitular titular;
    TFApertura fecha_apertura;
public:

    //Constructor
    Servicios(TCodigo id_servicio, TSaldo saldo, TTitular titular, TCuenta numero_cuenta, TFApertura fecha_apertura)
		: id_servicio(id_servicio), saldo(saldo), titular(titular), numero_cuenta(numero_cuenta), fecha_apertura(fecha_apertura) {
	};

	//Destructor
    ~Servicios() {};

	//Metodos
    void consultarSaldo()const;
    void cancelarServicio()const;
	void generarEstadoCuenta()const;
    virtual void generarServicio()=0;

	//Getters
	TCodigo getIdServicio()const {};
	TSaldo getSaldo()const {};
	TFApertura getFechaApertura()const {};

	//Setters
    
};

//###################################
// Implementacion de Metodos
//###################################

template <typename TCodigo, typename TSaldo, typename TTitular, typename TCuenta, typename TFApertura>
Servicios<TCodigo,TSaldo,TTitular,TCuenta, TFApertura>::~Servicios() {}

template <typename TCodigo, typename TSaldo, typename TTitular, typename TCuenta, typename TFApertura>
void Servicios<TCodigo, TSaldo, TTitular, TCuenta, TFApertura>::consultarSaldo() const {
	cout << "El saldo actual es__: " << saldo << endl;   
};
template <typename TCodigo, typename TSaldo, typename TTitular, typename TCuenta, typename TFApertura>
void Servicios<TCodigo, TSaldo, TTitular, TCuenta, TFApertura>::generarEstadoCuenta() const {
    cout << "El estado de cuenta es__: "<<endl
    << "|   ID Servicio: " << id_servicio<<endl
	<< "|   Saldo: " << saldo << endl
	<< "|   Estado: " << estado << endl
	<< "|   Fecha de Apertura: " << fecha_apertura.tm_mday << "/" << fecha_apertura.tm_mon + 1 << "/" << fecha_apertura.tm_year + 1900 << endl;
};
template <typename TCodigo, typename TSaldo, typename TTitular, typename TCuenta, typename TFApertura>
void Servicios<TCodigo, TSaldo, TTitular, TCuenta, TFApertura>::cancelarServicio() const {
    cout << "Calculo de intereses no implementado aun." << endl;
};

//###################################
// Implementacion de Getters
//###################################

template <typename TCodigo, typename TSaldo, typename TTitular, typename TCuenta, typename TFApertura>
TCodigo Servicios<TCodigo, TSaldo, TTitular, TCuenta, TFApertura>::getIdServicio() const {
    return id_servicio;
};
template <typename TCodigo, typename TSaldo, typename TTitular, typename TCuenta, typename TFApertura>
TSaldo Servicios<TCodigo, TSaldo, TTitular, TCuenta, TFApertura>::getSaldo() const {
    return saldo;
};
template <typename TCodigo, typename TSaldo, typename TTitular, typename TCuenta, typename TFApertura>
TFApertura Servicios<TCodigo, TSaldo, TTitular, TCuenta, TFApertura>::getFechaApertura() const {
    return fecha_apertura;
};