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

void BMOMenu()
{
  tft.fillScreen(BLACK);

  for (int i = 0; i < 80; i++)
    tft.drawPixel(random(0, screenWidth), random(0, screenHeight), 0xCFBA);
  for (int i = 0; i < 10; i++)
    tft.drawCircle(random(0, screenWidth), random(0, screenHeight), random(0, 3), 0xCFBA);

  tft.setTextSize(2);
  bool inMenu = true;
  bool transition = false;
  unsigned int menuTimer = 0;
  int currentOption = 1;

  for (int i = 0; i < 4; i++)
    DrawText(optionMenu[i].text, optionMenu[i].x, optionMenu[i].y, WHITE);

  tft.setCursor(140, 220);
  tft.setTextSize(1);
  tft.print("(C)2020 Tarik Cosovic");
  tft.setTextSize(2);
  
  SelectText(false, currentOption);

  while (inMenu)
  {
    menuTimer += CalculateDeltaTime();

    if (menuTimer > 500)
    {
      if (transition)
        DrawText(optionMenu[currentOption].text, optionMenu[currentOption].x, optionMenu[currentOption].y, BLACK);
      else
        DrawText(optionMenu[currentOption].text, optionMenu[currentOption].x, optionMenu[currentOption].y, RED);
      transition = !transition;
      menuTimer = 0;
    }

    String temp = CheckAnalogInputs();
    if (temp == DOWN && currentOption < 3)
      SelectText(true, currentOption);
    else if (temp == UP && currentOption > 0)
      SelectText(false, currentOption);

    String test = CheckButtonInputs();
    if (test == BLUEBUTTON)
      MainMenu();
  }
}

void DrawText(String text, int x, int y, uint16_t color)
{
  tft.setTextColor(color);
  tft.setCursor(x, y);
  tft.print(text);
}

void SelectText(bool increment, int &currentOption)
{
  DrawText(optionMenu[currentOption].text, optionMenu[currentOption].x, optionMenu[currentOption].y, WHITE);
  if (increment)
    currentOption++;
  else currentOption--;
  DrawText(optionMenu[currentOption].text, optionMenu[currentOption].x, optionMenu[currentOption].y, RED);

  delay(200);
}
