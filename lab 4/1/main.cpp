#include <bits/stdc++.h>
using namespace std;

ifstream fin("date.in");

#define PI 3.141
struct punct{
    double x, y;
};

// dinst dintre 2 pct
float dist(punct a, punct b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// produsul scalar dintre 2 vectori
double prod(punct a, punct b, punct c, punct d)
{
    double x1 = b.x - a.x;
   double y1 = b.y - a.y;
    double x2 = d.x - c.x;
   double y2 = d.y - c.y;

    return x1 * x2 + y1 * y2;
}

// cos (A) = <AB, AC> / ||AB||.||AC||
double arc_cosinus(punct a, punct b, punct c){
    double produs = prod(a, b, a, c); ///<A2A3 , A2A1 > - produsul scalar
    double dist1 = dist(a, b); ///  || A2A1 || - distanta dintre cei 2 vectori
    double dist2 = dist(a, c); ///  || A2A3 ||
    double x = produs / (dist1 * dist2);
    return acos(x); // arccos(A)
}

int test_orientare(punct a, punct b, punct c)
{
    double d;
    d = b.x * c.y + a.x * b.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
    if(d < 0)
        return 1;
    return 0;
}

bool convex(punct A1, punct A2, punct A3, punct A4)
{
    if((test_orientare(A1, A2, A3) == 1 && test_orientare(A2, A3, A4) == 1 && test_orientare(A3, A4, A1) == 1 && test_orientare(A4, A1, A2) == 1 ||
        (test_orientare(A1, A2, A3) == 0 && test_orientare(A2, A3, A4) == 0 && test_orientare(A3, A4, A1) == 0 && test_orientare(A4, A1, A2) == 0 )))
            return true;
    return false;
}

int main()
{
    punct A, B, C, D;
    fin >> A.x >> A.y;
    fin >> B.x >> B.y;
    fin >> C.x >> C.y;
    fin >> D.x >> D.y;
    if(convex(A, B, C, D) == 0)
    {
        cout << "Nu este convex!";
        exit(0);
    }
    cout << "\nEste convex!\n";

    // cosA2+cosA4
    double A2 = arc_cosinus(B, A, C); ///ABC
    double A4 = arc_cosinus(D, A, C); ///ADC
   // cout<<x;

    if(A2 + A4 - PI < 0.01 && A2 + A4 - PI > -0.01) ///aproximativ PI
        cout << "\npunctul D este pe cercul circumscris \n";
    else if(A2 + A4 > PI )
            cout << "\npunctul D este in interiorul cercului circumscris \n";
         else cout << "\npunctul D este in exteriorul cercului circumscris \n";

    return 0;
}
