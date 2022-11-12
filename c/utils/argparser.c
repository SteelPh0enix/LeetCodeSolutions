#include "argparser.h"

#include <stdio.h>
#include <string.h>

ArgumentParsingResult parse_arguments(int const argc, char** const argv,
                                      ProgramArguments* const arguments, size_t const min_arguments,
                                      size_t const max_arguments) {
  if (argv == NULL) {
    return ArgumentParsingResult_ArgvNull;
  }

  if (arguments == NULL) {
    return ArgumentParsingResult_ArgumentsNull;
  }

  size_t const arguments_amount = argc - 1;

  if (arguments_amount < min_arguments) {
    return ArgumentParsingResult_NotEnoughArguments;
  }

  if (arguments_amount > max_arguments) {
    return ArgumentParsingResult_TooManyArguments;
  }

  memset(arguments, 0x00, sizeof(ProgramArguments));
  arguments->amount = arguments_amount;
  arguments->executable = argv[0];
  arguments->arguments = malloc(arguments_amount * sizeof(string));
  if (arguments->arguments == NULL) {
    return ArgumentParsingResult_AllocFailed;
  }

  for (size_t i = 0; i < arguments_amount; i++) {
    arguments->arguments[i] = argv[i + 1];
  }

  return ArgumentParsingResult_Ok;
}

void print_arguments(ProgramArguments const* const arguments) {
  if (arguments == NULL) {
    printf("Provided NULL pointer instead of arguments!\n");
    return;
  }

  printf("Program %s executed with %lu arguments:\n", arguments->executable, arguments->amount);
  for (size_t i = 0; i < arguments->amount; i++) {
    printf("\t%lu: %s\n", (i + 1), arguments->arguments[i]);
  }
}

string argument_parsing_result_to_string(ArgumentParsingResult result) {
  switch (result) {
    case ArgumentParsingResult_Ok:
      return "OK";
    case ArgumentParsingResult_ArgumentsNull:
      return "Pointer to arguments structure is NULL";
    case ArgumentParsingResult_ArgvNull:
      return "Pointer to argv is NULL";
    case ArgumentParsingResult_NotEnoughArguments:
      return "Not enough arguments";
    case ArgumentParsingResult_TooManyArguments:
      return "Too many arguments";
    case ArgumentParsingResult_AllocFailed:
      return "Allocation for arguments buffer has failed";
  }
}

void free_program_arguments(ProgramArguments const* const arguments) {
  if (arguments != NULL) {
    free(arguments->arguments);
  }
}
