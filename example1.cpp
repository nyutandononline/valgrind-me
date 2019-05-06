#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
static int copy_data (const int len, const int buf_size)
{
	char *buf = (char *) malloc (buf_size);
	int left = len;
 
	while (left) {
		ssize_t res = read (0, buf, left < buf_size ? left : buf_size);
 
		if (res < 0) {
			perror ("read");
			return -1;
		}
 
 
		if (res == 0) {
			fprintf (stderr, "Have less data than needed!\n");
			return left - len;
		}
 
		if (write(1, buf, res) < 0) {
			perror ("write");
			exit (1);
		}
 
		left -= res;
	}
 
	free (buf);
	return len;
}
 
int main (int argc, char *argv[])
{
	copy_data (128, 16);
 
	return 0;
}
