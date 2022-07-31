#pragma once
#include <string>
#include "DynamicStack.h"

class hooksValidator
{
	string obj;

public:
	//Конструктори
	hooksValidator() {};
	hooksValidator(string s) {takeInput(s);}
	
	void takeInput(string s);
	void chechToValid();

};

//приймає строку, видаляє пробіли
void hooksValidator::takeInput(string s)
{
	std::cout << "STR LENGTH : " << s.length() << '\n';
	string temp;

	for (size_t i{}; i < s.length(); i++)
		if(s[i] != 32)
			obj += s[i];
	
	std::cout << obj << '\n';
	std::cout << "STR LENGTH : " << obj.length() << '\n';

}

//перевірка за домомогою динамічного стеку
void hooksValidator::chechToValid()
{
}
