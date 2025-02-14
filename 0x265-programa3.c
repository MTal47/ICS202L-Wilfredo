#include <stdio.h>
int main() {
int i;
char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
int int_array[5] = {1, 2, 3, 4, 5};
char *char_pointer;
int *int_pointer;
char_pointer = int_array;
int_pointer = char_array; 
for(i=0; i < 5; i++) { 
printf("[integer pointer] points to %p, which contains the char '%c'\n",
int_pointer, *int_pointer);
int_pointer = int_pointer + 1;
}
for(i=0; i < 5; i++) { 
printf("[char pointer] points to %p, which contains the integer %d\n",
char_pointer, *char_pointer);
char_pointer = char_pointer + 1;
}
}

/*output:
pointer_types2.c: In function `main':
pointer_types2.c:12: warning: assignment from incompatible pointer type
pointer_types2.c:13: warning: assignment from incompatible pointer type
*/
