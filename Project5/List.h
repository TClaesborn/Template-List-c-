#pragma once
#include "Node.h"
#include <iostream>

template <typename T> //Skapar en mall f�r typ T
class List
{
private: //Allt efter private: �r private
	std::shared_ptr<Node<T>> head = nullptr;//Pointer till n�sta nod i listan
	
public: //Allt efter public: �r public
	List() //Tom constructor
	{

	}
	void Add(T data) 
	{
		// I c# finns en automatisk garbage collector som rensar upp minnet under runtime.
		// c++ har inte det.
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(data); //Skapar nod att l�gga till i listan
		
		if (head == nullptr) //Kollar om f�rsta v�rdet �r tomt
			head = newNode; //Om tomt, l�gg till h�r.
		else
		{
			auto current = head; // Om head inte �r tomt, current h�ller koll p� position i listan
			while (current->next != nullptr) // Kolla n�sta pos
			{
				current = current->next; // Uppdatera pos i listan
			} //Efter loopen vet vi att vi �r vid slutet av listan.
			current->next = newNode; // vid slutet av listan, l�gg till noden
		}
	}
	void RemoveFirst()
	{
		//auto temp = this->head; //H�ll koll p� tidigare head.
		head = head->next; //Flytta start p� listan.
		//delete temp; //ta bort f�reg�ende head (c++ har ingen egen garbage collector som c#)
	}
	void PrintAll()
	{
		auto current = head;
		while (current != nullptr)
		{
			std::cout << current->value << std::endl;
			current = current->next;
		}
	}
};

