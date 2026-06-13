#include <cmath>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> sides = {3,4,5};
    int a = sides[0];
    int b = sides[1];
    int c = sides[2];
    
    vector<double> ans;
    if(a+b <= c || b+c <= a || c+a <= b ){return 0;}
    double cos_a = (b*b + c*c - a*a) / (2.0*b*c);
    double cos_b = (a*a + c*c - b*b) / (2.0*a*c);
    double cos_c = (a*a + b*b - c*c) / (2.0*a*b);
    
    double angle_radians_of_a = acos(cos_a);
    double angle_radians_of_b = acos(cos_b);
    double angle_radians_of_c = acos(cos_c);
    
    double pi = 3.14159265358979323846;
    double angle_degrees_of_a = angle_radians_of_a * (180.0 / pi);
    double angle_degrees_of_b = angle_radians_of_b * (180.0 / pi);
    double angle_degrees_of_c = angle_radians_of_c * (180.0 / pi);
    
    ans.push_back(angle_degrees_of_a);
    ans.push_back(angle_degrees_of_b);
    ans.push_back(angle_degrees_of_c);
    for(auto i:ans)cout<<i<<endl;
    
}