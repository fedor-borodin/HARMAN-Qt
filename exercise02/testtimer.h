#ifndef TESTTIMER_H
#define TESTTIMER_H

#include <QObject>
#include <QTimer>

class TestTimer : public QObject
{
    Q_OBJECT
public:
    explicit TestTimer(int minNumber, int maxNumber, int maxSteps = 5, int timerInterval = 1000, QObject *parent = 0);

signals:
    void timeout();

public slots:
    void onTimerTimeout();

private:
    QTimer *m_timer;        // timer
    int n_stepsCounter;     // current timer iterations
    int m_maxSteps;         // maximum timer iterations
    int m_timerInterval;    // timer interval
    int m_minNumber;        // min random number
    int m_maxNumber;        // max random number

    //gets random number between min and max
    int getRandomNumber(int min, int max);
};

#endif // TESTTIMER_H
