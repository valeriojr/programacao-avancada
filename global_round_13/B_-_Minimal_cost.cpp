//
// Created by Valerio Nogueira on 08/03/2021.
//

#include <iostream>
#include <vector>

typedef long long int lli;

using namespace std;


void minimal_cost() {
    int n;
    lli u, v;
    cin >> n >> u >> v;
    lli cost = 1e9;
    vector<int> col(n, 0);

    for (int i = 0;i < n;i++) {
        cin >> col[i];
    }

    if (abs(col[1] - col[0]) > 1) {
        /*
         * o x o
         * o o o
         */
        cost = 0;
    }
    else if (col[1] == col[0]) {
        /*
         * o x o
         * o x o
         */
        cost = min(2 * v, u + v);
    }
    else {
        cost = min(cost, min(u, v));
    }

    for (int i = 1;i < n - 1;i++) {
        lli abs1 = abs(col[i - 1] - col[i]);
        lli abs2 = abs(col[i + 1] - col[i]);

        if (abs1 > 1 || abs2 > 1) {
            /*
             * o o o      ? ? ?
             * o x o  ou  o x o
             * ? ? ?      o o o
             */
            cost = 0;
        }
        else if (abs1 == 0 && abs2 == 0) {
            /*
             * o x o
             * o x o
             * o x o
             */
            cost = min(cost, 2 * v);
        }
        else if (abs1 == 1 || abs2 == 1) {
            cost = min(cost, min(u, v));
        }
    }

    if (abs(col[n - 2] - col[n - 1]) > 1) {
        /*
         * o o o
         * o x o
         */
        cost = 0;
    }
    else if (col[n - 2] == col[n - 1]) {
        /*
         * o x o
         * o x o
         */
        cost = min(cost, min(2 * v, u + v));
    }
    else {
        cost = min(cost, min(u, v));
    }

    cout << cost << endl;
}


int main() {
    int t;
    cin >> t;

    for (int i = 0;i < t;i++) {
        minimal_cost();
    }

    return 0;
}