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
    int number3 = -161235;
    char letter = 'a';
    int number = -345;
    int unumber = 356;
    double my_double = 0.23425;
    double my_double_1 = 223.253514;
    char project_review  [] = "this project is awesome!!";

    printf("My favourite letter is %c  I also like the %d and the  %+d as well as the double "
                   "% f this way too %e %E and %G the unsigned can by in hexa or octa with flags:"
                   "%#o %#X %#x and I think that %s  ! \n  also double and string precision "
                   "double : %3.5f  string : %3.4s I also added the # flag for floats to leave trailing"
                   " zeroes when using #g or #G %#g precision now works great:\n%12.6f \n%5.4f \n%3.6f\n%+012.6f !",
           letter,number3,unumber,my_double,my_double,my_double,my_double,unumber,unumber,unumber,project_review,
     my_double,project_review,number2,my_double_1,my_double_1,my_double_1,my_double_1);
    printf("\n");
    ft_printf("My favourite letter is %c  I also like the %d and the  %+d as well as the double "
                      "% f this way too %e %E and %G the unsigned can by in hexa or octa with flags:"
                      "%#o %#X %#x and I think that %s  ! \n  also double and string precision "
                      "double : %3.5f  string : %3.4s I also added the # flag for floats to leave trailing"
                      " zeroes when using #g or #G %#g precision now works great:\n%12.6f \n%5.4f \n%3.6f\n%+012.6f !",
              letter,number3,unumber,my_double,my_double,my_double,my_double,unumber,unumber,unumber,project_review,
              my_double,project_review,number2,my_double_1,my_double_1,my_double_1,my_double_1);

 return 0;
}
