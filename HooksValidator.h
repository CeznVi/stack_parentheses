#pragma once
#include <string>
#include "DynamicStack.h"


class hooksValidator
{
	string obj;

	string start = "({[";
	string finish = ")}]";
	string list = "({[)}]";

public:
	//Конструктори
	hooksValidator() {};
	hooksValidator(string s) {takeInput(s);}
	
	void takeInput(string s);
	void chechToValid();

};

//приймає строку, записує лише дужки
void hooksValidator::takeInput(string s)
{
	for (size_t i{}; i < s.length(); i++)
		for (size_t j{}; j < list.length(); j++)
				if(s[i] == list[j])
					obj += s[i];
	
	//std::cout << obj << '\n';
	//std::cout << "STR LENGTH : " << obj.length() << '\n';
}

//перевірка за домомогою динамічного стеку
void hooksValidator::chechToValid()
{
	//Максимальна емність динамічного стеку чар 100 символів
	DynamicStack<char> stack;

	for (size_t i{}; i < obj.length(); i++)
		for (size_t j{}; j < start.length(); j++)
		{
			if (stack.peek() == finish[j])
				stack.pop();
			else
			{
				if (obj[i] == start[j])
					stack.push(obj[i]);
				else if (obj[i] == finish[j])
					stack.push(obj[i]);
			}


				
		}


	




	//for (size_t i{}; i < obj.length(); i++)
	//	for (size_t j{}; j < start.length(); j++)
	//	{
	//			if (obj[i] == start[j])
	//				stack.push(obj[i]);
	//			else if (obj[i] == finish[j])
	//				stack.push(obj[i]);
	//	}

	stack.print();




}
