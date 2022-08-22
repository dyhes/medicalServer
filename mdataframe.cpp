#include "mdataframe.h"

MDataFrame::MDataFrame(Qt::HANDLE threadId, MDataFrame::DataError error):
    threadId(threadId),
    error(error)
{

}

MDataFrame::MDataFrame(Qt::HANDLE threadId, QString gender, QString name, int age, QVariantList &ecg, QVariantList &spo2, QVariantList &resp, int heartRate, int highPr, int lowPr, int oxygen):
    threadId(threadId),
    gender(gender),
    age(age),
    name(name),
    ecg(ecg),
    spo2(spo2),
    resp(resp),
    heartRate(heartRate),
    lowPr(lowPr),
    highPr(highPr),
    oxygen(oxygen)
{

}
