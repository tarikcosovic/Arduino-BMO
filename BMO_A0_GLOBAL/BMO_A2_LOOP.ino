void StartupConsole()
{
  if (MusicEnabled())
    tmrpcm.play("INTRO.wav");

  tft.fillScreen(BLACK);

  tft.drawRect(130, 100, 150, 30, WHITE);

  int indicatorWidth = 0;
  while (indicatorWidth < 147)
  {
    tft.fillRect(132, 102, indicatorWidth, 26, 0xCFBA);
    delay(20);
    indicatorWidth++;
  }
  for (int i = 0; i < 7; i++)
  {
    if (i % 2 == 0)
      DrawDot(BLACK);
    else DrawDot(0xCFBA);
    delay(500);
  }

  currentEvent = &BMOMenu;
}

void DrawDot(uint16_t color)
{
  tft.setCursor(180, 75);
  tft.setTextColor(color);
  tft.print("Complete");
}

void DrawBMO()
{
  tft.fillScreen(0xCFBA);
  tft.fillCircle(140, 60, 8, BLACK);
  tft.fillCircle(260, 60, 8, BLACK);
  tft.drawCircle(200, 100, 30, BLACK);
  tft.fillRect(170, 70, 60, 30, 0xCFBA);
  delay(2000);
}

void loop(void)
{
  //Serial.print("Current Memory:");
  //Serial.println(freeMemory());

  if(currentEvent != NULL)
    currentEvent();
}
