#include <iostream>

using namespace std;
///(1,2,3) (2,1,3) (4,1, 1)
typedef struct{double x, y}pct;

int main()
{
    pct A1, A2, A3, A4;
    cout << "Coordonatele lui A1: ";
    cin >> A1.x >> A1.y;

    cout << "\nCoordonatele lui A2: ";
    cin >> A2.x >> A2.y;

    cout << "\nCoordonatele lui A3: ";
    cin >> A3.x >> A3.y;

    cout << "\nCoordonatele lui A4: ";
    cin >> A4.x >> A4.y;
    if(A2.x == A1.x && A2.y == A1.y && A2.z == A1.z) ///pentru A1 = A2 rez a), b)
        cout << "\nCaz A2 = A1 \na) punctele sunt coliniare \n b)A1 = 1*A2 + 0*A3\n";
    else
    {
        int ok = 1;
        double a;
        if(A2.y - A1.y != 0)
            a = (A3.y - A1.y)/(A2.y - A1.y);
        else
            if(A2.x - A1.x != 0)
                a = (A3.x - A1.x)/(A2.x - A1.x);

        if(A3.x - A1.x != a * (A2.x - A1.x))
            ok = 0;
        if(A3.y - A1.y != a * (A2.y - A1.y))
            ok = 0;

        if(ok == 0)
            {
                cout << "\na) punctele nu sunt coliniare!";
                cout << "\nb) Nu se pot exprima ca o combinatie afina pentru ca nu sunt coliniare!";
            }
        else
        {
            cout << "\nPunctele sunt coliniare";
            cout << "\nZ = " << (double)(1 - a) << " *A " << (double)a << " *B";
        }
    }
    return 0;
}
