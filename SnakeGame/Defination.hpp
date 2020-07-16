#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

const int xCount = 35;
const int yCount = 25;
const int size = 32;
const int window_Width = xCount * size;
const int window_Height = yCount * size;

#define Game_Title "Assets/images/SnakeGameTitle.png"
#define Snake_Speed 0.1f
//sf::IntRect game_Title_Partition(sf::IntRect(0, 0, 900, 126));

#define Main_Manu_Play_Button "Assets/images/StartButton07.png"
#define Main_Manu_Quit_Button "Assets/images/QuitButton03.png"
#define Play_Button "Assets/images/PlayButton.png"
#define Pause_Button "Assets/images/PauseButton.png"
#define Level_Pause_Button "Assets/images/LevelPauseButton.png"
#define Home_Button "Assets/images/HomeButton.png"
#define Quit_Button "Assets/images/QuitButton.png"

#define Main_Menu_Red_Start_button sf::IntRect(0, 0, 250, 78)
#define Main_Menu_Blue_Start_button sf::IntRect(250, 0, 250, 78)
#define Main_Menu_Red_Quit_button sf::IntRect(0, 0, 200, 62)
#define Main_Menu_Blue_Quit_button sf::IntRect(200, 0, 200, 62)
#define Blue_button sf::IntRect(0, 0, 175, 175)
#define Green_button sf::IntRect(175, 0, 175, 175)
#define Yellow_button sf::IntRect(350, 0, 175, 175)
#define Level_Blue_button sf::IntRect(0, 0, 32, 32)
#define Level_Green_button sf::IntRect(32, 0, 32, 32)
#define Level_Yellow_button sf::IntRect(64, 0, 32, 32)

#define Main_Menu_Background "Assets/images/MainManuBackground01.png"
#define Level_01_Background_FilePath "Assets/images/Grass09.png"
#define Level_02_Background_FilePath "Assets/images/Grass03.png"
#define Level_03_Background_FilePath "Assets/images/Grass06.png"
#define Level_01_Wall_Border_FilePath "Assets/images/Wall02.png"
#define Level_02_Wall_Border_FilePath "Assets/images/Wall01.png"
#define Level_03_Wall_Border_FilePath "Assets/images/Wall03.png"
#define Game_Starting_Splash_Screen_Background_FilePath "Assets/images/Background04.jpg"
#define Game_Starting_Splash_Screen_Snake_Animation_FilePath "Assets/images/SnakeAnimation.png"
#define Level_01_Splash_Screen_Background_FilePath "Assets/images/level_01.png"
#define Level_02_Splash_Screen_Background_FilePath "Assets/images/level_02.png"
#define Level_03_Splash_Screen_Background_FilePath "Assets/images/level_03.png"
#define GameOver_Background "Assets/images/GameOverBackground.png"
#define Common_Background "Assets/images/background.png"

#define Food_FilePath "Assets/images/redApple.png"
#define Bonus_Food_FilePath "Assets/images/BonusFood.png"

#define Font_FilePath "Assets/Fonts/a.ttf"
#define Arial_Font_FilePath "C:/Windows/Fonts/Arial.ttf"


#define Eating_Sound_FilePath "Assets/Audio/EatSound.wav"
#define Turn_Sound_FilePath "Assets/Audio/Turn.wav"
#define Level_Up_Sound_FilePath "Assets/Audio/LevelUp.wav"
#define Wall_Hit_Sound_FilePath "Assets/Audio/WallHit.wav"
#define SnakeBody_hit_Sound_FilePath "Assets/Audio/SnakeHit.wav"

#define Snake_Segment_FilePath "Assets/images/SnakeSpriteSheet03.png"
#define Snake_Body sf::IntRect(0, 0, 32, 32)

#define headUp sf::IntRect(3*32, 0*32, 32, 32)
#define headDown sf::IntRect(4*32, 1*32, 32, 32)
#define headLeft sf::IntRect(3*32, 1*32, 32, 32)
#define headRight sf::IntRect(4*32, 0*32, 32, 32)
#define tailUp sf::IntRect(3*32, 2*32, 32, 32)
#define tailDown sf::IntRect(4*32, 3*32, 32, 32)
#define tailLeft sf::IntRect(3*32, 3*32, 32, 32)
#define tailRight sf::IntRect(4*32, 2*32, 32, 32)
#define turnUp sf::IntRect(0*32, 1*32, 32, 32)
#define turnDown sf::IntRect(2*32, 0*32, 32, 32)
#define turnLeft sf::IntRect(2*32, 2*32, 32, 32)
#define turnRight sf::IntRect(0*32, 0*32, 32, 32)
#define segmentH sf::IntRect(1*32, 0*32, 32, 32)
#define segmentV sf::IntRect(2*32, 1*32, 32, 32)

#define Bonus_Food_Generation_Speed 13
#define Bonus_Food_Duration_Level_01 8.0f
#define Bonus_Food_Duration_Level_02 8.0f
#define Bonus_Food_Duration_Level_03 8.0f
#define Bonus_Food_Initial_X_Position 55
#define Bonus_Food_Initial_Y_Position 55


