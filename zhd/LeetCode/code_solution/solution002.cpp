#pragma once
#include "code_solution.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void Solution_S002::displayQus()
{
	std::cout << "�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�\n\
���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����\n\
����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��";
}

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int inc = 0;
	ListNode* ret_ndoe = new ListNode();
	ListNode* next_node = ret_ndoe;
	while (l1 != nullptr || l2 != nullptr)
	{
		int left = l1 == nullptr ? 0 : l1->val;
		int right = l2 == nullptr ? 0 : l2->val;
		int sum = (left + right + inc);
		
		inc = sum / 10;
		sum = sum % 10;
		next_node->next = new ListNode(sum);
		next_node = next_node->next;

		if (l1 != nullptr)
		{
			l1 = l1->next;
		}
		if (l2 != nullptr)
		{
			l2 = l2->next;
		}
	}
	
	if (inc > 0)
	{
		next_node->next = new ListNode(inc);
		next_node = next_node->next;
	}
	return ret_ndoe->next;
}



void Solution_S002::solute()
{
	auto first = new ListNode(0);
	
	auto second_2 = new ListNode(8);
	auto second_1 = new ListNode(7, second_2);
	auto second = new ListNode(2, second_1);

	auto ret = addTwoNumbers(first, second);
	while (ret != nullptr)
	{
		cout << ret->val;
		ret = ret->next;
	}

}