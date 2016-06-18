#include "geometry.h"
#include "fct.h"

double ComputeDistance(Point A, Point B) {
    return sqrt((B.x - A.x)*(B.x - A.x) + (B.y - A.y)*(B.y - A.y) + (B.z - A.z)*(B.z - A.z));
}
