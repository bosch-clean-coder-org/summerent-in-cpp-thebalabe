
#ifndef ALERT_STRATEGY_HEADER_H_
#define ALERT_STRATEGY_HEADER_H_

#include "Common.h"
#include "ControllerAlert.h"
#include "EmailAlert.h"

class AlertManager
{
public:
    AlertManager() = default;
    virtual ~AlertManager() = default;
    AlertStatus sendAlert(BreachType BreachType, AlertTarget alertTarget);

private:
    std::map<BreachType, const char*> temperatureBreachMapper {
        {NORMAL, "Temperature is normal"},
        {TOO_LOW, "Temperature is too low"},
        {TOO_HIGH, "Temperature is too high"},
        {INVALID, "Invalid Cooling type"}};

    std::unique_ptr<EmailAlert> emailAlert = std::make_unique<EmailAlert>();
    std::unique_ptr<ControllerAlert> controllerAlert = std::make_unique<ControllerAlert>();

};

#endif // ALERT_STRATEGY_HEADER_H_
