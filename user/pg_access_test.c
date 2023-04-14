#include <kernel/param.h>
#include <kernel/types.h>
#include <user/user.h>
#include <kernel/riscv.h>

void assert(int cond) {
	if (!cond) {
		printf("error\n");
		exit(1);
	}
}

int main() {
	char *a;
  unsigned int ab;
	const int N = 32;
  a = malloc(N * PGSIZE);
  assert(pgaccess(a, N, &ab) >= 0);
	for (int i = 0; i < N; i++) {
		a[PGSIZE * i]++;

 		assert(pgaccess(a, N, &ab) >= 0);
		assert(ab & (1 << i));
	}
  free(a);
  printf("ok\n");	

	return 0;
}
