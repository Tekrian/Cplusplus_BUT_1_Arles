#include "Polynome.hpp"
#include <iostream>

using namespace std;

int main()
{
    unsigned int sizeMax = 10;
    Polynome *memory[sizeMax];
    for (size_t i = 0; i < sizeMax; i++)
        memory[i] = nullptr;

    // double coeffs2[3] = {-4,5,2};
    // memory[2] = new Polynome(2, coeffs2);
    // Etat des emplacements et affichage==========================================
    int choice = -1;
    cout << "===PROGRAMME DES POLYNOMES===" << endl;
    cout << "------Etat des emplacements------" << endl;    
    while (choice != 0)
    {   // BOUCLE D'AFFICHAGE=======================================================
        for (size_t i = 0; i < sizeMax; i++)
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
        cout << "5. Affichage" << endl; /*
        cout << "6. Affectation" << endl;
        cout << "7. Comparaison" << endl;
        cout << "8. ..." << endl;       */
        cout << "0. Quitter" << endl;
        cout << endl;
        cout << "Votre choix : ";
        cin >> choice;
        cout << endl;
       
        if (choice == 1)
        {
            cout << "===Saisie du polynome=== "<<endl;
            cout << endl;
            unsigned int indice, degree;
            cout << "Saisir l'indice de l'emplacement : ";
            cin >> indice;
            cout << "Saisir le degre du polynome : ";
            cin >> degree;
            double *coeff = new double[degree + 1];
            cout << "Saisie des coefficients du polynome : ";
            cout << endl;
            for (size_t i = 0; i <= degree; i++)
            {
                cout << "Coefficient de x^" << i << " : ";
                cin >> coeff[i];
            }
            do
            {
                if (indice >= sizeMax || indice < 0)
                {
                    cout << "Indice hors limites, veuillez ressaisir : " << endl;
                    cin >> indice;
                }
                else
                {
                    if (memory[indice] != nullptr)      //Ecraser si il y a des données existantes
                        delete memory[indice];
                    
                    (memory[indice]) = new Polynome(degree, coeff);
                }
            } while (indice >= sizeMax || indice < 0);

            delete[] coeff;
        }

        else if (choice == 2)
        {
            cout << "===ADDITION=== "<<endl;
            cout << endl;
            unsigned int indice1, indice2, indiceRes;
            cout << "Saisir l'indice du premier polynome : ";
            cin >> indice1;
            cout << "Saisir l'indice du second polynome : ";
            cin >> indice2;
            cout << "Saisir l'indice de l'emplacement du resultat : " << endl;
            cin >> indiceRes;

            if(memory[indice1] != nullptr && memory[indice2] != nullptr && indiceRes < sizeMax){           
                Polynome somme = *(memory[indice1]) + *(memory[indice2]);
                //Ecraser si il y a des données existantes
                if(memory[indiceRes] != nullptr)
                    delete memory[indiceRes];
                memory[indiceRes] = new Polynome(somme);
            }
        }
        
        else if( choice == 3) {
            cout << "===SOUSTRACTION=== "<<endl;
            cout << endl;
            unsigned int indice1, indice2, indiceRes;
            cout << "Saisir l'indice du premier polynome : ";
            cin >> indice1;
            cout << "Saisir l'indice du second polynome : ";
            cin >> indice2;
            cout << "Saisir l'indice de l'emplacement du resultat : ";
            cin >> indiceRes;
            cout << endl;

            if(memory[indice1] != nullptr && memory[indice2] != nullptr && indiceRes < sizeMax){           
                Polynome res = *(memory[indice1]) - *(memory[indice2]);
                if(memory[indiceRes] != nullptr)
                    delete memory[indiceRes];
                memory[indiceRes] = new Polynome(res);
            }
        }

        else if(choice == 4){
            unsigned int indice, indiceRes;
            cout << "Saisir l'indice de l'emplacement du polynome a deriver (entre 0 et 9) :";
            cin >> indice;            
            cout << "Saisir l'indice de l'emplacement du resultat : " ;
            cin >> indiceRes;
            cout << endl;

            if(memory[indice] != nullptr){
                (memory[indiceRes]) =  new Polynome( (memory[indice])->deriver() );
            }
        }

        // Reste à faire choix 5 ... 
    } 
    for(size_t i = 0; i<sizeMax; i++)
        if(memory[i] != nullptr)
            delete memory[i];
    return 0;
}