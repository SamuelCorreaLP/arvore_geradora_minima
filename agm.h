#ifndef AGM_H
#define AGM_H

#include <vector>
#include "grafo.h"

class XAgm {
    public:
        XAgm (XGrafo* grafo, int tamanho);
        void imprime();
    private:
        void geraAgm();
        void geraAgmInterno(int raiz);
        XGrafo* m_grafo;
        int m_tamanho;
        std::vector<bool> m_verificado;
        std::vector<int> m_chave;
        std::vector<int> m_predecessor;
};

#endif