#pragma once
#include <string>
#include "DynamicStack.h"
#include "func.h"


class hooksValidator
{
	string obj;
	string list = "({[)}]";
	//змінна стану класу
	bool isEror = false;
	//інспектор символів початку дужок
	bool isStartSymbol(int i);
	//інспектор символів закінчення дужок
	bool isFinishSymbol(int i);

public:
	//Конструктори
	hooksValidator() {};
	hooksValidator(string s) {takeInput(s);}
	//отримати та перевірити данні
	void takeInput(string s);
	//Метод перевірки по правильній розстановці дужок
	void chechToValid();
	//Метод який вказує на помилку в рядку при розставленні дужок 
	void showErors(DynamicStack<char>& stack);

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
				//2 та 1 - різниця між символами відкритої та закритої дужок
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
		std::cout << "У введеному рядку: " << obj;
		SetColor(ConsoleColor::Red);
		std::cout << "\t дужки розставлені НЕВІРНО\n";
		SetColor(ConsoleColor::White);
		showErors(stack);
	}


}

//Метод який вказує на помилку в рядку при розставленні дужок 
void hooksValidator::showErors(DynamicStack<char>& stack)
{
	stack.clear();
	std::cout << "Червоним виділено помилкові дужки\n";


	for (size_t i{}; i < obj.length(); i++)
	{
		if (isStartSymbol(i))
		{
			stack.push(obj[i]);
			SetColor(ConsoleColor::Green);
			std::cout << obj[i];
			SetColor(ConsoleColor::White);

		}
		else if (isFinishSymbol(i))
		{
			//2 та 1 - різниця між символами відкритої та закритої дужок
			if ((obj[i] - stack.peek()) == 2 || (obj[i] - stack.peek()) == 1)
				stack.pop();
			else
			{
				SetColor(ConsoleColor::Red);
				std::cout << obj[i];
				SetColor(ConsoleColor::White);
				stack.push(obj[i]);
			}
		}
		else
			std::cout << obj[i];
	}
	std::cout << "\n";
}
