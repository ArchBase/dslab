#include <stdio.h>

#define MAX_LENGTH 100

struct poly
{
    struct term
    {
        int coeff, expon;
    }terms[MAX_LENGTH];
};


void main(){
    struct poly a, b, sum;
    int i, j, k, numa, numb;
    printf("Enter first polyniomial: ");
    printf("\number of terms? : ");
    scanf("%d", &numa);
    printf("\tEnter each terms:\n");
    for (i = 0; i < numa; i++)
    {
        printf("\t\tterm:%d(coeff expon): ", i);
        scanf("%d %d", &a.terms[i].coeff, &a.terms[i].expon);
    }

    printf("Enter second polyniomial: ");
    printf("\number of terms? : ");
    scanf("%d", &numb);
    printf("\tEnter each terms:\n");
    for (i = 0; i < numb; i++)
    {
        printf("\t\tterm:%d(coeff expon): ", i);
        scanf("%d %d", &b.terms[i].coeff, &b.terms[i].expon);
    }
    
    i=0;
    j=0;
    k=0;
    while (i<numa && j<numb)
    {
        if (a.terms[i].expon == b.terms[j].expon)
        {
            sum.terms[k].coeff = a.terms[i].coeff + b.terms[j].coeff;
            sum.terms[k].expon = a.terms[i].expon;
            i++;
            j++;
            k++;
        }
        else if (a.terms[i].expon > b.terms[j].expon)
        {
            sum.terms[k].coeff = a.terms[i].coeff;
            sum.terms[k].expon = a.terms[i].expon;
            i++;
            k++;
        }
        else if (b.terms[j].expon > a.terms[i].expon)
        {
            sum.terms[k].coeff = b.terms[j].coeff;
            sum.terms[k].expon = b.terms[j].expon;
            j++;
            k++;
        }
    }

    while (i < numa)
    {
        sum.terms[k].expon = a.terms[i].expon;
        sum.terms[k].coeff = a.terms[i].coeff;
        i++;
        k++;
    }
    
    while (j < numb)
    {
        sum.terms[k].expon = b.terms[j].expon;
        sum.terms[k].coeff = b.terms[j].coeff;
        j++;
        k++;
    }


    printf("Sum poly: \n");
    for (i = 0; i < k; i++)
    {
        printf("\t\tterm:%d(coeff expon): %d %d\n", i, sum.terms[i].coeff, sum.terms[i].expon);
    }
    

}