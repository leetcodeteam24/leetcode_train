#pragma once
#include "code_solution.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

DECLARE_SOLUTION(S005)

void Solution_S005::displayQus()
{
    std::cout << "给你一个字符串 s，找到 s 中最长的回文子串。" << endl;
}



// 中心扩散
static pair<int, int> expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    return { left + 1, right - 1 };
}

string longestPalindrome_0(string s) {
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) {
        auto pair1 = expandAroundCenter(s, i, i);
        auto pair2 = expandAroundCenter(s, i, i + 1);
        int left1 = pair1.first;
        int right1 = pair1.second;
        int left2 = pair2.first;
        int right2 = pair2.second;
        if (right1 - left1 > end - start) {
            start = left1;
            end = right1;
        }
        if (right2 - left2 > end - start) {
            start = left2;
            end = right2;
        }
    }
    return s.substr(start, end - start + 1);
}

//动态规划
string longestPalindrome_1(string s) {
    int n = int(s.size());
    if (n < 2)
    {
        return s;
    }

    int begin = 0;
    int max = 1;

    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // 先枚举子串长度
    for (int L = 2; L <= n; L++) {
        // 枚举左边界，左边界的上限设置可以宽松一些
        for (int i = 0; i < n; i++) {
            int j = L + i - 1;
            if (j >= n)
            {
                break;
            }
            if (s[i] != s[j])
            {
                dp[i][j] = false;
            }
            else
            {
                if (j - i < 3)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            if (dp[i][j] && j - i + 1 > max)
            {
                max = j - i + 1;
                begin = i;
            }
        }
    }

    return s.substr(begin, max);
}



// Manacher
int expand(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    return (right - left - 2) / 2;
}

string longestPalindrome_2(string s) {
    int start = 0, end = -1;
    string t = "#";
    for (char c : s) {
        t += c;
        t += '#';
    }
    t += '#';
    s = t;
    vector<int> arm_len;
    int right = -1, j = -1;
    for (int i = 0; i < s.size(); ++i) {                                                                                                              
        int cur_arm_len;
        if (right >= i) {
            int i_sym = j * 2 - i;
            int min_arm_len = min(arm_len[i_sym], right - i);
            cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
        }
        else {
            cur_arm_len = expand(s, i, i);
        }
        arm_len.push_back(cur_arm_len);
        if (i + cur_arm_len > right) {
            j = i;
            right = i + cur_arm_len;
        }
        if (cur_arm_len * 2 + 1 > end - start) {
            start = i - cur_arm_len;
            end = i + cur_arm_len;
        }
    }

    string ans;
    for (int i = start; i <= end; ++i) {
        if (s[i] != '#') {
            ans += s[i];
        }
    }
    return ans;
}


void Solution_S005::solute()
{
    std::string s = "babad";
    cout << longestPalindrome_2(s) << endl;
}