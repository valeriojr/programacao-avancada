//
// Created by Valerio Nogueira on 10/03/2021.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long int lli;


void diamond_miner(){
    int n;
    cin >> n;
    vector<lli> miners;
    vector<lli> mines;

    lli x, y;
    for (int i = 0;i < 2 * n;++i) {
        cin >> x >> y;
        if (x == 0){
            miners.push_back(abs(y));
        }
        else{
            mines.push_back(abs(x));
        }
    }

    sort(miners.begin(), miners.end());
    sort(mines.begin(), mines.end());

    long double e = 0.0;
    for (int i = 0;i < n;++i) {
        // cout << mines[i] << " " << miners[i] << endl;
        e += hypotl(mines[i], miners[i]);
    }

    printf("%.15Lf\n", e);
}


int main(){
    int t;
    cin >> t;

    for (int i = 0;i < t;++i) {
        diamond_miner();
    }

    return 0;
}