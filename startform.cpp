#include "startform.h"
#include "ui_startform.h"


StartForm::StartForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartForm)
{
    this->setFixedSize(300, 320);
    ui->setupUi(this);
}

StartForm::~StartForm()
{
    delete ui;
    delete window;
}

void StartForm::on_pushButton_clicked()
{
    window=new MainWindow();
    window->setWindowIcon(QIcon(QDir::currentPath()+"\\icon.png"));
    window->setWindowTitle("Grapher");
    window->show();
    this->close();
    window->load(false);
    window->deleteToolBar();
    window->drag();
}


void StartForm::on_pushButton_2_clicked()
{
    window=new MainWindow();
    window->setWindowIcon(QIcon(QDir::currentPath()+"\\icon.png"));
    window->setWindowTitle("Grapher");
    window->show();
    window->hideNextButton();
    this->close();
}


void StartForm::on_pushButton_3_clicked()
{
    delete ui;
    exit(0);
}

