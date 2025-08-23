# distutils: language = c

cdef extern from "mock.h":  # Replace with the actual header file name
    cdef enum fossil_mock_pizza_type_t:
        FOSSIL_MOCK_PIZZA_TYPE_I8
        FOSSIL_MOCK_PIZZA_TYPE_I16
        FOSSIL_MOCK_PIZZA_TYPE_I32
        FOSSIL_MOCK_PIZZA_TYPE_I64
        FOSSIL_MOCK_PIZZA_TYPE_U8
        FOSSIL_MOCK_PIZZA_TYPE_U16
        FOSSIL_MOCK_PIZZA_TYPE_U32
        FOSSIL_MOCK_PIZZA_TYPE_U64
        FOSSIL_MOCK_PIZZA_TYPE_HEX
        FOSSIL_MOCK_PIZZA_TYPE_OCTAL
        FOSSIL_MOCK_PIZZA_TYPE_FLOAT
        FOSSIL_MOCK_PIZZA_TYPE_DOUBLE
        FOSSIL_MOCK_PIZZA_TYPE_WSTR
        FOSSIL_MOCK_PIZZA_TYPE_CSTR
        FOSSIL_MOCK_PIZZA_TYPE_CCHAR
        FOSSIL_MOCK_PIZZA_TYPE_WCHAR
        FOSSIL_MOCK_PIZZA_TYPE_BOOL
        FOSSIL_MOCK_PIZZA_TYPE_SIZE
        FOSSIL_MOCK_PIZZA_TYPE_ANY

    cdef struct fossil_mock_pizza_value_t:
        char *data
        bint mutable_flag

    cdef struct fossil_mock_pizza_attribute_t:
        char* name
        char* description
        char* id

    cdef struct fossil_mock_pizza_t:
        fossil_mock_pizza_type_t type
        fossil_mock_pizza_value_t value
        fossil_mock_pizza_attribute_t attribute

    cdef struct fossil_mock_call_t:
        char *function_name
        fossil_mock_pizza_t *arguments
        int num_args
        fossil_mock_call_t *next

    cdef struct fossil_mock_calllist_t:
        fossil_mock_call_t *head
        fossil_mock_call_t *tail
        int size

    void fossil_mock_init(fossil_mock_calllist_t *list)
    void fossil_mock_destroy(fossil_mock_calllist_t *list)
    void fossil_mock_add_call(fossil_mock_calllist_t *list, const char *function_name, fossil_mock_pizza_t *arguments, int num_args)
    void fossil_mock_print(fossil_mock_calllist_t *list)
    int fossil_mock_capture_output(char *buffer, size_t size, void (*function)(void))
    bint fossil_mock_compare_output(const char *captured, const char *expected)