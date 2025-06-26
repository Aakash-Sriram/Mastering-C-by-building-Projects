#include "printf.h"

int main(){
    char *greeting = "world";
    char letter = 'A';
    int number = 42;
    float pi = 3.14159;

    my_printf("Demo of my_printf\r\n");
    my_printf("String: %s\r\n", greeting);
    my_printf("Char: %c\r\n", letter);
    my_printf("Integer: %d\r\n", number);
    my_printf("Hex (lower): %x\r\n", number);
    my_printf("Hex (upper): %X\r\n", number);
    my_printf("Float: %f\r\n", pi);
    my_printf("Octal: %o\r\n",number);
    my_printf("Literal %%: 100%% done!\r\n");
    my_printf("Unsupported: %q\r\n", 123);
  /*
   * For now only the above mentioned format specifiers are handled
   * Unsuppored format specifiers are printed with a special emoji */
}
