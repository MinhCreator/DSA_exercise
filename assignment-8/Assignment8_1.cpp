#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& Heap, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && Heap[left] > Heap[largest]) largest = left;
    if (right < n && Heap[right] > Heap[largest]) largest = right;
    if (largest != i){
        swap(Heap[i], Heap[largest]);
        heapify(Heap, n, largest);
    }
}

void buildMaxHeap(vector<int>& Heap){
    int n = Heap.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(Heap, n, i);
}

int main(){
    vector<int> Heap = {50, 64, 52, 20, 43, 32, 61, 12};
    cout << "Initial array: ";
    for (int x : Heap) cout << x << " ";
    cout << "\n\n";

    buildMaxHeap(Heap);

    cout << "Max heap array: ";
    for (int x : Heap) cout << x << " ";
    cout << "\n\n";

    cout << "Memory representation (array):\n";
    for (int i = 0; i < Heap.size(); i++)
        cout << "Heap[" << i << "] = " << Heap[i] << "\n";

    return 0;
}
