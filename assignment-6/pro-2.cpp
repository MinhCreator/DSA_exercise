#include <bits/stdc++.h>

void binarySearch(int a[], int n, int x){
    int l = 0, r = n;
    while(l <= r){
        int mid = (l+r)/2;
        if (a[mid] == x){
            std::cout << "Have found";
            return;
        }
        else if (a[mid] < x){
            l = mid + 1;
            std::cout << "Not found" << std::endl;
        }
        else{
            r = mid - 1;
            std::cout << "Not found" << std::endl;
        }
    }
}

int main(){
    int n,x;
    std::cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    binarySearch(a, n, x);
    return 0;
}