#include <stdio.h>
#include "can_message.h"
#include "can_message_def.h"
#include "fc_can_messages.h"
#include <mcp2515_lib.h>
#include <arduino.h>

/*
* Create CAN Message Descriptors
*/
//can_msg::MsgEncode MSG_NAME( can_msg::TYPE, can_msg::DEVICE, can_msg::MSG, can_msg::PRIOR, LEN)

//FC_ERROR
can_msg::MsgEncode fc_error_msg( can_msg::UINT16, can_msg::FUEL_CELL, can_msg::FC_ERROR, can_msg::CRITICAL, 1 );

//FC_STATE
can_msg::MsgEncode fc_state_msg( can_msg::UINT8, can_msg::FUEL_CELL, can_msg::FC_STATE, can_msg::IMPORTANT, 1 );

//FC_PURGE_COUNT
can_msg::MsgEncode fc_purge_count_msg( can_msg::UINT8, can_msg::FUEL_CELL, can_msg::FC_PURGE_COUNT, can_msg::LOGGING, 1 );

//FC_TIME_BETWEEN_LAST_PURGES
can_msg::MsgEncode fc_time_between_last_purges_msg( can_msg::UINT32, can_msg::FUEL_CELL, can_msg::FC_TIME_BETWEEN_LAST_PURGES, can_msg::LOGGING, 1 );

//FC_ENERGY_SINCE_LAST_PURGE
can_msg::MsgEncode fc_energy_since_last_purge_msg( can_msg::UINT32, can_msg::FUEL_CELL, can_msg::FC_ENERGY_SINCE_LAST_PURGE, can_msg::LOGGING, 1 );

//FC_TOTAL_ENERGY
can_msg::MsgEncode fc_total_energy_message( can_msg::UINT32, can_msg::FUEL_CELL, can_msg::FC_TOTAL_ENERGY, can_msg::LOGGING, 1);

//FC_CHARGE_SINCE_LAST_PURGE
can_msg::MsgEncode fc_charge_since_last_purge_message( can_msg::UINT32, can_msg::FUEL_CELL, can_msg::FC_CHARGE_SINCE_LAST_PURGE, can_msg::LOGGING, 1);

//FC_TOTAL_CHARGE
can_msg::MsgEncode fc_total_charge_message( can_msg::UINT32, can_msg::FUEL_CELL, can_msg::FC_TOTAL_CHARGE, can_msg::LOGGING, 1);

//FCVOLT
can_msg::MsgEncode fcvolt_message( can_msg::INT32, can_msg::FUEL_CELL, can_msg::FCVOLT, can_msg::INFORMATION, 1);




/*
* Create functions for sending the messages
*/


//FC_ERROR
void send_fc_error(uint16_t val)
{
	//make a messages
	CanMessage msg;
	msg.id = fc_error_msg.id();
	msg.length = fc_error_msg.len();
	fc_error_msg.buf(msg.data, val);
	can_send_message(&msg);
}

//FC_STATE
void send_fc_state(uint8_t val)
{
	//make a messages
	CanMessage msg;
	msg.id = fc_state_msg.id();
	msg.length = fc_state_msg.len();
	fc_state_msg.buf(msg.data, val);
	can_send_message(&msg);
}

//FC_PURGE_COUNT
void send_fc_purge_count(uint8_t val)
{
	//make a messages
	CanMessage msg;
	msg.id = fc_purge_count_msg.id();
	msg.length = fc_purge_count_msg.len();
	fc_purge_count_msg.buf(msg.data, val);
	can_send_message(&msg);
}

//FC_TIME_BETWEEN_LAST_PURGES
void send_fc_time_between_last_purges(unsigned long val)
{
	//make a messages
	CanMessage msg;
	msg.id = fc_time_between_last_purges_msg.id();
	msg.length = fc_time_between_last_purges_msg.len();
	fc_time_between_last_purges_msg.buf(msg.data, val);
	can_send_message(&msg);
}

//FC_ENERGY_SINCE_LAST_PURGE
void send_fc_energy_since_last_purge(unsigned long val)
{
	//make a messages
	CanMessage msg;
	msg.id = fc_energy_since_last_purge_msg.id();
	msg.length = fc_energy_since_last_purge_msg.len();
	fc_energy_since_last_purge_msg.buf(msg.data, val);
	can_send_message(&msg);
}