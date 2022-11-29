#pragma once
#include "code_solution.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void Solution_S002::displayQus()
{
	std::cout << "给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。\n\
请你将两个数相加，并以相同形式返回一个表示和的链表。\n\
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。";
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