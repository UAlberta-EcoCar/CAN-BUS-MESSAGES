#ifndef LCD_CAN_MESSAGES_H
#define LCD_CAN_MESSAGES_H

void send_lcd_horn(bool horn);
void send_lcd_wipers(bool wipers);
void send_lcd_signals(bool left, bool right, bool hazards);
void send_lcd_headlights(bool state);

#endif
