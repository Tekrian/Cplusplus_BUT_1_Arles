#include "ListOfStrings.hpp"
#include <stdexcept>


ListOfStrings::ListOfStrings()
    : first(nullptr), last(nullptr), count(0)
{ 
}// Constructeur par défaut de la classe ListOfStrings

void ListOfStrings::push_front(StringNode* node)
{
    node->next = first; // Le nouveau noeud pointe vers l'ancien premier noeud 
    first = node;   // Le nouveau noeud devient le premier noeud de la liste
    if(last == nullptr) // Si la liste était vide, le nouveau noeud devient également le dernier noeud
        last = node;
    count++;
}

void ListOfStrings::push_front(const std::string& str)
{
    StringNode* node = new StringNode(str); // Créer un nouveau noeud avec la chaîne str fournie  
    push_front(node); // Ajouter le nouveau noeud au début de la liste
}

void ListOfStrings::push_back(StringNode* node)
{
    if(last == nullptr) // Si la liste est vide, le nouveau noeud devient à la fois le premier et le dernier noeud
        first = last = node;
    else{           
        last->next = node;  // Sinon, le dernier noeud actuel pointe vers le nouveau noeud 
        last = node;        // et le nouveau noeud devient le dernier noeud de la liste
    }
    node->next = nullptr; // Le nouveau noeud devient le dernier noeud de la liste, il ne pointe vers aucun autre noeud
    count++;
}

void ListOfStrings::push_back(const std::string& str)
{
    StringNode* node = new StringNode(str);
    push_back(node);
}

const std::string& ListOfStrings::front() const
{
    if(count == 0 /*first == nullptr*/)
        throw std::out_of_range("Liste vide");
    return first->value;
}

const std::string& ListOfStrings::back() const
{
    if(count == 0 /*last == nullptr*/)
        throw std::out_of_range("Liste vide");
    return last->value;
}

void ListOfStrings::pop_front()
{
    if(first == nullptr)
        throw std::out_of_range("Liste vide");
    StringNode* temp = first;   //Sauvegarder l'ancien premier élément
    first = first->next;       // Le premier elt devient le suivant de l'ancien premier elt
    delete temp;               //On supprime l'ancien premier élément

    // Cas ou c'était un elt dans la liste, donc 0 après suppression du first
    if(count == 0)
        first = last = nullptr;
}

void ListOfStrings::pop_back()
{
    if(last == nullptr)
        throw std::out_of_range("Liste vide");
    if(first == last){ //Si la liste contient qu'un elt
        delete first;
    first = last = nullptr;
    }else{
        StringNode* current = first;
        while(current->next != last)
            current = current->next;
        delete last;
        last = current;
        last->next = nullptr; 

    }

    
}