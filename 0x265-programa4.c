#include <stdio.h>
int main() {
int i;
char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
int int_array[5] = {1, 2, 3, 4, 5};
char *char_pointer;
int *int_pointer;
char_pointer = (char *) int_array; 
int_pointer = (int *) char_array;
for(i=0; i < 5; i++) { 
printf("[integer pointer] points to %p, which contains the char '%c'\n",
int_pointer, *int_pointer);
int_pointer = (int *) ((char *) int_pointer + 1);
}
for(i=0; i < 5; i++) { 
printf("[char pointer] points to %p, which contains the integer %d\n",
char_pointer, *char_pointer);
char_pointer = (char *) ((int *) char_pointer + 1);
}
}

/*output:
[integer pointer] points to 0xbffff810, which contains the char 'a'
[integer pointer] points to 0xbffff811, which contains the char 'b'
[integer pointer] points to 0xbffff812, which contains the char 'c'
[integer pointer] points to 0xbffff813, which contains the char 'd'
[integer pointer] points to 0xbffff814, which contains the char 'e'
[char pointer] points to 0xbffff7f0, which contains the integer 1
[char pointer] points to 0xbffff7f4, which contains the integer 2
[char pointer] points to 0xbffff7f8, which contains the integer 3
[char pointer] points to 0xbffff7fc, which contains the integer 4
[char pointer] points to 0xbffff800, which contains the integer 5
*/
