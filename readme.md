# cclosure

A small pre-processor to use closures in C.

## Status

Just an idea with a bit of code.

## Example

Input:

```C
int main() {
  networkReq("https://someurl", int (char* body) {
    printf("body of req: %s", body);
  });
}
```

Output:

```C

int cclosure_routine234235(char* body);

int cclosure_routine234235(char* body) {
  printf("body of req: %s", body);
}

int main() {
  networkReq("https://someurl", cclosure_routine234235);
}
```

## TODO

1. Implement the pre-processor
1. Figure out how to share the lexical scope
