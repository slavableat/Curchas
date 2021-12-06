#include "startform.h"
#include "ui_startform.h"


StartForm::StartForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartForm)
{
    ui->setupUi(this);
    window=new MainWindow();
    window->setWindowIcon(QIcon("D:\\final\\cursach\\icon.png"));
    window->setWindowTitle("Grapher");
    window->hide();
}

StartForm::~StartForm()
{
    delete ui;
}

void StartForm::on_pushButton_clicked()
{
    window->show();
    this->close();
    window->load(false);
    window->deleteToolBar();
    window->drag();
}


void StartForm::on_pushButton_2_clicked()
{
    window->show();
    window->hideNextButton();
    this->close();
}


void StartForm::on_pushButton_3_clicked()
{
    exit(0);
}

