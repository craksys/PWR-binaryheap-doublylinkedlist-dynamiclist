#include <iostream>
#include <fstream> //import biblioteki fstream
#include <stdio.h> //import biblioteki stdio.h
using namespace std;
class Tablica {
	public:
		
        int size_of_tab = 1; //rozmiar tablicy dynamicznej
		int actual_size_of_tab = 1;
		int* pointerTab; //wska�nik na tablic� 

		void delete_Tab() {
			int* tab = new int[1];
			tab[0] = 0;
			pointerTab = tab;
			size_of_tab = 1;

		}
		void getSizeOfTab() {
			cout << "Podaj rozmiar tablicy: ";
			cin >> size_of_tab;
			if (size_of_tab < 1) { size_of_tab = 1; }
			actual_size_of_tab = size_of_tab;
		}

		void createTabAndFillWithNull() { //wyzerowanie tablicy aby unikn�� b��dnych danych
			int* tab = new int[size_of_tab]; //deklaracja tablicy dynamicznej
			pointerTab = tab; //przypisanie tablicy do wska�nika


			for (int i = 0; i < size_of_tab; i++) { //wype�nij tablice nullami 
				tab[i] = NULL;
			}
		}

		void fillWithRandomData() {
			srand(time(NULL));

			for (int i = 0; i < actual_size_of_tab; i++) { //wpisanie losowych licz do tablicy
				pointerTab[i] = rand() % 1000; //zakres losowanych liczb do tablicy
			}
		}

		void printAllVeriables() {
			for (int i = 0; i < actual_size_of_tab; i++) {
				cout << pointerTab[i]<<"|";
			}
			cout << "\n";
		}

		void addFirstElement(int element) {
			int* tempTab = new int[actual_size_of_tab + 1];
			tempTab[0] = element;

			for (int i = 0; i < actual_size_of_tab; i++) {
				tempTab[i + 1] = pointerTab[i];
			}
			actual_size_of_tab++;
			delete pointerTab;

			int* tab = new int[actual_size_of_tab];
			pointerTab = tab;


			for (int i = 0; i < actual_size_of_tab; i++) {
				tab[i] = tempTab[i];
			}
			delete tempTab;
		}

		void addLastElement(int element) {
			int* tempTab = new int[actual_size_of_tab + 1]; //tworzenie tablicy tymczasowej

			for (int i = 0; i < actual_size_of_tab; i++) {
				tempTab[i] = pointerTab[i];
			}
			actual_size_of_tab++;
			tempTab[actual_size_of_tab - 1] = element;
			delete pointerTab;

			int* tab = new int[actual_size_of_tab];

			for (int i = 0; i < actual_size_of_tab; i++) {
				tab[i] = tempTab[i];
			}
			pointerTab = tab;
			
			delete tempTab;
		}

		void removeFirstElement() {
			int* tempTab = new int[actual_size_of_tab - 1]; //tworzenie tablicy tymczasowej

			for (int i = 0; i < actual_size_of_tab - 1; i++) {
				tempTab[i] = pointerTab[i + 1];
			}

			delete pointerTab; //usuni�cie starej tablicy
			actual_size_of_tab--;
			int* tab = new int[actual_size_of_tab]; //ponowne utworzenie tablicy

			for (int i = 0; i < actual_size_of_tab; i++) {
				tab[i] = tempTab[i];
			}

			pointerTab = tab; //przypisanie nowej tablicy do wska�nika
			delete tempTab; //usuni�cie tablicy tymczasowej
		}
	
		void removeLastElement() {
			int* tempTab = new int[actual_size_of_tab - 1]; //tworzenie tablicy tymczasowej

			for (int i = 0; i < actual_size_of_tab - 1; i++) { //przepisanei warto�ci do tablicy tymczasowej
				tempTab[i] = pointerTab[i];
			}

			delete pointerTab;
			actual_size_of_tab--;
			int* tab = new int[actual_size_of_tab]; //ponowne utworzenie tablicy

			for (int i = 0; i < actual_size_of_tab; i++) {
				tab[i] = tempTab[i];
			}
			pointerTab = tab; //przypisanie nowej tablicy do wska�nika
			delete tempTab; //usuni�cie tablicy tymczasowej
		}

		void addSelectedElement(int position, int element) {
			int* tempTab = new int[actual_size_of_tab + 1]; //tworzenie tablicy tymczasowej

			if (position < 0 || position > actual_size_of_tab) { //sprawdzanie czy mo�na zapisa� dane w podane miesjce
				cout << "\nPrzekroczono zakres tablicy!!!";
				return;
			}
			tempTab[position] = element;//wpisanie elementu na podan� pozycj�

			for (int i = 0; i < actual_size_of_tab + 1; i++) {
				if (i < position) {
					tempTab[i] = pointerTab[i];
				}
				else if (i > position) {
					tempTab[i] = pointerTab[i - 1];
				}
			}
			delete pointerTab;
			actual_size_of_tab++;
			int* tab = new int[actual_size_of_tab]; //ponowne utworzenie tablicy
			for (int i = 0; i < actual_size_of_tab; i++) {
				tab[i] = tempTab[i];
			}
			pointerTab = tab; //przypisanie nowej tablicy do wska�nika
			delete tempTab; //usuni�cie tablicy tymczasowe

		}

		void removeSelectedElement(int position) {
			int* tempTab = new int[actual_size_of_tab - 1]; //tworzenie tablicy tymczasowej

			if (position < 0 || position > actual_size_of_tab) { //sprawdzanie czy mo�na usun�� dane w podanym miesjce
				cout << "\nPrzekroczono zakres tablicy!!!";
				return;
			}

			for (int i = 0; i < actual_size_of_tab; i++) {
				if (i < position) {
					tempTab[i] = pointerTab[i];
				}
				else if (i > position) {
					tempTab[i - 1] = pointerTab[i];
				}
			}
			delete pointerTab;
			actual_size_of_tab--;
			int* tab = new int[actual_size_of_tab]; //ponowne utworzenie tablicy

			for (int i = 0; i < actual_size_of_tab; i++) {
				tab[i] = tempTab[i];
			}
			pointerTab = tab; //przypisanie nowej tablicy do wska�nika
			delete tempTab; //usuni�cie tablicy tymczasowe
		}

		void searchElement(int tofind) {
			bool is_find = false;
			for (int i = 0; i < actual_size_of_tab; i++) {
				if (pointerTab[i] == tofind) {
					cout << "\nZnaleziono na pozycji: " << i;
					is_find = true;
				}
			}
			if (is_find == false) { cout << endl << "Nie znaleziono pasujacych elementow"; } //jezeli nie znalezion napisz
		}
		
  
};
