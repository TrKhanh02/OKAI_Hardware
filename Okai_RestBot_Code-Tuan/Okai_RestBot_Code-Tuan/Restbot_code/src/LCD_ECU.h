#ifndef LCD_ECU_H
#define LCD_ECU_H

#include <Arduino.h>
extern int trangHienTai;
extern int mucMenu;

void lcd_setup();
void khiNutLenDuocNhan();
void khiNutOkDuocNhan();
void khiNutXuongDuocNhan();
void khiNutBackDuocNhan();
int loop_botton(int &trangHienTai, int &mucMenu);
void menu(int menu, int line);
void lcdTask(void *pvParameters);

#endif // LCD_ECU_H