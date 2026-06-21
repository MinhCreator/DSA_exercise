#include <iostream>
#include <string>
#include <cmath>
#include <stack>

int main() {
  std::stack<int> binNum;

  std::string BinaryNum;
  std::cout << "Enter a binary number: ";
  std::cin >> BinaryNum;

  for (int i = 0; i < BinaryNum.size(); i++)
  {
    binNum.push(BinaryNum[i] - '0');
  }

  int decimal = 0;
  int exponent = 0;
  while (!binNum.empty()){
    decimal += binNum.top() * std::pow(2, exponent);
    binNum.pop();
    exponent++;
  }
  
  std::cout << "Decimal number: " << decimal << std::endl;
  return 0;

}