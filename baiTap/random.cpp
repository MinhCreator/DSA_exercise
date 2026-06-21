#include <iostream>
#include <random>
#include <fstream>
using namespace std;

int main() {

    std::ofstream out("original.txt");

    if (out.is_open())
    {
        for (int i = 1; i < 100; i++)
        {
            out << (rand() % 1000) + 1 << endl;
        }
        out.close();
    }
    
}