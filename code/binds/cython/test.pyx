# distutils: language = c
# cython: language_level=3

from libc.stdint cimport int32_t, uint64_t, size_t
from libc.stdlib cimport malloc, free
from libc.stdio cimport FILE
from libc.time cimport time_t
from libc.stdint cimport int64_t
from libc.stdint cimport int32_t
from libc.stdint cimport uint64_t
from libc.stdint cimport size_t
from libc.stdint cimport int8_t
from libc.stdint cimport uint8_t
from libc.stdint cimport int16_t
from libc.stdint cimport uint16_t
from libc.stdint cimport int32_t
from libc.stdint cimport uint32_t
from libc.stdint cimport int64_t
from libc.stdint cimport uint64_t
from libc.stdbool cimport bool

cdef extern from "test.h":
    # --- Return codes ---
    enum:
        FOSSIL_PIZZA_SUCCESS
        FOSSIL_PIZZA_FAILURE

    cdef enum fossil_pizza_case_result_t:
        FOSSIL_PIZZA_CASE_EMPTY
        FOSSIL_PIZZA_CASE_PASS
        FOSSIL_PIZZA_CASE_FAIL
        FOSSIL_PIZZA_CASE_TIMEOUT
        FOSSIL_PIZZA_CASE_SKIPPED
        FOSSIL_PIZZA_CASE_UNEXPECTED

    cdef struct fossil_pizza_score_t:
        int passed
        int failed
        int skipped
        int timeout
        int unexpected
        int empty

    cdef struct fossil_pizza_meta_t:
        char* hash
        char* prev_hash
        time_t timestamp
        char* origin_device_id
        char* author
        double trust_score
        double confidence
        bint immutable
        char* signature

    cdef struct fossil_pizza_case_t:
        char* name
        char* tags
        char* criteria
        void (*setup)(void)
        void (*teardown)(void)
        void (*run)(void)
        uint64_t elapsed_ns
        fossil_pizza_case_result_t result
        fossil_pizza_meta_t meta

    cdef struct fossil_pizza_suite_t:
        char* suite_name
        fossil_pizza_case_t* cases
        size_t count
        size_t capacity
        void (*setup)(void)
        void (*teardown)(void)
        uint64_t time_elapsed_ns
        int total_score
        int total_possible
        fossil_pizza_score_t score
        fossil_pizza_meta_t meta

    cdef struct fossil_pizza_pallet_t:
        pass  # Define if needed

    cdef struct fossil_pizza_engine_t:
        fossil_pizza_suite_t* suites
        size_t count
        size_t capacity
        int score_total
        int score_possible
        fossil_pizza_score_t score
        fossil_pizza_pallet_t pallet
        fossil_pizza_meta_t meta

    int fossil_pizza_start(fossil_pizza_engine_t* engine, int argc, char** argv)
    int fossil_pizza_add_suite(fossil_pizza_engine_t* engine, fossil_pizza_suite_t suite)
    int fossil_pizza_add_case(fossil_pizza_suite_t* suite, fossil_pizza_case_t test_case)
    int fossil_pizza_run_suite(const fossil_pizza_engine_t* engine, fossil_pizza_suite_t* suite)
    int fossil_pizza_run_all(fossil_pizza_engine_t* engine)
    void fossil_pizza_summary(const fossil_pizza_engine_t* engine)
    int32_t fossil_pizza_end(fossil_pizza_engine_t* engine)
    void pizza_test_assert_internal(bint condition, const char *message, const char *file, int line, const char *func)
    char *pizza_test_assert_messagef(const char *message, ...)
    void _given(const char *description)
    void _when(const char *description)
    void _then(const char *description)
    void _on_skip(const char *description)
