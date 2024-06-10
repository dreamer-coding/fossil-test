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
#ifndef FOSSIL_TEST_EXCEPT_FLOAT_TYPE_H
#define FOSSIL_TEST_EXCEPT_FLOAT_TYPE_H

#include <fossil/unittest.h> // using assurt rules from Fossil Test
#include <math.h>
#include <float.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Double equality check with tolerance
#define EXCEPT_ITS_EQUAL_F64(actual, expected, tol) \
    TEST_EXCEPT(fabs((actual) - (expected)) <= (tol), "Expected " #actual " to be equal to " #expected " within tolerance " #tol)

#define EXCEPT_ITS_LESS_THAN_F64(actual, expected) \
    TEST_EXCEPT((actual) < (expected), "Expected " #actual " to be less than " #expected)

#define EXCEPT_ITS_MORE_THAN_F64(actual, expected) \
    TEST_EXCEPT((actual) > (expected), "Expected " #actual " to be more than " #expected)

#define EXCEPT_ITS_LESS_OR_EQUAL_F64(actual, expected) \
    TEST_EXCEPT((actual) <= (expected), "Expected " #actual " to be less than or equal to " #expected)

#define EXCEPT_ITS_MORE_OR_EQUAL_F64(actual, expected) \
    TEST_EXCEPT((actual) >= (expected), "Expected " #actual " to be more than or equal to " #expected)

#define EXCEPT_NOT_EQUAL_F64(actual, expected, tol) \
    TEST_EXCEPT(fabs((actual) - (expected)) > (tol), "Expected " #actual " to not be equal to " #expected " within tolerance " #tol)

#define EXCEPT_NOT_LESS_THAN_F64(actual, expected) \
    TEST_EXCEPT((actual) >= (expected), "Expected " #actual " to not be less than " #expected)

#define EXCEPT_NOT_MORE_THAN_F64(actual, expected) \
    TEST_EXCEPT((actual) <= (expected), "Expected " #actual " to not be more than " #expected)

#define EXCEPT_NOT_LESS_OR_EQUAL_F64(actual, expected) \
    TEST_EXCEPT((actual) > (expected), "Expected " #actual " to not be less than or equal to " #expected)

#define EXCEPT_NOT_MORE_OR_EQUAL_F64(actual, expected) \
    TEST_EXCEPT((actual) < (expected), "Expected " #actual " to not be more than or equal to " #expected)

// Float equality check with tolerance
#define EXCEPT_ITS_EQUAL_F32(actual, expected, tol) \
    TEST_EXCEPT(fabsf((actual) - (expected)) <= (tol), "Expected " #actual " to be equal to " #expected " within tolerance " #tol)

#define EXCEPT_ITS_LESS_THAN_F32(actual, expected) \
    TEST_EXCEPT((actual) < (expected), "Expected " #actual " to be less than " #expected)

#define EXCEPT_ITS_MORE_THAN_F32(actual, expected) \
    TEST_EXCEPT((actual) > (expected), "Expected " #actual " to be more than " #expected)

#define EXCEPT_ITS_LESS_OR_EQUAL_F32(actual, expected) \
    TEST_EXCEPT((actual) <= (expected), "Expected " #actual " to be less than or equal to " #expected)

#define EXCEPT_ITS_MORE_OR_EQUAL_F32(actual, expected) \
    TEST_EXCEPT((actual) >= (expected), "Expected " #actual " to be more than or equal to " #expected)

#define EXCEPT_NOT_EQUAL_F32(actual, expected, tol) \
    TEST_EXCEPT(fabsf((actual) - (expected)) > (tol), "Expected " #actual " to not be equal to " #expected " within tolerance " #tol)

#define EXCEPT_NOT_LESS_THAN_F32(actual, expected) \
    TEST_EXCEPT((actual) >= (expected), "Expected " #actual " to not be less than " #expected)

#define EXCEPT_NOT_MORE_THAN_F32(actual, expected) \
    TEST_EXCEPT((actual) <= (expected), "Expected " #actual " to not be more than " #expected)

#define EXCEPT_NOT_LESS_OR_EQUAL_F32(actual, expected) \
    TEST_EXCEPT((actual) > (expected), "Expected " #actual " to not be less than or equal to " #expected)

#define EXCEPT_NOT_MORE_OR_EQUAL_F32(actual, expected) \
    TEST_EXCEPT((actual) < (expected), "Expected " #actual " to not be more than or equal to " #expected)

// Float NaN and Infinity checks
#define EXCEPT_ITS_NAN_F32(actual) \
    TEST_EXCEPT(isnan(actual), "Expected " #actual " to be NaN")

#define EXCEPT_ITS_INF_F32(actual) \
    TEST_EXCEPT(isinf(actual), "Expected " #actual " to be infinity")

// Double NaN and Infinity checks
#define EXCEPT_ITS_NAN_F64(actual) \
    TEST_EXCEPT(isnan(actual), "Expected " #actual " to be NaN")

#define EXCEPT_ITS_INF_F64(actual) \
    TEST_EXCEPT(isinf(actual), "Expected " #actual " to be infinity")

#ifdef __cplusplus
}
#endif

#endif
