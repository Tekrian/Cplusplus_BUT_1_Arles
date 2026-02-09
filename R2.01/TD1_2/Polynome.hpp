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
        
        //Opérateur[] : consultation du monôme de dégre i
        inline double& operator[](const unsigned int& i)const
        {
            if(i <= degre)
                return coef[i];
            else
                throw runtime_error("Votre coefficient est superieur au degre du polynome");
            
        }

        //Opérateur[] : modification du monôme de dégre i
        inline double& operator[](const unsigned int& i)
        {
            if(i <= degre)
                return coef[i];
            else
                throw runtime_error("Votre coefficient est superieur au degre du polynome");
            
        }
        //double& operator[](const unsigned int&)const;
        //double& operator[](const unsigned int&);
        double operator()(const double& x);    
        friend ostream& operator<<(ostream& , const Polynome&);

};

#endif