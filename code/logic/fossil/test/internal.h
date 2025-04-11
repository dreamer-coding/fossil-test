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
#ifndef FOSSIL_TEST_CORE_H
#define FOSSIL_TEST_CORE_H

#define MAX_NAME_LENGTH 256

#include <setjmp.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <float.h>

// Define color codes for output
#define FOSSIL_TEST_COLOR_RESET       "\033[0m"
#define FOSSIL_TEST_COLOR_RED         "\033[31m"
#define FOSSIL_TEST_COLOR_GREEN       "\033[32m"
#define FOSSIL_TEST_COLOR_YELLOW      "\033[33m"
#define FOSSIL_TEST_COLOR_BLUE        "\033[34m"
#define FOSSIL_TEST_COLOR_MAGENTA     "\033[35m"
#define FOSSIL_TEST_COLOR_CYAN        "\033[36m"
#define FOSSIL_TEST_COLOR_WHITE       "\033[37m"

// Define text attributes
#define FOSSIL_TEST_ATTR_BOLD         "\033[1m"
#define FOSSIL_TEST_ATTR_UNDERLINE    "\033[4m"
#define FOSSIL_TEST_ATTR_REVERSED     "\033[7m"
#define FOSSIL_TEST_ATTR_BLINK        "\033[5m"
#define FOSSIL_TEST_ATTR_HIDDEN       "\033[8m"
#define FOSSIL_TEST_ATTR_NORMAL       "\033[22m"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    FOSSIL_TEST_FORMAT_PLAIN,
    FOSSIL_TEST_FORMAT_CI,
    FOSSIL_TEST_FORMAT_JELLYFISH
} fossil_test_format_t;

typedef enum {
    FOSSIL_TEST_SUMMARY_PLAIN,
    FOSSIL_TEST_SUMMARY_CI,
    FOSSIL_TEST_SUMMARY_JELLYFISH
} fossil_test_summary_t;

typedef enum {
    FOSSIL_TEST_MODE_PLAIN,
    FOSSIL_TEST_MODE_CI,
    FOSSIL_TEST_MODE_JELLYFISH
} fossil_test_mode_t;

typedef struct {
    // Core
    bool show_version;
    bool show_help;
    bool show_info;
    bool show_list;

    // Execution behavior
    bool reverse;
    bool shuffle_enabled;
    bool dry_run;
    bool fail_fast;
    bool step_enabled;
    bool color_output;
    bool chaos_enabled;

    // Counters & limits
    bool repeat_enabled;
    int32_t repeat_count;
    int32_t retry_count;
    int32_t parallel_threads;
    int32_t watchdog_seconds;
    int32_t seed;

    // Output config
    fossil_test_summary_t summary;     // e.g., PLAIN, CI, JELLYFISH
    fossil_test_format_t format;       // e.g., PLAIN, CI, JELLYFISH
    fossil_test_mode_t mode; // overrides both summary and format if set

    // Paths & shell
    const char *config_path;
    const char *shell_command;

    // Profile
    bool profile_enabled;

    // Cleanup / Diagnostics
    bool clean;
    bool audit;

    // Mocking
    bool mock_log_enabled;
    const char *mock_trace_symbol; // one symbol at a time (null if unused)
    bool watch_enabled;
    const char *mock_set_symbol;
    const char *mock_set_value;
    const char *mock_restore_symbol;

    // Filtering
    const char *filter_pattern;
    const char *exclude_pattern;
    const char *scenario_name;
    const char *group_name;
    const char *tag_name;
    const char *range_spec;

    // Internal control
    bool has_error;   // Used internally to detect option parse failures
} fossil_test_options_t;

/**
 * Prints a string to the output.
 *
 * @param str The string to be printed.
 */
void internal_test_puts(const char *str);

/**
 * Prints a formatted string to the output.
 *
 * @param format The format string.
 * @param ... The additional arguments to be formatted.
 */
void internal_test_printf(const char *format, ...);

/**
 * Prints a string to the output with a specified color.
 *
 * @param color The color code to be applied.
 * @param format The format string.
 * @param ... The additional arguments to be formatted.
 */
void internal_test_print_color(const char *color, const char *format, ...);

/**
 * Prints a character to the output.
 *
 * @param c The character to be printed.
 */
void internal_test_putchar(char c);

/**
 * Prints a character to the output with a specified color.
 *
 * @param c The character to be printed.
 * @param color The color code to be applied.
 */
void internal_test_putchar_color(char c, const char *color);

// Set global color output flag
void internal_test_set_color_output(bool enabled);

#ifdef __cplusplus
}
#endif

#endif // FOSSIL_TEST_CORE_H
