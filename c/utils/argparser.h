#pragma once
#include "types.h"

typedef enum {
  ArgumentParsingResult_Ok = 0,
  ArgumentParsingResult_ArgumentsNull,
  ArgumentParsingResult_ArgvNull,
  ArgumentParsingResult_NotEnoughArguments,
  ArgumentParsingResult_TooManyArguments,
  ArgumentParsingResult_AllocFailed,
} ArgumentParsingResult;

typedef struct {
  size_t amount;
  string executable;
  string* arguments;
} ProgramArguments;

ArgumentParsingResult parse_arguments(int const argc, char** const argv,
                                      ProgramArguments* const arguments, size_t const min_arguments,
                                      size_t const max_arguments);

void print_arguments(ProgramArguments const* const arguments);

string argument_parsing_result_to_string(ArgumentParsingResult result);

void free_program_arguments(ProgramArguments const* const arguments);
