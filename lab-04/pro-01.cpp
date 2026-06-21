#include <iostream>
#include <fstream>
#include <vector>

int hoare(int* array, int l, int r)
{
    int pivot = array[l];
    int i = l - 1, j = r + 1;
    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);
        do
        {
            j--;
        } while (array[j] > pivot);
        if (i < j)
            std::swap(array[i], array[j]);
        else
            return j;
    }
}

void insert_sort(int* array, int size)
{
    for (int index = 1; index < size; index++)
    {
        int current = array[index], pos = index - 1;

        while (current < array[pos] && pos >= 0)
        {
            array[pos + 1] = array[pos];
            pos--;
        }
        array[pos + 1] = current;
    }
}

void selection_sort(int* array, int size)
{
    for (int index = 0; index < size - 1; index++)
    {
        int min_pos = index;
        for (int j = index + 1; j < size; j++)
        {
            if (array[j] < array[min_pos])
            {
                min_pos = j;
            }
        }
        std::swap(array[index], array[min_pos]);
    }
}

void bubble_sort(int* array, int size)
{
    for (int index = 0; index < size - 1; index++)
    {

        for (int j = 0; j < size - index - 1; j++)
        {

            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

void quick_sort(int* array, int left, int right)
{
    if (left >= right)
        return;
    int p = hoare(array, left, right);
    quick_sort(array, left, p);
    quick_sort(array, p + 1, right);
}

void merge(int* array, int left, int middle, int right)
{
    std::vector<int> v1(array + left, array + middle + 1);
    std::vector<int> v2(array + middle + 1, array + right + 1);
    int index = 0;
    int j = 0;
    while (index < v1.size() && j < v2.size())
    {
        if (v1[index] <= v2[j])
        {
            array[left] = v1[index];
            left++;
            index++;
        }
        else
        {
            array[left] = v2[j];
            j++;
        }
    }
    while (index < v1.size())
    {
        array[left] = v1[index];
        left++;
        index++;
    }
    while (j < v2.size())
    {
        array[left] = v2[j];
        left++;
        j++;
    }
}

void merge_sort(int* array, int left, int right)
{
    if (left >= right)
        return;
    int middle = (left + right) / 2;
    merge_sort(array, left, middle);
    merge_sort(array, middle + 1, right);
    merge(array, left, middle, right);
}

int* initArr(int size){

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> arr[i];
    }
    return arr;
}

void printArr(int* arr, int size){
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void linearSearch(int* arr, int size, int target){

    for (int index = 0; index < size; index++){
        if (arr[index] == target){
            std::cout << "Target found at index " << index << std::endl;
            return;
        } 
    }

}

void binarySearch(int* arr, int size, int target){
    int left = 0;
    int right = size - 1;

    while (left <= size)
    {
        int middle = (left + right) / 2;
        if (arr[middle] == target){
            std::cout << "Target found at index " << middle << std::endl;
            return;
        }
        else if (arr[middle] < target){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }
    
}

int main() {

    int size;
    std::cout << "Enter size: ";
    std::cin >> size;

    int* arr = initArr(size);   
    printArr(arr, size);
    binarySearch(arr, size, 5);
    linearSearch(arr, size, 5);

    //sort func
    insert_sort(arr, size);
    // printArr(arr, size);
    
    selection_sort(arr, size);
    // printArr(arr, size);
    
    bubble_sort(arr, size);
    // printArr(arr, size);
    
    quick_sort(arr, 0, size - 1);
    // printArr(arr, size);
    
    merge_sort(arr, 0, size - 1);
    // printArr(arr, size);
    
    return 0;

}