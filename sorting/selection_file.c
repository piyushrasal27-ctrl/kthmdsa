#include<stdio.h>

struct student
{
    char name[20];
    int age;
    float per;
};

void selection(struct student s[],int n);

int main()
{
    FILE *f,*sf;
    struct student s[50];
    int n=0,i;

    f=fopen("Student.txt","r");

    while(fscanf(f,"%s%d%f",s[n].name,
          &s[n].age,&s[n].per)!=EOF)
        n++;

    fclose(f);

    selection(s,n);

    sf=fopen("SortedStudent.txt","w");

    for(i=0;i<n;i++)
        fprintf(sf,"%s %d %.2f\n",
                s[i].name,s[i].age,s[i].per);

    fclose(sf);

    printf("Sorted data stored in file");
    return 0;
}

void selection(struct student s[],int n)
{
    int i,j,min;
    struct student t;

    for(i=0;i<n-1;i++)
    {
        min=i;

        for(j=i+1;j<n;j++)
            if(s[j].per<s[min].per)
                min=j;

        t=s[i];
        s[i]=s[min];
        s[min]=t;
    }
}