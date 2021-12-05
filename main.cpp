#include <QIcon>
#include <startform.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartForm w;
    w.setWindowIcon(QIcon("D:\\final\\cursach\\icon.png"));
    w.setWindowTitle("Grapher");
    w.show();
    return a.exec();
}
