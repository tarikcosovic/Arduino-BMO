BodyPart food(240, 24); //Spawning the initial food
String movementDirection = UP; //Starting movementDirection
int snakeScalingFactor = 8;
int SnakeBorderOffset = 15;

void UpdateSnakePositions(Vector<BodyPart> &Snake, bool eaten = false);

void StartSnake()
{
  tft.fillScreen(BLACK);
  tft.drawRect(SnakeBorderOffset - 1, SnakeBorderOffset - 1, screenWidth - (SnakeBorderOffset * 2) + 2, screenHeight - (SnakeBorderOffset * 2) + 2, MAGENTA); //Draws game borders
  tft.drawRect(food.positionX, food.positionY, snakeScalingFactor, snakeScalingFactor, GREEN); //Draws initial food

  GameStartTimer();
  tft.setTextSize(1);

  Vector<BodyPart> Snake;
  Snake.Clear();

  BodyPart temp(240, 160); //Starting position of snake
  BodyPart temp2(240, 152);
  BodyPart temp3(240, 144);

  Snake.PushBack(temp);
  Snake.PushBack(temp2);
  Snake.PushBack(temp3);

  tft.drawRect(240, 152, snakeScalingFactor, snakeScalingFactor, MAGENTA);
  tft.drawRect(240, 144, snakeScalingFactor, snakeScalingFactor, MAGENTA);

  score = 0;
  isRunning = true;
  isPaused = false;
  UpdateScore();

  unsigned int gameSpeed = 100;  //Setting the game speed
  unsigned int timer = 0;

  while (isRunning)
  {
    //Checking for input
    String tempVal = CheckAnalogInputs();

    String tempVal2 = CheckButtonInputs();
    if (tempVal2 != NONE)
      ButtunInputsSnake(tempVal2);
    if (isPaused)continue;

    if ((movementDirection == LEFT && tempVal == RIGHT) || (movementDirection == RIGHT && tempVal == LEFT) || (movementDirection == UP && tempVal == DOWN) || (movementDirection == DOWN && tempVal == UP))
    {
      //Movement constraints e.g. go Left then Right && from Up to Down
    }
    else
      movementDirection = tempVal != NONE ? tempVal : movementDirection; //If no input, keep the previous movementDirection


    timer += CalculateDeltaTime();
    if (timer > gameSpeed)
    {
      timer = 0;

      UpdateGameLogic(Snake);

      RefreshDisplay(Snake);
    }
  }

  currentEvent = &GameOver;
  currentEventArgs.fileName = SNAKE;
  currentEventArgs.score = score;
}


void UpdateGameLogic(Vector<BodyPart> &Snake)
{
  //Collision Checks

  for (int i = 3; i < Snake.Size() - 1; i++) //If collided with itself
  {
    if (Snake[0].positionX == Snake[i].positionX && Snake[0].positionY == Snake[i].positionY)
    {
      isRunning = false;
    }
  }

  if (Snake[0].positionX > screenWidth - SnakeBorderOffset - 2 || Snake[0].positionX < SnakeBorderOffset || Snake[0].positionY > screenHeight - SnakeBorderOffset - 2 || Snake[0].positionY < SnakeBorderOffset) //If went out of screen boundaries
  {
    isRunning = false;
  }

  if (Snake[0].positionX == food.positionX && Snake[0].positionY == food.positionY) //If collided with food
  {
    score++;
    //Generating new food position
restart:
    do
    {
      food.positionX = random(SnakeBorderOffset, screenWidth - SnakeBorderOffset - snakeScalingFactor);
    } while (food.positionX % snakeScalingFactor);

    do
    {
      food.positionY = random(SnakeBorderOffset, screenHeight - SnakeBorderOffset - snakeScalingFactor);
    } while (food.positionY % snakeScalingFactor != 0);

    //CHECK FOR OVERLAPPING WITH SNAKE BODY
    for (int i = 0; i < Snake.Size(); i++)
      if (food.positionX == Snake[i].positionX && food.positionY == Snake[i].positionY)
        goto restart;

    //END GENERATING NEW FOOD POSITION
    tft.drawRect(food.positionX, food.positionY, snakeScalingFactor, snakeScalingFactor, GREEN);

    UpdateSnakePositions(Snake, true);
    return;
  }

  UpdateSnakePositions(Snake, false);
}

void UpdateSnakePositions(Vector<BodyPart> &Snake, bool eaten = false)
{
  //Draws the tail of the snake black and new position white
  //tft.drawPixel(Snake[Snake.Size() - 1].positionX, Snake[Snake.Size() - 1].positionY, BLACK);
  tft.drawRect(Snake[Snake.Size() - 1].positionX, Snake[Snake.Size() - 1].positionY, snakeScalingFactor, snakeScalingFactor, BLACK);

  for (int i = Snake.Size() - 1; i > 0; i--)
  {
    Snake[i].positionX = Snake[i - 1].positionX;
    Snake[i].positionY = Snake[i - 1].positionY;
  }

  //Updating the head of snake to next frame position
  if (movementDirection == UP)
    Snake[0].positionY -= snakeScalingFactor;
  else if (movementDirection == DOWN)
    Snake[0].positionY += snakeScalingFactor;
  else if (movementDirection == LEFT)
    Snake[0].positionX -= snakeScalingFactor;
  else if (movementDirection == RIGHT)
    Snake[0].positionX += snakeScalingFactor;

  if (eaten)
  {
    BodyPart temp(Snake[Snake.Size() - 1].positionX, Snake[Snake.Size() - 1].positionY);
    Snake.PushBack(temp);

    tft.drawRect(Snake[Snake.Size() - 1].positionX, Snake[Snake.Size() - 1].positionY, snakeScalingFactor, snakeScalingFactor, MAGENTA);

    UpdateScore();
  }
}

void ButtunInputsSnake(String temp)
{
  if (temp == WHITEBUTTON)
  {
    tft.setCursor(350, 5);
    if (isPaused)
    {
      tft.setTextColor(BLACK);
      tft.print("PAUSED");
      isPaused = false;
    }
    else
    {
      tft.setTextColor(MAGENTA);
      tft.print("PAUSED");
      isPaused = true;
    }
    delay(500);
  }
  else if (temp == REDBUTTON)
  {
    currentEvent = gameSelectUI[currentGameUI];
    currentEventArgs.swipeDirection = LEFT;
  }
}

void RefreshDisplay(Vector<BodyPart> &Snake)
{
  tft.drawRect(Snake[0].positionX, Snake[0].positionY, snakeScalingFactor, snakeScalingFactor, MAGENTA);
}

void UpdateScore()
{
   //Serial.println(freeMemory());
  //Delete old score
  tft.setTextColor(BLACK);
  tft.setCursor(SnakeBorderOffset, 5);
  tft.print("score: " + (String)(score - 1));

  //Add new score
  tft.setTextColor(MAGENTA);
  tft.setCursor(SnakeBorderOffset, 5);
  tft.print("score: " + (String)score);
}
