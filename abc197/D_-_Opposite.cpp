//
// Created by Valerio Nogueira on 29/03/2021.
//
 
#include <stdio.h>
#include <math.h>
 
 
typedef struct {
    float x, y;
} vec2;
 
 
float norm(vec2 v) {
    return hypot(v.x, v.y);
}
 
 
vec2 project(vec2 u, vec2 v) {
    float dot = u.x * v.x + u.y * v.y;
    float vnorm = norm(v);
 
    vec2 proj;
    proj.x = (dot / vnorm) * (v.x / vnorm);
    proj.y = (dot / vnorm) * (v.y / vnorm);
 
    return proj;
}
 
 
vec2 rotate(vec2 v, float angle) {
    vec2 u;
    float s = sin(angle);
    float c = cos(angle);
    u.x = c * v.x - s * v.y;
    u.y = s * v.x + c * v.y;
 
    return u;
}
 
 
int main() {
    int n;
    vec2 p0, pN_2;
    scanf("%d%f%f%f%f", &n, &p0.x, &p0.y, &pN_2.x, &pN_2.y);
    float angle = ((n - 2) * M_PI) / (2 * n);
    vec2 diagonal;
    diagonal.x = pN_2.x - p0.x;
    diagonal.y = pN_2.y - p0.y;
    vec2 side = rotate(diagonal, -angle);
    vec2 proj = project(diagonal, side);
    // printf("diagonal: (%.2f, %.2f)\n", diagonal.x, diagonal.y);
    // printf("side: (%.2f, %.2f)\n", side.x, side.y);
    // printf("proj: (%.2f, %.2f)\n", proj.x, proj.y);
    // printf("angle: %.2f p1: (%.5f, %.5f)\n", angle * (180.0f / M_PI), proj.x, proj.y);
    printf("%.5f %.5f\n", p0.x + proj.x, p0.y + proj.y);
 
    return 0;
}
