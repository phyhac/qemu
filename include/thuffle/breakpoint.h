#ifndef THUFFLE_BREAKPOINT_H
#define THUFFLE_BREAKPOINT_H

#include "qemu/osdep.h"
#include "cpu.h"
#include "thuffle/constant.h"

int thuffle_kvm_insert_breakpoint(CPUState *cpu, target_ulong addr,
                                  target_ulong len, int type);
int thuffle_kvm_remove_breakpoint(CPUState *cpu, target_ulong addr,
                                  target_ulong len, int type);
void thuffle_kvm_remove_all_breakpoints(CPUState *cpu);

int thuffle_handle_breakpoint(CPUState *cpu);

#endif /* THUFFLE_BREAKPOINT_H */ 