#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
using namespace std;
#include <stdexcept>
#include <string>
#include "functions.hpp"


string DivideBothFloat(string a, string b)
{
    int dangqianxiaoshu = 0;
    int maxxiaoshu = 20;
    int apoint = a.find(".");
    int axiaoshu = a.length() - 1 - apoint;
    a.erase(apoint, 1);
    int bpoint = b.find(".");
    int bxiaoshu = b.length() - 1 - bpoint;
    b.erase(bpoint, 1);
    dangqianxiaoshu = axiaoshu - bxiaoshu;
    if (axiaoshu > bxiaoshu && maxxiaoshu < axiaoshu)
        maxxiaoshu = axiaoshu;
    if (axiaoshu < bxiaoshu && maxxiaoshu < bxiaoshu)
        maxxiaoshu = bxiaoshu;
    string result = "";
    int count;
    while (dangqianxiaoshu < maxxiaoshu)
    {   
        count++;
        if (compareNum(a, b) == 1)
        {
            b.append("0");
            if (compareNum(a, b) == 2)
            {
                b.erase(b.length() - 1, 1);
            }
            else
            {
                dangqianxiaoshu--;
                continue;
            }
        }
        else if (compareNum(a, b) == 0)
        {
            return "1.0";
        }

        else
        {
            a.append("0");
            dangqianxiaoshu++;
        }

        for (size_t i = 9; i >= 0; i--)
        {
            if (compareNum(MultiplyBothInteger(to_string(i), b), a) == 2 |
                compareNum(MultiplyBothInteger(to_string(i), b), a) == 0)
            {
                result.append(to_string(i));
                a = MinusBothInteger(a, MultiplyBothInteger(to_string(i), b));
                break;
            }
        }
       
    }

    int point = result.length() - dangqianxiaoshu;
    while (point <= 0)
    {
        result.insert(0, "0");
        point++;
    }

    result.insert(point, ".");
    if (stoi(result.substr(result.length() - 1, 1)) >= 5)
    {
        result.erase(result.length() - 1, 1);
        int jinwei = stoi(result.substr(result.length() - 1, 1)) + 1;
        result.erase(result.length() - 1, 1);
        result.append(to_string(jinwei));
    }
    
    
    return result;
}

string Divide(string a)
{
    int chuhao = a.find("/");
    string left = a.substr(0, chuhao);
    string right = a.substr(chuhao + 1, a.length()  - chuhao);
    left = NumDeleteKuohao(left);
    right = NumDeleteKuohao(right);
    if (left.find(".") == string::npos)
        left.append(".0");
    if (right.find(".") == string::npos)
        right.append(".0");

    bool positive = judgeResultPositive(left, right);
    if (left.substr(0, 1) == "-")
        left.erase(0, 1);

    if (right.substr(0, 1) == "-")
        right.erase(0, 1);

    string c = DivideBothFloat(left, right);
    if (!positive)
    {
        c.insert(0, "-");
        c.insert(0, "(");
        c.append(")");
    }
    return c;
}
