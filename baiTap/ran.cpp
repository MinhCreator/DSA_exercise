#include <bits/stdc++.h>
using namespace std;

int main() {

    int a[101];

    freopen("output.txt","w", stdout);
    ofstream inputFile("input.txt");
    ofstream evenFile("even.txt");
    ofstream oddFile("odd.txt");

    srand(time(0));

    for (int i = 1; i <= 100; i++) {
        a[i] = rand() % 1000 + 1;
        inputFile << a[i] << endl;
    }

    vector <int> v1,v2;
    for (int i = 1; i <= 100; i++) {

        if (a[i] % 2 == 0) {
            v1.push_back(a[i]);
        }
        else {
            v2.push_back(a[i]);
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for (int x: v1){
        evenFile << x << endl;
        cout << x << endl;
    }
    for (int x: v2){
        oddFile << x << endl;
        cout << x << endl;
    }
    inputFile.close();
    evenFile.close();
    oddFile.close();

    return 0;
}