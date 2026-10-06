#include<stdio.h>
#include<string.h>

int linearSearch(char name[][20], char class[][5], int n, char key[])
{
    int i;

    for(i=0;i<n;i++)
    {
        if(strcmp(name[i],key)==0)
        {
            printf("Class = %s",class[i]);
            return 1;
        }
    }
    return 0;
}

int main()
{
    FILE *fp;
    char name[50][20], class[50][5], key[20];
    int n=0;

    fp=fopen("student.txt","r");

    if(fp==NULL)
    {
        printf("File not found");
        return 0;
    }

    while(fscanf(fp,"%s %s",name[n],class[n])!=EOF)
        n++;

    fclose(fp);

    printf("Enter student name: ");
    scanf("%s",key);

    if(linearSearch(name,class,n,key)==0)
        printf("Student not in the list");

    return 0;
}