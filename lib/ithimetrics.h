#ifndef ITHI_METRICS_H
#define ITHI_METRICS_H

#include <time.h>
#include "CaptureSummary.h"
#include "M1Data.h"
#include "M2Data.h"
#include "ComputeM34.h"
#include "ComputeM6.h"
#include "M7Getter.h"


#ifdef _WINDOWS
#ifndef ITHI_DEFAULT_FOLDER
#define ITHI_DEFAULT_FOLDER ".\\"
#endif
#ifndef ITHI_FILE_PATH_SEP
#define ITHI_FILE_PATH_SEP "\\"
#endif
#else
#ifndef ITHI_DEFAULT_FOLDER
#define ITHI_DEFAULT_FOLDER "./"
#endif
#ifndef ITHI_FILE_PATH_SEP
#define ITHI_FILE_PATH_SEP "/"
#endif
#endif

class ithimetrics
{
public:
    ithimetrics();
    ~ithimetrics();

    bool GetMetrics();

    bool SetIthiFolder(char const * folder);
    const char * GetIthiFolderName() {
        return ithi_folder;
    };

    bool SetMetricFileNames(int metric_number, char const * metric_file_name);

    bool SetRootCaptureFileName(char const * file_name);
    bool SetRecursiveCaptureFileName(char const * file_name);

    bool SetRootZoneFileName(char const * file_name);

    bool SetDefaultRootCaptureFile();
    bool SetDefaultRecursiveCaptureFile();
    bool SetDefaultRootZoneFile();

    const char * GetRootCaptureFileName() {
        return root_capture_file_name;
    };
    const char * GetRecursiveCaptureFileName() {
        return recursive_capture_file_name;
    };
    const char * GetRootZoneFileName() {
        return root_zone_file_name;
    };

    bool SetDateString(char const * date_string);
    bool SetDefaultDate(time_t current_time);
    const char * GetMetricDate() { return (const char *)metric_date; };

    bool SetAbuseFileName(char const * abuse_file_name, M2DataType f_type);
    bool SetDefaultAbuseFileName(M2DataType f_type);
    const char * GetAbuseFileName(M2DataType f_type);

    bool SetComplianceFileName(char const * compliance_file_name);
    bool SetDefaultComplianceFileName();
    const char * GetComplianceFileName() { return (const char *)compliance_file_name; };

    bool SaveMetricFiles();

    bool Save(char const * file_name);

private:
    ComputeM1 cm1;
    ComputeM2 cm2;
    ComputeM3 cm3;
    ComputeM4 cm4;
    ComputeM6 cm6;
    ComputeM7 cm7;

    char * metric_date;
    char * ithi_folder;
    char * metric_file[7];
    bool metric_is_available[7];
    char * compliance_file_name;
    char * root_capture_file_name;
    char * recursive_capture_file_name;
    char * abuse_file_name_tlds;
    char * abuse_file_name_registrars;
    char * root_zone_file_name;

    bool SetDefaultCaptureFiles(char const * metric_name, char const * suffix, char ** p_file_name);

    static bool copy_name(char ** target, char const * name);
};

#endif /* ITHI_METRICS_H */
