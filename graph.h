#ifndef GRAPH_H
#define GRAPH_H

#include <exception>
#include <QQueue>
#include <QList>

class GraphException: public std::exception
{
    QString error;
public:
    GraphException(QString str) {error = str;}
    QString getError() {return error;}
};


class Graph
{
    QList<QList<int>> adjacencyMatrix;
public:
    Graph();

    Graph(size_t size);

    Graph(QList<QList<int>>  arr);

    QList<QList<int>>  getMatrix();

    void setMatrix(QList<QList<int>>  arr);

    void addVertex();

    void delVertex(int num);

    void addEdge(int nativeVertex, int otherVertex);

    void delEdge(int nativeVertex, int otherVertex);

    void clear();
};



#endif // GRAPH_H
