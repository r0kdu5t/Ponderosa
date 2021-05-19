#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is included
#warning **** user_config_override.h: Using Settings from this File ****

// ***********************************************
// ** Global settings for all binaries ***********

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "YourSSID"             // [Ssid1] Wifi SSID
#undef  STA_PASS1
#define STA_PASS1         "YourWifiPassword"     // [Password1] Wifi password

// You can also define your IP settings or your MQTT settings

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
    #define USE_I2C
    #define USE_SENSOR_FOO  // Beware this doesn't exist !!!

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

#endif  // _USER_CONFIG_OVERRIDE_H_
