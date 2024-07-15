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
#include "fossil/unittest/console.h"
#include "fossil/unittest/framework.h"
#include "fossil/unittest/commands.h"
#include <stdarg.h>

static const char* FOSSIL_TEST_NAME = "Fossil Test";
static const char* FOSSIL_TEST_AUTH = "Michael Gene Brockus (Dreamer)";
static const char* FOSSIL_TEST_VERSION = "1.0.2";
static const char* FOSSIL_TEST_INFO = "Fossil Test is a next-generation unit testing/mockup framework for C/C++.";

// ==============================================================================
// Xtest internal console stream logic
// ==============================================================================

// Function to generate a random humorous comment about an empty test runner
// becuse way not add a little sillyness.
char* empty_runner_comment(void) {
    char* comments[] = { // add more to this
        "Looks like the test runner is on a coffee break!",
        "The test runner is feeling a bit empty today, like my coffee cup.",
        "The test runner is as empty as a developer's coffee mug on Monday morning.",
        "Did someone forget to load the tests? The runner seems quite empty!",
        "The test runner is as empty as a promise to write documentation.",
        "The test runner is emptier than a developer's promise to refactor code.",
        "The test runner seems to be on a diet - it's looking quite empty!",
        "Did the tests escape? The runner seems unusually empty!",
        "The test runner is as empty as a JavaScript developer's promises.",
        "The test runner seems as empty as my enthusiasm for Monday mornings.",
        "The test runner is emptier than a meeting agenda without a clear purpose.",
        "The test runner is looking as empty as a developer's patience with legacy code.",
        "The test runner is as empty as a database without any data.",
        "The test runner seems to be in stealth mode - it's quite empty!",
        "The test runner is emptier than a startup's promise of equity.",
        "The test runner is as empty as a meeting room during a free lunch seminar.",
        "The test runner is looking as empty as a developer's snack stash on Friday afternoon.",
        "The test runner seems to be as empty as a Git repository with no commits.",
        "The test runner is emptier than a developer's memory after a long debugging session.",
        "The test runner is looking as empty as a developer's inbox after vacation.",
        "The test runner is as empty as a conference room during a fire drill.",
        "The test runner seems to be as empty as a developer's coffee pot after a long night of coding.",
        "The test runner is emptier than a developer's promise to write unit tests."
    };

    int num_comments = sizeof(comments) / sizeof(comments[0]);

    srand(time(xnullptr));

    // Generate a random index
    int random_index = rand() % num_comments;

    return comments[random_index];
}

char* passing_test_comment(void) {
    char* comments[] = {
        "Success! The test passed faster than a speeding processor!",
        "Hooray! The test passed like a champ!",
        "All green! The test passed with flying colors!",
        "The test passed as smoothly as butter on a hot pancake!",
        "Great job! The test passed like a breeze on a sunny day!",
        "The test passed with more grace than a ballerina on stage!",
        "Fantastic! The test passed like it was on a mission!",
        "Woohoo! The test passed like a pro!",
        "The test passed like a well-oiled machine!",
        "Brilliant! The test passed without a hitch!",
        "The test passed like a hot knife through butter!",
        "Outstanding! The test passed like a well-orchestrated symphony!",
        "Victory! The test passed like a champion!",
        "The test passed as smoothly as a Tesla on autopilot!",
        "Amazing! The test passed like a rocket to the moon!",
        "The test passed like a marathon runner crossing the finish line!",
        "Excellent! The test passed without breaking a sweat!",
        "The test passed like a star pupil acing an exam!",
        "Spectacular! The test passed with flying colors!",
        "The test passed like a well-rehearsed play!",
        "The test passed like a breeze through an open window!",
        "The test passed like a pro on its first try!",
        "The test passed like a dream come true!"
    };

    int num_comments = sizeof(comments) / sizeof(comments[0]);

    srand(time(NULL));

    // Generate a random index
    int random_index = rand() % num_comments;

    return comments[random_index];
}

char* failure_test_comment(void) {
    char* comments[] = {
        "Oops! The test failed like a buttered cat falling from the ceiling!",
        "Yikes! The test failed harder than my New Year's resolutions!",
        "Darn it! The test failed like a paper airplane in a storm!",
        "Bummer! The test failed like a joke at a silent party!",
        "Oh no! The test failed like my diet on a cheat day!",
        "Rats! The test failed like a house of cards in a windstorm!",
        "Drat! The test failed like a deflated balloon at a party!",
        "Egads! The test failed like a bad pun in a dad joke contest!",
        "Alas! The test failed like my plans to wake up early!",
        "Shoot! The test failed like my internet connection during a crucial moment!",
        "Dang it! The test failed like a soap opera plot twist!",
        "Blast! The test failed like a lead balloon!",
        "Crud! The test failed like my attempts to avoid procrastination!",
        "Oh dear! The test failed like a misplaced semicolon!",
        "Bother! The test failed like a comedian at a serious event!",
        "Son of a gun! The test failed like a tech demo at a live presentation!",
        "Aw, shucks! The test failed like my weekend plans to relax!",
        "Fiddlesticks! The test failed like a magician's trick gone wrong!",
        "Good grief! The test failed like a server on Black Friday!",
        "Zounds! The test failed like my Wi-Fi when I need it most!",
        "Oh snap! The test failed like a toaster in the bathtub!",
        "Cripes! The test failed like a fish out of water!",
        "Dagnabbit! The test failed like a cat trying to swim!",
        "Holy moly! The test failed like a balloon in a cactus field!"
    };

    int num_comments = sizeof(comments) / sizeof(comments[0]);

    srand(time(NULL));

    // Generate a random index
    int random_index = rand() % num_comments;

    return comments[random_index];
}

// Function to generate a random tip for unit testing released tasks
// as this would servse as a handy feature and be helpful for teaching
// new developers how they can write good test cases.
char* helpful_tester_tip(void) {
    char* tips[] = {
        "Always write meaningful test names.",
        "Test both positive and negative cases.",
        "Use mocking for external dependencies.",
        "Run tests frequently during development.",
        "Ensure tests are isolated and independent.",
        "Avoid hardcoding values in test cases.",
        "Focus on testing the functionality, not the implementation.",
        "Regularly update and maintain test cases.",
        "Use code coverage tools to identify untested code.",
        "Test edge cases and boundary conditions.",
        "Keep unit tests fast and repeatable.",
        "Use setup and teardown methods when necessary.",
        "Automate the execution of tests.",
        "Review and refactor tests regularly.",
        "Write tests for both happy paths and error paths.",
        "Test for performance and scalability where applicable.",
        "Use assertions effectively to verify outcomes.",
        "Consider using property-based testing for complex logic.",
        "Document the purpose and expected run_as of each test.",
        "Collaborate with the development team to identify test cases.",
        "Prioritize and focus on critical and high-risk areas.",
        "Write tests early in the development process.",
        "Use version control for test code and test data.",
        "Ensure that tests can run in different environments.",
        "Consider the maintainability and readability of test code.",
        "Use test frameworks and libraries to simplify testing.",
        "Use test data generation tools to create test data.",
        "Use test reporting tools to track test results.",
        "Use test management tools to organize and execute tests.",
        "Use continuous integration to automate test execution."
    };

    int num_tips = sizeof(tips) / sizeof(tips[0]);

    srand(time(xnullptr));

    // Generate a random index
    int random_index = rand() % num_tips;

    return tips[random_index];
}

char *summary_message(fossil_env_t *env) {
    if (env->stats.expected_failed_count == 0 && env->stats.expected_passed_count > 0) {
        return passing_test_comment();
    } else if (env->stats.expected_failed_count > 0) {
        return failure_test_comment();
    } else {
        return empty_runner_comment();
    }
    return "No summary message available";
}

char* current_datetime(void) {
    time_t rawtime;
    struct tm* timeinfo;
    static char datetime[20];  // Buffer to hold the formatted date and time

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(datetime, sizeof(datetime), "%Y-%m-%d %H:%M:%S", timeinfo);

    char* copy = _custom_fossil_test_strdup(datetime);  // Return a dynamically allocated copy of the datetime
    if (!copy) {
        return xnullptr; // Check for memory allocation failure
    }

    char* result = _custom_fossil_test_strdup(datetime);  // Return a dynamically allocated copy of the datetime
    free(copy);  // Free the temporary copy

    return result;
}

static char* replace_underscore(const char* str) {
    if (!str) {
        return xnullptr; // Check for xnull input
    }

    char* result = _custom_fossil_test_strdup(str);
    if (!result) {
        return xnullptr; // Check for memory allocation failure
    }

    for (char* ptr = result; *ptr; ptr++) {
        if (*ptr == '_') {
            *ptr = ' ';
        }
    }

    char* copy = _custom_fossil_test_strdup(result);  // Create a copy to free the original
    free(result);  // Free the original

    return copy;
}

// Define color codes
#define COLOR_RED         "\033[1;31m"
#define COLOR_GREEN       "\033[1;32m"
#define COLOR_YELLOW      "\033[1;33m"
#define COLOR_BLUE        "\033[1;34m"
#define COLOR_BRIGHT_BLUE "\033[1;94m"
#define COLOR_DARK_BLUE   "\033[0;34m"
#define COLOR_MAGENTA     "\033[1;35m"
#define COLOR_CYAN        "\033[1;36m"
#define COLOR_WHITE       "\033[1;37m"
#define COLOR_RESET       "\033[0m"

// Define a structure to map color names to their corresponding codes
typedef struct {
    const char* name;
    const char* code;
} ColorMap;

// Custom print function with color support
void fossil_test_cout(const char* color_name, const char* format, ...) {
    static const ColorMap color_map[] = {
        {"red", COLOR_RED},
        {"green", COLOR_GREEN},
        {"yellow", COLOR_YELLOW},
        {"blue", COLOR_BLUE},
        {"bright blue", COLOR_BRIGHT_BLUE},
        {"dark blue", COLOR_DARK_BLUE},
        {"magenta", COLOR_MAGENTA},
        {"cyan", COLOR_CYAN},
        {"white", COLOR_WHITE},
        {NULL, COLOR_RESET} // Default color
    };

    va_list args;
    va_start(args, format);

    // Check if color output is enabled
    if (_CLI.color_enabled) {
        // Default color code
        const char* color_code = COLOR_RESET;

        // Find the corresponding color code
        for (int i = 0; color_map[i].name != NULL; i++) {
            if (strcmp(color_name, color_map[i].name) == 0) {
                color_code = color_map[i].code;
                break;
            }
        }

        // Print color code and formatted string
        printf("%s", color_code);
        vprintf(format, args);
        printf("%s", COLOR_RESET); // Reset color
    } else {
        // Color output disabled, print formatted string directly
        vprintf(format, args);
    }

    va_end(args);
}

// Internal function to calculate elapsed time for a test
static void calculate_elapsed_time(fossil_test_timer_t *timer) {
    timer->end = clock();
    // Calculate elapsed time
    timer->elapsed = timer->end - timer->start;

    // Convert elapsed time to different units
    timer->detail.minutes = timer->elapsed / (CLOCKS_PER_SEC * 60);
    timer->detail.seconds = (timer->elapsed / CLOCKS_PER_SEC) % 60;
    timer->detail.milliseconds = (timer->elapsed * 1000) / CLOCKS_PER_SEC;
    timer->detail.microseconds = (timer->elapsed * 1000000) / CLOCKS_PER_SEC;
    timer->detail.nanoseconds = (timer->elapsed * 1000000000) / CLOCKS_PER_SEC;
}

// Function to handle CLI information output
void fossil_test_io_information(void) {
    if (_CLI.show_version) {
        fossil_test_cout("blue", "%s\n", FOSSIL_TEST_VERSION);
        exit(0);
    } else if (_CLI.show_info) {
        fossil_test_cout("blue", "%s\n", FOSSIL_TEST_INFO);
        exit(0);
    } else if (_CLI.show_tip) {
        fossil_test_cout("blue", "%s\n", helpful_tester_tip());
        exit(0);
    } else if (_CLI.show_author) {
        fossil_test_cout("blue", "%s\n", FOSSIL_TEST_AUTH);
        exit(0);
    } else if (_CLI.show_help) {
        fossil_test_cout("blue", "Usage: fossil_test_cli [options]\n");
        fossil_test_cout("blue", "Options:\n");
        fossil_test_cout("cyan", "  --version                         Displays the version of the Fossil Test CLI\n");
        fossil_test_cout("cyan", "  --help                            Shows the help message with usage instructions\n");
        fossil_test_cout("cyan", "  --tip                             Provides a tip or hint about using the Fossil Test CLI\n");
        fossil_test_cout("cyan", "  --info                            Displays information about the test runner\n");
        fossil_test_cout("cyan", "  --author                          Shows information about the author of the test runner\n");
        fossil_test_cout("cyan", "  only=<tag> or only=<tags>         Runs only the tests tagged with the specified tag(s)\n");
        fossil_test_cout("cyan", "  reverse [enable/disable]          Enables or disables the reverse order of test execution\n");
        fossil_test_cout("cyan", "  repeat=<number>                   Repeats the test suite for the specified number of times\n");
        fossil_test_cout("cyan", "  shuffle [enable/disable]          Enables or disables the shuffling of test execution order\n");
        fossil_test_cout("cyan", "  verbose [cutback/normal/verbose]  Sets the verbosity level of the output\n");
        fossil_test_cout("cyan", "  list                              Lists all available tests\n");
        fossil_test_cout("cyan", "  summary [enable/disable]          Enables or disables the summary of test results after execution\n");
        fossil_test_cout("cyan", "  color [enable/disable]            Enables or disables colored output in the terminal\n");
        fossil_test_cout("cyan", "  sanity [enable/disable]           Enables or disables sanity checks before running the tests\n");
        exit(0);
    }
}

void fossil_test_io_sanity_load(fossil_test_t *test) {
    if (_CLI.verbose_level == 2 && _CLI.sanity_enabled) {
        fossil_test_cout("blue", "load test: ");
        fossil_test_cout("cyan", " -> id: %.4d, tag: %s, name: %s\n", _TEST_ENV.stats.untested_count + 1, test->tags, test->name);
    } else if (_CLI.verbose_level == 1 && _CLI.sanity_enabled) {
        fossil_test_cout("blue", "[loaded] test: ");
        fossil_test_cout("cyan", " -> %.4d %s\n", _TEST_ENV.stats.untested_count + 1, test->name);
    }
}

void fossil_test_io_unittest_start(fossil_test_t *test) {
    test->timer.start = clock();
    
    if (_CLI.verbose_level == 2) {
        fossil_test_cout("blue", "%s[%.4d]%s\n", "=[started case]=====================================================================",
        _TEST_ENV.stats.expected_total_count + 1, "===");
        fossil_test_cout("blue", "test name : ");
        fossil_test_cout("cyan", " -> %s\n", replace_underscore(test->name));
        fossil_test_cout("blue", "priority  : ");
        fossil_test_cout("cyan", " -> %d\n", test->priority);
        fossil_test_cout("blue", "tags      : ");
        fossil_test_cout("cyan", " -> %s\n", test->tags);
        fossil_test_cout("blue", "marker    : ");
        fossil_test_cout("cyan", " -> %s\n", test->marks);
    } else if (_CLI.verbose_level == 1) {
        fossil_test_cout("blue", "[start] ");
        fossil_test_cout("cyan", "%.4d: %s tag: %s mark: %s\n", _TEST_ENV.stats.expected_total_count + 1, replace_underscore(test->name), test->tags, test->marks);
    }
}

void fossil_test_io_unittest_given(char *description) {
    if (_CLI.verbose_level == 2) {
        fossil_test_cout("blue", "          : ");
        fossil_test_cout("magenta", "%s%s\n", "GIVEN ", description);
    }
}

void fossil_test_io_unittest_when(char *description) {
    if (_CLI.verbose_level == 2) {
        fossil_test_cout("blue", "          : ");
        fossil_test_cout("magenta", "%s%s\n", "\tWHEN ", description);
    }
}

void fossil_test_io_unittest_then(char *description) {
    if (_CLI.verbose_level == 2) {
        fossil_test_cout("blue", "          : ");
        fossil_test_cout("magenta", "%s%s\n", "\t\tTHEN ", description);
    }
}

void fossil_test_io_unittest_step(xassert_info *assume) {
    if (_CLI.verbose_level == 2) {
        fossil_test_cout("blue", "has assert  : ");
        fossil_test_cout("cyan", " -> %s\n", assume->has_assert ? COLOR_GREEN "has assertions" COLOR_RESET : COLOR_RED "missing assertions" COLOR_RESET);
        fossil_test_cout("blue", "asserts used: ");
        fossil_test_cout("cyan", COLOR_GREEN "%3i\n" COLOR_RESET , assume->num_asserts);
    } else if (_CLI.verbose_level == 1) {
        fossil_test_cout("blue", "[intro] has_assert : ");
        fossil_test_cout("cyan", "%s\n", assume->has_assert ? COLOR_GREEN "yes" COLOR_RESET : COLOR_RED "no" COLOR_RESET);
        fossil_test_cout("blue", "[intro] same_assert: ");
        fossil_test_cout("cyan", "%s\n", assume->same_assert ? COLOR_RED "yes" COLOR_RESET : COLOR_GREEN "no" COLOR_RESET);
        fossil_test_cout("blue", "[intro] num_asserts: ");
        fossil_test_cout("cyan", COLOR_GREEN "%3i\n" COLOR_RESET , assume->num_asserts);
    }
}

void fossil_test_io_unittest_ended(fossil_test_t *test) {
    calculate_elapsed_time(&test->timer);

    if (_CLI.verbose_level == 2) {
        fossil_test_cout("blue", "timestamp : ");
        fossil_test_cout("cyan", " -> %ld minutes, %ld seconds, %ld milliseconds, %ld microseconds, %ld nanoseconds\n",
            (uint32_t)test->timer.detail.minutes, (uint32_t)test->timer.detail.seconds, (uint32_t)test->timer.detail.milliseconds,
            (uint32_t)test->timer.detail.microseconds, (uint32_t)test->timer.detail.nanoseconds);
        fossil_test_cout("blue", "%s\n", "=[ ended case ]==============================================================================");
    } else if (_CLI.verbose_level == 1) {
        fossil_test_cout("blue", "[ended] time: ");
        fossil_test_cout("cyan", "%ld:%ld:%ld:%ld:%ld\n",
            (uint32_t)test->timer.detail.minutes, (uint32_t)test->timer.detail.seconds, (uint32_t)test->timer.detail.milliseconds,
            (uint32_t)test->timer.detail.microseconds, (uint32_t)test->timer.detail.nanoseconds);
    } else if (_CLI.verbose_level == 0 && !_ASSERT_INFO.should_fail) {
        fossil_test_cout("green", "[#]");
    }

    // Check for timeout
    if (test->timer.elapsed >= (2 * 60 * CLOCKS_PER_SEC)) {
        _TEST_ENV.rule.timeout = true;
    }
}

void fossil_test_io_asserted(xassert_info *assume) {
    if (_CLI.verbose_level == 2) {
        fossil_test_cout("red", "=[F]=[assertion failed]======================================================================\n");
        fossil_test_cout("red", "message  : -> %s\n", assume->message);
        fossil_test_cout("red", "file name: -> %s\n", assume->file);
        fossil_test_cout("red", "line num : -> %d\n", assume->line);
        fossil_test_cout("red", "function : -> %s\n", assume->func);
        fossil_test_cout("red", "=========================================================================================[F]=\n");
    } else if (_CLI.verbose_level == 1) {
        fossil_test_cout("red", "name: %s line: -> %d msg: -> %s\n", assume->func, assume->line, assume->message);
    } else {
        fossil_test_cout("red", "[#]");
    }
}

void fossil_test_io_summary_start(void) {
    fossil_test_cout("blue", "=============================================================================================\n");
    fossil_test_cout("blue", "%s\n", "platform meta data about the host system:");
    fossil_test_cout("blue", "endian(%6s) cpus(%2i) memory(%4i) os(%s) arch(%s)\n",
    _fossil_test_assert_is_big_endian() ? "big" : "little", _fossil_test_get_num_cpus(), _fossil_test_get_memory_size(), _fossil_test_get_os_name(), _fossil_test_get_architecture());
    fossil_test_cout("blue", "=============================================================================================\n");
}

void fossil_test_io_summary_ended(void) {
    char *color = "green";
    if (_TEST_ENV.stats.expected_failed_count > 0) {
        color = "red";
    } else if (_TEST_ENV.stats.expected_passed_count == 0) {
        color = "yellow";
    }

    fossil_test_cout("blue", "\n%s %s: %s\n\n", FOSSIL_TEST_NAME, FOSSIL_TEST_VERSION, FOSSIL_TEST_INFO);
    fossil_test_cout("blue", "=============================================================================================\n");
    fossil_test_cout("blue", "%s", " message: ");
    fossil_test_cout(color, "%s\n", summary_message(&_TEST_ENV));
    fossil_test_cout("cyan", "> Expected Passed  : %3d   Expected Failed: %3d\n", _TEST_ENV.stats.expected_passed_count, _TEST_ENV.stats.expected_failed_count);
    fossil_test_cout("cyan", "> Unexpected Passed: %3d Unexpected Failed: %3d\n", _TEST_ENV.stats.unexpected_passed_count, _TEST_ENV.stats.expected_failed_count);
    fossil_test_cout("cyan", "> Timeout: %3d Skipped: %3d Empty: %3d\n", _TEST_ENV.stats.expected_timeout_count, _TEST_ENV.stats.expected_skipped_count, _TEST_ENV.stats.expected_empty_count);
    fossil_test_cout("blue", "=============================================================================================\n");
    fossil_test_cout("blue", "Total Tests: %d\n", _TEST_ENV.stats.expected_total_count);
    fossil_test_cout("blue", "Total Ghost: %d\n", _TEST_ENV.stats.untested_count);
    fossil_test_cout("blue", "=============================================================================================\n");
    calculate_elapsed_time(&_TEST_ENV.timer);
    fossil_test_cout("yellow", "timestamp : -> %ld minutes, %ld seconds, %ld milliseconds, %ld microseconds, %ld nanoseconds\n",
           (uint32_t)_TEST_ENV.timer.detail.minutes, (uint32_t)_TEST_ENV.timer.detail.seconds, (uint32_t)_TEST_ENV.timer.detail.milliseconds,
           (uint32_t)_TEST_ENV.timer.detail.microseconds, (uint32_t)_TEST_ENV.timer.detail.nanoseconds);
}
