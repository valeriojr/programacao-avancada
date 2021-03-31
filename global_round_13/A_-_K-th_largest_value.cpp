//
// Created by Valerio Nogueira on 08/03/2021.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    int count[2] = {0};

    for (int i = 0;i < n;i++) {
        cin >> a[i];
        count[a[i]]++;
    }

    int q_i;
    for (int i = 0;i < q;i++) {
        cin >> q_i;

        //printf("count:\t1:%d\t0:%d\n", count[1], count[0]);

        if (q_i == 1) {
            int x;
            cin >> x;
            x -= 1;

            //printf("flip a[%d]: %d -> %d\n", x, a[x], !a[x]);

            count[a[x]]--;
            count[!a[x]]++;
            a[x] = !a[x];
        }
        else if (q_i == 2) {
            int k;
            cin >> k;

            //printf("print %d-th largest\n", k);

            if (count[1] >= k) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}