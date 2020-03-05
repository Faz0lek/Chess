#pragma once
#include <string>
#include <fstream>

class VoiceControl
{
public:
	std::fstream Log;
	std::string LastMove;
	std::string Move;

	std::string From; 
	std::string To;
	
	VoiceControl();
	void Save();
	void Init();
	
private:
	void SplitInputString();
};