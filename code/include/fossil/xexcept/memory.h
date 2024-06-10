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
#ifndef FOSSIL_TEST_EXCEPT_MEMORY_TYPE_H
#define FOSSIL_TEST_EXCEPT_MEMORY_TYPE_H

#include <fossil/unittest.h> // using assurt rules from Fossil Test
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Null pointer assertions (_CNULL)

// ITS set
#define EXCEPT_ITS_CNULL(actual) \
    TEST_EXCEPT((actual) == xnull, "Expected " #actual " to be xnull")

#define EXCEPT_NOT_CNULL(actual) \
    TEST_EXCEPT((actual) != xnull, "Expected " #actual " to not be xnull")

// General pointer assertions (_PTR)

// ITS set
#define EXCEPT_ITS_EQUAL_PTR(actual, expected) \
    TEST_EXCEPT((actual) == (expected), "Expected pointer " #actual " to be equal to pointer " #expected " ")

#define EXCEPT_NOT_EQUAL_PTR(actual, expected) \
    TEST_EXCEPT((actual) != (expected), "Expected pointer " #actual " to not be equal to pointer " #expected " ")

// Size_t assertions

// Equal
#define EXCEPT_ITS_EQUAL_SIZE(actual, expected) \
    TEST_EXCEPT((size_t)(actual) == (size_t)(expected), "Expected " #actual " to be equal to " #expected)

// Less than
#define EXCEPT_ITS_LESS_THAN_SIZE(actual, expected) \
    TEST_EXCEPT((size_t)(actual) < (size_t)(expected), "Expected " #actual " to be less than " #expected)

// More than
#define EXCEPT_ITS_MORE_THAN_SIZE(actual, expected) \
    TEST_EXCEPT((size_t)(actual) > (size_t)(expected), "Expected " #actual " to be more than " #expected)

// Less or equal
#define EXCEPT_ITS_LESS_OR_EQUAL_SIZE(actual, expected) \
    TEST_EXCEPT((size_t)(actual) <= (size_t)(expected), "Expected " #actual " to be less than or equal to " #expected)

// More or equal
#define EXCEPT_ITS_MORE_OR_EQUAL_SIZE(actual, expected) \
    TEST_EXCEPT((size_t)(actual) >= (size_t)(expected), "Expected " #actual " to be more than or equal to " #expected)

// Not equal
#define EXCEPT_NOT_EQUAL_SIZE(actual, expected) \
    TEST_EXCEPT((size_t)(actual) != (size_t)(expected), "Expected " #actual " to not be equal to " #expected)

#ifdef __cplusplus
}
#endif

#endif