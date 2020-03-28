void OptionsMenu()
{
  tft.fillScreen(BLACK);

  int musicValue = EEPROM.read(musicEEPROM);
  if (musicValue == 255)
    musicValue = 2;

  DrawCredits();
  DrawMusicVolume(musicValue);


  isRunning = true;
  while (isRunning)
  {
    String tempVal = CheckAnalogInputs();
    String tempVal2 = CheckButtonInputs();

    if (tempVal != NONE)CheckOptionAnalog(tempVal, musicValue);
    if (tempVal2 == REDBUTTON)BMOMenu();

  }
}

void DrawMusicVolume(int temp)
{
  tft.fillRect(130, 70, 140, 20, BLACK);

  tft.drawRect(129, 69, 142, 22, WHITE);
  tft.fillRect(130, 70, (temp * 20), 20, YELLOW);
}

void CheckOptionAnalog(String temp, int &musicValue)
{
  if (temp == RIGHT && musicValue < 7)
  {
    musicValue++;
    EEPROM.write(musicEEPROM, musicValue);
    tmrpcm.setVolume(musicValue);
  }
  else if (temp == LEFT && musicValue > 0)
  {
    musicValue--;
    EEPROM.write(musicEEPROM, musicValue);
    tmrpcm.setVolume(musicValue);
  }

  DrawMusicVolume(musicValue);
  delay(500);
}

void DrawCredits()
{
  for (int i = 0; i < 80; i++)
    tft.drawPixel(random(0, screenWidth), random(0, screenHeight), CYAN);

  tft.setCursor(125, 35);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("Music Volume");

  tft.setCursor(150, 130);
  tft.print("Credits");
  tft.drawLine(150, 150, 234, 150, WHITE);

  tft.setTextSize(1);
  tft.setCursor(125, 170);
  tft.print("Developer: Tarik Cosovic");
  tft.setCursor(115, 190);
  tft.print("Mentor: doc.dr.Elmir Babovic");

}
