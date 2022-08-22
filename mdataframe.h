#ifndef MDATAFRAME_H
#define MDATAFRAME_H
#include "helper.h"

class MDataFrame
{
public:
    enum DataError {
                NoError,JsonParseError,ClientdisconnectError,NetworkError,UnknownError
            };
    Qt::HANDLE threadId;
    DataError error{NoError};
    QString gender{};
    QString name{};
    int age{0};
    QVariantList ecg{};
    QVariantList spo2{};
    QVariantList resp{};
    int heartRate{0};
    int highPr{0};
    int lowPr{0};
    int oxygen{0};
    MDataFrame()=default;
    MDataFrame(Qt::HANDLE threadId,DataError error);
    MDataFrame(Qt::HANDLE threadId,QString gender,QString name,int age,QVariantList& ecg,QVariantList& spo2,QVariantList& resp,int heartRate,int highPr,int lowPr,int oxygen);

};

Q_DECLARE_METATYPE(MDataFrame)

#endif // MDATAFRAME_H
