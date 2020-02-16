//Array of function pointers for the game select UI
void (* gameSelectUI [2])(String) = {StarWarsUI, TheMatrixUI};
int currentGameUI = 0;

String CheckInputs()
{
  LeftButtonState = digitalRead(LeftButton);
  RightButtonState = digitalRead(RightButton);

  if (LeftButtonState == HIGH)
  {
    return LEFT;
  }
  else if (RightButtonState == HIGH)
  {
    return RIGHT;
  }

  return NONE;
}

int CalculateCurrentGameUI(String swipeDirection)
{
  if (swipeDirection.equals(LEFT))
  {
    if (currentGameUI <= 0)
    {
      currentGameUI = 1;
    }
    else
    {
      currentGameUI--;
    }
  }

  if (swipeDirection.equals(RIGHT))
  {
    if (currentGameUI >= 1)
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
