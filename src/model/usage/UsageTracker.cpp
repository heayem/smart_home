#include "UsageTracker.h"

UsageTracker::UsageTracker() {
    frontLedOnTime = 0;
    behindLedOnTime = 0;
    lastUpdateTime = 0;
}

void UsageTracker::begin() {
    preferences.begin(namespace_name, false);
    frontLedOnTime = preferences.getULong("front_time", 0);
    behindLedOnTime = preferences.getULong("behind_time", 0);
    lastUpdateTime = millis();
}

void UsageTracker::updateFrontLed(bool isOn) {
    unsigned long currentTime = millis();
    if (isOn) {
        frontLedOnTime += (currentTime - lastUpdateTime);
        preferences.putULong("front_time", frontLedOnTime);
    }
    lastUpdateTime = currentTime;
}

void UsageTracker::updateBehindLed(bool isOn) {
    unsigned long currentTime = millis();
    if (isOn) {
        behindLedOnTime += (currentTime - lastUpdateTime);
        preferences.putULong("behind_time", behindLedOnTime);
    }
    lastUpdateTime = currentTime;
}

void UsageTracker::getUsageStats(unsigned long& frontHours, unsigned long& behindHours) {
    frontHours = frontLedOnTime / (1000 * 60 * 60);
    behindHours = behindLedOnTime / (1000 * 60 * 60);
}

void UsageTracker::resetStats() {
    frontLedOnTime = 0;
    behindLedOnTime = 0;
    preferences.putULong("front_time", 0);
    preferences.putULong("behind_time", 0);
} 