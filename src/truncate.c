#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>


int verifyArgs(const int argc, char* argv[])
{
	char *execFileName;
	*execFileName = basename(argv[0]);
	if(argc != 3)
	{
		printf("Usage : %s fileToTruncate newSize", execFileName);
		return -1;
	}
	return 0;
}


int main(int argc, char* argv[])
{
	int argsOk = verifyArgs(argc, argv);
	if(argsOk == 0)
	{
		return -1;
	}

	off_t newLength;
	long long newLengthLongLong;
	newLengthLongLong = atoll(argv[2]);
	newLength = (off_t)newLengthLongLong;
	
	truncate(argv[1], newLength);
	return 0;
}
