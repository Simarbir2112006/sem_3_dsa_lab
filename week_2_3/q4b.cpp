#include <iostream>

using namespace std;

void rev(char s[]){
    int len=0;
    while (s[len] != '\0'){
        len++;
    } 
    int j = len-1;
    for (int i = 0; i < len/2; i++){
        char temp =s[i];
        s[i] = s[j];
        s[j] = temp;
        j--;
    }
}

int main() {
    char s[50];

    cout << "Enter first string: ";
    cin.getline(s, 50);

    rev(s);

    cout << "Reversed string: " << s << endl;

    return 0;
}