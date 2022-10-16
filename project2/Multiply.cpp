#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
using namespace std;
#include <stdexcept>
#include <string>
#include "functions.hpp"

string MultiplyBothInteger(string a, string b)
{
    int a1[a.length()] = {0};

    for (size_t i = 0; i < a.length(); i++)
    {
        a1[i] = stoi(a.substr(i, 1));
    }

    int b1[b.length()] = {0};

    for (size_t i = 0; i < b.length(); i++)
    {
        b1[i] = stoi(b.substr(i, 1));
    }

    int total[a.length() + b.length()] = {0};
    for (size_t i = a.length(); i > 0; i--)
    {
        for (size_t j = b.length(); j > 0; j--)
        {
            total[i + j - 1] += a1[i - 1] * b1[j - 1];
        }
    }

    for (size_t i = a.length() + b.length() - 1; i >= 1; i--)
    {
        int division = total[i] / 10;
        total[i - 1] += division;
        total[i] -= division * 10;
    }

    string c = "";

    for (size_t i = 0; i < a.length() + b.length(); i++)
    {
        c.append(to_string(total[i]));
    }

    return c;
}

string MultiplyBothFloat(string a, string b)
{
    int apoint = a.find(".");
    int afloat = a.length() - 1 - apoint;
    int bpoint = b.find(".");
    int bfloat = b.length() - 1 - bpoint;
    a.erase(apoint, 1);
    b.erase(bpoint, 1);
    string c = MultiplyBothInteger(a, b);
    c.insert(c.length() - afloat - bfloat, ".");
    return c;
}

string MultiplyAIntegerBFloat(string a, string b)
{
    int bpoint = b.find(".");
    int bfloat = b.length() - 1 - bpoint;
    b.erase(bpoint, 1);
    string c = MultiplyBothInteger(a, b);
    c.insert(c.length() - bfloat, ".");
    return c;
}

string MultiplyAFloatBInteger(string a, string b)
{
    int apoint = a.find(".");
    int afloat = a.length() - 1 - apoint;
    a.erase(apoint, 1);
    string c = MultiplyBothInteger(a, b);
    c.insert(c.length() - afloat, ".");
    return c;
}

string calculateMultiply(string a, string b)
{
    string c;
    if (a.find(".") == string::npos && b.find(".") == string::npos)
        c = MultiplyBothInteger(a, b); // if both are integer
    else if (a.find(".") == string::npos && b.find(".") != string::npos)
        c = MultiplyAIntegerBFloat(a, b); // a integer b float
    else if (a.find(".") != string::npos && b.find(".") == string::npos)
        c = MultiplyAFloatBInteger(a, b); // a float b integer
    else
        c = MultiplyBothFloat(a, b); // both are float

    return c;
}

string Multiply(string a)
{
    int chenghao = a.find("*");
    string left = a.substr(0, chenghao);
    string right = a.substr(chenghao + 1, a.length() - 1 - chenghao);
    left = NumDeleteKuohao(left);
    right = NumDeleteKuohao(right);
    bool positive = judgeResultPositive(left, right);
    if (left.substr(0, 1) == "-")
        left.erase(0, 1);
    if (right.substr(0, 1) == "-")
        right.erase(0, 1);

    string c = calculateMultiply(left, right);
    if (!positive)
    {
        c.insert(0, "-");
        c.insert(0, "(");
        c.append(")");
    }
    return c;
}
