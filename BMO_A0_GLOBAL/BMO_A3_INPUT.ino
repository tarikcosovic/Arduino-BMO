//Array of function pointers for the game select UI
void (* gameSelectUI [2])(String) = {StarWarsUI, TheMatrixUI};
int currentGameUI = 0;

void CheckInputs()
{
  LeftButtonState = digitalRead(LeftButton);
  RightButtonState = digitalRead(RightButton);

  if (LeftButtonState == HIGH)
  {
    CalculateCurrentGameUI("left");
  }
  else if (RightButtonState == HIGH)
  {
    CalculateCurrentGameUI("right");
  }
}

int CalculateCurrentGameUI(String swipeDirection)
{
  if (swipeDirection.equals("left"))
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

  if (swipeDirection.equals("right"))
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

  gameSelectUI[currentGameUI](swipeDirection);
}
