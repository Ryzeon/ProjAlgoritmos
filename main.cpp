#include "controller/ControllerBinder.h"
#include "controller/impl/DriverNowController.h"
#include "controller/impl/ClientController.h"
using namespace std;

int main() {
    srand(time(NULL));
    ControllerBinder::getInstance().addController(new DriverNowController());
    ControllerBinder::getInstance().addController(new ClientController());
    ControllerBinder::getInstance().init();
    return 0;
}