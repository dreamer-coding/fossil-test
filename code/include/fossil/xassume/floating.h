/*
 * -----------------------------------------------------------------------------
 * Project: Fossil Logic
 *
 * This file is part of the Fossil Logic project, which aims to develop high-
 * performance, cross-platform applications and libraries. The code contained
 * herein is subject to the terms and conditions defined in the project license.
 *
 * Author: Michael Gene Brockus (Dreamer)
 * Date: 07/01/2024
 *
 * Copyright (C) 2024 Fossil Logic. All rights reserved.
 * -----------------------------------------------------------------------------
 */
#ifndef FOSSIL_TEST_ASSUME_FLOAT_TYPE_H
#define FOSSIL_TEST_ASSUME_FLOAT_TYPE_H

#include <fossil/unittest/framework.h> // using assurt rules from Fossil Test
#include <math.h>
#include <float.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Double equality check with tolerance
#define ASSUME_ITS_EQUAL_F64(actual, expected, tol) \
    TEST_ASSUME(fabs((actual) - (expected)) <= (tol), "Expected " #actual " to be equal to " #expected " within tolerance " #tol)

#define ASSUME_ITS_LESS_THAN_F64(actual, expected) \
    TEST_ASSUME((actual) < (expected), "Expected " #actual " to be less than " #expected)

#define ASSUME_ITS_MORE_THAN_F64(actual, expected) \
    TEST_ASSUME((actual) > (expected), "Expected " #actual " to be more than " #expected)

#define ASSUME_ITS_LESS_OR_EQUAL_F64(actual, expected) \
    TEST_ASSUME((actual) <= (expected), "Expected " #actual " to be less than or equal to " #expected)

#define ASSUME_ITS_MORE_OR_EQUAL_F64(actual, expected) \
    TEST_ASSUME((actual) >= (expected), "Expected " #actual " to be more than or equal to " #expected)

#define ASSUME_NOT_EQUAL_F64(actual, expected, tol) \
    TEST_ASSUME(fabs((actual) - (expected)) > (tol), "Expected " #actual " to not be equal to " #expected " within tolerance " #tol)

#define ASSUME_NOT_LESS_THAN_F64(actual, expected) \
    TEST_ASSUME((actual) >= (expected), "Expected " #actual " to not be less than " #expected)

#define ASSUME_NOT_MORE_THAN_F64(actual, expected) \
    TEST_ASSUME((actual) <= (expected), "Expected " #actual " to not be more than " #expected)

#define ASSUME_NOT_LESS_OR_EQUAL_F64(actual, expected) \
    TEST_ASSUME((actual) > (expected), "Expected " #actual " to not be less than or equal to " #expected)

#define ASSUME_NOT_MORE_OR_EQUAL_F64(actual, expected) \
    TEST_ASSUME((actual) < (expected), "Expected " #actual " to not be more than or equal to " #expected)

// Float equality check with tolerance
#define ASSUME_ITS_EQUAL_F32(actual, expected, tol) \
    TEST_ASSUME(fabsf((actual) - (expected)) <= (tol), "Expected " #actual " to be equal to " #expected " within tolerance " #tol)

#define ASSUME_ITS_LESS_THAN_F32(actual, expected) \
    TEST_ASSUME((actual) < (expected), "Expected " #actual " to be less than " #expected)

#define ASSUME_ITS_MORE_THAN_F32(actual, expected) \
    TEST_ASSUME((actual) > (expected), "Expected " #actual " to be more than " #expected)

#define ASSUME_ITS_LESS_OR_EQUAL_F32(actual, expected) \
    TEST_ASSUME((actual) <= (expected), "Expected " #actual " to be less than or equal to " #expected)

#define ASSUME_ITS_MORE_OR_EQUAL_F32(actual, expected) \
    TEST_ASSUME((actual) >= (expected), "Expected " #actual " to be more than or equal to " #expected)

#define ASSUME_NOT_EQUAL_F32(actual, expected, tol) \
    TEST_ASSUME(fabsf((actual) - (expected)) > (tol), "Expected " #actual " to not be equal to " #expected " within tolerance " #tol)

#define ASSUME_NOT_LESS_THAN_F32(actual, expected) \
    TEST_ASSUME((actual) >= (expected), "Expected " #actual " to not be less than " #expected)

#define ASSUME_NOT_MORE_THAN_F32(actual, expected) \
    TEST_ASSUME((actual) <= (expected), "Expected " #actual " to not be more than " #expected)

#define ASSUME_NOT_LESS_OR_EQUAL_F32(actual, expected) \
    TEST_ASSUME((actual) > (expected), "Expected " #actual " to not be less than or equal to " #expected)

#define ASSUME_NOT_MORE_OR_EQUAL_F32(actual, expected) \
    TEST_ASSUME((actual) < (expected), "Expected " #actual " to not be more than or equal to " #expected)

// Float NaN and Infinity checks
#define ASSUME_ITS_NAN_F32(actual) \
    TEST_ASSUME(isnan(actual), "Expected " #actual " to be NaN")

#define ASSUME_ITS_INF_F32(actual) \
    TEST_ASSUME(isinf(actual), "Expected " #actual " to be infinity")

// Double NaN and Infinity checks
#define ASSUME_ITS_NAN_F64(actual) \
    TEST_ASSUME(isnan(actual), "Expected " #actual " to be NaN")

#define ASSUME_ITS_INF_F64(actual) \
    TEST_ASSUME(isinf(actual), "Expected " #actual " to be infinity")

#ifdef __cplusplus
}
#endif

#endif
