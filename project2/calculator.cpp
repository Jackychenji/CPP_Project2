#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
using namespace std;
#include <stdexcept>
#include <string>
#include "functions.hpp"

int chenghao;
int chuhao;
int jiahao;
int jianhao;

bool findCorrectJianhao(string a)
{
    for (size_t i = 1; i < a.length(); i++)
    {
        if (a.substr(i, 1) == "-" && a.substr(i - 1, 1) != "(")
            return false;
    }
    return true;
}

string calculateNoKuohao(string a)
{

    while (!(a.find("+") == string::npos && findCorrectJianhao(a) && a.find("*") == string::npos && a.find("/") == string::npos))
    {
        if (a.find("*") != string::npos | a.find("/") != string::npos) //先确保乘除的运算
        {
            if (a.find("*") != string::npos)
                chenghao = a.find("*");
            else
                chenghao = a.length();
            if (a.find("/") != string::npos)
                chuhao = a.find("/");
            else
                chuhao = a.length();

            if (chenghao < chuhao) //乘法
            {
                int i = chenghao + 1;
                int j = chenghao - 1;
                while (i < a.length() - 1)
                {
                    if (a.substr(i, 1) == "(")
                        i += 2;
                    if (a.substr(i, 1) != "*" && a.substr(i, 1) != "/" && a.substr(i, 1) != "+" && a.substr(i, 1) != "-")
                        i++;
                    else
                    {
                        i--;
                        break;
                    }
                }

                while (j > 0)
                {
                    if (a.substr(j, 1) != "*" && a.substr(j, 1) != "/" && a.substr(j, 1) != "+" && a.substr(j, 1) != "-")
                        j--;
                    else
                    {
                        if (a.substr(j - 1, 1) == "(")
                        {
                            j--;
                            break;
                        }
                        j++;
                        break;
                    }
                }

                string temp = "";
                temp.append(a.substr(0, j));
                temp.append(Multiply(a.substr(j, i - j + 1)));

                if (i < a.length())
                    temp.append(a.substr(i + 1, a.length() - i));
                a = temp;
            }
            else //除法
            {
                int i = chuhao + 1;
                int j = chuhao - 1;
                while (i < a.length() - 1)
                {
                    if (a.substr(i, 1) == "(")
                        i += 2;
                    if (a.substr(i, 1) != "*" && a.substr(i, 1) != "/" && a.substr(i, 1) != "+" && a.substr(i, 1) != "-")
                        i++;
                    else
                    {
                        i--;
                        break;
                    }
                }
                while (j > 0)
                {
                    if (a.substr(j, 1) != "*" && a.substr(j, 1) != "/" && a.substr(j, 1) != "+" && a.substr(j, 1) != "-")
                        j--;

                    else
                    {
                        if (a.substr(j - 1, 1) == "(")
                        {
                            j--;
                            break;
                        }
                        j++;
                        break;
                    }
                }

                string num = Divide(a.substr(j, i - j + 1));

                string temp = "";
                temp.append(a.substr(0, j));
                temp.append(num);
                if (i < a.length())
                    temp.append(a.substr(i + 1, a.length() - i - 1));
                a = temp;
            }
        }
        else //这里开始加减的运算，要注意，本project中的加减需要结合两个数的正负来进行方法的选取
        {

            for (size_t i = 1; i < a.length(); i++)
            {

                if (a.substr(i, 1) == "+" || (a.substr(i, 1) == "-" && a.substr(i - 1, 1) != "(")) //找到合法的那个符号
                {

                    if (a.substr(i, 1) == "+") //如果是＋,双正与双负用加法，其余用减法。
                    {

                        if (a.substr(i - 1, 1) == ")" && a.substr(i + 1, 1) == "(") //双负加法
                        {
                            int leftnum = i - 1;
                            int rightnum = i + 1;
                            while (rightnum < a.length() - 1)
                            {

                                if (a.substr(rightnum, 1) != ")")
                                    rightnum++;
                                else
                                {
                                    break;
                                }
                            }
                            while (leftnum > 0)
                            {
                                if (a.substr(leftnum, 1) != "(")
                                    leftnum--;
                                else
                                {
                                    break;
                                }
                            }

                            string num = Add(a.substr(leftnum, rightnum - leftnum + 1));
                            string temp = "";
                            if (leftnum > 0)
                                temp.append(a.substr(0, leftnum));
                            temp.append(num);
                            if (rightnum < a.length() - 1)
                                temp.append(a.substr(rightnum, a.length() - rightnum - 1));
                            a = temp;
                        }
                        else if (a.substr(i - 1, 1) != ")" && a.substr(i + 1, 1) != "(") //双正加法
                        {
                            int leftnum = i - 1;
                            int rightnum = i + 1;
                            while (rightnum < a.length() - 1)
                            {
                                if (a.substr(rightnum, 1) != "+" && a.substr(rightnum, 1) != "-")
                                    rightnum++;
                                else
                                {
                                    rightnum--;
                                    break;
                                }
                            }
                            while (leftnum > 0)
                            {
                                if (a.substr(leftnum, 1) != "+" && a.substr(leftnum, 1) != "-")
                                    leftnum--;
                                else
                                {
                                    leftnum++;
                                    break;
                                }
                            }

                            string num = Add(a.substr(leftnum, rightnum - leftnum + 1));
                            string temp = "";
                            if (leftnum > 0)
                                temp.append(a.substr(0, leftnum));
                            temp.append(num);
                            if (rightnum < a.length())
                                temp.append(a.substr(rightnum, a.length() - rightnum - 1));
                            a = temp;
                        }
                        else if (a.substr(i - 1, 1) != ")" && a.substr(i + 1, 1) == "(")
                        {

                            int leftnum = i - 1;
                            int rightnum = i + 1;
                            while (rightnum < a.length() - 1)
                            {
                                if (a.substr(rightnum, 1) != ")")
                                    rightnum++;
                                else
                                    break;
                            }
                            while (leftnum > 0)
                            {
                                if (a.substr(leftnum, 1) != "+" && a.substr(leftnum, 1) != "-")
                                    leftnum--;
                                else
                                {
                                    leftnum++;
                                    break;
                                }
                            }

                            a.erase(rightnum, 1);
                            a.erase(i, 2);
                            rightnum -= 3;
                            string num = Minus(a.substr(leftnum, rightnum - leftnum + 1));

                            string temp = "";
                            if (leftnum > 0)
                                temp.append(a.substr(0, leftnum));
                            temp.append(num);

                            if (rightnum < a.length() - 1)
                                temp.append(a.substr(rightnum, a.length() - rightnum - 1));
                            a = temp;

                        } //后负前正，转化成减法
                        else if (a.substr(i - 1, 1) == ")" && a.substr(i + 1, 1) != "(")
                        {
                            int leftnum = i - 1;
                            int rightnum = i + 1;
                            while (rightnum < a.length() - 1)
                            {
                                if (a.substr(rightnum, 1) != "+" && a.substr(rightnum, 1) != "-")
                                    rightnum++;
                                else
                                {
                                    rightnum--;
                                    break;
                                }
                            }
                            while (leftnum > 0)
                            {
                                if (a.substr(leftnum, 1) != "(")
                                    leftnum--;
                                else
                                    break;
                            }
                            string left1 = a.substr(leftnum, i - leftnum);
                            string right1 = a.substr(i + 1, rightnum - i);
                            string afterchange = "";
                            afterchange.append(a.substr(0, leftnum));
                            afterchange.append(right1);
                            afterchange.append("+");
                            afterchange.append(left1);
                            afterchange.append(rightnum + 1, a.length() - rightnum - 1);
                            a = afterchange;

                        } //前负后正，转化成前正后负
                    }
                    else //如果是-,双减与双加用加法，其余用加法。
                    {

                        if (a.substr(i + 1, 1) != "(" && a.substr(i - 1, 1) == ")") //后正前负，加法
                        {

                            int leftnum = i - 1;
                            int rightnum = i + 1;

                            while (rightnum < a.length() - 1)
                            {
                                if (a.substr(rightnum, 1) != "+" && a.substr(rightnum, 1) != "-")
                                    rightnum++;
                                else
                                {
                                    rightnum--;
                                    break;
                                }
                            }

                            while (leftnum > 0)
                            {
                                if (a.substr(leftnum, 1) != "(")
                                    leftnum--;
                                else

                                    break;
                            }
                            a.erase(i, 1);
                            a.insert(i, "+");
                            if (rightnum == a.length() - 1)
                                a.append(")");

                            else
                                a.insert(rightnum + 1, ")");

                            a.insert(i + 1, "(-");

                            rightnum += 3;

                            string num = Add(a.substr(leftnum, rightnum - leftnum + 1));

                            return num;
                            string temp = "";
                            if (leftnum > 0)
                                temp.append(a.substr(0, leftnum));
                            temp.append(num);
                            if (rightnum < a.length() - 1)
                                temp.append(a.substr(rightnum, a.length() - rightnum - 1));
                            a = temp;
                        }
                        else if (a.substr(i + 1, 1) == "(" && a.substr(i - 1, 1) != ")") //前正后负，加法
                        {
                            int leftnum = i - 1;
                            int rightnum = i + 1;
                            while (rightnum < a.length() - 1)
                            {
                                if (a.substr(rightnum, 1) != ")")
                                    rightnum++;
                                else
                                    break;
                            }
                            while (leftnum > 0)
                            {
                                if (a.substr(leftnum, 1) != "+" && a.substr(leftnum, 1) != "-")
                                    leftnum--;
                                else
                                {
                                    leftnum++;
                                    break;
                                }
                            }
                            a.erase(i, 1);
                            a.insert(i, "+");
                            a.erase(rightnum, 1);
                            a.erase(i + 1, 2);
                            rightnum -= 3;
                            string num = Add(a.substr(leftnum, rightnum - leftnum + 1));
                            string temp = "";
                            if (leftnum > 0)
                                temp.append(a.substr(0, leftnum));
                            temp.append(num);
                            if (rightnum < a.length() - 1)
                                temp.append(a.substr(rightnum, a.length() - rightnum - 1));
                            a = temp;
                        }
                        else if (a.substr(i - 1, 1) != ")" && a.substr(i + 1, 1) != "(") //都正，减法
                        {
                            int leftnum = i - 1;
                            int rightnum = i + 1;
                            while (rightnum < a.length() - 1)
                            {
                                if (a.substr(rightnum, 1) != "+" && a.substr(rightnum, 1) != "-")
                                    rightnum++;
                                else
                                {
                                    rightnum--;
                                    break;
                                }
                            }
                            while (leftnum > 0)
                            {
                                if (a.substr(leftnum, 1) != "+" && a.substr(leftnum, 1) != "-")
                                    leftnum--;
                                else
                                {
                                    leftnum++;
                                    break;
                                }
                            }
                            string num = Minus(a.substr(leftnum, rightnum - leftnum + 1));
                            string temp = "";
                            if (leftnum > 0)
                                temp.append(a.substr(0, leftnum));
                            temp.append(num);
                            if (rightnum < a.length() - 1)
                                temp.append(a.substr(rightnum + 1, a.length() - rightnum - 1));
                            a = temp;
                        }
                        else //都负，把后面的变为正数，再进行上述运算
                        {
                            int leftnum = i - 1;
                            int rightnum = i + 1;
                            while (rightnum < a.length() - 1)
                            {
                                if (a.substr(rightnum, 1) != ")")
                                    rightnum++;
                                else
                                    break;
                            }
                            while (leftnum > 0)
                            {
                                if (a.substr(leftnum, 1) != "(")
                                    leftnum--;
                                else
                                    break;
                            }
                            a.erase(rightnum, 1);
                            a.erase(i, 3);
                            a.insert(i, "+");
                        }
                    }
                }
            }
        }
    }
    return a;
}

string changeOutput(string c)
{
    if (c.find('.') == string::npos) // no point
    {
        int c1[c.length()] = {0};

        for (size_t i = 0; i < c.length(); i++)
        {
            c1[i] = stoi(c.substr(i, 1));
        }
        for (size_t i = 0; i < c.length(); i++)
        {
            if (c1[i] == 0)
                c.erase(0, 1);
            if (c1[i] != 0)
                break;
        }
        return c;
    }
    else // has point
    {
        int point = c.find('.');
        string cleft = c.substr(0, point);
        int cle[cleft.length()] = {0};
        for (size_t i = 0; i < cleft.length(); i++)
        {
            cle[i] = stoi(cleft.substr(i, 1));
        }
        string cright = c.substr(point + 1, c.length() - 1 - point);
        int cri[cright.length()] = {0};
        for (size_t i = 0; i < cright.length(); i++)
        {
            cri[i] = stoi(cright.substr(i, 1));
        }
        for (size_t i = 0; i < cleft.length() - 1; i++)
        {

            if (cle[i] == 0)
            {
                cleft.erase(0, 1);
            }
        }
        for (size_t i = cright.length() - 1; i >= 1; i--)
        {
            if (cri[cright.length() - 1] != 0)
                break;
            if (cri[i] != 0)
            {
                cright.erase(i + 1, cright.length() - 1 - i);
                break;
            }
            if (i == 1)
            {
                cright.erase(1, cright.length() - 1);
            }
        }
        string d = "";
        d.append(cleft);
        d.append(".");
        d.append(cright);
        return d;
    }
}

string deleteKuohao(string a)
{
    while (judgeLegalKuohao(a))
    {
        int RKuohao = findFirstLegalRKuohao(a);

        int LKuohao = findFirstLegalLKuohao(a);

        string afterCalc = calculateNoKuohao(a.substr(LKuohao + 1, RKuohao - LKuohao - 1));

        string temp = "";
        if (LKuohao > 0)
            temp.append(a.substr(0, LKuohao));

        temp.append(afterCalc);

        temp.append(a.substr(RKuohao + 1, a.length() - RKuohao - 1));

        a = temp;
    }
    return a;
}

bool judgeChushuZero(string a)
{
    if (a.find('/') != string::npos)
    {
        int l = a.find('/');
        for (size_t i = l + 1; i < a.length(); i++)
        {
            if (a.substr(i, 1) == "+" | a.substr(i, 1) == "-" | a.substr(i, 1) == "*" | a.substr(i, 1) == "/" | i == a.length() - 1)
            {
                if (compareNum(a.substr(l + 1, i - l), "0") == 0)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{

    string str;
    cout << "input zimu to make variables, others for common calculate." << endl;
    getline(cin, str);

    if (str == "zimu")
    {
        cout << "input numbers of variables" << endl;
        getline(cin, str);

        cout << "input each variable type like x=3, no repetition" << endl;
        int a = stoi(str);
        string a1[a] = {};
        char a2[a];
        for (size_t i = 0; i < a; i++)
        {
            getline(cin, str);
            a2[i] = str[0];
            a1[i] = str.substr(2, str.length() - 2);
        }

        cout << "input the formula" << endl;
        getline(cin, str);
        for (size_t i = 0; i < a; i++)
        {
            int m = str.find(a2[i]);
            str.erase(m, 1);
            str.insert(m, a1[i]);
        }

        if (!judgeIllegalInput(str))
        {
            cout << "Invalid input" << endl;
            return 0;
        }

        if (str == "0")
            return 0;

        str = deleteKuohao(str);
        if (judgeChushuZero(str))
        {
            cout << "Do not let divide number to be zero." << endl;
            return 0;
        }
        str = calculateNoKuohao(str);

        NumDeleteKuohao(str);
        if (str.substr(0, 1) == "-")
        {
            str.erase(0, 1);
            str = changeOutput(str);
            str.insert(0, "-");
        }
        else
            str = changeOutput(str);

        cout << str << endl;
    }
    else
    {

        while (true)
        {
            cout << "Input a Formula to calculate, input 0 to exit" << endl;

            getline(cin, str);
            if (!judgeIllegalInput(str))
            {
                cout << "Invalid input" << endl;
                continue;
            }

            if (str == "0")
                return 0;

            str = deleteKuohao(str);
            if (judgeChushuZero(str))
            {
                cout << "Do not let divide number to be zero." << endl;
                continue;
            }
            str = calculateNoKuohao(str);

            NumDeleteKuohao(str);
            if (str.substr(0, 1) == "-")
            {
                str.erase(0, 1);
                str = changeOutput(str);
                str.insert(0, "-");
            }
            else
                str = changeOutput(str);

            cout << str << endl;
        }
    }
}