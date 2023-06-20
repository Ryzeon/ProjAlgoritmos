#pragma once
#include "List.h"
template<class K> <class V>
// K -> Generico
// V -> Genericos
class HashEntidad 
{
private:
	int key, value;
public:
	HashEntidad(int key, int value) 
	{
		this->key = key;
		this->value = value;
	}
	int getKey() 
	{
		return key;
	}
	int getValue()
	{
		return value;
	}
};

class HashTable {
private:
	HashEntidad** table;
	int num_element;
	int size;

	int hashFunction(int key)
	{
		return key % size;
	}

	// char -> obtener valores ascii

	// string -> recorrer los char y obtner los volores ascii

public:
	HashTable(int size = 200) 
	{
		this->size = size;
		table = new HashEntidad* [size];
		for (int i = 0; i < size; i++)
		{
			table[i] = nullptr;
		}num_element = 0;
	}
	~HashTable() 
	{
		for (int i = 0; i < size; i++) {
			if (table[i] = nullptr) {
				delete table[i];
			}
			delete[] table;
		}
	}
	void insert(int key, int value) 
	{
		int base, hash, step;
		if (num_element == size) return;
		// hash funtion #1
		base = key % size;
		hash = base;
		// constant for hash #2
		step = 0;
		while (table[hash] != nullptr) 
		{
			// hash funtion #2
			hash = (step + base) % size;
			step++;
		}
	}
	// method #1
	int search(int key) 
	{
		int step = 0;
		int i, base;
		i = base = key % size;
		while (true) 
		{
			if (table[i] == nullptr)
			{
				return -1;
			}
			else if (table[i]->getKey() == key) 
			{
				return i;
			}
			else
				step++;	
			i = (base + step) % size;
		}
	}
	// method #2
	int find_first(function<bool(int)>predicate)
	{
		
	}
	//method #3
	int remove_if(function<bool(int)>predicate) {

	}
};
