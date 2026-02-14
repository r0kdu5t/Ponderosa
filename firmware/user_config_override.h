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

// force the compiler to show a warning to confirm that this file is included
#warning **** user_config_override.h: USING SETTINGS FROM THIS FILE ****

// ***********************************************
// ** Global settings for all binaries ***********

// -- Setup your own Wifi settings  ---------------
#ifdef WIFI_SCAN_AT_RESTART
  #undef WIFI_SCAN_AT_RESTART
#endif
#define WIFI_SCAN_AT_RESTART true

#ifdef WIFI_SCAN_REGULARLY
  #undef WIFI_SCAN_REGULARLY
#endif
#define WIFI_SCAN_REGULARLY true

// UNDEF stuff here that I don't want in my mix.
//#undef USE_ARDUINO_OTA
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
//#undef USE_DISCOVERY                             // Disable Discovery services for both MQTT and web server
//#undef USE_TIMERS                                // Disable support for up to 16 timers
//#undef USE_TIMERS_WEB                            // Disable support for timer webpage
//#undef USE_SUNRISE                               // Disable support for Sunrise and sunset tools
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
#undef USE_SONOFF_D1                             // Disable support for Sonoff D1 Dimmer (+0k7 code)
#undef USE_SHELLY_DIMMER                         // Disable support for Shelly Dimmer (+3k code)
#undef USE_ENERGY_SENSOR                         // Disable energy sensors (-14k code)

// ***********************************************
// ** Firmware specific settings *****************

// -- Options for firmware tasmota-wiegand and tasmota32-wiegand ------
#ifdef FIRMWARE_WIEGAND
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: WIEGAND ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "custom-wiegand"

    // Put here your override for firmware tasmota-foo
    // -- No IR options ----------------------------
    #ifdef USE_IR_REMOTE
      #undef USE_IR_REMOTE                          // Enable IR remote commands using library IRremoteESP8266
    #endif
    #ifdef USE_IR_REMOTE_FULL
      #undef USE_IR_REMOTE_FULL                     // Support all IR protocols from IRremoteESP8266
    #endif
    // -- Add Wiegand ---
    #ifndef USE_WIEGAND                             // Add support for 24/26/32/34 bit RFID Wiegand interface (D0/D1) (+1k7 code)
      #define USE_WIEGAND
    #endif
#endif

// -- Options for firmware tasmota-smartmeter and tasmota32-smartmeter ------
#ifdef FIRMWARE_SMARTMETER
    #warning **** Build: SMARTMETER ****
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "custom-smartmeter"

    #ifndef USE_ENERGY_SENSOR
        #define USE_ENERGY_SENSOR                 // Add energy sensors (-14k code)
        //
    #endif

    // Put here your override for firmware custom-smartmeter
    // Added the following as I only have a pulse led meter.
    //#define NO_USE_SML_SPECOPT
    //#define NO_USE_SML_DECRYPT
    //#define NO_USE_SML_TCP
    //#define NO_SML_OBIS_LINE

    #ifndef USE_SCRIPT
      #define USE_SCRIPT
    #endif
    #ifndef USE_SML_M
      #define USE_SML_M
      #define USE_SML_SCRIPT_CMD
    #endif
    #ifdef USE_RULES
      #undef USE_RULES
    #endif

    // If these settings are only for ESP32, you can check these
    // are used only when building for ESP32
    #ifdef ESP32
      #warning *** Build this setup for tasmota32 ONLY ***
      // Add support for ethernet (Currently fixed for Olimex ESP32-PoE)
      #define USE_ETHERNET                           // Add support for ethernet (Currently fixed for Olimex ESP32-PoE)
      #define ETH_TYPE          0                    // [EthType] 0 = ETH_PHY_LAN8720, 1 = ETH_PHY_TLK110, 2 = ETH_PHY_IP101
      #define ETH_ADDR          0                    // [EthAddress] 0 = PHY0 .. 31 = PHY31
      #define ETH_CLKMODE       3                    // [EthClockMode] 0 = ETH_CLOCK_GPIO0_IN, 1 = ETH_CLOCK_GPIO0_OUT, 2 = ETH_CLOCK_GPIO16_OUT, 3 = ETH_CLOCK_GPIO17_OUT
    #endif

#endif

// -- Options for firmware tasmota32-i2saudio ------
#ifdef FIRMWARE_I2SAUDIO

    // If these settings are only for ESP32, you can check these
    // are used only when building for ESP32
    #ifndef ESP32
      #error *** This setup is for tasmota32 only ***
    #endif

    #warning **** Build: I2SAUDIO ****
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "custom-I2S"

    // Put here your override for firmware custom-I2S
    #ifndef USE_I2S_AUDIO
    #define USE_I2S_AUDIO                             // Add support for I2S audio output
    // #define USE_I2S_NO_DAC                         // Add support for transistor-based output without DAC
    // #define USE_I2S_LSB                            // Add support for LSBJ chips, e.g. TM8211/PT8211
    // #define USE_I2S_WEBRADIO                       // Add support for MP3 web radio streaming (only on ESP32 with PSRAM)
    #define USE_I2S_SAY_TIME                          // Add support for english speaking clock
    #define USE_I2S_RTTTL                             // Add support for Rtttl playback
    #endif
#endif

// -- Options for firmware tasmota-client ------
#ifdef FIRMWARE_TCLIENT
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "custom-tclient"

    // -- No IR options ----------------------------
    #ifdef USE_IR_REMOTE
        #undef USE_IR_REMOTE                        // Enable IR remote commands using library IRremoteESP8266
    #endif
    #ifdef USE_IR_REMOTE_FULL
        #undef USE_IR_REMOTE_FULL                   // Support all IR protocols from IRremoteESP8266
    #endif

    #ifndef USE_TASMOTA_CLIENT
        #define USE_TASMOTA_CLIENT    // Enable the driver
    #endif
    #ifndef USE_TASMOTA_CLIENT_FLASH_SPEED
        #define USE_TASMOTA_CLIENT_FLASH_SPEED 57600    // Configure the baud rate of the bootloader
    #endif
    #ifndef USE_TASMOTA_CLIENT_SERIAL_SPEED 57600  
        #define USE_TASMOTA_CLIENT_SERIAL_SPEED 57600    // Configure the baud rate at which the client microcontroller will be interfacing to Tasmota
    #endif
#endif

// -- Options for firmware tasmota-radar and tasmota32-radar ------
#ifdef FIRMWARE_RADAR
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: RADAR ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "custom-radar"

    // Put here your override for firmware tasmota-radar and tasmota32-radar
    // -- No IR options ----------------------------
    #ifdef USE_IR_REMOTE
      #undef USE_IR_REMOTE                        // Enable IR remote commands using library IRremoteESP8266
    #endif
    #ifdef USE_IR_REMOTE_FULL
      #undef USE_IR_REMOTE_FULL                   // Support all IR protocols from IRremoteESP8266
    #endif
    // -- Add Radar LD2410 ---
    #ifndef USE_LD2410
      #define USE_LD2410
    #endif
#endif

// -- Options for firmware tasmota-energy-monitor and tasmota32-energy-monitor ------
#ifdef FIRMWARE_ENERGY
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: ENERGY ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "custom-energy-monitor"

    // Put here your override for firmware tasmota-energy-monitor and tasmota32-energy-monitor
    // -- No IR options ----------------------------
    #ifdef USE_IR_REMOTE
      #undef USE_IR_REMOTE                        // Enable IR remote commands using library IRremoteESP8266
    #endif
    #ifdef USE_IR_REMOTE_FULL
      #undef USE_IR_REMOTE_FULL                   // Support all IR protocols from IRremoteESP8266
    #endif
    // -- Add Energy Monitoring ---
    #ifndef USE_ENERGY_SENSOR
        #define USE_ENERGY_SENSOR                 // Add energy sensors (-14k code)
        #define USE_PZEM004T                      // Add support for PZEM004T Energy monitor (+2k code)
        #define USE_PZEM_AC                       // Add support for PZEM014,016 Energy monitor (+1k1 code)
        #define USE_PZEM_DC                       // Add support for PZEM003,017 Energy monitor (+1k1 code)
        #define USE_CSE7766                       // This is suppose to add support for HLW8032 Energy monitor (+ code)
        #undef USE_MCP39F501                      // Add support for MCP39F501 Energy monitor as used in Shelly 2 (+3k1 code)
        #undef USE_SDM72                          // Add support for Eastron SDM72-Modbus energy monitor (+0k3 code)
        #undef USE_SDM120                         // Add support for Eastron SDM120-Modbus energy monitor (+1k1 code)
        #undef USE_SDM230                         // Add support for Eastron SDM230-Modbus energy monitor (+?? code)
        #undef USE_SDM630                         // Add support for Eastron SDM630-Modbus energy monitor (+0k6 code)
        #undef USE_DDS2382                        // Add support for Hiking DDS2382 Modbus energy monitor (+0k6 code)
        #undef USE_DDSU666                        // Add support for Chint DDSU666 Modbus energy monitor (+0k6 code)
        //#define USE_SOLAX_X1                    // Add support for Solax X1 series Modbus log info (+3k1 code)
        //#define USE_LE01MR                      // Add support for F&F LE-01MR modbus energy meter (+2k code)
        //#define USE_TELEINFO                    // Add support for French Energy Provider metering telemetry (+5k2 code, +168 RAM + SmartMeter LinkedList Values RAM)
        //#define USE_WE517                       // Add support for Orno WE517-Modbus energy monitor (+1k code)
        //#define USE_MODBUS_ENERGY               // Add support for generic modbus energy monitor using a user file in rule space (+5k)
    #endif

#endif

// -- Options for firmware tasmota-KC868-A16 ------
#ifdef FIRMWARE_KC868A16
    #warning **** Build: KICONY_KC868A16 ****
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "custom-kc868-a16"

    // **********************************************************************
    // Is it possible that the following causes problems with SetOption114?
    // Comment out and coomplile for testing - Sunday 13th April 2025
    // **********************************************************************
    /*
    #ifdef USE_HOME_ASSISTANT
       #undef USE_HOME_ASSISTANT
    #endif

    #ifdef USE_TASMOTA_DISCOVERY
       #undef USE_TASMOTA_DISCOVERY
    #endif
    */
    // **********************************************************************

    #ifndef USE_I2C
      #define USE_I2C                             // I2C using library wire (+10k code, 0k2 mem, 124 iram)
    #endif

    #define USE_PCF8574                           // [I2cDriver2] Enable PCF8574 I/O Expander (I2C addresses 0x20 - 0x26 and 0x39 - 0x3F) (+1k9 code)
      #define USE_PCF8574_MODE2
      #define USE_PCF8574_SENSOR                  // enable PCF8574 inputs and outputs in SENSOR message
      #define USE_PCF8574_DISPLAYINPUT            // enable PCF8574 inputs display in Web page
      #define USE_PCF8574_MQTTINPUT               // enable MQTT message & rule process on input change detection : stat/%topic%/PCF8574_INP = {"Time":"2021-03-07T16:19:23+01:00","PCF8574-1_INP":{"D1":1}}

    #define USE_ETHERNET                          // Add support for ethernet (Currently fixed for Olimex ESP32-PoE)
      #define ETH_TYPE          0                 // [EthType] 0 = ETH_PHY_LAN8720, 1 = ETH_PHY_TLK110, 2 = ETH_PHY_IP101
      #define ETH_ADDR          0                 // [EthAddress] 0 = PHY0 .. 31 = PHY31
      #define ETH_CLKMODE       3                 // [EthClockMode] 0 = ETH_CLOCK_GPIO0_IN, 1 = ETH_CLOCK_GPIO0_OUT, 2 = ETH_CLOCK_GPIO16_OUT, 3 = ETH_CLOCK_GPIO17_OUT

#endif

// -- Options for firmware tasmota-ds-temp-ir ------
#ifdef FIRMWARE_DSIRDEVICE
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: DSTEMPIR ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "custom-dsirdevice"

    // Put here your override for firmware tasmota-ds-temp-ir
    // -- No IR options ----------------------------
    #ifndef USE_IR_REMOTE
      #define USE_IR_REMOTE                         // Enable IR remote commands using library IRremoteESP8266
    #endif
    #ifndef USE_IR_REMOTE_FULL
      #define USE_IR_REMOTE_FULL                    // Support all IR protocols from IRremoteESP8266
    #endif
    // -- Add DS18X20 ---
    #ifndef USE_DS18x20
      #define USE_DS18x20                           // Add support for DS18x20 sensors with id sort, single scan and read retry (+2k6 code)
    //  #define W1_PARASITE_POWER                     // Optimize for parasite powered sensors
      #define DS18x20_USE_ID_AS_NAME                // Use last 3 bytes for naming of sensors
      #define DS18x20_USE_ID_ALIAS
        /* 
         * Use alias for fixed sensor name in scripts by autoexec. Command: DS18Alias XXXXXXXXXXXXXXXX,N where XXXXXXXXXXXXXXXX full serial and N number 1-255
         * Result in JSON:  "DS18Sens_2":{"Id":"000003287CD8","Temperature":26.3} (example with N=2)
         * Setting N to an alphanumeric value, the complete name is replaced with it
         * Result in JSON:  "Outside1":{"Id":"000003287CD8","Temperature":26.3} (example with N=Outside1)
        */
    #endif
#endif

#endif  // _USER_CONFIG_OVERRIDE_H_
