//
// Created by Valerio Nogueira on 03/03/2021.
//
 
#include <stdio.h>
#include <math.h>
#include <unordered_set>
 
int main(){
    long long int n, i;
    long long int count = 0;
    std::unordered_set<long long int> representable;
 
    scanf("%lld", &n);
 
    for(i = 2;i <= 1e5;i++){
        int j;
        long long int result = i;
        while(result <= n){
            result *= i;
 
            if(result <= n){
                representable.insert(result);
            }
        }
    }
 
    printf("%lld\n", n - representable.size());
 
    return 0;
}
