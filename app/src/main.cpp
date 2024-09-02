#include "DLinkedInt.hpp"

int main() {
    DLinkedInt list;
    list.insereLista(2);
    list.insereLista(3);
    list.insereLista(1, Posicao::BEGIN);

    list.imprime();

    return 0;
}