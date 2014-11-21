#include "Chinese.h"

void loadWords()
{
	FileUtils* fu = FileUtils::getInstance();
	txt_map = fu->getValueMapFromFile("words.plist");
}

string ChineseWord(const char* wordId)
{
	if (txt_map.size() <= 0)
		loadWords();
	string ret = txt_map.at(wordId).asString();
	return ret;
}