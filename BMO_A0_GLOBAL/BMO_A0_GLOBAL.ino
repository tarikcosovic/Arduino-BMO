#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <Vector.h>
#include <SD.h>
#include <BMO_gfx.h>
#include <TMRpcm.h>
#include <EEPROM.h>

MCUFRIEND_kbv tft;
TMRpcm tmrpcm;
File file;

//Color Definitions
#define BLACK   0x0000
#define LIGHTBLACK 0x2104
#define LIGHTBLACK2 0x2945
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define BROWN 0xEF17
#define ORANGE 0xFF27
#define DARKPURPLE 0x4167
#define DARKBROWN 0x7A29

//GLOBAL CONSTANTS DEFINITIONS
const int screenWidth = tft.height();
const int screenHeight = tft.width();

//SD Card-Adapter Pin
const int MicroSDPin = 30;

//Speaker Sound Effects
const int Speaker_SFX = 46;
//BuzzerPin SFX
const int Buzzer_SFX = 22;

//ButtonPins and States
const int YAxis = A8;
int YAxisValue = 0;

const int XAxis = A9;
int XAxisValue = 0;

const int RedButton = 42;
int RedButtonState = 0;

const int BlueButton = 44;
int BlueButtonState = 0;

const int WhiteButton = 40;
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
String INVADERS = "SPACE";

//Global settings
bool isRunning = false;
int score = 0;
bool isPaused = false;
bool sfxEnabled = true;

//EEPROM constants
const int musicEEPROM = 0;
const int sfxEEPROM = 0;

//-----------------------------------------
//GLOBAL FUNCTION FOR CALCULATING DELTA TIME
unsigned int oldTime = 0;
unsigned int CalculateDeltaTime() {
  int currentTime = millis();
  int deltaTime = currentTime - oldTime;
  oldTime = currentTime;
  return deltaTime;
}
