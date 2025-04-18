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
#include "fossil/test/internal.h"

#define FOSSIL_TEST_BUFFER_SIZE 1000

static bool internal_test_color_enabled = true;

// Function to apply color
void internal_test_apply_color(const char *color) {
    if (strcmp(color, "red") == 0) {
        printf(FOSSIL_TEST_COLOR_RED);
    } else if (strcmp(color, "green") == 0) {
        printf(FOSSIL_TEST_COLOR_GREEN);
    } else if (strcmp(color, "yellow") == 0) {
        printf(FOSSIL_TEST_COLOR_YELLOW);
    } else if (strcmp(color, "blue") == 0) {
        printf(FOSSIL_TEST_COLOR_BLUE);
    } else if (strcmp(color, "magenta") == 0) {
        printf(FOSSIL_TEST_COLOR_MAGENTA);
    } else if (strcmp(color, "cyan") == 0) {
        printf(FOSSIL_TEST_COLOR_CYAN);
    } else if (strcmp(color, "white") == 0) {
        printf(FOSSIL_TEST_COLOR_WHITE);
    }
}

// Function to apply text attributes (e.g., bold, underline)
void internal_test_apply_attribute(const char *attribute) {
    if (strcmp(attribute, "bold") == 0) {
        printf(FOSSIL_TEST_ATTR_BOLD);
    } else if (strcmp(attribute, "underline") == 0) {
        printf(FOSSIL_TEST_ATTR_UNDERLINE);
    } else if (strcmp(attribute, "reset") == 0) {
        printf(FOSSIL_TEST_COLOR_RESET);
    } else if (strcmp(attribute, "normal") == 0) {
        printf(FOSSIL_TEST_ATTR_NORMAL);
    } else if (strcmp(attribute, "reversed") == 0) {
        printf(FOSSIL_TEST_ATTR_REVERSED);
    } else if (strcmp(attribute, "blink") == 0) {
        printf(FOSSIL_TEST_ATTR_BLINK);
    } else if (strcmp(attribute, "hidden") == 0) {
        printf(FOSSIL_TEST_ATTR_HIDDEN);
    }
}

// Function to print text with attributes, colors, and format specifiers
void internal_test_print_with_attributes(const char *format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[FOSSIL_TEST_BUFFER_SIZE];
    vsnprintf(buffer, sizeof(buffer), format, args);

    const char *current_pos = buffer;
    const char *start = NULL;
    const char *end = NULL;

    while ((start = strchr(current_pos, '{')) != NULL) {
        printf("%.*s", (int)(start - current_pos), current_pos);
        end = strchr(start, '}');
        if (end) {
            size_t length = end - start - 1;
            char attributes[length + 1];
            strncpy(attributes, start + 1, length);
            attributes[length] = '\0';

            char *color = NULL;
            char *attribute = NULL;
            char *comma_pos = strchr(attributes, ',');
            if (comma_pos) {
                *comma_pos = '\0';
                color = attributes;
                attribute = comma_pos + 1;
            } else {
                color = attributes;
            }

            if (color) internal_test_apply_color(color);
            if (attribute) internal_test_apply_attribute(attribute);

            current_pos = end + 1;
        } else {
            break;
        }
    }

    printf("%s", current_pos);
    va_end(args);
}

// Setter to initialize color flag from options
void internal_test_set_color_output(bool enabled) {
    internal_test_color_enabled = enabled;
}

// Internal utility function for color printing
void internal_test_print_color(const char *color, const char *format, ...) {
    va_list args;
    va_start(args, format);
    if (internal_test_color_enabled) {
        printf("%s", color);
        vprintf(format, args);
        printf("%s", FOSSIL_TEST_COLOR_RESET);
    } else {
        vprintf(format, args);
    }
    va_end(args);
}

// Function to print a sanitized string with attributes inside {}
void internal_test_puts(const char *str) {
    if (str != NULL) {
        char sanitized_str[FOSSIL_TEST_BUFFER_SIZE];
        strncpy(sanitized_str, str, sizeof(sanitized_str));
        sanitized_str[sizeof(sanitized_str) - 1] = '\0';
        internal_test_print_with_attributes(sanitized_str);
    } else {
        fputs("NULL\n", stderr);
    }
}

// Function to print a single character
void internal_test_putchar(char c) {
    putchar(c);
}

// Function to print a single character in color
void internal_test_putchar_color(char c, const char *color) {
    if (internal_test_color_enabled) {
        printf("%s%c%s", color, c, FOSSIL_TEST_COLOR_RESET);
    } else {
        putchar(c);
    }
}

// Function to print sanitized formatted output with attributes
void internal_test_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[FOSSIL_TEST_BUFFER_SIZE];
    vsnprintf(buffer, sizeof(buffer), format, args);

    if (internal_test_color_enabled) {
        internal_test_print_with_attributes(buffer);
    } else {
        // Strip color tags before printing
        for (char *p = buffer; *p;) {
            if (*p == '{') {
                // Skip until closing '}'
                while (*p && *p != '}') p++;
                if (*p == '}') p++;
            } else {
                putchar(*p++);
            }
        }
    }

    va_end(args);
}
