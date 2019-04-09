#ifndef CCLOSURE_CORE_H
#define CCLOSURE_CORE_H

#define FILE_BUFFER_SIZE 100 * 1024 // each file gets 100KB buffer
#define STRING_BUFFER_SIZE 256

struct Closure_t {
  // e.g `cclosure_routine0438598345`
  char name[STRING_BUFFER_SIZE];
  // e.g
  // `
  // int a, b = 5;
  // b = 6;
  // `
  char body[FILE_BUFFER_SIZE];
  // e.g `int cclosure_routine0438598345(int a, double b, void* c)`
  char signature[STRING_BUFFER_SIZE];
};

struct ClosureContainer_t {
  struct Closure_t closures[1024];
  int n;
};

int cclosure_processor(const char *in, char *out, int outSize);
int cclosure_core(int argc, char *argv[]);

#endif
