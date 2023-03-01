#include "D:\spring 2023\CS 2\assignments\assignment 2\prototyping.h" // please change this path to the one in your computer
#include <time.h>


point center(point *p , int n) {

point center_p;
float avg_x = 0 , avg_y = 0;
for(int i = 0; i<n; i++){
avg_x += (p+i)->get_x();
avg_y += (p+i)->get_y();
}
avg_x/=n; avg_y/=n;
center_p.set_x(avg_x);
center_p.set_y(avg_y); 
return center_p;
} 

int closest(point *p, int s1 , point *q , int s2 , point x){
    point center_p = center(p , s1);
    point center_q = center(q , s2);
    float d1 = x.distance_to_another_point(center_p);
    float d2 = x.distance_to_another_point(center_q);
    if(d1 < d2){return 1;}
    else if(d2 < d1){return 2;}
    else{return 0;} // if we would ignore the fact that the point may be as close to A as B, we can use the shorthand (d1<d2) ? 1 : 2;
    }

int main(){

srand(time(0));

int res;
float x,y;

point *A = new point[200];
point *B = new point[200];

for(int i = 0; i<200; i++){

x = x = 70.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(20.0)));
y = y = 70.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(20.0)));

(A+i)->set_x(x);
(A+i)->set_y(y);

}
for(int j = 0; j<200; j++){

x = 20.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(40.0-20.0)));
y = 20.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(40.0-20.0)));

(B+j)->set_x(x);
(B+j)->set_y(y);
}

cout << "Center of cluster A is of coordinates: " ; center(A , 200).display_as_coordinate();
cout << "Center of cluster B is of coordinates: " ; center(B , 200).display_as_coordinate();

point *points = new point[20];

for(int k = 0; k <20; k++){

x = 5.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(100.0-5.0)));
y = 5.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(100.0-5.0)));

(points+k)->set_x(x);
(points+k)->set_y(y);

cout << "Point " << k+1 <<  " has coordinates "; (*(points+k)).display_as_coordinate(); 

res = closest(A , 200 , B , 200 , *(points+k)); 
(res != 0) ? (cout << " it is closest to cluster " << res << endl) : (cout <<" it is as close to A as B\n");
}

delete A; delete B; delete points; // deleting the pointers
}