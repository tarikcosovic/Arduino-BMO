#include <Adafruit_GFX.h>    // Core graphics library
//#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <MCUFRIEND_kbv.h>
#include <Vector.h>
#include <SD.h>
#include<BMO_gfx.h>
#include <TMRpcm.h>  

// TFT Breakout  -- Arduino Mega2560
// GND              -- GND
// 3V3               -- 3.3V
// CS                 -- A3
// RS                 -- A2
// WR                -- A1
// RD                 -- A0
// RST                -- RESET
// LED                -- GND
// DB0                -- 8
// DB1                -- 9
// DB2                -- 10
// DB3                -- 11
// DB4                -- 4
// DB5                -- 13
// DB6                -- 6
// DB7                -- 7

//Color Definitions
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define BROWN 0xEF17

MCUFRIEND_kbv tft;
TMRpcm tmrpcm; 


//Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
// If using the shield, all control and data lines are fixed, and
// a simpler declaration can optionally be used:
// Adafruit_TFTLCD tft;

//SD Card Files
File file;

  
//GLOBAL CONSTANTS DEFINITIONS
const int screenWidth = tft.height();
const int screenHeight = tft.width();

//SD Card-Adapter Pin
const int MicroSDPin = 30;

//BuzzerPin Sound Effects
const int Buzzer_SFX = 28;
const int Speaker_SFX = 46;

//ButtonPins and States
const int YAxis = A8;
int YAxisValue = 0;

const int XAxis = A9;
int XAxisValue = 0;

const int RedButton = 2;
int RedButtonState = 0;

const int BlueButton = 3;
int BlueButtonState = 0;

const int WhiteButton = 44;
int WhiteButtonState = 0;


//Input Constants
String LEFT = "left";
String RIGHT = "right";
String UP = "up";
String DOWN = "down";
String REDBUTTON = "redbutton";
String BLUEBUTTON = "bluebutton";
String WHITEBUTTON = "whitebutton";
String NONE = "none";

//FileName Constants
String SNAKE = "SNAKE";

//Global settings
bool isRunning = false;
int score = 0;

//Game constants
char* CRATE = "crate";

//-----------------------------------------
//GLOBAL FUNCTION FOR CALCULATING DELTA TIME
unsigned int oldTime = 0;
unsigned int CalculateDeltaTime(){
  int currentTime = millis();
  int deltaTime = currentTime - oldTime;
  oldTime = currentTime;
  return deltaTime;
}
