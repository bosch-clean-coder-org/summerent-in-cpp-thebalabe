#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "BatteryMonitor.h"
#include "test/catch.hpp"
#undef MINSIGSTKSZ
#define MINSIGSTKSZ 16384

TEST_CASE("infers the breach according to limits for PASSIVE_COOLING with Alert to controller")
{
    std::unique_ptr<BatteryMonitor> battery = std::make_unique<BatteryMonitor>();
    REQUIRE(battery->monitor(CoolingType::PASSIVE_COOLING, 10, AlertTarget::TO_CONTROLLER)
            == ALERT_SENT);
    REQUIRE(battery->monitor(CoolingType::PASSIVE_COOLING, 40, AlertTarget::TO_CONTROLLER)
            == ALERT_SENT);
    REQUIRE(battery->monitor(CoolingType::PASSIVE_COOLING, -10, AlertTarget::TO_CONTROLLER)
            == ALERT_SENT);
};

TEST_CASE("infers the breach according to limits for PASSIVE_COOLING with Alert to email")
{
    std::unique_ptr<BatteryMonitor> battery = std::make_unique<BatteryMonitor>();
    REQUIRE(battery->monitor(CoolingType::PASSIVE_COOLING, 10, AlertTarget::TO_EMAIL)
            == ALERT_SENT);
    REQUIRE(battery->monitor(CoolingType::PASSIVE_COOLING, 40, AlertTarget::TO_EMAIL)
            == ALERT_SENT);
    REQUIRE(battery->monitor(CoolingType::PASSIVE_COOLING, -10, AlertTarget::TO_EMAIL)
            == ALERT_SENT);
};

TEST_CASE("infers the breach according to limits for PASSIVE_COOLING without Alert")
{
    std::unique_ptr<BatteryMonitor> battery = std::make_unique<BatteryMonitor>();
    REQUIRE(battery->monitor(CoolingType::PASSIVE_COOLING, 10, AlertTarget::NO_TARGET)
            == ALERT_NOT_SENT);
};

TEST_CASE("infers the breach according to limits for HI_ACTIVE_COOLING with Alert to controller")
{
    std::unique_ptr<BatteryMonitor> battery = std::make_unique<BatteryMonitor>();
    REQUIRE(battery->monitor(CoolingType::HI_ACTIVE_COOLING, 10, AlertTarget::TO_CONTROLLER)
            == ALERT_SENT);
    REQUIRE(battery->monitor(CoolingType::HI_ACTIVE_COOLING, 50, AlertTarget::TO_CONTROLLER)
            == ALERT_SENT);
    REQUIRE(battery->monitor(CoolingType::HI_ACTIVE_COOLING, -10, AlertTarget::TO_CONTROLLER)
            == ALERT_SENT);
};

TEST_CASE("infers the breach according to limits for HI_ACTIVE_COOLING with Alert to email")
{
    std::unique_ptr<BatteryMonitor> battery = std::make_unique<BatteryMonitor>();
    REQUIRE(battery->monitor(CoolingType::HI_ACTIVE_COOLING, 10, AlertTarget::TO_EMAIL)
            == ALERT_SENT);
    REQUIRE(battery->monitor(CoolingType::HI_ACTIVE_COOLING, 50, AlertTarget::TO_EMAIL)
            == ALERT_SENT);
    REQUIRE(battery->monitor(CoolingType::HI_ACTIVE_COOLING, -10, AlertTarget::TO_EMAIL)
            == ALERT_SENT);
};

TEST_CASE("infers the breach according to limits for HI_ACTIVE_COOLING without Alert")
{
    std::unique_ptr<BatteryMonitor> battery = std::make_unique<BatteryMonitor>();
    REQUIRE(battery->monitor(CoolingType::HI_ACTIVE_COOLING, 10, AlertTarget::NO_TARGET)
            == ALERT_NOT_SENT);
};

TEST_CASE("infers the breach according to limits for MED_ACTIVE_COOLING with Alert to controller")
{
    std::unique_ptr<BatteryMonitor> battery = std::make_unique<BatteryMonitor>();
    REQUIRE(battery->monitor(CoolingType::MED_ACTIVE_COOLING, 10, AlertTarget::TO_CONTROLLER)
            == ALERT_SENT);
    REQUIRE(battery->monitor(CoolingType::MED_ACTIVE_COOLING, 45, AlertTarget::TO_CONTROLLER)
            == ALERT_SENT);
    REQUIRE(battery->monitor(CoolingType::MED_ACTIVE_COOLING, -10, AlertTarget::TO_CONTROLLER)
            == ALERT_SENT);
};

TEST_CASE("infers the breach according to limits for MED_ACTIVE_COOLING with Alert to email")
{
    std::unique_ptr<BatteryMonitor> battery = std::make_unique<BatteryMonitor>();
    REQUIRE(battery->monitor(CoolingType::MED_ACTIVE_COOLING, 10, AlertTarget::TO_EMAIL)
            == ALERT_SENT);
    REQUIRE(battery->monitor(CoolingType::MED_ACTIVE_COOLING, 45, AlertTarget::TO_EMAIL)
            == ALERT_SENT);
    REQUIRE(battery->monitor(CoolingType::MED_ACTIVE_COOLING, -10, AlertTarget::TO_EMAIL)
            == ALERT_SENT);
};

TEST_CASE("infers the breach according to limits for MED_ACTIVE_COOLING without Alert")
{
    std::unique_ptr<BatteryMonitor> battery = std::make_unique<BatteryMonitor>();
    REQUIRE(battery->monitor(CoolingType::MED_ACTIVE_COOLING, 10, AlertTarget::NO_TARGET)
            == ALERT_NOT_SENT);
};

TEST_CASE("infers the breach according to limits for Invalid type cooling")
{
    std::unique_ptr<BatteryMonitor> battery = std::make_unique<BatteryMonitor>();
    REQUIRE(battery->monitor(CoolingType::INVALID_TYPE_COOLING, 10, AlertTarget::NO_TARGET)
            == ALERT_NOT_SENT);
};
