int optionsCounter = 0;
void OptionsMenu()
{
  tft.fillScreen(BLACK);

  int musicValue = EEPROM.read(musicEEPROM);
  if (musicValue == 255)
    musicValue = 2;

  DrawCredits();
  DrawMusicVolume(musicValue, YELLOW);
  DrawSFXToggle();


  isRunning = true;
  while (isRunning)
  {
    String tempVal = CheckAnalogInputs();
    String tempVal2 = CheckButtonInputs();

    if (tempVal == UP || tempVal == DOWN)//CheckOptionAnalog(tempVal, musicValue);
      ToggleOption(musicValue);

    if(tempVal == LEFT || tempVal == RIGHT)
    {
      if(optionsCounter == 0)
        CheckOptionAnalog(tempVal, musicValue);
      else 
        ToggleSFX();
    }

    if (tempVal2 == REDBUTTON)
    {
      EscapeSFX_v1();
      isRunning = false;
      currentEvent = &BMOMenu;
    }
  }
}

void ToggleOption(int musicVal)
{
  optionsCounter = 1 - optionsCounter;

  if (optionsCounter == 0)
  {
    DrawMusicVolume(musicVal, YELLOW);

    tft.fillRect(205, 90, 40, 30, BLACK);
    tft.setCursor(205, 100);

    tft.setTextColor(WHITE);
    if (sfxEnabled)
      tft.print("ON");
    else tft.print("OFF");
  }
  else
  {
    DrawMusicVolume(musicVal, WHITE);

    tft.fillRect(205, 90, 40, 30, BLACK);
    tft.setCursor(205, 100);

    tft.setTextColor(YELLOW);
    if (sfxEnabled)
      tft.print("ON");
    else tft.print("OFF");
  }

  ButtonSelectSFX();
  delay(1000);
}

void DrawMusicVolume(int temp, uint16_t color)
{
  tft.fillRect(130, 55, 140, 20, BLACK);

  tft.drawRect(129, 54, 142, 22, WHITE);
  tft.fillRect(130, 55, ( (1 + temp) * 20), 20, color);
}

void DrawSFXToggle()
{
  tft.setTextSize(2);
  tft.setCursor(155, 100);
  tft.print("SFX:");

  tft.setCursor(205, 100);

  if (sfxEnabled)
    tft.print("ON");
  else tft.print("OFF");
}

void ToggleSFX()
{
  ButtonSelectSFX();

  sfxEnabled = !sfxEnabled;
  EEPROM.write(sfxEEPROM, sfxEnabled);

  tft.fillRect(205, 90, 40, 30, BLACK);
  tft.setCursor(205, 100);

  if (sfxEnabled)
    tft.print("ON");
  else tft.print("OFF");

  delay(500);
}

void CheckOptionAnalog(String temp, int &musicValue)
{
  ButtonSelectSFX();

  if (temp == RIGHT && musicValue < 6)
  {
    musicValue++;
    EEPROM.write(musicEEPROM, musicValue);
    tmrpcm.setVolume(musicValue);
  }
  else if (temp == LEFT && musicValue >= 0)
  {
    musicValue--;
    EEPROM.write(musicEEPROM, musicValue);
    tmrpcm.setVolume(musicValue);
  }

  DrawMusicVolume(musicValue, YELLOW);
  delay(500);
}

void DrawCredits()
{
  for (int i = 0; i < 80; i++)
    tft.drawPixel(random(0, screenWidth), random(0, screenHeight), CYAN);

  tft.setCursor(125, 15);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("Music Volume");

  tft.setCursor(150, 145);
  tft.print("Credits");
  tft.drawLine(150, 165, 234, 165, WHITE);

  tft.setTextSize(1);
  tft.setCursor(125, 185);
  tft.print("Developer: Tarik Cosovic");
  tft.setCursor(115, 205);
  tft.print("Mentor: doc.dr.Elmir Babovic");

}
