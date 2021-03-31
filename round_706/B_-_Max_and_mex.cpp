//
// Created by Valerio Nogueira on 10/03/2021.
//

#include <iostream>
#include <map>
#include <cmath>

typedef long long int lli;
using namespace std;


void max_and_mex(){
    lli n, k, distinct;
    lli mex, max;
    map<lli, lli> set;

    cin >> n >> k;

    distinct = n;
    mex = 0;
    max = -1;

    for (int i = 0;i < n;++i) {
        lli a_i;
        cin >> a_i;
        set[a_i]++;
        max = std::max(max, a_i);
    }

    for(auto& p : set){
        if(mex != p.first){
            break;
        }
        mex++;
    }

    for (int i = 0;i < k;++i) {
        // cout << "Max: " << max << " Mex: " << mex << endl;
        lli a = std::ceil(0.5 * (max + mex));
        // cout << "Inserting " << a << endl;
        if(set[a] == 1) {
            distinct--;
        }
        set[a]++;
        max = std::max(max, a);
        if(mex == a){
            auto it = set.find(mex);
            while(it != set.end()){
                if(mex != it->first){
                    break;
                }
                mex++;
            }
        }
    }

    cout << set.size() << endl;
}


int main(){
    int t;
    cin >> t;
    for (int i = 0;i < t;++i) {
        max_and_mex();
    }
}