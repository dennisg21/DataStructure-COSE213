#include "wordfrequency.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <string.h>

using namespace std;

/** 
  * Assignment 3 for COSE213 Data Structures
  *
  * Won-Ki Jeong (wkjeong@korea.ac.kr)
  *
  * 2021. 5. 9
  *
  */

WordFrequency::WordFrequency()
{
	map = new WordFreqMap();
}

WordFrequency::~WordFrequency()
{
	delete map;
}

void WordFrequency::ReadText(const char* filename)
{
	std::ifstream file(filename);
	std::string s;
	int i;
	if(file.is_open())
	{
		std::getline(file, s, '#');
		std::istringstream iss(s);
		do
		{
		std::string word;
		iss >> word;
		
		//remove symbols
		word.erase(std::remove_if(word.begin(), word.end(), [](unsigned char x){return std::ispunct(x); }), word.end());

		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		IncreaseFrequency(word);
		}while(iss);
	}
	
}

int WordFrequency::GetFrequency(const std::string word)
{
	WordFreqElem* current  = map->find(word);
	int i = 0;
	if (current != NULL)
	{
		return current -> val;
	}
	return 0;
}

void WordFrequency::IncreaseFrequency(const std::string word)
{
	WordFreqElem*  current = map->find(word);
	if(current != NULL)
	{
		int value;
		value = current -> val + 1;
		map->insert(word, value);
	}
	else
	{
		map->insert(word,1);
	}
}
