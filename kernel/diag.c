#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "defs.h"
#include "diag.h"

struct spinlock pr_msg_buffer_lock;
char pr_msg_buffer[BUFFER_SIZE];
int  pr_msg_buffer_pointer = 0;

static void
pr_uint(uint x) 
{
	if (x > 9) 
	{
		pr_uint(x / 10);
	}
	pr_msg_buffer[pr_msg_buffer_pointer++] = x % 10 + '0';
}

void 
pr_msg(const char *str) 
{
	acquire(&pr_msg_buffer_lock);
	pr_uint(ticks);
	pr_msg_buffer[pr_msg_buffer_pointer++] = ':';
	while (pr_msg_buffer_pointer < BUFFER_SIZE && *str)
	{
		pr_msg_buffer[pr_msg_buffer_pointer++] = *str++;
	}
	pr_msg_buffer[pr_msg_buffer_pointer++] = '\n';
	release(&pr_msg_buffer_lock);
}
