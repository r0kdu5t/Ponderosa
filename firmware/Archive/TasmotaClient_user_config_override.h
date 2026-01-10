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

#ifdef CODE_IMAGE_STR
  #undef CODE_IMAGE_STR
#endif
#define CODE_IMAGE_STR "Custom-TasmotaClient"

// NO HA or Tasmota discovery
#ifdef USE_HOME_ASSISTANT
   #undef USE_HOME_ASSISTANT
#endif
#ifdef USE_TASMOTA_DISCOVERY
   #undef USE_TASMOTA_DISCOVERY
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



#endif  // _USER_CONFIG_OVERRIDE_H_