#include "core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int getRandomInt() {
  srand(time(NULL));
  return rand();
}

/**
 * Generate a random name for "anonymous" routines
 */
int generateRoutineName(char *out, int size) {
  snprintf(out, size, "cclosure_routine%d", getRandomInt());
  return 0;
}

/**
 * Given the input
 * 'int (int a, double b, void* c) { ... }'
 *
 * generate
 *
 * 'int routineName(int a, double b, void* c) { ... }'
 */
int generateRoutineSignature(const char *in, char *out) { return -1; }

/**
 * Pull all "closure routines" out of `in`
 * (replacing them with their generated name),
 * write the named version to `out`
 * and store parsed closures in `container`
 */
int extractClosures(const char *in, char *out,
                    struct ClosureContainer_t *container) {
  return -1;
}

/**
 * Write each member of `container` to `out`
 * (including prototypes)
 */
int writeClosures(char *out, struct ClosureContainer_t *container) {
  char *buff[STRING_BUFFER_SIZE];
  struct Closure_t *c;
  for (int i = 0; i < container->n; i++) {
    c = &container->closures[i];
    snprintf(buff, STRING_BUFFER_SIZE, "%s;", c->signature);
    strcat(out, buff);
  }
  for (int i = 0; i < container->n; i++) {
    c = &container->closures[i];
    snprintf(buff, STRING_BUFFER_SIZE, "%s {\n", c->signature);
    strcat(out, buff);
    strcat(out, c->body);
    strcat(out, "\n}\n");
  }
  return 0;
}

/**
 * Entry point for the parser
 */
int cclosure_processor(const char *in, char *out, int outSize) {
  int r;
  struct ClosureContainer_t container = {.n = 0};

  r = extractClosures(in, out, &container);
  if (r)
    goto done;

  r = writeClosures(out, &container);
  if (r)
    goto done;

done:
  return r;
}

/**
 * Entry point for the main binary
 */
int cclosure_core(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage ./cclosure <filename>.c\n");
    return 1;
  }
  // load up the input file
  char inBuff[FILE_BUFFER_SIZE], outBuff[FILE_BUFFER_SIZE],
      outName[STRING_BUFFER_SIZE];
  char *inName = argv[1];
  FILE *f = fopen(inName, "r");
  fread(inBuff, 1, FILE_BUFFER_SIZE, f);
  fclose(f);

  // do the work
  cclosure_parser(inBuff, outBuff, FILE_BUFFER_SIZE);

  // write the output
  snprintf(outName, STRING_BUFFER_SIZE, "%s.out.c", inName);
  f = fopen(outName, "w");
  fwrite(outBuff, 1, strlen(outBuff), f);
  return 0;
}
