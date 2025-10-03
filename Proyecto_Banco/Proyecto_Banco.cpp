
#include <iostream>

using namespace std;

void menuCuentas() {
    int opcionC;
    do {
        cout << "\n====== MENU DE CUENTAS ======\n";
        cout << "1. Crear Cuenta de Ahorros\n";
        cout << "2. Crear Cuenta Empresarial\n";
        cout << "3. Crear Cuenta de Seguro\n";
        cout << "4. Crear Cuenta de Inversion\n";
        cout << "0. Regresar\n";
        cout << "Seleccione una opcion: ";
        cin >> opcionC;
        switch (opcionC) {
        case 1:
            cout << "Funcionalidad para crear cuenta de ahorros no implementada.\n";
            break;
        case 2:
            cout << "Funcionalidad para crear cuenta corriente no implementada.\n";
            break;
        case 3:
            cout << "Funcionalidad para crear cuenta plazo fijo no implementada.\n";
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
        cout << "Seleccione una opcion: ";
        cin >> opcionM;

        switch (opcionM) {
        case 1:
			menuCuentas();
            break;
        case 2:
            cout << "Funcionalidad para contratar servicio de tarjeta no implementada.\n";
            break;
        case 3:
            cout << "Funcionalidad para contratar servicio de credito no implementada.\n";
            break;case 0:
            cout << "Regresando al menu principal.\n";
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcionM != 0);
}

int main()
{
    
    int opcion;
    do {
        cout << "\n===== CAJA HUANCAYO =====\n";
        cout << "1. Registrar Cliente\n";
        cout << "2. Contratar Servicio\n";
        cout << "2. Listar todas las cuentas\n";
        cout << "3. Buscar cuenta por numero\n";
        cout << "4. Ver historial de una cuenta\n";
        cout << "5. Registrar transaccion (deposito/retiro)\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion){
            case 1:// Lógica para crear cliente
                cout << "Funcionalidad para crear cliente no implementada.\n";
				break;
            case 2://Logica Para contrater Servicios
				menuServicios();
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

