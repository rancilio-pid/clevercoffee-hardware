/**
 * @file ISR.h
 *
 * @brief Timer - ISR for PID calculation and heat realay output
 */

#include <Arduino.h>


#if defined(ESP32)
void IRAM_ATTR onTimer(){
    timerAlarmWrite(timer, 10000, true);

    if (Output <= isrCounter) {
        digitalWrite(PINHEATER, LOW);
    } else {
        digitalWrite(PINHEATER, HIGH);
    }

    isrCounter += 10; // += 10 because one tick = 10ms

    //set PID output as relais commands
    if (isrCounter >= windowSize) {
        isrCounter = 0;
    }
}
#endif

/**
 * @brief Initialize hardware timers
 */
void initTimer1(void) {
    #if defined(ESP32)
        timer = timerBegin(0, 80, true); //m
        timerAttachInterrupt(timer, &onTimer, true);//m
        timerAlarmWrite(timer, 10000, true);//m
    #else
        #error("MCU not supported");
    #endif
}

void enableTimer1(void) {
    #if defined(ESP32)
        timerAlarmEnable(timer);
    #else
        #error("MCU not supported");
    #endif
}

void disableTimer1(void)
{
    #if defined(ESP32)
        timerAlarmDisable(timer);
    #else
        #error("MCU not supported");
    #endif
}

bool isTimer1Enabled(void) {
    bool timerEnabled = false;

    #if defined(ESP32)
        timerEnabled = timerAlarmEnabled(timer);
    #else
        #error("MCU not supported");
    #endif

    return timerEnabled;
}
