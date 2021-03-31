//
// Created by Valerio Nogueira on 06/03/2021.
//
#include <iostream>
#include <unordered_map>
 
 
typedef long long int llint;
 
int main(){
    llint n;
	std::unordered_map<llint, llint> count;
    llint sum = 0;
    llint a_i;
 
  	std::cin >> n;
 
    std::cin >> a_i;
    count[a_i] = 1;
  	for(llint i = 1;i < n;i++){
    	std::cin >> a_i;
    	for (auto& c : count){
    	    sum += c.second * (c.first - a_i) * (c.first - a_i);
    	}
 
    	if(count.find(a_i) == count.end()){
    	    count[a_i] = 1;
    	}
    	else{
    	    count[a_i]++;
    	}
    }
 
  	std::cout << sum << std::endl;
 
  	return 0;
}

