#include "misc.h"
#include <math.h>

/*COVERED FEATURES
 * c 	Character
d or i 	Signed decimal integer
e 	Scientific notation (mantissa/exponent) using e character
E 	Scientific notation (mantissa/exponent) using E character
f 	Decimal floating point
g 	Uses the shorter of %e or %f
G 	Uses the shorter of %E or %f
o 	Unsigned octal
s 	String of characters
u 	Unsigned decimal integer
x 	Unsigned hexadecimal integer
X 	Unsigned hexadecimal integer (capital letters)
*/

int main() {
int Fahrenheit;
  //  ft_printf("%E %E %E",10.543,10.543,10.543);


/*
    printf(":%s:\n", "Hello, world!");
    printf(":%15s:\n", "Hello, world!");
    printf(":%.10s:\n", "Hello, world!");
    printf(":%-10s:\n", "Hello, world!");
    printf(":%-15s:\n", "Hello, world!");
    printf(":%.15s:\n", "Hello, world!");
    printf(":%15.10s:\n", "Hello, world!");
    printf(":%-15.10s:\n", "Hello, world!");

    printf("\nMY PRINTF\n");

    ft_printf(":%s:\n", "Hello, world!");
    ft_printf(":%15s:\n", "Hello, world!");
    ft_printf(":%.10s:\n", "Hello, world!");
    ft_printf(":%-10s:\n", "Hello, world!");
    ft_printf(":%-15s:\n", "Hello, world!");
    ft_printf(":%.15s:\n", "Hello, world!");
    ft_printf(":%15.10s:\n", "Hello, world!");
    ft_printf(":%-15.10s:\n", "Hello, world!");
*/
    /*

    printf("The color: %s\n", "blue");
    printf("First number: %d\n", 12345);
    printf("Second number: %04d\n", 25);
    printf("Third number: %i\n", 1234);
    printf("Float number: %3.2f\n", 3.14159);
    printf("Hexadecimal: %x\n", 255);
    printf("Octal: %o\n", 255);
    printf("Unsigned value: %u\n", 150);
    printf("Just print the percentage sign %%\n", 10);


    printf("\nMY PRINTF\n");

    ft_printf("The color: %s\n", "blue");
    ft_printf("First number: %d\n", 12345);
    ft_printf("Second number: %04d\n", 25);
    ft_printf("Third number: %i\n", 1234);
    ft_printf("Float number: %3.2f\n", 3.14159);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("Octal: %o\n", 255);
    ft_printf("Unsigned value: %u\n", 150);
    ft_printf("Just print the percentage sign %%\n", 10);





    printf( "%.3f\n%.3g\n%.3f\n%.3g\n", 100.2, 100.2, 3.1415926, 3.1415926 );

    printf("\nMY PRINTF\n");

    ft_printf( "%.3f\n%.3g\n%.3f\n%.3g\n", 100.2, 100.2, 3.1415926, 3.1415926 );

    printf( "%#x\n", 1225 );
    printf( "%#X\n", 1343 );
    printf( "%#o\n", 145245 );
    printf( "%x\n", 827 );
    printf( "%X\n", 13242 );
    printf( "%o\n", 239085 );

    printf("\nMY PRINTF\n");

    ft_printf( "%#x\n", 1225 );
    ft_printf( "%#X\n", 1343 );
    ft_printf( "%#o\n", 145245 );
    ft_printf( "%x\n", 827 );
    ft_printf( "%X\n", 13242 );
    ft_printf( "%o\n", 239085 );


    for( char ch = 75 ; ch <= 100; ch++ )
    {
        printf("ASCII value = %d, Character = %c\n", ch , ch );
    }
    printf("\nMY PRINTF\n");
    for( char ch = 75 ; ch <= 100; ch++ )
    {
        ft_printf("ASCII value = %d, Character = %c\n", ch , ch );
    }



    printf("demostrate some flags  %+010d\n", 14132);
    printf("demostrate some flags  %010d\n", 14132);
    printf("demostrate some flags  %10d\n", 14132);
    printf("demostrate some flags  %+10d\n", 14132);
    printf("demostrate some flags  %+10.5f\n", 10.32);
    printf("demostrate some flags  %+10.4f\n", -15.25);
    printf("demostrate some flags  %+g\n", 10.32);
    printf("demostrate some flags  %+g\n", -15.25);
    printf("demostrate some flags  %-10G hey there \n", 10.32);
    printf("demostrate some flags  %-10G spaces work ? \n", -15.25);
    printf("demonstrate power numbers %e\n",1414.523);
    printf("demonstrate power numbers %+E\n",145.25235);
    printf("demonstrate power numbers %+E\n",0.0015);


    printf("\nMY PRINTF\n");

    ft_printf("demostrate some flags  %+010d\n", 14132);
    ft_printf("demostrate some flags  %010d\n", 14132);
    ft_printf("demostrate some flags  %10d\n", 14132);
    ft_printf("demostrate some flags  %+10d\n", 14132);
    ft_printf("demostrate some flags  %+g\n", 10.32);
    ft_printf("demostrate some flags  %+g\n", -15.25);
    ft_printf("demostrate some flags  %-10G hey there \n", 10.32);
    ft_printf("demostrate some flags  %-10g spaces work ? \n", -15.25);

    ft_printf("demonstrate power numbers %e\n",1414.523);
    ft_printf("demonstrate power numbers %+E\n",145.25235);
    ft_printf("demonstrate power numbers %+E\n",0.0015);

*/


    for (Fahrenheit = 0; Fahrenheit <= 300; Fahrenheit = Fahrenheit + 20)
        printf("%3d %06.3f\n", Fahrenheit, (5.0/9.0)*(Fahrenheit-32));

    printf("\nMY PRINTF\n");

    for (Fahrenheit = 0; Fahrenheit <= 300; Fahrenheit = Fahrenheit + 20)
        ft_printf("%3d %06.3f\n", Fahrenheit, (5.0/9.0)*(Fahrenheit-32));


















/*
        printf("%2.5e \n %2.5e",my_double,my_double);
        printf("\n");
        ft_printf("% 2.5e \n %2.5e \n %2.5e \n % 2.5e ",my_double,my_double,my_double,my_double);

    //ft_printf("%2.11f \n %2.11f \n %2.11f \n %2.11f %2.11f  ",
    // my_double,my_double,my_double,my_double,my_double);


    ft_printf("%+010d",number);


      printf("DOUBLE : print a floating_point with precision: %10.5f"
                     "\n print a floating_point with precision and power: %10.5E "
                     "\n print a floating_point with precision and no trailing zeros  %10.5g ",my_double,my_double,my_double);

      printf("\n");

     ft_printf("DOUBLE : print a floating_point with precision: %10.5f"
                     "\n print a floating_point with precision and power: %10.5e "
                     "\n print a floating_point with precision and no trailing zeros  %10.5g"
                       "\n printf floating point %10.5e"
                       "\n ",
               my_double,my_double,my_double,my_double);

 //   ft_printf("print a floating_point with precision %10.5f",my_double);


 /*
    printf("My favourite letter is %c  I also like the %d and the  %+d as well as the double "
                   "% f this way too %e %E and %G the unsigned can by in hexa or octa with flags:"
                   "%#o %#X %#x and I think that %s  ! \n  also double and string precision "
                   "double : %3.5f  string : %3.4s I also added the # flag for floats to leave trailing"
                   " zeroes when using #g or #G %#g precision now works great:\n%12.6f \n%5.4f \n%3.6f\n%+012.6f ",
           letter,number3,unumber,my_double,my_double,my_double,my_double,unumber,unumber,unumber,project_review,
     my_double,project_review,number2,my_double_1,my_double_1,my_double_1,my_double_1);
    printf("\n");
    printf("\n");
    printf("\n");
    ft_printf("My favourite letter is %c  I also like the %d and the  %+d as well as the double "
                      "% f this way too %e %E and %G the unsigned can by in hexa or octa with flags:"
                      "%#o %#X %#x and I think that %s  ! \n  also double and string precision "
                      "double : %3.5f  string : %3.4s I also added the # flag for floats to leave trailing"
                      " zeroes when using #g or #G %#g precision now works great:\n%12.6f \n%5.4f \n%3.6f\n%+012.6f ",
              letter,number3,unumber,my_double,my_double,my_double,my_double,unumber,unumber,unumber,project_review,
              my_double,project_review,number2,my_double_1,my_double_1,my_double_1,my_double_1);
*/
    return 0;
}
