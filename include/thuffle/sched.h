#ifndef THUFFLE_SCHED_H
#define THUFFLE_SCHED_H

#include "qemu/osdep.h"
#include "cpu.h"

typedef struct thsched *thsched;
struct thsched {
    int len;
    uint64_t addr;
    unsigned int order;
};

extern thsched schedule_queue;

#endif /* THUFFLE_SCHED_H */