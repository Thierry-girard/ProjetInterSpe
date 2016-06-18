#include <cmath>
#include "geometry.h"


using namespace std;

Vector operator*(double const& coeff, Vector const& a) {
    return Vector(coeff * a.x, coeff * a.y, coeff * a.z);
}


Vector::Vector(Point p1, Point p2)
{
    x = p2.x - p1.x;
    y = p2.y - p1.y;
    z = p2.z - p1.z;
}


double Vector::norm()
{
    double norm;

    norm = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

    return norm;
}

double distance(Point p1, Point p2)
{
    Vector vect(p1, p2);
    return vect.norm();
}

double ComputeDistance(Point A, Point B) {
    return sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y) + (B.z - A.z)*(B.z - A.z));
}

Vector GetVector(Point A, Point B) {
    return Vector(B.x - A.x, B.y - A.y, B.z - A.z);;
}
