#ifndef MSQLSERVICE_H
#define MSQLSERVICE_H
#include "helper.h"


class MsqlService
{
public:
    bool insertInfo(QString gender, QString name, int age, QVariantList &ecg, QVariantList &spo2, QVariantList &resp, int heartRate, int highPr, int lowPr, int oxygen);
    void getTableData(QSqlQueryModel *m_model);//用于取得对应的数据库模型
    void getChartData(int id,QString time,int divide,QStringList &datetime,QVariantList &ecg,QVariantList &resp,QVariantList &spo2);
    bool selectInfo();
    static MsqlService& getService() {
        static MsqlService sqlService;
        return sqlService;
    }
private:
    MsqlService();
    MsqlService(MsqlService const&);
    MsqlService& operator =(MsqlService const&);
    ~MsqlService();
};


#endif // MSQLSERVICE_H
