/**
 * @file defaults.h
 *
 * @brief Default values for user configurable system parameters
 *
 */

#pragma once


#define SETPOINT 95                // Brew temperature setpoint
#define STEAMSETPOINT 120          // Steam temperature setpoint
#define BREWDETECTIONLIMIT 150     // Brew detection limit, be careful: if too low there is a risk of wrong brew detection and rising temperature
#define AGGKP 69                   // PID Kp (regular stage)
#define AGGTN 399                  // PID Tn (regular stage)
#define AGGTV 0                    // PID Tv (regular stage)
#define STARTKP 50                 // PID Kp (coldstart stage)
#define STARTTN 150                // PID Tn (coldstart stage)
#define STEAMKP 150                // PID kp (steam stage)
#define AGGBKP 50                  // PID Kp (brew detection stage)
#define AGGBTN 0                   // PID Tn (brew detection stage)
#define AGGBTV 20                  // PID Tv (brew detection stage)
#define BREW_TIME 25               // Brew time in seconds
#define BREW_SW_TIMER 45           // Brew software timer after detection in seconds
#define PRE_INFUSION_TIME 2        // Pre-infusion time in seconds
#define PRE_INFUSION_PAUSE_TIME 5  // Pre-infusion pause time in seconds
