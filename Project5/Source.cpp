#include <iostream>
//Deklaration vs definition
//Deklaration: void doSomething();
//Definition: void doSomething() { do stuff )
#include "List.h" //Header


int main()
{
	
	List<int> list;
	list.Add(3);
	list.Add(5);
	list.Add(6);
	list.Add(12);
	list.RemoveFirst();
	list.PrintAll();
	
	std::cin.get();
}