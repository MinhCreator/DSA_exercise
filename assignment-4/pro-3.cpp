#include <iostream>
#include <string>
#include <stack>

std::string stackReverse(std::string s){
    std::stack<char> st;

    for (int index = 0; index < s.size(); index++){
        st.push(s[index]);
    }
    
    std::string re = "";
    while(!st.empty()){
        re += st.top();
        st.pop();
    }
    return re;
}
std::string RecursiveReverse(std::string s, int index){
    std::string result = "";
    if(index < s.size()){
        result = RecursiveReverse(s, index + 1);
        result += s[index];
    }
    return result;
}




int main() {
    std::cout << RecursiveReverse("hello", 0) << std::endl;
    std::cout << stackReverse("hello") << std::endl;
}