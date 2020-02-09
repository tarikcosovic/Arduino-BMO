uint16_t g_identifier;

void setup(void) {
  
  g_identifier = tft.readID(); //0x9327
  
  tft.begin(g_identifier);
  tft.setRotation(1); //Sets the screen rotation to horizontal

  MainMenu();
}
