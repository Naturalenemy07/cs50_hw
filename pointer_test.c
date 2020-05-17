#include <stdio.h>

int swap(int,int);

int main(void)
{
    //These won't swap correctly, no pointers
    int odd = 15;
    int even = 8;

    swap(odd,even);

    printf("odd: %i\n", even);
    printf("even: %i\n", odd);



    //These will swap correctly because useing pointers
    int* ptr_odd;
    int* ptr_even;

    ptr_odd = 5;

    //HOW DO I PRINT A POINTER? I JUST WANT TO PRINT 5??? 
    printf("%p\n", (void *) ptr_odd);

    //swap(ptr_odd, ptr_even);

    //printf("odd: %i\n", ptr_even);
    //printf("even: %i\n", ptr_odd);

}

int swap(num1, num2)
{
    int hold;

    hold = num1;
    num2 = num1;
    num1 = hold;

    return 0;
}
