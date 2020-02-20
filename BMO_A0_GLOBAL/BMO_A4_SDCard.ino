//Examples of read - write to sd
//  ReadFromSDCard("snake");
//  WriteToSDCard("snake", "TEST", 15);

void ReadFromSDCard(String fileName) //category e.g. game/music/etc..
{
  file = SD.open(fileName + ".txt", FILE_READ);

  if (file)
  {
    char character;
    while ((character = file.read()) != -1) { // this while loop reads data stored in "file.txt" and prints it to serial monitor
      Serial.print(character);
    }
    file.close();
  }
  else
  {
    Serial.println("Could not open file (reading).");
  }
}

void WriteToSDCard(String fileName, String username, int score)
{
  file = SD.open(fileName + ".txt", FILE_WRITE); // open "file.txt" to write data

  if (file) {
    file.println(username + " " + (String)score); // write number to file
    file.close(); // close file
  } else {
    Serial.println("Could not open file (writing).");
  }
}

bool CheckForHighscore(String fileName, int score)
{
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
  }else {
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
  return newHighscore;
}

String GetHighscores(String fileName)
{
  file = SD.open(fileName + ".txt", FILE_READ);

  String highscoreList;
  int counter = 0;
  String list;
  if (file)
  {
    while (counter < 5)
    {
      list = file.readStringUntil('\n');
      highscoreList += list.substring(0, 5) + list.substring(5, 20);
      counter++;
    }
    file.close();
  }
  else
    Serial.println("Could not open file (reading).");

  return highscoreList;
}
