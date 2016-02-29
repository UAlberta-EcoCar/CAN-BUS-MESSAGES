#include <stdio.h>
#include "can_message.h"
#include "can_message_def.h"
#include "lcd_can_messages.h"
#include <mcp2515_lib.h>
#include <arduino.h>


//LCD Horn
can_msg::MsgEncode lcd_horn_msg( can_msg::BOOL, can_msg::AUX, can_msg::HORN, can_msg::IMPORTANT, 1);

//LCD WIpers
can_msg::MsgEncode lcd_wipers_msg( can_msg::BOOL, can_msg::AUX, can_msg::WIPERS, can_msg::IMPORTANT, 1);

//LCD Signals
can_msg::MsgEncode lcd_signals_msg( can_msg::BOOL, can_msg::AUX, can_msg::SIGNAL, can_msg::IMPORTANT, 3);

//LCD Headlight
can_msg::MsgEncode lcd_headlights_msg( can_msg::BOOL, can_msg::AUX, can_msg::HEADLIGHTS, can_msg::IMPORTANT, 1);




//Send LCD Horn
void send_lcd_horn(bool horn){
	CanMessage msg;
	msg.id = lcd_horn_msg.id();
	msg.length = lcd_horn_msg.len();
	lcd_horn_msg.buf(msg.data, horn << 0); //lets use a default of setting a single bool as bit 0
	while(can_send_message(&msg));
}

//Send LCD Wipers
void send_lcd_wipers(bool wipers){
	CanMessage msg;
	msg.id = lcd_wipers_msg.id();
	msg.length = lcd_wipers_msg.len();
	lcd_wipers_msg.buf(msg.data, wipers << 0); //lets use a default of setting a single bool as bit 0
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
	lcd_headlights_msg.buf(msg.data, state << 0);
	while(can_send_message(&msg));
}
