#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void sort(int base[], int length);
void print_list(int base[], int length);
void test(int base[], int length);
void tests();
void benchmarks();
void sort(int base[], int length) {
 /* Your sorting algorithm goes here. */
 /*insertion sort algorithm*/
 int i, y, a;
 for (i = 1; i < length; i++)
 {
 y = base[i]; /*pick element*/
 a = i - 1;
 while (a >= 0 && base[a] > y)

 {

 base[a + 1] = base[a]; /*moves to next position*/
 a = a - 1;

 }

 base[a + 1] = y; /*insert at a+1 position*/
 }
}
/* Print a list to standard output. */
void print_list(int base[], int length) {
 for (int n = 0; n < length; n++) {
 printf("%d ", base[n]);
 }
 printf("\n");
}
/* Print a list, sort it, then print it again. */
void test(int base[], int length) {
 printf("Before sorting: ");
 print_list(base, 10);
 sort(base, 10);
 printf("After sorting: ");
 print_list(base, 10);
}
/* Print, sort, print list for arrays not with 10 elements*/
void test2(int base[], int length) {
 printf("Before sorting: ");
 print_list(base, length);
 sort(base, length);
 printf("After sorting: ");
 print_list(base, length);
}
/* Run some tests of the sorting algorithm. */
void tests() {

 int test_0[] = {0, 1, 5, -4, -8, 3, 2, 9, -7, 6};
 test(test_0, sizeof(test_0)/sizeof(int));

 /* Your test cases go here. */

 /* sorting empty list of length 0. */
 int test_1[] = {};
 test2(test_1, sizeof(test_1)/sizeof(int));

 /* sorting a list of length 1*/
 int test_2[] = {8};
 test2(test_2, sizeof(test_2)/sizeof(int));

 /*sorting a list of length 2*/
 int test_3[] = {5, 2};
 test2(test_3, sizeof(test_3)/sizeof(int));

 /*sorting a list with at least 2 equal elements*/
 int test_4[] = {8, 3, 26, 26, 22, 2};
 test2(test_4, sizeof(test_4)/sizeof(int));

}
/* Benchmark the sorting algorithm. */
void benchmarks() {
 /* Your benchmarking code goes here. */
 int c = 0;
 int numelements;
 printf("Length, time (seconds)");

 for (int g = 0; g < 20; g++) { /*creates a loop that runs until completed 20 times*/
 numelements = c; /*this will be the number of elements in the array*/
 c = c + 50; /*number of elements goes up by 50 each time*/
 int array[numelements];
 int s1 = sizeof(array) / sizeof(int); /*calculates size of array*/

 for (int j = 1; j < s1; j++) {
 array[g] = rand() % 100; /*randomises numbers in array from 0 - 100*/

 }

 clock_t start_t = clock(); /*counts time until this point*/
 sort(array, s1); /*this calls the program sort*/
 start_t = clock() - start_t; /* counts time and subtracted by previous value of start_t to
find time of just algorithm*/
 double time = ((double)start_t) / CLOCKS_PER_SEC; /*time converted into seconds*/
 printf("\n%d, %f", s1, time); /*displays time taken and length of array*/
 }

}
int main() {
 tests();
 benchmarks();
 exit(0);
}