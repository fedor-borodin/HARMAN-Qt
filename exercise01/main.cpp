#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // exercise 1a
    qDebug() << "exersice 01a-----------------------------";

    const static int cDaysOfWeekCount = 7;
    QDate currDate = QDate::currentDate();
    int currDayOfWeek = currDate.dayOfWeek();

    for (int i = 1; i < cDaysOfWeekCount + 1; ++i) {
        qDebug() << currDate.addDays(i - currDayOfWeek).toString("MM-dd-yyyy-dddd");
    }


    // exercise 1b
    qDebug() << "exersice 01b-----------------------------";

    QTextStream cin(stdin);
    qDebug() << "Enter a word:";

    QString userWord = cin.readLine();
    int strSize = userWord.size();
    QString reverseWord;

    for (int i = 0; i < strSize; ++i) {
        reverseWord.append(userWord.at(strSize - i - 1));
    }

    qDebug() << reverseWord;

    return a.exec();
}
