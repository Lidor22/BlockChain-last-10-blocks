
#include "print_blocks.h"
#include "libutills.h"


int main()
{
	FILE* fp;
	fp = fopen("final10Blocks", "r");
	PrintAllBlocks(fp);

	return 0;
}