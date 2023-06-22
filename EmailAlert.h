
#ifndef EMAIL_ALERT_HEADER_H_
#define EMAIL_ALERT_HEADER_H_

#include "Common.h"

class EmailAlert
{
public:
    EmailAlert() = default;
    virtual ~EmailAlert() = default;
    void sendToEmail(const std::string message) const;

private:
    std::string RECIPIENT = "a.b@c.com";
};

#endif // EMAIL_ALERT_HEADER_H_
