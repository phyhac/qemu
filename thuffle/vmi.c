#include <linux/kvm.h>
#include "qemu/osdep.h"
#include "cpu.h"

#include "thuffle/vmi.h"
#include "thuffle/constant.h"
#include "thuffle/log.h"

struct thuffle_vmi_info vmi_info;

static target_ulong vmi_hint_trampoline(CPUState *cpu,
                                        target_ulong a1, target_ulong a2)
{
    vmi_info.trampoline_addr[0] = a1;
    vmi_info.trampoline_addr[1] = a2;
    LOG_CPU(cpu, "vmi: tramploline hint %lx %lx", a1, a2);
}

static target_ulong vmi_hint_current_task(CPUState *cpu,
                                          target_ulong tid)
{
    vmi_info.current_task = tid;
    LOG_CPU(cpu, "vmi: current_task hint %lx ", tid);
}

static target_ulong vmi_hint_preempt_count(CPUState *cpu,
                                          target_ulong preempt_count)
{
    vmi_info.preempt_count = preempt_count;
    LOG_CPU(cpu, "vmi: preempt_count hint %lx ", preempt_count);
}

target_ulong vmi_hint(CPUState *cpu, target_ulong *args)
{
    target_ulong cmd = args[0];
    target_ulong ret;
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
        LOG_CPU(cpu, "vmi: undefined cmd %s");
        ret = -EINVAL;
        break;
    }
    return ret;
}