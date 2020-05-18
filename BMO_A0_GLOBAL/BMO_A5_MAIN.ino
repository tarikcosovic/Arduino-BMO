struct MenuTitle {
  String text;
  int x;
  int y;

  MenuTitle(String temp, int x2, int y2)
  {
    text = temp;
    x = x2;
    y = y2;
  }
};

MenuTitle option1("Games", 175, 50);
MenuTitle option2("Options", 165, 85);
MenuTitle option3("Highscores", 147, 120);
MenuTitle option4("Music", 175, 155);

MenuTitle optionMenu[4] {option1, option2, option3, option4};
void (* selectMenuOption [4])() = {MainMenu, OptionsMenu, HighScoreMenu, MusicMenu};

void BMOMenu()
{
  tft.fillScreen(BLACK);
  BodyPart stars[80];

  for (int i = 0; i < 80; i++)
  {
    stars[i].positionX = random(0, screenWidth);
    stars[i].positionY = random(0, screenHeight);
  }

  bool inMenu = true;
  bool transition = false;
  bool transitionAnimation = false;
  unsigned int transitionAnimationTimer = 0;
  unsigned int menuTimer = 0;
  int currentOption = 1;

  bool inputCheckAvailability = true;
  unsigned int inputTimer = 0;

  tft.setTextSize(2);
  for (int i = 0; i < 4; i++)
    DrawText(optionMenu[i].text, optionMenu[i].x, optionMenu[i].y, WHITE);
  DrawCopyright(WHITE);

  SelectText(false, currentOption);

  int deltaTime;
  while (inMenu)
  {
    deltaTime = CalculateDeltaTime();

    menuTimer += deltaTime;
    inputTimer += deltaTime;

    if (transitionAnimation)
      transitionAnimationTimer += deltaTime;


    StarsMovementMainMenu(stars, transitionAnimation, currentOption);

    if (menuTimer > 500 && !transitionAnimation)
    {
      if (transition)
        DrawText(optionMenu[currentOption].text, optionMenu[currentOption].x, optionMenu[currentOption].y, BLACK);
      else
        DrawText(optionMenu[currentOption].text, optionMenu[currentOption].x, optionMenu[currentOption].y, CYAN);//0xE71C
      transition = !transition;
      menuTimer = 0;
    }

    if (inputTimer > 500)
      inputCheckAvailability = true;

    String temp = CheckAnalogInputs();
    String temp2 = CheckButtonInputs();
    if (inputCheckAvailability && (temp != NONE || temp2 != NONE))
    {
      MainMenuArrowCheck(temp, currentOption);
      MainMenuButtonCheck(temp2, transitionAnimation);

      inputCheckAvailability = false;
      inputTimer = 0;
    }

    if (transitionAnimationTimer > 1500)
    {
      tft.setRotation(3);
      tft.fillScreen(BLACK);
      tft.setRotation(1);
      inMenu = false;
      currentEvent = selectMenuOption[currentOption];
    }
  }
}

void MainMenuButtonCheck(String temp, bool &transitionAnimation)
{
  if (temp == BLUEBUTTON)
  {
    for (int i = 0; i < 4; i++)
      DrawText(optionMenu[i].text, optionMenu[i].x, optionMenu[i].y, BLACK);
    DrawCopyright(BLACK);

    transitionAnimation = true;
  }
  
  if(temp != NONE)
    ButtonPressSFX();
  else ButtonSelectSFX();
}

void StarsMovementMainMenu(BodyPart stars[80], bool transitionAnimation, int currentOption)
{
  for (int i = 0; i < 80; i++)
  {
    if (!transitionAnimation)
      tft.drawPixel(stars[i].positionX, stars[i].positionY, BLACK);

    stars[i].positionY--;
    tft.drawPixel(stars[i].positionX, stars[i].positionY, CYAN);//0xCFBA

    if (stars[i].positionY < 0)
      stars[i].positionY = 240;
  }
  if (!transitionAnimation)
  {
    for (int i = 0; i < 4; i++)
    {
      if (currentOption == i)
        continue;
      DrawText(optionMenu[i].text, optionMenu[i].x, optionMenu[i].y, WHITE);
    }
    DrawCopyright(WHITE);
  }
}

void MainMenuArrowCheck(String temp, int &currentOption)
{
  if (temp == DOWN && currentOption < 3)
    SelectText(true, currentOption);
  else if (temp == UP && currentOption > 0)
    SelectText(false, currentOption);
}

void DrawText(String text, int x, int y, uint16_t color)
{
  tft.setTextColor(color);
  tft.setCursor(x, y);
  tft.print(text);
}

void DrawCopyright(uint16_t color)
{
  tft.setCursor(140, 220);
  tft.setTextSize(1);
  tft.setTextColor(color);
  tft.print("(C)2020 Tarik Cosovic");
  tft.setTextSize(2);
}

void SelectText(bool increment, int &currentOption)
{
  DrawText(optionMenu[currentOption].text, optionMenu[currentOption].x, optionMenu[currentOption].y, WHITE);
  if (increment)
    currentOption++;
  else currentOption--;
  DrawText(optionMenu[currentOption].text, optionMenu[currentOption].x, optionMenu[currentOption].y, CYAN);
}
