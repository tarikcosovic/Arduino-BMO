BodyPart food(random(10, screenWidth - 10), random(10, screenHeight -10)); //Spawning the initial food
int movementDirection = -1; //Starting movementDirection 
bool isRunning = true;
int score = 0;

 
void UpdateSnakePositions(Vector<BodyPart> &Snake, bool eaten = false);

void StartSnake()
{
  Vector<BodyPart> Snake;
  Snake.clear();
  score = 0;

  BodyPart temp(screenWidth/2, 200); //Starting position of snake
  Snake.push_back(temp);

  Serial.println(Snake[0].positionX);
  Serial.println(Snake[0].positionY);
  Serial.println(temp.positionX);
  Serial.println(screenWidth);
  Serial.println(Snake[0].GetPositionX());
  Serial.println(Snake[0].GetPositionY());
  Serial.println("random");
  Serial.println(Snake[0].positionX);
  

  unsigned int gameSpeed = 700;  //Setting the game speed
  unsigned int timer = 0;

  while(isRunning)
  {
    //Checking for input
    int tempVal = SnakeCheckInput();
    movementDirection = tempVal != 10?tempVal:movementDirection; //If no input, keep the previous movementDirection
    
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

  for(int i = 3; i < Snake.size() - 1; i++) //If collided with itself
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
  for(int i = Snake.size() - 1; i > 0; i--)
  {
    Snake[i].positionX = Snake[i - 1].positionX;
    Snake[i].positionY = Snake[i - 1].positionY;
  }
  
  switch(movementDirection)
  {
    case -1:
        Snake[0].positionY--;
      break;
    case 1:
        Snake[0].positionY++;
      break;
    case 2:
        Snake[0].positionX--;
      break;
    case 3:
        Snake[0].positionX++;
      break;
  }
  
  if(eaten)
  {
    BodyPart temp(Snake[Snake.size() - 1].positionX, Snake[Snake.size() - 1].positionY); // SPAWN ON THE POSITION OF THE LAST BODY PART AND WHEN THEY GET SHIFTED HE WILL STAY THE SAME OF LAST POS AND IGNORE THE SHIFT BECASUE HE'S THE LAST ONE
    Snake.push_back(temp); //SPAWNA OD KRAjA ELEMENTE RADI JEDNOSTAVNOSTI U KODU
  }
}

void RefreshDisplay(Vector<BodyPart> &Snake)
{
  tft.fillScreen(BLACK);
  for(int i = 0; i < Snake.size() - 1; i++)
  {
    tft.drawPixel(Snake[i].positionX, Snake[i].positionY, GREEN);
  }

  tft.drawPixel(food.positionX, food.positionY, RED);
}
