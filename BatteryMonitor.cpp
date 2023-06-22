#include "BatteryMonitor.h"

BreachType BatteryMonitor::inferBreach(sTempData data)
{
    BreachType new_type = NORMAL;
    if (data.currentTemp < data.lowerLimit)
    {
        new_type = TOO_LOW;
    }
    if (data.currentTemp > data.upperLimit)
    {
        new_type = TOO_HIGH;
    }
    return new_type;
}

BreachType BatteryMonitor::classifyTemperatureBreach(CoolingType coolingType, double temperatureInC)
{
    if (INVALID != coolingTypeValidator(coolingType))
    {
        sTempData data = {};
        data.currentTemp = temperatureInC;
        for (const auto& configData : battTemperatureConfig)
        {
            if (coolingType == configData.coolingType)
            {
                data.lowerLimit = configData.lowerLimit;
                data.upperLimit = configData.upperLimit;
                break;
            }
        }
        return inferBreach(data);
    }
    return INVALID;
}

int BatteryMonitor::coolingTypeValidator(int coolingType)
{
    return (NUMBER_OF_COOLINGTYPES > coolingType) ? coolingType : INVALID;
}

AlertStatus BatteryMonitor::monitor(CoolingType coolingType,
                                    double temperatureInC,
                                    AlertTarget target)
{
    BreachType breachType = classifyTemperatureBreach(coolingType, temperatureInC);
    return alertManager->sendAlert(breachType, target);
}
