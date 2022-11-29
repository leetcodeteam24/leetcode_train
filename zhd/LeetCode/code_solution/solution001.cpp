#pragma once
#include "code_solution.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void Solution_S001::displayQus()
{
std::cout << "����һ����������nums��һ������Ŀ��ֵtarget�������ڸ��������ҳ���ΪĿ��ֵtarget�����������������������ǵ������±ꡣ\n\
����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�\n\
����԰�����˳�򷵻ش𰸡�\n";
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