#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[]) {
	write(1, "hello!\n", 7);
	if (dmesg(1) == -1) {
		printf("Error while printing buffer!");
	}	
	exit(0);
}
