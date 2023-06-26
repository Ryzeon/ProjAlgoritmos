#pragma once

#include "../IController.h"

class MenusController : public IController {
public:
    bool end = false;
    void tick() {
        if (end) return;
    }
    int currentMenu;

    void load() override {
        currentMenu = 1;
        end = false;
    }

    string getName() override {
        return "menus";
    }

    void mainMenu() {
        cout << "1. Login Driver" << endl;
        cout << "2. Credits" << endl;
        cout << "3. Exit" << endl;
    }
    void menuRegistro()
    {
        int nombres, apellidos;
        string dni, email;
        string telefono;

        cout << "Nombres: ";
        cin >> nombres;
        cout << endl;
        cout << "Apellidos: ";
        cin >> apellidos;
        cout << "DNI: ";
        cin >> dni;
        cout << endl;
        cout << "Email: ";
        cin >> email;
        cout << endl;
        cout << "Telefono: ";
        cin >> telefono;
        cout << endl;
    }
    void menuIniciarSesion()
    {
        int correo;
        string contraseña;
        cout << "Correo: ";
        cin >> correo;
        cout << endl;
        cout << "Contraseña: ";
        cin >> contraseña;
    }
    void menuSolicitudViaje()
    {
        string o, d;
        cout << "Ingrese su punto de origen: ";
        cin >> o;
        cout << endl;
        cout << "Indique el destino: ";
        cin >> d;
        cout << endl;
    }
    void menuVehiculo()
    {
        string vehi;
        cout << "Ingrese el vehiculo que desea viajar: ";
        cin >> vehi;
        cout << "Eleccion confirmada.";
    }
    void menuMetodoPago()
    {
        int op;
        cout << "****Metodo de Pago****" << endl;
        cout << "1. Efectivo" << endl;
        cout << "2. Tarjeta de Credito Online" << endl;
        cout << "3. Yape" << endl;
        cout << "4. Plin" << endl;
        cout << "Opcion => ";
        cin >> op;
        cout << endl;
        while (true) {
            switch (op)
            {
                case 1:
                    cout << "Pago de tarifa en efectivo.";
                    cout << endl;
                    break;
                case 2:
                    cout << "Pago de tarifa por tarjeta de credito online.";
                    cout << endl;
                    break;
                case 3:
                    cout << "Pago de tarifa por Yape.";
                    cout << endl;
                    break;
                case 4:
                    cout << "Pago de tarifa por Plin.";
                    cout << endl;
                    break;
            }
        }
    }
    void menuCalificacion()
    {
        int cali;
        cout << "║CALIFICACION DEL VIAJE║" << endl;
        cout << "1. Muy Satisfecho" << endl;
        cout << "2. Satisfecho" << endl;
        cout << "3. Poco satisfecho" << endl;
        cout << "4. Insatisfecho" << endl;
        cout << "5. Demasiado Insatisfecho" << endl;
        cout << "Opcion => ";
        cin >> cali;
        while (true)
        {
            switch (cali)
            {
                case 1:
                    cout << "Excelente!!";
                    break;
                case 2:
                    cout << "Nos alegramos.";
                    break;
                case 3:
                    cout << "Esta bien, que le vaya bien.";
                    break;
                case 4:
                    cout << "Okey gracias por su comentario.";
                    break;
                case 5:
                    cout << "Lo sentimos, no volvera a pasar";
                    break;
            }

        }
    }
    void historialdeVaije()
    {
        menuSolicitudViaje();
        menuMetodoPago();
        menuCalificacion();
    }
    void PrintCredtisProject()
    {
        cout << "*****PROJECT PARTICIPANTS*****" << endl;
        cout << "1. Alex Ramon Alberto Avila Asto" << endl;
        cout << "2. Pedro Andre Guia Carrasco" << endl;
        cout << "3. Augusto Jose Pin Matallana" << endl;
        cout << "4. Brayan Stiven Gamboa Delgado" << endl;
    }
};