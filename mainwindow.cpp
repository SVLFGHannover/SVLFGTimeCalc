#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage(appTitle + " " + appVersion + " " + appDate + " by " + appAuthor);
    ui->s1->setInputMask("99.99");
    ui->e1->setInputMask("99.99");
    ui->s2->setInputMask("99.99");
    ui->e2->setInputMask("99.99");
    ui->s3->setInputMask("99.99");
    ui->e3->setInputMask("99.99");
    ui->s4->setInputMask("99.99");
    ui->e4->setInputMask("99.99");
    ui->s5->setInputMask("99.99");
    ui->e5->setInputMask("99.99");

    falseS1Palette = ui->s1->palette();
    rightS1Palette = ui->s1->palette();
    falseS1Palette.setColor(QPalette::Base, Qt::red);
    rightS1Palette.setColor(QPalette::Base, Qt::green);
    falseE1Palette = ui->e1->palette();
    rightE1Palette = ui->e1->palette();
    falseE1Palette.setColor(QPalette::Base, Qt::red);
    rightE1Palette.setColor(QPalette::Base, Qt::green);

    falseS2Palette = ui->s2->palette();
    rightS2Palette = ui->s2->palette();
    falseS2Palette.setColor(QPalette::Base, Qt::red);
    rightS2Palette.setColor(QPalette::Base, Qt::green);
    falseE2Palette = ui->e2->palette();
    rightE2Palette = ui->e2->palette();
    falseE2Palette.setColor(QPalette::Base, Qt::red);
    rightE2Palette.setColor(QPalette::Base, Qt::green);

    falseS3Palette = ui->s3->palette();
    rightS3Palette = ui->s3->palette();
    falseS3Palette.setColor(QPalette::Base, Qt::red);
    rightS3Palette.setColor(QPalette::Base, Qt::green);
    falseE3Palette = ui->e3->palette();
    rightE3Palette = ui->e3->palette();
    falseE3Palette.setColor(QPalette::Base, Qt::red);
    rightE3Palette.setColor(QPalette::Base, Qt::green);


    falseS4Palette = ui->s4->palette();
    rightS4Palette = ui->s4->palette();
    falseS4Palette.setColor(QPalette::Base, Qt::red);
    rightS4Palette.setColor(QPalette::Base, Qt::green);
    falseE4Palette = ui->e4->palette();
    rightE4Palette = ui->e4->palette();
    falseE4Palette.setColor(QPalette::Base, Qt::red);
    rightE4Palette.setColor(QPalette::Base, Qt::green);


    falseS5Palette = ui->s5->palette();
    rightS5Palette = ui->s5->palette();
    falseS5Palette.setColor(QPalette::Base, Qt::red);
    rightS5Palette.setColor(QPalette::Base, Qt::green);
    falseE5Palette = ui->e5->palette();
    rightE5Palette = ui->e5->palette();
    falseE5Palette.setColor(QPalette::Base, Qt::red);
    rightE5Palette.setColor(QPalette::Base, Qt::green);

    ui->s1->setPalette(falseS1Palette);
    ui->s2->setPalette(falseS2Palette);
    ui->s3->setPalette(falseS3Palette);
    ui->s4->setPalette(falseS4Palette);
    ui->s5->setPalette(falseS5Palette);
    ui->e1->setPalette(falseE1Palette);
    ui->e2->setPalette(falseE2Palette);
    ui->e3->setPalette(falseE3Palette);
    ui->e4->setPalette(falseE4Palette);
    ui->e5->setPalette(falseE5Palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_s1_textChanged(const QString &arg1)
{
    bool ok;
    ms1 = validate(arg1,&ok);
    if(ok == false)
    {
        ui->s1->setPalette(falseS1Palette);
        ms1.setHMS(24,0,0,0);
    }else{
        ui->s1->setPalette(rightS1Palette);
    }
    calcDiff();
}
void MainWindow::on_e1_textChanged(const QString &arg1)
{
    bool ok;
    me1 = validate(arg1,&ok);
    if(ok == false)
    {
        ui->e1->setPalette(falseE1Palette);
        me1.setHMS(24,0,0,0);
    }else{
        ui->e1->setPalette(rightE1Palette);
    }
    calcDiff();
}


void MainWindow::on_s2_textChanged(const QString &arg1)
{
    bool ok;
    ms2 = validate(arg1,&ok);
    if(ok == false)
    {
        ui->s2->setPalette(falseS2Palette);
        ms2.setHMS(24,0,0,0);
    }else{
        ui->s2->setPalette(rightS2Palette);
    }
    calcDiff();
}


void MainWindow::on_e2_textChanged(const QString &arg1)
{
    bool ok;
    me2 = validate(arg1,&ok);
    if(ok == false)
    {
        ui->e2->setPalette(falseE2Palette);
        me2.setHMS(24,0,0,0);
    }else{
        ui->e2->setPalette(rightE2Palette);
    }
    calcDiff();
}


void MainWindow::on_s3_textChanged(const QString &arg1)
{
    bool ok;
    ms3 = validate(arg1,&ok);
    if(ok == false)
    {
        ui->s3->setPalette(falseS3Palette);
        ms3.setHMS(24,0,0,0);
    }else{
        ui->s3->setPalette(rightS3Palette);
    }
    calcDiff();

}


void MainWindow::on_e3_textChanged(const QString &arg1)
{
    bool ok;
    me3 = validate(arg1,&ok);
    if(ok == false)
    {
        ui->e3->setPalette(falseE3Palette);
        me3.setHMS(24,0,0,0);
    }else{
        ui->e3->setPalette(rightE3Palette);
    }
    calcDiff();

}


void MainWindow::on_s4_textChanged(const QString &arg1)
{
    bool ok;
    ms4 = validate(arg1,&ok);
    if(ok == false)
    {
        ui->s4->setPalette(falseS4Palette);
        ms4.setHMS(24,0,0,0);
    }else{
        ui->s4->setPalette(rightS4Palette);
    }
    calcDiff();

}


void MainWindow::on_e4_textChanged(const QString &arg1)
{
    bool ok;
    me4 = validate(arg1,&ok);
    if(ok == false)
    {
        ui->e4->setPalette(falseE4Palette);
        me4.setHMS(24,0,0,0);
    }else{
        ui->e4->setPalette(rightE4Palette);
    }
    calcDiff();

}


void MainWindow::on_s5_textChanged(const QString &arg1)
{
    bool ok;
    ms5 = validate(arg1,&ok);
    if(ok == false)
    {
        ui->s5->setPalette(falseS5Palette);
        ms5.setHMS(24,0,0,0);
    }else{
        ui->s5->setPalette(rightS5Palette);
    }
    calcDiff();
}


void MainWindow::on_e5_textChanged(const QString &arg1)
{
    bool ok;
    me5 = validate(arg1,&ok);
    if(ok == false)
    {
        ui->e5->setPalette(falseE5Palette);
        me5.setHMS(24,0,0,0);
    }else{
        ui->e5->setPalette(rightE5Palette);
    }
    calcDiff();
}



// liefert ein QTime Objekt zurück
QTime MainWindow::validate(QString value, bool *ok)
{
    QTime retVal=QTime::fromString(value,"hh.mm");
    if (retVal.isValid()) {
        *ok = true;
        return retVal;
    }
    *ok=false;
    retVal.setHMS(24,0,0,0);
    return retVal;
}

void MainWindow::calcDiff()
{
    qint32 seconds;
    qint32 minutes;
    qint32 hours;

    // 1
    if((ms1.isValid() && me1.isValid()) && ms1<me1){
        seconds = ms1.secsTo(me1);
    }else{
        seconds = 0;
    }
    minutes  = seconds / 60;
    seconds         = seconds % 60;
    hours    = minutes / 60;
    minutes         = minutes % 60;
    mz1.setHMS(hours,minutes,seconds,0);
    ui->z1->setText(mz1.toString("hh.mm"));

    // 2
    if((ms2.isValid() && me2.isValid()) && ms2<me2){
        seconds = ms2.secsTo(me2);
    }else{
        seconds = 0;
    }
    minutes  = seconds / 60;
    seconds         = seconds % 60;
    hours    = minutes / 60;
    minutes         = minutes % 60;
    mz2.setHMS(hours,minutes,seconds,0);
    ui->z2->setText(mz2.toString("hh.mm"));

    // 3
    if((ms3.isValid() && me3.isValid()) && ms3<me3){
        seconds = ms3.secsTo(me3);
    }else{
        seconds = 0;
    }
    minutes  = seconds / 60;
    seconds         = seconds % 60;
    hours    = minutes / 60;
    minutes         = minutes % 60;
    mz3.setHMS(hours,minutes,seconds,0);
    ui->z3->setText(mz3.toString("hh.mm"));

    // 4
    if((ms4.isValid() && me4.isValid()) && ms4<me4){
        seconds = ms4.secsTo(me4);
    }else{
        seconds = 0;
    }
    minutes  = seconds / 60;
    seconds         = seconds % 60;
    hours    = minutes / 60;
    minutes         = minutes % 60;
    mz4.setHMS(hours,minutes,seconds,0);
    ui->z4->setText(mz4.toString("hh.mm"));

    // 5
    if((ms5.isValid() && me5.isValid()) && ms5<me5){
        seconds = ms5.secsTo(me5);
    }else{
        seconds = 0;
    }
    minutes  = seconds / 60;
    seconds         = seconds % 60;
    hours    = minutes / 60;
    minutes         = minutes % 60;
    mz5.setHMS(hours,minutes,seconds,0);
    ui->z5->setText(mz5.toString("hh.mm"));

    qint32 t1 = QTime(0, 0, 0).secsTo(mz1);
    qint32 t2 = QTime(0, 0, 0).secsTo(mz2);
    qint32 t3 = QTime(0, 0, 0).secsTo(mz3);
    qint32 t4 = QTime(0, 0, 0).secsTo(mz4);
    qint32 t5 = QTime(0, 0, 0).secsTo(mz5);

    seconds = t1+t2+t3+t4+t5;

    minutes  = seconds / 60;
    seconds         = seconds % 60;
    hours    = minutes / 60;
    minutes         = minutes % 60;
    QTime summe;
    summe.setHMS(hours,minutes,seconds,0);
    ui->summe->setText(summe.toString("hh.mm"));
}





void MainWindow::on_pushButton_clicked()
{
    mz1.setHMS(24,0,0,0);
    mz2.setHMS(24,0,0,0);
    mz3.setHMS(24,0,0,0);
    mz4.setHMS(24,0,0,0);
    mz5.setHMS(24,0,0,0);

    ui->s1->setText("");
    ui->s2->setText("");
    ui->s3->setText("");
    ui->s4->setText("");
    ui->s5->setText("");

    ui->e1->setText("");
    ui->e2->setText("");
    ui->e3->setText("");
    ui->e4->setText("");
    ui->e5->setText("");

    ui->z1->setText("00.00");
    ui->z2->setText("00.00");
    ui->z3->setText("00.00");
    ui->z4->setText("00.00");
    ui->z5->setText("00.00");

    ui->summe->setText("");
}

