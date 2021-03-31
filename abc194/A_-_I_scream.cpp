#include <iostream>
 
 
int main(){
  	int not_fat, fat, solids;
  	std::cin >> not_fat >> fat;
  	solids = not_fat + fat;
  
  	if(solids >= 15 && fat >=8){
    	std::cout << 1;
    }
  	else if(solids >= 10 && fat >= 3){
    	std::cout << 2;
    }
  	else if(solids >= 3){
      	std::cout << 3;
    }
  	else {
      	std::cout << 4;
    }
  	
	return 0;
}

