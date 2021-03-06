#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif
#include <glib.h>
#include <asm/unistd.h>
#include <errno.h>
#include <unistd.h>
#include <sched.h>

#include "sysfuzz.h"
#include "typelib.h"
#include "iknowthis.h"

// Delete a POSIX.1b interval timer
// long sys_timer_delete (timer timer_id);
SYSFUZZ(timer_delete, __NR_timer_delete, SYS_NONE, CLONE_DEFAULT, 0)
{
    return spawn_syscall_lwp(this, NULL, __NR_timer_delete,                                             // long
                             typelib_get_integer());                                                    // timer_t timer_id
}

