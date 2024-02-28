#include <linux/kvm.h>
#include "qemu/osdep.h"
#include "cpu.h"

#include "thuffle/vmi.h"
#include "thuffle/constant.h"
#include "thuffle/log.h"

struct thuffle_vmi_info vmi_info;

static uint64_t vmi_hint_trampoline(CPUState *cpu,
                                    uint64_t a1, uint64_t a2)
{
    vmi_info.trampoline_addr[0] = a1;
    vmi_info.trampoline_addr[1] = a2;
    // LOG_CPU(cpu, "vmi: tramploline hint %lx %lx", a1, a2);
    return 0;
}

static uint64_t vmi_hint_current_task(CPUState *cpu,
                                      uint64_t tid)
{
    vmi_info.current_task = tid;
    // LOG_CPU(cpu, "vmi: current_task hint %lx ", tid);
    return 0;
}

static uint64_t vmi_hint_preempt_count(CPUState *cpu,
                                       uint64_t preempt_count)
{
    vmi_info.preempt_count = preempt_count;
    // LOG_CPU(cpu, "vmi: preempt_count hint %lx ", preempt_count);
    return 0;
}

uint64_t vmi_hint(CPUState *cpu, uint64_t *args)
{
    uint64_t cmd = args[0];
    uint64_t ret;
    switch (cmd) {
    case VMI_TRAMPOLINE:
        ret = vmi_hint_trampoline(cpu, args[1], args[2]);
        break;
    case VMI_CURRENT_TASK:
        ret = vmi_hint_current_task(cpu, args[1]);
        break;
    case VMI_PREEMPT_COUNT:
        ret = vmi_hint_preempt_count(cpu, args[1]);
        break;
    default:
        // LOG_CPU(cpu, "vmi: undefined cmd %s");
        ret = -EINVAL;
        break;
    }
    return ret;
}