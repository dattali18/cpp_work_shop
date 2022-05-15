// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 8.1


#include <iostream>
#include <sstream>
#include "StackVector.h"
#include "string"

std::string infixToPostfix(std::string str);
int calcPostfix(std::string str);
int precedence(char c);

int main() {
    std::string exp;
    std::cout << "enter an infix expression as a string" << std::endl;
    std::cin >> exp;
    std::string postfix = infixToPostfix(exp);
    std::cout << "in postfix form: " << postfix << std::endl;
    std::cout << "calculated value: " << calcPostfix(postfix) << std::endl;
    return 0;
}

// function to decide if an operator has a precedence over another
int precedence(char c) {
    if(c == '/' || c == '*') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }
    return -1;
}

// function to transform any infix input to postfix
std::string infixToPostfix(std::string str) {
    std::string postfix;
    StackVector<char> st(str.size());

// looping through the string

    for (int i = 0; i < str.size(); ++i) {
        char ch = str[i];
//      if the char is a digit we push it into the stack
        if (ch >= '0' && ch <= '9') {
            postfix += ch;
//            in case the number is greater than 10
            if(str[i+1] < '0' || str[i+1] > '9')
                postfix += " ";

        } else if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            while(st.top() != '(') {
                postfix += st.pop();
                postfix += " ";
            }
            st.pop();
        } else {
            while (!st.isEmpty() && precedence(str[i]) <= precedence(st.top())) {
                postfix += st.pop();
                postfix += " ";
            }
            st.push(ch);
        }
    }

    while (!st.isEmpty()) {
        postfix += st.pop();
        postfix += " ";
    }

    return postfix;
}

// function to calculate the value of the postfix input

int calcPostfix(std::string str) {
    StackVector<int> st(str.size());
    int num1, num2;
//  looping through the string
    for (int i = 0; i < str.size(); ++i) {
        char ch = str[i];
//      if the char is a digit
        if (ch >= '0' && ch <= '9') {
            std::stringstream ss;
            ss << str.substr(i, str.size() - i);
            int temp;
            ss >> temp;
            st.push(temp);
            if(temp >= 10) i++;
        }


        switch (ch) {
            case '+':
                num1 = st.pop();
                num2 = st.pop();
                st.push(num1 + num2);
                break;
            case '-':
                num1 = st.pop();
                num2 = st.pop();
                st.push(num2 - num1);
                break;
            case '*':
                num1 = st.pop();
                num2 = st.pop();
                st.push(num1 * num2);
                break;
            case '/':
                num1 = st.pop();
                num2 = st.pop();
                st.push(num2 / num1);
                break;
            default:
                break;
        }
    }
    return st.top();
}