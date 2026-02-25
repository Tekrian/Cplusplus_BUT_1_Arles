w#include "ListOfStrings.hpp"
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

void ListOfStrings::push_front(StringNode* node){
    if(first == nullptr)    // Si la liste était vide, le nouveau noeud devient le premier ainsi que le dernier noeud
        last = first = node;
    else{
        node->next = first; // Le nouveau noeud pointe vers l'ancien premier noeud
        first = node;   // Le nouveau noeud devient le premier noeud de la liste
    }
    count++; //mise à jour du nombre de Maillon
}

void LisOfStrings::push_front(const std::string& str){
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

void ListOfstrings::push_back(const std::string& str){
    push_back(new StringNode(str));
}

const std::string& ListOfStrings::front() const {
    if(first == nullptr)
        throw std::out_of_range("Impossible de consulter front car la liste est vide.");
    else 
        return first->value;
}

const std::string& LisOfStrings::back()const {
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
        while(previewLast->next != last)    // L'avant dernier élément a son next qui pointe last
            previewLast = previewLast-> next;
        previewLast->next = mullptr;    // Car se sera le dernier élt de la liste
        last = previewLast;
        delete node;
         
        
    }
}












// void ListOfStrings::push_front(StringNode* node)
// {
//     node->next = first; // Le nouveau noeud pointe vers l'ancien premier noeud 
//     first = node;   // Le nouveau noeud devient le premier noeud de la liste
//     if(last == nullptr) // Si la liste était vide, le nouveau noeud devient également le dernier noeud
//         last = node;
//     count++;
// }

// void ListOfStrings::push_front(const std::string& str)
// {
//     StringNode* node = new StringNode(str); // Créer un nouveau noeud avec la chaîne str fournie  
//     push_front(node); // Ajouter le nouveau noeud au début de la liste
// }

// void ListOfStrings::push_back(StringNode* node)
// {
//     if(last == nullptr) // Si la liste est vide, le nouveau noeud devient à la fois le premier et le dernier noeud
//         first = last = node;
//     else{           
//         last->next = node;  // Sinon, le dernier noeud actuel pointe vers le nouveau noeud 
//         last = node;        // et le nouveau noeud devient le dernier noeud de la liste
//     }
//     node->next = nullptr; // Le nouveau noeud devient le dernier noeud de la liste, il ne pointe vers aucun autre noeud
//     count++;
// }

// void ListOfStrings::push_back(const std::string& str)
// {
//     StringNode* node = new StringNode(str);
//     push_back(node);
// }

// const std::string& ListOfStrings::front() const
// {
//     if(count == 0 /*first == nullptr*/)
//         throw std::out_of_range("Liste vide");
//     return first->value;
// }

// const std::string& ListOfStrings::back() const
// {
//     if(count == 0 /*last == nullptr*/)
//         throw std::out_of_range("Liste vide");
//     return last->value;
// }

// void ListOfStrings::pop_front()
// {
//     if(first == nullptr)
//         throw std::out_of_range("Liste vide");
//     StringNode* temp = first;   //Sauvegarder l'ancien premier élément
//     first = first->next;       // Le premier elt devient le suivant de l'ancien premier elt
//     delete temp;               //On supprime l'ancien premier élément

//     // Cas ou c'était un elt dans la liste, donc 0 après suppression du first
//     if(count == 0)
//         first = last = nullptr;
// }

// void ListOfStrings::pop_back()
// {
//     if(last == nullptr)
//         throw std::out_of_range("Liste vide");
//     if(first == last){ //Si la liste contient qu'un elt
//         delete first;
//     first = last = nullptr;
//     }else{
//         StringNode* current = first;
//         while(current->next != last)
//             current = current->next;
//         delete last;
//         last = current;
//         last->next = nullptr; 

//     }    
// }