#pragma once
#include "code_solution.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

DECLARE_SOLUTION(S006)

void Solution_S006::displayQus()
{
    std::cout << "将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。\n\
        比如输入字符串为 'PAYPALISHIRING'' 行数为 3 时，排列如下：\n\
        P   A   H   N\n\
        A P L S I I G\n\
        Y   I   R\n\
        之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如：'PAHNAPLSIIGYIR'。\n\
        请你实现这个将字符串进行指定行数变换的函数：\n\
        string convert(string s, int numRows); " << endl;
}


string convert(string s, int numRows) {
    int len = int(s.size());
    if (len == 1 || numRows == 1)
    {
        return s;
    }

    int space = numRows * 2 - 2;
    int circle = len / space;
    string ret;
    for (int r = 0; r < numRows; r++)
    {
        for (int i = 0; i <= circle; i++)
        {
            if (r == 0 || r == numRows - 1)
            {
                int a = i * space  + r;
                if (a < len)
                {
                    ret.append(s.substr(a, 1));
                }
            }
            else
            {
                int a = i * space + r;
                int b = i * space + space - r;
                if (a < len)
                {
                    ret.append(s.substr(a, 1));
                }
                if (b < len)
                {
                    ret.append(s.substr(b, 1));
                }
            }
        }
    }
    return ret;
}

void Solution_S006::solute()
{
    std::string s = "PAYPALISHIRING";
    cout << convert(s, 3) << endl;
    cout << convert(s, 4) << endl;
    cout << convert("A", 1) << endl;
}