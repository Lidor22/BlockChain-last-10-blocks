#include "libutills.h"

void DataBaseToCsv(FILE *fp,FILE *csvFile)
{
    fprintf(csvFile,"hash,height,total,time,relayed by,prev block");
   
    char * line = NULL;
    char* hash = NULL;
    char* height = NULL;
    char* total = NULL;
    char* time = NULL;
    char* relayed = NULL ;
    char* prev = NULL;

    
    size_t len = 0;
    int counter = 0;
    size_t read;

    while ((read = getline(&line, &len, fp)) != -1) 
    {

        hash = line;
        read = getline(&height, &len, fp);
        read = getline(&total, &len, fp);   
        read = getline(&time, &len, fp);
        read = getline(&relayed, &len, fp);
        read = getline(&prev, &len, fp);

        char *p = strchr(height, '\n');
        if (p != NULL) *p = '\0';

        char *p5 = strchr(total, '\n');
        if (p5 != NULL) *p5 = '\0';
        char *p1 = strchr(time, '\n');
        if (p1 != NULL) *p1 = '\0';
        char *p2 = strchr(relayed, '\n');
        if (p2 != NULL) *p2 = '\0';
        char *p3 = strchr(prev, '\n');
        if (p3 != NULL) *p3 = '\0';
        char *p4 = strchr(hash, '\n');
        if (p4 != NULL) *p4 = '\0';

       fprintf(csvFile,"\n%s,%s,%s,%s,%s,%s",hash + 5,height + 7,total +5,time + 5,relayed + 11,prev +11); 

        read = getline(&line, &len, fp);
    }

}
void PrintAllBlocks(FILE *fp)
{
    char * line = NULL;
    size_t len = 0;
    size_t read;
    int counter = 0;

    while ((read = getline(&line, &len, fp)) != -1) 
    {
        counter++;
        printf("%s", line);
        if(counter == 7)
        {
        printf("%s", "                    |\n");
        printf("%s", "                    |\n");
        printf("%s", "                    |\n");
        printf("%s", "                    V\n");
        counter = 0;
        }
       
    }
    fclose (fp);

     if (line)
        free(line);
}
void LookForHash(char* HashId,FILE *fp)
{
   char * line = NULL;
    size_t len = 0;
    size_t read;
     while ((read = getline(&line, &len, fp)) != -1) 
    {
        if(strstr(line,"hash") != NULL) 
        {
            if(strstr(line,HashId) != NULL)
            {
            printf("%s", line);
            read = getline(&line, &len, fp);
            printf("%s", line);
            read = getline(&line, &len, fp);
            printf("%s", line);
            read = getline(&line, &len, fp);
            printf("%s", line);
            read = getline(&line, &len, fp);
            printf("%s", line);
            read = getline(&line, &len, fp);
            printf("%s", line);
            printf("\n");
            return;
            }
        }
    }
}

void LookForHeight(char* HeightId,FILE *fp)
{
    char * line = NULL;
    char prevLine[99];
    size_t len = 0;
    size_t read;
     while ((read = getline(&line, &len, fp)) != -1) 
    {
        if(strstr(line,"hash") != NULL)
        {
            strncpy(prevLine, line, strlen(line));
        }

        if(strstr(line,"height") != NULL) 
        {
            if(strstr(line,HeightId) != NULL)
            {
            printf("%s", prevLine);
            printf("%s", line);
            read = getline(&line, &len, fp);
            printf("%s", line);
            read = getline(&line, &len, fp);
            printf("%s", line);
            read = getline(&line, &len, fp);
            printf("%s", line);
            read = getline(&line, &len, fp);
            printf("%s", line);
            printf("\n");
            return;
            }
        }
    }

}
