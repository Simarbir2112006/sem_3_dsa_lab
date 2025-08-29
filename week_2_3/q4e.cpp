#include <iostream>

using namespace std;

void lower(char s[]){
    int len=0;
    while (s[len] != '\0'){
        len++;
    }
    int i = 0;
    while (i<len){
        s[i] = tolower(s[i]);
        i++;
    }
}

int main() {
    char s[50];

    cout << "Enter first string: ";
    cin.getline(s, 50);

    lower(s);

    cout << "Lowered string: " << s << endl;

    return 0;
}