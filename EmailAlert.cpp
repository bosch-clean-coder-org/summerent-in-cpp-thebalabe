#include "EmailAlert.h"

using namespace std;

void EmailAlert::sendToEmail(const std::string message) const
{
    cout << "To: " << RECIPIENT << endl;
    cout << "Hi, " << message << endl;
}
