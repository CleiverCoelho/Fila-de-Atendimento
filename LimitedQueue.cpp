#include "LimitedQueue.hpp"

LimitedQueue::LimitedQueue(int max_size){
    if(max_size <= 0){
        throw InvalidSizeException();
    }
    _maxSize = max_size;
}

LimitedQueue::LimitedQueue(){}

void LimitedQueue::push_back(int elemento){
    int tamanhoLista = _queueList.size();
    if(tamanhoLista == _maxSize){
        throw QueueFullException();
    }
    _queueList.push_back(elemento);
    return;
}

void LimitedQueue::pop_front(){
    if(_queueList.size() == 0){
        throw QueueEmptyException();
    }
    _queueList.pop_front();
    return;
}

int LimitedQueue::front(){
    if(_queueList.size() == 0){
        throw QueueEmptyException();
    }
    return _queueList.front();
}

int LimitedQueue::back(){
    if(_queueList.size() == 0){
        throw QueueEmptyException();
    }
    return _queueList.back();
}

int LimitedQueue::find(int elemento){
    int i = 0;
    int index = -1;

    if(_queueList.size() == 0){
        throw QueueEmptyException();
    }else{
        for(auto &numero : _queueList){
            if(numero == elemento){
                return index = i;
            }
            i++;
        }
        if(index == -1)
            throw ItemNotFoundException();
        return 0;
    }
}

void LimitedQueue::print(){
    if(_queueList.size() == 0){
        throw QueueEmptyException();
    }else{
        for(auto &numero : _queueList) {
            std::cout << numero << std::endl;
        }
    }
    return;
}

int LimitedQueue::get_max_size(){return _maxSize;}