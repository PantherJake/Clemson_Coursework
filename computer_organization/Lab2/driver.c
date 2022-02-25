#include <stdio.h>

// int sum(int, int); (This can be added to get the warning to go away, but the program works without it.)
// The warning occurs because the driver is being added first, and when it is checked, the sum does not yet have a definition or implementation

int main(int argc, char* argv[]) {
    printf("%d\n",sum(5, 10));
    return 0;
}
