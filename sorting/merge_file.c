#include<stdio.h>

struct emp
{
    char name[20];
    int age;
    float sal;
};

void merge(struct emp e[],int l,int m,int h);
void mergesort(struct emp e[],int l,int h);

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

    mergesort(e,0,n-1);

    s=fopen("sortedemponage.txt","w");

    for(i=0;i<n;i++)
        fprintf(s,"%s %d %.2f\n",
                e[i].name,e[i].age,e[i].sal);

    fclose(s);

    printf("Sorted data stored in file");

    return 0;
}

void mergesort(struct emp e[],int l,int h)
{
    int m;

    if(l<h)
    {
        m=(l+h)/2;

        mergesort(e,l,m);
        mergesort(e,m+1,h);

        merge(e,l,m,h);
    }
}

void merge(struct emp e[],int l,int m,int h)
{
    struct emp t[50];
    int i=l,j=m+1,k=0;

    while(i<=m && j<=h)
    {
        if(e[i].age<e[j].age)
            t[k++]=e[i++];
        else
            t[k++]=e[j++];
    }

    while(i<=m)
        t[k++]=e[i++];

    while(j<=h)
        t[k++]=e[j++];

    for(i=l,k=0;i<=h;i++,k++)
        e[i]=t[k];
}