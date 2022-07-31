#pragma once
#include <string>
#include "DynamicStack.h"


class hooksValidator
{
	string obj;

	//string start = "({[";
	//string finish = ")}]";
	string list = "({[)}]";
	bool isStartSymbol(int i);
	bool isFinishSymbol(int i);

public:
	//Конструктори
	hooksValidator() {};
	hooksValidator(string s) {takeInput(s);}
	
	void takeInput(string s);
	void chechToValid();

};

bool hooksValidator::isStartSymbol(int i)
{
	if (obj[i] == 91 || obj[i] == 40 || obj[i] == 123)
		return true;
	else
		return false;
}

bool hooksValidator::isFinishSymbol(int i)
{
	if (obj[i] == 93 || obj[i] == 41 || obj[i] == 125)
		return true;
	else
		return false;
}

//приймає строку, записує лише дужки
void hooksValidator::takeInput(string s)
{
	//for (size_t i{}; i < s.length(); i++)
	//	for (size_t j{}; j < list.length(); j++)
	//			if(s[i] == list[j])
	//				obj += s[i];
	obj = s;
}

//перевірка за домомогою динамічного стеку
void hooksValidator::chechToValid()
{
	//Максимальна емність динамічного стеку чар 100 символів
	DynamicStack<char> stack;

	for (size_t i{}; i < obj.length(); i++)
	{
			if(isStartSymbol(i))
				stack.push(obj[i]);
			else if(isFinishSymbol(i))
			{
				if ((obj[i] - stack.peek()) == 2 || (obj[i] - stack.peek()) == 1)
					stack.pop();
				else 
					stack.push(obj[i]);
			}
	}

	if (stack.isEmpty())
		std::cout << "У введеному рядку дужки розставлені вірно\n";
	else
	{
		std::cout << "У введеному рядку дужки розставлені НЕВІРНО!\n";

	}


}
