#ifndef THUFFLE_VMI_H
#define THUFFLE_VMI_H


// #define PREEMPT_BITS 8
// #define SOFTIRQ_BITS 8
// #define HARDIRQ_BITS 4
// #define NMI_BITS 4

// #define PREEMPT_SHIFT 0
// #define SOFTIRQ_SHIFT (PREEMPT_SHIFT + PREEMPT_BITS)
// #define HARDIRQ_SHIFT (SOFTIRQ_SHIFT + SOFTIRQ_BITS)
// #define NMI_SHIFT (HARDIRQ_SHIFT + HARDIRQ_BITS)

// #define __IRQ_MASK(x) ((1UL << (x)) - 1)

// #define PREEMPT_MASK (__IRQ_MASK(PREEMPT_BITS) << PREEMPT_SHIFT)
// #define SOFTIRQ_MASK (__IRQ_MASK(SOFTIRQ_BITS) << SOFTIRQ_SHIFT)
// #define HARDIRQ_MASK (__IRQ_MASK(HARDIRQ_BITS) << HARDIRQ_SHIFT)
// #define NMI_MASK (__IRQ_MASK(NMI_BITS) << NMI_SHIFT)

// #define PREEMPT_OFFSET (1UL << PREEMPT_SHIFT)
// #define SOFTIRQ_OFFSET (1UL << SOFTIRQ_SHIFT)
// #define HARDIRQ_OFFSET (1UL << HARDIRQ_SHIFT)
// #define NMI_OFFSET (1UL << NMI_SHIFT)

struct thuffle_vmi_info {
    target_ulong trampoline_addr[2];
    target_ulong hook_addr;
    target_ulong current_task;
    target_ulong preempt_count;
};
#define trampoline_entry_addr trampoline_addr[0]
#define trampoline_exit_addr trampoline_addr[1]

extern struct thuffle_vmi_info vmi_info;

target_ulong vmi_hint(CPUState *cpu, target_ulong *args);

#endif /* THUFFLE_VMI_H */