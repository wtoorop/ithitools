#ifndef ITHI_METRICS_H
#define ITHI_METRICS_H
#include "CaptureSummary.h"

typedef struct _st_metric4_line_t {
    char domain[64];
    double frequency;
} metric4_line_t;

typedef struct _st_metric6_registered_t {
    uint32_t key;
    char const * key_name;
} metric6_registered_t;

typedef struct _st_metric6_parameter {
    uint32_t parameter_value;
    uint32_t parameter_count;
} metric6_parameter_t;

typedef struct _st_metric6_def_t {
    char const * m6_prefix;
    uint32_t table_id;
    uint32_t nb_registered;
    metric6_registered_t * registry;
    char const * iana_file_name;
} metric6_def_t;

typedef struct _st_metric6_line_t {
    char const * m6_prefix;
    double m6_x_1;
    double m6_x_2;
    std::vector<metric6_parameter_t> m6_x_3;
} metric6_line_t;

class ithimetrics
{
public:
    ithimetrics();
    ~ithimetrics();

    bool GetMetrics(CaptureSummary* cs);

    bool Save(char const * file_name);

private:
    uint32_t nb_rootqueries;
    uint32_t nb_userqueries;
    uint32_t nb_nondelegated;
    uint32_t nb_delegated;

    double m3_1;
    double m3_2;
    std::vector<metric4_line_t> m33_1;
    std::vector<metric4_line_t> m33_2;
    std::vector<metric4_line_t> m33_3;
    double m33_4;
    double m4_1;
    std::vector<metric4_line_t> m4_2;
    std::vector<metric4_line_t> m4_3;
    std::vector<metric6_line_t> m6;

    void GetM3_1(CaptureSummary* cs);
    void GetM3_2(CaptureSummary* cs);
    void GetM33_1(CaptureSummary* cs);
    void GetM33_2(CaptureSummary* cs);
    void GetM33_3(CaptureSummary* cs);
    void GetM4_1(CaptureSummary* cs);
    void GetM4_2(CaptureSummary* cs);
    void GetM4_3(CaptureSummary* cs);
    void GetM3_X(CaptureSummary* cs, uint32_t table_id,
        std::vector<metric4_line_t> * mstring_x, double min_share);
    void GetM4_X(CaptureSummary* cs, uint32_t table_id,
        std::vector<metric4_line_t> * mstring_x, double min_share);
    void GetStringM_X(CaptureSummary* cs, uint32_t table_id, 
        std::vector<metric4_line_t> * mstring_x, uint32_t nbqueries,double min_share);
    void GetM6(CaptureSummary* cs);

    static bool metric4_line_is_bigger(metric4_line_t x, metric4_line_t y);
};
#endif
