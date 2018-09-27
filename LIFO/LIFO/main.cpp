#include "pch.h"
#include <iostream>

#include "CNode.h"
#include "CStack.h"

int main()
{
	CStack<int> stack(5);
	stack.push(1);
	if (stack.empty())
	{
		std::cout << "vide" << std::endl;
	}
	else std::cout << "il n'est pas vide" << std::endl;
	stack.push(2);
	stack.push(stack.top()->GetData() * 2);
	if (stack.full())
	{
		std::cout << "rempli" << std::endl;
	}
	else std::cout << "il n'est pas plein" << std::endl;

	//stack.pop();
	stack.show();
	std::cout << std::endl;
	CStack<int> stack2(stack);
	
	stack2.push(8);
	stack2.push(10);
	stack2.pop();
	stack2.show();

	
}
