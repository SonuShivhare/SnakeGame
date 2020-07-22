#include "HighestScore.hpp"

HighestScore::HighestScore()
{
}

HighestScore::~HighestScore()
{
}

void HighestScore::storePlayerScore(int playerCurrentScore)
{
	out_file_PlayerScore.open("Assets/Score/PlayerScore.txt");
	out_file_PlayerScore << playerCurrentScore << std::endl;
	out_file_PlayerScore.close();
}

int HighestScore::returnHighestScore()
{
	in_file_HighScore.open("Assets/Score/HighestScore.txt");
	in_file_HighScore >> highScore;
	in_file_HighScore.close();
	return highScore;
}

int HighestScore::returnPlayerScore()
{
	in_file_PlayerScore.open("Assets/Score/PlayerScore.txt");
	in_file_PlayerScore >> playerScore;
	in_file_PlayerScore.close();
	return playerScore;
}

void HighestScore::compareScore()
{
	in_file_HighScore.open("Assets/Score/HighestScore.txt");
	in_file_HighScore >> highScore;
	in_file_HighScore.close();

	in_file_PlayerScore.open("Assets/Score/PlayerScore.txt");
	in_file_PlayerScore >> playerScore;
	in_file_PlayerScore.close();

	if (highScore < playerScore)
	{
		out_file_HighScore.open("Assets/Score/HighestScore.txt");
		out_file_HighScore << playerScore << std::endl;
		out_file_HighScore.close();
	}

	out_file_PlayerScore.open("Assets/Score/PlayerScore.txt");
	out_file_PlayerScore << 0 << std::endl;
	out_file_PlayerScore.close();
}
