//
// Created by Valerio Nogueira on 10/03/2021.
//

#include <iostream>

using namespace std;


void split_it(){
    int n, k;
    cin >> n >> k;
    // cout << "n = " << n <<" and "<< "k = " << k << endl;


    string s;
    cin >> s;

    // cout << "read string " << s << endl;
    if(k == 0){
        cout << "YES" << endl;
        return;
    }
    int palindrome_chars = 0;
    int i = 0;
    int j = s.size() - 1;

    // printf("%d + 1 < %d and s[%d] == s[%d] (%c == %c)\n", i, j, i, j, s[i], s[j]);

    while(i + 1 < j && s[i] == s[j]){
        palindrome_chars++;
        i++;
        j--;
    }

    // cout << "Palindrome chars: " << palindrome_chars << endl;

    if(palindrome_chars >= k){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}


int main(){
    int t;
    cin >> t;

    for (int i = 0;i < t;i++) {
        // cout << "Test case " << i << endl;
        split_it();
        // cout << endl;
    }
}