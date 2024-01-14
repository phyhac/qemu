#include <linux/kvm.h>
#include "qemu/osdep.h"
#include "qemu/main-loop.h"
#include "sysemu/kvm.h"
#include "cpu.h"

#include "thuffle/thuffle.h"
#include "thuffle/hcall.h"

extern void thsched_handle_hcall(CPUState *cpu, struct kvm_run *run);
extern int thuffle_handle_breakpoint(CPUState *cpu);

void thuffle_init_vcpu(CPUState *cpu)
{
    
}

void thuffle_pre_run(CPUState *cpu)
{

}

void thuffle_post_run(CPUState *cpu)
{

}

void thuffle_handle_kick(CPUState *cpu)
{

}


