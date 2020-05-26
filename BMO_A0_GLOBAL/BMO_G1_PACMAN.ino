const unsigned char ghost[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000011, B11000000, B00000000,
  B00000111, B11100000, B00000000,
  B00000111, B11100000, B00000000,
  B00000101, B10100000, B00000000,
  B00000111, B11100000, B00000000,
  B00000010, B01000000, B00000000,
  B00011110, B01111000, B00000000,
  B00111111, B11111100, B00000000,
  B00100111, B11100100, B00000000,
  B00100111, B11100100, B00000000,
  B00110111, B11101100, B00000000,
  B00110011, B11001100, B00000000,
  B00000011, B10000000, B00000000,
  B00000001, B11000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char house[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000001, B10000000, B00000000,
  B00000010, B11000000, B00000000,
  B00000100, B11100000, B00000000,
  B00001000, B11110000, B00000000,
  B00010001, B11011000, B00000000,
  B00100010, B01111100, B00000000,
  B01000101, B10110110, B00000000,
  B01001011, B11011010, B00000000,
  B01010110, B01101110, B00000000,
  B01101110, B01110110, B00000000,
  B00011111, B11111000, B00000000,
  B00111110, B01111100, B00000000,
  B00011110, B01111000, B00000000,
  B00111110, B01111100, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};


const unsigned char teleport[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000010, B01000000, B00000000,
  B00001001, B10010000, B00000000,
  B00000001, B10000000, B00000000,
  B00101101, B10110100, B00000000,
  B00001110, B01110000, B00000000,
  B00000111, B11100000, B00000000,
  B00010001, B10001000, B00000000,
  B00100101, B10100100, B00000000,
  B00100011, B11000100, B00000000,
  B00100001, B10000100, B00000000,
  B00011000, B00011000, B00000000,
  B00000111, B11100000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char stickyTile[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000000, B10000000, B00000000,
  B00001000, B00000000, B00000000,
  B00000011, B10110000, B00000000,
  B00011011, B10110100, B00000000,
  B00011011, B10000000, B00000000,
  B00000000, B00111000, B00000000,
  B01011101, B10111000, B00000000,
  B00011101, B10111010, B00000000,
  B00011100, B00000000, B00000000,
  B00000001, B11011000, B00000000,
  B00101101, B11011000, B00000000,
  B00001101, B11000000, B00000000,
  B00000000, B00010000, B00000000,
  B00000001, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char money[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B01111000, B00000000,
  B00000000, B11001100, B00000000,
  B00000000, B10110100, B00000000,
  B00000000, B11001100, B00000000,
  B00000000, B01111000, B00000000,
  B00011110, B10000100, B00000000,
  B00110011, B01111000, B00000000,
  B00101101, B10000100, B00000000,
  B00110011, B01111000, B00000000,
  B00011110, B00000000, B00000000,
  B00100001, B00000000, B00000000,
  B00011110, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char face_smile[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000011, B11000000, B00000000,
  B00001111, B11110000, B00000000,
  B00011111, B11111000, B00000000,
  B00111111, B11111100, B00000000,
  B00111111, B11111100, B00000000,
  B01110011, B11001110, B00000000,
  B01110011, B11001110, B00000000,
  B01110011, B11001110, B00000000,
  B01111111, B11111110, B00000000,
  B00110111, B11101100, B00000000,
  B00111000, B00011100, B00000000,
  B00011111, B11111000, B00000000,
  B00001111, B11110000, B00000000,
  B00000011, B11000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char face_angry[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000011, B11000000, B00000000,
  B00001111, B11110000, B00000000,
  B00011111, B11111000, B00000000,
  B00111111, B11111100, B00000000,
  B00111111, B11111100, B00000000,
  B01111111, B11111110, B00000000,
  B01100011, B11000110, B00000000,
  B01110001, B10001110, B00000000,
  B01110011, B11001110, B00000000,
  B00111111, B11111100, B00000000,
  B00111100, B00111100, B00000000,
  B00011011, B11011000, B00000000,
  B00001111, B11110000, B00000000,
  B00000011, B11000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};
const unsigned char face_sad[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000011, B11000000, B00000000,
  B00001111, B11110000, B00000000,
  B00011111, B11111000, B00000000,
  B00111111, B11111100, B00000000,
  B00111101, B10111100, B00000000,
  B01100011, B11000110, B00000000,
  B01110011, B11001110, B00000000,
  B01111111, B11111110, B00000000,
  B01111000, B00011110, B00000000,
  B00110111, B11101100, B00000000,
  B00111111, B11111100, B00000000,
  B00011111, B11111000, B00000000,
  B00001111, B11110000, B00000000,
  B00000011, B11000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char face_laugh[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000011, B11000000, B00000000,
  B00001111, B11110000, B00000000,
  B00011111, B11111000, B00000000,
  B00111111, B11111100, B00000000,
  B00110011, B11001100, B00000000,
  B01100011, B11000110, B00000000,
  B01111111, B11111110, B00000000,
  B01110000, B00001110, B00000000,
  B01110000, B00001110, B00000000,
  B00110011, B11001100, B00000000,
  B00111000, B00011100, B00000000,
  B00011111, B11111000, B00000000,
  B00001111, B11110000, B00000000,
  B00000011, B11000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};


/*Level Editor Info

   GridTile(*[n])) where n is the number of columns
   new GridTile[n]{} - where n is the number of blocks in that row
   Specific tiles are created by assigning names to them
   gridLevel->timer is the time limit for beating the evel
   SetValues(numColumns, numRows, level_tiles, playerStartX, playerStartY) - if playerStarPos is not defined he will start at 0-0 of the grid
  D - death, P - points, E - end, S - sticky, Two tiles with the same number are used as teleports e.g. 1-1, 2-2, etc..
*/

Grid* currentGrid;
Grid* LoadLevel(int level)
{
  delete currentGrid;
  currentGrid = NULL;
  Grid* gridLevel = new Grid();
  if (level == 1)
  {
    GridTile** level_tiles = new (GridTile(*[3])) {
      new GridTile[3] {},
          new GridTile[3] {},
          new GridTile[3] {},
    };

    level_tiles[2][2].name = 'D';
    level_tiles[1][2].name = 'E';
    gridLevel->timer = 30000;
    gridLevel->SetValues(3, 3, level_tiles);
  }
  else if (level == 2)
  {
    GridTile** level_tiles = new (GridTile(*[4])) {
      new GridTile[4] {},
          new GridTile[4] {},
          new GridTile[4] {},
          new GridTile[4] {},
    };
    level_tiles[0][3].isOpen = false;
    level_tiles[1][0].isOpen = false;

    level_tiles[3][3].name = 'P';
    level_tiles[0][2].name = 'D';
    level_tiles[0][0].name = 'E';
    gridLevel->timer = 20000;
    gridLevel->SetValues(4, 4, level_tiles);
  }
  else if (level == 3)
  {
    GridTile** level_tiles = new (GridTile(*[7])) {
      new GridTile[8] {},
          new GridTile[8] {},
          new GridTile[8] {},
          new GridTile[8] {},
          new GridTile[8] {},
          new GridTile[8] {},
    };
    level_tiles[2][0].isOpen = false;
    level_tiles[1][2].isOpen = false;

    level_tiles[2][2].name = 'P';
    level_tiles[1][5].name = 'E';

    gridLevel->timer = 30000;
    gridLevel->SetValues(7, 6, level_tiles, 3, 3);
  }
  else if (level == 4)
  {
    GridTile** level_tiles = new (GridTile(*[8])) {
      new GridTile[8] {},
          new GridTile[8] {},
          new GridTile[8] {},
          new GridTile[8] {},
          new GridTile[8] {},
          new GridTile[8] {},
          new GridTile[8] {},
          new GridTile[8] {},
    };
    level_tiles[6][1].isOpen = false;
    level_tiles[0][0].name = 'P';
    level_tiles[7][7].name = 'P';
    level_tiles[2][3].name = 'D';
    level_tiles[3][3].name = 'S';

    level_tiles[2][4].name = 'E';
    gridLevel->timer = 20000;
    gridLevel->SetValues(8, 8, level_tiles, 6, 2);
  }
  else if (level == 5)
  {
    GridTile** level_tiles = new (GridTile(*[5])) {
      new GridTile[6] {},
          new GridTile[6] {},
          new GridTile[6] {},
          new GridTile[6] {},
          new GridTile[6] {}
    };
    level_tiles[1][1].isOpen = false; level_tiles[4][0].isOpen = false; level_tiles[4][4].isOpen = false;

    level_tiles[1][5].name = 'S';
    level_tiles[3][3].name = 'D';

    level_tiles[4][1].name = 'E';
    gridLevel->timer = 20000;
    gridLevel->SetValues(6, 5, level_tiles, 3, 4);
  }
  else if (level == 6)
  {
    GridTile** level_tiles = new (GridTile(*[6])) {
      new GridTile[6] {},
          new GridTile[6] {},
          new GridTile[6] {},
          new GridTile[6] {},
          new GridTile[6] {},
          new GridTile[6] {},
    };
    level_tiles[1][2].isOpen = false;
    level_tiles[2][0].isOpen = false;
    level_tiles[4][2].isOpen = false;
    level_tiles[4][4].isOpen = false;

    level_tiles[3][3].name = '1';
    level_tiles[5][3].name = '1';

    level_tiles[2][2].name = 'E';
    gridLevel->timer = 30000;
    gridLevel->SetValues(6, 6, level_tiles, 0, 2);
  }
  else if (level == 7)
  {
    GridTile** level_tiles = new (GridTile(*[7])) {
      new GridTile[7] {},
          new GridTile[7] {},
          new GridTile[7] {},
          new GridTile[7] {},
          new GridTile[7] {},
          new GridTile[7] {},
          new GridTile[7] {},
    };
    level_tiles[0][6].isOpen = false; level_tiles[3][6].isOpen = false;
    level_tiles[3][2].isOpen = false; level_tiles[6][1].isOpen = false;

    level_tiles[6][0].name = '1';
    level_tiles[5][6].name = '1';

    level_tiles[5][5].name = 'D';

    level_tiles[3][3].name = 'E';
    gridLevel->timer = 20000;
    gridLevel->SetValues(7, 7, level_tiles, 6, 6);
  }
  else if (level == 8)
  {
    GridTile** level_tiles = new (GridTile(*[9])) {
      new GridTile[9] {},
          new GridTile[9] {},
          new GridTile[9] {},
          new GridTile[9] {},
          new GridTile[9] {},
          new GridTile[9] {},
          new GridTile[9] {},
          new GridTile[9] {},
          new GridTile[9] {},
    };
    level_tiles[0][4].isOpen = false; level_tiles[5][4].isOpen = false;
    level_tiles[1][4].isOpen = false; level_tiles[6][4].isOpen = false;
    level_tiles[2][4].isOpen = false; level_tiles[7][4].isOpen = false;
    level_tiles[3][4].isOpen = false; level_tiles[8][4].isOpen = false;
    level_tiles[4][4].isOpen = false;

    level_tiles[2][1].isOpen = false; level_tiles[3][3].isOpen = false;
    level_tiles[5][0].isOpen = false; level_tiles[6][0].isOpen = false; level_tiles[6][2].isOpen = false;

    level_tiles[2][5].isOpen = false; level_tiles[2][7].isOpen = false; level_tiles[2][8].isOpen = false;

    level_tiles[6][3].name = '1';
    level_tiles[4][7].name = '1';

    level_tiles[6][7].name = 'D';
    level_tiles[1][3].name = 'D';

    level_tiles[5][8].name = 'S'; level_tiles[5][6].name = 'S';
    level_tiles[7][6].name = 'P'; level_tiles[3][5].name = 'P';



    level_tiles[0][7].name = 'E';
    gridLevel->timer = 20000;
    gridLevel->SetValues(9, 8, level_tiles, 2, 3);
  }
  else if (level == 9)
  {
    GridTile** level_tiles = new (GridTile(*[10])) {
      new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
    };

    level_tiles[0][1].isOpen = false; level_tiles[9][2].isOpen = false;
    level_tiles[5][3].isOpen = false; level_tiles[6][3].isOpen = false;
    level_tiles[1][6].isOpen = false; level_tiles[2][6].isOpen = false; level_tiles[9][6].isOpen = false;
    level_tiles[6][8].isOpen = false;  level_tiles[4][9].isOpen = false;

    level_tiles[4][3].name = '1'; level_tiles[8][3].name = '1';
    level_tiles[1][9].name = 'S'; level_tiles[8][4].name = 'S';
    level_tiles[9][7].name = 'D'; level_tiles[9][8].name = 'D'; level_tiles[7][9].name = 'D';

    level_tiles[1][7].name = 'P';  level_tiles[1][8].name = 'P';
    level_tiles[2][7].name = 'P';  level_tiles[2][8].name = 'P';  level_tiles[2][9].name = 'P';
    level_tiles[3][7].name = 'P';  level_tiles[3][8].name = 'P';  level_tiles[3][9].name = 'P';
    level_tiles[5][9].name = 'P';  level_tiles[6][9].name = 'P';
    level_tiles[9][3].name = 'P';  level_tiles[9][4].name = 'P';  level_tiles[9][5].name = 'P';

    level_tiles[9][9].name = 'E';
    gridLevel->timer = 30000;
    gridLevel->SetValues(10, 10, level_tiles, 0, 0);
  } else if (level == 10)
  {
    GridTile** level_tiles = new (GridTile(*[10])) {
      new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
          new GridTile[10] {},
    };

    level_tiles[6][0].isOpen = false; level_tiles[0][5].isOpen = false;

    level_tiles[3][8].isOpen = false; level_tiles[0][9].isOpen = false;
    level_tiles[2][7].isOpen = false; level_tiles[6][2].isOpen = false; level_tiles[4][8].isOpen = false;

    level_tiles[5][8].name = 'P';
    level_tiles[3][7].name = 'P';
    level_tiles[7][4].name = 'P';
    level_tiles[9][9].name = 'P';
    level_tiles[7][7].name = 'D';
    level_tiles[8][4].name = 'D';
    level_tiles[3][6].name = 'D';
    level_tiles[5][5].name = 'S';
    level_tiles[1][5].name = 'S';

    level_tiles[3][3].name = '1';
    level_tiles[4][7].name = '1';

    level_tiles[6][7].name = 'E';
    gridLevel->timer = 30000;
    gridLevel->SetValues(10, 10, level_tiles, 0, 0);
  }
  return gridLevel;
}

BodyPart player;
int playerGridPosX;
int playerGridPosY;

int scallingFactorX = 20;
int scallingFactorY = 20;

int currentLevel = 1;
bool isNextLevel = false;
bool isSticky = false;
int levelTimer = 10000;
int indicatorLevel = 0;
const int gridBorderOffset = 3;
void DrawGrid()
{
  scallingFactorX = 20;
  scallingFactorY = 20;
  tft.fillScreen(BLACK);

  for (int i = 0; i < 80; i++)
    tft.fillRect(random(0, screenWidth), random(0, screenHeight), random(0, 4), random(0, 4), 0x2944);

  currentGrid = LoadLevel(currentLevel);

  int wallSize = 2;

  //Center grid on the x and x position of screen
  int startingPosX = (screenWidth / 2) - ((scallingFactorX * currentGrid->dimX) / 2);
  int posX = startingPosX;
  int posY = (screenHeight / 2) - ((scallingFactorY * currentGrid->dimY) / 2) - (currentGrid->dimY - 2) * gridBorderOffset;

  //Setting the start pos of player visual
  playerGridPosX = (currentGrid->pX * scallingFactorX) + posX + (scallingFactorX / 2) + (currentGrid->pX * gridBorderOffset);
  playerGridPosY = (currentGrid->pY * scallingFactorY) + posY + (scallingFactorY / 2) + (currentGrid->pY * gridBorderOffset);

  uint16_t interactableColor;

  for (int i = 0; i < currentGrid->dimY; i++)
  {
    for (int j = 0; j < currentGrid->dimX; j++)
    {
      if (currentGrid->gridTiles[i][j].isOpen)
      {
        tft.fillRect(posX, posY, scallingFactorX, scallingFactorY, 0x4208);
        delay(50);

        if (currentGrid->gridTiles[i][j].name == 'E')          //END
        {
          tft.drawBitmap(posX + 4, posY + 2, house, 17, 17, BROWN);
        }
        else if (currentGrid->gridTiles[i][j].name == 'D')          //DEATH
        {
          tft.fillRect(posX, posY, scallingFactorX, scallingFactorY, 0x4208);
          tft.drawBitmap(posX + 2, posY + 2, ghost, 17, 17, WHITE);
        }
        else if (currentGrid->gridTiles[i][j].name == 'P')          //POINTS
        {
          tft.drawBitmap(posX + 2, posY + 2, money, 17, 17, YELLOW);
        }
        else if (currentGrid->gridTiles[i][j].name == 'S')          //STICKY
        {
          tft.drawBitmap(posX + 2, posY + 2, stickyTile, 17, 17, WHITE);
        }
        else if (isDigit(currentGrid->gridTiles[i][j].name))
        {
          tft.drawBitmap(posX + 4, posY + 2, teleport, 17, 17, MAGENTA);
        }
      }
      else
      {
        delay(50);
      }
      posX += scallingFactorX + gridBorderOffset;
    }
    posY += scallingFactorY + gridBorderOffset;
    posX = startingPosX;
  }
  scallingFactorX = 23;
  scallingFactorY = 23;

  Serial.println(scallingFactorX - gridBorderOffset);

  //Setting the player start location and marking it as occupied
  player.positionX = currentGrid->pX;
  player.positionY = currentGrid->pY;
  currentGrid->gridTiles[player.positionY][player.positionX].isOpen = false;
  //--------------------------------------------------------------
  UpdateScore(0);
  UpdateGraphics();

  tft.setCursor(5, 20);
  tft.print("Score:");

  tft.drawRect(20, 50, 10, 100, WHITE);
  tft.fillRect(21, 51, 8, 98, YELLOW);

  levelTimer = currentGrid->timer;
  indicatorLevel = 0;
}

void StartPacman()
{
  score = 0;
  currentLevel = 1;
  DrawGrid();
  isRunning = true;

  String tempVal;
  unsigned int indicatorTimer = 0;
  while (isRunning)
  {
    int deltaTime = CalculateDeltaTime();
    indicatorTimer += deltaTime;

    String tempVal = CheckAnalogInputs();
    if (tempVal != NONE)
    {
      InputLogic(tempVal);
    }

    if (indicatorTimer > 2000)
    {
      UpdateIndicator();
      indicatorTimer = 0;

      UpdateTimer();
      tft.fillRect(21, 51, 8, 100 - (currentGrid->timer / levelTimer) * 100, BLACK);
    }
  }
  currentEvent = &GameOver;
  currentEventArgs.fileName = WORMS;
  currentEventArgs.score = score;
}

void InputLogic(String input)
{
  if (input == LEFT)
    CollisionCheck(0);
  else if (input == RIGHT)
    CollisionCheck(1);
  else if (input == UP)
    CollisionCheck(2);
  else if (input == DOWN)
    CollisionCheck(3);

  delay(500);
}

void CollisionCheck(int dir)
{
  //Off Grid Constraints
  if ((player.positionX <= 0 && dir == 0) || (player.positionX >= currentGrid->dimX - 1 && dir == 1) || (player.positionY <= 0 && dir == 2) || (player.positionY >= currentGrid->dimY - 1 && dir == 3))
    return;

  //int inverseDir = dir ^ 1; bit operator
  int dc[4] = { -1, 1, 0, 0};
  int dr[4] = {0, 0, -1, 1};

  bool isDeadEnd = true;//Checking if player hit a dead end path
  for (int i = 0; i < 4; i++)
  {
    int tempX = player.positionX + dc[i];
    int tempY = player.positionY + dr[i];
    if ((tempX < 0 || tempX > currentGrid->dimX - 1) || (tempY < 0 || tempY > currentGrid->dimY - 1))
      continue;

    if (currentGrid->gridTiles[tempY][tempX].isOpen)
      isDeadEnd = false;
  }
  if (isDeadEnd)
  {
    isRunning = false;
    return;
  }

  int graphicScaleX[4] = { -scallingFactorX, scallingFactorX, 0, 0};
  int graphicScaleY[4] = {0, 0, -scallingFactorY, scallingFactorY};

  int posY = player.positionY + dr[dir];
  int posX = player.positionX + dc[dir];

  if (currentGrid->gridTiles[posY][posX].isOpen)
  {
    ButtonSelectSFX();
    currentGrid->gridTiles[posY][posX].isOpen = false;

    //Changing player position and graphic position to next tile
    player.positionX += dc[dir];
    player.positionY += dr[dir];
    MovePlayer(graphicScaleX[dir], graphicScaleY[dir]);

    //Collision check for object-specific types
    CollisionCheckTile(currentGrid->gridTiles[posY][posX]);

    if (!isNextLevel && !isSticky)
      CollisionCheck(dir);

    if (isNextLevel)
      NextLevel();
    if (isSticky)
      isSticky = false;
  }
}

void CollisionCheckTile(GridTile temp)
{
  if (temp.name == 'E')
    isNextLevel = true;
  else if (temp.name == 'D')
  {
    isSticky = true;
    isRunning = false;
  }
  else if (temp.name == 'P')
  {
    UpdateScore(2);
    tft.fillCircle( playerGridPosX, playerGridPosY, 8, WHITE);
  }
  else if (isdigit(temp.name))
    Teleport(temp);
  else if (temp.name == 'S')
    isSticky = true;
}

void Teleport(GridTile temp)
{
  for (int i = 0; i < currentGrid->dimY; i++)
  {
    for (int j = 0; j < currentGrid->dimX; j++)
    {
      if (i == player.positionY && j == player.positionX)
        continue;
      if (currentGrid->gridTiles[i][j].name == temp.name)
      {
        int offsetX = (player.positionX > j) ? (player.positionX - j) * scallingFactorX : (j - player.positionX ) * -scallingFactorX;
        int offsetY = (player.positionY > i) ? (player.positionY - i) * scallingFactorY : (i - player.positionY) * -scallingFactorY;

        player.positionX = j;
        player.positionY = i;

        playerGridPosX -= offsetX;
        playerGridPosY -= offsetY;

        currentGrid->gridTiles[i][j].isOpen = false;
        UpdateGraphics();
        return;
      }
    }
  }
}

void UpdateScore(int x)
{
  tft.setTextSize(1);

  tft.setTextColor(BLACK);
  tft.setCursor(50, 20);
  tft.print(score);
  score += x;
  tft.setTextColor(YELLOW);
  tft.setCursor(50, 20);
  tft.print(score);

  Collect_SFX();
}

void NextLevel()
{
  NewHighscore_SFX();
  isNextLevel = false;
  currentLevel++;
  UpdateScore(currentLevel * 2);

  if (currentLevel == 11)
    CompletedGame();
  else DrawGrid();
}

void UpdateTimer()
{
  currentGrid->timer -= 1000;
  if (currentGrid->timer <= 0)
    isRunning = false;
}

void UpdateIndicator()
{
  tft.setCursor(40, 200);
  tft.setTextSize(1);
  tft.setTextColor(WHITE);

  tft.fillRect(0, 200, 100, 20, BLACK);

  float timer = (currentGrid->timer / levelTimer) * 100;

  if (timer <= 20 && indicatorLevel == 3)
  {
    tft.drawBitmap(20, 200, face_sad, 17, 17, WHITE);
    tft.println("Please win");
    indicatorLevel++;
  }
  else if (timer <= 50 && indicatorLevel == 2)
  {
    tft.drawBitmap(20, 200, face_angry, 17, 17, WHITE);
    tft.println("Hurry up!");
    indicatorLevel++;
  }
  else if (timer <= 70 && indicatorLevel == 1)
  {
    tft.drawBitmap(20, 200, face_smile, 17, 17, WHITE);
    tft.println("Hmm..");
    indicatorLevel++;
  }
  else if (timer <= 100 && indicatorLevel == 0)
  {
    tft.drawBitmap(20, 200, face_laugh, 17, 17, WHITE);
    tft.println("Good Luck!");
    indicatorLevel++;
  }
}

void CompletedGame()
{
  tft.fillScreen(BLACK);

  for (int i = 0; i < 80; i++)
    tft.fillRect(random(0, screenWidth), random(0, screenHeight), random(0, 4), random(0, 4), 0x2944);

  tft.setTextColor(YELLOW);
  tft.setTextSize(2);
  tft.setCursor(110, 40);
  tft.print("Congratulations!");

  tft.setTextSize(1);
  tft.setCursor(100, 80);
  tft.print("You have completed all of the levels");

  tft.setCursor(50, 160);
  tft.setTextColor(GREEN);
  tft.print("You will be redirected to the GameOver page shortly..");
  isRunning = false;
  GameCompleted_SFX();

  delay(7000);
}

void UpdateGraphics() {
  tft.fillCircle( playerGridPosX + 2, playerGridPosY + 2, 3, BLACK);
  tft.fillCircle( playerGridPosX, playerGridPosY, 3, WHITE);
  tft.drawPixel( playerGridPosX, playerGridPosY, BLACK);
  tft.drawPixel( playerGridPosX + 5, playerGridPosY, BLACK);
}
void MovePlayer(int x1, int x2)
{
  int absX = abs(x1);
  int absY = abs(x2);

  while (absX != 0)
  {
    if (x1 < 0)
      playerGridPosX--;
    else playerGridPosX++;

    UpdateGraphics();
    absX--;
    delay(2);
  }
  while (absY != 0)
  {
    if (x2 < 0)
      playerGridPosY--;
    else playerGridPosY++;

    UpdateGraphics();
    absY--;
    delay(2);
  }
}
