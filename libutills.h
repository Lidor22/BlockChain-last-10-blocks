#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#ifndef LIBUTILLS_H
#define LIBUTILLS_H

void LookForHash(char* HashId,FILE *fp);
void LookForHeight(char* HeightId,FILE *fp);
void PrintAllBlocks(FILE *fp);
void DataBaseToCsv(FILE *fp,FILE *csvFile);
#endif