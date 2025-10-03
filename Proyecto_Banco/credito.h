#ifndef CREDITO_H
#define CREDITO_H

#include <iostream>
#include <string>

using namespace std;

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

#endif