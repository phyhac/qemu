thuffle_ss = ss.source_set()
thuffle_ss.add(when: 'CONFIG_THUFFLE', if_true: files(
  'thuffle.c',
  'sched.c',
  'hcall.c',
  'breakpoint.c',
  'vmi.c',
  'trampoline.c'
))

specific_ss.add_all(when: 'CONFIG_SOFTMMU', if_true: [thuffle_ss])
