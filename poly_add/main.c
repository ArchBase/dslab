#include <stdio.h>

typedef struct term
{
    int coefficient;
    int exponent;
}term;

typedef struct polynomial
{
    int num_of_terms;
    term terms[10];
}polynomial;

int main(){
    int num_of_terms[10], num_of_polynomials, i, j, k, flag;
    polynomial poly[10], result;
    
    // input
    {
        printf("Enter number of polynomials: ");
        scanf("%d", &num_of_polynomials);
        i=0;
        while (i<num_of_polynomials)
        {
            printf("\tEnter number of terms of polynomial %d: ", i);
            scanf("%d", &poly[i].num_of_terms);
            printf("\t\tEnter coefficients of polynomial %d: ", i);
            for(j=0; j<poly[i].num_of_terms; j++){
                scanf("%d", &poly[i].terms[j].coefficient);
            }
            printf("\t\tEnter exponentials of polynomial %d: ", i);
            for(j=0; j<poly[i].num_of_terms; j++){
                scanf("%d", &poly[i].terms[j].exponent);
            }
            i++;
        }

        for (i = 0; i < num_of_polynomials; i++)
        {
            printf("\n\nPoly %d:\n", i);
            for (j = 0; j < poly[i].num_of_terms; j++)
            {
                printf("%d %d\n", poly[i].terms[j].coefficient, poly[i].terms[j].exponent);
            }
            
        }
    }

    // add polynomials
    {
        // copy first polynomial to result
        for (i = 0; i < poly[0].num_of_terms; i++)
        {
            result.terms[i].coefficient = poly[0].terms[i].coefficient;
            result.terms[i].exponent = poly[0].terms[i].exponent;
            result.num_of_terms = poly[0].num_of_terms;
        }
        
        // Add polynomials
        i=1;
        while (i < num_of_polynomials)
        {
            for(j=0; j<poly[i].num_of_terms; j++){
                flag=0;
                for(k=0; k<result.num_of_terms; k++){
                    if(result.terms[k].exponent == poly[i].terms[j].exponent){
                        result.terms[k].coefficient += poly[i].terms[j].coefficient;
                        flag = 1;
                    }
                }
                if(flag == 0){
                    result.num_of_terms += 1;
                    result.terms[result.num_of_terms - 1].coefficient = poly[i].terms[j].coefficient;
                    result.terms[result.num_of_terms - 1].exponent = poly[i].terms[j].exponent;
                }
            }
            i++;
        }

    }
    
    // output
    {
        printf("\n\nResult is:\n");
        for (i = 0; i < result.num_of_terms; i++)
        {
            printf("%d %d\n", result.terms[i].coefficient, result.terms[i].exponent);
        }
        
    }

}


