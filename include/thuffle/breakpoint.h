#ifndef THUFFLE_BREAKPOINT_H
#define THUFFLE_BREAKPOINT_H

#include "qemu/osdep.h"
#include "cpu.h"
#include "thuffle/constant.h"

int thuffle_kvm_insert_breakpoint(CPUState *cpu, uint64_t addr,
                                  uint64_t len, int type);
int thuffle_kvm_remove_breakpoint(CPUState *cpu, uint64_t addr,
                                  uint64_t len, int type);
void thuffle_kvm_remove_all_breakpoints(CPUState *cpu);

#endif /* THUFFLE_BREAKPOINT_H */ 