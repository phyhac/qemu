#include "thuffle/breakpoint.h"
#include "qemu/osdep.h"
#include "sysemu/kvm.h"

struct percpu_hw_breakpoint hw_breakpoint[MAX_NR_CPUS];

#include <linux/kvm.h>
#include "qemu/osdep.h"
#include "sysemu/kvm.h"
#include "cpu.h"
#include "exec/gdbstub.h"


int thuffle_kvm_insert_breakpoint(CPUState *cpu, target_ulong addr,
                                  target_ulong len, int type)
{
    int err = 0;
    if (type == GDB_BREAKPOINT_SW) {
        err = -EINVAL;
    } else {
        err = thuffle_kvm_arch_insert_hw_breakpoint(cpu, addr, len, type);
    }

    if (err)
        return err;

    return thuffle_kvm_update_guest_debug(cpu, 0);
}

int thuffle_kvm_remove_breakpoint(CPUState *cpu, target_ulong addr,
                                  target_ulong len, int type)
{
    int err = 0;
    if (type == GDB_BREAKPOINT_SW) {
        err = -EINVAL;
    } else {
        err = thuffle_kvm_arch_remove_hw_breakpoint(cpu, addr, len, type);
    }

    if (err)
        return err;

    return thuffle_kvm_update_guest_debug(cpu, 0);
}

void thuffle_kvm_remove_all_breakpoints(CPUState *cpu)
{
    // currently only support hardware breakpoint
    thuffle_kvm_arch_remove_all_hw_breakpoints(cpu);
    thuffle_kvm_update_guest_debug(cpu, 0);
}

int thuffle_handle_breakpoint(CPUState *cpu)
{
    qemu_mutex_lock_iothread();

    // TODO: fill this
    // remove_breakpoint();
    // thuffle_kvm_update_guest_debug();

    qemu_mutex_unlock_iothread();
    return 0;    
}