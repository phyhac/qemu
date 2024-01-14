#include <linux/kvm.h>
#include "qemu/osdep.h"
#include "cpu.h"

#include "thuffle/hcall.h"
#include "thuffle/constant.h"
#include "thuffle/vmi.h"

static target_ulong hcall_reset(CPUState *cpu)
{

}

static target_ulong hcall_install_breakpoint(CPUState *cpu)
{

}

static target_ulong hcall_clear_breakpoint(CPUState *cpu)
{

}

static target_ulong hcall_vmi_hint(CPUState *cpu, uint64_t *args)
{
    return vmi_hint(cpu, args);
}

void thsched_handle_hcall(CPUState *cpu, struct kvm_run *run)
{
    uint64_t *args = run->hypercall.args;
    uint64_t cmd = args[0];
    target_ulong ret;

    qemu_mutex_lock_iothread();
    switch (cmd) {
    case HCALL_RESET:
        ret = hcall_reset(cpu);
        break;
    case HCALL_INSTALL_BP:
        ret = hcall_install_breakpoint(cpu);
        break;
    case HCALL_CLEAR_BP:
        ret = hcall_clear_breakpoint(cpu);
        break;
    case HCALL_VMI_HINT:
        ret = hcall_vmi_hint(cpu, &args[1]);
        break;
    default:
        ret = -EINVAL;
    }

    if (ret) {
        // error
    }
    qemu_mutex_unlock_iothread();
    // commit state
}