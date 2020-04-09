void StartTopGun()
{
  DrawInitialHud();

  isRunning = true;
  while (isRunning)
  {

  }
}

void DrawInitialHud()
{
  //Colors: HUD Red - 0xEC0C, HUD Darker Red - 0xEAA5, HUD BG Green - 0x2B20, HUD FG Green - 0x86AC, Sky Blue - 0xB73F, Ocean Blue - 0x037E
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 400, 140, 0xB73F);
  tft.fillRect(0, 100, 400, 40, 0x037E);
  tft.drawLine(0, 140, 400, 140, 0xEC0C);

  //DRAWING UPPER RIGHT-LEFT RED BORDERS
  int tempVal = 140;
  for (int i = 0; i < 7; i++)
  {
    if (i < 3) tft.drawLine(screenWidth / 2 - 70, 140, 0, tempVal, BLACK);
    else tft.drawLine(screenWidth / 2 - 70, 140, 0, tempVal, 0xEC0C);
    tempVal += 2;
  }
  tempVal = 140;
  for (int i = 0; i < 7; i++)
  {
    if (i < 3)tft.drawLine(screenWidth / 2 + 70, 140, 400, tempVal, BLACK);
    else tft.drawLine(screenWidth / 2 + 70, 140, 400, tempVal, 0xEC0C);
    tempVal += 2;
  }
  //---------------------------------------

  //DRAWING CENTRAL HUB
  tft.fillRect(screenWidth / 2 - 80, 140, 160, 15, 0xEC0C);//Upper Red HUD
  tft.fillRect(screenWidth / 2 - 70, 160, 140, 70, 0x2B20);//Bottom Green HUD
  tft.drawLine(screenWidth / 2 - 80, 155, screenWidth / 2 - 75, 210, 0xEC0C);//Drawing Red Line Left
  tft.drawLine(screenWidth / 2 + 80, 155, screenWidth / 2 + 75, 210, 0xEC0C);//Drawing Red Line Right

  tempVal = 5;
  for (int i = 0; i < 4; i++)
  {
    //tft.drawLine(screenWidth / 2 - 60, 170 + tempVal, screenWidth / 2 + 55, 170 + tempVal, 0x86AC); //Horizontal Lines
    //tft.drawLine(screenWidth / 2 - 60 + tempVal, 170, screenWidth / 2 - 60 + tempVal, 230, 0x86AC); //Vertical Lines
    //tft.drawLine(screenWidth / 2 + tempVal, 170, screenWidth / 2 + tempVal, 230, 0x86AC); //Vertical Lines
    tempVal += 15;
  }
  tempVal = 0;
  for (int i = 0; i < 8; i++)
  {
    tft.fillRect(screenWidth / 2 - 67 + tempVal, 234, 14, 3, 0xEC0C);
    tempVal += 17;
  }
  //---------------------

  //DRAWING LEFT PANEL
  tft.fillRect(35, 165, 50, 15, 0x2B20);
  tft.fillRect(35, 183, 50, 3, 0x86AC);
  tft.setTextColor(0x86AC);
  tft.setTextSize(1);
  tft.setCursor(45, 170);
  tft.println("023272");

  tft.fillRect(35, 195, 50, 15, 0x2B20);
  tft.fillRect(35, 213, 50, 3, 0x86AC);
  tft.setCursor(45, 200);
  tft.println("000573");

  tft.setTextColor(0xEC0C);
  tft.setCursor(90, 200);
  tft.println("SPEED");
  tft.setCursor(90, 170);
  tft.println("ALT.");

  tempVal = 0;
  for (int i = 0; i < 8; i++)
  {
    tft.fillRect(10, 220 - tempVal, 10, 5, 0xEC0C);
    if (i == 7)
    {
      tft.fillRect(10, 220 - tempVal, 10, 5, BLACK);
      tft.drawRect(10, 220 - tempVal, 10, 5, 0xEC0C);
    }
    tempVal += 7;
  }
  tft.setCursor(22, 218);
  tft.print("E.");
  //-------------------

  //DRAWING RIGHT PANEL
  tft.fillRect(325, 165, 40, 13, 0x2B20);
  tft.setTextColor(0x86AC);
  tft.setTextSize(1);
  tft.setCursor(335, 168);
  tft.println("65");

  tft.fillRect(325, 180, 40, 13, 0x2B20);
  tft.setCursor(335, 183);
  tft.println("573");

  tft.setTextColor(0xEC0C);
  tft.setCursor(285, 168);
  tft.println("SCORE");
  tft.setCursor(285, 183);
  tft.println("HEALTH");

  tft.drawCircle(305, 215, 12, 0xEC0C);
  tft.fillRect(300, 214, 2, 4, WHITE);
  tft.fillRect(303, 214, 2, 4, WHITE);
  tft.fillRect(306, 214, 2, 4, WHITE);
  tft.fillRect(309, 214, 2, 4, WHITE);
  tft.drawLine(293, 215, 317, 215, 0xEC0C);
  tft.drawLine(305, 203, 305, 227, 0xEC0C);



  tft.drawCircle(345, 215, 12, 0xEC0C);
  //-------------------

}
