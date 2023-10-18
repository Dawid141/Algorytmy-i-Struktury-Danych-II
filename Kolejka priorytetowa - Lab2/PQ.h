#ifndef KOLEJKA_PRIORYTETOWA___LAB2_PQ_H
#define KOLEJKA_PRIORYTETOWA___LAB2_PQ_H
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;


class KolejkaPriorytetowa
{
private:
    vector <int> heap;

    void bubble_up (int index) { //operacja polega na sprawdzaniu czy aktualna wartosc znajduje sie w odpowiednim miejscu (czy jest mniejsza od swojego rodzica) jesli nie
        if(index == 0) {         //to operacja polega na swapie rodzica z dzieckiem i ponownym wywolaniu funkcji tym razem dla rodzica
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

        if(left < heap.size() && heap[left] < heap[smaller_val]) { //sprawdza czy operacja nie wychodzi poza wielkosc kopca a nastepnie zamienia miejscami wartosc wieksza razem z lewym dzieckiem
            smaller_val = left;
            t = true;
        }

        if (right < heap.size() && heap[right] < heap[smaller_val]) { //to samo co wyzej tylko dla prawego dziecka
            smaller_val = right;
            t = true;
        }

        /*if (left < heap.size() && right < heap.size() && heap[left] == heap[right]) {
            largest = left; //jesli wartosc dwoch dzieci jest taka sama, wybieramy lewe
            t = true;
        }*/

        if(t) {
            swap(heap[index], heap[smaller_val]); //jesli t jest na true (jakas operacja zostala wykonana) to robimy swap oraz wywolujemy funkcje ponownie dla nowej mniejszej wartosci
            bubble_down(smaller_val);
        }

    }

public:

    void insert(int x) { //operacja dodawania, dodajemy na koniec heapa i robimy bubble up zeby ustawic w odpowiednim iejscu
        heap.push_back(x);
        bubble_up(heap.size() - 1);
    }

    int poll() { //zabieramy wartosc z korzenia
        if(heap.empty()) { //pusty heap zwraca blad
            throw out_of_range("Kolejka jest pusta");
        }

        int root = heap[0]; //nadajemy korzeniowi wartosc na poczatku heapa

        swap(heap[0], heap[heap.size() - 1]); //zamieniamy element pierwszy z ostatnim
        heap.pop_back(); //usuwamy element ostatni
        bubble_down(0); //przeprowadzamy bubble down dla elementu na poczatku

        return  root; //zwrocenie wartosci z korzenia
    }

    int peek() { //zwraca wartosc korzenia bez usuwania jej z kolejki
        if(heap.empty()) {
            throw out_of_range("Kolejka jest pusta");
        }

        return heap[0];
    }

};
#endif
