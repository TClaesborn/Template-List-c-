#pragma once
#include <iostream>
template <typename T>
class Node
{
public:
	T value;
	std::shared_ptr<Node<T>> next = nullptr;

	Node(T data) 
		:value(data)
	{
		
	}
};

