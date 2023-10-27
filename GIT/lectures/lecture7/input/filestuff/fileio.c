#include <stdio.h>

int main() 
{
    FILE *fp;

    fp = fopen("textFile.txt", "w+");
    fprintf(fp, "This is testing for fprintf\n");
    fputs("This iis testing for fputs", fp);

    return 0;
}