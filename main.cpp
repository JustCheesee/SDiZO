//@author Daniel Gaida, nr. 264467

#include <fstream>
#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include "DoublyLinkedList.h"
#include "DoublyLinkedList.cpp"
#include "Node.cpp"
#include "MaxHeap.h"
#include "MaxHeap.cpp"
#include "BRTree.h"
#include "BRTree.cpp"
#include "BRNode.cpp"
using namespace std;

int main(){

    while(true){
        system("cls");
        cout << "Witaj! Wybierz strukture do utworzenia: \n";
        cout << "1. Tablica \n";
        cout << "2. Lista dwukierunkowa \n";
        cout << "3. Kopiec binarny \n";
        cout << "4. Drzewo czerwono-czarne \n";
        int chosen;
        cin >> chosen;
        int isChosen = true;
        switch(chosen){
            case 1:{
                    DynamicArray x;
                    string myText;
                    ifstream MyReadFile("config.txt");
                    int i = 0;
                    while (getline (MyReadFile, myText)) {
                        if(i > 0)x.addEnd(stoi(myText));
                        else i ++;
                    }
                    MyReadFile.close();
                    cout << "Utworzona struktura: \n";
                while(isChosen){
                    system("cls");
                    x.printArray();
                    cout << "\n Wybierz operacje do wykonania: \n";
                    cout << "1. Dodanie na poczatek tablicy \n";
                    cout << "2. Dodanie na koniec tablicy \n";
                    cout << "3. Dodanie w dowolne miejsce tablicy \n";
                    cout << "4. Usuniecie z poczatku tablicy \n";
                    cout << "5. Usuniecie z konca tablicy \n";
                    cout << "6. Usuniecie z dowolnego miejsca tablicy \n";
                    cout << "7. Wyszukanie elementu \n";
                    cout << "8. Wroc \n";
                    cin >> chosen;
                    system("cls");
                    switch(chosen){
                        case 1:
                            cout << "Podaj wartosc: \n";
                            cin >> chosen;
                            x.addBeginning(chosen);
                            break;
                        case 2:
                            cout << "Podaj wartosc: \n";
                            cin >> chosen;
                            x.addEnd(chosen);
                            break;
                        case 3:
                            cout << "Podaj wartosc: \n";
                            cin >> chosen;
                            int position;
                            cout << "Podaj pozycje: \n";
                            cin >> position;
                            x.addDesired(chosen, position);
                            break;
                        case 4:
                            x.deleteBeginning();
                            break;
                        case 5:
                            x.deleteEnd();
                            break;
                        case 6:
                            cout << "Podaj index do usuniecia: \n";
                            cin >> chosen;
                            x.deleteDesired(chosen);
                            break;
                        case 7:{
                            cout << "Podaj wartosc: \n";
                            cin >> chosen;
                            int searched = x.search(chosen);
                            cout <<"Wyszukana pozycja elementu: \n" << searched;
                            cout <<"\n Wpisz cokolwiek aby wrocic: \n";
                            cin >> chosen;
                        }
                        break;
                        case 8:
                            isChosen = false;
                    }
                }
            }
            break;
            case 2: {
                DoublyLinkedList x;
                string myText;
                ifstream MyReadFile("config.txt");
                int i = 0;
                while (getline(MyReadFile, myText)) {
                    if (i > 0)x.addEnd(stoi(myText));
                    else i++;
                }
                MyReadFile.close();
                cout << "Utworzona struktura: \n";
                while (isChosen) {
                    system("cls");
                    x.printList();
                    cout << "\n Wybierz operacje do wykonania: \n";
                    cout << "1. Dodanie na poczatek listy \n";
                    cout << "2. Dodanie na koniec listy \n";
                    cout << "3. Dodanie w dowolne miejsce listy \n";
                    cout << "4. Usuniecie z poczatku listy \n";
                    cout << "5. Usuniecie z konca listy \n";
                    cout << "6. Usuniecie danego elementu z listy \n";
                    cout << "7. Wyszukanie elementu \n";
                    cout << "8. Wroc \n";
                    cin >> chosen;
                    system("cls");
                    switch (chosen) {
                        case 1:
                            cout << "Podaj wartosc: \n";
                            cin >> chosen;
                            x.addBeginning(chosen);
                            break;
                        case 2:
                            cout << "Podaj wartosc: \n";
                            cin >> chosen;
                            x.addEnd(chosen);
                            break;
                        case 3:
                            cout << "Podaj wartosc: \n";
                            cin >> chosen;
                            int position;
                            cout << "Podaj pozycje: \n";
                            cin >> position;
                            x.addDesired(chosen, position);
                            break;
                        case 4:
                            x.deleteBeginning();
                            break;
                        case 5:
                            x.deleteEnd();
                            break;
                        case 6:
                            cout << "Podaj liczbe do usuniecia: \n";
                            cin >> chosen;
                            x.deleteDesired(chosen);
                            break;
                        case 7:{
                            cout << "Podaj wartosc: \n";
                            cin >> chosen;
                            Node* searched = x.search(chosen);
                            if(searched != nullptr)cout <<"Wyszukany element: \n" << searched -> value;
                            cout <<"\n Wpisz cokolwiek aby wrocic: \n";
                            cin >> chosen;
                        }
                        break;
                        case 8:
                            isChosen = false;
                    }
                }
            }
            break;
            case 3: {
                MaxHeap x;
                string myText;
                ifstream MyReadFile("config.txt");
                int i = 0;
                while (getline(MyReadFile, myText)) {
                    if (i > 0)x.addElement(stoi(myText));
                    else i++;
                }
                MyReadFile.close();
                cout << "Utworzona struktura: \n";
                while (isChosen) {
                    system("cls");
                    x.printHeap(0, "", true);
                    cout << "\n Wybierz operacje do wykonania: \n";
                    cout << "1. Dodanie do kopca \n";
                    cout << "2. Usuniecie elementu z kopca \n";
                    cout << "3. Wyszukanie elementu \n";
                    cout << "4. Wroc \n";
                    cin >> chosen;
                    system("cls");
                    switch (chosen) {
                        case 1:
                            cout << "Podaj wartosc: \n";
                            cin >> chosen;
                            x.addElement(chosen);
                            break;
                        case 2:
                            cout << "Podaj wartosc: \n";
                            cin >> chosen;
                            x.removeElement(chosen);
                            break;
                        case 3:{
                            cout << "Podaj wartosc: \n";
                            cin >> chosen;
                            int searched = x.searchElement(chosen);
                            cout <<"Wyszukana pozycja elementu: \n" << searched;
                            cout <<"\n Wpisz cokolwiek aby wrocic: \n";
                            cin >> chosen;
                        }
                        break;
                        case 4:
                            isChosen = false;
                    }
                }
            }
            break;
            case 4:  {
                BRTree x;
                string myText;
                ifstream MyReadFile("config.txt");
                int i = 0;
                while (getline(MyReadFile, myText)) {
                    if (i > 0){
                        BRNode* node = new BRNode;
                        node -> key = stoi(myText);
                        x.BRinsert(node);
                    }
                    else i++;
                }
                MyReadFile.close();
                cout << "Utworzona struktura: \n";
                while (isChosen) {
                    system("cls");
                    x.printTree(x.root, "", true);
                    cout << "\n Wybierz operacje do wykonania: \n";
                    cout << "1. Dodanie do drzewa \n";
                    cout << "2. Usuniecie elementu z drzewa \n";
                    cout << "3. Wyszukanie elementu \n";
                    cout << "4. Wroc \n";
                    cin >> chosen;
                    system("cls");
                    switch (chosen) {
                        case 1:{
                            cout << "Podaj wartosc: \n";
                            cin >> chosen;
                            BRNode* node = new BRNode;
                            node -> key = chosen;
                            x.BRinsert(node);
                        }
                        break;
                        case 2:{
                            cout << "Podaj wartosc: \n";
                            cin >> chosen;
                            BRNode* searched = x.BRsearch(x.root, chosen);
                            if(searched != nullptr) x.BRremove(searched);
                        }
                        break;
                        case 3:{
                            cout << "Podaj wartosc: \n";
                            cin >> chosen;
                            BRNode* searched = x.BRsearch(x.root, chosen);
                            if(searched != nullptr)cout <<"Wyszukany element to: \n" << searched -> key;
                            cout <<"\n Wpisz cokolwiek aby wrocic: \n";
                            cin >> chosen;
                        }
                        break;
                        case 4:
                            isChosen = false;
                    }
                }
            }
            break;
        }
    }
    return 0;
}