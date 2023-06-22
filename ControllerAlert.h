
#ifndef CONTROLLER_ALERT_HEADER_H_
#define CONTROLLER_ALERT_HEADER_H_

#include "Common.h"

class ControllerAlert
{
public:
    ControllerAlert() = default;
    virtual ~ControllerAlert() = default;
    void SendControllerAlert(BreachType breachType);

private:
    const unsigned short HEADER = 0xfeed;
};

#endif // CONTROLLER_ALERT_HEADER_H_
