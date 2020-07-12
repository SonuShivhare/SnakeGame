#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

const int xCount = 35;
const int yCount = 25;
const int size = 32;
const int window_Width = xCount * size;
const int window_Height = yCount * size;

#define Game_Title "Assets/images/SnakeGameTitle.png"
#define Snake_Game_Title_Speed 0.4
//sf::IntRect game_Title_Partition(sf::IntRect(0, 0, 900, 126));

#define Main_Manu_Play_Button "Assets/images/StartButton07.png"
#define Main_Manu_Quit_Button "Assets/images/QuitButton03.png"
#define Play_Button "Assets/images/PlayButton.png"
#define Pause_Button "Assets/images/PauseButton.png"
#define Home_Button "Assets/images/HomeButton.png"
#define Quit_Button "Assets/images/QuitButton.png"

#define Main_Menu_Red_Start_button sf::IntRect(0, 0, 250, 78)
#define Main_Menu_Blue_Start_button sf::IntRect(250, 0, 250, 78)
#define Main_Menu_Red_Quit_button sf::IntRect(0, 0, 200, 62)
#define Main_Menu_Blue_Quit_button sf::IntRect(200, 0, 200, 62)
#define Blue_button sf::IntRect(0, 0, 175, 175)
#define Green_button sf::IntRect(175, 0, 175, 175)
#define Yellow_button sf::IntRect(350, 0, 175, 175)

#define Main_Menu_Background "Assets/images/MainManuBackground01.png"
#define Level1_Background "Assets/images/Grass06.png"
#define GameOver_Background "Assets/images/GameOverBackground.png"
#define Common_Background "Assets/images/background.png"

#define Food_FilePath "Assets/images/redApple.png"

#define Snake_Segment_FilePath "Assets/images/SnakeSheet.png"

#define Font_FilePath "Assets/Fonts/a.ttf"
#define Arial_Font_FilePath "C:/Windows/Fonts/Arial.ttf"

#define Snake_Body sf::IntRect(0, 0, 32, 32)

#define Eating_Sound_FilePath "Assets/Audio/EatSound.ogg"