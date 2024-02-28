#ifndef THUFFLE_HCALL_H
#define THUFFLE_HCALL_H

#include "qemu/osdep.h"
#include "cpu.h"

#define VMCALL_INSTR_LEN 3

void thuffle_handle_hcall(CPUState *cpu, struct kvm_run *run);

#endif /* THUFFLE_HCALL_H */    