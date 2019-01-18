/*
 * Lamp Software
 * By dpkn
 * MIT Licensed
 */

// Including required libraries
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <FastLED.h>
#include <ArduinoJson.h>

// Defining possible states the lamp has
// for readability purposes

#define OFF 0
#define STATIC 1
#define FADE_ON 2
#define FADE_OFF 3
#define PULSATING 4
#define MOVING_BAR 5
#define DEMO_CALENDAR 6
#define SUNRISE 7
#define TIMER_START 8
#define TIMER_RUNNING 9

int LED_STRIP_STATE = OFF;
