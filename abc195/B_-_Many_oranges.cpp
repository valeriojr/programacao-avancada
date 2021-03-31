//
// Created by Valerio Nogueira on 15/03/2021.
//
 
#include <iostream>
#include <cmath>
 
using namespace std;
 
 
int main() {
    int a, b, w;
 
    cin >> a >> b >> w;
 
    w *= 1000;
 
    int min = ceil(1.0f * w/b);
    int max = floor(1.0f * w/a);
 
    if(min <= max){
        cout << min << " " << max;
    }
    else {
        cout << "UNSATISFIABLE" << endl;
    }
 
    return 0;
}
