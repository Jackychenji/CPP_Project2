#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
using namespace std;
#include <stdexcept>
#include <string>
#include "functions.hpp"

bool judgeResultPositive(string a, string b)
{
    int count = 0;
    if (a.substr(0, 1) == "-")
    {
        count++;
    }
    if (b.substr(0, 1) == "-")
    {
        count++;
    }
    if (count == 0 || count == 2)
        return true;
    else
        return false;
}

int compareNum(string a, string b)
{
    if (a.find(".") == string::npos)
        a.append(".0");
    if (b.find(".") == string::npos)
        b.append(".0");

    int apoint = a.find(".");
    string aleft = a.substr(0, apoint);
    string aright = a.substr(apoint + 1, a.length() - 1 - apoint);
    int bpoint = b.find(".");
    string bleft = b.substr(0, bpoint);
    string bright = b.substr(bpoint + 1, b.length() - 1 - bpoint);
    if (aright.length() > bright.length())
        b.append(aright.length() - bright.length(), '0');
    else
        a.append(bright.length() - aright.length(), '0');
    aright = a.substr(apoint + 1, a.length() - 1 - apoint);
    bright = b.substr(bpoint + 1, b.length() - 1 - bpoint);

    int len = 0;

    if (aleft.length() > bleft.length())
        len = aleft.length();
    else
        len = bleft.length();

    int a2[len] = {0};

    for (size_t i = len - 1, k = aleft.length() - 1; k >= 0; i--, k--)
    {
        a2[i] = stoi(aleft.substr(k, 1));
        if (k == 0)
            break;
    }

    int b2[len] = {0};

    for (size_t i = len - 1, k = bleft.length() - 1; k >= 0; i--, k--)
    {
        b2[i] = stoi(bleft.substr(k, 1));
        if (k == 0)
            break;
    }
    for (size_t i = 0; i < len; i++)
    {
        if (a2[i] > b2[i])
            return 1;
        else if (a2[i] < b2[i])
            return 2;
    }
    int len1 = 0;
    if (aright.length() > bright.length())
        len1 = aright.length();
    else
        len1 = bright.length();

    int a1[len1] = {0};

    for (size_t i = 0; i < aright.length(); i++)
    {
        a1[i] = stoi(aright.substr(i, 1));
    }

    int b1[bright.length()] = {0};

    for (size_t i = 0; i < bright.length(); i++)
    {
        b1[i] = stoi(bright.substr(i, 1));
    }
    for (size_t i = 0; i < aright.length(); i++)
    {
        if (a1[i] > b1[i])
            return 1;
        else if (a1[i] < b1[i])
            return 2;
    }
    return 0;
}

int compareNum1(string &a, string &b)
{
    if (a.find(".") == string::npos)
        a.append(".0");
    if (b.find(".") == string::npos)
        b.append(".0");

    int apoint = a.find(".");
    string aleft = a.substr(0, apoint);
    string aright = a.substr(apoint + 1, a.length() - 1 - apoint);
    int bpoint = b.find(".");
    string bleft = b.substr(0, bpoint);
    string bright = b.substr(bpoint + 1, b.length() - 1 - bpoint);
    if (aright.length() > bright.length())
        b.append(aright.length() - bright.length(), '0');
    else
        a.append(bright.length() - aright.length(), '0');
    aright = a.substr(apoint + 1, a.length() - 1 - apoint);
    bright = b.substr(bpoint + 1, b.length() - 1 - bpoint);

    int len = 0;

    if (aleft.length() > bleft.length())
        len = aleft.length();
    else
        len = bleft.length();

    int a2[len] = {0};

    for (size_t i = len - 1, k = aleft.length() - 1; k >= 0; i--, k--)
    {
        a2[i] = stoi(aleft.substr(k, 1));
        if (k == 0)
            break;
    }

    int b2[bleft.length()] = {0};

    for (size_t i = len - 1, k = bleft.length() - 1; k >= 0; i--, k--)
    {
        b2[i] = stoi(bleft.substr(k, 1));
        if (k == 0)
            break;
    }
    for (size_t i = 0; i < len; i++)
    {
        if (a2[i] > b2[i])
            return 1;
        else if (a2[i] < b2[i])
            return 2;
    }
    int len1 = 0;
    if (aright.length() > bright.length())
        len1 = aright.length();
    else
        len1 = bright.length();

    int a1[len1] = {0};

    for (size_t i = 0; i < aright.length(); i++)
    {
        a1[i] = stoi(aright.substr(i, 1));
    }

    int b1[bright.length()] = {0};

    for (size_t i = 0; i < bright.length(); i++)
    {
        b1[i] = stoi(bright.substr(i, 1));
    }
    for (size_t i = 0; i < aright.length(); i++)
    {
        if (a1[i] > b1[i])
            return 1;
        else if (a1[i] < b1[i])
            return 2;
    }
    return 0;
}

string NumDeleteKuohao(string &a)
{
    if (a.find("(") != string::npos)
    {
        a.erase(a.length() - 1, 1);
        a.erase(0, 1);
    }
    return a;
}

bool judgeLegalKuohao(string a)
{
    for (size_t i = 0; i < a.length(); i++)
    {
        if (a.substr(i, 1) == "(")
        {
            if (a.substr(i + 1, 1) != "-")
                return true;
        }
    }
    return false;
}

int findFirstLegalRKuohao(string a)
{
    int j = 0;
    for (size_t i = 0; i < a.length(); i++)
    {
        if (a.substr(i, 1) == ")")
        {
            j = i - 1;
            while (a.substr(j, 1) != "(" && j > 0)
            {
                if ((a.substr(j, 1) == "-" && a.substr(j - 1, 1) != "(") | a.substr(j, 1) == "+" |
                    a.substr(j, 1) == "*" | a.substr(j, 1) == "/")
                {
                    return i;
                }
                j--;
            }
        }
    }

    return 0;
}

int findFirstLegalLKuohao(string a)
{
    int RKuohao = findFirstLegalRKuohao(a);
    for (size_t i = RKuohao - 1; i > 0; i--)
    {
        if (a.substr(i, 1) == "(")
        {
            if (a.substr(i + 1, 1) != "-")
                return i;
        }
    }
    return 0;
}
