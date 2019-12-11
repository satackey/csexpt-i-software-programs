#!/bin/bash

SOURCE_CODE="${1//\\/\/}"
SOURCE_CODE_FILE="${SOURCE_CODE##*\/}"
SOURCE_CODE_DIR="$(dirname $SOURCE_CODE)"
COMPILE_TO_DIR="$SOURCE_CODE_DIR/.bin"
COMPILE_TO_FILE="${SOURCE_CODE_FILE%.*}.out"
COMPILE_TO="$COMPILE_TO_DIR/$COMPILE_TO_FILE"

mkdir -p "$COMPILE_TO_DIR"

gcc -g -o "$COMPILE_TO" "$SOURCE_CODE"

exit $?

echo "Congratulations!! Successfully Compiled."
echo "To run: ./$COMPILE_TO"
