#include "graph.h"

Graph::Graph() {

}

Graph::Graph(size_t size)
{
    for(size_t i = 0; i<size; i++)
    {
        QList<int> line(size);
        adjacencyMatrix.push_back(line);
    }
}

void Graph::addVertex()
{
    QList<int> line(adjacencyMatrix.size()+1);
    for(int i = 0; i<adjacencyMatrix.size(); i++)
    {
        adjacencyMatrix[i].push_back(0);
    }
    adjacencyMatrix.push_back(line);
}

void Graph::delVertex(int num)
{
    if(num < 0 || num > adjacencyMatrix.size()) throw GraphException("Incorrect number");
    else
    {
        for(int i = 0; i<adjacencyMatrix.size(); i++)
        {
            adjacencyMatrix[i].erase(adjacencyMatrix[i].begin()+num);
        }
        adjacencyMatrix.erase(adjacencyMatrix.begin() + num);
    }
}


void Graph::addEdge(int nativeVertex, int otherVertex)
{
    if(nativeVertex<0 || nativeVertex>=adjacencyMatrix.size() || otherVertex<0 || otherVertex>=adjacencyMatrix.size())
        throw GraphException("Incorrect numbers");
    else
    {
        adjacencyMatrix[nativeVertex][otherVertex] = 1;
        adjacencyMatrix[otherVertex][nativeVertex] = 1;
    }
}

void Graph::delEdge(int nativeVertex, int otherVertex)
{
    if(nativeVertex<0 || nativeVertex>=adjacencyMatrix.size() || otherVertex<0 || otherVertex>=adjacencyMatrix.size())
        throw GraphException("Incorrect numbers");
    else
    {
        adjacencyMatrix[nativeVertex][otherVertex] = 0;
        adjacencyMatrix[otherVertex][nativeVertex] = 0;
    }
}

Graph::Graph(QList<QList<int>>  arr)
{
    adjacencyMatrix = arr;
}

QList<QList<int>>  Graph::getMatrix()
{
    return adjacencyMatrix;
}

void Graph::setMatrix(QList<QList<int>>  arr)
{
    adjacencyMatrix = arr;
}

void Graph::clear()
{
    for(int i = 0; i < adjacencyMatrix.size(); i++)
    {
        adjacencyMatrix[i].clear();
    }
    adjacencyMatrix.clear();
}
