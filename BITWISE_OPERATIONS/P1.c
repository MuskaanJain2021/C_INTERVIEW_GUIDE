//Binary Bit Manipulation
// bit 31......bit3 bit2 bit1 bit0
//  31st        3rd   2nd  1st 0th  bit number
// Enter an integer (x): 23
// Enter bit position(index 0 based) to manipulate(n):3
// Setting bit 3 of 23 (00000000000000000000000000010111) : 31 (00000000000000000000000000011111)
// Clear bit 3 of 23 (00000000000000000000000000010111) : 23 (00000000000000000000000000010111)
// Toggle bit 3 of 23 (00000000000000000000000000010111) : 31 (00000000000000000000000000011111)
// Checking bit 3 of 23 (00000000000000000000000000010111): NOT SET

#include<stdio.h>
#include<stdlib.h>
char* DecToBin(int);
int main()
{
    int x ,n,bit;

    printf("Enter an integer (x): ");
    scanf("%d",&x);
    printf("Enter bit position(index 0 based) to manipulate(n):");
    scanf("%d",&n);

    //Setting a bit :SetBitRes (Bitwise OR)
    int SetBitRes = x|(1<<n);
    printf("Setting bit %d of %d (%s) : %d (%s)\n",n,x,DecToBin(x),SetBitRes,DecToBin(SetBitRes));
    //Clear a bit :ClearBitRes (Bitwise AND) 
    int ClearBitRes = x & ~(1<<n);
    printf("Clear bit %d of %d (%s) : %d (%s)\n",n,x,DecToBin(x),ClearBitRes,DecToBin(ClearBitRes));
    //Toggle a bit :ToggleBitRes(Bitwise XOR)
    int ToggleBitRes= x ^ (1<<n);
    printf("Toggle bit %d of %d (%s) : %d (%s)\n",n,x,DecToBin(x),ToggleBitRes,DecToBin(ToggleBitRes));
   //Checking a bit 0/1
   //bit= x & (1<<n);
   //bit?1:0;
    bit= x & (1<<n)?1:0;//bit at position n is set or not set  ie Extract the bit at position n
    printf("Checking bit %d of %d (%s): %s\n",n,x,DecToBin(x),bit?"SET":"NOT SET");
    
    return 0;
}
char* DecToBin(int num)
{
    char* bin = (char*)malloc(33); // Allocate memory for 32 bits + null terminator
    bin[32] = '\0'; // Set the null terminator at the end of the string
    int idx;
    for(idx=31; idx>=0; idx--)
    {
       if (num & (1 << idx)) // Check if the bit is set
         bin[31 - idx]='1'; // Set the corresponding index in the string to '1' and binary string is stored from msb to lsb fashion bin[31-idx]
       else
         bin[31 - idx]='0'; // Set the corresponding index in the string to '0' and binary string is stored from msb to lsb fashion bin[31-idx]
    }
    return bin;
}
