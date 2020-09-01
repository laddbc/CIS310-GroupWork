#include <stdlib.h>
#include <stdio.h>
using namespace std;

/*
 * Example.cpp
 * A example of C programming (char *, printf, etc.) inside
 * a C++ program (better error messages and convenience features).
 *
 * @author Brian C. Ladd
 * @email laddbc@potsdam.edu
 * @course CIS 310 Operating Systems
 * @assignment Reading a C/C++ Program
 * @date Fall 2020
 * @note Based on work done by Tammy VanDeGrift
 */

/*
 * Calculates a lucky number given two integer parameters.
 *
 * @param age of the person for whom the number is generated
 * @param length_of_name length, in characters, of person's last name
 * @return the lucky number for the person described
 */
int generate_lucky_number(int age, int length_of_name) {
  return 127 - age + length_of_name * 3;
}

/*
 * Return the number of characters in the array that are in use.
 * Code is similar to that in std::str_len.
 *
 * @param str pointer at a C-style string
 * @return the number of characters before the a null chacarter
 * @warning NO ERROR CHECKING
 */
int len(char * str) {
  int i = 0;
  for (i = 0; str[i] != '\0'; i++)
    ; // empty body
  return i;
}

/*
 *  Prompt user for their name and age. Use data to calculate and
 *  report user's lucky number information.
 *
 *  @param argc the number of entries in the argument vector
 *  @param argv the argument vector of strings from cammandline
 *  @return 0 if all is well; non-zero to report an error.
 */
int main(int argc, char *argv[]) {
  char user_name[100];
  int age = -1;
  int length_of_name = 0;
  int lucky_number = 0;

  printf("CIS 310 Operating Systems...What Does It Do?\n");
  // Compare C++ to Java: What are the similarities? The differences?

  printf("What is your name? ");
  scanf("%s", user_name);
  // scan a string (%s) into the named char * or char[]
  // note: scanf is a security nightmare.

  while (age <= 0) {
    printf("%s, what is your age? ", user_name);
    scanf("%d", &age);
    // scan a decimal number (%d) into an int; need address
  }

  length_of_name = len(user_name);
  lucky_number = generate_lucky_number(age, length_of_name);
  printf("So, %s, your lucky number is %d\n",user_name, lucky_number);

  // stdlib.h defines EXIT_SUCCESS (and EXIT_FAILURE) for return from main
  return EXIT_SUCCESS;
}
