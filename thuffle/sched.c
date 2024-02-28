#include "thuffle/sched.h"

#include <linux/kvm.h>
#include "qemu/osdep.h"
#include "cpu.h"
#include "sysemu/kvm.h"

thsched schedule_queue;

// queue_insert
// queue_push
// queue_pop
// queue_del_bp
// queue_add_bp
// queue_isempty
// queue_move
