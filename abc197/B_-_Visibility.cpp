//
// Created by Valerio Nogueira on 29/03/2021.
//
 
#include <stdio.h>
 
int main(){
    int h, w, x, y;
    scanf("%d%d%d%d", &h, &w, &x, &y);
    char grid[h][w];
    x--;
    y--;
    int i, j;
    for(i = 0;i < h;i++){
        for(j = 0;j < w;j++){
            scanf(" %c", &grid[i][j]);
        }
    }
    int count = 0;
    // Left
    for(j = -1;y + j >= 0 && grid[x][y + j] == '.';j--){
        count++;
    }
    for(j = 1;y + j < w && grid[x][y + j] == '.';j++){
        count++;
    }
    for(i = -1;x + i >= 0 && grid[x + i][y] == '.';i--){
        count++;
    }
    for(i = 1;x + i < h && grid[x + i][y] == '.';i++){
        count++;
    }
 
    printf("%d\n", count + 1);
 
    return 0;
}
