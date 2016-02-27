#include <stdio.h>
#include "can_message.h"
#include "can_message_def.h"
#include "lcd_can_messages.h"
#include <mcp2515_lib.h>
#include <arduino.h>


//LCD Horn and Wipers
can_msg::MsgEncode lcd_horn_wipers_msg( can_msg::BOOL, can_msg::AUX, can_msg::HORN_WIPERS, can_msg::IMPORTANT, 2);

//LCD Signals
can_msg::MsgEncode lcd_signals_msg( can_msg::BOOL, can_msg::AUX, can_msg::SIGNAL, can_msg::IMPORTANT, 3);

//LCD Headlight
can_msg::MsgEncode lcd_headlights_msg( can_msg::BOOL, can_msg::AUX, can_msg::HEADLIGHTS, can_msg::IMPORTANT, 1);




//Send LCD Horn and Wipers
void send_lcd_horn_wipers(bool horn, bool wipers){
	CanMessage msg;
	msg.id = lcd_horn_wipers_msg.id();
	msg.length = lcd_horn_wipers_msg.len();
	lcd_horn_wipers_msg.buf(msg.data, horn << can_msg::HORN | wipers << can_msg::WIPER);
	while(can_send_message(&msg));
}

//Send Signals
void send_lcd_signals(bool left, bool right, bool hazards){
	CanMessage msg;
	msg.id = lcd_signals_msg.id();
	msg.length = lcd_signals_msg.len();
	lcd_signals_msg.buf(msg.data, left << can_msg::LEFT_SIGNAL | right << can_msg::RIGHT_SIGNAL | hazards << can_msg::HAZARD_LIGHTS);
	while(can_send_message(&msg));
}

//Send headlights states
void send_lcd_headlights(bool state){
	CanMessage msg;
	msg.id = lcd_headlights_msg.id();
	msg.length = lcd_headlights_msg.len();
	lcd_headlights_msg.buf(msg.data, state << can_msg::HEADLIGHTBIT);
	while(can_send_message(&msg));
}
