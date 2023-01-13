// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_excecoes.hpp"
#include "LimitedQueue.hpp"
#include "Exceptions.hpp"
#include <list>
#include <iostream>

int main() {

    LimitedQueue fila = LimitedQueue(1);
    char command;
    while (std::cin >> command) {

        switch (command) {
            case 'i': { // inicializar a fila com um certo tamanho maximo
                int max_size;
                cin >> max_size;
                try{
                    fila = LimitedQueue(max_size);
                }catch(InvalidSizeException& e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }        
            case 'p': { // insere um inetiro no final da fila
                int elemento;
                cin >> elemento;
                try{
                    fila.push_back(elemento);
                }catch(QueueFullException& e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 'o': { // remove o primeiro elemento da fila
                try{
                    fila.pop_front();
                }catch(QueueEmptyException& e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 'f': { // imprime o primeiro elemento da fila
                try{
                    int primeiro = fila.front();
                    std::cout << primeiro << std::endl;
                }catch(QueueEmptyException& e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 'l': { // imprime o ultimo elemento da fila
                try{
                    int ultimo = fila.back();
                    std::cout << ultimo << std::endl;
                }catch(QueueEmptyException& e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 'm': { // comando para imprimir toda a fila
                try{
                    fila.print();
                }catch(QueueEmptyException& e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 'd': { // procura um elemento na fila
                int elemento;
                int posicaoElemento;
                cin >> elemento;
                try{
                    posicaoElemento = fila.find(elemento);
                    std::cout << posicaoElemento << std::endl;
                }catch(QueueEmptyException& e){
                    std::cout << e.what() << std::endl;
                    // throw;
                }catch(ItemNotFoundException& e){
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 'b': { // avalia o codigo (nao só os resultados)
                try{
                    avaliacao_basica();    
                }catch(InvalidSizeException& e){
                    std::cout << e.what() << std::endl;
                }catch(QueueEmptyException& e){
                    std::cout << e.what() << std::endl;
                }catch(QueueFullException& e){
                    std::cout << e.what() << std::endl;
                }catch(ItemNotFoundException& e){
                    std::cout << e.what() << std::endl;
                }
            }
        }
    }

    return 0;
}