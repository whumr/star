#ifndef _CHINESEWORD_H_
#define _CHINESEWORD_H_
#include <string>
#include <cocos2d.h>
using namespace std;
using namespace cocos2d;

static ValueMap txt_map;

string ChineseWord(const char* wordId);

void loadWords();

#endif