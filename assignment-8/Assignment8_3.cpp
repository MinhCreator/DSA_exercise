#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
private:
    vector<int> Heap;

    void heapify(int numb, int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left < numb && Heap[left] > Heap[largest])
            largest = left;
        if (right < numb && Heap[right] > Heap[largest])
            largest = right;
        if (largest != index)
        {
            swap(Heap[index], Heap[largest]);
            heapify(numb, largest);
        }
    }

public:
    MaxHeap() {}

    void insert(int val)
    {
        Heap.push_back(val);
        int i = Heap.size() - 1;
        while (i > 0 && Heap[(i - 1) / 2] < Heap[i])
        {
            swap(Heap[i], Heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int extractMax()
    {
        if (Heap.empty())
            return -1;
        int root = Heap[0];
        Heap[0] = Heap.back();
        Heap.pop_back();
        if (!Heap.empty())
            heapify(Heap.size(), 0);
        return root;
    }

    void printArray()
    {
        cout << "Array: ";
        for (int x : Heap)
            cout << x << " ";
        cout << "\n";
    }

    void printHeapTree()
    {
        if (Heap.empty())
        {
            cout << "(empty)\n";
            return;
        }
        int HeapSize = Heap.size();
        int height = log2(HeapSize);
        int index = 0;
        for (int row = 0; row <= height; row++)
        {
            int count = 1 << row;
            int spaces = (1 << (height - row + 1)) - 1;
            for (int i = 0; i < count && index < HeapSize; i++)
            {
                for (int s = 0; s < spaces; s++)
                    cout << " ";
                cout << setw(2) << Heap[index++];
                for (int s = 0; s < spaces; s++)
                    cout << " ";
                if (i < count - 1)
                    cout << " ";
            }
            cout << "\n\n";
        }
    }

    int size() { return Heap.size(); }
};

int main()
{
    MaxHeap heap;

    cout << "=== Inserting priorities 1 through 10 ===\n\n";
    for (int i = 1; i <= 10; i++)
    {
        heap.insert(i);
        cout << "Inserted " << i << " -> ";
        heap.printArray();
    }

    cout << "\n=== Max-Heap after all insertions ===\n";
    heap.printArray();
    cout << "\nTree representation:\n\n";
    heap.printHeapTree();

    cout << "\n=== Removing 3 elements (extract max) ===\n\n";
    for (int i = 0; i < 3; i++)
    {
        int removed = heap.extractMax();
        cout << "Removed " << removed << " -> ";
        heap.printArray();
    }

    cout << "\n=== Max-Heap after removing 3 elements ===\n";
    heap.printArray();
    cout << "\nTree representation:\n\n";
    heap.printHeapTree();

    return 0;
}
