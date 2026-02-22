#include "Polynome.hpp"
#include <iostream>

using namespace std;

int main()
{
    int sizeMax = 10;
    Polynome *memory[sizeMax];
    for (int i = 0; i < sizeMax; i++)
        memory[i] = nullptr;

    // Etat des emplacements et affichage==========================================
    int choice = -1;
    cout << "===PROGRAMME DES POLYNOMES===" << endl;

    while (choice != 0)
    {   // BOUCLE D'AFFICHAGE=======================================================
        cout << endl;
        cout << "------Etat des emplacements------" << endl; 
        cout << endl;
        for (int i = 0; i < sizeMax; i++)
        {
            cout << "Emplacement[" << i << "] : " ;
            if (memory[i] == nullptr)
                cout << "vide" << endl;
            else
                cout << *(memory[i]) << endl;
        }

        cout << "\n Quelle action voullez-vous faire ?" << endl;
        cout << "Actions :" << endl;
        cout << "1. Saisir" << endl;
        cout << "2. Addition" << endl;
        cout << "3. Soustraction" << endl;
        cout << "4. Derivation" << endl;
        cout << "5. Multiplication" << endl; 
        cout << "6. Integration" << endl;
        cout << "7. Evaluation P(x)" << endl; 
        cout << "0. Quitter" << endl;
        cout << endl;
        cout << "Votre choix : ";
        cin >> choice;
        cout << endl;
       
        //========SAISIE
        if (choice == 1)
        {
            cout << "===Saisie du polynome=== "<<endl;
            cout << endl;
            int indice; 
            unsigned int degree;
            cout << "Saisir l'indice de l'emplacement : ";
            cin >> indice;
            while (indice >= sizeMax || indice < 0){
                cout << "Indice hors limites,valeur des indices entre 0 et " << sizeMax-1 << endl; 
                cout << "Veuillez ressaisir : " << endl;
                cin >> indice;
            }

            cout << "Saisir le degre du polynome (>0): ";
            cin >> degree;
            while (degree < 0){
                cout << "Degre du polynome doit etre superieur ou egal a 0." << endl; 
                cout << "Veuillez ressaisir : " << endl;
                cin >> degree;
            }

            double *coeff = new double[degree + 1];
            cout << "Saisie des coefficients du polynome : ";
            cout << endl;
            for (size_t i = 0; i <= degree; i++)
            {
                cout << "Coefficient de x^" << i << " : ";
                cin >> coeff[i];
            }            
                
            if (memory[indice] != nullptr)      //Ecraser s'il y a des données existantes
                delete memory[indice];
            
            memory[indice] = new Polynome(degree, coeff);             
            
            delete[] coeff;
        }

        //========ADDITION
        else if (choice == 2)
        {
            cout << "===ADDITION=== "<<endl;
            cout << endl;
            int indice1, indice2, indiceRes;              
            cout << "Saisir l'indice de l'emplacement du premier polynome : ";
            cin >> indice1;
            cout << "Saisir l'indice de l'emplacement du second polynome : ";
            cin >> indice2;
            cout << "Saisir l'indice de l'emplacement du resultat : ";
            cin >> indiceRes;
            cout << endl;
            while(indice1 >= sizeMax || indice1 < 0 || indice2 >= sizeMax || indice2 < 0 || indiceRes >= sizeMax || indiceRes < 0)
            {
                cout << "Indice hors limites,valeur des indices entre 0 et " << sizeMax-1 << endl; 
                cout << "Veuillez ressaisir : " << endl;
                cout << "Saisir l'indice de l'emplacement du premier polynome : ";
                cin >> indice1;
                cout << "Saisir l'indice de l'emplacement du second polynome : ";
                cin >> indice2;
                cout << "Saisir l'indice de l'emplacement du resultat : ";
                cin >> indiceRes;
                cout << endl;
            }          
                        
            while (memory[indice1] == nullptr || memory[indice2] == nullptr)
            { 
                cout << "Un des emplacements est vide, veuillez ressaisir." << endl;
                cout << "Saisir l'indice de l'emplacement du premier polynome : ";
                cin >> indice1;
                cout << "Saisir l'indice de l'emplacement du second polynome : ";
                cin >> indice2;
                while (indice1 < 0 || indice1 >= sizeMax || indice2 < 0 || indice2 >= sizeMax)
                {
                    cout << "Indice hors limites,valeur des indices entre 0 et " << sizeMax-1 << endl; 
                    cout << "Veuillez ressaisir : " << endl;
                    cout << "Saisir l'indice de l'emplacement du premier polynome : ";
                    cin >> indice1;
                    cout << "Saisir l'indice de l'emplacement du second polynome : ";
                    cin >> indice2;
                }                
            }
                
                        
            Polynome somme = *(memory[indice1]) + *(memory[indice2]);
                    
            if(memory[indiceRes] != nullptr) //Ecraser s'il y a des données existantes
                delete memory[indiceRes];
            memory[indiceRes] = new Polynome(somme);                              
        }

        //========SOUSTRACTION
        else if( choice == 3) {
            cout << "===SOUSTRACTION=== "<<endl;
            cout << endl;
            int indice1, indice2, indiceRes;         
            cout << "Saisir l'indice du premier polynome : ";
            cin >> indice1;
            cout << "Saisir l'indice du second polynome : ";
            cin >> indice2;
            cout << "Saisir l'indice de l'emplacement du resultat : ";
            cin >> indiceRes;
            cout << endl; 
            while(indice1 >= sizeMax || indice1 < 0 || indice2 >= sizeMax || indice2 < 0 || indiceRes >= sizeMax || indiceRes < 0)
            {
                cout << "Indice hors limites,valeur des indices entre 0 et " << sizeMax-1 << endl; 
                cout << "Veuillez ressaisir : " << endl;
                cout << "Saisir l'indice du premier polynome : ";
                cin >> indice1;
                cout << "Saisir l'indice du second polynome : ";
                cin >> indice2;
                cout << "Saisir l'indice de l'emplacement du resultat : ";
                cin >> indiceRes;
                cout << endl; 
            }
            while (memory[indice1] == nullptr || memory[indice2] == nullptr)
            {
                cout << "Un des emplacements est vide, veuillez ressaisir." << endl;
                cout << "Saisir l'indice du premier polynome : ";
                cin >> indice1;
                cout << "Saisir l'indice du second polynome : ";
                cin >> indice2;
                while(indice1 >= sizeMax || indice1 < 0 || indice2 >= sizeMax || indice2 < 0)
                {
                    cout << "Indice hors limites,valeur des indices entre 0 et " << sizeMax-1 << endl; 
                    cout << "Veuillez ressaisir : " << endl;
                    cout << "Saisir l'indice du premier polynome : ";
                    cin >> indice1;
                    cout << "Saisir l'indice du second polynome : ";
                    cin >> indice2; 
                }
            }
            
            Polynome res = *(memory[indice1]) - *(memory[indice2]);
            if(memory[indiceRes] != nullptr)
                delete memory[indiceRes];
            memory[indiceRes] = new Polynome(res);           
        }

        //========DERIVATION
        else if(choice == 4){
            cout << "===DERIVATION=== "<<endl;
            cout << endl;
            int indice, indiceRes;
            cout << "Saisir l'indice de l'emplacement du polynome a deriver : ";
            cin >> indice;            
            cout << "Saisir l'indice de l'emplacement du resultat : " ;
            cin >> indiceRes;
            cout << endl;

            while(indice >= sizeMax || indice < 0 || indiceRes >= sizeMax || indiceRes < 0)
            {
                cout << "Indice hors limites,valeur des indices entre 0 et " << sizeMax-1 << endl; 
                cout << "Veuillez ressaisir : " << endl;
                cout << "Saisir l'indice de l'emplacement du polynome a deriver : ";
                cin >> indice;            
                cout << "Saisir l'indice de l'emplacement du resultat : " ;
                cin >> indiceRes;
                cout << endl;
            }
            while (memory[indice] == nullptr)
            {
                cout << "L'emplacement " << indice << " est vide, veuillez ressaisir." << endl;
                cout << "Saisir l'indice de l'emplacement du polynome a deriver : ";
                cin >> indice;
            }
                    Polynome res = (memory[indice])->deriver();

                    if(memory[indiceRes] != nullptr)
                        delete memory[indiceRes];
                    memory[indiceRes] = new Polynome(res);
        }

        //========MULTIPLICATION
        else if(choice == 5){
            cout << "===MULTIPLICATION=== "<<endl;
            cout << endl;
            int indice1, indice2, indiceRes;
                          
            cout << "Saisir l'indice de l'emplacement du premier polynome : ";
            cin >> indice1;
            cout << "Saisir l'indice de l'emplacement du second polynome : ";
            cin >> indice2;
            cout << "Saisir l'indice de l'emplacement du resultat : ";
            cin >> indiceRes;
            cout << endl;
            while(indice1 >= sizeMax || indice1 < 0 || indice2 >= sizeMax || indice2 < 0 || indiceRes >= sizeMax || indiceRes < 0)
            {
                cout << "Indice hors limites,valeur des indices entre 0 et " << sizeMax-1 << endl; 
                cout << "Veuillez ressaisir : " << endl;
                cout << "Saisir l'indice de l'emplacement du premier polynome : ";
                cin >> indice1;
                cout << "Saisir l'indice de l'emplacement du second polynome : ";
                cin >> indice2;
                cout << "Saisir l'indice de l'emplacement du resultat : ";
                cin >> indiceRes;
                cout << endl;
            }

            while (memory[indice1] == nullptr || memory[indice2] == nullptr)
            {
                cout << "Un des emplacements est vide, veuillez ressaisir." << endl;
                cout << "Saisir l'indice de l'emplacement du premier polynome : ";
                cin >> indice1;
                cout << "Saisir l'indice de l'emplacement du second polynome : ";
                cin >> indice2;
                while(indice1 >= sizeMax || indice1 < 0 || indice2 >= sizeMax || indice2 < 0)
                {
                    cout << "Indice hors limites,valeur des indices entre 0 et " << sizeMax-1 << endl; 
                    cout << "Veuillez ressaisir : " << endl;
                    cout << "Saisir l'indice de l'emplacement du premier polynome : ";
                    cin >> indice1;
                    cout << "Saisir l'indice de l'emplacement du second polynome : ";
                    cin >> indice2; 
                }
            }     

            Polynome res = *(memory[indice1]) * *(memory[indice2]);
                    
                    if(memory[indiceRes] != nullptr) //Ecraser si il y a des données existantes
                        delete memory[indiceRes];
                    memory[indiceRes] = new Polynome(res);
        }

        //=======INTEGRATION
        else if(choice == 6){
            cout << "===INTEGRATION=== "<<endl;
            cout << endl;
            int indice, indiceRes;
            cout << "Saisir l'indice de l'emplacement du polynome a integrer : ";
            cin >> indice;            
            cout << "Saisir l'indice de l'emplacement du resultat : " ;
            cin >> indiceRes;
            cout << endl;
            while (indice >= sizeMax || indice < 0 || indiceRes >= sizeMax || indiceRes < 0)
            {
                cout << "Indice hors limites,valeur des indices entre 0 et " << sizeMax-1 << endl; 
                cout << "Veuillez ressaisir : " << endl;
                cout << "Saisir l'indice de l'emplacement du polynome a integrer : ";
                cin >> indice;            
                cout << "Saisir l'indice de l'emplacement du resultat : " ;
                cin >> indiceRes;
                cout << endl;
            }
            while (memory[indice] == nullptr)
            {
                cout << "L'emplacement " << indice << " est vide, veuillez ressaisir." << endl;
                cout << "Saisir l'indice de l'emplacement du polynome a integrer : ";
                cin >> indice;
                while (indice >= sizeMax || indice < 0)
                {
                    cout << "Indice hors limites,valeur des indices entre 0 et " << sizeMax-1 << endl; 
                    cout << "Veuillez ressaisir : " << endl;
                    cout << "Saisir l'indice de l'emplacement du polynome a integrer : ";
                    cin >> indice;            
                }
            }
            Polynome res = (memory[indice])->integrer();
                if(memory[indiceRes] != nullptr)
                    delete memory[indiceRes];
                memory[indiceRes] = new Polynome(res);
        }

        //=======EVALUATION P(x)
        else if(choice == 7){
            cout << "===EVALUATION P(x)=== "<<endl;
            cout << endl;
            int indice;
            double x;
            cout << "Saisir l'indice de l'emplacement du polynome a evaluer : ";
            cin >> indice;            
            cout << "Saisir la valeur de x : " ;
            cin >> x;
            cout << endl;

            while(indice >= sizeMax || indice < 0){
                cout << "Indice hors limites,valeur des indices entre 0 et " << sizeMax-1 << endl; 
                cout << "Veuillez ressaisir." << endl;
                cout << "Saisir l'indice de l'emplacement du polynome a evaluer : ";
                cin >> indice;            
                cout << "Saisir la valeur de x : " ;
                cin >> x;
                cout << endl;
            }

            while (memory[indice] == nullptr)
            {
                cout << "L'emplacement " << indice << " est vide, veuillez ressaisir." << endl;
                cout << "Saisir l'indice de l'emplacement du polynome a evaluer : ";
                cin >> indice;            
                cout << "Saisir la valeur de x : " ;
                cin >> x;
                cout << endl;
            }
            double res = (memory[indice])->operator()(x);            
            cout << "P(" << x << ") = " << res << endl;        
        }
    }
            
    for(int i = 0; i<sizeMax; i++)
        if(memory[i] != nullptr)
            delete memory[i];
    return 0;
}