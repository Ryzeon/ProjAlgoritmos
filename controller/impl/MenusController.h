#pragma once

#include "../IController.h"
#include "../impl/ClientController.h"
#include "../ControllerBinder.h"
#include "../impl/DriveController.h"
#include "../../model/Driver.h"
#include "../../model/Client.h"
#include "../../model/UserReview.h"

using namespace drive_now_models;
using namespace utils;


class MenusController : public IController {
public:
    bool end = false;

    void customGetch(string question) {
        cout << question;
        cin.ignore();
        cin.get();
    }

    void clearConsole() {
        system("cls");
    }

    void tick() {
        if (end) return;
        switch (currentMenu) {
            case 1:
                mainMenu();
                break;
            case 2:
                loginMenu();
                break;
            case 3:
                break;
            case 4:
                break;
        }
    }

    int askForInt(string question, int min, int max) {
        int out;
        do {
            cout << question;
            cin >> out;
        } while (!(out >= min && out <= max));
        return out;
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
        cout << "1. Login" << endl;
        cout << "2. Credits" << endl;
        cout << "3. Exit" << endl;

        int option = askForInt("Option: ", 1, 3);
        if (option == 1) {
            currentMenu = 2;
        } else if (option == 2) {
            PrintCreditssProject();
            customGetch("Pulsa una tecla!!");
            clearConsole();
        } else if (option == 3) {
            end = true;
        }
    }

    void loginMenu() {
        ClientController* controller = (ClientController*) ControllerBinder::getInstance().getController("client");
        system("cls");
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Login as driver" << endl;
        cout << "4. Register as driver" << endl;

        int option = askForInt("Option: ", 1, 4);
        switch(option) {
            case 1:{
                cout << "Ingrese el nombre de usuario: " << endl;
                cin.ignore();
                string username;
                getline(cin, username);
                cout << "Ingrese la contraseña: " << endl;
                string password;
                getline(cin, password);

                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
        }
    }

    void menuRegistro() {
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

    void menuIniciarSesion() {
        int correo;
        string contraseña;
        cout << "Correo: ";
        cin >> correo;
        cout << endl;
        cout << "Contraseña: ";
        cin >> contraseña;
    }

    void menuSolicitudViaje() {
        string o, d;
        cout << "Ingrese su punto de origen: ";
        cin >> o;
        cout << endl;
        cout << "Indique el destino: ";
        cin >> d;
        cout << endl;
    }

    void menuVehiculo() {
        string vehi;
        cout << "Ingrese el vehiculo que desea viajar: ";
        cin >> vehi;
        cout << "Eleccion confirmada.";
    }

    void menuCalificacion() {
        int cali;
        cout << "║CALIFICACION DEL VIAJE║" << endl;
        cout << "1. Muy Satisfecho" << endl;
        cout << "2. Satisfecho" << endl;
        cout << "3. Poco satisfecho" << endl;
        cout << "4. Insatisfecho" << endl;
        cout << "5. Demasiado Insatisfecho" << endl;
        cout << "Opcion => ";
        cin >> cali;
        while (true) {
            switch (cali) {
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

    void historialdeVaije() {
        menuSolicitudViaje();
        menuCalificacion();
    }

    void PrintCreditssProject() {
        cout << "*****PROJECT PARTICIPANTS*****" << endl;
        cout << "1. Alex Ramon Alberto Avila Asto" << endl;
        cout << "2. Pedro Andre Guia Carrasco" << endl;
        cout << "3. Augusto Jose Pin Matallana" << endl;
        cout << "4. Brayan Stiven Gamboa Delgado" << endl;
    }
};