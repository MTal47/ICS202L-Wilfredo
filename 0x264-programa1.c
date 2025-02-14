#include <stdio.h>
int main() {
char string[10];
int A = -73;
unsigned int B = 31337;
strcpy(string, "sample");
printf("[A] Dec: %d, Hex: %x, Unsigned: %u\n", A, A, A);
printf("[B] Dec: %d, Hex: %x, Unsigned: %u\n", B, B, B);
printf("[field width on B] 3: '%3u', 10: '%10u', '%08u'\n", B, B, B);
printf("[string] %s Address %08x\n", string, string);
printf("variable A is at address: %08x\n", &A);
}

/*
output:
[A] Dec: -73, Hex: ffffffb7, Unsigned: 4294967223
[B] Dec: 31337, Hex: 7a69, Unsigned: 31337
[field width on B] 3: '31337', 10: ' 31337', '00031337'
[string] sample Address bffff870
variable A is at address: bffff86c
*/
