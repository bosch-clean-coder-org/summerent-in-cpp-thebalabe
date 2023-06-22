
#include "ControllerAlert.h"

using namespace std;

void ControllerAlert::SendControllerAlert(BreachType breachType)
{
    cout << hex << HEADER << ": " << hex << breachType << endl;
}
