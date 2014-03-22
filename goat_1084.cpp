#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.141592653589793238462643383279502884197169399375

using namespace std;

/***************************************************/
/* Consult goat.png for more detailed explanation  */
/***************************************************/

int main() {
        double a, r;

        cin >> a;
        cin >> r;

        if (r >= a*sqrt(2.0) / 2) {
                cout << fixed << setprecision(3) << pow(a, 2);
        }
        else if (r <= a / 2) {
                cout << fixed << setprecision(3) << pow(r, 2) * PI;
        }
        else {
                double beta = acos(a/(2*r)) * 180.0/PI; // Angle between a/2 and r multiplied with 180/PI to get radians
                double alpha = 90 - 2*beta;             // Angle of the arc that is in between two beta angles
                double arc_area = pow(r, 2) * PI * alpha / 360;
                double triangle_area = (a/2) * (r*sin(PI/180 * beta)) / 2;
                double area = 4*arc_area + 8*triangle_area;
                cout << fixed << setprecision(3) << area;
        }

        return 0;
}   
