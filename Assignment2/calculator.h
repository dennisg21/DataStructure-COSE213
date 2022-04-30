#ifndef CALCULATOR_H
#define CALCULATOR_H

//
// Assignment 2 : Simple calculator using Stack
//
// COSE213 Spring 2021
//
// Won-Ki Jeong (wkjeong@korea.ac.kr)
//

#include <iostream>
#include <sstream>
#include <cassert>
#include <math.h>
#include <string.h>
#include "stack.h"


Stack<double> opr; // stack for operands
Stack<char> opt;   // stack for operators


//
// Modify Eval() below to evaluate the given expression
//


int Priority(char opr)//
{
    switch (opr)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '(':
    case ')':
        return 1;
    default:
        return 0;
    }
}

double Eval(char* in)
{
    string buf="                                                      ";
    char Current_op;
    int negative;
    int i = 0, j = 0;

    while (in[i] != '\0')
    {
        if (i + 1 != '\0')
            negative = 0;
        if (in[i] >= 48 && in[i] <= 57) 
        {
            buf[j++] = '|';
            buf[j++] = in[i];
            while (in[++i] >= 48 && in[i] <= 57) 
            {
                buf[j++] = in[i];
            }
            if (in[i] == '.') 
            {
                buf[j++] = '.';
                i += 1;
                while (in[i] >= 48 && in[i] <= 57) 
                {
                    buf[j++] = in[i];
                    i += 1;
                }
            }
        }
        else if (in[i] == '(')
        {
            opr.Push(in[i++]);
        }
        else if (in[i] == ')')
        {

            if (opr.IsEmpty())
                cout << "expression error" << endl;
            else
            {
                Current_op = opr.Top();
                while (Current_op != '(')
                {
                  
                    buf[j++] = '|';
                    buf[j++] = Current_op;
                    opr.Pop();
                    if (opr.IsEmpty())
                    {
                        cout << "expression error" << endl;
                        break;
                    }
                    Current_op = opr.Top();
                }
                opr.Pop();
                i++;
            }
        }

        else if (in[i] == '+' || in[i] == '-' || in[i] == '/' || in[i] == '*')
        {
            if (in[i] == '-')
            {

                if (i == 0)
                    negative = 1;
                else if (in[i - 1] == '+' || in[i - 1] == '-' || in[i - 1] == '/' || in[i - 1] == '*')
                    negative = 1;
                if (negative == 1)
                {
                    buf[j++] = '|';
                    buf[j++] = '-';
                    i += 1;
                    if (in[i] >= 48 && in[i] <= 57) 
                    {
                        buf[j++] = in[i];
                        while (in[++i] >= 48 && in[i] <= 57)
                        {
                            buf[j++] = in[i];
                        }
                        if (in[i] == '.') 
                        {
                            buf[j++] = '.';
                            i += 1;
                            while (in[i] >= 48 && in[i] <= 57)
                            {
                                buf[j++] = in[i];
                                i += 1;
                            }
                        }
                    }
                    continue;
                }
            }


            if (opr.IsEmpty())
            {
                opr.Push(in[i++]);
            }
            else
            {
                char Top = opr.Top();
                if (Priority(Top) < Priority(in[i])) 
                {
                    opr.Push(in[i++]);
                }
                else
                {
                    while (Priority(Top) >= Priority(in[i]))
                    {
                        buf[j++] = '|';
                        buf[j++] = Top;
                        opr.Pop();
                        if (!opr.IsEmpty())
                        {
                            Top = opr.Top();
                        }
                        else
                            break;
                    }
                    opr.Push(in[i++]);
                }
            }

        }
        else
        {
            i += 1;
        }
    }

    while (!opr.IsEmpty())
    {
        char to = opr.Top();
        buf[j++] = '|';
        buf[j++] = to;
        opr.Pop();
    }
    buf[j] = '#';

    double result;
    int x = 0, y;
    int isNum = 0;
    string current = "                               ";
    while(buf[x] != '#')
    {
        isNum = 0;
        if (buf[x] == '|')
        {
            for (y = x + 1;; y++)
            {
                if (buf[y] == '|')
                    break;
                if (buf[y] == '#')
                    break;
            }

           
            for (int k = x + 1; k < y; k++)
            {
                current += buf[k];
            }

        
            for (int k = 0; k < current.size(); k++)
            {
                if (current[k] >= 48 && current[k] <= 57)
                {
                   
                    istringstream iss(current);
                    double num;
                    iss >> num;
                    opr.Push(num);
                    isNum = 1;
                    break;
                }
            }
            if (isNum != 1) {
                double n2 = opr.Top();
                opr.Pop();
                double n1 = opr.Top();
                opr.Pop();
                if (current == "+") {
                    opr.Push(n1 + n2);
                }
                else if (current == "-") {
                    opr.Push(n1 - n2);
                }
                else if (current == "*") {
                    opr.Push(n1 * n2);
                }
                else if (current == "/") {
                    opr.Push(n1 / n2);
                }
            }
            current.erase();
         
        }x++;
        
    }


return opr.Top();

}
#endif
