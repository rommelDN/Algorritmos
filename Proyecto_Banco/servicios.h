#include <ctime> // Agrega esta línea al inicio del archivo si no está incluida
#include <string>
#include<iostream>

using namespace std;

template <typename TCodigo,typename TSaldo,typename TEstado,typename TFApertura>
class Servicios {
public:
    TCodigo id_servicio;
    TSaldo saldo;
    TEstado estado;
    TFApertura fecha_apertura;
public:
    //Constructor
    Servicios(TCodigo id_servicio, TSaldo saldo, TEstado estado, TFApertura fecha_apertura)
        : id_servicio(id_servicio), saldo(saldo), estado(estado), fecha_apertura(fecha_apertura) {
    };
	//Destructor
    ~Servicios() {};

	//Metodos
    void consultarSaldo()const;
    void cancelarServicio()const;
	void generarEstadoCuenta()const;

	//Getters
	TCodigo getIdServicio()const {};
	TSaldo getSaldo()const {};
	TEstado getEstado()const {};
	TFApertura getFechaApertura()const {};

	//Setters
    
};

//###################################
// Implementacion de Metodos
//###################################
template <typename TCodigo, typename TSaldo, typename TEstado, typename TFApertura>
Servicios<TCodigo, TSaldo, TEstado, TFApertura>::~Servicios() {}

template <typename TCodigo, typename TSaldo, typename TEstado, typename TFApertura>
void Servicios<TCodigo, TSaldo, TEstado, TFApertura>::consultarSaldo() const {
	cout << "El saldo actual es__: " << saldo << endl;   
};
template <typename TCodigo, typename TSaldo, typename TEstado, typename TFApertura>
void Servicios<TCodigo,TSaldo,TEstado,TFApertura>::generarEstadoCuenta() const {
    cout << "El estado de cuenta es__: "<<endl
    << "|   ID Servicio: " << id_servicio<<endl
	<< "|   Saldo: " << saldo << endl
	<< "|   Estado: " << estado << endl
	<< "|   Fecha de Apertura: " << fecha_apertura.tm_mday << "/" << fecha_apertura.tm_mon + 1 << "/" << fecha_apertura.tm_year + 1900 << endl;
};
template <typename TCodigo, typename TSaldo, typename TEstado, typename TFApertura>
void Servicios<TCodigo, TSaldo, TEstado, TFApertura>::cancelarServicio() const {
    cout << "Calculo de intereses no implementado aun." << endl;
};

//###################################
// Implementacion de Getters
//###################################
template <typename TCodigo, typename TSaldo, typename TEstado, typename TFApertura>
TCodigo Servicios<TCodigo, TSaldo, TEstado, TFApertura>::getIdServicio() const {
    return id_servicio;
};
template <typename TCodigo, typename TSaldo, typename TEstado, typename TFApertura>
TSaldo Servicios<TCodigo, TSaldo, TEstado, TFApertura>::getSaldo() const {
    return saldo;
};
template <typename TCodigo, typename TSaldo, typename TEstado, typename TFApertura>
TEstado Servicios<TCodigo, TSaldo, TEstado, TFApertura>::getEstado() const {
    return estado;
};
template <typename TCodigo, typename TSaldo, typename TEstado, typename TFApertura>
TFApertura Servicios<TCodigo, TSaldo, TEstado, TFApertura>::getFechaApertura() const {
    return fecha_apertura;
};