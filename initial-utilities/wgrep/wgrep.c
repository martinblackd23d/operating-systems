#include <stdio.h>

// search for a string in a line
int find(char *line, char *search)
{
	int i, j;
	for (i = 0; line[i] != '\0'; i++)
	{
		for (j = 0; search[j] != '\0'; j++)
		{
			if (line[i + j] != search[j])
			{
				break;
			}
		}
		if (search[j] == '\0')
		{
			return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char *lineptr = NULL;
	size_t n = 0;

	//no arguments
	if (argc == 1)
	{
		printf("wgrep: searchterm [file ...]\n");
		return 1;
	}

	//loop through all files
	for (int i = 1; i < argc; i++)
	{
		// open file
		if (argc == 2)
		{
			fp = stdin;
		}
		else if (i == 1)
		{
			continue;
		}
		else
		{
			fp = fopen(argv[i], "r");
		}

		if (fp == NULL)
		{
			printf("wgrep: cannot open file\n");
			return 1;
		}

		// read and search lines
		while (getline(&lineptr, &n, fp) != -1)
		{
			if (find(lineptr, argv[1]))
			{
				printf("%s", lineptr);
			}
		}

		fclose(fp);
	}

	return 0;
}