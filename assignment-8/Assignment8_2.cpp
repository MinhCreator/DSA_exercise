#include <bits/stdc++.h>
using namespace std;

class MinHeap {
private:
    vector<int> Heap;

    void heapify(int numb, int index){
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left < numb && Heap[left] < Heap[smallest]) smallest = left;
        if (right < numb && Heap[right] < Heap[smallest]) smallest = right;
        if (smallest != index){
            swap(Heap[index], Heap[smallest]);
            heapify(numb, smallest);
        }
    }

public:
    MinHeap(){}

    MinHeap(vector<int> arr){
        Heap = arr;
        int n = Heap.size();
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(n, i);
    }

    void insert(int val){
        Heap.push_back(val);
        int i = Heap.size() - 1;
        while (i > 0 && Heap[(i - 1) / 2] > Heap[i]){
            swap(Heap[i], Heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
        cout << val << "\n";
    }

    int peek(){
        if (Heap.empty()){
            return -1;
        }
        return Heap[0];
    }

    int removeMin(){
        if (Heap.empty()){
            return -1;
        }
        int root = Heap[0];
        Heap[0] = Heap.back();
        Heap.pop_back();
        if (!Heap.empty())
            heapify(Heap.size(), 0);
        cout << root << "\n";
        return root;
    }

    void heapSortDecreasing(){
        int n = Heap.size();
        for (int i = n - 1; i > 0; i--){
            swap(Heap[0], Heap[i]);
            heapify(i, 0);
        }
        cout << "HeapSort (decreasing): ";
        for (int x : Heap) cout << x << " ";
        cout << "\n";
    }

    void print(){
        cout << "Heap array: ";
        for (int x : Heap) cout << x << " ";
        cout << "\n";
    }
};

int main(){
    vector<int> arr = {50, 64, 52, 20, 43, 32, 61, 12};

    MinHeap heap(arr);
    heap.print();

    cout << "result of case a: ";
    heap.insert(10);
    heap.print();

    cout << "result of case b: ";
    heap.removeMin();
    heap.print();

    cout << "result of case c: ";
    cout << heap.peek() << "\n";

    cout << "result of case d: ";
    MinHeap heap2(arr);
    heap2.heapSortDecreasing();

    return 0;
}
