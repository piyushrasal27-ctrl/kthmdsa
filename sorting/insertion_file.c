#include<stdio.h>

struct student
{
    char name[20];
    int age;
    float per;
};

int main()
{
    FILE *fp,*sp;
    struct student s[50],key;
    int n=0,i,j;

    fp=fopen("Student.txt","r");

    if(fp==NULL)
    {
        printf("File not found");
        return 0;
    }

    while(fscanf(fp,"%s %d %f",s[n].name,&s[n].age,&s[n].per)!=EOF)
        n++;

    fclose(fp);

    /* Insertion Sort on Age */
    for(i=1;i<n;i++)
    {
        key=s[i];
        j=i-1;

        while(j>=0 && s[j].age>key.age)
        {
            s[j+1]=s[j];
            j--;
        }

        s[j+1]=key;
    }

    sp=fopen("SortedStudent.txt","w");

    for(i=0;i<n;i++)
        fprintf(sp,"%s %d %.2f\n",
                s[i].name,s[i].age,s[i].per);

    fclose(sp);

    printf("Data sorted and stored in SortedStudent.txt");

    return 0;
}