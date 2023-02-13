/**
 * This program reads the distance data from the TFmini lidar sensor,  
 * prints the read data and controls an LED depending on the measured distance.
 */
#include <stdint.h>
#include <stdio.h>

#include "eecs388_lib.h"

int main()
{
    gpio_mode(RED_LED, OUTPUT);
    gpio_mode(GREEN_LED, OUTPUT);
    ser_setup();

    ser_printline("Setup completed.\n"); //ser_printline() can be used to print to the serial monitor

    // Low and high byte in array
    char char2bytes[2] = {"\0"};
    uint8_t low;
    uint8_t high;
    /* 
        LIDAR distance data is 16 bits.
    */
    uint16_t dist = 0;

    while (1) {
        /* 
            Task 2.1: 
            - read a data frame from the TFmini sensor
            
            - from Table 6, we know each LIDAR measurement sends 9 bytes
            - the function `ser_read()` can process 1 byte per function call

            - This if-statement below will read (and check) the first two bytes of a valid data frame
            - You will need to write code to read the subsequent bytes to get the distance data
            - You will need to process the data received from the sensor to get the correct distance value
        */
        if ('Y' == ser_read() && 'Y' == ser_read()) {
            // read next two bytes
            ser_readline(2, char2bytes);
            // ser_printline(char2bytes);

            low = char2bytes[0];
            high = char2bytes[1];
            dist = low | (high<<8);
            // ser_printline("test\n");
            // printf("%d, %d, %d\n", low, high, dist);

        /* 
            Task 2.2: 
            - turn on the red LED if the distance measured is less than 50 cm. 
            - otherwise turn on the green LED 

            - print the measured value to the console (i.e. the serial monitor) 
            - You can use printf() or ser_printline() or ser_write()
            
            - Helpful guide for printing with printf()
            - https://en.cppreference.com/w/cpp/io/c/fprintf
        */
            printf("%d cm\n", dist);
            if (dist < 50) {
                gpio_write(GREEN_LED, 0);
                gpio_write(RED_LED, 1);
            } else {
                gpio_write(RED_LED, 0);
                gpio_write(GREEN_LED, 1);
            }
        }
        // polling rate 100hz or 10ms
        delay(10);
    }
}
