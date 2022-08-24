#ifndef MSQLSERVICE_H
#define MSQLSERVICE_H
#include "helper.h"


class MsqlService
{
public:
    static bool insertInfo(QString gender, QString name, int age, QVariantList &ecg, QVariantList &spo2, QVariantList &resp, int heartRate, int highPr, int lowPr, int oxygen);
    static QSqlQueryModel *getTableData(QString sql);
    static void getChartData(int id,QDateTime startTime,QDateTime endTime,qint64 divide,QStringList &datetime,QVariantList &ecg,QVariantList &resp,QVariantList &spo2);
    static MsqlService& getService() {
        static MsqlService sqlService;
        return sqlService;
    }
    static QVariantList getEcg (int id);
    static QSqlQueryModel *getTableData(int id/*,QDateTime beginTime,QDateTime endTime,qint64 interval*/);
    static QByteArray encode(QVariantList &vlist);
    static QString currentDateTimeString();
    static QString formatTime(QDateTime time);
    static QVariantList decode(QByteArray &json);
private:
    MsqlService();
    MsqlService(MsqlService const&);
    MsqlService& operator =(MsqlService const&);
    ~MsqlService();
};


#endif // MSQLSERVICE_H
