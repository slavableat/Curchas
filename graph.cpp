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

QList<int> Graph::BFS(int start, int end)
{
    size_t size = adjacencyMatrix.size();
    std::vector<bool> used(size);
    used[start] = true;
    QQueue<int> queue;
    queue.enqueue(start);
    std::vector<size_t> routes(size);
    std::vector<int> ancestor(size);
    ancestor[start] = -1;
    while(!queue.empty())
    {
        int first = queue.front();
        queue.dequeue();
        for(size_t i = 0; i < size; i++)
        {
            short int to = i;
            if(!used[to] && adjacencyMatrix[first][i] == 1)
            {
                used[to] = true;
                queue.enqueue(to);
                routes[to] = routes[first]+1;
                ancestor[to] = first;
            }
        }
    }
    if(!used[end])
        throw GraphException("No way between this points");
    else
    {
        QList<int> path;
        for (int v=end; v!=-1; v=ancestor[v]) path.push_back (v);
        return path;
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
