#include <iostream>

using namespace std;

void concatenate(char s1[], char s2[]){
    int len_s1=0, len_s2=0;
    while (s1[len_s1] != '\0'){
        len_s1++;
    } 
    while (s2[len_s2] != '\0'){
        len_s2++;
    } 
    int j = 0;
    for (int i = len_s1; i < len_s1+len_s2; i++){
        s1[i]=s2[j];
        j++;
    }

    s1[len_s1+len_s2] = '\0';
}

int main() {
    char s1[200], s2[100];

    cout << "Enter first string: ";
    cin.getline(s1, 200);

    cout << "Enter second string: ";
    cin.getline(s2, 100);

    concatenate(s1, s2);

    cout << "Concatenated string: " << s1 << endl;

    return 0;
}