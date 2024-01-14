#ifndef THUFFLE_THUFFLE_H
#define THUFFLE_THUFFLE_H

#include "qemu/osdep.h"
#include "cpu.h"
#include "thuffle/constant.h"
#include "thuffle/hcall.h"

void thuffle_init_vcpu(CPUState *cpu);
void thuffle_pre_run(CPUState *cpu);
void thuffle_post_run(CPUState *cpu);
void thuffle_handle_kick(CPUState *cpu);
int  thuffle_handle_breakpoint(CPUState *cpu);

#endif /* THUFFLE_THUFFLE_H */