#pragma once
#include "code_solution.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

DECLARE_SOLUTION(S006)

void Solution_S006::displayQus()
{
    std::cout << "��һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ��� Z �������С�\n\
        ���������ַ���Ϊ 'PAYPALISHIRING'' ����Ϊ 3 ʱ���������£�\n\
        P   A   H   N\n\
        A P L S I I G\n\
        Y   I   R\n\
        ֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺'PAHNAPLSIIGYIR'��\n\
        ����ʵ��������ַ�������ָ�������任�ĺ�����\n\
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