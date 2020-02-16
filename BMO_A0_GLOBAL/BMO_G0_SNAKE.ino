BodyPart food(200, 120); //Spawning the initial food
String movementDirection = UP; //Starting movementDirection 
bool isRunning = true;
int score = 0;

void UpdateSnakePositions(Vector<BodyPart> &Snake, bool eaten = false);

void StartSnake()
{
  tft.fillScreen(BLACK);
  Vector<BodyPart> Snake;
  Snake.Clear();
  score = 0;

  BodyPart temp(screenWidth/2, 200); //Starting position of snake
  Snake.PushBack(temp);

  unsigned int gameSpeed = 300;  //Setting the game speed
  unsigned int timer = 0;

  while(isRunning)
  {
    //Checking for input
    String tempVal = CheckInputs();
    movementDirection = tempVal != NONE?tempVal:movementDirection; //If no input, keep the previous movementDirection
    
    timer += CalculateDeltaTime();
    if(timer > gameSpeed)
    {
      timer = 0;

      UpdateGameLogic(Snake);

      RefreshDisplay(Snake);
    }
  }
  //When Game Over
  tft.fillScreen(RED);
}


void UpdateGameLogic(Vector<BodyPart> &Snake)
{
  //Collision Checks

  for(int i = 3; i < Snake.Size() - 1; i++) //If collided with itself
  {
    if(Snake[0].positionX == Snake[i].positionX && Snake[0].positionY == Snake[i].positionY)
    {
      isRunning = false;
    }
  }

  if(Snake[0].positionX > screenWidth || Snake[0].positionX < 0 || Snake[0].positionY > screenHeight || Snake[0].positionY < 0) //If went out of screen boundaries
  {
    isRunning = false;
  }

  if(Snake[0].positionX == food.positionX && Snake[0].positionY == food.positionY) //If collided with food
  {
    score++;
    //Generating new food position
    food.positionX = random(0, screenWidth);
    food.positionY = random(0, screenHeight);

     UpdateSnakePositions(Snake, true);
     return;
  }

  UpdateSnakePositions(Snake, false);
}

void UpdateSnakePositions(Vector<BodyPart> &Snake, bool eaten = false)
{
  for(int i = Snake.Size() - 1; i > 0; i--)
  {
    Snake[i].positionX = Snake[i - 1].positionX;
    Snake[i].positionY = Snake[i - 1].positionY;
  }
  //Draws the tail of the snake black and new position white
  tft.drawPixel(Snake[Snake.Size() - 1].positionX, Snake[Snake.Size() - 1].positionY, BLACK);
  //Updating the head of snake to next frame position
  if(movementDirection == UP)
    Snake[0].positionY--;
  else if(movementDirection == DOWN)
    Snake[0].positionY++;
  else if(movementDirection == LEFT)
    Snake[0].positionX--;
  else if(movementDirection == RIGHT)
    Snake[0].positionX++;
  
  if(eaten)
  {
    BodyPart temp(Snake[Snake.Size() - 1].positionX, Snake[Snake.Size() - 1].positionY);
    Snake.PushBack(temp); 
  }
}

void RefreshDisplay(Vector<BodyPart> &Snake)
{
  tft.drawPixel(Snake[0].positionX, Snake[0].positionY, GREEN);

  tft.drawPixel(food.positionX, food.positionY, RED);
}
