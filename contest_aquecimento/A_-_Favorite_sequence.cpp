#include <stdio.h>
#include <stack>


int main(){
    int t;
	
	scanf("%d", &t);
	
	for(int t_i = 0;t_i < t;t_i++){
		long long int n, a_i;
		std::deque<long long int> d;
		
		scanf("%lld", &n);
		
		for(int i = 0;i < n;i++){
			scanf("%lld", &a_i);
			d.push_back(a_i);
		} 
		
		while(!d.empty()){
			printf("%lld ", d.front());
			d.pop_front();
			if(!d.empty()){				
				printf("%lld ", d.back());
				d.pop_back();
			}
		}
		
		printf("\n");
	}
	
	return 0;
}