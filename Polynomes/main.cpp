#include "Polynome.hpp"
#include <iostream>

using namespace std;
 
int main()
{
    const double coef_p1[] = {3,-1.414,3,6,0,1};
    Polynome p1(5, coef_p1);
    cout<< "p1(x) = " << p1 << "et son degre est " << p1.getDegre() << "." << endl;

    const double coef_p2[]= {4,-2,3,1,-2,-1};
    Polynome p2(5, coef_p2);
    cout<< "p2(x) = " << p2 << "et son degre est " << p2.getDegre() << "." << endl;

    cout << "Construction de p3 comme copie de p2. " << endl;
    Polynome p3(p2);
    if(p3 == p2)
        cout<< "p3 est egale a p2 ... Ce qui est rassurant pour une copie !" << endl;

    cout << "Affectation de p1 à p3." << endl;
    p3 = p1;

    cout << "On affecte le coefficient du monome de degre 1 a la constante de p3." << endl;
    p3[0] = p3[1];
    cout << "p3 est maintenant egal a p3(x) =" << p3 << endl;
    if(p2 == p3)
        cout << "p2 est egal a p3 ... ce qui ne devrait pas arriver !" << endl;
    else
        cout << "p2 est maintenant different de p3 !" << endl;

    cout << "(p1+p2)(x)=" << p1+p2 << endl;

    cout << "Sachant que p1(x)=" << p1
         << ", on peut calculer ses valeurs en fonction de x : " << endl;
    for(double x=-2; x<=2; x+=1)
        cout << "pour p1(" << x <<")=" << p1(x) << endl;

    cout << "Le polynome p2(x)=" << p2 ;
    Polynome p2prime(p2.deriver());
    cout << " a pour derivee p2'(x)=" << p2prime;

    return 0;
}
