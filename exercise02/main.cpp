#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QtGlobal>
#include <QTime>

#include "testtimer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qsrand(QTime::currentTime().msecsSinceStartOfDay());

    qDebug() << "Enter a maximum random number:";
    QTextStream cin(stdin);
    int maxNumber = cin.readLine().toInt();

    TestTimer *my_timer = new TestTimer(0, maxNumber);
    QObject::connect(my_timer, SIGNAL(timeout()), &a, SLOT(quit()));

    return a.exec();
}
