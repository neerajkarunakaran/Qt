#ifndef SYSINFOWINDOWSIMPL_H
#define SYSINFOWINDOWSIMPL_H

#include <QtGlobal>
#include <QVector>

#include "SysInfo.h"

typedef struct _FILETIME FILETIME;

class SysInfoWindowsImpl: public SysInfo
{
public:
    SysInfoWindowsImpl();


    // SysInfo interface
public:
    void init();
    double cpuLoadAvarage();
    double memoryUsed();

private:
    QVector<qulonglong> cpuRawData();
    qulonglong convertFileTime(const FILETIME& filetime) const;

private:
    QVector<qulonglong> mCpuLoadLastValues;
};

#endif // SYSINFOWINDOWSIMPL_H
