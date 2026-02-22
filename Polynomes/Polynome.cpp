#include <iostream>
#include "Polynome.hpp"
#include <cmath>

//================Constructuer de polynomes
Polynome::Polynome(const unsigned int _degre, const double * _coef) 
: degre(_degre), coef(nullptr)
{
    coef = new double[degre + 1];
    for(size_t i = 0; i<= degre; i++)
        coef[i] = _coef[i];
    
}

//==============Constructeur de copie
Polynome::Polynome(const Polynome & src)
: Polynome(src.degre, src.coef)
{
}

//===============Le destructeur
Polynome::~Polynome()
{
    delete[] coef;
}

//==============Opérateur d'addition
Polynome operator+(const Polynome& a, const Polynome& b)
{
    const Polynome& big = ( a.degre >= b.degre ? a : b);
    const Polynome& small = ( a.degre < b.degre ? a : b);
    Polynome res(big);
    for(size_t i = 0; i<= small.degre; i++)
        res.coef[i] += small.coef[i];
    return res;
}

//==============Opérateur de soustraction
Polynome operator-(const Polynome& p1 , const Polynome& p2)
{    
    //Soustraction en addition (p1 + (-p2))

    double* tmp = new double[p2.degre + 1];
    for( size_t i= 0 ; i<= p2.degre ; i++ ){
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

//=============Opérateur multiplication
Polynome operator*(const Polynome& a, const Polynome& b)
{
    unsigned int degreRes = a.degre + b.degre;
    double* resCoef = new double[degreRes+1];

    for(unsigned int i = 0; i<= degreRes; i++)
        resCoef[i] = 0;
    
    for(unsigned int i = 0; i<= a.degre; i++)
        for(unsigned int j = 0; j<= b.degre; j++)
            resCoef[i+j] += a.coef[i] * b.coef[j];
    Polynome res(degreRes, resCoef);
    delete[] resCoef;

    return res;
}

//====================Fonction de dérivation
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

//====================Fonction d'intégration (une primitive de l'instance)
Polynome Polynome::integrer() const
{
    unsigned int nouveauDegre = degre + 1;
    double* temp = new double[nouveauDegre + 1];

    for(size_t i = 0; i < nouveauDegre; i++)
        temp[i + 1] = coef[i] / (double)(i + 1);
    temp[0] = 0;        // la constante prise est 0

    Polynome primitive(nouveauDegre, temp);
    delete[] temp;

    return primitive;
}

//================Opérateur d'affectation
Polynome& Polynome::operator=(const Polynome& p)
{   
    if(this != &p){     // Cas ou on doit affecter le même poly (p1 = p1) :Une exception 
    delete [] coef;
    degre = p.degre;
    coef = new double[degre + 1];
    for(size_t i = 0; i <= degre; i++)
        coef[i] = p.coef[i];
    }
    return *this;
}

//=========================Opérateur de comparaison
bool operator==(const Polynome& a, const Polynome& b)
{
    if(a.degre != b.degre)
        return false;
    for(size_t i = 0; i <= a.degre; i++)
    if(a.coef[i] != b.coef[i])
        return false;
    return true;
}

//=================================le functeur
double Polynome::operator()(const double& x)
{
    double y = 0;
    for(size_t i = 0; i <= degre; i++)
        y += coef[i]* pow(x,i); 
    return y;
}

//===========================ecriture sur le flux
std::ostream& operator<<(std::ostream& os, const Polynome& p)
{  
    bool first = true;
    for(size_t i = p.degre+1; i >= 1; i--){
    double c = p.coef[i-1];
    if(c != 0){ 
        // Gestion des signes
        if(!first && c > 0)
            os << "+";
            else if (c <0)
                os << "-";
        if(abs(c) != 1 || i == 1)                   // pour ne pas afficher le coef 1 (sauf pour le terme constant coef 0)
            os << abs(c);
            // Gestion de l'afichage de x
        if(i > 2)                                  // car on ne veut pas afficher x^1
                os << "x^" << i-1;
        else if(i == 2)                            // pour la puissance de 1
                os << "x";
            first = false;  // pour changer le statut de first après le premier monome affiché
    }
    else if(first && i == 1)                       // polynome nul
        os << "0";   
    
    }   
    return os;
}
