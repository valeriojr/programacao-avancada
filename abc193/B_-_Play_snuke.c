#include <stdio.h>
 
int main(){
    int n, i;
    long long int a, p, x, min_p = 1000000000;
    int can_buy = 0;
    scanf("%d", &n);
    
    for(i = 0;i < n;i++){
        scanf("%lld%lld%lld", &a, &p, &x);
        if(x > a){
            if(p < min_p){
                can_buy = 1;
                min_p = p;
            }
        }
    }
    
    if(!can_buy){
        printf("-1");
    }
    else{
        printf("%lld", min_p);
    }
}
