#pragma once
#include "code_solution.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void Solution_S003::displayQus()
{
	std::cout << "给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。" << endl;
}


int lengthOfLongestSubstring(string s) {
	int index = 0;
	int max = 0;
	int temp_max = 0;
	if (s.length() < 2)
	{
		return int(s.length());
	}
	unordered_map<char, int> hashtable;
	int pre = 0;
	while (index < s.length())
	{
		std::string sub_0 = s.substr(index, 1);
		char c = s[index];
		if (hashtable.find(c) == hashtable.end())
		{
			hashtable[c] = index;
		}
		else
		{
			temp_max = index - pre;
			pre = std::max(hashtable[c] + 1, pre);
			hashtable[c] = index;
			max = std::max(temp_max, max);
		}
		index++;
	}
	temp_max = index - pre;
	max = std::max(temp_max, max);
	return max;
}


void Solution_S003::solute()
{
	std::string s = "abbac";
	cout << lengthOfLongestSubstring(s) << endl;
}