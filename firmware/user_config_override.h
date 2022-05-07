/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

// platformio run -e tasmota or just platformio run

// !!! Remember that your changes GOES AT THE BOTTOM OF THIS FILE right before the last #endif !!! 
// sample file from the live stream of compiling via gitpod https://youtu.be/9Am5hf7eHho

// force the compiler to show a warning to confirm that this file is included
#warning **** user_config_override.h: Using Settings from this File ****

// ***********************************************
// ** Global settings for all binaries ***********

// NO HA or Tasmota discovery
#ifdef USE_HOME_ASSISTANT
   #undef USE_HOME_ASSISTANT
#endif
#ifdef USE_TASMOTA_DISCOVERY
   #undef USE_TASMOTA_DISCOVERY
#endif

// Set MODULE to WEMOS
#ifdef MODULE
  #undef MODULE
#endif
#define MODULE WEMOS

// Use WiFi Manager and WiFi scan
#ifdef WIFI_CONFIG_TOOL
  #undef WIFI_CONFIG_TOOL
#endif
#define WIFI_CONFIG_TOOL WIFI_MANAGER

#ifdef WIFI_AP_PASSPHRASE
  #undef WIFI_AP_PASSPHRASE
#endif
#define WIFI_AP_PASSPHRASE "tazpass123456"

#ifdef WIFI_SCAN_AT_RESTART
  #undef WIFI_SCAN_AT_RESTART
#endif
#define WIFI_SCAN_AT_RESTART true

#ifdef WIFI_SCAN_REGULARLY
  #undef WIFI_SCAN_REGULARLY
#endif
#define WIFI_SCAN_REGULARLY true

// -- Time - Start Daylight Saving Time and timezone offset from UTC in minutes
// "cmnd/tasmotas/timedst" -m "1, 0, 9, 1, 2, +780"

#ifdef TIME_DST_HEMISPHERE
  #undef TIME_DST_HEMISPHERE
#endif
#define TIME_DST_HEMISPHERE    South              // [TimeDst] Hemisphere (0 or North, 1 or South)
#ifdef TIME_DST_WEEK
  #undef TIME_DST_WEEK
#endif
#define TIME_DST_WEEK          Last               // Week of month (0 or Last, 1 or First, 2 or Second, 3 or Third, 4 or Fourth)
#ifdef TIME_DST_MONTH
  #undef TIME_DST_MONTH
#endif
#define TIME_DST_MONTH         Sep                // Month (1 or Jan, 2 or Feb, 3 or Mar, 4 or Apr, 5 or May, 6 or Jun, 7 or Jul, 8 or Aug, 9 or Sep, 10 or Oct, 11 or Nov, 12 or Dec)
#ifdef TIME_DST_DAY
  #undef TIME_DST_DAY
#endif
#define TIME_DST_DAY           Sun                // Day of week (1 or Sun, 2 or Mon, 3 or Tue, 4 or Wed, 5 or Thu, 6 or Fri, 7 or Sat)
#ifdef TIME_DST_HOUR
  #undef TIME_DST_HOUR
#endif
#define TIME_DST_HOUR          2                  // Hour (0 to 23)
#ifdef TIME_DST_OFFSET
  #undef TIME_DST_OFFSET
#endif
#define TIME_DST_OFFSET        +780               // Offset from UTC in minutes (-780 to +780)

// -- Time - Start Standard Time and timezone offset from UTC in minutes
// "cmnd/tasmotas/timestd" -m "1, 1, 4, 1, 3, +720"

#ifdef TIME_STD_HEMISPHERE
  #undef TIME_STD_HEMISPHERE
#endif
#define TIME_STD_HEMISPHERE    South              // [TimeStd] Hemisphere (0 or North, 1 or South)
#ifdef TIME_STD_WEEK
  #undef TIME_STD_WEEK
#endif
#define TIME_STD_WEEK          First               // Week of month (0 or Last, 1 or First, 2 or Second, 3 or Third, 4 or Fourth)
#ifdef TIME_STD_MONTH
  #undef TIME_STD_MONTH
#endif
#define TIME_STD_MONTH         Apr                // Month (1 or Jan, 2 or Feb, 3 or Mar, 4 or Apr, 5 or May, 6 or Jun, 7 or Jul, 8 or Aug, 9 or Sep, 10 or Oct, 11 or Nov, 12 or Dec)
#ifdef TIME_STD_DAY
  #undef TIME_STD_DAY
#endif
#define TIME_STD_DAY           Sun                // Day of week (1 or Sun, 2 or Mon, 3 or Tue, 4 or Wed, 5 or Thu, 6 or Fri, 7 or Sat)
#ifdef TIME_STD_HOUR
  #undef TIME_STD_HOUR
#endif
#define TIME_STD_HOUR          3                  // Hour (0 to 23)
#ifdef TIME_STD_OFFSET
  #undef TIME_STD_OFFSET
#endif
#define TIME_STD_OFFSET        +720                // Offset from UTC in minutes (-780 to +780)

// -- Application ---------------------------------
#ifdef APP_TIMEZONE
  #undef APP_TIMEZONE
#endif
#define APP_TIMEZONE           99                 // [Timezone] +1 hour (Amsterdam) (-13 .. 14 = hours from UTC, 99 = use TIME_DST/TIME_STD)

// -- Location ------------------------------------
#ifdef LATITUDE
  #undef LATITUDE
#endif
#define LATITUDE            -43.4793487          // [Latitude] Your location to be used with sunrise and sunset
#ifdef LONGITUDE
  #undef LONGITUDE
#endif
#define LONGITUDE            172.6067354        // [Longitude] Your location to be used with sunrise and sunset

// ***********************************************
// ** Firmare specific settings ******************

// -- Options for firmware tasmota-foo and tasmota32-foo ------
#ifdef FIRMWARE_FOO
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: FOO ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "foo"

    // Put here your override for firmware tasmota-foo
    #undef USE_ARDUINO_OTA  
    #undef USE_DOMOTICZ 
    #undef USE_TELEGRAM                              // Disable Domoticz
    #undef USE_MQTT_TLS                              // Disable TLS support won't work as the MQTTHost is not set
    #undef USE_KNX 
    #undef USE_JAVASCRIPT_ES6 
    #undef USE_WEBSEND_RESPONSE                      // Disable command WebSend response message (+1k code)
    #undef USE_EMULATION                             // Disable Wemo or Hue emulation
    #undef USE_EMULATION_HUE                         // Disable Hue Bridge emulation for Alexa (+14k code, +2k mem common)
    #undef USE_EMULATION_WEMO                        // Disable Belkin WeMo emulation for Alexa (+6k code, +2k mem common)
    //#undef USE_CUSTOM                                // Disable Custom features
    #undef USE_DISCOVERY                             // Disable Discovery services for both MQTT and web server
    //#undef USE_TIMERS                                // Disable support for up to 16 timers
    #undef USE_TIMERS_WEB                            // Disable support for timer webpage
    #undef USE_SUNRISE                               // Disable support for Sunrise and sunset tools
    #undef USE_SCRIPT                                  // Add support for script (+17k code)
    #undef ROTARY_V1                                 // Disable support for MI Desk Lamp
    #undef USE_SONOFF_SC
    #undef USE_RF_FLASH                              // Disable support for Sonoff Sc (+1k1 code)
    #undef USE_ARMTRONIX_DIMMERS                     // Disable support for Armtronix Dimmers (+1k4 code)
    #undef USE_PS_16_DZ                              // Disable support for PS-16-DZ Dimmer and Sonoff L1 (+2k code)
    #undef USE_ARILUX_RF                             // Disable support for Arilux RF remote controller
    #undef USE_SHUTTER                               // Disable Shutter support for up to 4 shutter with different motortypes (+6k code)
    #undef USE_DEEPSLEEP                             // Disable support for deepsleep (+1k code)
    #undef USE_EXS_DIMMER                            // Disable support for EX-Store WiFi Dimmer
    #undef USE_HOTPLUG                               // Disable support for HotPlug
    #undef USE_PWM_DIMMER_REMOTE                     // Disbale support for remote switches to PWM Dimmer
    #undef USE_KEELOQ                                // Disable support for Jarolift rollers by Keeloq algorithm (+4k5 code)

    // -- Optional light modules ----------------------
    //#define USE_LIGHT                                // Add Dimmer/Light support
    #undef USE_WS2812                                // Disable WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //
    #undef USE_SONOFF_D1                             // Disable support for Sonoff D1 Dimmer (+0k7 code)
    #undef USE_SM16716                               // Disable support for SM16716 RGB LED controller (+0k7 code)
    #undef USE_SM2135                                // Disable support for SM2135 RGBCW led control as used in Action LSC (+0k6 code)
    #undef USE_SONOFF_L1                             // Disable support for Sonoff L1 led control
    #undef USE_ELECTRIQ_MOODL                        // Disable support for ElectriQ iQ-wifiMOODL RGBW LED controller
    #undef USE_LIGHT_PALETTE                         // Disable support for color palette (+0k9 code)
    #undef USE_DGR_LIGHT_SEQUENCE                         // Disable support for color palette (+0k9 code)

    #undef USE_MY92X1                               // Add support for MY92X1 RGBCW led controller as used in Sonoff B1, Ailight and Lohas

    #undef USE_SHELLY_DIMMER                         // Disable support for Shelly Dimmer (+3k code)
    #undef USE_COUNTER                               // Disable counters
    #undef USE_ADC_VCC                              // Display Vcc in Power status. Disable for use as Analog input on selected devices
    #undef USE_DS18x20                               // Disable DS18x20 sensor
    #undef USE_I2C                                   // Disable all I2C sensors and devices
    #undef USE_SPI                                   // Disable all SPI devices
    #undef USE_DISPLAY                               // Disable Display support
    #undef USE_MHZ19                                 // Disable support for MH-Z19 CO2 sensor
    #undef USE_SENSEAIR                              // Disable support for SenseAir K30, K70 and S8 CO2 sensor
    #undef USE_PMS5003                               // Disable support for PMS5003 and PMS7003 particle concentration sensor
    #undef USE_NOVA_SDS                              // Disable support for SDS011 and SDS021 particle concentration sensor
    #undef USE_HPMA                                  // Disable support for Honeywell HPMA115S0 particle concentration sensor
    #undef USE_SR04                                  // Disable support for HC-SR04 ultrasonic devices (+1k code)
    #undef USE_DYP                                   // Disable support for DYP ME-007 ultrasonic distance sensor, serial port version (+0k5 code)
    #undef USE_MP3_PLAYER                            // Disable DFPlayer Mini MP3 Player RB-DFR-562 commands: play, volume and stop
    #undef USE_SERIAL_BRIDGE                        // Add support for software Serial Bridge (+0k8 code)
    #undef USE_TCP_BRIDGE                           //  Add support for Serial to TCP bridge (+1.3k code)
    #undef USE_AZ7798                                // Disable support for AZ-Instrument 7798 CO2 datalogger
    #undef USE_PN532_HSU                             // Disable support for PN532 using HSU (Serial) interface (+1k8 code, 140 bytes mem)
    #undef USE_ZIGBEE                                // Disable serial communication with Zigbee CC2530 flashed with ZNP
    #undef USE_RDM6300                               // Disable support for RDM6300 125kHz RFID Reader (+0k8)
    #undef USE_IBEACON                               // Disable support for bluetooth LE passive scan of ibeacon devices (uses HM17 module)
    #undef USE_GPS                                   // Disable support for GPS and NTP Server for becoming Stratus 1 Time Source (+ 3.1kb flash, +132 bytes RAM)
    #undef USE_HM10                                  // (ESP8266 only) Disable support for HM-10 as a BLE-bridge for the LYWSD03 (+5k1 code)
    #undef USE_MI_ESP32                              // (ESP32 only) Disable support for ESP32 as a BLE-bridge (+9k2 mem, +292k flash)
    #undef USE_HRXL                                  // Disable support for MaxBotix HRXL-MaxSonar ultrasonic range finders (+0k7)
    #undef USE_TASMOTA_CLIENT                        // Disable support for Arduino Uno/Pro Mini via serial interface including flashing (+2k3 code, 44 mem)
    #undef USE_OPENTHERM                             // Disable support for OpenTherm (+15k code)
    #undef USE_MIEL_HVAC                             // Disable support for Mitsubishi Electric HVAC serial interface (+5k code)
    #undef USE_BL0940                               // Add support for BL0940 Energy monitor as used in Blitzwolf SHP-10 (+1k6 code)
    #undef USE_PZEM004T                              // Disable PZEM004T energy sensor
    #undef USE_PZEM_AC                               // Disable PZEM014,016 Energy monitor
    #undef USE_PZEM_DC                               // Disable PZEM003,017 Energy monitor
    #undef USE_MCP39F501                             // Disable MCP39F501 Energy monitor as used in Shelly 2
    #undef USE_SDM120                                // Disable support for Eastron SDM120-Modbus energy meter
    #undef USE_SDM630                                // Disable support for Eastron SDM630-Modbus energy monitor (+0k6 code)
    #undef USE_DDS2382                               // Disable support for Hiking DDS2382 Modbus energy monitor (+0k6 code)
    #undef USE_DDSU666                               // Disable support for Chint DDSU666 Modbus energy monitor (+0k6 code)
    #undef USE_SOLAX_X1                              // Disable support for Solax X1 series Modbus log info (+3k1 code)
    #undef USE_LE01MR                                // Disable support for F&F LE-01MR Modbus energy meter (+2k code)
    #undef USE_TELEINFO                              // Disable support for French Energy Provider metering telemetry
    #undef USE_IEM3000                               // Disable support for Schneider Electric iEM3000-Modbus series energy monitor (+0k8 code)
    #undef USE_WE517                                 // Disable support for Orno WE517-Modbus energy monitor (+1k code)
    #undef USE_DHT                                   // Disable support for DHT11, AM2301 (DHT21, DHT22, AM2302, AM2321) and SI7021 Temperature and Humidity sensor
    #undef USE_MAX31855                              // Disable MAX31855 K-Type thermocouple sensor using softSPI
    #undef USE_MAX31865                              // Disable support for MAX31865 RTD sensors using softSPI
    #undef USE_LMT01
    #undef USE_IR_REMOTE                             // Disable IR driver
    #undef USE_TM1638                                // Disable support for TM1638 switches copying Switch1 .. Switch8
    #undef USE_HX711                                 // Disable support for HX711 load cell
    #undef USE_TX20_WIND_SENSOR                      // Disable support for La Crosse TX20 anemometer
    #undef USE_TX23_WIND_SENSOR                      // Disable support for La Crosse TX23 anemometer
    #undef USE_WINDMETER                             // Disable support for analog anemometer (+2k2 code)
    #undef USE_FTC532                               // Add support for FTC532 8-button touch controller (+0k6 code)
    #undef USE_PROMETHEUS                           // Add support for https://prometheus.io/ metrics exporting over HTTP /metrics endpoint
    #undef USE_NEOPOOL                              // Add support for Sugar Valley NeoPool Controller - also known under brands Hidrolife, Aquascenic, Oxilife, Bionet, Hidroniser, UVScenic, Station, Brilix, Bayrol and Hay (+6k flash, +60 mem)
    #undef USE_RC_SWITCH                             // Disable support for RF transceiver using library RcSwitch
    #undef USE_RF_SENSOR                             // Disable support for RF sensor receiver (434MHz or 868MHz) (+0k8 code)
    #undef USE_HRE                                   // Disable support for Badger HR-E Water Meter (+1k4 code)
    #undef USE_A4988_STEPPER                         // Disable support for A4988_Stepper
    #undef USE_THERMOSTAT                            // Disable support for Thermostat
    #undef DEBUG_THEO                                // Disable debug code
    #undef USE_DEBUG_DRIVER                          // Disable debug code
    #undef USE_PING                                  // Disable Ping command (+2k code)
    #undef USE_UNISHOX_COMPRESSION                   // Disable support for string compression in Rules or Scripts
    #undef USE_BL0940
    
#endif


/*********************************************************************************************\
 * -- Options for firmware tasmota-bar -- Based upon[tasmota-ir.bin]
 * Provide a dedicated image with IR full protocol support, with limited additional features
\*********************************************************************************************/

#ifdef FIRMWARE_BAR
  #warning **** Build: BAR ****
  #undef CODE_IMAGE_STR
  #define CODE_IMAGE_STR "bar"

  #undef USE_ARDUINO_OTA  
  #undef USE_TELEGRAM                              // Disable Domoticz
  #undef USE_MQTT_TLS                              // Disable TLS support won't work as the MQTTHost is not set
  #undef USE_JAVASCRIPT_ES6 
  #undef USE_WEBSEND_RESPONSE                      // Disable command WebSend response message (+1k code)
  #undef USE_EMULATION
  #undef USE_EMULATION_HUE                         // Disable Hue emulation - only for lights and relays
  #undef USE_EMULATION_WEMO                        // Disable Wemo emulation - only for relays
  #undef USE_DOMOTICZ                              // Disable Domoticz
  #undef USE_HOME_ASSISTANT                        // Disable Home Assistant
  #undef USE_KNX                                   // Disable KNX IP Protocol Support
  //#undef USE_CUSTOM                                // Disable Custom features
  //#undef USE_TIMERS                                // Disable support for up to 16 timers
  #undef USE_TIMERS_WEB                            // Disable support for timer webpage
  #undef USE_SUNRISE                               // Disable support for Sunrise and sunset tools
  //#undef USE_RULES                                 // Disable support for rules
  #undef USE_DISCOVERY                             // Disable mDNS for the following services (+8k code or +23.5k code with core 2_5_x, +0.3k mem)

  // -- IR options ----------------------------
  #define USE_IR_REMOTE                            // Enable IR remote commands using library IRremoteESP8266
  #define USE_IR_REMOTE_FULL                       // Support all IR protocols from IRremoteESP8266

  // -- Optional modules ----------------------------
  #undef ROTARY_V1                                 // Disable support for MI Desk Lamp
  #undef USE_SONOFF_RF                             // Disable support for Sonoff Rf Bridge (+3k2 code)
    #undef USE_RF_FLASH                            // Disable support for flashing the EFM8BB1 chip on the Sonoff RF Bridge. C2CK must be connected to GPIO4, C2D to GPIO5 on the PCB
  #undef USE_SONOFF_SC                             // Disable support for Sonoff Sc (+1k1 code)
  #undef USE_TUYA_MCU                              // Disable support for Tuya Serial MCU
  #undef USE_ARMTRONIX_DIMMERS                     // Disable support for Armtronix Dimmers (+1k4 code)
  #undef USE_PS_16_DZ                              // Disable support for PS-16-DZ Dimmer and Sonoff L1 (+2k code)
  #undef USE_SONOFF_IFAN                           // Disable support for Sonoff iFan02 and iFan03 (+2k code)
  #undef USE_BUZZER                                // Disable support for a buzzer (+0k6 code)
  #undef USE_ARILUX_RF                             // Disable support for Arilux RF remote controller
  #undef USE_SHUTTER                               // Disable Shutter support for up to 4 shutter with different motortypes (+6k code)
  #undef USE_DEEPSLEEP                             // Disable support for deepsleep (+1k code)
  #undef USE_EXS_DIMMER                            // Disable support for EX-Store WiFi Dimmer
  #undef USE_HOTPLUG                               // Disable support for HotPlug
  #undef USE_DEVICE_GROUPS                         // Disable support for device groups (+3k5 code)
  #undef USE_PWM_DIMMER                            // Disable support for MJ-SD01/acenx/NTONPOWER PWM dimmers (+4k5 code)
  #undef USE_PWM_DIMMER_REMOTE                     // Disbale support for remote switches to PWM Dimmer
  #undef USE_KEELOQ                                // Disable support for Jarolift rollers by Keeloq algorithm (+4k5 code)
  #undef USE_SONOFF_D1                             // Disable support for Sonoff D1 Dimmer (+0k7 code)

  // -- Optional light modules ----------------------
  //#undef USE_LIGHT                                 // Also disable all Dimmer/Light support
  #undef USE_WS2812                                // Disable WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //
  #undef USE_MY92X1                                // Disable support for MY92X1 RGBCW led controller as used in Sonoff B1, Ailight and Lohas
  #undef USE_SM16716                               // Disable support for SM16716 RGB LED controller (+0k7 code)
  #undef USE_SM2135                                // Disable support for SM2135 RGBCW led control as used in Action LSC (+0k6 code)
  #undef USE_SONOFF_L1                             // Disable support for Sonoff L1 led control
  #undef USE_ELECTRIQ_MOODL                        // Disable support for ElectriQ iQ-wifiMOODL RGBW LED controller
  #undef USE_LIGHT_PALETTE                         // Disable support for color palette (+0k9 code)
  #undef USE_SHELLY_DIMMER                         // Disable support for Shelly Dimmer (+3k code)

  #undef USE_COUNTER                               // Disable counters
  #define USE_ADC_VCC                              // Display Vcc in Power status. Disable for use as Analog input on selected devices
  #undef USE_DS18x20                               // Disable DS18x20 sensor

  #undef USE_ENERGY_SENSOR                         // Disable energy sensors (-14k code)
    #undef USE_PZEM004T                            // Disable PZEM004T energy sensor
    #undef USE_PZEM_AC                             // Disable PZEM014,016 Energy monitor
    #undef USE_PZEM_DC                             // Disable PZEM003,017 Energy monitor
    #undef USE_MCP39F501                           // Disable MCP39F501 Energy monitor as used in Shelly 2
    #undef USE_SDM72                               // Disable support for Eastron SDM72-Modbus energy meter
    #undef USE_SDM120                              // Disable support for Eastron SDM120-Modbus energy meter
    #undef USE_SDM230                              // Disable support for Eastron SDM230-Modbus energy monitor (+?? code)
    #undef USE_SDM630                              // Disable support for Eastron SDM630-Modbus energy monitor (+0k6 code)
    #undef USE_DDS2382                             // Disable support for Hiking DDS2382 Modbus energy monitor (+0k6 code)
    #undef USE_DDSU666                             // Disable support for Chint DDSU666 Modbus energy monitor (+0k6 code)
    #undef USE_SOLAX_X1                            // Disable support for Solax X1 series Modbus log info (+3k1 code)
    #undef USE_LE01MR                              // Disable support for F&F LE-01MR Modbus energy meter (+2k code)
    #undef USE_TELEINFO                            // Disable support for French Energy Provider metering telemetry
    #undef USE_IEM3000                             // Disable support for Schneider Electric iEM3000-Modbus series energy monitor (+0k8 code)
    #undef USE_WE517                               // Disable support for Orno WE517-Modbus energy monitor (+1k code)

  //#undef USE_DS18x20                               // Disable support for DS18x20 sensors with id sort, single scan and read retry (+1k3 code)

  #undef USE_I2C                                   // Disable all I2C sensors
  #undef USE_SPI                                   // Disable all SPI devices

  #undef USE_DISPLAY                               // Disable support for displays

  #undef USE_MHZ19                                 // Disable support for MH-Z19 CO2 sensor
  #undef USE_SENSEAIR                              // Disable support for SenseAir K30, K70 and S8 CO2 sensor
  #undef USE_PMS5003                               // Disable support for PMS5003 and PMS7003 particle concentration sensor
  #undef USE_NOVA_SDS                              // Disable support for SDS011 and SDS021 particle concentration sensor
  #undef USE_HPMA                                  // Disable support for Honeywell HPMA115S0 particle concentration sensor
  #undef USE_SR04                                  // Disable support for HC-SR04 ultrasonic devices (+1k code)
  #undef USE_DYP                                   // Disable support for DYP ME-007 ultrasonic distance sensor, serial port version (+0k5 code)
  #undef USE_SERIAL_BRIDGE                         // Disable support for software Serial Bridge
  #undef USE_MP3_PLAYER                            // Disable DFPlayer Mini MP3 Player RB-DFR-562 commands: play, volume and stop
  #undef USE_AZ7798                                // Disable support for AZ-Instrument 7798 CO2 datalogger
  #undef USE_PN532_HSU                             // Disable support for PN532 using HSU (Serial) interface (+1k8 code, 140 bytes mem)
  #undef USE_ZIGBEE                                // Disable serial communication with Zigbee CC2530 flashed with ZNP
  #undef USE_RDM6300                               // Disable support for RDM6300 125kHz RFID Reader (+0k8)
  #undef USE_IBEACON                               // Disable support for bluetooth LE passive scan of ibeacon devices (uses HM17 module)
  #undef USE_GPS                                   // Disable support for GPS and NTP Server for becoming Stratus 1 Time Source (+ 3.1kb flash, +132 bytes RAM)
  #undef USE_HM10                                  // (ESP8266 only) Disable support for HM-10 as a BLE-bridge for the LYWSD03 (+5k1 code)
  #undef USE_BLE_ESP32                             // (ESP32 only) Disable support for native BLE on ESP32 - use new driver
  #undef USE_MI_ESP32                              // (ESP32 only) Disable support for ESP32 as a BLE-bridge (+9k2 mem, +292k flash)
  #undef USE_HRXL                                  // Disable support for MaxBotix HRXL-MaxSonar ultrasonic range finders (+0k7)
  #undef USE_TASMOTA_CLIENT                        // Disable support for Arduino Uno/Pro Mini via serial interface including flashing (+2k3 code, 44 mem)
  #undef USE_OPENTHERM                             // Disable support for OpenTherm (+15k code)
  #undef USE_MIEL_HVAC                             // Disable support for Mitsubishi Electric HVAC serial interface (+5k code)
  #undef USE_PROJECTOR_CTRL                        // Disable support for LCD/DLP Projector serial control interface

  #undef USE_DHT                                   // Disable support for DHT11, AM2301 (DHT21, DHT22, AM2302, AM2321) and SI7021 Temperature and Humidity sensor
  #undef USE_MAX31855                              // Disable MAX31855 K-Type thermocouple sensor using softSPI
  #undef USE_MAX31865                              // Disable support for MAX31865 RTD sensors using softSPI
  #undef USE_TM1638                                // Disable support for TM1638 switches copying Switch1 .. Switch8
  #undef USE_HX711                                 // Disable support for HX711 load cell
  #undef USE_TX20_WIND_SENSOR                      // Disable support for La Crosse TX20 anemometer
  #undef USE_TX23_WIND_SENSOR                      // Disable support for La Crosse TX23 anemometer
  #undef USE_WINDMETER                             // Disable support for analog anemometer (+2k2 code)
  #undef USE_RC_SWITCH                             // Disable support for RF transceiver using library RcSwitch
  #undef USE_RF_SENSOR                             // Disable support for RF sensor receiver (434MHz or 868MHz) (+0k8 code)
  #undef USE_HRE                                   // Disable support for Badger HR-E Water Meter (+1k4 code)
  #undef USE_A4988_STEPPER                         // Disable support for A4988_Stepper
  #undef USE_THERMOSTAT                            // Disable support for Thermostat
  #undef DEBUG_THEO                                // Disable debug code
  #undef USE_DEBUG_DRIVER                          // Disable debug code
#endif  // FIRMWARE_BAR

// -- Options for firmware tasmota-prox ------
#ifdef FIRMWARE_PROX
    #warning **** Build: PROX ****
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "prox"

    // Put here your override for firmware tasmota-prox
    #undef USE_ARDUINO_OTA  
    #undef USE_DOMOTICZ 
    #undef USE_TELEGRAM                              // Disable Domoticz
    #undef USE_MQTT_TLS                              // Disable TLS support won't work as the MQTTHost is not set
    #undef USE_KNX 
    #undef USE_JAVASCRIPT_ES6 
    #undef USE_WEBSEND_RESPONSE                      // Disable command WebSend response message (+1k code)
    #undef USE_EMULATION                             // Disable Wemo or Hue emulation
    #undef USE_EMULATION_HUE                         // Disable Hue Bridge emulation for Alexa (+14k code, +2k mem common)
    #undef USE_EMULATION_WEMO 

    #define USE_WIEGAND                              // Add support for 24/26/32/34 bit RFID Wiegand interface (D0/D1) (+1k7 code)

#endif

// -- Options for firmware tasmota32-grizzly ------
#ifdef FIRMWARE_GRIZZLY

    // If these settings are only for ESP32, you can check these
    // are used only when building for ESP32
    #ifndef ESP32
    #error *** This setup of for tasmota32 only ***
    #endif

    #warning **** Build: GRIZZLY ****
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "grizzly"

    // Put here your override for firmware tasmota32-grizzly

#endif

#endif  // _USER_CONFIG_OVERRIDE_H_
