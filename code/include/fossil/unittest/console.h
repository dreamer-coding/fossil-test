/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#ifndef FOSSIL_TEST_CONSOLE_H
#define FOSSIL_TEST_CONSOLE_H

#include "fossil/_common/common.h"
#include "internal.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Function to print a message to the console with a specific color.
 * 
 * @param color_name The name of the color
 * @param format The format string
 * @param ... The arguments to format
 */
void fossil_test_cout(const char* color_name, const char* format, ...);

void fossil_test_io_information(void);
void fossil_test_io_sanity_load(fossil_test_t *test);
void fossil_test_io_unittest_given(char *description);
void fossil_test_io_unittest_when(char *description);
void fossil_test_io_unittest_then(char *description);

void fossil_test_io_unittest_start(fossil_test_t *test);
void fossil_test_io_unittest_step(xassert_info *assume);
void fossil_test_io_unittest_ended(fossil_test_t *test);
void fossil_test_io_asserted(xassert_info *assume);
void fossil_test_io_summary_start(void);
void fossil_test_io_summary_ended(void);

#ifdef __cplusplus
}
#endif

#endif
