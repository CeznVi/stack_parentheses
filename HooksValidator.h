#pragma once
#include <string>
#include "DynamicStack.h"
#include "func.h"


class hooksValidator
{
	string obj;

	//string start = "({[";
	//string finish = ")}]";
	string list = "({[)}]";
	bool isEror = false;
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
	int count{};

	for(size_t i{}; i < s.length(); i++)
		for (size_t j{}; j < list.length(); j++)
				if(s[i] == list[j])
					count++;

	if (count >= 2)
		obj = s;
	else
		isEror = true;
}

//перевірка за домомогою динамічного стеку
void hooksValidator::chechToValid()
{
	//якщо строка без 2х дужок, або там зовсім якась нісінітнеця то виходимо із перевірки
	if (isEror == true)
	{
		SetColor(ConsoleColor::Red);
		std::cout << "Невірні данні!\n";
		SetColor(ConsoleColor::White);
		return;
	}

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
	{
		std::cout << "У введеному рядку: " << obj;
		SetColor(ConsoleColor::Green);
		std::cout << "\t дужки розставлені вірно\n";
		SetColor(ConsoleColor::White);
	}
	else
	{
		std::cout << "У введеному рядку: " << obj << "\t дужки розставлені НЕВІРНО\n";

	}


}
