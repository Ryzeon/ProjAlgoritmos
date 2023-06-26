#include "controller/ControllerBinder.h"
#include "controller/impl/DriverNowController.h"
#include "controller/impl/ClientController.h"
#include "controller/impl/DriveController.h"
#include "controller/impl/MenusController.h"

using namespace std;

int main() {
    srand(time(NULL));
    MenusController* menu = new MenusController();
    ControllerBinder::getInstance().addController(new DriverNowController());
    ControllerBinder::getInstance().addController(new ClientController());
    ControllerBinder::getInstance().addController(new DriverController());
    ControllerBinder::getInstance().addController(menu);
    ControllerBinder::getInstance().init();
//    while (!menu->end) {
//        menu->tick();
//    }
    return 0;
}