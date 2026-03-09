#ifndef LIST_OF_STRINGS_HPP
#define LIST_OF_STRINGS_HPP

#include <string>
#include <iostream>

class ListOfStrings{

    private:
        //Classe interne privée représentant un maillon
        class StringNode {
            public :
                std::string value;
                StringNode* next;

                StringNode(const std::string& _value = "", StringNode* _next = nullptr);    // Constructeur
                StringNode(const StringNode&);  //  Constructeur de copie
                ~StringNode();  //Destructeur
        };//StringNode

        size_t count;      // Nombre de maillons dans la liste
        StringNode* first; // Pointeur vers le premier maillon de la liste
        StringNode* last;  // Pointeur vers le dernier maillon de la liste

        // Méthodes privées
        void push_front(StringNode*);
        void push_back(StringNode*);
        void insert_sorted(StringNode*);
                   
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
        void splice(ListOfStrings&);
        void reverse();
        void insert_sorted(const std::string&);
        void sort();
        inline size_t size() const {return count;};
        void clear();
        friend std::ostream& operator<<(std::ostream&, const ListOfStrings&);

};

#endif // LIST_OF_STRINGS_HPP