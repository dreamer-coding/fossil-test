from libc.stdint cimport uint64_t
from libc.time cimport clock_t

cdef extern from "mark.h":
    cdef struct fossil_mark_t:
        const char* name
        clock_t start_time
        clock_t end_time
        int num_samples
        double total_duration
        double min_duration
        double max_duration
        int running

    void fossil_benchmark_init(fossil_mark_t* benchmark, const char* name)
    void fossil_benchmark_start(fossil_mark_t* benchmark)
    void fossil_benchmark_stop(fossil_mark_t* benchmark)
    double fossil_benchmark_elapsed_seconds(const fossil_mark_t* benchmark)
    double fossil_benchmark_min_time(const fossil_mark_t* benchmark)
    double fossil_benchmark_max_time(const fossil_mark_t* benchmark)
    double fossil_benchmark_avg_time(const fossil_mark_t* benchmark)
    void fossil_benchmark_reset(fossil_mark_t* benchmark)
    void fossil_benchmark_report(const fossil_mark_t* benchmark)

    cdef struct fossil_scoped_mark_t:
        fossil_mark_t* benchmark

    void fossil_scoped_benchmark_init(fossil_scoped_mark_t* scoped_benchmark, fossil_mark_t* benchmark)
    void fossil_scoped_benchmark_destroy(fossil_scoped_mark_t* scoped_benchmark)

    void fossil_test_benchmark(char* duration_type, double expected, double actual)
    void fossil_test_start_benchmark()
    uint64_t fossil_test_stop_benchmark()