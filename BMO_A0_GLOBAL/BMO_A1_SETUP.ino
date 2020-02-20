uint16_t g_identifier;

void setup(void) {

  Serial. begin(9600); //For Debugging
  randomSeed(analogRead(5));

  InitiateSDCard();
  
  //BUTTON PINS
  pinMode(LeftButton, INPUT);     //LeftButton
  pinMode(RightButton, INPUT);    //RightButton
  pinMode(UpButton, INPUT);       //UpButton
  pinMode(DownButton, INPUT);     //DownButton
  
  g_identifier = tft.readID(); //0x9327
  
  tft.begin(g_identifier);
  tft.setRotation(1); //Sets the screen rotation to horizontal

  //MainMenu();
  StartSnake();
}

void InitiateSDCard()
{
  pinMode(MicroSDPin, OUTPUT);

  if (!SD.begin(MicroSDPin)) { // Initialize SD card
    Serial.println("Could not initialize SD card."); // if return value is false, something went wrong.
  }
}
