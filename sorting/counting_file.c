#include<stdio.h>

struct emp
{
    char name[20];
    int age;
    float sal;
};

void counting(struct emp e[],int n);

int main()
{
    FILE *f,*s;
    struct emp e[50];
    int n=0,i;

    f=fopen("employee.txt","r");

    while(fscanf(f,"%s%d%f",e[n].name,
          &e[n].age,&e[n].sal)!=EOF)
        n++;

    fclose(f);

    counting(e,n);

    s=fopen("sortedemponage.txt","w");

    for(i=0;i<n;i++)
        fprintf(s,"%s %d %.2f\n",
                e[i].name,e[i].age,e[i].sal);

    fclose(s);

    printf("Sorted data stored in file");
    return 0;
}

void counting(struct emp e[],int n)
{
    struct emp t[50];
    int c[100]={0};
    int i,j,k=0,max=e[0].age;

    for(i=1;i<n;i++)
        if(e[i].age>max)
            max=e[i].age;

    for(i=0;i<n;i++)
        c[e[i].age]++;

    for(i=0;i<=max;i++)
        while(c[i]>0)
        {
            for(j=0;j<n;j++)
                if(e[j].age==i)
                    t[k++]=e[j];

            c[i]--;
        }

    for(i=0;i<n;i++)
        e[i]=t[i];
}