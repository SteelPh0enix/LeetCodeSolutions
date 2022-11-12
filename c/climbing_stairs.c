#include <stdio.h>

#include "utils/ansi_color_codes.h"
#include "utils/argparser.h"

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

int climbStairs(int const stairs) { return stairs; }

int main(int argc, char** argv) {
  ProgramArguments args;

  ArgumentParsingResult result = parse_arguments(argc, argv, &args, 1, 1);
  if (result != ArgumentParsingResult_Ok) {
    printf("Arguments parsing error (%u): %s\n", result, argument_parsing_result_to_string(result));
    return result;
  }

  char* str_end = NULL;
  int const stairs = strtol(args.arguments[0], &str_end, 10);

  if (str_end == args.arguments[0]) {
    printf("Couldn't parse amount of stairs, expected a number, got '%s'!\n", args.arguments[0]);
    return 10;
  }

  printf("You can climb in " BGRN "%d" CRESET " ways to the top of the stairs\n",
         climbStairs(stairs));

  free_program_arguments(&args);
}
