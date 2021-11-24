#include <stdio.h>
#include <stdlib.h>
int check_exp(int num);

int main()
{
    printf("Enter size of input:\n");
    int num_of_num;
    scanf("%d",&num_of_num);
    if(num_of_num <= 0)
    {
        printf("Invalid size\n");
        exit(0);
    }
    printf("Enter numbers:\n");
    int* arr_num=malloc(sizeof(int)*num_of_num);
    int* arr_exp=malloc(sizeof(int)*num_of_num);
    for(int i=0;i<num_of_num;i++)
    {
        if(scanf("%d",&arr_num[i]) != 1)
        {
            printf("Invalid number\n");
            free(arr_num);
            free(arr_exp);
            exit(0);
        }
    }
    int exp;
    int sum_exp;
    for(int i=0;i<num_of_num;i++)
    {
        exp=check_exp(arr_num[i]);
        arr_exp[i]=exp;
    }
    for(int i=0;i<num_of_num;i++)
    {
        if(arr_exp[i]>-1)
        {
            printf("The number %d is a power of 2: %d = 2^%d\n",arr_num[i],arr_num[i],arr_exp[i]);
            sum_exp=sum_exp+arr_exp[i];
        }
    }
    printf("Total exponent sum is %d\n",sum_exp);
    free(arr_num);
    free(arr_exp);
    return 0;    
}


int check_exp(int num)
{
    int exp=0;
    if(num < 1)
    {
        return -5;
    }
    while(num % 2 == 0 && num != 1)
    {
        num=num/2;
        exp++;
    }
    if(num == 1)
    {
        return exp;
    }
    else
    {
        return -5;
    }   
}