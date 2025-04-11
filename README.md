# ***Fossil Test by Fossil Logic***

**Fossil Test** is a powerful and flexible unit testing, mocking, and benchmarking suite developed by Fossil Logic to ensure the reliability, clarity, and performance of **C**, **C++**, and **Python** projects. Supporting multiple development methodologies—including Behavior-Driven Development (BDD), Domain-Driven Design (DDD), and Test-Driven Development (TDD)—Fossil Test offers a versatile foundation for building high-quality, maintainable test suites across diverse workflows. Starting with version 1.1.8, it integrates **Jellyfish AI**, an intelligent system designed to apply AI where it makes sense—enhancing test coverage insights, feedback clarity, and overall developer experience.

The Fossil suite consists of three complementary frameworks to streamline the development and testing process:

- **Fossil Test**: The core unit testing framework that enables developers to create, manage, and execute unit tests effectively, ensuring each component functions as expected.
- **Fossil Mock**: A dedicated mocking library that simulates complex dependencies. Using mock objects, developers can isolate and thoroughly test individual components, improving the precision and reliability of test coverage.
- **Fossil Mark**: A benchmarking tool that provides detailed performance insights by measuring execution time, identifying bottlenecks, and offering in-depth reporting to optimize code efficiency.

Together, **Fossil Test**, **Fossil Mock**, and **Fossil Mark** — now supercharged with **Jellyfish AI** — offer a powerful, integrated toolkit for developing, testing, and optimizing robust software, making them an essential asset for developers committed to quality and performance.

---

## **Key Features**

| Feature                     | Description                                                                                                                             |
|-----------------------------|-----------------------------------------------------------------------------------------------------------------------------------------|
| **Jellyfish AI Integration** | Intelligent assistant for analyzing test coverage, diagnostics, and improving test clarity (available from v1.1.8 onward).               |
| **BDD, DDD, and TDD Support** | Supports Behavior-Driven, Domain-Driven, and Test-Driven Development styles, catering to various project methodologies.                    |
| **Comprehensive Unit Testing** | A full suite of tools for creating, managing, and executing unit tests, ensuring that individual units of code behave as expected.         |
| **Mocking Capabilities**    | Powerful mocking features allow developers to simulate complex dependencies, ensuring focused and reliable unit tests.                 |
| **Performance Tracking**    | Measures and reports the performance of each test case, helping developers optimize test execution time and performance.                 |
| **Command-Line Interface (CLI)** | A powerful CLI for running tests, generating reports, and managing the test suite, supporting automation and integration workflows.    |

---

*Note: Jellyfish AI is developed as part of the Fossil Logic ecosystem and is tightly integrated with Fossil Test to offer non-intrusive, intelligent guidance throughout the testing process.*

---

## ***Prerequisites***

To get started with Fossil Test, ensure you have the following installed:

- **Meson Build System**: If you don’t have Meson installed, follow the installation instructions on the official [Meson website](https://mesonbuild.com/Getting-meson.html).

---

### Adding Fossil Test Dependency

#### Adding Fossil Test Dependency With Meson

1. **Install Meson Build System**:
   Install Meson version `1.3` or newer:
   ```sh
   python -m pip install meson           # To install Meson
   python -m pip install --upgrade meson # To upgrade Meson
   ```

2. **Create a `.wrap` File**:
   Add the `fossil-test.wrap` file in your `subprojects` directory and include the following content:

   ```ini
   # ======================
   # Git Wrap package definition
   # ======================
   [wrap-git]
   url = https://github.com/fossillogic/fossil-test.git
   revision = v1.2.0

   [provide]
   fossil-test = fossil_test_dep
   ```

3. **Integrate the Dependency**:
   In your `meson.build` file, integrate Fossil Test by adding the following line:
   ```ini
   dep = dependency('fossil-test')
   ```

---

**Note**: For the best experience, always use the latest release of Fossil Test. Visit the [Fossil Test Releases](https://github.com/fossillogic/fossil-test/releases) page for the latest versions.

## Fossil Test CLI Usage

The Fossil Test CLI provides an efficient way to run and manage tests directly from the terminal. Here are the available commands and options:

### 🧪 Fossil Test CLI Commands

| Command / Option                 | Description                                                                                   | Notes                                                                                         | Scope    |
|----------------------------------|-----------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------|----------|
| `--help`                         | Shows help message with usage instructions.                                                   | Provides a quick reference for all available commands.                                        | core     |
| `--list`                         | Lists all available tests without running them.                                               | Useful for documentation or CI dry runs.                                                      | core     |
| `--version`                      | Displays the current version.                                                                 | Useful for verifying the version of the tool in use.                                          | core     |

---

| Command / Option                 | Description                                                                                   | Notes                                                                                         | Scope    |
|----------------------------------|-----------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------|----------|
| `--info`                         | Displays detailed information about the test run.                                             | Includes information such as test count, duration, and configuration.                         | test     |
| `--watch`                        | Watches the test directory and reruns tests on file changes.                                  | Ideal for test-driven development (TDD).                                                      | test     |
| `--config <path>`                | Loads a specific config file for test settings.                                               | Useful for environment-specific settings.                                                     | test     |
| `--seed <number>`                | Sets the random seed for shuffling.                                                           | Enables deterministic shuffling for debug repeatability.                                      | test     |
| `reverse [enable/disable]`       | Enables or disables reverse order of test execution.                                          | Useful for debugging or ensuring the tests don't depend on execution order.                   | test     |
| `shuffle [enable/disable]`       | Enables or disables shuffling of test execution order.                                        | Helps identify order-dependent issues in the test suite.                                      | test     |
| `dry-run [enable/disable]`       | Enables dry run mode, showing which tests will execute without running them.                  | Ideal for verifying test selection criteria before actual execution.                          | test     |
| `repeat <number>`                | Repeats the test suite a specified number of times.                                           | Handy for stress-testing or reproducing intermittent failures.                                | test     |
| `color [enable/disable]`         | Enables or disables colored output.                                                           | Enhances readability in supported terminals.                                                  | test     |
| `format <plain, ci, jellyfish>`  | Selects the output format for test results.                                                   | Affects how test data is displayed; useful for visual or machine-parsed output.               | test     |
| `summary <plain, ci, jellyfish>` | Sets the level of summary output after test execution.                                        | `ci` is minimal, `jellyfish` is smart test mode, and `plain` is default classic.              | test     |
| `fail-fast [enable/disable]`     | Stops test execution after the first failure.                                                 | Reduces noise and speeds up feedback loops.                                                   | test     |
| `parallel <threads>`             | Runs tests in parallel using the specified number of threads.                                 | Increases speed on multicore systems.                                                         | test     |
| `profile [enable/disable]`       | Profiles memory and CPU usage per test.                                                       | Helpful for performance tuning.                                                               | test     |
| `shell <command>`                | Runs a shell command before or after tests.                                                   | Good for setup/teardown hooks or notifications.                                               | test     |
| `step [enable/disable]`          | Pauses between tests and waits for confirmation to proceed.                                   | Good for live debugging or teaching.                                                          | test     |
| `watchdog <seconds>`             | Kills any test that exceeds this global timeout.                                              | Backup to per-test `timeout`.                                                                 | test     |
| `retry <count>`                  | Automatically retries failed tests up to `<count>` times.                                     | Can catch flaky tests for diagnostics.                                                        | test     |
| `clean`                          | Deletes test artifacts, cache, or temporary files.                                            | Useful in combination with `--dry-run` or `--export`.                                         | test     |
| `audit`                          | Verifies the health, performance, and structure of the test suite.                            | Could include naming, duration, and coverage checks.                                          | test     |

---

| Command / Option                 | Description                                                                                   | Notes                                                                                         | Scope    |
|----------------------------------|-----------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------|----------|
| `chaos [enable/disable]`         | Introduces controlled randomness to I/O, delays, etc.                                         | Good for stress-testing or chaos engineering.                                                 | mock     |
| `mock-set <symbol> <value>`      | Defines a mock value or return for a specific symbol/function.                                | Used in unit tests where controlled behavior is needed.                                       | mock     |
| `mock-restore <symbol>`          | Restores original behavior for a previously mocked symbol.                                    | Useful for cleaning up after a test.                                                          | mock     |
| `mock-log [enable/disable]`      | Enables logging of all mock calls and arguments.                                              | Great for diagnosing what mocks were hit.                                                     | mock     |
| `mock-trace <symbol>`            | Traces calls and arguments to a particular mock.                                              | Used for deep debugging or learning code behavior.                                            | mock     |

---

| Command / Option                 | Description                                                                                   | Notes                                                                                         | Scope    |
|----------------------------------|-----------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------|----------|
| `filter <pattern>`               | Runs only tests matching a given name or pattern.                                             | Supports regex or glob for selective testing.                                                 | mark     |
| `scenario <name>`                | Runs a predefined test scenario or test plan.                                                 | Supports scripting and composite test plans.                                                  | mark     |
| `groups <groupname>`            | Runs all tests in a named group.                                                              | Test grouping mechanism similar to tags, but structured.                                      | mark     |
| `tag <name>`                     | Runs only tests marked with a given tag.                                                      | Similar to `groups`, but supports multiple tags per test.                                     | mark     |
| `exclude <pattern>`             | Skips tests matching a given name or pattern.                                                 | Inverse of `filter`, for ignoring flaky or irrelevant tests.                                  | mark     |
| `range <start>..<end>`           | Runs only tests in a named or numbered range.                                                 | Useful for partial test runs or test set bisection.                                           | mark     |

## Configure Build Options

To configure the build system with testing enabled, use the following command:

```sh
meson setup builddir -Dwith_test=enabled
```

---

## ***Contributing and Support***

If you would like to contribute, have questions, or need help, feel free to open an issue on the [Fossil Test GitHub repository](https://github.com/fossillogic/fossil-test) or consult the [Fossil Logic Docs](https://fossillogic.com/docs).

---

## ***Conclusion***

Fossil Test is a powerful and flexible framework for C and C++ developers, designed to support a wide range of testing methodologies such as BDD, DDD, and TDD. With features like mocking, detailed reporting, and performance tracking, Fossil Test empowers developers to create high-quality software and maintainable test suites. Combined with Fossil Mark and Fossil Mock, it provides a complete suite for testing, optimization, and dependency management. Whether you're building small projects or large-scale applications, Fossil Test is an essential tool to ensure the reliability and performance of your code.
