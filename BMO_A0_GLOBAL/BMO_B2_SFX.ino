void ButtonSelectSFX()
{
  if (!sfxEnabled)
    return;

  tone(Buzzer_SFX, 988, 50);
}

void ButtonPressSFX()
{
  if (!sfxEnabled)
    return;

  tone(Buzzer_SFX, 1047, 50);
  delay(50);
  tone(Buzzer_SFX, 1480, 100);
}

void ShootSFX_v1()
{
  if (!sfxEnabled)
    return;

  tone(Buzzer_SFX, 2093, 50);
}

void DeathSFX_v1()
{
  if (!sfxEnabled)
    return;

  tone(Buzzer_SFX, 4435l, 100);
}

void EscapeSFX_v1()
{
  if (!sfxEnabled)
    return;

  tone(Buzzer_SFX, 329, 35);
  delay(45);
  tone(Buzzer_SFX, 440, 60);
}

void GameOver_v1()
{
  if (!sfxEnabled)
    return;

  tone(Buzzer_SFX, 174, 200);
  delay(250);
  tone(Buzzer_SFX, 87, 200);
  delay(250);
  tone(Buzzer_SFX, 36, 500);
}

void NewHighscore_SFX()
{
  if (!sfxEnabled)
    return;

  tone(Buzzer_SFX, 523, 100);
  delay(120);
  tone(Buzzer_SFX, 523, 100);
  delay(120);
  tone(Buzzer_SFX, 2093, 400);
}
