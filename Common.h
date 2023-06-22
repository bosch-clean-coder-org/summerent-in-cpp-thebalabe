#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <map>
#include <memory>
#include <vector>

typedef enum
{
    NORMAL,
    TOO_LOW,
    TOO_HIGH,
    INVALID
} BreachType;

typedef enum
{
    ALERT_NOT_SENT,
    ALERT_SENT,
} AlertStatus;

typedef enum
{
    TO_CONTROLLER,
    TO_EMAIL,
    NO_TARGET
} AlertTarget;

#endif // COMMON_H_
