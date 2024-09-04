#ifndef SD_DLINKEDINT_H
#define SD_DLINKEDINT_H

enum class Position {
    START,
    FINAL
};

class DLinkedInt {
private:
    struct DLIElement{
        int value;

        DLIElement* lElement = nullptr;
        DLIElement* rElement = nullptr;

        DLIElement(int value): value(value){
}
    };
    
    DLIElement* startElement = nullptr;
    DLIElement* finalElement = nullptr;
public:
    void insertList(int value, Position position = Position::FINAL);
    void removeValue(int value, bool foundElement = false);
    void printList();
};

#endif