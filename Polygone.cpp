#include "Polygone.h"
#include <stdio.h>

bool Inside(int n,POINT pg[],int X,int Y) {
  bool b=false; // (u,v) = point "précédent"
  int x=pg[0].x,u=pg[n-1].x,y=pg[0].y,v=pg[n-1].y;
  for (int i=0; i<n; ++i,u=x,x=pg[i].x,v=y,y=pg[i].y)
    if (((u>X)!=(x>X)) && (Y<(v+(X-u)*(y-v)/(x-u)))) b=!b;
  return b;
}

bool InsideBis(int n,POINT pg[],int X,int Y) {
  bool b=false;
  for (int j=n-1,i=0; i<n; j=i++) // j = index "précédent"
    if (((pg[j].x>X)!=(pg[i].x>X)) && (Y<(pg[j].y+(X-pg[j].x)*(pg[i].y-pg[j].y)/(pg[i].x-pg[j].x)))) b=!b;
  return b;
}

bool Inside(int n,real xx[],real yy[],real X,real Y) {
  bool b=false; // (u,v) = point "précédent"
  real x=xx[0],u=xx[n-1],y=yy[0],v=yy[n-1];
  for (int i=0; i<n; ++i,u=x,x=xx[i],v=y,y=yy[i])
    if (((u>X)!=(x>X)) && (Y<(v+(X-u)*(y-v)/(x-u)))) b=!b;
  return b;
}

real Area(int n,POINT pg[]) {
  real A=0; // j = index "précédent"
  for (int j=n-1,i=0; i<n; j=i++) A+=pg[j].x*pg[i].y-pg[j].y*pg[i].x;
  return A/2;
}

real Area(int n,real xx[],real yy[]) {
  real A=0; // j = index "précédent"
  for (int j=n-1,i=0; i<n; j=i++) A+=xx[j]*yy[i]-yy[j]*xx[i];
  return A/2;
}

real AreaCenter(int n,POINT pg[],real *xCenter,real *yCenter) {
  real A=0,a,xC=0,yC=0;
  for (int j=n-1,i=0; i<n; j=i++) { // j = index "précédent"
    A+=(a=(real)(pg[j].x*pg[i].y-pg[j].y*pg[i].x));
    xC+=a*(pg[j].x+pg[i].x); yC+=a*(pg[j].y+pg[i].y);
  }
  *xCenter=xC/A/3; *yCenter=yC/A/3; return A/2;
}

real AreaCenter(int n,real xx[],real yy[],real *xCenter,real *yCenter) {
  real A=0,a,xC=0,yC=0;
  for (int j=n-1,i=0; i<n; j=i++) { // j = index "précédent"
    A+=(a=xx[j]*yy[i]-yy[j]*xx[i]);
    xC+=a*(xx[j]+xx[i]); yC+=a*(yy[j]+yy[i]);
  }
  *xCenter=xC/A/3; *yCenter=yC/A/3; return A/2;
}

POINT *PolygoneRegulier(int n,int r,int X,int Y) { // n>=3
  POINT *pg=(POINT*)malloc(n*sizeof(POINT));
  real da=(2*(real)3.14159265358979324)/n,a=0;
  for (int i=0; i<n; ++i,a+=da) {pg[i].x=X+(int)(r*cos(a)); pg[i].y=Y+(int)(r*sin(a));}
  return pg; // after use ==> free(pg)
}

POINT *PolygoneEnSpirale(int n,int siz,int X,int Y) { // n= Nombre d'arêtes
  POINT *pg=(POINT*)malloc(2*(1+n)*sizeof(POINT));
  for (int i=0,m=2*(1+n)-1; i<=n; ++i,--m) {
    int u=siz*((i&2)?-i:i),v=siz*((i&2)?-i-2:i+2);
    if (i&1) {pg[i].x=pg[m].x=X; pg[i].y=Y-u; pg[m].y=Y-v;} // i impair
    else     {pg[i].y=pg[m].y=Y; pg[m].x=X+v; pg[i].x=X+u;} // i pair
  }
  return pg; // after use ==> free(pg)
}
