#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int BUFFER_SIZE = 256;
	char buffer[BUFFER_SIZE];

	//no arguments
	if (argc == 1)
	{
		return 0;
	}

	//loop through all files
	for (int i = 1; i < argc; i++)
	{
		// open file
		fp = fopen(argv[i], "r");
		if (fp == NULL)
		{
			printf("wcat: cannot open file\n");
			return 1;
		}

		// read and print files
		while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
		{
			printf("%s", buffer);
		}
	}

	return 0;
}