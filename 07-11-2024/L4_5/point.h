#ifndef _POINT_
#define _POINT_
typedef struct {
    float x;
    float y;
} tPonto;

tPonto create_point(float x, float y);
tPonto read_point();
float get_distance(tPonto pA, tPonto pB);
#endif