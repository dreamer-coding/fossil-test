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
#include "fossil/unittest/commands.h"
#include "fossil/unittest/internal.h"
#include <stdio.h>
#include <stdlib.h>

fossil_test_command_t commands[] = {
    {"Display this help message", "--help", "-h", NULL, 1},
    {"Display program version", "--version", "-v", NULL, 1},
    {"Display a helpful tip", "--tip", "-t", NULL, 1},
    {"Set IO mode for runner ('human'/cutback/turbo)", "--console", "-c", (char*[]){"human", "cutback", "turbo", NULL}, 0},
    {"Set priority threshold for test cases (1-100)", "--priority", "-p", NULL, 0},
    {"Set a given repeat for a number of times (1-100)", "--repeat", "-r", NULL, 0},
    {"Enable colored output", "--color", "-c", NULL, 1},
    {"Do a simple pass of the test runner to ensure it works", "--dry-run", NULL, 1}
};

void fossil_test_cli_parse(int argc, char *argv[], fossil_test_command_t *commands) {
    size_t command_count = sizeof(commands) / sizeof(commands[0]);
    if (argc < 2) {
        fossil_test_cli_show_help(commands);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        bool command_found = false;
        for (int j = 0; j < command_count; j++) {
            if (strcmp(argv[i], commands[j].long_name) == 0 || strcmp(argv[i], commands[j].short_name) == 0) {
                command_found = true;
                if (commands[j].flag) {
                    fossil_test_cli_handle_command(&commands[j], NULL);
                } else {
                    if (i + 1 < argc) {
                        fossil_test_cli_handle_command(&commands[j], argv[++i]);
                    } else {
                        fprintf(stderr, "Error: Command '%s' requires an argument.\n", argv[i]);
                        exit(EXIT_FAILURE);
                    }
                }
                break;
            }
        }
        if (!command_found) {
            fprintf(stderr, "Error: Unknown command '%s'.\n", argv[i]);
            fossil_test_cli_show_help(commands);
            exit(EXIT_FAILURE);
        }
    }
}

void fossil_test_cli_show_help(fossil_test_command_t *commands) {
    size_t command_count = sizeof(commands) / sizeof(commands[0]);
    xconsole_out("blue", "Usage: Fossil Runner [options] %s\n", current_datetime());
    xconsole_out("blue", "Options: ");
    xconsole_out("yellow",   "{help,version,tip,console,priority,color,dry-run,repeat}\n\n");
    
    for (int i = 0; i < command_count; i++) {
        const char *color = (i % 2 == 0) ? "bright blue" : "dark blue";
        xconsole_out(color, "\t%s, %s : %s :\n", commands[i].short_name, commands[i].long_name, commands[i].description);
    }
}

void fossil_test_cli_handle_command(fossil_test_command_t *command, char *arg) {
    if (strcmp(command->long_name, "--help") == 0) {
        fossil_test_cli_show_help(commands);
    } else if (strcmp(command->long_name, "--version") == 0) {
        printf("Fossil Test CLI version 1.0.0\n");
    } else if (strcmp(command->long_name, "--tip") == 0) {
        printf("Tip: Always write tests for your code.\n");
    } else if (strcmp(command->long_name, "--console") == 0) {
        if (arg) {
            bool valid_arg = false;
            for (char **valid = command->valid_args; *valid != NULL; valid++) {
                if (strcmp(arg, *valid) == 0) {
                    valid_arg = true;
                    break;
                }
            }
            if (valid_arg) {
                printf("Setting console mode to: %s\n", arg);
            } else {
                fprintf(stderr, "Error: Invalid argument '%s' for --console. Valid arguments are: ", arg);
                for (char **valid = command->valid_args; *valid != NULL; valid++) {
                    printf("%s ", *valid);
                }
                printf("\n");
                exit(EXIT_FAILURE);
            }
        } else {
            fprintf(stderr, "Error: --console requires an argument.\n");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(command->long_name, "--priority") == 0) {
        if (arg) {
            int priority = atoi(arg);
            if (priority >= 1 && priority <= 100) {
                printf("Setting priority to: %d\n", priority);
            } else {
                fprintf(stderr, "Error: Invalid priority '%s'. Must be between 1 and 100.\n", arg);
                exit(EXIT_FAILURE);
            }
        } else {
            fprintf(stderr, "Error: --priority requires an argument.\n");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(command->long_name, "--repeat") == 0) {
        if (arg) {
            int repeat = atoi(arg);
            if (repeat >= 1 && repeat <= 100) {
                printf("Repeating %d times.\n", repeat);
            } else {
                fprintf(stderr, "Error: Invalid repeat count '%s'. Must be between 1 and 100.\n", arg);
                exit(EXIT_FAILURE);
            }
        } else {
            fprintf(stderr, "Error: --repeat requires an argument.\n");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(command->long_name, "--color") == 0) {
        printf("Colored output enabled.\n");
    } else if (strcmp(command->long_name, "--dry-run") == 0) {
        printf("Performing dry run of the test runner.\n");
    } else {
        fprintf(stderr, "Error: Unhandled command '%s'.\n", command->long_name);
        exit(EXIT_FAILURE);
    }
}