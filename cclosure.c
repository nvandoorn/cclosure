#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100 * 1024 // each file gets 100KB buffer

int cclosure_parser(const char* in, char* out) {
  // for now just copy between them
  strcpy(out, in);
  return 0;
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    printf("Usage ./cclosure <filename>.c\n");
    return 1;
  }
  // load up the input file
  char inBuff[BUFFER_SIZE], outBuff[BUFFER_SIZE], outName[1024];
  char *inName = argv[1];
  FILE* f = fopen(inName, "r");
  fread(inBuff, 1, BUFFER_SIZE, f);
  fclose(f);

  // do the work
  cclosure_parser(inBuff, outBuff);

  // write the output
  snprintf(outName, 1024, "%s.out.c", inName);
  f = fopen(outName, "w");
  fwrite(outBuff, 1, strlen(outBuff), f);
}
