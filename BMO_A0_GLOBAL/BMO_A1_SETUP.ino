uint16_t g_identifier;

void setup(void) {

  //Serial. begin(9600); //For Debugging
  
  //BUTTON PINS
  pinMode(LeftButton, INPUT);     //LeftButton
  pinMode(RightButton, INPUT);     //RightButton
  
  g_identifier = tft.readID(); //0x9327
  
  tft.begin(g_identifier);
  tft.setRotation(1); //Sets the screen rotation to horizontal

  MainMenu();

}
