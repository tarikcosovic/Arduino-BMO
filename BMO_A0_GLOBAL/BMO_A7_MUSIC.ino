struct Playlist
{
  String songs[15];
  String playlistName;
};

int currentPlaylist = 0;
int currentSong = 1;
int currentRowMusic = 0;
int currentlyPlayingSong = -1;
Playlist playlists[1];
String songName[1][15] {"Undertale", "Zelda", "Super Mario Bros", "Twisted Metal", "Silver Surfer", "Kirby", "Tetris", "Mega Man 2", "F-Zero", "Spyro", "Final Fantasy VII", "Duke Nukem", "Cuphead", "Donkey Kong", "Crash Team Racing"};

int selectedSongX = 10;
int selectedSongY = 80;
void MusicMenu()
{
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  DrawButtonsMusic();

  Playlist games;
  for (int i = 1; i <= 15; i++)
    games.songs[i - 1] = "G" + (String)i;
  games.playlistName = "Game Themes";

  playlists[0] = games;

  LoadPlaylist();

}

void LoadPlaylist()
{
  tft.fillRect(0, 0, 400, 150, BLACK);

  tft.setCursor(130, 20);
  tft.setTextSize(2);
  tft.setTextColor(YELLOW);
  tft.print(playlists[currentPlaylist].playlistName);

  tft.setTextSize(1);
  tft.setTextColor(WHITE);
  int posY = 60;
  int posX = 20;

  for (int j = 0; j < 3; j++)
  {
    for (int i = 0 ; i < 5; i++)
    {
      tft.setCursor(posX, posY);
      tft.print(songName[currentPlaylist][i + (j * 5)]);
      posY += 20;
    }
    posY = 60;
    posX += 125;
  }
  MusicEventLoop();
}

void MusicEventLoop()
{
  isRunning = true;

  String tempVal;
  String tempVal2;
  unsigned int timer = 0;

  DrawSelectedSong(UP);

  while (isRunning)
  {
    tempVal = CheckAnalogInputs();
    tempVal2 = CheckButtonInputs();

    if (tempVal == DOWN)
      DrawSelectedSong(DOWN);
    else if (tempVal == UP)DrawSelectedSong(UP);

    if (tempVal2 != NONE)
      CheckMusicButtons(tempVal2);
  }
}

void CheckMusicButtons(String temp)
{
  tft.setTextSize(1);
  String playingSong;
  if (temp == BLUEBUTTON)
  {
    if (currentlyPlayingSong == currentSong)
    {
      tmrpcm.pause();
    }
    else
    {
      String str = (String)playlists[currentPlaylist].songs[currentSong] + ".wav";
      const char *cstr = str.c_str();
      tmrpcm.play(cstr);

      tft.setCursor(21, 190);
      tft.setTextColor(BLACK);
      playingSong = "Playing: " + songName[currentPlaylist][currentlyPlayingSong];
      tft.print(playingSong);

      currentlyPlayingSong = currentSong;
      playingSong = "Playing: " + songName[currentPlaylist][currentlyPlayingSong];

      tft.setCursor(21, 190);
      tft.setTextColor(YELLOW);
      tft.print(playingSong);
    }
  }
  else if (temp == REDBUTTON)
  {
    //UGASITI MUZIKU I UPALITI DEFAULT
    BMOMenu();
  }

  delay(500);
}

void DrawSelectedSong(String temp)
{
  tft.fillCircle(selectedSongX, selectedSongY + 2, 2, BLACK);
  tft.setCursor(selectedSongX + 10, selectedSongY);
  tft.setTextColor(WHITE);
  tft.print(songName[currentPlaylist][currentSong]);

  if (temp == DOWN)
  {
    currentSong++;
    if (currentSong > 14)
      currentSong = 0;
  }
  else if (temp == UP)
  {
    currentSong--;
    if (currentSong < 0)
      currentSong = 14;
  }

  if (currentSong > 4)
    currentRowMusic = currentSong / 5;
  else currentRowMusic = 0;

  selectedSongY = (((1 + currentSong) * 20) + 40) - (currentRowMusic * 5 * 20);
  selectedSongX = 10 + (currentRowMusic * 125);

  tft.fillCircle(selectedSongX, selectedSongY + 2, 2, YELLOW);
  tft.setCursor(selectedSongX + 10, selectedSongY);
  tft.setTextColor(YELLOW);
  tft.print(songName[currentPlaylist][currentSong]);

  delay(200);
}

void DrawButtonsMusic()
{
  tft.fillScreen(BLACK);
  tft.drawLine(20, 180, 380, 180, WHITE);
  tft.setTextSize(1);

  tft.drawCircle(380, 216, 4, RED);
  tft.setCursor(345, 213);
  tft.setTextColor(RED);
  tft.print("exit");

  tft.drawCircle(325, 216, 4, BLUE);
  tft.setCursor(255, 213);
  tft.setTextColor(BLUE);
  tft.print("play/pause");

  tft.setCursor(21, 190);
  tft.setTextSize(1);
  tft.setTextColor(YELLOW);
  tft.print("Playing: ");
}
