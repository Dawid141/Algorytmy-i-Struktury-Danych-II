#ifndef GRAFY___LAB5_DIJKSTRA_DIJKSTRA_H
#define GRAFY___LAB5_DIJKSTRA_DIJKSTRA_H
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

class MyHeap
{
private:
    //reuse poprzedniego kodu z kolejki priorytetowej do implementacji heapa
    vector<pair<int, int>> heap;

    void bubble_up (int index) {
        if(index == 0) {
            return;
        }

        int parent = (index - 1) / 2;

        if(heap[index] < heap[parent]) { //operacja floor z index - 1 daje nam parenta
            swap(heap[index], heap[parent]);
            bubble_up(parent);
        }
    }

    void bubble_down (int index) {
        int right = (2 * index) + 1; //prawe dziecko
        int left = (2 * index) + 2; //lewe dziecko
        int smaller_val = index; //zmienna pomocnicza do wyznaczenia najwiekszego z dzieci
        bool t = false;

        if(left < heap.size() && heap[left] < heap[smaller_val]) {
            smaller_val = left;
            t = true;
        }

        if (right < heap.size() && heap[right] < heap[smaller_val]) {
            smaller_val = right;
            t = true;
        }

        /*if (left < heap.size() && right < heap.size() && heap[left] == heap[right]) {
            largest = left; //jesli wartosc dwoch dzieci jest taka sama, wybieramy lewe
            t = true;
        }*/

        if(t) {
            swap(heap[index], heap[smaller_val]);
            bubble_down(smaller_val);
        }

    }

public:

    void insert(int key, int val) { //operacja dodawania klucza razem z wartoscia do kopca
        heap.push_back({key, val});
        bubble_up(heap.size() - 1);
    }

    pair<int, int> pop() { //zmodyfikowane poll, zwracamy pare o najmniejszym key i usuwamy ją z heapa
        pair<int, int> result = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        bubble_down(0);
        return result;
    }

    bool isEmpty() { //sprawdzanie czy != empty
        return heap.empty();
    }

};

#endif //GRAFY___LAB5_DIJKSTRA_DIJKSTRA_H
