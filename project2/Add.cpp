#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
using namespace std;
#include <stdexcept>
#include <string>
#include "functions.hpp"


string addBothInteger(string a, string b)
{
    int resultlength;
    if (a.length() > b.length())
        resultlength = a.length() + 1;
    else
        resultlength = b.length() + 1;

    int a1[resultlength] = {0};

    for (size_t i = resultlength - 1, k = a.length() - 1; k >= 0; i--, k--)
    {
        a1[i] = stoi(a.substr(k, 1));
        if (k == 0)
            break;
    }

    int b1[resultlength] = {0};

    for (size_t i = resultlength - 1, k = b.length() - 1; k >= 0; i--, k--)
    {
        b1[i] = stoi(b.substr(k, 1));
        if (k == 0)
            break;
    }

    int total[resultlength] = {0};

    for (size_t k = resultlength - 1; k > 0; k--)
    {
        total[k] += (a1[k] + b1[k]);

        if (total[k] >= 10)
        {
            total[k] -= 10;
            total[k - 1] += 1;
        }
    }

    string c = "";

    for (size_t i = 0; i < resultlength; i++)
    {
        c.append(to_string(total[i]));
    }

    return c;
}

string addBothFloat(string a, string b)
{
    int jinwei = 0;
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
    for (size_t i = 0; i < aright.length() ; i++)
    {
        total[i] += a1[i] ;
    }
    for (size_t i = 0; i < bright.length(); i++)
    {
        total[i] += b1[i];
    }
    

    for (size_t i = resultlength1 - 1; i > 0; i--)
    {
        if (total[i] >= 10)
        {
            total[i] -= 10;
            total[i - 1] += 1;
        }
    }
    if (total[0] >= 10)
    {
        jinwei = 1;
        total[0] -= 10;
    }
    string cright = "";

    for (size_t i = 0; i < resultlength1; i++)
    {
        cright.append(to_string(total[i]));
    }

    //以下为整数部分
    int resultlength2;
    if (aleft.length() > bleft.length())
        resultlength2 = aleft.length() + 1;
    else
        resultlength2 = bleft.length() + 1;

    int a2[resultlength2] = {0};

    for (size_t i = resultlength2 - 1, k = aleft.length() - 1; k >= 0; i--, k--)
    {
        a2[i] = stoi(aleft.substr(k, 1));
        if (k == 0)
            break;
    }

    int b2[resultlength2] = {0};

    for (size_t i = resultlength2 - 1, k = bleft.length() - 1; k >= 0; i--, k--)
    {

        b2[i] = stoi(bleft.substr(k, 1));

        if (k == 0)
            break;
    }

    int total1[resultlength2] = {0};
    total1[resultlength2 - 1] = jinwei;
    for (size_t k = resultlength2 - 1; k > 0; k--)
    {
        total1[k] += a2[k] + b2[k];
        
        if (total1[k] >= 10)
        {
            total1[k] -= 10;
            total1[k - 1] += 1;
        }
    }
    

    string cleft = "";

    for (size_t i = 0; i < resultlength2; i++)
    {
        cleft.append(to_string(total1[i]));
        
    }
   
    string c = "";
    c.append(cleft);
    c.append(".");
    c.append(cright);
    return c;
}

string addAIntegerBFloat(string a, string b)
{
    int bpoint = b.find(".");
    string bleft = b.substr(0, bpoint);
    string bright = b.substr(bpoint + 1, b.length() - 1 - bpoint);
    string cleft = addBothInteger(a, bleft);
    string c = "";
    c.append(cleft);
    c.append(".");
    c.append(bright);
    return c;
}

string addAFloatBInteger(string a, string b)
{
    int apoint = a.find(".");
    string aleft = a.substr(0, apoint);
    string aright = a.substr(apoint + 1, a.length() - 1 - apoint);
    string cleft = addBothInteger(aleft, b);
    string c = "";
    c.append(cleft);
    c.append(".");
    c.append(aright);
    return c;
}

string calculateAdd(string a, string b)
{
    string c;

    if (a.find(".") == string::npos && b.find(".") == string::npos)
        c = addBothInteger(a, b); // if both are integer
    else if (a.find(".") == string::npos && b.find(".") != string::npos)
        c = addAIntegerBFloat(a, b); // a integer b float
    else if (a.find(".") != string::npos && b.find(".") == string::npos)
        c = addAFloatBInteger(a, b); // a float b integer
    else
        c = addBothFloat(a, b); // both are float

    return c;
}

string Add(string a)
{
    int jiahao = a.find("+");
    string left = a.substr(0, jiahao);
    string right = a.substr(jiahao + 1, a.length() - 1 - jiahao);
    left = NumDeleteKuohao(left);
    right = NumDeleteKuohao(right);
    bool positive = !(left.substr(0, 1) == "-" && right.substr(0, 1) == "-");
    if (left.substr(0, 1) == "-")
        left.erase(0, 1);
    if (right.substr(0, 1) == "-")
        right.erase(0, 1);
    string c = calculateAdd(left, right);
    if (!positive)
    {
        c.insert(0, "-");
        c.insert(0, "(");
        c.append(")");
    }
    return c;
}
