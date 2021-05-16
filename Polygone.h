#include <math.h>
#include <windows.h>

typedef float real; // ou typedef double real;
// typedef struct tagPOINT {LONG x; LONG y;} POINT;

bool Inside(int n,POINT *pg,int X,int Y);
bool Inside(int n,real xx[],real yy[],real X,real Y);

real Area(int n,POINT *pg);
real Area(int n,real *x,real *y);

real AreaCenter(int n,real x[],real y[],real *xCenter,real *yCenter);
real AreaCenter(int n,POINT pg[],real *xCenter,real *yCenter);

POINT *PolygoneRegulier(int n,int r,int X,int Y);
POINT *PolygoneEnSpirale(int n,int siz,int X,int Y);