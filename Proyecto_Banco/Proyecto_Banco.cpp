#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "Cu_Empresarial.h"

using namespace std;
 
// Función para leer un número entero con validación
int leerEntero(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia buffer
            return valor;
        }
        else {
            cout << "Entrada inválida. Intente de nuevo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Función para leer un número decimal con validación
double leerDouble(const string& mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia buffer
            return valor;
        }
        else {
            cout << "Entrada inválida. Intente de nuevo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Función para leer una cadena (puede tener espacios)
string leerCadena(const string& mensaje) {
    string valor;
    cout << mensaje;
    getline(cin, valor);
    return valor;
}

// Función para leer cuentas desde el archivo
void leerCuentasDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;
        cout << "\n===== LISTADO DE CUENTAS EMPRESARIALES =====\n";
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string empresa, ruc, titular, numero_cuenta, id_servicio, saldo, tasa, limite, fecha_apertura;

            getline(ss, empresa, '|');
            getline(ss, ruc, '|');
            getline(ss, titular, '|');
            getline(ss, numero_cuenta, '|');
            getline(ss, id_servicio, '|');
            getline(ss, saldo, '|');
            getline(ss, tasa, '|');
            getline(ss, limite, '|');
            getline(ss, fecha_apertura, '|');

            cout << "Empresa: " << empresa
                << " | RUC: " << ruc
                << " | Titular: " << titular
                << " | Cuenta: " << numero_cuenta
                << " | ID Servicio: " << id_servicio
                << " | Saldo: " << saldo
                << " | Tasa: " << tasa
                << " | Limite: " << limite
                << " | Fecha Apertura: " << fecha_apertura
                << endl;
        }
        archivo.close();
    }
    else {
        cout << "Error al abrir archivo para leer." << endl;
    }
}

void menuCuentas() {
    int opcionC;
    do {
        cout << "\n====== MENU DE CUENTAS ======\n";
        cout << "1. Crear Cuenta de Ahorros\n";
        cout << "2. Crear Cuenta Empresarial\n";
        cout << "3. Crear Cuenta de Seguro\n";
        cout << "4. Crear Cuenta de Inversion\n";
        cout << "0. Regresar\n";
        opcionC = leerEntero("Seleccione una opcion: ");

        switch (opcionC) {
        case 1:
            cout << "Funcionalidad para crear cuenta de ahorros no implementada.\n";
            break;
        case 2: {
            cout << "\n=== CREAR CUENTA EMPRESARIAL ===\n";
            string empresa = leerCadena("Ingrese nombre de la empresa: ");
            string ruc = leerCadena("Ingrese RUC: ");
            string titular = leerCadena("Ingrese titular: ");
            int numero_cuenta = leerEntero("Ingrese numero de cuenta: ");
            int id_servicio = leerEntero("Ingrese ID de servicio: ");
            double saldo = leerDouble("Ingrese saldo inicial: ");
            double tasa_interes = leerDouble("Ingrese tasa de interes (%): ");
            double limite_retiro = leerDouble("Ingrese limite de retiro: ");
            string fecha_apertura = leerCadena("Ingrese fecha de apertura (dd/mm/yyyy): ");

            Cu_Empresarial<string, string, int, double, string, int, string, double, double>
                cuentaEmp(
                    empresa,        // TEmpresa
                    ruc,            // TRuc
                    tasa_interes,   // TInteresTasa
                    limite_retiro,  // TLimRetiro
                    id_servicio,    // TCodigo
                    saldo,          // TSaldo
                    titular,        // TTitular
                    numero_cuenta,  // TCuenta
                    fecha_apertura  // TFApertura
                );

            // Guardar en archivo
            ofstream archivo("cuentas_empresariales.txt", ios::app);
            if (archivo.is_open()) {
                archivo << empresa << "|"
                    << ruc << "|"
                    << titular << "|"
                    << numero_cuenta << "|"
                    << id_servicio << "|"
                    << saldo << "|"
                    << tasa_interes << "|"
                    << limite_retiro << "|"
                    << fecha_apertura << "\n";
                archivo.close();
                cout << "Cuenta empresarial guardada correctamente.\n";
            }
            else {
                cout << "Error al abrir el archivo para guardar.\n";
            }
            break;
        }
        case 3:
            cout << "Funcionalidad para crear cuenta plazo fijo no implementada.\n";
            break;
        case 4:
            cout << "Funcionalidad para crear cuenta de inversion no implementada.\n";
            break;
        case 0:
            cout << "Regresando al menu principal.\n";
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcionC != 0);
}

void menuServicios() {
    int opcionM;
    do {
        cout << "\n====== MENU DE SERVICIOS ======\n";
        cout << "1. Servicios de Cuentas\n";
        cout << "2. Servicios de Tarjetas\n";
        cout << "3. Servicios de Creditos\n";
        cout << "0. Regresar\n";
        opcionM = leerEntero("Seleccione una opcion: ");

        switch (opcionM) {
        case 1:
            menuCuentas();
            break;
        case 2:
            cout << "Funcionalidad para contratar servicio de tarjeta no implementada.\n";
            break;
        case 3:
            cout << "Funcionalidad para contratar servicio de credito no implementada.\n";
            break;
        case 0:
            cout << "Regresando al menu principal.\n";
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcionM != 0);
}

int main() {
    int opcion;
    do {
        cout << "\n===== CAJA HUANCAYO =====\n";
        cout << "1. Registrar Cliente\n";
        cout << "2. Contratar Servicio\n";
        cout << "3. Listar todas las cuentas\n";
        cout << "4. Buscar cuenta por numero\n";
        cout << "5. Registrar transaccion (deposito/retiro)\n";
        cout << "0. Salir\n";
        opcion = leerEntero("Seleccione una opcion: ");

        switch (opcion) {
        case 1:
            cout << "Funcionalidad para crear cliente no implementada.\n";
            break;
        case 2:
            menuServicios();
            break;
        case 3:
            leerCuentasDesdeArchivo("cuentas_empresariales.txt");
            break;
        case 4:
            cout << "Funcionalidad para buscar cuenta por numero no implementada.\n";
            break;
        case 5:
            cout << "Funcionalidad para registrar transaccion no implementada.\n";
            break;
        case 0:
            cout << "Saliendo del sistema. ¡Hasta luego!\n";
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}
