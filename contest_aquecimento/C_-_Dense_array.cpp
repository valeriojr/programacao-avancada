#include <stdio.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)


int main(){
	int t, n, a, b, count;
	scanf("%d", &t);
	
	for(int t_i = 0;t_i < t;t_i++){
		count = 0;
		scanf("%d", &n);
		scanf("%d", &a);
		for(int i = 1;i < n;i++){
			scanf("%d", &b);
			int old_b = b;
			if(a < b){
				while(b > (a << 1)){
					// printf("[%d] %d eh maior que 2*%d\n", i, b, a);
					a = a << 1;
					count++;
					// printf("a=%d, b=%d, count=%d\n", a, b, count);
				}
			}
			else{
				while(a > (b << 1)){
					// printf("[%d] %d eh maior que 2*%d\n", i, a, b);
					b = b << 1;
					count++;
					// printf("a=%d, b=%d, count=%d\n", a, b, count);
				}
			} 
			a = old_b;
		}
		
		printf("%d\n", count);
	}
	
	return 0;
}