#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool was_not_inlined;

char *memcpy(char *d, const char *s, unsigned int n)
{
    if (d == 0 && s == 0) {
        was_not_inlined = true;
    }
}

int main()
{
    was_not_inlined = false; memcpy(0, 0, 104); assert(was_not_inlined);
    puts("SUCCESS!");
}
