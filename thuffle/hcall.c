#include <linux/kvm.h>
#include "qemu/osdep.h"
#include "cpu.h"
#include "qemu/main-loop.h"
#include "sysemu/kvm.h"

#include "thuffle/hcall.h"
#include "thuffle/constant.h"
#include "thuffle/vmi.h"

static uint64_t hcall_reset(CPUState *cpu)
{
    return 0;
}

static uint64_t hcall_install_breakpoint(CPUState *cpu)
{
    return 0;
}

static uint64_t hcall_clear_breakpoint(CPUState *cpu)
{
    return 0;
}

static uint64_t hcall_vmi_hint(CPUState *cpu, uint64_t *args)
{
    return vmi_hint(cpu, args);
}

static uint64_t hcall_gen_intr(CPUState *cpu, uint64_t *args)
{
    // printf("qemu: hello hcall_gen_intr\n");
    int intr_num = (int)args[0];
    // if (info.trig_mode == IOAPIC_TRIGGER_EDGE) {
    //     kvm_set_irq(kvm_state, intr_num, 1);
    //     kvm_set_irq(kvm_state, intr_num, 0);
    // } else {
    kvm_set_irq(kvm_state, intr_num, 1);
    kvm_set_irq(kvm_state, intr_num, 0);
    // }
    return 0;
}

static void skip_vmcall_instr(CPUState *cpu) {
    cpu->regs.rip += VMCALL_INSTR_LEN;
    cpu->thf_dirty = true;
}

void thuffle_handle_hcall(CPUState *cpu, struct kvm_run *run)
{
    uint64_t *args = (uint64_t *)(run->hypercall.args);
    uint64_t cmd = args[0];
    uint64_t ret;

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
    case HCALL_GEN_INTR:
        ret = hcall_gen_intr(cpu, &args[1]);
        break;
    default:
        ret = -EINVAL;
    }

    if (ret) {
        // error
    }
    skip_vmcall_instr(cpu);
    qemu_mutex_unlock_iothread();
    // commit state
}