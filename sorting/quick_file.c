#include<stdio.h>

struct emp
{
    char name[20];
    int age;
    float sal;
};

void quick(struct emp e[],int l,int h);

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

    quick(e,0,n-1);

    s=fopen("sortedemponage.txt","w");

    for(i=0;i<n;i++)
        fprintf(s,"%s %d %.2f\n",
                e[i].name,e[i].age,e[i].sal);

    fclose(s);

    printf("Sorted data stored in file");
    return 0;
}

void quick(struct emp e[],int l,int h)
{
    int i=l,j=h;
    struct emp t,p;

    if(l<h)
    {
        p=e[l];

        while(i<j)
        {
            while(e[i].age<=p.age && i<h)
                i++;

            while(e[j].age>p.age)
                j--;

            if(i<j)
            {
                t=e[i];
                e[i]=e[j];
                e[j]=t;
            }
        }

        e[l]=e[j];
        e[j]=p;

        quick(e,l,j-1);
        quick(e,j+1,h);
    }
}