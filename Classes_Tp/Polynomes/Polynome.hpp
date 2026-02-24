#ifndef POLYNOME_HPP
#define POLYNOME_HPP
#include <iostream>

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
        friend Polynome operator*(const Polynome& a, const Polynome& b);
        Polynome deriver() const;
        Polynome integrer() const;
        Polynome& operator=(const Polynome&);
        friend bool operator==(const Polynome&, const Polynome&);
        
        //Opérateur[] : consultation du monôme de dégre i
        inline double operator[](const unsigned int& i)const
        {
            if(i > degre)                
                throw std::out_of_range("Indice hors limites");
            return coef[i];
        }

        //Opérateur[] : modification du monôme de dégre i
        inline double& operator[](const unsigned int& i)
        {
            if(i > degre)                
                throw std::out_of_range("Indice hors limites");
            return coef[i];            
        }
        //double& operator[](const unsigned int&)const;
        //double& operator[](const unsigned int&);
        double operator()(const double& x);    
        friend std::ostream& operator<<(std::ostream& , const Polynome&);

};

#endif