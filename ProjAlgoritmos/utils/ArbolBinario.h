#pragma once
#include <functional>
using namespace std;

template <class T>
class Node {
public:
	T elem;
	Node* left, rigth;
};

template <class T>
class ArbolBinario 
{
	typedef function <int(T, T)> comp;
	Node<T>* root;
	void(*procesar)(T);

	comp compare;
private:
	bool search(Node<T>* node, T e) {
		if (node == nullptr)
			return false;
		else {
			int r = compare(node->elem, e);
			if (r == 0)
				return true;
			else if (r < 0) {
				return search(node->rigth, e);
			}
			else
				return search(node->left, e);
		}
	}
	Node<T>* obtain(Node<T>* node, T e) {
		if (node == nullptr)
			return nullptr;
		else {
			int r = compare(node->elem, e);
			if (r == 0)
				return node;
			else if (r < 0) {
				return search(node->rigth, e);
			}
			else
				return search(node->left, e);
		}
	}
	bool insert(Node<T>*& node, T e) {
		if (node == nullptr) {
			node = new Node<T>();
			node->elem = e;
			return true;
		}
		else {
			int r = compare(node->elem, e);
			if (r == 0)
				return false;
			else if (r < 0) {
				return insert(node->rigth, e);
			}
			else
				return insert(node->left, e);
		}
	}
	bool remove(Node<T>*& node, T e)
	{
		if (node == nullptr) return false;
		else
		{
			int r = compare(node->elem, e);
			if (r < 0)
			{
				return remove(node->rigth, e);
			}
			else if (r > 0)
			{
				return remove(node->left, e);
			}
			else
			{
				if (node->rigth == nullptr && node->left == nullptr)
				{
					node = nullptr;
					delete node;
					return true;
				}
				else if (node->left == nullptr) 
				{
					node = node->rigth;
					return true;
				}
				else if (node->rigth == nullptr)
				{
					node = node->left;
					return true;
				}
				else
				{
					Node<T>* aux = node->rigth;
					while (aux->left != nullptr)
					{
						aux = aux->left;
					}
					node->elem = aux->elem;
					return remove(node->rigth, aux->elem);
				}
			}
		}
	}
	bool isEmpty()
	{
		return root = nullptr;
	}
public:
	ArbolBinario(void(*anotherPointerAFunction)(T)) 
	{
		this->procesar = anotherPointerAFunction;
		this->compare = [](T a, T b)->int 
		{
			return a - b;
		}
		root = nullptr;
	}
	bool Insert(T e)
	{
		return insert(root, e);
	}
	bool Remove(T e)
	{
		return remove(root, e);
	}
	// method #1
	bool Search(T e) 
	{
		return search(root, e);
	}
	// method #2
	int find_first(function<bool(int)>predicate)
	{

	}
	//method #3
	int remove_if(function<bool(int)>predicate) 
	{

	}

};
