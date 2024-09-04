#include "DLinkedInt.hpp"

int main() {
    DLinkedInt list;
    list.insertList(2);
    list.insertList(3);
    list.insertList(1, Position::START);

    list.removeValue(3);
    list.removeValue(1);
    list.removeValue(2);
    list.printList();

    return 0;
}