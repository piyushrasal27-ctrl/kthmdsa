#include<stdio.h>

struct employee
{
    char name[20];
    int age;
    float salary;
};

void bubble_sort(struct employee e[], int n);

int main()
{
    FILE *fp;
    struct employee e[50];
    int n=0,i;

    fp=fopen("employee.txt","r");

    if(fp==NULL)
    {
        printf("File not found");
        return 0;
    }

    while(fscanf(fp,"%s %d %f",
                 e[n].name,
                 &e[n].age,
                 &e[n].salary)!=EOF)
    {
        n++;
    }

    fclose(fp);

    bubble_sort(e,n);

    printf("\nEmployees sorted according to age:\n");

    for(i=0;i<n;i++)
    {
        printf("%s %d %.2f\n",
               e[i].name,
               e[i].age,
               e[i].salary);
    }

    return 0;
}

void bubble_sort(struct employee e[], int n)
{
    int i,j;
    struct employee temp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(e[j].age > e[j+1].age)
            {
                temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
            }
        }
    }
}