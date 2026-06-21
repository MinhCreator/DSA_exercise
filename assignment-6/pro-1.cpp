#include <bits/stdc++.h>

int main(){
    int n,x;
    std::cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        if (a[i] == x){
            std::cout << "Have found " << x;
            break;
        }
        else{
            std::cout << "Not found" << std::endl;
        }
    }
    return 0;
}