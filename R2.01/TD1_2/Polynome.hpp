#ifndef POLYNOME_HPP
#define POLYNOME_HPP
#include <iostream>

using namespace std;

class Polynome {
    private :
        unsigned int degre;
        double* coef;
    public :
        Polynome(const unsigned int, const double*);        
        Polynome(const Polynome &);
        Polynome() = delete;        
        inline unsigned int getDegre()const {return degre;}
        ~Polynome();
        friend Polynome operator+(const Polynome&, const Polynome&);
        friend Polynome operator-(const Polynome&, const Polynome&);
        Polynome deriver() const;
        Polynome& operator=(const Polynome&);
        friend bool operator==(const Polynome&, const Polynome&);
        double& operator[](const unsigned int&)const;
        double& operator[](const unsigned int&);
        double operator()(const double& x);    
        friend ostream& operator<<(ostream& , const Polynome&);

};

#endif