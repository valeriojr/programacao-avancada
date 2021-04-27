//
// Created by Valerio Nogueira on 22/03/2021.
//

#include <iostream>
#include <string>

typedef long long int lli;
using namespace std;


int main() {
    lli n;
    cin >> n;
    lli count = 0;

    for(int i = 1;i < 10000001;i++){
	if(stoll(to_string(i) + to_string(i)) <= n){
	    count++;
	}
	else {
	    break;
	}
    }

    cout << count << endl;

    return 0;
}
