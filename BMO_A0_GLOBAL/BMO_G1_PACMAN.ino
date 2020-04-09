Grid* currentGrid;
Grid* LoadLevel(int level)
{
  delete currentGrid;
  currentGrid = NULL;
  Grid* gridLevel = new Grid();
  if (level == 3)
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
  else if (level == 1)
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
void DrawGrid()
{
  tft.fillScreen(0xFFDD);

  currentGrid = LoadLevel(currentLevel);

  int wallSize = 2;
  uint16_t wallColor = 0xFFDD;
  const int gridBorderOffset = 3;

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
        tft.fillRect(posX, posY, scallingFactorX, scallingFactorY, 0xD678);
        delay(50);

        if (currentGrid->gridTiles[i][j].name == 'E')
          interactableColor = 0x7E69;
        else if (currentGrid->gridTiles[i][j].name == 'D')
          interactableColor = 0xD286;
        else if (currentGrid->gridTiles[i][j].name == 'P')
          interactableColor = 0xF58E;
        else if (isDigit(currentGrid->gridTiles[i][j].name))
          interactableColor = MAGENTA;
        else interactableColor = 0;

        if (interactableColor != 0)
          tft.fillRect(posX, posY, scallingFactorX, scallingFactorY, interactableColor);
      }
      else
      {
        tft.fillRect(posX, posY, scallingFactorX, scallingFactorY, 0x8C0F);
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
    if((tempX < 0 || tempX > currentGrid->dimX -1)|| (tempY < 0 || tempY > currentGrid->dimY -1))
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
    if (!isdigit(currentGrid->gridTiles[posY][posX].name))
      currentGrid->gridTiles[posY][posX].isOpen = false; //OVO MALO POGLEDATI

    //Changing player position and graphic position to next tile
    player.positionX += dc[dir];
    player.positionY += dr[dir];
    MovePlayer(graphicScaleX[dir], graphicScaleY[dir]);

    //Collision check for object-specific types
    CollisionCheckTile(currentGrid->gridTiles[posY][posX]);
    CollisionCheck(dir);
  }
}

void CollisionCheckTile(GridTile temp)
{
  if (temp.name == 'E')
    NextLevel();
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

        //currentGrid->gridTiles[i][j].isOpen = false; PORADITI NA OVOM DA TP MOZEMO 2 PUTA AKTIVIRATI
        UpdateGraphics();
        return;
      }
    }
  }
}

void UpdateScore(int x)
{
  tft.setTextSize(1);

  tft.setTextColor(WHITE);
  tft.setCursor(50, 20);
  tft.print(score);
  score += x;
  tft.setTextColor(BLACK);
  tft.setCursor(50, 20);
  tft.print(score);
}

void NextLevel()
{
  currentLevel++;
  DrawGrid();
}

void UpdateGraphics() {
  tft.fillCircle( playerGridPosX, playerGridPosY, 2, WHITE);
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
