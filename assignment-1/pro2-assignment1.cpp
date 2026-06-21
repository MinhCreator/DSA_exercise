#include <iostream>
#include <string>

std::string convertToRoman(int number)
{
    std::string romanNumeral;
    const std::string RomanSymbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    for (int i = 0; i < 13; i++)
    {

        while (number >= value[i])
        {
            romanNumeral += RomanSymbol[i];
            number -= value[i];
        }
    }
    return romanNumeral;
}

int main()
{
    int number;
    std::cout << "Enter an Arabic number: ";
    std::cin >> number;
    std::string romanNumber = convertToRoman(number);
    std::cout << "Arabic number: " << number << "\n";
    std::cout << "Roman number: " << romanNumber << "\n";
    return 0;
}