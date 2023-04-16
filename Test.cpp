#include <windows.h>
#include <iostream>
#include <fstream>
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
#include "Test.h"
using namespace std;

void Test::StartCounter() {
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000000000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double Test::GetCounter(){
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

int main(){
    Test test;
    std::ofstream ofs;
    ofs.open("results.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    for(int i = 0; i < 30; i++) {  //how many times to perform test
        srand(time(nullptr));

        std::ofstream ofs;
        ofs.open("testnodes.txt", std::ofstream::out | std::ofstream::trunc);
        ofs.close();

        for (int j = 0; j < 50000; j++) {    //size of structure
            int v1 = rand() - RAND_MAX / 2;
            std::ofstream outfile;
            outfile.open("testnodes.txt", std::ios_base::app);
            outfile << v1 << "\n";
        }

        BRTree x;                   //tested structure
        string myText;
        ifstream MyReadFile("testnodes.txt");
        while (getline(MyReadFile, myText)) { //adding random number to array
            BRNode* node = new BRNode;
            node -> key = stoi(myText);
            x.BRinsert(node);
        }
        MyReadFile.close();

        int v1 = rand() - RAND_MAX / 2;      //random value
//        int y = rand() % x.size;               //random position

        test.StartCounter();
        x.BRsearch(x.root, v1);            //tested function
        double counter = test.GetCounter();


        std::ofstream outfile;
        outfile.open("results.txt", std::ios_base::app);
        outfile << counter << "\n";
    }
    return 0;
}
