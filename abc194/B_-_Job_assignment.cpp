//
// Created by Valerio Nogueira on 06/03/2021.
//
 
#include <iostream>
#include <algorithm>
 
 
int main(){
  	int n;
  	int min = 10e5;
  	std::cin >> n;
 
  	int a[n], b[n];
 
  	for(int i = 0;i < n;i++){
    	std::cin >> a[i] >> b[i];
    }
 
  	for(int i = 0;i < n;i++){
    	for(int j = 0;j < n;j++){
        	int t = (i == j) ? (a[i] + b[j]) : (std::max(a[i], b[j]));
          	if(t < min){
            	min = t;
            }
        }
    }
 
  	std::cout << min << std::endl;
 
  	return 0;
}
