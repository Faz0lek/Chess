#include "VoiceControl.h"
#include <iostream>

VoiceControl::VoiceControl()
{
	this->Move = "";
	this->LastMove = "";
	this->Log.open("log.txt", std::ios::out | std::ios::trunc);
	this->Log.close();
}

void VoiceControl::Init()
{
	this->Log.open("log.txt", std::ios::in);
	this->Log.seekg(-4, std::ios_base::end);
	this->Log >> this->Move;

	this->SplitInputString();
}

void VoiceControl::SplitInputString()
{
	this->From = this->Move[0];
	this->From.push_back(this->Move[1]);
	this->To = this->Move[2];
	this->To.push_back(this->Move[3]);
}

void VoiceControl::Save()
{
	this->Log.close();
}