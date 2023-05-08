#include <iostream>
#include <iomanip>
#include "agm.h"
#include "aresta.h"

XAgm::XAgm (XGrafo* grafo, int tamanho) : m_grafo(grafo), m_tamanho(tamanho) {
    for (int i = 0; i <= m_tamanho; i++) {
        m_verificado.push_back(false);
        m_chave.push_back(-1);
        m_predecessor.push_back(-1);
    }
    this->geraAgm();
}

void XAgm::geraAgm() {
    m_chave[0] = 0; //inicia o ponto zero como a origem
    m_predecessor[0] = 0;
    Aresta* aux = m_grafo->primeiroListaAdj(0); //pega o primeiro vertice
    int chaveMenor = aux->getPeso(); 
    int sucessorMenor = aux->getV2();
    while (aux != NULL) {
        if ((!m_verificado[aux->getV2()]) && ( ( aux->getPeso() < m_chave[aux->getV2()]) || (m_chave[aux->getV2()] < 0) ) ) { //atualiza no vetor de chave e antecessores as arestas com peso menor
            m_chave[aux->getV2()] = aux->getPeso();
            m_predecessor[aux->getV2()] = 0;
            std::cout << "atualiza 0 para " << aux->getV2() << "  com valor valor " << aux->getPeso() << std::endl;
            if (aux->getPeso() < chaveMenor) {
                chaveMenor = aux->getPeso();
                sucessorMenor = aux->getV2();
            }
        }
        aux = m_grafo->proxAdj(0); // passa para o proximo adjacente
    }
    m_verificado[0] = true;
    this->geraAgmInterno(sucessorMenor); //primeiro a raiz avança para o menor vetor antes de ir para o resto
    aux = m_grafo->primeiroListaAdj(0); //pega o primeiro vertice de novo
    while (aux != NULL) { //percorre a lista de adjacencia de novo para avançar para proximos galhos
        std::cout << "Avança de 0 para " << aux->getV2() << " com a chave" << aux->getPeso() << std::endl;
        this->geraAgmInterno(aux->getV2()); //apenas no caso da raiz, ela avança para todos os galhos
        aux = m_grafo->proxAdj(0);
    }
}

void XAgm::geraAgmInterno(int raiz) {
    Aresta* aux;

    aux = m_grafo->primeiroListaAdj(raiz); //pega o primeiro vertice
    int chaveMenor = 0;
    int sucessorMenor = 0;
    while (aux != NULL) { //permanece no loop ate terminar a lista de adjacencia
        if ((!m_verificado[aux->getV2()]) && ( (aux->getPeso() < m_chave[aux->getV2()]) || (m_chave[aux->getV2()] < 0) ) ) { //atualiza no vetor de chave e antecessores as arestas com peso menor
            std::cout << "atualiza " << raiz << " para " << aux->getV2() << " com chave " << aux->getPeso() << std::endl;
            m_chave[aux->getV2()] = aux->getPeso();
            m_predecessor[aux->getV2()] = raiz;
            if ( (!m_verificado[aux->getV2()]) &&  ( (aux->getPeso() < chaveMenor) || (chaveMenor == 0) ) ) { //dentre os vertices do ponto, procura-se o menor de todos
                chaveMenor = aux->getPeso();
                sucessorMenor = aux->getV2();
            }
        }
        aux = m_grafo->proxAdj(raiz); // passa para o proximo adjacente
    } //depois de atualizar os vetores, avança recursivamente para o ponto com vetor de menor peso
    m_verificado[raiz] = true;
    if (!m_verificado[sucessorMenor] && sucessorMenor >= 0) { //avança apenas para o galho com menor vetor, ate que encontre um galho já verificado, que então para a recursividade
        std::cout << "avança de " << raiz << " para " << sucessorMenor << " valor " << chaveMenor << std::endl;
        this->geraAgmInterno(sucessorMenor);
    } 
}

void XAgm::imprime() {
    std::cout << "           ";
    for (int i = 0; i <= m_tamanho; i++) {
        std::cout << " " << std::setw(2) << i;
    }
    std::cout << std::endl;
    std::cout << "chave:     ";
    for (int i = 0; i <= m_tamanho; i++) {
        std::cout <<  " " << std::setw(2) << m_chave[i];
    }
    std::cout << std::endl;
    std::cout << "Antecessor:";
    for (int i = 0; i <= m_tamanho; i++) {
        std::cout <<  " " << std::setw(2) << m_predecessor[i];
    }
    std::cout << std::endl;
    int somaPesos = 0;
    for (int i = 0; i <= m_tamanho; i++) {
        somaPesos = somaPesos + m_chave[i];
    }
    std::cout <<  "Peso total: "  << somaPesos << std::endl;
}
