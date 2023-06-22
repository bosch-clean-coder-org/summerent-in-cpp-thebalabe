#include "AlertManager.h"
#include "Common.h"

const int NUMBER_OF_COOLINGTYPES = 3;

typedef enum
{
    PASSIVE_COOLING,
    HI_ACTIVE_COOLING,
    MED_ACTIVE_COOLING,
    INVALID_TYPE_COOLING
} CoolingType;

struct BatteryTemperatureConfigurations
{
    CoolingType coolingType;
    double lowerLimit;
    double upperLimit;
};

typedef struct TemperatureData
{
    double currentTemp;
    double lowerLimit;
    double upperLimit;
} sTempData;

class BatteryMonitor
{
private:
    BreachType inferBreach(sTempData data);
    int coolingTypeValidator(int coolingType);

    std::unique_ptr<AlertManager> alertManager = std::make_unique<AlertManager>();

    BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

    std::vector<BatteryTemperatureConfigurations> battTemperatureConfig = {
        // CoolingType       //lowerlimit    //upperlimit
        {PASSIVE_COOLING,       0,              35},
        {HI_ACTIVE_COOLING,     0,              45},
        {MED_ACTIVE_COOLING,    0,              40},
        {INVALID_TYPE_COOLING,  0,               0},
    };

public:
    BatteryMonitor() = default;
    virtual ~BatteryMonitor() = default;
    AlertStatus monitor(CoolingType coolingType, double temperatureInC, AlertTarget target);
};
