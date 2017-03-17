#include "testtimer.h"
#include <QDebug>
#include <QtGlobal>

TestTimer::TestTimer(int minNumber, int maxNumber, int maxSteps, int timerInterval, QObject *parent) :
    m_minNumber(minNumber), m_maxNumber(maxNumber), m_maxSteps(maxSteps), m_timerInterval(timerInterval), QObject(parent)
{
    m_timer = new QTimer(this);
    m_timer->start(m_timerInterval);

    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimerTimeout()));
    n_stepsCounter = 0;
}

void TestTimer::onTimerTimeout()
{
    qDebug() << QString::number(getRandomNumber(m_minNumber, m_maxNumber));
    ++n_stepsCounter;
    if (n_stepsCounter + 1 > m_maxSteps)
        emit timeout();
}

int TestTimer::getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(qrand() * fraction * (max - min + 1) + min);
}
