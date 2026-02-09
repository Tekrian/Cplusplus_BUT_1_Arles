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

//Soustraction
Polynome operator-(const Polynome& a, const Polynome& b) 
{
    const Polynome& big = ( a.degre >= b.degre ? a : b);
    const Polynome& small = ( a.degre < b.degre ? a : b);
    double* temp = new double[small.degre+1];
    for(size_t i = 0 ; i <= small.degre; i++)
        temp[i] = -small.coef[i];
    Polynome res(big);
    for(size_t i = 0 ; i <= small.degre; i++)
        res.coef[i] += temp[i];
    delete [] temp;
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

//Opérateur[] : consultation du monôme de dégre i
double& Polynome::operator[](const unsigned int& i)const
{
    if(i <= degre)
        return coef[i];
    else
        throw runtime_error("Votre coefficient est superieur au degre du polynome");
    
}

//Opérateur[] : modification du monôme de dégre i
double& Polynome::operator[](const unsigned int& i)
{
    if(i <= degre)
        return coef[i];
    else
        throw runtime_error("Votre coefficient est superieur au degre du polynome");
    
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
    for(size_t i = p.degre+1; i >= 1; i--)
        if(p.coef[i-1] != 0){
            if(i != p.degre +1 && p.coef[i-1] > 0)
                cout << "+";            
            cout << p.coef[i-1];
        }
    return os;
}