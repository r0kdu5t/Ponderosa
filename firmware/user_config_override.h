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

/*********************************************************************************************\
 * 
 * An attempt to set up a build system to provide the necessary different versions that
 * I've been playing about with but using better techniques than multiple config files.
 *
\*********************************************************************************************/

// ***********************************************
// ** Global settings for all binaries ***********

#ifdef CODE_IMAGE_STR
  #undef CODE_IMAGE_STR
#endif
#define CODE_IMAGE_STR "Custom"

#ifdef MODULE
  #undef MODULE
#endif
#define MODULE WEMOS

#ifdef USE_HOME_ASSISTANT
   #undef USE_HOME_ASSISTANT
#endif

#ifdef USE_TASMOTA_DISCOVERY
   #undef USE_TASMOTA_DISCOVERY
#endif

#undef USE_ARDUINO_OTA
#undef USE_DOMOTICZ                              // Disable Domoticz
#undef USE_TELEGRAM
#undef USE_MQTT_TLS                              // Disable TLS support won't work as the MQTTHost is not set
#undef USE_KNX 
#undef USE_JAVASCRIPT_ES6 
#undef USE_WEBSEND_RESPONSE                      // Disable command WebSend response message (+1k code)
#undef USE_EMULATION                             // Disable Wemo or Hue emulation
#undef USE_EMULATION_HUE                         // Disable Hue Bridge emulation for Alexa (+14k code, +2k mem common)
#undef USE_EMULATION_WEMO                        // Disable Belkin WeMo emulation for Alexa (+6k code, +2k mem common)

// ***********************************************
// ** Firmware specific settings *****************

/*
    List the various different variants I've configured prevously.
    *   TasmotaClient   - TAC
    *   Wiegand         - WIE
    *   Radar LD2410    - RAD
    *   Tasmota32 I2S   - AUD
    *
 */


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
    #define USE_I2C
    #define USE_SENSOR_FOO  // Beware this doesn't exist !!!

#endif
// -- Options for firmware tasmota-wie and tasmota32-wie ------
#ifdef FIRMWARE_WIE
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: WIE - Wiegand ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #ifdef CODE_IMAGE_STR
        #undef CODE_IMAGE_STR
    #endif
    #define CODE_IMAGE_STR "Custom-Wiegand"

    // Put here your override for firmware tasmota-foo
    #define USE_WIEGAND                              // Add support for 24/26/32/34 bit RFID Wiegand interface (D0/D1) (+1k7 code)
    //#define USE_I2C

#endif

// -- Options for firmware tasmota-bar ------
#ifdef FIRMWARE_BAR
    #warning **** Build: BAR ****
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "bar"

    // Put here your override for firmware tasmota-bar

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

// !!! Remember that your changes GOES AT THE BOTTOM OF THIS FILE right before the last #endif !!!

#endif  // _USER_CONFIG_OVERRIDE_H_
