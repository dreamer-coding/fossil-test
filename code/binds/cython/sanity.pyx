# distutils: language = c
# cython: language_level=3

cdef extern from "sanity.h":
    int fossil_sanity_sys_execute(const char* command)
    int fossil_sanity_sys_getpid()
    void fossil_sanity_sys_sleep(int milliseconds)
    int fossil_sanity_sys_create_file(const char* filename)
    int fossil_sanity_sys_file_exists(const char* filename)
    int fossil_sanity_sys_create_dir(const char* dirname)
    int fossil_sanity_sys_dir_exists(const char* dirname)
    char* fossil_sanity_sys_read_file(const char* filename)
    int fossil_sanity_sys_write_file(const char* filename, const char* data)
    int fossil_sanity_sys_delete_file(const char* filename)
    const char* fossil_sanity_sys_getenv(const char* name)
    int fossil_sanity_sys_setenv(const char* name, const char* value)
    char* fossil_sanity_sys_timestamp()
    long long fossil_sanity_sys_uptime_ms()
    int fossil_sanity_sys_is_running(int pid)
    int fossil_sanity_sys_kill(int pid)

from libc.stdlib cimport free
from libc.string cimport strdup

def sys_execute(command: str) -> int:
    return fossil_sanity_sys_execute(command.encode())

def sys_getpid() -> int:
    return fossil_sanity_sys_getpid()

def sys_sleep(milliseconds: int):
    fossil_sanity_sys_sleep(milliseconds)

def sys_create_file(filename: str) -> int:
    return fossil_sanity_sys_create_file(filename.encode())

def sys_file_exists(filename: str) -> int:
    return fossil_sanity_sys_file_exists(filename.encode())

def sys_create_dir(dirname: str) -> int:
    return fossil_sanity_sys_create_dir(dirname.encode())

def sys_dir_exists(dirname: str) -> int:
    return fossil_sanity_sys_dir_exists(dirname.encode())

def sys_read_file(filename: str) -> str:
    cdef char* buf = fossil_sanity_sys_read_file(filename.encode())
    if not buf:
        return None
    pystr = buf.decode()
    free(buf)
    return pystr

def sys_write_file(filename: str, data: str) -> int:
    return fossil_sanity_sys_write_file(filename.encode(), data.encode())

def sys_delete_file(filename: str) -> int:
    return fossil_sanity_sys_delete_file(filename.encode())

def sys_getenv(name: str) -> str:
    cdef const char* val = fossil_sanity_sys_getenv(name.encode())
    if not val:
        return None
    return val.decode()

def sys_setenv(name: str, value: str) -> int:
    return fossil_sanity_sys_setenv(name.encode(), value.encode())

def sys_timestamp() -> str:
    cdef char* buf = fossil_sanity_sys_timestamp()
    if not buf:
        return None
    pystr = buf.decode()
    free(buf)
    return pystr

def sys_uptime_ms() -> int:
    return fossil_sanity_sys_uptime_ms()

def sys_is_running(pid: int) -> int:
    return fossil_sanity_sys_is_running(pid)

def sys_kill(pid: int) -> int:
    return fossil_sanity_sys_kill(pid)
