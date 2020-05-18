//BITMAPS
const unsigned char deathBlock[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000011, B11100000, B00000000,
  B00001111, B11111000, B00000000,
  B00011111, B11111100, B00000000,
  B00011111, B11111100, B00000000,
  B00011110, B01100100, B00000000,
  B00011110, B01100100, B00000000,
  B00001111, B11111100, B00000000,
  B00000000, B11111000, B00000000,
  B00000110, B10101000, B00000000,
  B00000110, B01010000, B00000000,
  B00000111, B11111000, B00000000,
  B00000011, B11110000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char grass_01[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B01000000, B01000000, B00000000,
  B01100000, B11000010, B00000000,
  B00100000, B10000110, B00000000,
  B00000000, B00000100, B00000000,
  B00000100, B00010000, B00000000,
  B00000110, B00011000, B00000000,
  B00100010, B00001000, B00000000,
  B01100000, B00100000, B00000000,
  B01000000, B01100100, B00000000,
  B00000000, B01000110, B00000000,
  B00000010, B00000010, B00000000,
  B01000011, B00001000, B00000000,
  B01100001, B00011000, B00000000,
  B00100000, B00010000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char grass_02[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000001, B10000000, B00000000,
  B00000011, B11000000, B00000000,
  B00000011, B11000000, B00000000,
  B00000011, B11011000, B00000000,
  B00000011, B11011000, B00000000,
  B00000011, B11011000, B00000000,
  B00011011, B11011000, B00000000,
  B00011011, B11111000, B00000000,
  B00011011, B11110000, B00000000,
  B00011011, B11000000, B00000000,
  B00011111, B11000000, B00000000,
  B00001111, B11000000, B00000000,
  B00000011, B11000000, B00000000,
  B00000011, B11000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char grass_03[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000001, B10000000, B00000000,
  B00000001, B10000000, B00000000,
  B00000011, B11000000, B00000000,
  B00000011, B11000000, B00000000,
  B00000111, B11100000, B00000000,
  B00000011, B11000000, B00000000,
  B00000100, B00100000, B00000000,
  B00001111, B11110000, B00000000,
  B00000111, B11100000, B00000000,
  B00011000, B00011000, B00000000,
  B00011111, B11111000, B00000000,
  B00001111, B11110000, B00000000,
  B00000000, B00000000, B00000000,
  B00000001, B10000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char grass_04[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000000, B00010000, B00000000,
  B00000000, B00111000, B00000000,
  B00000000, B01111100, B00000000,
  B00001000, B01111100, B00000000,
  B00011100, B11111110, B00000000,
  B00111110, B11111110, B00000000,
  B00111110, B11111110, B00000000,
  B01111111, B01111110, B00000000,
  B01111111, B01111110, B00000000,
  B01111111, B01111110, B00000000,
  B01111111, B01111100, B00000000,
  B00111110, B00000000, B00000000,
  B00000000, B00010000, B00000000,
  B00001000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};
const unsigned char grass_05[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00110000, B00000000,
  B00000000, B00110000, B00000000,
  B00001100, B10110000, B00000000,
  B00001100, B10110100, B00000000,
  B00001100, B01110100, B00000000,
  B00001100, B00111000, B00000000,
  B00001101, B00110000, B00000000,
  B00101101, B00110000, B00000000,
  B00101110, B00000000, B00000000,
  B00101100, B00000000, B00000000,
  B00011100, B00000000, B00000000,
  B00001100, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char grass_06[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000000, B00100000, B00000000,
  B00001000, B00110010, B00000000,
  B00101010, B00010110, B00000000,
  B00000000, B00000100, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000100, B00001000, B00000000,
  B01001100, B00101010, B00000000,
  B01101000, B00000000, B00000000,
  B00100000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000001, B00000000, B00000000,
  B00000101, B01000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char grass_07[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B10000000, B00000000,
  B00001001, B00000000, B00000000,
  B00000101, B00000000, B00000000,
  B00000110, B00010000, B00000000,
  B00000010, B10100000, B00000000,
  B00000010, B01100000, B00000000,
  B00010010, B01001000, B00000000,
  B00001010, B01010000, B00000000,
  B00101010, B01010000, B00000000,
  B00001010, B01010100, B00000000,
  B00000010, B01010000, B00000000,
  B00000000, B01000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char *grass[7] = {grass_07, grass_02, grass_03, grass_04, grass_05, grass_06, grass_07};

const unsigned char dirt_01[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000001, B00000000, B00000000,
  B00000101, B01000000, B00000000,
  B00100000, B00000010, B00000000,
  B00110000, B00000000, B00000000,
  B00010001, B10001100, B00000000,
  B00000001, B11011100, B00000000,
  B00000000, B11011000, B00000000,
  B01000000, B01010000, B00000000,
  B00000000, B00000000, B00000000,
  B00000010, B00000000, B00000000,
  B00100110, B00000000, B00000000,
  B00110100, B00001000, B00000000,
  B00010000, B00001100, B00000000,
  B00000000, B10000100, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char dirt_02[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B01000001, B00000100, B00000000,
  B00001100, B01110000, B00000000,
  B00101100, B01110010, B00000000,
  B00000000, B01110000, B00000000,
  B00001011, B00000000, B00000000,
  B01100011, B00100110, B00000000,
  B01100000, B00000110, B00000000,
  B00001110, B01100000, B00000000,
  B00001110, B01101000, B00000000,
  B01001110, B00000000, B00000000,
  B00000000, B01000010, B00000000,
  B00111000, B00011000, B00000000,
  B00111000, B10011000, B00000000,
  B00111000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char dirt_03[] PROGMEM = {
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
const unsigned char dirt_04[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00001000, B00100000, B00000000,
  B00000011, B10000000, B00000000,
  B00011011, B10111000, B00000000,
  B00011011, B10111010, B00000000,
  B01011011, B10000000, B00000000,
  B00000000, B00111100, B00000000,
  B00111101, B10111100, B00000000,
  B00111101, B10111100, B00000000,
  B00111100, B00000000, B00000000,
  B00000001, B11011010, B00000000,
  B01011101, B11011000, B00000000,
  B00011101, B11011000, B00000000,
  B00000001, B11000000, B00000000,
  B00000100, B00010000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char dirt_05[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00100000, B00000000,
  B00000000, B01000000, B00000000,
  B00000010, B01000000, B00000000,
  B00000001, B01000000, B00000000,
  B00000001, B01001000, B00000000,
  B00001001, B01010000, B00000000,
  B00000101, B01010000, B00000000,
  B00100101, B01010100, B00000000,
  B00010101, B01010100, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char dirt_06[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00100000, B00000000, B00000000,
  B00100010, B00010000, B00000000,
  B01110100, B10100100, B00000000,
  B00111000, B01000100, B00000000,
  B00011101, B00101110, B00000000,
  B00101110, B00011100, B00000000,
  B01000111, B00111000, B00000000,
  B00001011, B11110000, B00000000,
  B00000001, B11101010, B00000000,
  B00101001, B11000100, B00000000,
  B00011101, B10010010, B00000000,
  B00000111, B10100000, B00000000,
  B00001011, B11110000, B00000000,
  B00000001, B11000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};
const unsigned char dirt_07[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000011, B11000000, B00000000,
  B00000100, B00100000, B00000000,
  B00000011, B11000000, B00000000,
  B00000101, B10100000, B00000000,
  B00000111, B11100000, B00000000,
  B00000011, B11000000, B00000000,
  B00001000, B00010000, B00000000,
  B00011111, B11111000, B00000000,
  B00010111, B11101000, B00000000,
  B00000000, B00000000, B00000000,
  B00010111, B11101000, B00000000,
  B00000100, B00100000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char *dirt[7] = {dirt_01, dirt_02, dirt_03, dirt_04, dirt_05, dirt_06, dirt_07};

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

const unsigned char flag[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B01010011, B11000000, B00000000,
  B00011111, B11110010, B00000000,
  B01011111, B11111110, B00000000,
  B00011111, B00111100, B00000000,
  B01001100, B00000000, B00000000,
  B01000000, B00000000, B00000000,
  B01000000, B00000000, B00000000,
  B01000000, B00000000, B00000000,
  B01000000, B00000000, B00000000,
  B01000000, B00000000, B00000000,
  B01000000, B00000000, B00000000,
  B01000000, B00000000, B00000000,
  B01000000, B00000000, B00000000,
  B01000000, B00000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};

const unsigned char money[] PROGMEM = {
  B00000000, B00000000, B00000000,
  B00000001, B10000000, B00000000,
  B00000001, B10000000, B00000000,
  B00000111, B11100000, B00000000,
  B00001111, B11110000, B00000000,
  B00001100, B00110000, B00000000,
  B00001100, B00000000, B00000000,
  B00001111, B11100000, B00000000,
  B00000111, B11110000, B00000000,
  B00000000, B00110000, B00000000,
  B00001100, B00110000, B00000000,
  B00001111, B11110000, B00000000,
  B00000111, B11100000, B00000000,
  B00000001, B10000000, B00000000,
  B00000001, B10000000, B00000000,
  B00000000, B00000000, B00000000,
  B00000000, B00000000, B00000000
};


const unsigned char teleport[] PROGMEM = {
  B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,
  B00000010,B01000000,B00000000,
  B00001001,B10010000,B00000000,
  B00000001,B10000000,B00000000,
  B00101101,B10110100,B00000000,
  B00001110,B01110000,B00000000,
  B00000111,B11100000,B00000000,
  B00010001,B10001000,B00000000,
  B00100101,B10100100,B00000000,
  B00100011,B11000100,B00000000,
  B00100001,B10000100,B00000000,
  B00011000,B00011000,B00000000,
  B00000111,B11100000,B00000000,
  B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000,
  B00000000,B00000000,B00000000
};




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
    gridLevel->SetValues(4, 4, level_tiles);
  }
  else if (level == 3)
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
    gridLevel->SetValues(6, 6, level_tiles, 0, 2);
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
const int gridBorderOffset = 3;
void DrawGrid()
{
  tft.fillScreen(BLACK); // OR BLACK

  for (int i = 0; i < 80; i++)
    tft.fillRect(random(0, screenWidth), random(0, screenHeight), random(0, 4), random(0, 4), 0x2944);

  currentGrid = LoadLevel(currentLevel);

  int wallSize = 2;
  uint16_t wallColor = DARKPURPLE;

  //Center grid on the x and x position of screen
  int startingPosX = (screenWidth / 2) - ((scallingFactorX * currentGrid->dimX) / 2);
  int posX = startingPosX;
  int posY = (screenHeight / 2) - ((scallingFactorY * currentGrid->dimY) / 2) - (currentGrid->dimY - 2) * gridBorderOffset;
  //DrawInitialEnvironment(posX, 25); UNCOMMENT IF YOU WANT TO DRAW BITMAPS!

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

        if (currentGrid->gridTiles[i][j].name == 'E')
        {
          //tft.fillRect(posX, posY, scallingFactorX, scallingFactorY, ORANGE);
          tft.drawBitmap(posX + 2, posY, flag, 17, 17, ORANGE);
        }
        else if (currentGrid->gridTiles[i][j].name == 'D')
        {
          tft.fillRect(posX, posY, scallingFactorX, scallingFactorY, 0x4208);
          tft.drawBitmap(posX + 2, posY, ghost, 17, 17, WHITE);
        }
        else if (currentGrid->gridTiles[i][j].name == 'P')
        {
          //POINTS
          //tft.fillRect(posX, posY, scallingFactorX, scallingFactorY, YELLOW);
          tft.drawBitmap(posX + 2, posY, money, 17, 17, GREEN);
        }
        else if (isDigit(currentGrid->gridTiles[i][j].name))
        {
          //TELEPORT
          //tft.fillRect(posX, posY, scallingFactorX, scallingFactorY, MAGENTA);
          tft.drawBitmap(posX + 2, posY, teleport, 17, 17, MAGENTA);

        }
        //else tft.fillRect(posX, posY, scallingFactorX, scallingFactorY, BROWN); UNCOMMENT IF YOU WANT WALLS OR SOMETHING
      }
      else
      {
        //tft.fillRect(posX, posY, scallingFactorX, scallingFactorY, 0x8C0F);
        delay(50);
      }
      posX += scallingFactorX + gridBorderOffset;
    }
    posY += scallingFactorY + gridBorderOffset;
    posX = startingPosX;
  }
  scallingFactorX += gridBorderOffset;
  scallingFactorY += gridBorderOffset;

  //Setting the player start location and marking it as occupied
  player.positionX = currentGrid->pX;
  player.positionY = currentGrid->pY;
  currentGrid->gridTiles[player.positionY][player.positionX].isOpen = false;
  //--------------------------------------------------------------
  UpdateScore(0);
  UpdateGraphics();

  tft.setCursor(5, 20);
  tft.print("Score:");
}

void StartPacman()
{
  score = 0;
  DrawGrid();
  isRunning = true;

  String tempVal;
  while (isRunning)
  {
    String tempVal = CheckAnalogInputs();
    if (tempVal != NONE)
    {
      InputLogic(tempVal);
    }
  }
  tft.fillScreen(RED);
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
    currentGrid->gridTiles[posY][posX].isOpen = false;

    //Changing player position and graphic position to next tile
    player.positionX += dc[dir];
    player.positionY += dr[dir];
    MovePlayer(graphicScaleX[dir], graphicScaleY[dir]);

    //Collision check for object-specific types
    CollisionCheckTile(currentGrid->gridTiles[posY][posX]);

    if (!isNextLevel)
      CollisionCheck(dir);
    else
    {
      isNextLevel = false;
      NextLevel();
    }
  }
}

void CollisionCheckTile(GridTile temp)
{
  if (temp.name == 'E')
    isNextLevel = true;
  else if (temp.name == 'D')
    isRunning = false;
  else if (temp.name == 'P')
    UpdateScore(2);
  else if (isdigit(temp.name))
    Teleport(temp);
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
}

void NextLevel()
{
  currentLevel++;
  UpdateScore(currentLevel * 2);
  DrawGrid();
}

void UpdateGraphics() {
  tft.fillCircle( playerGridPosX, playerGridPosY, 6, WHITE);
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

void DrawInitialEnvironment(int x, int y)
{
  int x1 = 0;
  int y1 = 0;
  int prefab = 0;
  int randPrefab = 0;
  for (int i = 0; i < 50; i++)
  {
    x1 = random(0, x - 10);
    y1 = random(0, screenHeight - 10);

    prefab = random(0, 7);

    randPrefab = random(0, 10);
    if (randPrefab > 3)
      tft.drawBitmap(x1, y1, *(grass + prefab), 17, 17, GREEN);
    else
      tft.drawBitmap(x1, y1, *(dirt + prefab), 17, 17, DARKBROWN);

    x1 = random(x + ((currentGrid->dimX * scallingFactorX) + (currentGrid->dimX * gridBorderOffset)), screenWidth - 17);
    y1 = random(0, screenHeight - 10);

    prefab = random(0, 7);

    randPrefab = random(0, 10);
    if (randPrefab > 3)
      tft.drawBitmap(x1, y1, *(grass + prefab), 17, 17, GREEN);
    else
      tft.drawBitmap(x1, y1, *(dirt + prefab), 17, 17, DARKBROWN);
  }
}
