
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tablica.cpp"
#include <windows.h>
#include <iomanip>
#include "Lista.cpp"
#include "Lista2.cpp"
#include "Kopiec.cpp"

Kopiec kopiec;
Tablica tablica;
Lista2 lista;
using namespace std;

long long int read_QPC() //pomiar czasu funkcji
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

int main()
{
    double sum = 0;
    lista.init();
    int random = 0;
    kopiec.init_Tab();
    srand(time(NULL));
    bool is_tab_created = false;
    bool is_list_created = false;
    bool is_mound_created = false;
    short menu;
    /*
    //testy 
    long long int frequency, start, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
    for (int i = 0; i < 50000; i++) {
        random = rand() % 1000;
        kopiec.push_Element(random);
    }
    kopiec.sort_Mound();
    start = read_QPC();
    //początek kodu ktorego czas wykonania mierzymy

    
    //koniec
    elapsed = read_QPC() - start;
    cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed/200 /
        frequency << endl;
    cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed)/200 /
        frequency << endl;
    cout << "Time [us] = " << setprecision(3) << (1000000.0 * elapsed)/200 /
        frequency << endl << endl;
    system("PAUSE");
    return 1;
    
    //panel*/
    cout << "Projekt SDiZO nr. 1" << endl;
    while (true) {
        cout << endl << "Wybierz strukture: " << endl;
        cout << "1. Tablica dynamiczna" << endl;
        cout << "2. Lista dwukierunkowa" << endl;
        cout << "3. Kopiec binarny" << endl;
        cin >> menu;
        while (menu == 1) {
            int select = 0;
            int help1 = 0;
            int help2 = 0;
            if (is_tab_created == false) {
                tablica.getSizeOfTab();
                tablica.createTabAndFillWithNull();
                is_tab_created = true;
            }
            cout << endl << "Dostepne operacje: " << endl;
            cout << "1. Dodaj element na poczatku" << endl;
            cout << "2. Dodaj element na koncu" << endl;
            cout << "3. Dodaj element na wybranym miejscu" << endl;
            cout << "4. Usun element na poczatku" << endl;
            cout << "5. Usun element na koncu" << endl;
            cout << "6. Usun element na wybranym miejscu" << endl;
            cout << "7. Wypelnij tablice losowymi danymi" << endl;
            cout << "8. Wyszukaj element" << endl;
            cout << "9. Wypisz wszystkie elementy" << endl;
            cout << "10. Wyjdz" << endl;
            cout << "Wpisz: ";
            cin >> select;
            switch (select) {
            case 1:
                cout << endl << "Wpisz element do dodania: ";
                cin >> help1;
                tablica.addFirstElement(help1);
                break;
            case 2:
                cout << endl << "Wpisz element do dodania: ";
                cin >> help1;
                tablica.addLastElement(help1);
                break;
            case 3:
                cout << endl << "Wpisz element do dodania: ";
                cin >> help1;
                cout << endl << "Podaj pozycje: ";
                cin >> help2;
                tablica.addSelectedElement(help2, help1);
                break;
            case 4:
                cout << endl << "wykonano";
                tablica.removeFirstElement();
                break;
            case 5:
                cout << endl << "wykonano";
                tablica.removeLastElement();
                break;
            case 6:
                cout << endl << "Podaj pozycje: ";
                cin >> help2;
                tablica.removeSelectedElement(help2);
                break;
            case 7:
                tablica.fillWithRandomData();
                cout << endl << "wykonano";
                break;

            case 8:
                cout << endl << "Podaj szukany elemment: ";
                cin >> help1;
                tablica.searchElement(help1);
                break;
            case 9:
                tablica.printAllVeriables();
                break;
            case 10:
                menu = 0;
                break;

            default:
                break;
            }
        }
        while (menu == 2) {
            int select = 0;
            int help1 = 0;
            int help2 = 0;

            cout << endl << "Dostepne operacje: " << endl;
            cout << "1. Dodaj element na poczatku" << endl;
            cout << "2. Dodaj element na koncu" << endl;
            cout << "3. Dodaj element na wybranym miejscu" << endl;
            cout << "4. Usun element na poczatku" << endl;
            cout << "5. Usun element na koncu" << endl;
            cout << "6. Usun element na wybranym miejscu" << endl;
            cout << "7. Wypelnij liste losowymi danymi" << endl;
            cout << "8. Wyszukaj element" << endl;
            cout << "9. Wypisz wszystkie elementy" << endl;
            cout << "10. Wyjdz" << endl;
            cout << "Wpisz: ";
            cin >> select;
            switch (select) {
            case 1:
                cout << endl << "Wpisz element do dodania: ";
                cin >> help1;
                lista.push_Front(help1);
                break;
            case 2:
                cout << endl << "Wpisz element do dodania: ";
                cin >> help1;
                lista.push_Back(help1);
                break;
            case 3:
                cout << endl << "Wpisz element do dodania: ";
                cin >> help1;
                cout << endl << "Podaj pozycje: ";
                cin >> help2;
                lista.push_Selected(help1, help2);
                break;
            case 4:
                cout << endl << "wykonano";
                lista.delete_Front();
                break;
            case 5:
                cout << endl << "wykonano";
                lista.delete_Back();
                break;
            case 6:
                cout << endl << "Podaj pozycje: ";
                cin >> help2;
                lista.delete_Selected(help2);
                break;
            case 7:
                cout << "Podaj ilosc elementow losowych: ";
                cin >> help1;
                for (int i = 0; i < help1; i++) {
                    help2 = rand() % 1000;
                    lista.push_Back(help2);
                }
                break;

            case 8:
                cout << endl << "Podaj szukany element: ";
                cin >> help1;
                lista.search_Element(help1);
                break;
            case 9:
                lista.print_All();
                break;
            case 10:
                menu = 0;
                break;

            default:
                break;
            }
        }
        while (menu == 3) {
            int select = 0;
            int help1 = 0;
            int help2 = 0;

            cout << endl << "Dostepne operacje: " << endl;
            cout << "1. Dodaj element" << endl;
            cout << "2. Usun element z wierzcholka" << endl;
            cout << "3. Wypelnij kopiec losowymi danymi" << endl;
            cout << "4. Wyszukaj element" << endl;
            cout << "5. Wyswietl kopiec" << endl;
            cout << "6. Wyjdz" << endl;
            cout << "Wpisz: ";
            cin >> select;
            switch (select) {
            case 1:
                cout << endl << "Wpisz element do dodania: ";
                cin >> help1;
                kopiec.push_Element(help1);
                break;
            case 2:
                cout << endl << "Wykonano";
                kopiec.delete_Element();
                break;
            case 3:
                cout << "Podaj ilosc elementow losowych: ";
                cin >> help1;
                for (int i = 0; i < help1; i++) {
                    help2 = rand() % 1000;
                    kopiec.push_Element(help2);
                }
                break;

            case 4:
                cout << endl << "Podaj szukany element: ";
                cin >> help1;
                kopiec.search_Element(help1);
                break;
            case 5:
                kopiec.print_Elements();
                break;
            case 6:
                menu = 0;
                break;

            default:
                break;
            }
        }
    }
   

    //cout << "Wybierz strukture:";
    //cin >> menu;
   // cout << "\n";

    //switch (menu) //menu wyboru
    //{
    //case 1:
     //   cout << "Wybrano tablice\n";
    //    createtab();
    //    break;
    //default:    
   //     cout << "Nie wybrano poprawnej funkcji\n";
   // }


}

