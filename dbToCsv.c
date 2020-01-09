
#include "dbToCsv.h"
#include "libutills.h"

int main()
{
	FILE* fp;
	fp = fopen("final10Blocks", "r");

	FILE* csvFile;
	csvFile = fopen("a.csv", "w+");

	DataBaseToCsv(fp, csvFile);

	fclose(csvFile);
	fclose(fp);
	return 0;
}