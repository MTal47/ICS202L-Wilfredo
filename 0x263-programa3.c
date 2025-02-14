#include <stdio.h>
int main() {
int int_var = 5;
int *int_ptr;
int_ptr = &int_var; 
printf("int_ptr = 0x%08x\n", int_ptr);
printf("&int_ptr = 0x%08x\n", &int_ptr);
printf("*int_ptr = 0x%08x\n\n", *int_ptr);
printf("int_var is located at 0x%08x and contains %d\n", &int_var, int_var);
printf("int_ptr is located at 0x%08x, contains 0x%08x, and points to %d\n\n",
&int_ptr, int_ptr, *int_ptr);
}

/* 
output:
int_ptr = 0x5e13574c
&int_ptr = 0x5e135740
*int_ptr = 0x00000005

int_var is located at 0x5e13574c and contains 5
int_ptr is located at 0x5e135740, contains 0x5e13574c, and points to 5
  */
