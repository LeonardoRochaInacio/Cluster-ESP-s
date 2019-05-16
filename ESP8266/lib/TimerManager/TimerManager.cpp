#include "TimerManager.h"
#include "Arduino.h"
#include "sys/time.h"
#include <iostream>

TimerManager::TimerManager()
{
    std::cout << "TimerManager construído";
}

void TimerManager::SetRTCTime(long Timestamp_Value)
{
    struct timeval Time_Value;
	Time_Value.tv_sec = Timestamp_Value;
    Time_Value.tv_usec = 0;

    struct timezone Time_Zone;
    Time_Zone.tz_minuteswest = 0;
    settimeofday(&Time_Value, &Time_Zone);
}

long TimerManager::GetCurrentRTCTime()
{
    return time(NULL);
}