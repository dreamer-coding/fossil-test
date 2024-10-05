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
#ifndef FOSSIL_TEST_ASSERT_MEMORY_TYPE_H
#define FOSSIL_TEST_ASSERT_MEMORY_TYPE_H

#include <fossil/unittest/framework.h> // using assurt rules from Fossil Test
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Null pointer assertions (_CNULL)

// ITS set
#define ASSERT_ITS_CNULL(actual) \
    TEST_ASSERT((actual) == xnull, "Expected " #actual " to be xnull")

#define ASSERT_NOT_CNULL(actual) \
    TEST_ASSERT((actual) != xnull, "Expected " #actual " to not be xnull")

// General pointer assertions (_PTR)

// ITS set
#define ASSERT_ITS_EQUAL_PTR(actual, expected) \
    TEST_ASSERT((actual) == (expected), "Expected pointer " #actual " to be equal to pointer " #expected " ")

#define ASSERT_NOT_EQUAL_PTR(actual, expected) \
    TEST_ASSERT((actual) != (expected), "Expected pointer " #actual " to not be equal to pointer " #expected " ")

// Size_t assertions

// Equal
#define ASSERT_ITS_EQUAL_SIZE(actual, expected) \
    TEST_ASSERT((size_t)(actual) == (size_t)(expected), "Expected " #actual " to be equal to " #expected)

// Less than
#define ASSERT_ITS_LESS_THAN_SIZE(actual, expected) \
    TEST_ASSERT((size_t)(actual) < (size_t)(expected), "Expected " #actual " to be less than " #expected)

// More than
#define ASSERT_ITS_MORE_THAN_SIZE(actual, expected) \
    TEST_ASSERT((size_t)(actual) > (size_t)(expected), "Expected " #actual " to be more than " #expected)

// Less or equal
#define ASSERT_ITS_LESS_OR_EQUAL_SIZE(actual, expected) \
    TEST_ASSERT((size_t)(actual) <= (size_t)(expected), "Expected " #actual " to be less than or equal to " #expected)

// More or equal
#define ASSERT_ITS_MORE_OR_EQUAL_SIZE(actual, expected) \
    TEST_ASSERT((size_t)(actual) >= (size_t)(expected), "Expected " #actual " to be more than or equal to " #expected)

// Not equal
#define ASSERT_NOT_EQUAL_SIZE(actual, expected) \
    TEST_ASSERT((size_t)(actual) != (size_t)(expected), "Expected " #actual " to not be equal to " #expected)

#ifdef __cplusplus
}
#endif

#endif
