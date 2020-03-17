//BITMAPS
//DIMENSIONS 7 - 5
const unsigned char invader[]PROGMEM = {B00111000, B11010110, B11111110, B00101000, B11000110, B00111000, B11010110, B11111110, B01000100, B00101000, B00010000, B10111010, B11010110, B01111100, B00101000, B00111000, B01010100, B11111110, B10010010, B00101000, B00111000, B01010100, B01111100, B01000100, B00101000, B00111000, B01010100, B01111100, B00101000, B01010100, B01010100, B10000010, B01010100, B10000010, B01010100, B01010100, B10000010, B01010100, B10000010, B01010100};

//DMENSIONS 3 - 6
const unsigned char playership[]PROGMEM = {B00010000, B01111100, B11111110, B11111110, B10001010, B01000000, B00000100, B10010010, B10010010, B00000100, B01000000, B10001010};

//DIMENSIONS 5 - 7

const unsigned char bunker[]PROGMEM  = { B01111110, B11111111, B11111111, B11100111, B11000011, B01111110, B11011011, B11111111, B10100101, B11000011, B01101110, B11011011, B01110110, B10100101, B11000011, B01100110, B11011001, B01010110, B10100101, B01000010, B00100010, B10001001, B01010010, B10100101, B01000010};

//Game Configuration
const int enemyRows = 3;
const int enemyColumns = 13;
Vector<InvaderShip> enemyShipsRow1;
Vector<InvaderShip> enemyShipsRow2;
Vector<InvaderShip> enemyShipsRow3;

Vector<InvaderShip> enemyShips[3] = {enemyShipsRow1, enemyShipsRow2, enemyShipsRow3};

bool movingLeft = false;
int currentRow = 2; //Manually insert enemyRows -1 due to a bug

Vector<InvaderShip> enemyBullets;

InvaderShip playerShip;
InvaderShip playerBullet;

int movementConstraintLeft = 80;
int movementConstraintRight = 320;

int invadersSpeedOffset = 400;

bool isFiring = false;
bool changeSides = false;
bool UpdateYPosition = false;

void StartInvaders()//AFTER EACH LEVEL JUST SET STARTING Y POSITION TO LOWER! or in this cord sys to higher and maybe vector instead of arrays for better optimisation
{
  unsigned int gameSpeedInvaders = 0;
  unsigned int playerSpeed = 0;
  unsigned int bulletSpeedInvaders = 0;
  unsigned int EnemyBulletSpeedInvaders = 0;
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
  DrawInitialInvaders();
  while (isRunning)
  {
    frameTime = CalculateDeltaTime();
    playerSpeed += frameTime;
    bulletSpeedInvaders += frameTime;
    gameSpeedInvaders += frameTime;
    EnemyBulletSpeedInvaders += frameTime;

    inputVal = CheckButtonInputs();
    if (inputVal == BLUEBUTTON && !isFiring)
      DrawBulletInvaders();

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

    if (EnemyBulletSpeedInvaders % 2500 == 0)
    {
      SpawnBulletsInvaders();
    }

    if (playerSpeed % 20 == 0) // % 20 - Speed
    {
      inputVal = CheckAnalogInputs();
      if (inputVal != NONE)
        UpdatePlayerShip(inputVal);

      UpdateInvaderBullet();

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

  tft.setCursor(10, 20);
  tft.print("SCORE:");

  //Starting position
  int enemyX = 100;
  int enemyY = 30;

  for (int i = 0; i < enemyRows; i++)
  {
    for (int j = 0; j < enemyColumns; j++)
    {
      InvaderShip temp(enemyX, enemyY);
      enemyShips[i].PushBack(temp);
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
  if (UpdateYPosition)
  {
    for (int i = 0; i < enemyShips[currentRow].Size(); i++)
      enemyShips[currentRow][i].y += 3;

    if (currentRow == 0)
      UpdateYPosition = false;

    if(enemyShips[currentRow].Size() > 0 && enemyShips[currentRow][0].y > 180)
      isRunning = false;
  }

  if (movingLeft)
  {
    for (int i = 0; i < enemyShips[currentRow].Size(); i++)
    {
      enemyShips[currentRow][i].x -= 4;
      //If one of the ships goes over the left constraint change moving sides
    }
    if (enemyShips[currentRow].Size() > 0 && enemyShips[currentRow][0].x < movementConstraintLeft)
      changeSides = true;
    //Updating the Y position when hitting x constraint
  }
  else
  {
    for (int i = 0; i < enemyShips[currentRow].Size(); i++)
    {
      enemyShips[currentRow][i].x += 4;
      //If one of the ships goes over the left constraint change moving sides
    }
    if (enemyShips[currentRow].Size() > 0 && enemyShips[currentRow][enemyShips[currentRow].Size() - 1].x > movementConstraintRight)
      changeSides = true;
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
  for (int i = 0; i < enemyShips[currentRow].Size(); i++)
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

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0 ; j < enemyShips[i].Size(); j++)
    {
      if ((abs(playerBullet.x - enemyShips[i][j].x)  <= 2 || abs(playerBullet.x - (enemyShips[i][j].x + 6))  <= 2) && abs(playerBullet.y - enemyShips[i][j].y) <= 2)
      {
        tft.drawBitmap(enemyShips[i][j].x, enemyShips[i][j].y, invader, 7, 5, BLACK);
        tft.fillRect(playerBullet.x + 2, playerBullet.y, 2, 6, BLACK);

        enemyShips[i].Erase(j);

        isFiring = false;
        UpdateScoreInvaders();
        break;
      }
    }
  }
}

void UpdateInvaderBullet()
{
  if (enemyBullets.Size() > 0)
  {
    for (int i = 0; i < enemyBullets.Size(); i ++)
    {
      tft.fillRect(enemyBullets[i].x, enemyBullets[i].y, 2, 6, BLACK);
      enemyBullets[i].y += 2;
      tft.fillRect(enemyBullets[i].x, enemyBullets[i].y, 2, 6, WHITE);

      CheckEnemyBulletCollision(enemyBullets[i], i);
    }
  }
}

void CheckEnemyBulletCollision(InvaderShip temp, int index)
{
  //If bullet misses everything - reset
  if (temp.y > 246)
  {
    tft.fillRect(temp.x, temp.y, 2, 6, BLACK);
    enemyBullets.Erase(index);
  }
  //If bullet hits bunker
  if ((temp.x > 122 && temp.x < 131 && (temp.y > 160 && temp.y < 170)) || (temp.x > 172 && temp.x < 181 && (temp.y > 160 && temp.y < 170)) ||
      (temp.x > 222 && temp.x < 231 && (temp.y > 160 && temp.y < 170))  || (temp.x > 272 && temp.x < 281 && (temp.y > 160 && temp.y < 170))) {
    tft.fillRect(temp.x, temp.y, 2, 6, BLACK);
    enemyBullets.Erase(index);
  }

  if (temp.x > playerShip.x - 4 && temp.x < playerShip.x + 4 && (temp.y > playerShip.y - 5 && temp.y < playerShip.y + 5))
    isRunning = false;
}

void SpawnBulletsInvaders()
{
  int rtemp = random(0, 5);
  for (int c = 0; c < rtemp; c++)
  {
    int row = random(0, 3);
    if (enemyShips[row].Size() > 0)
    {
      int col = random(0, enemyShips[row].Size());
      InvaderShip temp(enemyShips[row][col].x, enemyShips[row][col].y);
      enemyBullets.PushBack(temp);
    }
  }
}

void UpdateScoreInvaders()
{
  tft.setTextColor(BLACK);
  tft.setCursor(50, 20);
  tft.print(score);
  score++;
  tft.setTextColor(WHITE);
  tft.setCursor(50, 20);
  tft.print(score);
}

void DrawInitialInvaders()
{
  UpdateGraphicsInvaders(WHITE);
  currentRow--;
  UpdateGraphicsInvaders(WHITE);
  currentRow--;
  UpdateGraphicsInvaders(WHITE);
  currentRow = 2;
  delay(1000);
}
