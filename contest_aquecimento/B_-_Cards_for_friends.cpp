#include <stdio.h>
#define IS_EVEN(x) ((x & 1) == 0)

int main(){
	int t;
	scanf("%d", &t);
	
	for(int t_i = 0;t_i < t;t_i++){
		int w, h;
		long long int n;
		long long int s = 1;
		
		scanf("%d%d%lld", &w, &h, &n);
		
		while(IS_EVEN(w)){
			s = s << 1;
			w = w >> 1;
		}
		
		while(IS_EVEN(h)){
			s = s << 1;
			h = h >> 1;
		}
		
		printf(s >= n ? "YES\n" : "NO\n");
	}
	
	
	return 0;
}