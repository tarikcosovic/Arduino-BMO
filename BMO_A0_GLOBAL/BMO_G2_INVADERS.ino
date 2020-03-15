//BITMAPS
//DIMENSIONS 7 - 5
const unsigned char invader[]PROGMEM = {B00111000, B11010110, B11111110, B00101000, B11000110, B00111000, B11010110, B11111110, B01000100, B00101000, B00010000, B10111010, B11010110, B01111100, B00101000, B00111000, B01010100, B11111110, B10010010, B00101000, B00111000, B01010100, B01111100, B01000100, B00101000, B00111000, B01010100, B01111100, B00101000, B01010100, B01010100, B10000010, B01010100, B10000010, B01010100, B01010100, B10000010, B01010100, B10000010, B01010100};

//DMENSIONS 3 - 6
const unsigned char playership[]PROGMEM = {B00010000, B01111100, B11111110, B11111110, B10001010, B01000000, B00000100, B10010010, B10010010, B00000100, B01000000, B10001010};

//DIMENSIONS 2 - 6
const unsigned char bomb[]PROGMEM = {B10000000, B01000000, B10000000, B01000000, B01000000, B10000000, B01000000, B1000000};

//DIMENSIONS 5 - 7

const unsigned char bunker[]PROGMEM  = { B01111110, B11111111, B11111111, B11100111, B11000011, B01111110, B11011011, B11111111, B10100101, B11000011, B01101110, B11011011, B01110110, B10100101, B11000011, B01100110, B11011001, B01010110, B10100101, B01000010, B00100010, B10001001, B01010010, B10100101, B01000010};

//Game Configuration
const int enemyRows = 3;
const int enemyColumns = 13;
InvaderShip enemyShips[enemyRows][enemyColumns];
bool movingLeft = false;
int currentRow = 2; //Manually insert enemyRows -1 due to a bug

InvaderShip playerShip;
InvaderShip playerBullet;

int movementConstraintLeft = 100;
int movementConstraintRight = 300;

int invadersSpeedOffset = 400;

bool isFiring = false;
bool changeSides = false;
bool UpdateYPosition = false;

void StartInvaders()//AFTER EACH LEVEL JUST SET STARTING Y POSITION TO LOWER! or in this cord sys to higher and maybe vector instead of arrays for better optimisation
{
  unsigned int gameSpeedInvaders = 0;
  unsigned int playerSpeed = 0;
  unsigned int bulletSpeedInvaders = 0;
  unsigned int frameTime = 0;

  String inputVal;

  tft.fillScreen(BLACK);
  score = 0;
  isRunning = true;

  //Define Player Starting Cords
  playerShip.x = 200;
  playerShip.y = 200;

  CreateEnemyShips();
  CreateBunkers();

  UpdatePlayerShip(NONE);//Drawing the initial player ship

  while (isRunning)
  {
    frameTime = CalculateDeltaTime();
    playerSpeed += frameTime;
    bulletSpeedInvaders += frameTime;
    gameSpeedInvaders += frameTime;

    inputVal = CheckButtonInputs();
    if (inputVal == BLUEBUTTON && !isFiring)
      DrawBulletInvaders();

    if (playerSpeed % 20 == 0) // % 20 - Speed
    {
      inputVal = CheckAnalogInputs();
      if (inputVal != NONE)
        UpdatePlayerShip(inputVal);

    }
    if (isFiring && bulletSpeedInvaders % 10 == 0)
      DrawBulletInvaders();

    if (gameSpeedInvaders % invadersSpeedOffset == 0)
    {
      //Draws BLACK
      UpdateGraphicsInvaders(BLACK);

      //Update the movement of invaders
      UpdateGameLogicInvaders();

      //Draws WHITE
      UpdateGraphicsInvaders(WHITE);

      if (currentRow == 0)
        currentRow = 2;//Manually insert enemyRows -1 due to a bug
      else currentRow--;
    }
  }
}

void CreateEnemyShips()
{
  //Drawing some stars
  for (int i = 0; i < 80; i++) {
    tft.drawPixel(random(0, screenWidth), random(0, screenHeight), WHITE);
    delay(20);
  }
  for (int i = 0; i < 10; i++)
    tft.drawCircle(random(0, screenWidth), random(0, screenHeight), random(0, 2), WHITE);

  //Starting position
  int enemyX = 100;
  int enemyY = 20;
  for (int i = 0; i < enemyRows; i++)
  {
    for (int j = 0; j < enemyColumns; j++)
    {
      InvaderShip temp(enemyX, enemyY);
      enemyShips[i][j] = temp;
      enemyX += 15;
    }
    enemyX = 100;
    enemyY += 30;
  }
}

void CreateBunkers()
{
  int temp = 125;
  for (int i = 0; i < 4; i++)
  {
    tft.drawBitmap(temp, 170, bunker, 5, 7, WHITE);
    temp += 50;
  }
}

void UpdateGameLogicInvaders()
{
  if (UpdateYPosition)//Updating the Y position when hitting the constraints
  {
    if (currentRow == 0)
      UpdateYPosition = false;

    for (int i = 0; i < enemyColumns; i++)
      enemyShips[currentRow][i].y += 2;
  }

  if (movingLeft)
  {
    for (int i = 0; i < enemyColumns; i++)
    {
      if (!enemyShips[currentRow][i].isDead)
      {
        enemyShips[currentRow][i].x -= 4;
        //If one of the ships goes over the left constraint change moving sides
        if (enemyShips[currentRow][i].x < movementConstraintLeft)
          changeSides = true;
      }
    }
  }
  else
  {
    for (int i = 0; i < enemyColumns; i++)
    {
      if (!enemyShips[currentRow][i].isDead)
      {
        enemyShips[currentRow][i].x += 4;
        //If one of the ships goes over the left constraint change moving sides
        if (enemyShips[currentRow][i].x > movementConstraintRight)
          changeSides = true;
      }
    }
  }

  if (changeSides && currentRow == 0)
  {
    movingLeft = !movingLeft;
    changeSides = false;
    UpdateYPosition = true;

    invadersSpeedOffset -= 10;//Increasing the movement speed of invaders
  }
}

void UpdateGraphicsInvaders(uint16_t color)
{
  for (int i = 0; i < enemyColumns; i++)
    tft.drawBitmap(enemyShips[currentRow][i].x, enemyShips[currentRow][i].y, invader, 7, 5, color);
}

void UpdatePlayerShip(String temp)
{
  tft.drawBitmap(playerShip.x, playerShip.y, playership, 7, 5, BLACK);

  if (temp == LEFT && playerShip.x > movementConstraintLeft)
    playerShip.x --;
  else if (temp == RIGHT && playerShip.x < movementConstraintRight)
    playerShip.x ++;

  tft.drawBitmap(playerShip.x, playerShip.y, playership, 7, 5, WHITE);
}

void DrawBulletInvaders()
{
  if (!isFiring)
  {
    playerBullet.x = playerShip.x;
    playerBullet.y = playerShip.y - 4;
    isFiring = true;
  }
  tft.fillRect(playerBullet.x + 2, playerBullet.y, 2, 6, BLACK);
  playerBullet.y --;
  tft.fillRect(playerBullet.x + 2, playerBullet.y, 2, 6, WHITE);

  CheckBulletCollision();
}

void CheckBulletCollision()
{
  //If bullet misses everything - reset
  if (playerBullet.y < -6)
    isFiring = false;
  //If bullet hits bunker
  if ((playerBullet.x > 122 && playerBullet.x < 131 && playerBullet.y == 180) || (playerBullet.x > 172 && playerBullet.x < 181 && playerBullet.y == 180) ||
      (playerBullet.x > 222 && playerBullet.x < 231 && playerBullet.y == 180)  || (playerBullet.x > 272 && playerBullet.x < 281 && playerBullet.y == 180)) {
    tft.fillRect(playerBullet.x + 2, playerBullet.y, 2, 6, BLACK);
    isFiring = false;
  }

  //Collision with Invaders

}
