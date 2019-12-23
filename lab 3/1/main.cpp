#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <fstream>

using namespace std;
ifstream fin("date.in");
struct Punct
{
    double x, y;
};

int sortare_pct(const void* P,const void* Q)
{
    Punct* A = (Punct*)P;
    Punct* B = (Punct*)Q;
    if (A -> x == B -> x) {
        if (A -> y < B -> y)
            return -1;
        return 1;
    }
    if (A -> x < B -> x)
        return -1;
    return 1;
}

double det(double a, double b, double c, double d)
{

    return (double)(a*d - b*c);
}
int main()
{

    Punct A[4];
    double a1, b1, c1, a2, b2, c2;
    for (int i = 0; i < 4; i++)
        {
            //cout << "Citire (x, y) punct " << i + 1<< " : ";
            fin >> A[i].x >> A[i].y;
        }
    a1 = A[0].y - A[1].y; ///ecuatiile dreptelor
    b1 = A[1].x - A[0].x;
    c1 = A[0].x * A[1].y - A[1].x * A[0].y;

    a2 = A[2].y - A[3].y;
    b2 = A[3].x - A[2].x;
    c2 = A[2].x * A[3].y - A[3].x * A[2].y;

    double d;
    d = det(a1, b1, a2, b2); ///determinant
    if (d != 0)
    {
        double x, y;
        x = det(-c1, b1, -c2, b2) / d; ///cramer
        y = det(a1, -c1, a2, -c2) / d;
        //se afla pe AB sau pe CD intr-un mod sau altul
        if (((A[0].x <= x && x <= A[1].x) || (A[1].x <= x && x <= A[0].x)) && ((A[0].y <= y && y <= A[1].y) || (A[1].y <= y && y <= A[0].y))
            && ((A[2].x <= x && x <= A[3].x) || (A[3].x <= x && x <= A[2].x)) && ((A[2].y <= y && y <= A[3].y) || (A[3].y <= y && y <= A[2].y))) ///verific daca (x,y) apartine [A1,A2]
            {
                cout << "Intersectia se afla la punctele: "<< x << " " << y;
                return 0;
            }
        else
        {
            cout << "intersectia punctelor nu se afla pe AB si CD. Intersectia este multimea vida";
            return 0;
        }
    }
    else
    {
        ///intersectia dreptelor
        if ((a1 * c2 - a2 * c1 == 0) && (b1 * c2 - b2 * c1 == 0)) ///det matricei extinse sa fie identice cu det d
            {
                cout << "Punctele sunt coliniare." << endl;
                    ///verific pozitionare lor pe segment
                    if ((A[0].x < A[2].x && A[0].x < A[3].x && A[1].x < A[2].x && A[1].x < A[3].x) || (A[0].x > A[2].x&& A[0].x > A[3].x&& A[1].x > A[2].x&& A[1].x > A[3].x))
                    {
                        cout<<"Segmentele nu se intersecteaza1.";
                        return 0;
                    }
                qsort(A, 4, sizeof(Punct), sortare_pct);
                cout << A[1].x << " " << A[1].y << endl;
                cout << A[2].x << " " << A[2].y << endl;
                return 0;
            }
        cout << "Segmentele nu se intersecteaza2.";
        return 0;

    }
    cout << "Segmentele nu se intersecteaza3.";
    return 0;
}
