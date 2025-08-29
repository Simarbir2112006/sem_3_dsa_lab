#include <iostream>

using namespace std;

void delVowel(char s[]){
    int len=0;
    while (s[len] != '\0'){
        len++;
    }
    int i = 0, j=0;
    while (i<len){
        char test = tolower(s[i]);
        if (test != 'a' && test != 'e' && test != 'i' && test != 'o' && test != 'u'){
            s[j] = s[i];
            j++;
        } 
        i++;
    }
    s[j] = '\0';
}

int main() {
    char s[50];

    cout << "Enter first string: ";
    cin.getline(s, 50);

    delVowel(s);

    cout << "Vowel deleated string: " << s << endl;

    return 0;
}