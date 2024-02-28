#ifndef THUFFLE_LOG_H
#define THUFFLE_LOG_H

#define LOG_CPU(cpu, fmt, ...)                                                \
    fprintf(stderr, "[CPU #%d] " fmt, cpu->cpu_index,           \
            ##__VA_ARGS__)

#define DPRINTF(fmt, ...) \
    do { fprintf(stderr, fmt, ## __VA_ARGS__); } while (0)

#endif /* THUFFLE_LOG_H */    