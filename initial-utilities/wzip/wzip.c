#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int BUFFER_SIZE = 256;
	char buffer[BUFFER_SIZE];
	char current = '\0';
	int count = 0;

	//no arguments
	if (argc == 1)
	{
		printf("wzip: file1 [file2 ...]\n");
		return 1;
	}

	//loop through all files
	for (int i = 1; i < argc; i++)
	{
		// open file
		fp = fopen(argv[i], "r");
		if (fp == NULL)
		{
			printf("wzip: cannot open file\n");
			return 1;
		}

		// read and compress files
		while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
		{
			for (int j = 0; buffer[j] != '\0'; j++)
			{
				// countinue sequence
				if (buffer[j] == current)
				{
					count++;
					continue;
				}
				// new sequence
				if (count > 0)
				{
					fwrite(&count, sizeof(int), 1, stdout);
					fwrite(&current, sizeof(char), 1, stdout);
				}
				current = buffer[j];
				count = 1;
			}
		}
	}

	// write last sequence
	if (count > 0)
	{
		fwrite(&count, sizeof(int), 1, stdout);
		fwrite(&current, sizeof(char), 1, stdout);
	}

	return 0;
}