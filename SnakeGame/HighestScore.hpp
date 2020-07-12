#pragma once
#include<iostream>
#include<fstream>
class HighestScore
{
public:
	HighestScore();
	~HighestScore();
	void storePlayerScore(int currentScore);
	int returnHighestScore();
	int returnPlayerScore();
	void compareScore();
	
private:
	std::ifstream in_file_HighScore;
	std::ifstream in_file_PlayerScore;
	std::ofstream out_file_HighScore;
	std::ofstream out_file_PlayerScore;

	int highScore;
	int playerScore;
};

