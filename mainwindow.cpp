#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage(appTitle + " " + appVersion + " " + appDate + " by " + appAuthor);

    initialization();
    on_pushButton_clicked();

    // gui dependent initialization
#ifdef Q_OS_OSX
    // OSX---
    setWindowIcon(QIcon("timecalc.icns"));
#else
    // Windows Q_OS_WIN
    setWindowIcon(QIcon("timecalc.ico"));
#endif

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
    qint32 seconds = 0;
    qint32 minutes = 0;
    qint32 hours = 0;
    QString sum;
    QString plus = "%1.%2";
    QString minus = "-%1.%2";
    QString fmt = plus;

    diffTime(ms1,me1,&mz1,&isPositive1,ui->z1);
    diffTime(ms2,me2,&mz2,&isPositive2,ui->z2);
    diffTime(ms3,me3,&mz3,&isPositive3,ui->z3);
    diffTime(ms4,me4,&mz4,&isPositive4,ui->z4);
    diffTime(ms5,me5,&mz5,&isPositive5,ui->z5);

    qint32 t1 = QTime(0, 0, 0).secsTo(mz1);
    qint32 t2 = QTime(0, 0, 0).secsTo(mz2);
    qint32 t3 = QTime(0, 0, 0).secsTo(mz3);
    qint32 t4 = QTime(0, 0, 0).secsTo(mz4);
    qint32 t5 = QTime(0, 0, 0).secsTo(mz5);

    seconds = 0;
    if(ui->checkBox1->isChecked()){
        seconds += (isPositive1)?t1:-t1;
    }
    if(ui->checkBox2->isChecked()){
        seconds += (isPositive2)?t2:-t2;
    }
    if(ui->checkBox3->isChecked()){
        seconds += (isPositive3)?t3:-t3;
    }
    if(ui->checkBox4->isChecked()){
        seconds += (isPositive4)?t4:-t4;
    }
    if(ui->checkBox5->isChecked()){
        seconds += (isPositive5)?t5:-t5;
    }

    if(seconds < 0){
        seconds = -seconds;
        fmt = minus;
    }
    minutes  = seconds / 60;
    // seconds         = seconds % 60;
    hours    = minutes / 60;
    minutes         = minutes % 60;
    sum = QString(fmt).arg(hours,3).arg(minutes,2,10,QChar('0'));
    ui->summe->setText(sum);
}

void MainWindow::on_checkBoxAll_stateChanged(int arg1)
{
    if(arg1==Qt::CheckState::Checked){
        ui->checkBox1->setChecked(true);
        ui->checkBox2->setChecked(true);
        ui->checkBox3->setChecked(true);
        ui->checkBox4->setChecked(true);
        ui->checkBox5->setChecked(true);
    }
    else{
        ui->checkBox1->setChecked(false);
        ui->checkBox2->setChecked(false);
        ui->checkBox3->setChecked(false);
        ui->checkBox4->setChecked(false);
        ui->checkBox5->setChecked(false);
    }
    calcDiff();
}

void MainWindow::on_checkBox1_stateChanged(int arg1){Q_UNUSED(arg1) calcDiff(); }
void MainWindow::on_checkBox2_stateChanged(int arg1){Q_UNUSED(arg1) calcDiff(); }
void MainWindow::on_checkBox3_stateChanged(int arg1){Q_UNUSED(arg1) calcDiff(); }
void MainWindow::on_checkBox4_stateChanged(int arg1){Q_UNUSED(arg1) calcDiff(); }
void MainWindow::on_checkBox5_stateChanged(int arg1){Q_UNUSED(arg1) calcDiff(); }

void MainWindow::diffTime(QTime d1, QTime d2, QTime *m, bool *mSign, QLineEdit *z){
    qint32 seconds = 0;
    qint32 minutes = 0;
    qint32 hours = 0;
    QString plus = "hh:mm";
    QString minus = "-hh:mm";
    QString fmt = plus;
    if((d1.isValid() && d2.isValid()) ){
        seconds = d1.secsTo(d2);
    }else{
        seconds = 0;
    }
    if(seconds<0){
        fmt=minus;
        seconds = -seconds;
        *mSign = false;
    };
    minutes  = seconds / 60;
    seconds         = seconds % 60;
    hours    = minutes / 60;
    minutes         = minutes % 60;
    m->setHMS(hours,minutes,seconds,0);
    z->setText(m->toString(fmt));
}

void MainWindow::on_pushButton_clicked()
{
    // invalidate
    mz1.setHMS(24,0,0,0);
    mz2.setHMS(24,0,0,0);
    mz3.setHMS(24,0,0,0);
    mz4.setHMS(24,0,0,0);
    mz5.setHMS(24,0,0,0);

    isPositive1=true;
    isPositive2=true;
    isPositive3=true;
    isPositive4=true;
    isPositive5=true;

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

    ui->summe->setText("");
    ui->s1->setFocus();
    ui->s1->setCursorPosition(0);
}

void MainWindow::initialization(){
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
}
