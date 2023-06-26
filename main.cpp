#include "controller/ControllerBinder.h"
#include "controller/impl/DriverNowController.h"
#include "controller/impl/ClientController.h"
#include "controller/impl/DriveController.h"
#include "controller/impl/MenusController.h"
using namespace std;

int main() {
    srand(time(NULL));
    ControllerBinder::getInstance().addController(new DriverNowController());
    ControllerBinder::getInstance().addController(new ClientController());
    ControllerBinder::getInstance().addController(new DriverController());
    ControllerBinder::getInstance().addController(new MenusController());
    ControllerBinder::getInstance().init();

    try {
        MenusController *menu = ControllerBinder::getInstance().getController("menu");
    }
    return 0;
}