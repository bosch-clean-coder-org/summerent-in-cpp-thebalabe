
#include "AlertManager.h"

AlertStatus AlertManager::sendAlert(BreachType breachType, AlertTarget alertTarget)
{
    AlertStatus status = ALERT_NOT_SENT;
    switch (alertTarget)
    {
    case TO_CONTROLLER:
        controllerAlert->SendControllerAlert(breachType);
        status = ALERT_SENT;
        break;
    case TO_EMAIL:
        emailAlert->sendToEmail(temperatureBreachMapper.find(breachType)->second);
        status = ALERT_SENT;
        break;
    default:
        break;
    }
    return status;
}
