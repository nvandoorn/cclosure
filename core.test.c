#include "core.h"
#include "test-lib.h"
#include <string.h>

int testParserMatch() {
  char inBuff[FILE_BUFFER_SIZE], outBuff[FILE_BUFFER_SIZE];
  int r;
  r = cclosure_processor(inBuff, outBuff, FILE_BUFFER_SIZE);
  if (r)
    return r;
  if (!strcmp(inBuff, outBuff))
    return -1;
  return 0;
}

int main() {
  syncTest("cclosure_parser", "Input & output of parser match",
           testParserMatch);
}
