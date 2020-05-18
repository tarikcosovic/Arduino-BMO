uint16_t currentColor[2] = {CYAN, MAGENTA};
int currentPositionHighscore[2] = {115, 165};
int counter = 1;
String tempHighscores[5];

void HighScoreMenu()
{
  isRunning = true;

  unsigned int timer = 0;
  unsigned int timer2 = 0;
  bool changeColor = false;
  BodyPart stars[80];

  for (int i = 0; i < 80; i++)
  {
    if (i < 40)stars[i].positionX = random(0, 110);
    else  stars[i].positionX = random(290, 400);
    stars[i].positionY = random(0, screenHeight);
  }

  String fileNames[2] = {INVADERS, SNAKE};
  String gameNames[2] = {"Space Invaders", "Snake"};

  LoadHighscore(SNAKE, "Snake");

  int lastFrameTime = 0;
  while (isRunning)
  {
    lastFrameTime = CalculateDeltaTime();

    timer += lastFrameTime;

    String tempVal = CheckAnalogInputs();
    if (tempVal != NONE)HighscoreAnalogInput(tempVal, fileNames, gameNames, counter);

    String tempVal2 = CheckButtonInputs();
    if (tempVal2 == REDBUTTON)
    {
      EscapeSFX_v1();
      isRunning = false;
      currentEvent = &BMOMenu;
    }

    if (timer > 800)
    {
      if (changeColor)DrawTrianglesHighscore(BLACK);
      else DrawTrianglesHighscore(currentColor[counter]);
      changeColor = !changeColor;
      timer = 0;
    }
    if (timer % 40 == 0)
      MoveBackgroundHighscore(stars, gameNames[counter]);
  }
}

void HighscoreAnalogInput(String temp, String files[2], String names[2], int &counter)
{
  ButtonSelectSFX();
  if (temp == LEFT)counter--;
  else if (temp == RIGHT)counter++;

  if (counter < 0)
    counter = 1;
  else if (counter > 1)
    counter = 0;

  LoadHighscore(files[counter], names[counter]);
}

void DrawTrianglesHighscore(uint16_t color)
{
  tft.drawLine(screenWidth / 2 - 140, screenHeight / 2, screenWidth / 2 - 120, screenHeight / 2 - 20, color);
  tft.drawLine(screenWidth / 2 - 140, screenHeight / 2, screenWidth / 2 - 120, screenHeight / 2 + 20, color);

  tft.drawLine(screenWidth / 2 + 140, screenHeight / 2, screenWidth / 2 + 120, screenHeight / 2 - 20, color);
  tft.drawLine(screenWidth / 2 + 140, screenHeight / 2, screenWidth / 2 + 120, screenHeight / 2 + 20, color);
}

void LoadHighscore(String fileName, String gameName)
{
  tft.fillScreen(BLACK);
  String highscores = GetHighscores(fileName);
  int YPosition = 70;

  //Drawing game title and borders
  tft.drawRect(120, 55, 160, 160, currentColor[counter]);
  tft.setTextSize(2);
  tft.setCursor(currentPositionHighscore[counter], 20);
  tft.setTextColor(currentColor[counter]);
  tft.println(gameName);

  for (int i = 0; i < 5; i++)
  {
    tft.setCursor(130, YPosition);
    if (i == 0)YPosition += 40;
    else YPosition += 25;
    if (i == 0)tft.setTextColor(YELLOW);
    else tft.setTextColor(currentColor[counter]);

    int endRange = 0;
    for (int j = 0; j < highscores.length(); j++)
      if (highscores[j] == ':')
      {
        endRange = j;
        break;
      }

    String currentScore = highscores.substring(0, endRange - 1);
    tft.println((String)(i + 1) + "." + currentScore.substring(0, 5) + "   " + currentScore.substring(5, currentScore.length()));
    tempHighscores[i] = (String)(i + 1) + "." + currentScore.substring(0, 5) + "   " + currentScore.substring(5, currentScore.length());

    highscores = highscores.substring(endRange + 1, highscores.length());
  }
}

void MoveBackgroundHighscore(BodyPart stars[80], String gameName)
{
  for (int i = 0; i < 80; i++)
  {
    tft.drawPixel(stars[i].positionX, stars[i].positionY, BLACK);
    stars[i].positionY--;
    tft.drawPixel(stars[i].positionX, stars[i].positionY, currentColor[counter]);

    if (stars[i].positionY < 0)
      stars[i].positionY = 240;
  }
}
