#include "PQ.h"
#include <iostream>

using namespace std;

int main() {
    KolejkaPriorytetowa pq;

    pq.insert(5);
    pq.insert(1);
    pq.insert(7);
    pq.insert(3);
    pq.insert(0);

    cout << "Podejrzenie elementu na poczatku : " << pq.peek() <<endl;

    cout << "Elementy w kolejce :" << endl;
   cout << pq.poll() << endl;
   cout << pq.poll() << endl;
   cout << pq.poll() << endl;
   cout << pq.poll() << endl;
   cout << pq.poll() << endl;







}
