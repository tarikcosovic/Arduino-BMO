//Array of function pointers for the game select UI
void (* gameSelectUI [3])(String) = {StarWarsUI, TheMatrixUI, SnakeUI};
void (* gameSelectStart [3])() = {StarWarsUI, TheMatrixUI, StartSnake};
int currentGameUI = 0;

String CheckAnalogInputs()
{
  YAxisValue = analogRead(YAxis);
  XAxisValue = analogRead(XAxis);

  if (XAxisValue > 700)
  {
    return RIGHT;
  }
  else if (XAxisValue < 300)
  {
    return LEFT;
  }
   else if (YAxisValue < 300)
  {
    return UP;
  }
   else if (YAxisValue > 700)
  {
    return DOWN;
  }
  return NONE;
}

String CheckButtonInputs()
{
  RedButtonState = digitalRead(RedButton);
  BlueButtonState = digitalRead(BlueButton);
  WhiteButtonState = digitalRead(WhiteButton);

  if (RedButtonState == HIGH)
  {
    return REDBUTTON;
  }
  else if (BlueButtonState == HIGH)
  {
    return BLUEBUTTON;
  }
   else if (WhiteButtonState == HIGH)
  {
    return WHITEBUTTON;
  }
  return NONE;
}

void CalculateCurrentGameUI(String swipeDirection)
{
  if (swipeDirection.equals(LEFT))
  {
    if (currentGameUI <= 0)
    {
      currentGameUI = 2;
    }
    else
    {
      currentGameUI--;
    }
  }

  if (swipeDirection.equals(RIGHT))
  {
    if (currentGameUI >= 2)
    {
      currentGameUI = 0;
    }
    else
    {
      currentGameUI++;
    }
  }
  if(swipeDirection == LEFT || swipeDirection == RIGHT)
    gameSelectUI[currentGameUI](swipeDirection);
}
