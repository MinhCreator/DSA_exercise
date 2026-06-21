#include <iostream>

using namespace std;

void inputData(int *a, int n){

}

void outputData(int *a, int n){
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
}

void remove(int *a, int *n, int k){
    int *newbegin = a + k;
    for (int * i = a; i < newbegin ; i++)
    {
        *i = *(i + 1);
    }
    *n = *n - 1;
    
}
void removeOdd(int *a, int *n){
    int *newBegin = nullptr;
    for (int *p = a; p < a + *n; p++)
    {
        if (*p % 2 == 0)
        {
            if (newBegin == nullptr)
            {
                newBegin = p;
            }
            *newBegin = *p;
            newBegin++;
        }
    }
    int oldSize = *n;
    *n = newBegin - a;
    for (int *p = newBegin; p < a + oldSize; p++)
    {
        *p = *(p + *n);
    }
}

int main() {
    int SIZE = 10;
    int *array = new int[SIZE];

    inputData(array, SIZE);
    std::cout << "Input data:\n";
    outputData(array, SIZE);

    removeOdd(array, &SIZE);
    std::cout << "After removing odd numbers:\n";
    outputData(array, SIZE);

    // delete[] array;
}