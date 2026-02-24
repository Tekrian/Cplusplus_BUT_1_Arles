#ifndef LIST_OF_STRINGS_HPP
#define LIST_OF_STRINGS_HPP

#include <string>

class ListOfStrings{

    private:
        //Classe interne privée représentant un maillon
        class StringNode {
            public :
                std::string value;
                StringNode* next;

                StringNode(const std::string& _value, const StringNode* next = nullptr);    // Constructeur
                StringNode(const StringNode&);  //  Constructeur de copie
                ~StringNode();  //Destructeur
        };//StringNode

        StringNode* first; // Pointeur vers le premier maillon de la liste
        StringNode* last;  // Pointeur vers le dernier maillon de la liste
        size_t count;      // Nombre de maillons dans la liste

        // Méthodes privées
        void push_front(StringNode*);
        void push_back(StringNode*);

                   
    public :
        ListOfStrings(); // Constructeur par défaut de la classe ListOfStrings
        ListOfStrings(const ListOfStrings&);  // Constructeur de copie de la classe ListOfStrings
        ~ListOfStrings(); // Destructeur de la classe ListOfStrings   

        // Méthodes
        void push_front(const std::string&);
        void push_back(const std::string&);
        const std::string& front() const;
        const std::string& back() const;
        void pop_front();
        void pop_back();


};

#endif // LIST_OF_STRINGS_HPP