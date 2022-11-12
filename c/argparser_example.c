#include <stdio.h>

#include "utils/argparser.h"

int main(int argc, char** argv) {
  ProgramArguments args;

  ArgumentParsingResult parsing_result = parse_arguments(argc, argv, &args, 0, 100);
  if (parsing_result == ArgumentParsingResult_Ok) {
    print_arguments(&args);
  } else {
    printf("There was an error while parsing arguments: %s (code %u)\n",
           argument_parsing_result_to_string(parsing_result), parsing_result);
  }

  free_program_arguments(&args);
  return parsing_result;
}
