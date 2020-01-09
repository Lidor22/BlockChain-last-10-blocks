#include "print_block.h"
#include "libutills.h"

int main(int argc, char* argv[])
{
	FILE* fp;
	fp = fopen("final10Blocks", "r");

        

        if(argc == 1)
        {
                printf("%s\n", "Not valid input,please enter hash or height");
        }
	else if (strstr(argv[1], "hash") != NULL)
	{
		LookForHash(argv[2], fp);
	}
	else if (strstr(argv[1], "height") != NULL)
	{
		LookForHeight(argv[2], fp);
	}
	else
	{
		printf("%s\n", "Not valid input,please enter hash or height");
	}


	fclose(fp);
	return 0;
}

