void MainMenu()
{
  currentEvent = gameSelectUI[currentGameUI];
  currentEventArgs.swipeDirection = "none";
}

//---------------------------------
//GameTitleUI - Game poster in menu
//x1,y1 - position of title
//x2,y2 - position of subtitle
//title, subtitle, color
void GameTitleUI(int x1, int y1, int x2, int  y2, String title, String subtitle, uint16_t color, String swipeDirection)
{
  if (swipeDirection == RIGHT)
  {
    tft.setRotation(2);
    tft.fillScreen(BLACK);
  }
  else if (swipeDirection == LEFT)
  {
    tft.setRotation(0);
    tft.fillScreen(BLACK);
  }

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
  tft.drawTriangle(screenWidth - 86, screenHeight - 27, screenWidth - 96, screenHeight - 22, screenWidth - 96, screenHeight - 32, color);
  tft.drawTriangle(screenWidth / 2 - 100, screenHeight - 27, screenWidth / 2 - 90, screenHeight - 22, screenWidth / 2 - 90, screenHeight - 32, color);

  tft.setTextSize(1);

  isRunning = true;

  unsigned int counter = 0;
  while (isRunning)
  {
    MainMenuInput();

    counter += CalculateDeltaTime();

    if (counter < 500)
    {
      tft.setTextColor(color);
      tft.setCursor(screenWidth / 2 - 67, screenHeight - 30);
      tft.print("PRESS ANY BUTTON TO START");

    }
    else
    {
      tft.setTextColor(BLACK);
      tft.setCursor(screenWidth / 2 - 67, screenHeight - 30);
      tft.print("PRESS ANY BUTTON TO START");

      if (counter > 900)
        counter = 0;
    }

  }
}

void MainMenuInput()
{
  String buttonPressed = CheckAnalogInputs();

  String gameSelected = CheckButtonInputs();
  if (gameSelected == REDBUTTON)
  {
    EscapeSFX_v1();
    isRunning = false;
    currentEvent = &BMOMenu;
  }
  else if (gameSelected != NONE)
  {
    ButtonPressSFX();
    isRunning = false;
    currentEvent = gameSelectStart[currentGameUI];
  }

  if (buttonPressed != NONE)
  {
    ButtonSelectSFX();
    isRunning = false;
    CalculateCurrentGameUI(buttonPressed);
  }
}

//------------------------------------
//GAME TITLE: STAR WARS
//GAME SUBTITLE: THE RETURN OF THE JEDI
void StarWarsUI()
{
  String swipeDirection = currentEventArgs.swipeDirection;
  GameTitleUI(screenWidth / 2 - 80, screenHeight / 2 - 50, screenWidth / 2 - 150, screenHeight / 2 - 20, "Space Invaders", "The Arcade Legend Returns", YELLOW, swipeDirection);

  for (int i = 0; i < 80; i++) {
    tft.drawPixel(random(0, screenWidth), random(0, screenHeight), CYAN);
    delay(20);
  }
  for (int i = 0; i < 10; i++)
    tft.drawCircle(random(0, screenWidth), random(0, screenHeight), random(0, 2), YELLOW);

  PressAnyButtonUI(YELLOW);
}

//------------------------------------
//GAME TITLE: THE MATRIX
//GAME SUBTITLE: DEEP DIVE INTO REALITY
void TheMatrixUI()
{
  String swipeDirection = currentEventArgs.swipeDirection;
  GameTitleUI(screenWidth / 2 - 70, screenHeight / 2 - 50, screenWidth / 2 - 125, screenHeight / 2 - 20, "Space Worms", "Deluxe Puzzle Edition", RED, swipeDirection);

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

//------------------------------------
//GAME TITLE: SNAKE
//GAME SUBTITLE: 80s' retro classic
void SnakeUI()
{
  String swipeDirection = currentEventArgs.swipeDirection;
  GameTitleUI(screenWidth / 2 -  18, screenHeight / 2 - 65 , screenWidth / 2 - 68, screenHeight / 2 - 40, "Snake", "Retro classic", MAGENTA, swipeDirection);

  for (int i = 0; i < 40; i++) {
    tft.drawPixel(random(0, screenWidth), random(0, screenHeight), MAGENTA);
    delay(20);
  }
  for (int i = 0; i < 10; i++)
  {
    tft.drawCircle(random(0, screenWidth), random(0, screenHeight), random(0, 2), MAGENTA);
    delay(10);
  }

  tft.drawRect(130, 110, 160, 7, MAGENTA);

  PressAnyButtonUI(MAGENTA);
}
