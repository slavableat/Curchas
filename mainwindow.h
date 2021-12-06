#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>
#include <graph.h>
#include <exception>
#include <QMainWindow>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <QErrorMessage>
#include <QList>
#include <QKeyEvent>
#include <QToolBar>
#include <QAction>
#include <QGraphicsScene>
#include <QPushButton>

class FormException
{
    QString error;
public:
    FormException(QString e){error = e;}
    QString getError(){return error;}
};

struct Vertex
{
    QPoint cord;
    QString color;
    Vertex(QPoint p, QString col = "#000000"){cord = p;color=col;}
};
struct Edge
{
    int from;
    int to;
    Edge(int _from, int _to):from(_from),to(_to){}
};


struct PreviousCoursorPos
{
    QPoint point;
    int num;

};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    void mouseMoveEvent(QMouseEvent *event);

    void initMatrix();

    void saveMatrix();

    void paintEvent(QPaintEvent * e);

    QToolBar* createToolBar();

    void deleteToolBar();

    QPushButton* createNextButton();

    void hideNextButton();

public slots:
    void addVertex();

    void addEdge();

    void drag();

    void removeVertex();

    void removeEdge();

    void mousePressEvent(QMouseEvent *event);

    void save();

    void load(bool loadFile=true);

    void clear();

    void on_next_clicked();
private:
    enum names
    {
        _addVertex = 0,
        _removeVertex = 1,
        _drag = 2,
        _addEdge = 3,
        _removeEdge = 4,
        _clear = 5,
        _load = 6,
        _save = 7

    };
    Graph graph;
    int radius;
    QString colorEdge;
    QString colorVertex;
    QList<Vertex> coordinates;
    Ui::MainWindow *ui;
    int mode;
    static const int size = 5;
    static const int _size = 8;
    QAction *buttons[_size];
    QToolBar *toolBar;
    QPushButton *next;
    bool success = false;
    int num = -1;
    QList<int> path;
    QString routeColor;
    int progress=1;
};
#endif // MAINWINDOW_H
