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

// force the compiler to show a warning to confirm that this file is included
#warning **** user_config_override.h: Using Settings from this File ****

/*********************************************************************************************\
 * 
 * Provide an image with BLE support and I2S
 *
\*********************************************************************************************/

#ifdef CODE_IMAGE_STR
  #undef CODE_IMAGE_STR
#endif
#define CODE_IMAGE_STR "Custom-BLE-I2S"

#undef MODULE
#define MODULE                 WEMOS             // [Module] Select default module from tasmota_template.h
#undef FALLBACK_MODULE
#define FALLBACK_MODULE        WEMOS             // [Module2] Select default module on fast reboot where USER_MODULE is user template

#undef USE_INFLUXDB                             // Enable influxdb support (+5k code)

#ifdef USE_HOME_ASSISTANT
   #undef USE_HOME_ASSISTANT
#endif

#ifdef USE_TASMOTA_DISCOVERY
   #undef USE_TASMOTA_DISCOVERY
#endif

#define USE_SDCARD

#ifndef USE_BERRY_ULP                              // potential performance gains with ULP
  #define USE_ADC                                  // so do not use common ADC funtions in that case
#endif
//#undef USE_BERRY                                 // Disable Berry scripting language

#undef USE_ETHERNET                             // DON'T Add support for ethernet (+20k code)

// Enable BLE  stuff
#ifndef USE_MI_EXT_GUI
  #define USE_BLE_ESP32                            // Enable full BLE driver
  #define USE_EQ3_ESP32
#endif // USE_MI_EXT_GUI
#define USE_MI_ESP32                             // (ESP32 only) Add support for ESP32 as a BLE-bridge (+9k2 mem, +292k flash)


// Enable I2S stuff
#ifndef USE_I2S_AUDIO
#define USE_I2S_AUDIO                             // Add support for I2S audio output
  #define USE_I2S_NO_DAC                         // Add support for transistor-based output without DAC
// #define USE_I2S_LSB                            // Add support for LSBJ chips, e.g. TM8211/PT8211
// #define USE_I2S_WEBRADIO                       // Add support for MP3 web radio streaming (only on ESP32 with PSRAM)
  #define USE_I2S_SAY_TIME                       // Add support for english speaking clock
  #define USE_I2S_RTTTL                          // Add support for Rtttl playback
#endif


#endif  // _USER_CONFIG_OVERRIDE_H_
