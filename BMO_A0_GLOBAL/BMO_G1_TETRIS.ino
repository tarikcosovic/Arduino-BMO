
//int screenWidth = tft.height(); //We map the height to width and vice versa, because our device is rotated by 90 degrees due to working in landscape mode
//int screenHeight = tft.width(); 

int leftHorizontalBorder = (screenWidth / 4) + 25; // - 1 so the pieces don't overlap the border, thus 24 instead of 25
int rightHorizontalBorder = (screenWidth / 2) + 75;

bool hasStarted = true;

void TetrisSetup()
{
  tft.fillScreen(BLACK);
  
  tft.drawFastVLine( leftHorizontalBorder - 1 , 0, screenHeight, WHITE);
  tft.drawFastVLine( rightHorizontalBorder, 0, screenHeight, WHITE);
}

void StartTetris()
{

  TetrisSetup();

  //tft.drawRect(leftHorizontalBorder, 20, 30, 30, WHITE);

  tft.drawRect(leftHorizontalBorder + 30, 40, 15, 60, WHITE);

  tft.drawRect(leftHorizontalBorder + 45, 60, 15, 45, WHITE);
  tft.drawRect(leftHorizontalBorder + 60, 60, 15, 15, WHITE);

  tft.drawRect(leftHorizontalBorder + 75, 80, 15, 15, WHITE);
  tft.drawRect(leftHorizontalBorder + 90, 80, 15, 45, WHITE);

  int pos = -30;
  int lastPos;

  while(hasStarted)
  {
    if(pos < screenHeight - 30)
    {
    tft.drawRect(leftHorizontalBorder, pos, 30, 30, BLACK);
    pos += 15;
    tft.drawRect(leftHorizontalBorder, pos, 30, 30, WHITE);
    delay(500);
    tft.drawRect(leftHorizontalBorder, pos, 30, 30, BLACK);
    pos += 15;
    tft.drawRect(leftHorizontalBorder, pos, 30, 30, WHITE);
    delay(500);
    }
  }


}
