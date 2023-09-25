#pragma once
#include <iostream>
using namespace std;

class Lista2
{
public:
	typedef struct Element
	{
		Element(int newValue)
		{
			value = newValue;
			next = nullptr;
			prev = nullptr;
		}

		Element* next;
		int value;
		Element* prev;
	};
	Element* first;
	Element* last;

	void init() {
		Element* ok = new Element(0);
		first = ok;
		last = ok;
	}

	void push_Back(int value)
	{
		Element* temp = last;
		Element* temp2;
		temp2 = new Element(value);
		
			temp->next = temp2;
			temp2->prev = temp;
			last = temp2;
	}

	void delete_Back() {
		Element* temp = first;
		Element* temp2;
		if (temp->next == nullptr && temp->prev == nullptr) { return; }//warunek sprawdzaj¹cy czy zosta³ wiêcej ni¿ jeden element
		temp = last;
		temp2 = temp->prev;
		last = temp2;
		temp2->next = nullptr;
		delete temp;
	}

	void push_Front(int value) {
		Element* temp = first;
		Element* temp2;
		temp2 = new Element(value);
		temp2->next = temp;
		temp->prev = temp2;
		first = temp2;
	}

	void delete_Front() {
		Element* temp = first;
		if (temp->next == nullptr && temp->prev == nullptr) { return; }//warunek sprawdzaj¹cy czy zosta³ wiêcej ni¿ jeden element
		else {
			Element* temp2;
			temp2 = temp->next;
			temp2->prev = nullptr;
			first = temp2;
			delete temp;
		}
	}

	void push_Selected(int value, int place) {
		int i = 0;
		if (place < 0) { return; }
		else if (place == 0) { 
			push_Front(value);
			return;
		}//warunek sprawdzaj¹cy czêœciow¹ poprawnoœæ miejsca
		Element* temp = first;
		Element* temp2;
		temp2 = new Element(value);
		while (temp->next != nullptr && i < place)
		{
			temp = temp->next;
			i++;
		}
		//if (temp->next == nullptr) { last = temp2; }
		temp2->next = temp->next;
		temp2->prev = temp;
		temp->next = temp2;
	}

	void delete_Selected(int place) {
		Element* temp = first;
		Element* temp2;
		if (place < 0) { return; }
		else if (place == 0) {
			delete_Front(); 
			return;
		}
		if (first->next == nullptr && first->prev == nullptr) { return; } //warunek sprawdzaj¹cy czy zosta³ wiêcej ni¿ jeden element
		int i = 0;
		while (temp->next != nullptr && i < place)
		{
			temp = temp->next;
			i++;
		}
		temp2 = temp->prev;
		temp2->next = temp->next;
		temp2 = temp->next;
		if (temp2 != nullptr) { temp2->prev = temp->prev; }
		if (temp == last) { delete_Back(); return; }
		delete temp;
	}

	void search_Element(int element) {
		Element* temp = first;
		int position = 0;
		bool is_find = false;
		while (temp != nullptr)
		{
			if (temp->value == element) {
				//cout << endl << "Znaleziono element na pozycji: " << position;
				is_find = true;
			}
			temp = temp->next;
			position++;
		}
		//if(is_find == false) { cout << endl << "Nie znaleziono pasujacych elementow"; } //jezeli nie znalezion napisz
	}

	void print_All()
	{
		Element* temp = first;
		while (temp != nullptr)
		{
			cout  << temp->value<<"|";
			temp = temp->next;
		}
		cout <<endl;
	}


};

