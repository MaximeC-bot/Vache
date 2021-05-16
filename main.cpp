#include <iostream>
#include <stdio.h>
#include "Polygone.h"

using namespace std;

struct Point2D  //emplacement du point dans l'espace
{
    double x;
    double y;
};

/**
Fonction permettant le calcul de l'aire
et du centre de gravit� du polygone
Param�tres d'entr�e: l'emplacement et le nombre de sommets
Param�tres renvoy�es: Centre de gravit� du polygone
*/

Point2D Geometrie(const Point2D* sommets, int NbSommets)
{
    Point2D CntrGravite = {0, 0};
    double Aire = 0.0;
    double x0 = 0.0; // abscisse du sommet
    double y0 = 0.0; // ordonn�e du sommet
    double x1 = 0.0; // abscisse du sommet suivant
    double y1 = 0.0; // ordonn�e du sommet suivant
    double a = 0.0;  //calcul de l'aire

    //
    int i=0;
    for (i=0; i<NbSommets-1; ++i)
    {
        x0 = sommets[i].x;
        y0 = sommets[i].y;
        x1 = sommets[i+1].x;
        y1 = sommets[i+1].y;
        a = x0*y1 - x1*y0;
        Aire += a;
        CntrGravite.x += (x0 + x1)*a;
        CntrGravite.y += (y0 + y1)*a;
    }

    // Do last vertex separately to avoid performing an expensive
    // modulus operation in each iteration.
    x0 = sommets[i].x;
    y0 = sommets[i].y;
    x1 = sommets[0].x;
    y1 = sommets[0].y;
    a = x0*y1 - x1*y0;
    Aire += a;
    CntrGravite.x += (x0 + x1)*a;
    CntrGravite.y += (y0 + y1)*a;

    Aire *= 0.5;
    cout << "L'aire est egale a "<<Aire << "\n";
    CntrGravite.x /= (6.0*Aire); //abscisse du centre de gravit�
    CntrGravite.y /= (6.0*Aire); //ordonn�e du centre de gravit�

    return CntrGravite;
}

int main()
{
    Point2D Polygone[] = {{-1.0,1.0}, {-1.0,-1.0}, {1.0,-1.0}, {1.0,1.0}};
    size_t NbSommets = sizeof(Polygone) / sizeof(Polygone[0]);
    Point2D CntrGravite = Geometrie(Polygone, NbSommets);
    cout << "L'abscisse du centre de gravite vaut " << CntrGravite.x << ", et son ordonnee vaut " << CntrGravite.y << "\n";
}

