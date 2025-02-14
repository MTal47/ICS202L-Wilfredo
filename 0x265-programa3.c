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
[integer pointer] points to 0xbffff810, which contains the char 'a'
[integer pointer] points to 0xbffff814, which contains the char 'e'
[integer pointer] points to 0xbffff818, which contains the char '8'
[integer pointer] points to 0xbffff81c, which contains the char '
[integer pointer] points to 0xbffff820, which contains the char '?'
[char pointer] points to 0xbffff7f0, which contains the integer 1
[char pointer] points to 0xbffff7f1, which contains the integer 0
[char pointer] points to 0xbffff7f2, which contains the integer 0
[char pointer] points to 0xbffff7f3, which contains the integer 0
[char pointer] points to 0xbffff7f4, which contains the integer 2
*/
