#ifndef THUFFLE_THSCHED_H
#define THUFFLE_THSCHED_H

typedef struct thsched *thsched;
struct thsched {
    int len;
    target_ulong addr;
    unsigned int order;
};

extern thsched schedule_queue;

#endif /* THUFFLE_THSCHED_H */