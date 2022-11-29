#pragma once
#include "code_solution.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void Solution_S001::displayQus()
{
std::cout << "给定一个整数数组nums和一个整数目标值target，请你在该数组中找出和为目标值target的那两个整数，并返回它们的数组下标。\n\
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。\n\
你可以按任意顺序返回答案。\n";
}


vector<int> twoSum(vector<int>& nums, int target) 
{
	unordered_map<int, int> hashtable;
	for (int i = 0; i < nums.size(); ++i) {
		auto it = hashtable.find(target - nums[i]);
		if (it != hashtable.end()) {
			return { it->second, i };
		}
		hashtable[nums[i]] = i;
	}
	return {};
}



void Solution_S001::solute() 
{
	vector<int> test01 = { 3,3 };
	auto ret = twoSum(test01, 6);
	for (auto i : ret)
	{
		cout << i << endl;
	}
	
}