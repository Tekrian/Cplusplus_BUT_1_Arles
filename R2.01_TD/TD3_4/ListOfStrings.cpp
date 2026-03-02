#include "ListOfStrings.hpp"
#include <stdexcept>

/*
ListOfStrings::StringNode::StringNode(const std::string& _value, const StringNode* _next)
    :   value(_value), next(_next)
{

}// Constructeur de la classe interne StringNode

ListOfStrings::StringNode::StringNode(const StringNode& other)
    : value(other.value), next(other.next)
{

}//Constructeur par copie de la classe StringNOde
*/

ListOfStrings::ListOfStrings()
    : count(0), first(nullptr), last(nullptr)
{ 
}// Constructeur par défaut de la classe ListOfStrings

ListOfStrings::ListOfStrings(const ListOfStrings& src)
    : count(src.count), first(src.first), last(src.last)
{

}//constructeur de copie de la classe ListOfStrings

void ListOfStrings::push_front(StringNode* node){
    if(first == nullptr)    // Si la liste était vide, le nouveau noeud devient le premier ainsi que le dernier noeud
        last = first = node;
    else{
        node->next = first; // Le nouveau noeud pointe vers l'ancien premier noeud
        first = node;   // Le nouveau noeud devient le premier noeud de la liste
    }
    count++; //mise à jour du nombre de Maillon
}

void ListOfStrings::push_front(const std::string& str){
    push_front(new StringNode(str));    // Créer un nouveau noeud avec la chaîne str fournie et l'Ajouter au début de la liste
}

void ListOfStrings::push_back(StringNode* node){
    if(first == nullptr)    // Si la liste est vide, le nouveau noeud devient à la fois le premier et le dernier noeud
        first = last = node;
    else{
        last->next = node;  // Sinon, le dernier noeud actuel pointe vers le nouveau noeud
        last = node;        // et le nouveau noeud devient le dernier noeud de la liste
    }
    count++;
}

void ListOfStrings::push_back(const std::string& str){
    push_back(new StringNode(str));
}

const std::string& ListOfStrings::front() const {
    if(first == nullptr)
        throw std::out_of_range("Impossible de consulter front car la liste est vide.");
    else 
        return first->value;
}

const std::string& ListOfStrings::back()const {
    if(first == nullptr)
        throw std::out_of_range("Impossible de consulter back car la liste est vide.");
    else 
        return last->value;
}

void ListOfStrings::pop_front(){
    if (first == nullptr)
        throw std::out_of_range("Impossible de consulter pop_front car la liste est vide");
    else{
        StringNode* node = first;
        first = node->next;
        delete node;
        if(first == last)
            last = first;   // = nullptr
    }
    count--;
}

void ListOfStrings::pop_back(){
    if (first == nullptr)
        throw std::out_of_range("Impossible de consulter pop_back car la liste est vide");
    else{
        StringNode* node = last;
        // for(StringNode* temp = first; temp->next != last; temp = temp-> next){}
        StringNode* previewLast = first;
        if(first == last){
            first = last = nullptr;
            delete node;
        } else{
            while(previewLast->next != last)    // L'avant dernier élément a son next qui pointe last
                previewLast = previewLast-> next;
            previewLast->next = nullptr;    // Car se sera le dernier élt de la liste
            last = previewLast;
            delete node;
        }    
    }
    count--;
}// pop_back()

void ListOfStrings::splice(const ListOfStrings& other){
    //Retire tous les élts de other et l'ajoute sur l'instance courante
    
    if(other.first == nullptr)  // Si le paramètre est une liste vide, on ne fait rien
        return;
    else if(first == nullptr){   // Si l'instance courante est une liste vide, other devient notre liste
        first = other.first;
        last = other.last;
    } else {
        last->next = other.first;
        last = other.last;
    }
    count += other.count;   
}// splice()

void ListOfStrings::reverse(){
    if(first == nullptr)  // Si la liste est vide, on ne fait rien
        return;
    else if(first == last)   // Si la liste ne contient qu'un seul élément, on ne fait rien
        return;
    else{
        StringNode* previous = nullptr;
        StringNode* current = first;
        StringNode* next = nullptr;

        while(current != nullptr){
            next = current->next;   // Stocker le pointeur vers le noeud suivant
            current->next = previous;  // Inverser le pointeur du noeud courant pour qu'il pointe vers le noeud précédent
            previous = current;     // Avancer le pointeur précédent pour qu'il pointe vers le noeud courant
            current = next;        // Avancer le pointeur courant pour qu'il pointe vers le noeud suivant
        }
        // Après la boucle, previous pointe vers l'ancien dernier noeud qui devient le nouveau premier noeud de la liste
        last = first;  // L'ancien premier noeud devient le nouveau dernier noeud de la liste
        first = previous;    // Le nouveau premier noeud de la liste est celui pointé par previous
    }

    if(first == nullptr || first == last)   // Si la liste est vide ou contient qu'un seul élément, on ne fait rien
        return;
    else{
        StringNode* current = first;
        StringNode* previous = nullptr;
        while(current != nullptr){

            previous = current;
            current->next = nullptr;

            current = current->next;
        }
        last = 
        first = previous;
    }   
}
