#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
 
typedef long long int lli;
 
 
int main() {
    lli n, m;
    std::cin >> n >> m;
    std::vector<lli> a(n);
    std::map<lli, lli> count;
    lli min_mex = 0;
 
    for (int i = 0;i < n;i++) {
        std::cin >> a[i];
        if (i < m) {
            count[a[i]]++;
        }
    }
 
    for(auto& p : count){
        if(min_mex == p.first){
            min_mex++;
        }
    }
 
    // printf("min_mex = %lld\n", min_mex);
 
    for (int i = 0;i < n - m;i++) {
        count[a[i]]--;
        count[a[i + m]]++;
 
        if (count[a[i]] == 0) {
            // printf("a[%lld] = %lld\n", i, a[i]);
            min_mex = std::min(min_mex, a[i]);
        }
    }
 
    std::cout << min_mex << std::endl;
 
    return 0;
}

