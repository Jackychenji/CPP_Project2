#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
using namespace std;
#include <stdexcept>
#include <string>
#include "functions.hpp"

bool fuhaoxianglian(string a)
{
    for (size_t i = 1; i < a.length(); i++)
    {
        if (a.substr(i, 1) == "+" | a.substr(i, 1) == "-" | a.substr(i, 1) == "*" |
            a.substr(i, 1) == "/" | a.substr(i, 1) == ")" | a.substr(i, 1) == ".")
        {
            if (a.substr(i - 1, 1) == "+" | a.substr(i - 1, 1) == "-" | a.substr(i - 1, 1) == "*" |
                a.substr(i - 1, 1) == "/" | a.substr(i - 1, 1) == "(" | a.substr(i - 1, 1) == ".")
            {
                return false;
            }
        }
    }
    if (a.find(')') == 1 | a.substr(a.length() - 1, 1) == "(")
    {
        return false;
    }

    return true;
}

bool IsAllNumbers(string a)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (!isdigit(a[i]))
        {
            return false;
        }
    }
    return true;
}

bool AlldigitExceptFuhao(string a)
{
    while (a.find('+') != string::npos)
    {
        a.erase(a.find('+'), 1);
    }
    while (a.find('-') != string::npos)
    {
        a.erase(a.find('-'), 1);
    }
    while (a.find('*') != string::npos)
    {
        a.erase(a.find('*'), 1);
    }
    while (a.find('/') != string::npos)
    {
        a.erase(a.find('/'), 1);
    }
    while (a.find('.') != string::npos)
    {
        a.erase(a.find('.'), 1);
    }
    return IsAllNumbers(a);
}

bool judgeIllegalInput(string a)
{
    return AlldigitExceptFuhao(a)&&fuhaoxianglian(a);
}