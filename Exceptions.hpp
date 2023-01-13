#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

// Fila de números inteiros de tamanho limitado
class InvalidSizeException {

    public:
        std::string _name = "InvalidaSizeException";
        virtual const char* what() const throw(){
            return "Excecao: InvalidSizeException" ;
        } 
};

class QueueFullException {
    public:
        std::string _name = "QueueFullException";
        virtual const char* what() const throw(){
            return "Excecao: QueueFullException";
        }
};

class QueueEmptyException {
    public: 
        std::string _name = "QueueEmptyException";
        virtual const char* what() const throw(){
            return "Excecao: QueueEmptyException";
        }
};

class ItemNotFoundException {
    public:
        std::string _name = "ItemNotFoundException";
        virtual const char* what() const throw(){
            return "Excecao: ItemNotFoundException";
        }
};

#endif