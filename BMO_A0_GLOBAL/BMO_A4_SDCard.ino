bool CheckForHighscore(String fileName, int score)
{
  tmrpcm.pause();
  file = SD.open(fileName + ".txt", FILE_READ);

  int highscores[5];
  String list;
  int counter = 0;
  if (file)
  {
    while (counter < 5)
    {

      list = file.readStringUntil('\n');

      highscores[counter] = list.substring(5, 20).toInt();
      counter++;
    }
    file.close();
    tmrpcm.pause();
  } else {
    Serial.println("Could not open file (writing).");
  }
  if (score > highscores[4])
    return true;
  return false;
}

bool SaveHighscoreToSDCard(String fileName, String username, int score)
{
  if (username.length() > 5 || username.length() == 0)return;
  else if (username.length() < 5)
    while (username.length() != 5)
      username += " ";

  tmrpcm.pause();
  file = SD.open(fileName + ".txt", FILE_READ);

  int highscores[5];
  String names[5];
  int counter = 0;
  bool newHighscore = false;
  String list;
  //Check for highscore and add into array of highscores if so
  if (file)
  {
    while (counter < 5)
    {

      list = file.readStringUntil('\n');

      names[counter] = list.substring(0, 5);
      highscores[counter] = list.substring(5, 20).toInt();
      counter++;
    }

    String tempName;
    int tempScore;
    for (int i = 4; i >= 0; i--)
    {
      if (score > highscores[i])
      {
        newHighscore = true;
        tempName = names[i];
        tempScore = highscores[i];
        if (i < 4)
        {
          names[i + 1] = tempName;
          highscores[i + 1] = tempScore;
        }

        highscores[i] = score;
        names[i] = username;
      } else break;
    }
    //Delete the file and create the file again and write the new highscore
    if (newHighscore)
    {
      file.close();
      SD.remove(fileName + ".txt");

      file = SD.open(fileName + ".txt", FILE_WRITE);
      file.close();

      if (SD.exists(fileName + ".txt"))
      {
        file = SD.open(fileName + ".txt", FILE_WRITE);
        if (file)
        {
          for (int i = 0; i < 5; i++)
          {
            file.println(names[i] + highscores[i]);
          }
        }
      }
    }

    file.close();
  } else {
    Serial.println("Could not open file (writing).");
  }
  tmrpcm.pause();
  return newHighscore;
}

String GetHighscores(String fileName)
{
  tmrpcm.pause();
  file = SD.open(fileName + ".txt", FILE_READ);

  String highscoreList;
  int counter = 0;
  String list;
  if (file)
  {
    while (counter < 5)
    {
      list = file.readStringUntil('\n');
      highscoreList += list.substring(0, 5) + list.substring(5, 20) + ":";
      counter++;
    }
    file.close();
  }
  else
    Serial.println("Could not open file (reading).");

  tmrpcm.pause();
  return highscoreList;
}
