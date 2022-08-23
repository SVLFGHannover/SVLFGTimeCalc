#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QtWidgets/qlineedit.h"
#include <QMainWindow>
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_s1_textChanged(const QString &arg1);

    void on_e1_textChanged(const QString &arg1);

    void on_s2_textChanged(const QString &arg1);

    void on_e2_textChanged(const QString &arg1);

    void on_s3_textChanged(const QString &arg1);

    void on_e3_textChanged(const QString &arg1);

    void on_s4_textChanged(const QString &arg1);

    void on_e4_textChanged(const QString &arg1);

    void on_s5_textChanged(const QString &arg1);

    void on_e5_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_checkBoxAll_stateChanged(int arg1);

    void on_checkBox1_stateChanged(int arg1);

    void on_checkBox2_stateChanged(int arg1);

    void on_checkBox3_stateChanged(int arg1);

    void on_checkBox4_stateChanged(int arg1);

    void on_checkBox5_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QString appAuthor = "fz";
    QString appTitle = "TimeCalc";
    QString appVersion = "1.0";
    QString appDate = QDate::currentDate().toString();

    QTime ms1,me1,mz1;
    QTime ms2,me2,mz2;
    QTime ms3,me3,mz3;
    QTime ms4,me4,mz4;
    QTime ms5,me5,mz5;

    bool isPositive1;
    bool isPositive2;
    bool isPositive3;
    bool isPositive4;
    bool isPositive5;

    QPalette falseS1Palette;
    QPalette rightS1Palette;
    QPalette falseE1Palette;
    QPalette rightE1Palette;
    QPalette falseS2Palette;
    QPalette rightS2Palette;
    QPalette falseE2Palette;
    QPalette rightE2Palette;
    QPalette falseS3Palette;
    QPalette rightS3Palette;
    QPalette falseE3Palette;
    QPalette rightE3Palette;
    QPalette falseS4Palette;
    QPalette rightS4Palette;
    QPalette falseE4Palette;
    QPalette rightE4Palette;
    QPalette falseS5Palette;
    QPalette rightS5Palette;
    QPalette falseE5Palette;
    QPalette rightE5Palette;
    void initialization();
    QTime validate(QString,bool*);
    void calcDiff();
    void diffTime(QTime, QTime, QTime *m, bool *mSign, QLineEdit *z);
};
#endif // MAINWINDOW_H
