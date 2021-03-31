//
// Created by Valerio Nogueira on 06/03/2021.
//
 
#include <iostream>
#include <cmath>
 
int main(){
    int n;
    std::cin >> n;
    double expected = 0;
 
    for(int i = 1;i < n;i++){
        double prob = (double) (n - i) / n;
        expected += 1.0 / prob;
    }
 
    printf("%.18lf\n", expected);
 
    return 0;
}
