#include "reload_db.h"

int main()
{
	int result = reloadDb();
	return 0;
}
int reloadDb()
{
	FILE* fp;
	fp = fopen("final10Blocks", "r");
	system("./latestBlocks.sh");
        printf("%s\n","DB was reloaded");
	fclose(fp);
	return 0;
}
