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
