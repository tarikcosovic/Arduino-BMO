uint16_t g_identifier;

void setup(void) {

  Serial.begin(9600); //For Debugging
  randomSeed(analogRead(5));

  InitiateSDCard();

  tmrpcm.speakerPin = Speaker_SFX;
  InitiateMusisPrefs();

  //BUTTON PINS
  pinMode(RedButton, INPUT);
  pinMode(BlueButton, INPUT);
  pinMode(WhiteButton, INPUT);

  g_identifier = tft.readID(); //0x9327
  tft.begin(g_identifier);
  tft.setRotation(1); //Sets the screen rotation to horizontal

  //Serial.println(freeMemory());

  currentEvent = &BMOMenu;
}

void InitiateSDCard()
{
  pinMode(MicroSDPin, OUTPUT);

  if (!SD.begin(MicroSDPin)) { // Initialize SD card
    Serial.println("Could not initialize SD card.");
  }
}

void InitiateMusisPrefs()
{
  //Soundtrack
  int musicValue = EEPROM.read(musicEEPROM);
  if (musicValue == 255)
    musicValue = 2;

  tmrpcm.setVolume(musicValue);
  tmrpcm.loop(1);

  //Sound Effects
  int sfxValue = EEPROM.read(sfxEEPROM);
  if (sfxEEPROM == 255)
    sfxValue = 1;
  sfxEnabled = sfxValue;
}
