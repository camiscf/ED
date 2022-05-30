#include "linkedStack.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string.h>
using namespace std;


struct operatorStruct
{
	string op;
	int precedence;
};


linkedStack<operatorStruct> operatorStack;
linkedStack<int> operandStack;

bool isoperator(string);
int getprecedence(string);
int calculate();

//Main Function
main()
{
	cout<< "please enter an expression" << endl;
	calculate();
	return 0;
}

bool isoperator(string op)
{
	if(op=="+"||op=="-"||op=="*"||op=="/")
	{
		return true;
	}
	return false;
}

int getprecedence(string op)
{
	if(op=="+"||op=="-")
	{
		return 1;
	}
	else if(op=="*"||op=="/")
	{
		return 2;
	}
}



int calculate()
{
	string token;
	cin >> token;
	operatorStruct NewOp;
	while(token != ";")
	{
		if(isdigit(token[0]))
		{
			int a=atoi(token.c_str());
			operandStack.push(a);
		}
		else if(isoperator(token))
		{
			NewOp.op=token;
			NewOp.precedence=getprecedence(token);
			while(operatorStack.empty() != 0 && operatorStack.top().precedence >= NewOp.precedence)
			{
				int num1=operandStack.top();
				operandStack.pop();
				int num2=operandStack.top();
				operandStack.pop();
				if(operatorStack.top().op =="*")
				{
					operatorStack.pop();
					operandStack.push(num2*num1);
				}
				else if(operatorStack.top().op=="+")
				{
					operatorStack.pop();
					operandStack.push(num2+num1);
				}
				else if(operatorStack.top().op=="-")
				{
					operatorStack.pop();
					operandStack.push(num2-num1);
				}
				else if(operatorStack.top().op=="/")
				{
					operatorStack.pop();
					operandStack.push(num2/num1);
				}
			}
			operatorStack.push(NewOp);
		}
	}
	int result= operandStack.top();
	cout << result << endl;
}