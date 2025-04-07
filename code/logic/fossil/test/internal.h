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

// Color codes
#define FOSSIL_TEST_COLOR_RESET   "\033[0m"  // Reset
#define FOSSIL_TEST_COLOR_GREEN   "\033[32m" // Green
#define FOSSIL_TEST_COLOR_RED     "\033[31m" // Red
#define FOSSIL_TEST_COLOR_YELLOW  "\033[33m" // Yellow
#define FOSSIL_TEST_COLOR_BLUE    "\033[34m" // Blue
#define FOSSIL_TEST_COLOR_MAGENTA "\033[35m" // Magenta
#define FOSSIL_TEST_COLOR_CYAN    "\033[36m" // Cyan
#define FOSSIL_TEST_COLOR_WHITE   "\033[97m" // White
#define FOSSIL_TEST_COLOR_PURPLE  "\033[35m" // Purple
#define FOSSIL_TEST_COLOR_ORANGE  "\033[38;5;208m" // Orange

#define FOSSIL_TEST_ATTR_BOLD     "\033[1m"  // Bold
#define FOSSIL_TEST_ATTR_DIM      "\033[2m"  // Dim
#define FOSSIL_TEST_ATTR_UNDERLINE "\033[4m" // Underline
#define FOSSIL_TEST_ATTR_ITALIC    "\033[3m" // Italic
#define FOSSIL_TEST_ATTR_REVERSE   "\033[7m" // Reverse
#define FOSSIL_TEST_ATTR_STRIKETHROUGH "\033[9m" // Strikethrough

#include <setjmp.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    FOSSIL_TEST_FORMAT_PLAIN,    // Plain text format
    FOSSIL_TEST_FORMAT_CHART,    // Chart format
    FOSSIL_TEST_FORMAT_TABLE,    // Table format
    FOSSIL_TEST_FORMAT_MARKDOWN, // Markdown format
    FOSSIL_TEST_FORMAT_JELLYFISH // Jellyfish format
} fossil_test_format_t;

/**
 * @struct fossil_test_options_t
 * @brief Structure to hold various options for fossil testing.
 * 
 * This structure contains various flags and parameters that control the behavior of the fossil testing framework.
 * 
 * @var fossil_test_options_t::show_version
 * Flag to indicate if the version information should be displayed.
 * 
 * @var fossil_test_options_t::show_help
 * Flag to indicate if the help information should be displayed.
 * 
 * @var fossil_test_options_t::show_info
 * Flag to indicate if additional information should be displayed.
 * 
 * @var fossil_test_options_t::reverse
 * Flag to indicate if the order of tests should be reversed.
 * 
 * @var fossil_test_options_t::repeat_enabled
 * Flag to indicate if test repetition is enabled.
 * 
 * @var fossil_test_options_t::repeat_count
 * Number of times to repeat the tests if repetition is enabled.
 * 
 * @var fossil_test_options_t::shuffle_enabled
 * Flag to indicate if the tests should be shuffled.
 * 
 * @var fossil_test_options_t::dry_run
 * Flag to indicate if the tests should be run in dry-run mode (no actual execution).
 * 
 * @var fossil_test_options_t::fail_fast
 * Flag to enable fail-fast behavior, stopping test execution after the first failure.
 * 
 * @var fossil_test_options_t::quiet
 * Flag to suppress most non-essential output for minimal console logging.
 * 
 * @var fossil_test_options_t::color_output
 * Flag to enable or disable colorized output in the console.
 */
typedef struct {
    bool show_version;
    bool show_help;
    bool show_info;
    bool reverse;
    bool repeat_enabled;
    int32_t repeat_count;
    bool shuffle_enabled;
    bool dry_run;
    bool fail_fast;
    bool quiet;
    bool color_output;
    fossil_test_format_t format; // Store the format type
} fossil_test_options_t;


/**
 * @brief Prints a formatted title in the TUI with borders, centering the title
 *        and applying the appropriate colors.
 * 
 * @param env The test environment containing options, color preferences, and more.
 * @param title The title text to display.
 */
void fossil_test_tui_title(fossil_test_env_t *env, const char *title);

/**
 * @brief Prints a formatted message within a box-like structure in the TUI.
 * 
 * @param env The test environment containing options, color preferences, and more.
 * @param title The title of the message.
 * @param fmt A format string for the message.
 * @param ... Additional arguments for formatting the message.
 */
void fossil_test_tui_message(fossil_test_env_t *env, const char *title, const char *fmt, ...);

/**
 * @brief Prints a key-value widget, typically for showing status like "Repeat Mode"
 *        or "Dry Run" inside the TUI interface.
 * 
 * @param env The test environment containing options, color preferences, and more.
 * @param label The label describing the widget (e.g., "Repeat Mode").
 * @param value The value to display next to the label (e.g., "ON" or "OFF").
 */
void fossil_test_tui_widget(fossil_test_env_t *env, const char *label, const char *value);

#ifdef __cplusplus
}
#endif

#endif // FOSSIL_TEST_CORE_H
