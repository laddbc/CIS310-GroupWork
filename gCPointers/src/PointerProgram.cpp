
#include <stdlib.h>
#include <stdio.h>
using namespace std;

/*
 * PointerProgram.cpp
 * A C/C++ program that uses pointers at int and char.
 *
 * @author Brian C. Ladd
 * @email laddbc@potsdam.edu
 * @course CIS 310 Operating Systems
 * @assignment Pointers in C/C++
 * @date Fall 2020
 * @note Based on work done by Tammy VanDeGrift
 */

/*
 *  Declare many local variables, simple and arrays. Then print out
 *  information about them.
 *  @param argc the number of entries in the argument vector
 *  @param argv the argument vector of strings from cammandline
 *  @return 0 if all is well; non-zero to report an error.
 *  @note: Each array variable is assumed to have the given /decimal/
 *         base address. Assume (pretend) %p prints pointer in decimal.
 *
 *         When it is actually compiled and run, addresses print in
 *         hexadecimal and are not so evenly spaced.
 */
int main(int argc, char *argv[]) {
  int first[] = {0, 4, 12, 16, 25};         // base address: 1000 DECIMAL
  int * second[] = { &first[4], &first[2]}; // base address: 2000 DECIMAL
  char name[] = "Brian C. Ladd";            // base address: 3000 DECIMAL

  int count = 0;                            // counts output statements
  int i;                                    // utility index variable
  int * ptr = first;                        // same as &first[0]
  int * * ptrptr = &second[0];              // same as <?????>
  char * str = name;

  printf(">>>>> Dump Memory before count = 0 <<<<<\n");

  // first and ptr
  printf("%d: ptr is %p\n", count++, ptr);
  printf("%d: *ptr is %d\n", count++, *ptr);

  (*ptr)++;
  printf("%d: *ptr is %d\n", count++, *ptr);

  ptr++;
  printf("%d: ptr is %p\n", count++, ptr);
  printf("%d: *ptr is %d\n", count++, *ptr);

  ptr += 1;
  *ptr = 10;
  i = ptr - first; //
  printf("%d: ptr is %p\n", count++, ptr);
  printf("%d: first[%d] is %d\n", count++, i, first[i]);
  printf("<<<<< Dump Memory after count = %d >>>>>\n", count - 1);

  // second, ptrptr, and interaction with first
  ptrptr++;
  printf("%d: *ptrptr is %p\n", count++, *ptrptr);
  printf("%d: **ptrptr is %d\n", count++, **ptrptr);

  ptrptr--;
  (*ptr)--;
  printf("%d: second[0], second[1] are %p, %p\n", count++, second[0], second[1]);
  printf("%d:     dereferenced they are %d, %d\n", count++, *second[0], *second[1]);
  printf("%d:     their addresses are %p, %p\n", count++, &second[0], &second[1]);
  printf("<<<<< Dump Memory after count = %d >>>>>\n", count - 1);

  // name and str
  printf("%d: str is %p\n", count++, str);
  printf("%d: *str is %c\n", count++, *str);

  str += 6;
  (*str) += 1;
  printf("%d: str is %p\n", count++, str);
  printf("%d: *str is %c\n", count++, *str);
  printf("%d: name is %s\n", count++, name);

  printf("<<<<< Dump Memory after count = %d >>>>>\n", count - 1);

  // stdlib.h defines EXIT_SUCCESS (and EXIT_FAILURE) for return from main
  return EXIT_SUCCESS;
}
