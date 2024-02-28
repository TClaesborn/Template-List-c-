#pragma once
#include "Node.h"
#include <iostream>

template <typename T> //Skapar en mall för typ T
class List
{
private: //Allt efter private: är private
	std::shared_ptr<Node<T>> head = nullptr;//Pointer till nästa nod i listan
	
public: //Allt efter public: är public
	List() //Tom constructor
	{

	}
	void Add(T data) 
	{
		// I c# finns en automatisk garbage collector som rensar upp minnet under runtime.
		// c++ har inte det.
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(data); //Skapar nod att lägga till i listan
		
		if (head == nullptr) //Kollar om första värdet är tomt
			head = newNode; //Om tomt, lägg till här.
		else
		{
			auto current = head; // Om head inte är tomt, current håller koll på position i listan
			while (current->next != nullptr) // Kolla nästa pos
			{
				current = current->next; // Uppdatera pos i listan
			} //Efter loopen vet vi att vi är vid slutet av listan.
			current->next = newNode; // vid slutet av listan, lägg till noden
		}
	}
	void RemoveFirst()
	{
		//auto temp = this->head; //Håll koll på tidigare head.
		head = head->next; //Flytta start på listan.
		//delete temp; //ta bort föregående head (c++ har ingen egen garbage collector som c#)
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

