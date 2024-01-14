#ifndef THUFFLE_LOG_H
#define THUFFLE_LOG_H

#define LOG_CPU(cpu, fmt, ...)                                                \
    fprintf(stderr, "[CPU #%d] " fmt, cpu->cpu_index,           \
            ##__VA_ARGS__)
            // cpu->hcall_cookie, cpu->breakpoint_cookie, cpu->timer_cookie,      \

#endif /* THUFFLE_LOG_H */    