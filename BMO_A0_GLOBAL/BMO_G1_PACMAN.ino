Grid* currentGrid;
Grid* LoadLevel(int level)
{
  delete currentGrid;
  currentGrid = NULL;
  Grid* gridLevel = new Grid();
  if (level == 1)
  {
    GridTile** level_tiles = new (GridTile(*[4])) {
      new GridTile[4] {},
          new GridTile[4] {},
          new GridTile[4] {},
          new GridTile[4] {}
    };
    gridLevel->SetValues(4, 4, level_tiles, 5);
  }
  return gridLevel;
}

BodyPart player;
int playerGridPosX;
int playerGridPosY;

int scallingFactorX = 30;
int scallingFactorY = 30;

int currentLevel = 1;
void DrawGrid()
{
  currentGrid = LoadLevel(currentLevel);

  int wallSize = 2;
  uint16_t wallColor = BLACK;

  //Center grid on the x and x position of screen
  int startingPosX = (screenWidth / 2) - ((scallingFactorX * currentGrid->dimX) / 2);
  int posX = startingPosX;
  int posY = (screenHeight / 2) - ((scallingFactorY * currentGrid->dimY) / 2);


  //Setting the start pos of player
  playerGridPosX = startingPosX + (scallingFactorX / 2);
  playerGridPosY = ((currentGrid->dimY - 1) * posY) + (scallingFactorY / 2) - scallingFactorY;

  player.positionX = 0;
  player.positionY = currentGrid->dimY - 1;

  DrawPlayer(playerGridPosX, playerGridPosY, 7, wallColor);

  for (int i = 0; i < currentGrid->dimY; i++)
  {
    for (int j = 0; j < currentGrid->dimX; j++)
    {
      if (currentGrid->gridTiles[i][j].isOpen)
      {
        tft.drawRect(posX, posY, scallingFactorX, scallingFactorY, wallColor);

        //Drawing the walls of inside tiles
        if (currentGrid->gridTiles[i][j].wall[0] == 1)
          tft.fillRect(posX - wallSize, posY, wallSize * 2, scallingFactorY, wallColor);
        if (currentGrid->gridTiles[i][j].wall[2] == 1)
          tft.fillRect(posX, posY - wallSize, scallingFactorX, wallSize * 2, wallColor);
        if (currentGrid->gridTiles[i][j].wall[1] == 1)
          tft.fillRect(scallingFactorX + posX - wallSize, posY, wallSize * 2, scallingFactorY, wallColor);
        if (currentGrid->gridTiles[i][j].wall[3] == 1)
          tft.fillRect(posX, posY + scallingFactorY - wallSize, scallingFactorX, wallSize * 2, wallColor);
        delay(100);
      }
      posX += scallingFactorX;
    }
    posY += scallingFactorY;
    posX = startingPosX;
  }
}

void StartPacman()
{
  tft.fillScreen(WHITE);

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
      UpdateGameLogic();
    }
  }
}

void InputLogic(String input)
{
  if (input == LEFT && player.positionX > 0)
    CollisionCheck(0);
  else if (input == RIGHT && player.positionX < currentGrid->dimX - 1)
    CollisionCheck(1);
  else if (input == UP && player.positionY > 0)
    CollisionCheck(2);
  else if (input == DOWN && player.positionY < currentGrid->dimY - 1)
    CollisionCheck(3);

  delay(500);
}

void CollisionCheck(int dir)
{
  int inverseDir = dir ^ 1;
  int dc[4] = { -1, 1, 0, 0};
  int dr[4] = {0, 0, -1, 1};

  int graphicScaleX[4] = { -scallingFactorX, scallingFactorX, 0, 0};
  int graphicScaleY[4] = {0, 0, -scallingFactorY, scallingFactorY};

  int posY = player.positionY + dr[dir];
  int posX = player.positionX + dc[dir];

  //If next tile is open && current one does not contain a wall in that dir && the next tile does not contain a wall in the opposite dir
  if (currentGrid->gridTiles[posY][posX].isOpen && currentGrid->gridTiles[posY - dr[dir]][posX - dc[dir]].wall[dir] != 1 && currentGrid->gridTiles[posY][posX].wall[inverseDir] != 1)
  {
    player.positionX += dc[dir];
    player.positionY += dr[dir];

    DrawPlayer(playerGridPosX, playerGridPosY, 7, WHITE);
    playerGridPosX += graphicScaleX[dir];
    playerGridPosY += graphicScaleY[dir];

    UpdateGameLogic();
  }
}

void UpdateGameLogic()
{
  //Updating the possible grid moves
  currentGrid->gridMoves--;

  UpdateGraphics();
}

void UpdateGraphics()
{
  DrawPlayer(playerGridPosX, playerGridPosY, 7, BLACK );
}

void DrawPlayer(int x, int y, int radius, uint16_t color)
{
  tft.fillCircle( x, y, radius, color);
}
