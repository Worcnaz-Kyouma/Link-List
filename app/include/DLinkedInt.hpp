#ifndef SD_DLINKEDINT_H
#define SD_DLINKEDINT_H

enum class Posicao {
    BEGIN,
    FINAL
};

class DLinkedInt {
private:
    struct DLIElement{
        int value;

        DLIElement* lElement = nullptr;
        DLIElement* rElement = nullptr;

        DLIElement(int value): value(value){}
    };
    
    DLIElement* startElement = nullptr;
    DLIElement* finalElement = nullptr;
public:
    void insereLista(int valor, Posicao posicao = Posicao::FINAL);
    void removeValor(int valor);
    void imprime();
};

#endif