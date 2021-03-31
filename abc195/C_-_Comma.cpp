#include <iostream>
#include <cstring>
#include <cmath>
 
typedef unsigned long long int ull;
using namespace std;
 
 
int main() {
    ull n, count = 0;
    cin >> n;
 
    /* From     To           C (commas * numbers in [From, To])
     * 1        10e3 - 1     0 * (10e3  - 1 - 10e0  + 1)                                         = 0
     * 10e3     10e6 - 1     1 * (10e6  - 1 - 10e3  + 1) = 1 * (10e6  - 10e3)  = 1 * 999 * 10e3  = 999.000
     * 10e6     10e9 - 1     2 * (10e9  - 1 - 10e6  + 1) = 2 * (10e9  - 10e6)  = 2 * 999 * 10e6  = 1.998.000.000
     * 10e9     10e12 - 1    3 * (10e12 - 1 - 10e9  + 1) = 3 * (10e12 - 10e9)  = 3 * 999 * 10e9  = 2.997.000.000.000
     * 10e12    10e15 - 1    4 * (10e15 - 1 - 10e12 + 1) = 4 * (10e15 - 10e12) = 4 * 999 * 10e12 = 3.996.000.000.000.000
     * 10e15    10e15        5 * 1                                                               = 5
     */
 
    ull table[6][3] = {
            {1,                999,                0},
            {1000,             999999,             999000},
            {1000000,          999999999,          1998000000},
            {1000000000,       999999999999,       2997000000000},
            {1000000000000,    999999999999999,    3996000000000000},
            {1000000000000000, 999999999999999999, 5},
    };
 
    for (int i = 0;i < 6;i++) {
        ull from = table[i][0];
        ull to = table[i][1];
        ull c = table[i][2];
 
 
        if(n > to) {
            count += c;
        }
        else {
            count += i * (n - from + 1);
            break;
        }
    }
 
    cout << count << endl;
 
    return 0;
}
