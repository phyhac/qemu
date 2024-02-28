#include <linux/kvm.h>
#include "qemu/osdep.h"
#include "qemu/main-loop.h"
#include "sysemu/kvm.h"
#include "cpu.h"

#include "thuffle/thuffle.h"
#include "thuffle/hcall.h"
#include "thuffle/log.h"

void thuffle_init_vcpu(CPUState *cpu)
{
    
}

void thuffle_pre_run(CPUState *cpu)
{
    if (cpu->thf_dirty) {
        if (thuffle_kvm_write_regs(cpu)) {
            DPRINTF("thuffle_kvm_write_regs fail\n");
        }
        cpu->thf_dirty = false;
    }
}

void thuffle_post_run(CPUState *cpu)
{
    if (thuffle_kvm_read_regs(cpu)) {
        DPRINTF("thuffle_kvm_read_regs fail\n");
    }
}

void thuffle_handle_kick(CPUState *cpu)
{

}
