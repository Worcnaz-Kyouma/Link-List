#include "DLinkedInt.hpp"
#include <iostream>

void DLinkedInt::insereLista(int valor, Posicao posicao) {
    DLIElement* element = new DLIElement(valor);

    if(this->startElement == nullptr) {
        this->startElement = this->finalElement = element;
    } else if(posicao == Posicao::BEGIN) {
        this->startElement->lElement = element;
        element->rElement = this->startElement;

        this->startElement = element;
    } else {
        this->finalElement->rElement = element;
        element->lElement = this->finalElement;

        this->finalElement = element;
    }
}

// Manda a boa aqui Wenderu, como se fosse um metodo comum trabalhando com c normal. Se tiver dois elementos de mesmo valor, remove ambos
void DLinkedInt::removeValor(int valor) {
    
}

void DLinkedInt::imprime() {
    if(this->startElement == nullptr && this->finalElement == nullptr) {
        std::cout << "Empty list" << std::endl;
    }

    std::cout << "List elements" << std::endl;
    unsigned int index = 0;
    for(DLIElement* element = this->startElement; element != nullptr; element = element->rElement) {
        std::cout << "Posicao " << (index+1) << ": " << element->value << std::endl;
        index++;
    }
}