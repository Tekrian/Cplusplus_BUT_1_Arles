#include <iostream>
#include "Polynome.hpp"
#include <cmath>

//Constructuer de polynomes
Polynome::Polynome(const unsigned int _degre, const double * _coef) 
: degre(_degre), coef(nullptr)
{
    coef = new double[degre + 1];
    for(size_t i = 0; i<= degre; i++)
        coef[i] = _coef[i];
    
}

//Constructeur de copie
Polynome::Polynome(const Polynome & src)
: Polynome(src.degre, src.coef)
{
}

//Le destructeur
Polynome::~Polynome()
{
    delete[] coef;
}

//Opérateur d'addition
Polynome operator+(const Polynome& a, const Polynome& b)
{
    const Polynome& big = ( a.degre >= b.degre ? a : b);
    const Polynome& small = ( a.degre < b.degre ? a : b);
    Polynome res(big);
    for(size_t i = 0; i<= small.degre; i++)
        res.coef[i] += small.coef[i];
    return res;
}

Polynome operator-(const Polynome& p1 , const Polynome& p2)
{    
    //Soustraction en addition (p1 + (-p2))

    double* tmp = new double[p2.degre + 1];
    for( size_t i= 0 ; i< p2.degre ; i++ ){
        tmp[i] = -1 *(p2.coef[i]);
    }
    Polynome p(p2.degre , tmp);
    delete [] tmp;
    const Polynome& big = ( p1.degre >= p.degre ? p1 : p);
    const Polynome& small = ( p1.degre < p.degre ? p1 : p);
    Polynome res(big);
    for(size_t i = 0; i<= small.degre; i++)
        res.coef[i] += small.coef[i];
    return res;
}

//Fonction de dérivation
Polynome Polynome::deriver() const
{
    const double val[1] = {0};
    if(degre == 0) return Polynome(0, val);
    double* temp = new double[degre];
    for(size_t i = 1; i<=degre; i++)
        temp[i-1] = i*coef[i];
    Polynome prime(degre-1, temp);
    delete [] temp;
    return prime;
}

//Opérateur d'affectation
Polynome& Polynome::operator=(const Polynome& p)
{
    delete [] coef;
    degre = p.degre;
    coef = new double[degre + 1];
    for(size_t i = 0; i <= degre; i++)
        coef[i] = p.coef[i];
    return *this;
}

//Opérateur de comparaison
bool operator==(const Polynome& a, const Polynome& b)
{
    if(a.degre != b.degre)
        return false;
    for(size_t i = 0; i <= a.degre; i++)
    if(a.coef[i] != b.coef[i])
        return false;
    return true;
}

//le functeur
double Polynome::operator()(const double& x)
{
    double y = 0;
    for(size_t i = 0; i <= degre; i++)
        y += coef[i]* pow(x,i); 
    return y;
}

//ecriture sur le flux
ostream& operator<<(ostream& os, const Polynome& p)
{  
    bool first = true;
    for(size_t i = p.degre+1; i >= 1; i--){
    double c = p.coef[i-1];
    if(c != 0){ // pour na pas afficher les monomes de coef 0
        // Gestion des signes
        if(!first){
            if(c > 0)
                os << "+";
            else
                os << "-";
        }       
        if(abs(c) != 1 || i == 1) // pour ne pas afficher le coef 1 (sauf pour le terme constant)
            os << abs(c);     // abs() pour la valeur absolue (on a déja afficher les signes)
            // Gestion de la variable la variable x
        if(i > 1)   // pour les puissances de x superieures à 1 (car on ne veut pas afficher x^1)
                os << "x^" << i-1;
        else if(i == 1) // pour la puissance de 1
                os << "x";
            first = false;  // pour changer le statut de first après le premier monome affiché
    }
    else if(first /*&& c == 0 */&& i == 1) // polynome nul
        os << "0";   
    
    }   
    return os;
}
