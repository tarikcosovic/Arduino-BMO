/*int sound[10]{300, 360, 250, 612, 125, 350, 362, 100, 800, 2000};
  int duration[10]{200, 100, 0, 20, 500, 120, 200, 530, 100,50};

  void loop(void) {
  for(int i = 0; i < 10; i++)
  {
    tone(Buzzer_SFX, sound[i], duration[i]); // (buzzer pin, sound frequency, duration)
    // You can also use noTone() to stop the sound it takes 1 parametere which is the buzzer pin
  }
  }
*/

void DrawBMO()
{
  tft.fillScreen(0xCFBA);
  tft.fillCircle(140, 60, 8, BLACK);
  tft.fillCircle(260, 60, 8, BLACK);
  tft.drawCircle(200, 100, 30, BLACK);
  tft.fillRect(170, 70, 60, 30, 0xCFBA);
}

void StartupConsole()
{
  delay(2000);
  tmrpcm.play("INTRO.wav");
}

void loop(void)
{
}
