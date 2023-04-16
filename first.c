#include <stdio.h>

int main() {
int num,rev,rem,opt,sum,num2;
printf("Enter a number :");
scanf("%d",&num);
num2=num;
printf("Menu:\n1.Sum of all the digits.\n2.Reverse of a number.\nEnter your choice :");
scanf("%d",&opt);
if(opt==1)
{
    while(num>0)
    {
        rem=num%10;
        sum+=rem;
        num=num/10;
    }
    printf("The sum of all the digits in the number %d is %d",num2,sum);
}
else if(opt==2)
{
    while(num>0)
    {
        rem=num%10;
        rev=(rev*10)+rem;
        num=num/10;
    }
    printf("The reverse of the number %d is %d",num2,rev);
}
else{
    printf("Invalid choice");
}
    return 0;
}