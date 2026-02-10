#include "Polynome.hpp"
#include <iostream>

using namespace std;

int main()
{
    unsigned int sizeMax = 10;
    Polynome *memory[sizeMax];
    for (size_t i = 0; i < sizeMax; i++)
        memory[i] = nullptr;

    // Etat des emplacements et affichage
    int choice = -1;
    cout << "===PROGRAMME DES POLYNOMES===" << endl;
    cout << "------Etat des emplacements------" << endl;
    while (choice != 0)
    {
        for (size_t i = 0; i < sizeMax; i++)
        {
            cout << "Emplacement[" << i << "] : " ;
            if (memory[i] == nullptr)
                cout << "vide" << endl;
            else
                cout << *memory << endl;
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
        cout << "Votre choix : " << endl;
        cin >> choice;

        if (choice == 1)
        {
            unsigned int indice, degree;
            cout << "Saisir l'indice de l'emplacement : " << endl;
            cin >> indice;
            cout << "Saisir le degre du polynome : " << endl;
            cin >> degree;
            double *coeff = new double[degree + 1];
            cout << "Saisie des coefficients du polynome : " << endl;
            for (size_t i = 0; i <= degree; i++)
            {
                cout << "Coefficient de x^" << i+1 << " : " << endl;
                cin >> coeff[i];
            }
            do
            {
                if (indice >= sizeMax)
                {
                    cout << "Indice hors limites, veuillez ressaisir : " << endl;
                    cin >> indice;
                }
                else
                {
                    if (memory[indice] != nullptr)      //Ecraser si il y a des données existantes
                        delete memory[indice];
                    memory[indice] = new Polynome(degree, coeff);
                }
            } while (indice >= sizeMax);

            delete[] coeff;
        }

        else if (choice == 2)
        {
            unsigned int indice1, indice2, indiceRes;
            cout << "Saisir l'indice de polynome 1 : " << endl;
            cin >> indice1;
            cout << "Saisir l'indice de polynome 2 : " << endl;
            cin >> indice2;
            cout << "Saisir l'indice de l'emplacement de resultat : " << endl;
            cin >> indiceRes;

            if(memory[indice1] != nullptr && memory[indice2] != nullptr && indiceRes < sizeMax){           
                Polynome somme = *memory[indice1] + *memory[indice2];
                //Ecraser si il y a des données existantes
                if(memory[indiceRes] != nullptr)
                    delete memory[indiceRes];
                memory[indiceRes] = new Polynome(somme);
            }
        } 
        // Reste à faire choix 3 ... 
    } 
    for(size_t i = 0; i<sizeMax; i++)
        if(memory[i] != nullptr)
            delete memory[i];  

    return 0;
}