#include <stdio.h>
#include "can_message.h"
#include "can_message_def.h"
#include "fc_can_messages.h"


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

//