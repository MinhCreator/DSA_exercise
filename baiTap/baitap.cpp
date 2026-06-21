#include <bits/stdc++.h>
using namespace std;

int main()
{

    int arr[101];

    freopen("merge.txt", "w", stdout);
    ofstream inputFile("original.txt");
    ofstream evenFile("even.txt");
    ofstream oddFile("odd.txt");

    srand(time(0));

    for (int index = 1; index <= 100; index++)
    {
        arr[index] = rand() % 1000 + 1;
        inputFile << arr[index] << endl;
    }

    vector<int> even, odd;
    for (int i = 1; i <= 100; i++)
    {

        if (arr[i] % 2 == 0)
        {
            even.push_back(arr[i]);
        }
        else
        {
            odd.push_back(arr[i]);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    for (int value : even)
    {
        evenFile << value << endl;
        cout << value << endl;
    }
    for (int value : odd)
    {
        oddFile << value << endl;
        cout << value << endl;
    }
    inputFile.close();
    evenFile.close();
    oddFile.close();

    return 0;
}