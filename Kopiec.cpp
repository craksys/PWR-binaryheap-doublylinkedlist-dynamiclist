#include <iostream>
using namespace std;
class Kopiec {
public:
	int size_of_tab = 0;
	int* pointerTab;

	void init_Tab() {
		int* tab = new int[1]; //deklaracja tablicy dynamicznej
		tab[0] = 0;
		pointerTab = tab; //przypisanie tablicy do wska�nik
		size_of_tab++;
	}

	void push_Element(int element) {
		int i=0;
		int* temp = new int[size_of_tab + 1];
		for (; i < size_of_tab; i++) {
			temp[i] = pointerTab[i];
		}
		temp[i] = element;
		delete pointerTab;
		pointerTab = temp;
		size_of_tab++;
		sort_Mound();
	}
	void delete_Element() {
		if (size_of_tab < 2) { return; } //warunek sprawdzaj�cy czy jest mo�liwe usuni�cie z kopca
		int i = 0;
		int* temp = new int[size_of_tab - 1];
		for (; i < size_of_tab-1; i++) {
			temp[i] = pointerTab[i+1];
		}
		delete pointerTab;
		pointerTab = temp;
		size_of_tab--;
		sort_Mound();
	}

	void sort_Mound() {
		int bufor = 0;
		int stop = 0;
		for (int j = 0; j < size_of_tab; j++) {
			for (int i = 0; i < size_of_tab - 1; i++) {
				if (pointerTab[i] < pointerTab[i + 1]) {
					bufor = pointerTab[i];
					pointerTab[i] = pointerTab[i + 1];
					pointerTab[i + 1] = bufor;
					stop++;
				}
			}
			if (stop == 0) { return; }
			else { stop = 0; }
		}
	}
	void search_Element(int element) {
		bool is_find = false;
		for (int i = 0; i < size_of_tab; i++) {
			if (pointerTab[i] == element) {//wydrukuj pozycje elementu
				cout << endl << "Znaleziono podany element na pozycji: " << i;
				is_find = true;
			} 
		}
		if (is_find == false) { cout << endl << "Nie znaleziono pasujacych elementow"; } //jezeli nie znalezion napisz
	}

	void print_Elements() {
		//system("CLS");
		int count_printed = 0;
		int space = 30;
		for (int i = 0; i < size_of_tab; i++) {
			switch (i) {
			case 1:
				cout << endl;
				space = 27;
				for (int j = 0; j < space; j++) { cout << " "; }
				break;
			case 3:
				cout << endl;
				space = 24;
				for (int j = 0; j < space; j++) { cout << " "; }
				break;
			case 7:
				cout << endl;
				space = 17;
				for (int j = 0; j < space; j++) { cout << " "; }
				break;
			case 15:
				cout << endl;
				space = 0;
				for (int j = 0; j < space; j++) { cout << " "; }
				break;
			case 31:
				cout << endl;
				break;
			default:
				break;
			}
			if (i == 0) { for (int j = 0; j < space; j++) { cout << " "; } }
			cout << pointerTab[i]<<" ";
		}
	}
};



