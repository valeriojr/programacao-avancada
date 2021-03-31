#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main() {
  char x[10000] = "";
  scanf(" %[^\n]s", x);
  int i;
  for(i = 0;x[i] && x[i] != '.';i++){
    printf("%c", x[i]);
  }
  
  return 0;
}
