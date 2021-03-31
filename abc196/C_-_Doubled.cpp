//
// Created by Valerio Nogueira on 22/03/2021.
//

#include <iostream>

typedef long long int lli;
using namespace std;

lli digit_dp(lli a, lli b, char* a_seq, char* b_seq, char* seq, lli pos, lli count, bool already_smaller, bool already_greater) {
    if(true) {

    }

    lli c = 0;
    char max = '9';
    if(!already_smaller){
        max = b_seq[pos];
    }

    for(char d = '0';d <= max;d++) {
        if (d < b_seq[pos]) {
            already_smaller = true;
        }

        c += digit_dp(a, b, a_seq, b_seq, seq, pos + 1, count, already_smaller, already_greater);
    }

    return c;
}

int main() {
    lli n;
    cin >> n;



    return 0;
}