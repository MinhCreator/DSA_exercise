#include <bits/stdc++.h>
using namespace std;

void insert_sort(int array[], int size){
    for (int index = 1; index < size; index++){
        int current = array[index], pos = index - 1;
        
        while (current < array[pos] && pos >= 0){
            array[pos + 1] = array[pos];
            pos--;
        }
        array[pos + 1] = current;
    }
}

void selection_sort(int array[], int size){
    for (int index = 0; index < size - 1; index++){
        int min_pos = index;
        for (int j = index + 1; j < size; j++){
            if (array[j] < array[min_pos]){
                min_pos = j;
            }
        }
        swap(array[index], array[min_pos]);
    }
}

void bubble_sort(int array[], int size){
    for (int index = 0; index < size - 1; index++){
         
        for (int j = 0; j < size - index - 1; j++){
            
            if (array[j] > array[j+1]){
                swap(array[j],array[j+1]);
            }
        }
    }
}

void print(int array[], int size){
    for (int index = 0; index < size; index++){
        cout << array[index] << " ";
    }
    cout << endl;
}

int main(){
    int n,x;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    // tất cả đều O(n mũ 2)
    insert_sort(a, n); 
    print(a, n);
    random_device rd;
    mt19937 g(rd()); 
    shuffle(a, a + n, g);
    
    selection_sort(a, n);
    print(a, n);
    
    shuffle(a, a + n, g);
    bubble_sort(a, n);
    print(a, n);
    return 0;
}