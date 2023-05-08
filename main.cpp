/*
AED2 Prof. Thiago de Souza Rodrigues
Aluno: Samuel Correa Lucas Pereira
Implementação da classe AGM
*/

#include <iostream>
#include "grafo.h"
#include "agm.h"

int main (int argc, char* argv[]) {

    //primeiro grafo
    std::cout <<"Primeiro grafo" <<std::endl;
    XGrafo* grafo = new XGrafo(8);
    grafo->insereAresta(0, 1, 5); grafo->insereAresta(0, 4, 5); grafo->insereAresta(0, 6, 10);
    grafo->insereAresta(1, 0, 5); grafo->insereAresta(1, 5, 5); grafo->insereAresta(1, 7, 5); grafo->insereAresta(1, 8, 10);
    grafo->insereAresta(2, 3, 5); grafo->insereAresta(2, 4, 10); grafo->insereAresta(2, 6, 5);
    grafo->insereAresta(3, 0, 10); grafo->insereAresta(3, 2, 5); grafo->insereAresta(3, 4, 5); grafo->insereAresta(3, 6, 10);
    grafo->insereAresta(4, 0, 5); grafo->insereAresta(4, 2, 10); grafo->insereAresta(4, 3, 5); grafo->insereAresta(4, 8, 10);
    grafo->insereAresta(5, 1, 5); grafo->insereAresta(5, 6, 15);
    grafo->insereAresta(6, 0, 10); grafo->insereAresta(6, 2, 5); grafo->insereAresta(6, 3, 10);
    grafo->insereAresta(7, 0, 10); grafo->insereAresta(7, 1, 5); grafo->insereAresta(7, 8, 20);
    grafo->insereAresta(8, 1, 10); grafo->insereAresta(8, 4, 10); grafo->insereAresta(8, 7, 20);

    grafo->imprime();

    XAgm agm(grafo, 8);
    std::cout <<std::endl;
    agm.imprime();

    std::cout <<std::endl;
    std::cout <<std::endl;

    //segundo grafo
    std::cout <<"Segundo grafo" <<std::endl;
    XGrafo* grafo2 = new XGrafo(7);
    grafo2->insereAresta(0,1,8); grafo2->insereAresta(0,2,2); grafo2->insereAresta(0,6,9);
    grafo2->insereAresta(1,0,8); grafo2->insereAresta(1,2,3); grafo2->insereAresta(1,3,2); grafo2->insereAresta(1,4,7); grafo2->insereAresta(1,5,5); grafo2->insereAresta(1,7,6);
    grafo2->insereAresta(2,0,2); grafo2->insereAresta(2,1,3); grafo2->insereAresta(2,3,9); grafo2->insereAresta(2,6,6);
    grafo2->insereAresta(3,1,2); grafo2->insereAresta(3,2,9); grafo2->insereAresta(3,4,6); grafo2->insereAresta(3,6,2);
    grafo2->insereAresta(4,1,7); grafo2->insereAresta(4,3,6); grafo2->insereAresta(4,5,5); grafo2->insereAresta(4,6,4);
    grafo2->insereAresta(5,1,5); grafo2->insereAresta(5,4,5); grafo2->insereAresta(5,6,6); grafo2->insereAresta(5,7,4);
    grafo2->insereAresta(6,0,9); grafo2->insereAresta(6,2,6); grafo2->insereAresta(6,3,2); grafo2->insereAresta(6,4,4); grafo2->insereAresta(6,5,6); grafo2->insereAresta(6,7,3);
    grafo2->insereAresta(7,1,6); grafo2->insereAresta(7,5,4); grafo2->insereAresta(7,6,3);

    grafo2->imprime();
    
    XAgm agm2(grafo2, 7);
    std::cout <<std::endl;
    agm2.imprime();
}
