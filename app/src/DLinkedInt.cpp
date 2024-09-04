#include "DLinkedInt.hpp"
#include <iostream>

void DLinkedInt::insertList(int value, Position position) {
    DLIElement* element = new DLIElement(value);

    if(this->startElement == nullptr) {
        this->startElement = this->finalElement = element;
    } else if(position == Position::START) {
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
void DLinkedInt::removeValue(int value, bool foundElement) {
    if(this->startElement == nullptr) {
        std::cout << "Empty list" << std::endl;
        return;
    }

    if(this->startElement->value == value and this->startElement == this->finalElement) {
        this->startElement = this->finalElement = nullptr;
        free(this->startElement);
        return;
    }

    if(this->startElement->value == value) {
        DLIElement *nextElement = this->startElement->rElement;

        nextElement->lElement = nullptr;
        free(this->startElement);
        this->startElement = nextElement;

        this->removeValue(value, true);
    }else if(this->finalElement->value == value) {
        DLIElement *penultElement = this->finalElement->lElement;

        penultElement->rElement = nullptr;
        free(this->finalElement);
        this->finalElement = penultElement;
        
        this->removeValue(value, true);
    }
    else {
        for(DLIElement *element = this->startElement; element != nullptr; element = element->rElement) {
            if(element->value == value) {
                element->rElement->lElement = element->lElement;
                element->lElement->rElement = element->rElement;
                free(element);
                foundElement = true;
            }

            if(element->rElement == nullptr) {
                if (!foundElement) std::cout << "Element not found" << std::endl;
                return;
            }
        }
    }

}

void DLinkedInt::printList() {
    if(this->startElement == nullptr) {
        std::cout << "Empty list" << std::endl;
        return;
    }

    std::cout << "List elements" << std::endl;
    unsigned int index = 0;
    for(DLIElement* element = this->startElement; element != nullptr; element = element->rElement) {
        std::cout << "Index " << (index+1) << ": " << element->value << std::endl;
        index++;
    }
}