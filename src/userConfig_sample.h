/**
 * @file    userConfig.h
 *
 * @brief   Values must be configured by the user
 *
 */

#pragma once


// List of supported machines
enum MACHINE {
    RancilioSilvia,   // MACHINEID 0
    RancilioSilviaE,  // MACHINEID 1
    Gaggia,           // MACHINEID 2
    QuickMill         // MACHINEID 3
};

// Machine
#define MACHINEID 0                // see above list of supported machines

// Display
#define OLED_DISPLAY 2             // 0 = deactivated, 1 = SH1106 (e.g. 1.3 "128x64), 2 = SSD1306 (e.g. 0.96" 128x64)
#define OLED_I2C 0x3C              // I2C address for OLED, 0x3C by default
#define DISPLAYTEMPLATE 3          // 1 = Standard Display Template, 2 = Minimal Template, 3 = only Temperatur, 4 = Scale Template, 20 = vertical Display see git Handbook for further information
#define DISPLAYROTATE U8G2_R0      // rotate display clockwise: U8G2_R0 = no rotation; U8G2_R1 = 90°; U8G2_R2 = 180°; U8G2_R3 = 270°
#define SHOTTIMER 1                // 0 = deactivated, 1 = activated 2 = with scale
#define HEATINGLOGO 0              // 0 = deactivated, 1 = Rancilio, 2 = Gaggia
#define OFFLINEGLOGO 1             // 0 = deactivated, 1 = activated
#define BREWSWITCHDELAY 3000       // time in ms
#define LANGUAGE 1                 // LANGUAGE = 0 (DE), LANGUAGE = 1 (EN), LANGUAGE = 2 (ES)

// Connectivity
#define CONNECTMODE 1              // 0 = offline 1 = WIFI-MODE 2 = AP-MODE (not working in the moment)
#define HOSTNAME "silvia"
#define PASS "CleverCoffee"        // default password for WiFiManager
#define MAXWIFIRECONNECTS 5        // maximum number of reconnection attempts, use -1 to deactivate
#define WIFICINNECTIONDELAY 10000  // delay between reconnects in ms

// OTA
#define OTA true                   // true = OTA activated, false = OTA deactivated
#define OTAHOST "silvia"           // Name to be shown in ARUDINO IDE Port
#define OTAPASS "CleverCoffeeOTA"  // Password for OTA updtates

// PID & Hardware
#define ONLYPID 1                  // 1 = Only PID, 0 = PID and preinfusion
#define ONLYPIDSCALE 0             // 0 = off , 1= OnlyPID with Scale
#define BREWMODE 1                 // 1 = NORMAL preinfusion ; 2 = Scale with weight
#define BREWDETECTION 1            // 0 = off, 1 = Software (Onlypid 1), 2 = Hardware (Onlypid 0), 3 = Sensor/Hardware for Only PID
#define BREWSWITCHTYPE 1           // 1 = normal Switch, 2 = Trigger Switch
#define COLDSTART_PID 1            // 1 = default coldstart values, 2 = custom values
#define TRIGGERTYPE HIGH           // LOW = low trigger, HIGH = high trigger relay
#define VOLTAGESENSORTYPE HIGH     // Type of optocoupler for BREWDETECTION = 3

// Brew scale
#define SCALE_WEIGHTSETPOINT 30             // In grams
#define SCALE_SAMPLES 2                     // Load cell sample rate
#define SCALE_CALIBRATION_FACTOR 3195.83    // Raw data is divided by this value to convert to readable data

// Backflush values
#define FILLTIME 3000              // time in ms the pump is running
#define FLUSHTIME 6000             // time in ms the 3-way valve is open -> backflush
#define MAXFLUSHCYCLES 5           // number of cycles the backflush should run, 0 = disabled

/* Pressure sensor
 *
 * measure and verify "offset" value, should be 10% of ADC bit reading @supply volate (3.3V)
 * same goes for "fullScale", should be 90%
 */
#define PRESSURESENSOR 0    // 1 = pressure sensor connected to A0; PINBREWSWITCH must be set to the connected input!
#define OFFSET 102          // 10% of ADC input @3.3V supply = 102
#define FULLSCALE 922       // 90% of ADC input @3.3V supply = 922
#define MAXPRESSURE 200

// MQTT
#define MQTT 0
#define MQTT_USERNAME "mymqttuser"
#define MQTT_PASSWORD "mymqttpass"
#define MQTT_TOPIC_PREFIX "appliances/kitchen." // topic will be "<MQTT_TOPIC_PREFIX><HOSTNAME>/<READING>"
#define MQTT_SERVER_IP "XXX.XXX.XXX.XXX"        // IP address of the local mqtt broker instance
#define MQTT_SERVER_PORT 1883

// INFLUXDB
#define INFLUXDB 0
#define INFLUXDB_URL ""            // InfluxDB server address
#define INFLUXDB_AUTH_TYPE 1       // 1 = API Token , 2 = User/Pass
#define INFLUXDB_API_TOKEN ""
#define INFLUXDB_ORG_NAME ""
#define INFLUXDB_USER ""
#define INFLUXDB_PASSWORD ""
#define INFLUXDB_DB_NAME "coffee"  // InfluxDB bucket name
#define INFLUXDB_INTERVAL 5000     // Send interval in milliseconds

// Historic (no settings)
#define PONE 1                     // 1 = P_ON_E (default), 0 = P_ON_M (special PID mode, other PID-parameter are needed)
#define TEMPSENSORTYPE 2           // 2 = TSIC306 1=DS18B20

// defined compiler errors
#if (PRESSURESENSOR == 1) && (PINPRESSURESENSOR == 0) && (PINBREWSWITCH == 0)
    #error Change PINBREWSWITCH or PRESSURESENSOR!
#endif

