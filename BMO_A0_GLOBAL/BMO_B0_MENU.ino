void MainMenu()
{
  StarWarsUI();
}

//---------------------------------
//GameTitleUI - Game poster in menu
//x1,y1 - position of title
//x2,y2 - position of subtitle
//title, subtitle, color
void GameTitleUI(int x1, int y1, int x2, int  y2, String title, String subtitle, uint16_t color)
{
  tft.setRotation(2);
  tft.fillScreen(BLACK);
  tft.setRotation(1);
  tft.fillScreen(BLACK);

  tft.setTextSize(2);
  tft.setCursor(x1, y1);
  tft.setTextColor(color);
  tft.println(title);
  tft.setCursor(x2, y2);
  tft.print(subtitle);
}

//-------------------------------------
//PressAnyButtonUI - blinking indicator
void PressAnyButtonUI(uint16_t color)
{
  tft.setTextSize(1);
  while (true)
  {
    TakeInput(); 
    
    tft.setTextColor(color);
    tft.setCursor(screenWidth / 2 - 67, screenHeight - 30);
    tft.print("PRESS ANY BUTTON TO START");

    tft.drawTriangle(screenWidth - 86, screenHeight - 27, screenWidth - 96, screenHeight - 22, screenWidth - 96, screenHeight - 32, color);
    tft.drawTriangle(screenWidth / 2 - 100, screenHeight - 27, screenWidth / 2 - 90, screenHeight - 22, screenWidth / 2 - 90, screenHeight - 32, color);

    delay(500);

    tft.setTextColor(BLACK);
    tft.setCursor(screenWidth / 2 - 67, screenHeight - 30);
    tft.print("PRESS ANY BUTTON TO START");

    delay(400);
  }
}

//------------------------------------------------------------------------------------
//TakeInput - Chekcs for input regarding selecting the game or switching between games
void TakeInput()
{
  
}

//------------------------------------
//GAME TITLE: STAR WARS
//GAME SUBTITLE: THE RETURN OF THE JEDI
void StarWarsUI(int swipeDirection)
{
  GameTitleUI(screenWidth / 2 - 50, screenHeight / 2 - 40, screenWidth / 2 - 125, screenHeight / 2 - 20, "Star Wars", "The Return of The Jedi", YELLOW);

  for (int i = 0; i < 80; i++) {
    tft.drawPixel(random(0, screenWidth), random(0, screenHeight), WHITE);
    delay(30);
  }
  for (int i = 0; i < 10; i++)
    tft.drawCircle(random(0, screenWidth), random(0, screenHeight), random(0, 2), WHITE);

  PressAnyButtonUI(YELLOW);
}

//------------------------------------
//GAME TITLE: THE MATRIX
//GAME SUBTITLE: DEEP DIVE INTO REALITY
void TheMatrixUI(int swipeDirection)
{
  GameTitleUI(screenWidth / 2 - 50, screenHeight / 2 - 40, screenWidth / 2 - 125, screenHeight / 2 - 20, "The Matrix", "Deep dive into reality", GREEN);

  tft.setTextSize(0);
  tft.setTextColor(0x0500);
  
  for (int i = 0; i < 30; i++) {
    tft.setCursor(random(0, screenWidth), random(0, screenHeight));
    tft.print(random(0, 2));
    tft.drawPixel(random(0, screenWidth), random(0, screenHeight), 0x500);
    tft.drawPixel(random(0, screenWidth), random(0, screenHeight), 0x500);
    delay(30);
  }

  int lineHeight = 0;
  while (lineHeight < 160)
  {
    lineHeight += random(9, 15);

    tft.setCursor(40, lineHeight);
    tft.print(random(0, 2));

    if (lineHeight > 50)
    {
      tft.setCursor(300, lineHeight - 50);
      tft.print(random(0, 2));
      delay(120);
    }
  }

  PressAnyButtonUI(GREEN);
}
