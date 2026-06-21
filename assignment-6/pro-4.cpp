#include <bits/stdc++.h>
using namespace std;

int hoare(int a[], int l, int r){
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while(1){
        do{
            i++;
        }while (a[i] < pivot);
        do{
            j--;
        }while (a[j] > pivot);
        if (i < j) swap(a[i],a[j]);
        else return j;
    }
}

void quick_sort(int array[], int left, int right){
    if (left >= right) return;
    int p = hoare(array, left, right);
    quick_sort(array, left, p);
    quick_sort(array, p + 1, right);
}

void merge(int array[], int left, int middle, int right){
    vector <int> v1(array + left, array + middle + 1);
    vector <int> v2(array + middle + 1, array + right + 1);
    int index = 0; int j = 0;
    while (index < v1.size() && j < v2.size()){
        if (v1[index] <= v2[j]){
            array[left] = v1[index]; left++; index++;
        }
        else{
            array[left] = v2[j]; j++;  
        }
    }
    while (index < v1.size()){
        array[left] = v1[index]; left++; index++;
    }
    while(j < v2.size()){
        array[left] = v2[j]; left++; j++; 
    }
}

void merge_sort(int array[], int left, int right){
    if (left >= right) return;
    int middle = (left+right)/2;
    merge_sort(array, left, middle);
    merge_sort(array, middle+1, right);
    merge(array,left,middle,right);
}

void print(int array[], int size){
    for (int index = 0; index < size; index++){
        cout << array[index] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    // tất cả đều O(nlogn)
    quick_sort(a, 0, n - 1);
    print(a, n);
    
    random_device rd;
    mt19937 g(rd()); 
    shuffle(a, a + n, g);
    
    merge_sort(a,0,n-1);
    print(a,n);
    return 0;
}