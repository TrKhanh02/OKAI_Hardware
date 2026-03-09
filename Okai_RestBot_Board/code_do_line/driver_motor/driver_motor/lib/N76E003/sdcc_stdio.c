#include "N76E003.h"
// nếu bạn muốn dùng trực tiếp stdio thì include luôn
#include <stdio.h>

int putchar (int c) {
    while (!TI);
    TI = 0;
    SBUF = c;
    return c;
}

int getchar (void) {
    while (!RI);
    RI = 0;
    return SBUF;
}
