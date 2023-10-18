#include <iostream>
#include <vector>
#include <algorithm>
#include "dijkstra.h"
#include <fstream>
using namespace std;

const int INF = 1e9;

void dijkstra(vector<vector<pair<int, int>>>& graph, int start, int end, vector<int>& dist, vector<int>& prev) {
    int n = graph.size();
    dist.assign(n, INF);
    prev.assign(n, -1);
    dist[start] = 0;

    MyHeap pq;
    pq.insert(0, start);

    while (!pq.isEmpty()) {
        pair<int, int> curr = pq.pop();
        int u = curr.second;

        for (vector<pair<int, int>>::iterator it = graph[u].begin(); it != graph[u].end(); it++) {
            int v = it->first;
            int weight = it->second;

            int alt = dist[u] + weight;
            if (alt < dist[v]) {
                dist[v] = alt;
                prev[v] = u;
                pq.insert(alt, v);
            }
        }
    }
}

int main() {
    ifstream file;
    file.open(); //miejsce na podanie pliku źródłowego

    if (!file.is_open()) {
        cout << "Nie udalo sie otworzyc pliku." << endl;
        return 1;
    }

    int cena = 0;
    vector<int> ceny_metali; //kolejne ceny metali
    file >> cena;
    int pom;

    for(int i = 0; i < cena; i++) {
        file >> pom;
        ceny_metali.push_back(pom);
    }

    int n; // ilosc przemian
    file >> n;
    int x,y,z;
    vector<vector<pair<int, int>>> graph(n * 2);

    pom = 0;

    while (file >> x >> y >> z) {
        graph[x].push_back(make_pair(y, z));
        graph[x].push_back(make_pair((x + cena),(ceny_metali[x - 1] / 2))); //dodajemy na pozycje x' cene konwersji metalu
        graph[x + cena].push_back(make_pair((y + cena), z)); //dodawanie scieżek do zdublowanych wierzcholkow

    }

    int start = 1; // zloto
    int end = cena + 1; // zloto'

    // Uruchamianie algorytmu Dijkstry
    vector<int> distance;
    vector<int> previous;
    dijkstra(graph, start, end, distance, previous);


    //odpowiedz
    cout << "Cena najtanszej przemiany metali to " << distance[end] << endl;

    return 0;
}
