#include<stdio.h>
#include<string.h>

int binarySearch(char name[][20],char cls[][5],int n,char key[]);

int main()
{
    FILE *f;
    char name[50][20],cls[50][5],key[20];
    int n=0,pos;

    f=fopen("student.txt","r");

    while(fscanf(f,"%s%s",name[n],cls[n])!=EOF)
        n++;

    fclose(f);

    printf("Enter student name: ");
    scanf("%s",key);

    pos=binarySearch(name,cls,n,key);

    if(pos==-1)
        printf("Student not in the list");
    else
        printf("Class = %s",cls[pos]);

    return 0;
}

int binarySearch(char name[][20],char cls[][5],int n,char key[])
{
    int l=0,h=n-1,m;

    while(l<=h)
    {
        m=(l+h)/2;

        if(strcmp(name[m],key)==0)
            return m;

        if(strcmp(key,name[m])<0)
            h=m-1;
        else
            l=m+1;
    }

    return -1;
}