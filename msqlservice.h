#ifndef MSQLSERVICE_H
#define MSQLSERVICE_H
#include "helper.h"


class MsqlService
{
public:
    bool insertInfo(QString gender, QString name, int age, QVariantList &ecg, QVariantList &spo2, QVariantList &resp, int heartRate, int highPr, int lowPr, int oxygen);
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
