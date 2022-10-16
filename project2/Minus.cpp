#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
using namespace std;
#include <stdexcept>
#include <string>
#include "functions.hpp"


string MinusBothInteger(string a, string b)
{

    int a1[a.length()] = {0};

    for (size_t i = a.length() - 1; i >= 0; i--)
    {
        a1[i] = stoi(a.substr(i, 1));
        if (i == 0)
            break;
    }

    int b1[a.length()] = {0};

    for (size_t i = a.length() - 1, k = b.length() - 1; k >= 0; i--, k--)
    {
        b1[i] = stoi(b.substr(k, 1));

        if (k == 0)
            break;
    }

    int total[a.length()] = {0};
    for (size_t k = a.length() - 1; k >= 0; k--)
    {

        total[k] += (a1[k] - b1[k]);

        if (total[k] < 0)
        {
            total[k] += 10;
            total[k - 1] -= 1;
        }
        if (k == 0)
            break;
    }

    string c = "";

    for (size_t i = 0; i < a.length(); i++)
    {
        c.append(to_string(total[i]));
    }

    return c;
}

string MinusBothFloat(string a, string b)
{
    int jiewei = 0;
    int apoint = a.find(".");
    string aleft = a.substr(0, apoint);
    string aright = a.substr(apoint + 1, a.length() - 1 - apoint);
    int bpoint = b.find(".");
    string bleft = b.substr(0, bpoint);
    string bright = b.substr(bpoint + 1, b.length() - 1 - bpoint);

    int resultlength1;
    if (aright.length() > bright.length())
        resultlength1 = aright.length();
    else
        resultlength1 = bright.length();
    int a1[resultlength1] = {0};
    for (size_t i = 0; i < aright.length(); i++)
    {
        a1[i] = stoi(aright.substr(i, 1));
    }

    int b1[resultlength1] = {0};

    for (size_t i = 0; i < bright.length(); i++)
    {
        b1[i] = stoi(bright.substr(i, 1));
    }

    int total[resultlength1] = {0};
    for (size_t k = 0; k < resultlength1; k++)
    {
        total[k] += (a1[k] - b1[k]);
    }

    for (size_t i = resultlength1 - 1; i > 0; i--)
    {
        if (total[i] < 0)
        {
            total[i] += 10;
            total[i - 1] -= 1;
        }
    }

    if (total[0] < 0)
    {
        jiewei = 1;
        total[0] += 10;
    }

    string cright = "";

    for (size_t i = 0; i < resultlength1; i++)
    {
        cright.append(to_string(total[i]));
    }

    //以下为整数部分

    int a2[aleft.length()] = {0};

    for (size_t i = 0; i < aleft.length(); i++)
    {
        a2[i] = stoi(aleft.substr(i, 1));
    }

    int b2[aleft.length()] = {0};

    for (size_t i = aleft.length() - 1, k = bleft.length() - 1; k >= 0; i--, k--)
    {
        b2[i] = stoi(bleft.substr(k, 1));
        if (k == 0)
            break;
    }

    int total1[aleft.length()] = {0};
    total1[aleft.length() - 1] -= jiewei;

    for (size_t i = aleft.length() - 1; i >= 0; i--)
    {
        total1[i] += (a2[i] - b2[i]);
        if (total1[i] < 0)
        {
            total1[i] += 10;
            total1[i - 1] -= 1;
        }
        if (i == 0)
            break;
    }

    string cleft = "";

    for (size_t i = 0; i < aleft.length(); i++)
    {
        cleft.append(to_string(total1[i]));
    }

    string c = "";
    c.append(cleft);
    c.append(".");
    c.append(cright);
    return c;
}

string Minus(string a)
{
    int jianhao = a.find("-");
    string left = a.substr(0, jianhao);
    string right = a.substr(jianhao + 1, a.length() - 1 - jianhao);
    int daxiao = compareNum1(left, right);
    string c = "";
    bool positive = true;
    if (daxiao == 0)
        return "0";
    else if (daxiao == 2)
    {
        positive = false;

        c = MinusBothFloat(right, left);
        c.insert(0, "-");
        c.insert(0, "(");
        c.append(")");
    }
    else
        c = MinusBothFloat(left, right);

    return c;
}
