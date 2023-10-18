#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>



class Graf
{
    //od razu musimy zadeklarowaæ maksymaln¹ iloœæ wierzcho³ków - tutaj 100;
    int matrix[100][100];
    int numberOfVertices;

public:
    Graf();
    void createVertices(int ile);    
    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);    
    void removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    bool checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    int vertexDegree(int idx); 
    std::vector<int> getNeighbourIndices(int idx);
    void printNeighbourIndices(int idx);
    int getNumberOfEdges();
    void readFromFile(std::string path); 

private:
    void clear();
};

