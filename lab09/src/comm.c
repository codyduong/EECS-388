#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "eecs388_lib.h"

int main()
{
    char charbytes[2] = {'\0'};
    // initialize UART channels
    ser_setup(0); // uart0 (debug)
    ser_setup(1); // uart1 (raspberry pi)
    
    printf("Setup completed.\n");
    printf("Begin the main loop.\n");
    
    while (1) {
        if (ser_isready(1)) {
            ser_readline(1, 1, charbytes);
            ser_printline(0, charbytes);
            charbytes[0] = '\0';
        }
    }
    return 0;
}
