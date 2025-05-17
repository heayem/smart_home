#ifndef USAGE_TRACKER_H
#define USAGE_TRACKER_H

#include <Arduino.h>
#include <Preferences.h>

class UsageTracker {
private:
    Preferences preferences;
    const char* namespace_name = "led_usage";
    unsigned long frontLedOnTime;
    unsigned long behindLedOnTime;
    unsigned long lastUpdateTime;
    
public:
    UsageTracker();
    void begin();
    void updateFrontLed(bool isOn);
    void updateBehindLed(bool isOn);
    void getUsageStats(unsigned long& frontHours, unsigned long& behindHours);
    void resetStats();
};

#endif 