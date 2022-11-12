#!/bin/sh
while getopts d flag; do
  case "${flag}" in
  d) debug_mode=1 ;;
  esac
done

shift $((OPTIND - 1))
[[ "${1}" == "--" ]] && shift

additional_libs="utils/argparser.c"

if [[ debug_mode -eq 1 ]]; then
  echo "Building $1 in debug mode"
  clang -Wall -Wextra -Wpedantic -Werror -std=c11 -O0 -g -o bin/$1_d $additional_libs $1.c
else
  echo "Building $1 in release mode"
  clang -Wall -Wextra -Wpedantic -Werror -std=c11 -O2 -o bin/$1 $additional_libs $1.c
fi
