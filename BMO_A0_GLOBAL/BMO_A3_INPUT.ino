//Array of function pointers for the game select UI
void (* gameSelectUI [3])(String) = {StarWarsUI, TheMatrixUI, SnakeUI};
int currentGameUI = 0;

String CheckInputs()
{
  LeftButtonState = digitalRead(LeftButton);
  RightButtonState = digitalRead(RightButton);
  UpButtonState = digitalRead(UpButton);
  DownButtonState = digitalRead(DownButton);

  if (LeftButtonState == HIGH)
  {
    return LEFT;
  }
  else if (RightButtonState == HIGH)
  {
    return RIGHT;
  }
   else if (UpButtonState == HIGH)
  {
    return UP;
  }
   else if (DownButtonState == HIGH)
  {
    return DOWN;
  }

  return NONE;
}

int CalculateCurrentGameUI(String swipeDirection)
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
