#include "mainwindow.h"
#include "ui_mainwindow.h"


double distance(QPoint a, QPoint b)
{
    return sqrt(pow(a.x()-b.x(), 2)+pow(a.y() - b.y(), 2));
}

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::showMaximized();
    radius = 18;
    toolBar = createToolBar();
    addToolBar(Qt::TopToolBarArea, toolBar);
    mode = _drag;
    routeColor = "#FF0000";
    colorVertex = "#000000";
    colorEdge = "#000000";
}


QToolBar* MainWindow::createToolBar()
{
    QToolBar* toolBar = new QToolBar("Linker ToolBar");
    buttons[_addVertex] = new QAction("Add vertex");
    buttons[_removeVertex] = new QAction("Remove vertex");
    buttons[_drag] = new QAction("Drag node");
    buttons[_addEdge] = new QAction("Add edge");
    buttons[_removeEdge] = new QAction("Remove edge");
    buttons[_BFS] = new QAction("Shortest path");
    buttons[_save] = new QAction("Save");
    buttons[_load] = new QAction("Load");
    buttons[_clear] = new QAction("Clear");
    connect(buttons[_addVertex], SIGNAL(triggered()),this, SLOT(addVertex()));
    connect(buttons[_removeVertex], SIGNAL(triggered()),this, SLOT(removeVertex()));
    connect(buttons[_drag], SIGNAL(triggered()),this, SLOT(drag()));
    connect(buttons[_addEdge], SIGNAL(triggered()),this, SLOT(addEdge()));
    connect(buttons[_removeEdge], SIGNAL(triggered()),this, SLOT(removeEdge()));
    connect(buttons[_BFS],SIGNAL(triggered()), this, SLOT(BFS()));
    connect(buttons[_save], SIGNAL(triggered()), this, SLOT(save()));
    connect(buttons[_load], SIGNAL(triggered()), this, SLOT(load()));
    connect(buttons[_clear], SIGNAL(triggered()),this, SLOT(clear()));
    for(int i = 0; i < size; i++)
    {
        buttons[i]->setCheckable(true);
    }
    for(int i = 0; i<_size; i++)
    {
        toolBar->addAction(buttons[i]);
    }
    return toolBar;
}
void MainWindow:: deleteToolBar(){
    delete toolBar;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::initMatrix()
{
   int x = 40, y = 40;
   int m = 50;
   auto arr = graph.getMatrix();
   for(int i = 0; i<arr.size(); i++)
   {
       x = m + rand()%m*arr.size();
       y = m + rand()%m*arr.size();
       x = x > 1550? m + x%1550: x;
       y = y > 750? m + y%750: y;
       for(int j = 0; j<coordinates.size(); j++)
       {
           if(distance(coordinates[j].cord, QPoint(x,y))<20)
           {
               x += 10;
               y += 10;
               break;
           }
       }
       coordinates.append(Vertex(QPoint(x, y), colorVertex));
   }
   repaint();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QTextStream out(stdout);
    Q_UNUSED(event);
    QPoint pos = QWidget::mapFromGlobal(QCursor::pos());
    try
    {
        if(mode == _addVertex)
        {
            graph.addVertex();
            coordinates.append(Vertex(pos));
        }
        else if(mode == _removeVertex)
        {
            for(int i = 0; i < coordinates.size(); i++)
            {
                if(distance(pos,coordinates[i].cord) < 20)
                {
                    graph.delVertex(i);
                    coordinates.removeAt(i);
                    break;
                }

            }
        }
        else if(mode == _addEdge)
        {
            bool find = false;
            if(num<0)
            {
                for(int i = 0; i < coordinates.size(); i++)
                {
                    if(distance(pos,coordinates[i].cord) < 20)
                    {
                        num = i;
                        find = true;
                        break;
                    }

                }
                if(!find)throw FormException("Not find");
            }
            else
            {
                for(int i = 0; i < coordinates.size(); i++)
                {
                    if(distance(pos,coordinates[i].cord) < 20)
                    {
                        find = true;
                        if(num == i) throw FormException("Same vertex");
                        graph.addEdge(num,i);
                        num = -1;
                        break;
                    }

                }
               if(!find)throw FormException("Not find");
            }

        }
        else if(mode == _removeEdge)
        {
            bool find = false;
            if(num<0)
            {
                for(int i = 0; i < coordinates.size(); i++)
                {
                    if(distance(pos,coordinates[i].cord) < 20)
                    {
                        find = true;
                        num = i;
                        break;
                    }

                }
                if(!find)throw FormException("Not find");
            }
            else
            {
                for(int i = 0; i < coordinates.size(); i++)
                {
                    if(distance(pos,coordinates[i].cord) < 20)
                    {
                        find = true;
                        if(num == i) throw FormException("Same vertex");
                        graph.delEdge(num,i);
                        num = -1;
                        break;
                    }

                }
                if(!find)throw FormException("Not find");
            }

        }
        else if(mode == _BFS)
        {
            bool find = false;
            if(num<0)
            {
                for(int i = 0; i < coordinates.size(); i++)
                {
                    if(distance(pos,coordinates[i].cord) < 20)
                    {
                        find = true;
                        num = i;
                        break;
                    }

                }
                if(!find)throw FormException("Not find");
            }
            else
            {
                for(int i = 0; i < coordinates.size(); i++)
                {
                    if(distance(pos,coordinates[i].cord) < 20)
                    {
                        find = true;
                        if(num == i) throw FormException("Same vertex");
                        path = graph.BFS(num,i);
                        num = -1;
                        //throw FormException("asd");
                        break;
                    }

                }

                if(!find)throw FormException("Not find");
            }
        }
        repaint();
    }
    catch (FormException& e)
    {
        if(e.getError() == "Same vertex")
        {
            QMessageBox::information(this, tr("Error"), tr("Same vertex"));
        }
        else if(e.getError() == "Not find")
        {
            QMessageBox::information(this, tr("Error"), tr("Click on vertex next time"));
        }
    }
    catch(GraphException& e)
    {
        QMessageBox::information(this, tr("Error"), tr("No path between this vertexes"));
        num = -1;
    }

}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QPoint pos = QWidget::mapFromGlobal(QCursor::pos());
    if(mode == _drag)
    {
        for(int i = 0; i < coordinates.size(); i++)
        {
            if(distance(pos,coordinates[i].cord) < 20)
            {
                coordinates[i].cord = pos;
                break;
            }

        }
    }
    repaint();
}


void MainWindow::paintEvent(QPaintEvent * e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    if(mode == _BFS)
    {
        if(path.size()>1)
        {
            for(int i = 0; i<coordinates.size(); i++)
            {
                coordinates[i].color = colorVertex;
            }
            for(int i = 0; i<path.size(); i++)
            {
                coordinates[path[i]].color = routeColor;
            }
            path.clear();

        }
    }
    //edges
    auto arr = graph.getMatrix();
    QList<Edge> edges;
    for(int i = 0; i<arr.size(); i++)
    {
        for(int j = i+1; j < arr[0].size(); j++)
        {
            if(arr[i][j]==1)
            {
               bool key=true;
               for(int k=0;k<edges.size();k++){
                   if(edges[k].from==i && edges[k].to==j) {key=false;break;}
               }
               if(key) edges.append(Edge(i,j));
            }
        }

    }
    int counter=0;
     for(int i=0;i<edges.size();i++)
     {
         bool key=false;
         QPointF f;
         QLineF firstLine(coordinates[edges[i].from].cord,coordinates[edges[i].to].cord);
         for(int j=0;j<edges.size();j++)
         {
             if(j==i || edges[j].from==edges[i].from || edges[j].from==edges[i].to ||edges[j].to==edges[i].from ||edges[j].to==edges[i].to) continue;
              QLineF firstLine1(coordinates[edges[j].from].cord,coordinates[edges[j].to].cord);
              if(firstLine.intersects(firstLine1, &f )==QLineF::BoundedIntersection)
              {
                  QPen color(Qt::red, 4, Qt::SolidLine);
                  painter.setPen(color);
                  painter.drawLine(coordinates[edges[i].from].cord, coordinates[edges[i].to].cord);
                  key=true;
                  break;
              }
         }
         if(!key)
         {
             counter++;
                   QPen color(Qt::black, 4, Qt::SolidLine);
                   painter.setPen(color);
                   painter.drawLine(coordinates[edges[i].from].cord, coordinates[edges[i].to].cord);
         }
     }
        for(int i = 0; i < coordinates.size(); i++)
        {
            QPen pen(QColor(coordinates[i].color), 2, Qt::SolidLine);
            painter.setPen(QColor(coordinates[i].color));
            painter.setBrush(QBrush(QColor(coordinates[i].color)));
            painter.drawEllipse(coordinates[i].cord, radius, radius);
        }
        if(counter==edges.size()) lvlComplete=true;
}

void MainWindow::changeColors()
{
    for(int i = 0; i<coordinates.size(); i++)
    {
        coordinates[i].color = colorVertex;
    }
}


void MainWindow::addVertex()
{
    changeColors();
    buttons[mode] ->setChecked(false);
    buttons[_addVertex]->setChecked(true);
    mode = _addVertex;
    num = -1;
}

void MainWindow::addEdge()
{
    changeColors();
    buttons[mode] ->setChecked(false);
    buttons[_addEdge]->setChecked(true);
    mode = _addEdge;
    num = -1;
}

void MainWindow::drag()
{
    changeColors();
    buttons[mode] ->setChecked(false);
    buttons[_drag]->setChecked(true);
    mode = _drag;
    num = -1;
}

void MainWindow::removeVertex()
{
    changeColors();
    buttons[mode] ->setChecked(false);
    buttons[_removeVertex]->setChecked(true);
    mode = _removeVertex;
    num = -1;
}

void MainWindow::removeEdge()
{
    changeColors();
    buttons[mode] ->setChecked(false);
    buttons[_removeEdge]->setChecked(true);
    mode = _removeEdge;
    num = -1;
}

void MainWindow::BFS()
{
    buttons[mode] ->setChecked(false);
    buttons[_BFS]->setChecked(true);
    mode = _BFS;
    num = -1;
}

void MainWindow::save()
{
    QString fileName = QFileDialog::getSaveFileName(this,
           tr("Save Adjancecy Matrix"), "",
           tr("Adjancecy Matrix(*.txt)"));
    if (fileName.isEmpty())
        return;
    else
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
            return;
        }
        QTextStream out(&file);
        auto arr = graph.getMatrix();
        for(int i = 0; i < arr.size(); i++)
        {
            for(int j = 0; j < arr[0].size(); j++)
            {
                out<<arr[i][j];
            }
            out<<"\n";
        }
    }
}

void MainWindow::load(bool loadFile)
{
    //clear();
    QString fileName;
    if(loadFile)
       fileName = QFileDialog::getOpenFileName(this, tr("Load Adjancecy Matrix"), "",tr("Adjancecy Matrix(*.txt)"));
    else
    {
    fileName=QString::number(progress)+".txt";
    }
    if (fileName.isEmpty())
           return;
       else
       {
           QFile file(fileName);
           if (!file.open(QIODevice::ReadOnly)) {
               QMessageBox::information(this, tr("Unable to open file"),
                   file.errorString());
               return;
           }
           QList<QList<int>> arr;
           QTextStream in(&file);
           int row = 0;
           int columnMax;
           try
           {
               while(!in.atEnd())
               {
                   int column = 0;
                   QString str = in.readLine();
                   QList<int> line;
                   arr.push_back(line);
                   for(int i = 0; i < str.size(); i++)
                   {
                       if(str[i] == '0') arr[row].push_back(0);
                       else if(str[i] == '1') arr[row].push_back(1);
                       else throw FormException("Incorrect file data");

                   }
                   column = str.size();

                   if(row == 0)
                       columnMax = arr[0].size();

                   if(column != columnMax)
                        throw FormException("Incorrect file data");
                   row++;
               }

               if(columnMax != arr.size())
                   throw FormException("Incorrect file data");

               graph.setMatrix(arr);
           }  catch (FormException& e)
           {
               QMessageBox::information(this, tr("Error"),
                   tr("The file you are attempting to open has incorrect matrix."));
           }
    }
    initMatrix();
}

void MainWindow::clear()
{
    graph.clear();
    coordinates.clear();
    repaint();
}

void MainWindow::on_next_clicked()
{
    clear();
    progress++;
    load(false);
}

