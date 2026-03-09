/*
 * Line Follower Robot - N76E003 to ESP32
 * 11 Digital Line Sensors with Schmitt Trigger
 * UART Communication to ESP32
 */

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"

/* UART printf function */
int putchar(int c) {
    while (!TI);
    TI = 0;
    SBUF = c;
    return c;
}

/* Line sensor variables */
unsigned char line_sensors[11];
unsigned int line_pattern = 0;

/*
 * Initialize all GPIO pins with Schmitt Trigger
 */
void GPIO_Init(void)
{
    // P1.5 - LINE1 (Input with Schmitt Trigger)
    P15_Input_Mode;
    set_P1S_5;
    
    // P0.5 - LINE2 (Input with Schmitt Trigger)
    P05_Input_Mode;
    set_P0S_5;
    
    // P0.4 - LINE3 (Input with Schmitt Trigger)
    P04_Input_Mode;
    set_P0S_4;
    
    // P0.3 - LINE4 (Input with Schmitt Trigger)
    P03_Input_Mode;
    set_P0S_3;
    
    // P0.1 - LINE5 (Input with Schmitt Trigger)
    P01_Input_Mode;
    set_P0S_1;
    
    // P0.0 - LINE6 (Input with Schmitt Trigger)
    P00_Input_Mode;
    set_P0S_0;
    
    // P1.0 - LINE7 (Input with Schmitt Trigger)
    P10_Input_Mode;
    set_P1S_0;
    
    // P1.1 - LINE8 (Input with Schmitt Trigger)
    P11_Input_Mode;
    set_P1S_1;
    
    // P1.2 - LINE9 (Input with Schmitt Trigger)
    P12_Input_Mode;
    set_P1S_2;
    
    // P1.3 - LINE10 (Input with Schmitt Trigger)
    P13_Input_Mode;
    set_P1S_3;
    
    // P1.4 - LINE11 (Input with Schmitt Trigger)
    P14_Input_Mode;
    set_P1S_4;
}

/*
 * Initialize UART for communication with ESP32
 */
void UART_Init(void)
{
    InitialUART0_Timer1(115200);  // 115200 baud rate
// Xóa bit 6 của P0M1 (về 0)
    P0M1 &= ~(1 << 6); 
    // Bật bit 6 của P0M2 (lên 1)
    P0M2 |= (1 << 6);
}

/*
 * Read all line sensors
 */
void Read_Line_Sensors(void)
{
    line_sensors[0]  = P15;  // LINE1
    line_sensors[1]  = P05;  // LINE2
    line_sensors[2]  = P04;  // LINE3
    line_sensors[3]  = P03;  // LINE4
    line_sensors[4]  = P01;  // LINE5
    line_sensors[5]  = P00;  // LINE6
    line_sensors[6]  = P10;  // LINE7
    line_sensors[7]  = P11;  // LINE8
    line_sensors[8]  = P12;  // LINE9
    line_sensors[9]  = P13;  // LINE10
    line_sensors[10] = P14;  // LINE11
}

/*
 * Convert sensor array to 11-bit pattern
 */
unsigned int Get_Line_Pattern(void)
{
    unsigned int pattern = 0;
    unsigned char i;
    
    for(i = 0; i < 11; i++)
    {
        if(line_sensors[i] == 1)
            pattern |= (1 << i);
    }
    
    return pattern;
}

/*
 * Send line sensor data via UART to ESP32
 * Format 1: Binary pattern (0-2047)
 */
void Send_Pattern_Decimal(void)
{
    printf("%u\r\n", line_pattern);
}

/*
 * Send line sensor data via UART to ESP32
 * Format 2: Individual sensor values (space separated)
 */
void Send_Individual_Values(void)
{
    unsigned char i;
    
    for(i = 0; i < 11; i++)
    {
        printf("%u", line_sensors[i]);
        if(i < 10)
            printf(" ");
    }
    printf("\r\n");
}

/*
 * Send line sensor data via UART to ESP32
 * Format 3: JSON format
 */
void Send_JSON_Format(void)
{
    printf("{\"sensors\":[");
    
    for(unsigned char i = 0; i < 11; i++)
    {
        printf("%u", line_sensors[i]);
        if(i < 10)
            printf(",");
    }
    
    printf("],\"pattern\":%u}\r\n", line_pattern);
}

/*
 * Send line sensor data via UART to ESP32
 * Format 4: Binary string (visual representation)
 */
void Send_Binary_String(void)
{
    unsigned char i;
    
    for(i = 0; i < 11; i++)
    {
        printf("%c", line_sensors[i] ? '1' : '0');
    }
    printf("\r\n");
}

/*
 * Send line sensor data via UART to ESP32
 * Format 5: Compact hex format
 */
void Send_Hex_Format(void)
{
    printf("L:%03X\r\n", line_pattern);
}

/*
 * Main function
 */
void main(void) 
{
    // Initialize system
    Set_All_GPIO_Quasi_Mode;
    GPIO_Init();
    UART_Init();
    
    // Small delay for system stabilization
    Timer0_Delay1ms(100);
    
    // Send startup message
    printf("Line Follower Started\r\n");
    
    while(1)
    {
        // Read all line sensors
        Read_Line_Sensors();
        
        // Get line pattern
        line_pattern = Get_Line_Pattern();
        // Choose one of the following formats to send to ESP32:
        
        // Format 1: Decimal pattern (0-2047)
        //Send_Pattern_Decimal();
        
        // Format 2: Individual values (uncomment to use)
        // Send_Individual_Values();
        
        // Format 3: JSON format (uncomment to use)
         Send_JSON_Format();
        
        // Format 4: Binary string (uncomment to use)
        // Send_Binary_String();
        
        // Format 5: Hex format (uncomment to use)
        // Send_Hex_Format();
        
        // Delay between readings (adjust as needed)
        Timer0_Delay1ms(30);  // 50ms = 20Hz update rate
    }
}