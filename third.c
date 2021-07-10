#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])
{
   //int  tmp_input = atoi("7");			// DEBUG ONLY - read input_number
   int  tmp_input = atoi(argv[1]);			// read input_number as an int
   if (tmp_input > USHRT_MAX) {             // checking limit for unsigned-short MAX LIMIT
        exit(0);
   }
   unsigned short int input_number = (unsigned) tmp_input;  //converting given number to unsigned short

   unsigned short int this_bit, prev_bit=0;
   unsigned short int pair_cnt=0, one_cnt;

   while(input_number)
   {
       this_bit = input_number & 01;
       if( prev_bit && this_bit ) {          // if previous this_bit and present this_bit both 1's, increment pair_cnt
           pair_cnt++;
           prev_bit = 0;
       }
       else {
           prev_bit = this_bit;
	   }

       if (this_bit)                        // increment one_cnt if this_bit=1
           one_cnt++;

       input_number >>= 1;				    // shift input number to right for next bit
   }
   if (one_cnt%2 == 0)               		// find out odd/even
       printf("Even-Parity\t%d",pair_cnt);
   else
       printf("Odd-Parity\t%d",pair_cnt);

    return 0;
}