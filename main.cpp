#include <iostream>
#include <stdio.h>
#include "Polygone.h"

using namespace std;

struct Point2D
{
    double x;
    double y;
};

Point2D compute2DPolygonCentroid(const Point2D* vertices, int vertexCount)
{
    Point2D centroid = {0, 0};
    double signedArea = 0.0;
    double x0 = 0.0; // Current vertex X
    double y0 = 0.0; // Current vertex Y
    double x1 = 0.0; // Next vertex X
    double y1 = 0.0; // Next vertex Y
    double a = 0.0;  // Partial signed area

    // For all vertices except last
    int i=0;
    for (i=0; i<vertexCount-1; ++i)
    {
        x0 = vertices[i].x;
        y0 = vertices[i].y;
        x1 = vertices[i+1].x;
        y1 = vertices[i+1].y;
        a = x0*y1 - x1*y0;
        signedArea += a;
        centroid.x += (x0 + x1)*a;
        centroid.y += (y0 + y1)*a;
    }

    // Do last vertex separately to avoid performing an expensive
    // modulus operation in each iteration.
    x0 = vertices[i].x;
    y0 = vertices[i].y;
    x1 = vertices[0].x;
    y1 = vertices[0].y;
    a = x0*y1 - x1*y0;
    signedArea += a;
    centroid.x += (x0 + x1)*a;
    centroid.y += (y0 + y1)*a;

    signedArea *= 0.5;
    centroid.x /= (6.0*signedArea);
    centroid.y /= (6.0*signedArea);

    return centroid;
}

int main()
{
    Point2D polygon[] = {{-1.0,1.0}, {-1.0,-1.0}, {1.0,-1.0}, {1.0,1.0}};       //(-1, 1)(-1, -1)(1, -1)(1, 1)
    size_t vertexCount = sizeof(polygon) / sizeof(polygon[0]);
    Point2D centroid = compute2DPolygonCentroid(polygon, vertexCount);
    std::cout << "Le centre de gravite vaut (" << centroid.x << ", " << centroid.y << ")\n";
}



//{{0.0,0.0}, {0.0,10.0}, {10.0,10.0}, {10.0,0.0}}
