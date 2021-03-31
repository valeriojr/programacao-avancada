//
// Created by Valerio Nogueira on 08/03/2021.
//

#include <iostream>
#include <vector>

typedef long long int lli;

using namespace std;


lli find_best_choice(vector<lli>& s){
    lli n = s.size();
    lli best_choice = -1;

    // simulate pass starting from every trampoline, the pass with higher score is the best
    lli max_score = -1;
    for (lli i = 0;i < n;i++) {
        lli score = 0;
        lli j = i;
        while(j < n){
            if(s[i] > 1){
                score += 1;
            }
            j += s[i];
        }
        if (score > max_score){
            max_score = score;
            best_choice = i;
        }
    }

    return best_choice;
}


void jump(vector<lli>& s, lli& ruined, lli initial){
    while(initial < s.size()){
        lli prev = initial;
        initial += s[initial];
        if(s[prev] - 1 == 1){
            ruined++;
        }
        s[prev] = max(s[prev] - 1, 1LL);
    }
}


void pekora_and_trampoline(){
    lli n;
    lli ruined = 0;
    lli passes = 0;
    cin >> n;
    vector<lli> s(n);

    for (lli i = 0;i < n;i++) {
        cin >> s[i];
        if(s[i] == 1){
            ruined++;
        }
    }

    while(ruined < n){
        lli best_choice = find_best_choice(s);
        // cout << "\tPass " << passes + 1 << " best choice: " << best_choice << endl;
        jump(s, ruined, best_choice);
        passes++;
    }

    cout << passes << endl;
}

int main(){
    lli t;
    cin >> t;

    for (lli i = 0;i < t;++i) {
        // cout << "Test case " << i << endl;
        pekora_and_trampoline();
    }

    return 0;
}