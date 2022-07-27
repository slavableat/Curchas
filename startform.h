#ifndef STARTFORM_H
#define STARTFORM_H
#include <mainwindow.h>
#include <QWidget>

namespace Ui {
class StartForm;
}

class StartForm : public QWidget
{
    Q_OBJECT

public:
    explicit StartForm(QWidget *parent = nullptr);
    ~StartForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::StartForm *ui;
    MainWindow *window;
};

#endif // STARTFORM_H
