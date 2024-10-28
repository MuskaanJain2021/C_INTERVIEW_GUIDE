/*setting and unsetting the k-th bit of integer */
#include <stdio.h>
void set_unset_kth_bit(int *number, int pos, int choice)
{
    if (choice == 1)
        *number |= (1 << pos);/*Turn on the kth bit*/
    else
        *number &= ~(1 << pos);/*Turn off the kth Bit*/
    
}


int main()
{
    int num1=0,pos,choice;

    /*Ask user the number to be entered*/
    printf("Enter an integer: ");
    scanf("%d",&num1);


    /*Prompt user to enter the action bit (set or unset) and bit position*/
    printf("\n Set Bit  1  Unset Bit  0\n");
    scanf("%d",&choice);

    printf("\nEnter the bit position (0 based indexing):");
    scanf("%d",&pos);

    /* Call the function to set or unset the specified bit*/
    set_unset_kth_bit(&num1,pos,choice);

    /*Display final result*/
   if (choice == 1)
        printf("\nAfter setting the bit at position %d: %d (Hex: %#X)\n", pos, num1, num1);
    else
        printf("\nAfter unsetting/clearing the bit at position %d: %d (Hex: %#X)\n", pos, num1, num1);

    
    
    return 0;
}