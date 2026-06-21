#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    double arr[1000];

    for (int i = 0; i < num; i++) {
        cout << "Enter a number: ";
        cin >> arr[i];
    }
    
    // sum and divide by number
    double sum = 0;
    for(int i = 0; i < num; i++) {
        sum += arr[i];

    }

    cout << fixed << setprecision(4)  << "Average: " << sum / num << endl;

    // sum big num and sum small num

    int count1 = 0;
    int count2 = 0;
    double sum1 = 0;
    double sum2 = 0;

    for (int i = 0; i < num; i++)
    {
        if (arr[i] < 0.01)
        {
            count1++;
            sum1 += arr[i];
        }
        else
        {
            count2++;
            sum2 += arr[i];
        }
        


    }
    
    cout << fixed << setprecision(4) << sum1/count1 << endl;
    cout << fixed<< setprecision(4) << sum2/count2 << endl;

    return 0;

}
