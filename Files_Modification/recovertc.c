#include "types.h"
#include "user.h"
#include "syscall.h"
#include "stat.h"
#include "fcntl.h"

int main(int argc, char **argv) {
	// run compareWalkers before changing any data
	if(compareWalkers()){
		// If compareWalkers finds no differences, notify user
		printf(1,"No Differences Detected\n");
	}
	// add 1 level directory
	mkdir("hellotest");
	printf(1, "----> Created directory hellotest inside of root\n");
	int fd;
	fd = open("/hellotest/test1", O_CREATE | O_RDWR);
	if(fd >= 0){
		printf(1, "----> Created file test1 inside /hellotest\n");
	}
	write(fd, "hellotest1", 11);
	close(fd);

	fd = open("/hellotest/test2", O_CREATE | O_RDWR);
	if(fd >= 0){
		printf(1, "----> Created file test2 inside /hellotest\n");
	}
	write(fd, "hellotest2", 11);
	close(fd);


	// add 2 level directory
	mkdir("/hellotest/foo");
	printf(1, "----> Created directory foo inside of hellotest\n");
	fd = open("/hellotest/foo/test1", O_CREATE | O_RDWR);
	if(fd >= 0){
		printf(1, "----> Created file test1 inside /hellotest/foo\n");
	}
	write(fd, "hellotest1", 11);
	close(fd);

	fd = open("/hellotest/foo/test2", O_CREATE | O_RDWR);
	if(fd >= 0){
		printf(1, "----> Created file test2 inside /hellotest/foo\n");
	}
	write(fd, "hellotest2", 11);
	close(fd);

	exit();
	return 0;
}

