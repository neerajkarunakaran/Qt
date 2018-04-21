#ifndef SYSINFOLINUXIMPL_H
#define SYSINFOLINUXIMPL_H


#include <QtGlobal>
#include <QVector>

#include "SysInfo.h"

class SysInfoLinuxImpl : public SysInfo
{
public:
    SysInfoLinuxImpl();

    void init() override;
    double cpuLoadAvarage() override;
    double memoryUsed() override;

private:
    QVector<qulonglong> cpuRawData();

private:
    QVector<qulonglong> _mCpuLoadLastValues;
};

#endif // SYSINFOLINUXIMPL_H