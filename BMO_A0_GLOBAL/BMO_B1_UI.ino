//Calling the SaveHighscoreMethod   bool test = SaveHighscoreToSDCard("SNAKE", "kenny", 7);

void GameOver(String fileName, int score)
{
  String playerName;
  if (CheckForHighscore(fileName, score))
  {
    //If we have a highscore, the player has to enter his name
    playerName = EnterUsername();
    //Saving indicator
    tft.fillScreen(BLACK);
    //STARS BG
    for (int i = 0; i < 80; i++) {
      tft.drawPixel(random(0, screenWidth), random(0, screenHeight), WHITE);
      delay(20);
    }
    for (int i = 0; i < 10; i++)
      tft.drawCircle(random(0, screenWidth), random(0, screenHeight), random(0, 2), WHITE);
    //------------
    tft.setCursor(150, 70);
    tft.setTextColor(WHITE);
    tft.print("Saving..");

    tft.drawRect(130, 100, 150, 30, YELLOW);

    int indicatorWidth = 0;
    while (indicatorWidth < 147)
    {
      tft.fillRect(132, 102, indicatorWidth, 26, WHITE);
      delay(20);
      indicatorWidth++;
    }

    if (SaveHighscoreToSDCard(fileName, playerName, score))
    {
      tft.setCursor(100, 160);
      tft.setTextColor(GREEN);
      tft.print("successfully saved!");
    }
    else
    {
      tft.setCursor(120, 160);
      tft.setTextColor(RED);
      tft.print("Error saving!");
    }
  }
  GameOverUI(fileName, score);
}

String EnterUsername()
{
  tft.fillScreen(BLACK);

  for (int i = 0; i < 80; i++) {
    tft.drawPixel(random(0, screenWidth), random(0, screenHeight), WHITE);
    delay(20);
  }
  for (int i = 0; i < 10; i++)
    tft.drawCircle(random(0, screenWidth), random(0, screenHeight), random(0, 2), WHITE);

  tft.setTextSize(2);
  tft.setTextColor(YELLOW);
  tft.setCursor(115, 30);
  tft.print("New High-Score!");
  delay(1500);
  tft.setTextSize(1);
  tft.setCursor(140, 70);
  tft.print("Please enter username");
  delay(300);

  tft.drawRect(138, 150, 15, 4, YELLOW); delay(100);
  tft.drawRect(168, 150, 15, 4, YELLOW); delay(100);
  tft.drawRect(198, 150, 15, 4, YELLOW); delay(100);
  tft.drawRect(228, 150, 15, 4, YELLOW); delay(100);
  tft.drawRect(258, 150, 15, 4, YELLOW); delay(100);

  tft.drawCircle(30, 216, 4, RED);
  tft.setCursor(43, 213);
  tft.setTextColor(RED);
  tft.print("Remove");

  tft.drawCircle(110, 216, 4, BLUE);
  tft.setCursor(123, 213);
  tft.setTextColor(BLUE);
  tft.print("Select");

  tft.drawCircle(315, 216, 4, WHITE);
  tft.setCursor(328, 213);
  tft.setTextColor(WHITE);
  tft.print("Confirm");

  unsigned int counter = 0;
  bool isPicking = true;
  char letter = 'A';

  String playerName;
  String input;
  String buttonInput;

  int letterOffset = 30;
  int letterPosition = 140;

  int playerNameLength;
  bool hasDeleted = false;
  bool finishedPicking = false;
  while (isPicking)
  {
    //INPUT CHECK
    input = CheckAnalogInputs();
    buttonInput = CheckButtonInputs();

    playerNameLength = playerName.length();

    if (input == LEFT && (int)letter > 65) {
      DrawLetter(BLACK, letterPosition, letter);
      letter--;
    }
    else if (input == RIGHT && (int)letter < 90)
    {
      DrawLetter(BLACK, letterPosition, letter);
      letter++;
    }
    else if (buttonInput == BLUEBUTTON && playerNameLength < 5)
    {
      DrawLetter(WHITE, letterPosition, letter);
      playerName += letter;

      if (playerNameLength < 4)
        letterPosition += letterOffset;
      letter = 'A';

      if (playerNameLength == 4) //if we add all 5 letters
        finishedPicking = true;
    }
    else if (buttonInput == REDBUTTON && playerNameLength > 0 && playerNameLength < 6)
    {
      if (playerNameLength == 5)
        finishedPicking = false;

      DrawLetter(BLACK, letterPosition, playerName[playerNameLength - 1]);

      letter = playerName[playerNameLength - 1];

      if (playerNameLength < 5)
        letterPosition -= letterOffset;

      playerName.remove(playerNameLength - 1);

      hasDeleted = true;

    }

    if (buttonInput == WHITEBUTTON && playerNameLength >= 1)
      isPicking = false;

    if (input != NONE || buttonInput != NONE)
      delay(300);

    //END OF INPUT CHECK
    if (!finishedPicking)
      counter += CalculateDeltaTime();

    if (!finishedPicking)
      if (counter < 500)
        DrawLetter(WHITE, letterPosition, letter);
      else
        DrawLetter(BLACK, letterPosition, letter);

    if (counter > 900)
      counter = 0;
  }
  return playerName;
}

void DrawLetter(uint16_t color, int letterPosition, char letter)
{
  tft.setTextColor(color);
  tft.setTextSize(2);
  tft.setCursor(letterPosition, 130);
  tft.print(letter);
}

void GameOverUI(String fileName, int score)
{
  tft.fillScreen(BLACK);

  for (int i = 0; i < 80; i++) {
    tft.drawPixel(random(0, screenWidth), random(0, screenHeight), WHITE);
    delay(2);
  }

  String highscores = GetHighscores(fileName);
  int YPosition = 90;

  tft.setTextSize(2);
  tft.setCursor(80, 50);
  tft.setTextColor(YELLOW);
  tft.println("GAME OVER");

  tft.setCursor(90, 100);
  tft.setTextColor(GREEN);
  tft.println("Score:" + (String)score);

  //Inputs
  tft.fillCircle(100, 170, 6, BLUE);
  tft.fillCircle(170, 170, 6, RED);

  tft.setTextSize(1);
  tft.setCursor(80, 190);
  tft.setTextColor(BLUE);
  tft.println("restart");

  tft.setTextSize(1);
  tft.setCursor(160, 190);
  tft.setTextColor(RED);
  tft.println("exit");

  tft.drawRect(260, 35, 110, 180, YELLOW);
  //Text Settings
  tft.setTextSize(1);
  tft.setTextColor(YELLOW);
  tft.setCursor(280, 50);
  tft.println("HIGHSCORES");

  for (int i = 0; i < 5; i++)
  {
    tft.setCursor(270, YPosition);
    YPosition += 20;

    int endRange = 0;
    for (int j = 0; j < highscores.length(); j++)
      if (highscores[j] == ':')
      {
        endRange = j;
        break;
      }

    String currentScore = highscores.substring(0, endRange - 1);
    tft.println((String)(i + 1) + "." + currentScore.substring(0, 5) + "     " + currentScore.substring(5, currentScore.length()));

    highscores = highscores.substring(endRange + 1, highscores.length());
  }

  bool isRunning = true;
  String input;
  while (isRunning)
  {
    input = CheckButtonInputs();

    if (input != NONE && input != WHITEBUTTON)
      isRunning = false;
  }

  if (input == BLUEBUTTON)
    gameSelectStart[currentGameUI]();
  else if (input == REDBUTTON)
    MainMenu();

}

void GameStartTimer()
{
  tft.setTextSize(3);
  tft.setCursor(200, 100);
  tft.setTextColor(YELLOW);
  tft.print("3");
  delay(500);
  tft.setCursor(200, 100);
  tft.setTextColor(BLACK);
  tft.print("3");

  tft.setCursor(200, 100);
  tft.setTextColor(YELLOW);
  tft.print("2");
  delay(500);
  tft.setCursor(200, 100);
  tft.setTextColor(BLACK);
  tft.print("2");

  tft.setCursor(200, 100);
  tft.setTextColor(YELLOW);
  tft.print("1");
  delay(500);
  tft.setCursor(200, 100);
  tft.setTextColor(BLACK);
  tft.print("1");
}
