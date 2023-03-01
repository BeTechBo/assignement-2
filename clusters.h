// Ebram Thabet 900214496
#include <iostream>
#include <cmath>
using namespace std;

class point{
    private:
    float x,y;
    public:
    point(){x= 0.0; y = 0.0;}
    void set_x(float a) {x = a;}
    void set_y(float b) {y = b;}
    float get_x(){return x;}
    float get_y(){return y;}
    void display_as_coordinate(){cout << '(' << x << ',' << y << ')' <<endl;}
    float distance_to_another_point(point p){
        float d = sqrt(pow((x-p.x),2) + pow((y-p.y),2)); 
        return d;
    }
};