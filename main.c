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
    float number2 = -2;
    int number3 =-161235;
    char letter = 'a';
    int number = 345;
    int unumber = 356;
    double my_double = 0.00253514;
    double my_double_1 = 0.253514;
    char project_review  [] = "this project is awesome!!";


    printf(":%s:\n", "Hello, world!");
    printf(":%15s:\n", "Hello, world!");
    printf(":%.10s:\n", "Hello, world!");
    printf(":%-10s:\n", "Hello, world!");
    printf(":%-15s:\n", "Hello, world!");
    printf(":%.15s:\n", "Hello, world!");
    printf(":%15.10s:\n", "Hello, world!");
    printf(":%-15.10s:\n", "Hello, world!");

    printf("\n my printf");

    ft_printf(":%s:\n", "Hello, world!");
    ft_printf(":%15s:\n", "Hello, world!");
    ft_printf(":%.10s:\n", "Hello, world!");
    ft_printf(":%-10s:\n", "Hello, world!");
    ft_printf(":%-15s:\n", "Hello, world!");
    ft_printf(":%.15s:\n", "Hello, world!");
    ft_printf(":%15.10s:\n", "Hello, world!");
    ft_printf(":%-15.10s:\n", "Hello, world!");



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
