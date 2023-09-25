#include <iostream>
using namespace std;
class Lista {
public:
    int sizeoflist = 1;
    struct lista
    {
        lista *last;    // WskaŸnik na górny element listy (gdy elementu nie ma równe 0)
        int integer;        // int
        lista *next;// WskaŸnik na dolny element listy (gdy elementu nie ma równe 0)
    };
    lista lista0; //poczatek listy
    lista* tempList; //lista pomocnicza
    

    void initList() { //inicjalizacja listy
        lista0.next = NULL;
        lista0.last = NULL;
        lista0.integer = 0;
        tempList = &lista0;
    }

    void fillWithRandomData(int elements) {
        if (elements < 1) { //sprawdzenie poprawnoœci podanej liczby elementów
            cout << "\nB³ad, podano liczbê mniejsz¹ ni¿ 1";
            return;
        }

        for (int i = 0; i < elements; i++) {
            
        }


    }

    void printAllElements() {
        lista* lista1 = lista0.next;//przypisanie do wskaŸnika natêpnego elementu
        cout << "|" << lista0.integer;
        if (lista0.next != NULL) {
            lista1 = lista0.next;
        }
        else { return; }

        for (int i = 1; i < sizeoflist; i++) {
            cout << lista1->integer<<endl;
            lista1 = lista1->next;
        }
    }

    void addElementLast(int element) {
        tempList = &lista0; //przypisanie do listy tymczasowej pierwszego elementu
        while (tempList->next != nullptr) {
            tempList = tempList->next;
            cout << "wykonanotohujstwo";
        };
        
        lista listaNew; //tworzenie nowego elementu
        listaNew.last = tempList;
        listaNew.next = NULL;
        listaNew.integer = element;
        tempList->next = &listaNew;
        sizeoflist++;
    }

    void add(int element) {
        tempList = &lista0;
        int i = 1;
        lista* listHelper;
        tempList = &lista0; //przypisanie do listy tymczasowej pierwszego elementu
        while (tempList->next) {
            tempList = tempList->next;
            i++;
        }
        cout << "tojesti:"<<i<<endl;
    }

    void test() {
        tempList = &lista0;
        cout << tempList->integer << endl;
        tempList = tempList->next;
        cout << tempList->integer << endl;
    }


};
