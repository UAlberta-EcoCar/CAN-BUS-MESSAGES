#ifndef CAN_MESSAGE_DEF_H
#define CAN_MESSAGE_DEF_H

/*
 * Message ID format (11 bits)
 *  Bit [2-0] store the message data type
 *  Bit [4-3] device id
 *  Bit [8-5] message id
 *  Bit [10-9] priority level
 *    0 - mission critical
 *    1 - important
 *    2 - information
 *    3 - logging
 */

namespace can_msg {
  /*
   * message type
   */
  typedef enum {
    BOOL = 0,
    INT8 = 1,
    UINT8 = 2,
    INT16 = 3,
    UINT16 = 4,
    INT32 = 5,
	UINT32 = 6,
  } format_t;

  /*
   * device ids
   */
  typedef enum {
    FUEL_CELL = 0,
    MOTOR = 1,
    AUX = 2,
	OTHER = 3
  } device_t;
  
  /*
   * priority
   */
  typedef enum {
    CRITICAL = 0,
    IMPORTANT = 1,
    INFORMATION = 2,
    LOGGING = 3
  } priority_t;
  
  /*
   * Fuel cell
   */
   //to do: reorder so that levels have higher priority
  typedef enum {
	//purge data
    FC_ERROR = 0,  						//len 1
	FC_STATE = 1,						//len 1
	FC_PURGE_COUNT = 2,					//len 1
	FC_TIME_BETWEEN_LAST_PURGES = 3,	//len 1
	FC_ENERGY_SINCE_LAST_PURGE = 4,		//len 1
	FC_TOTAL_ENERGY = 5,				//len 1
	FC_CHARGE_SINCE_LAST_PURGE = 6,		//len 1
	FC_TOTAL_CHARGE = 8,				//len 1
	//FC levels
	FCVOLT = 9,							//len 1
	FCCURR = 10,						//len 1
	FCTEMP = 11,						//len 1
	FCPRES = 12,						//len 1
	FC_CAPVOLT = 13,					//len 1
	FC_FAN_SPEED = 14,					//len 1
	//output states
	FC_OUTPUTS = 15						//len 6 [fc_outputs_t]
  } fuel_cell_t;

  typedef enum {
	FC_START_RELAY = 0,
	FC_RES_RELAY = 1,
	FC_CAP_RELAY = 2,
	FC_MOTOR_RELAY = 3,
	FC_PURGE_VALVE = 4,
	FC_H2_VALVE = 5
  } fc_outputs_t;

	
	
  /*
   * Motor system
   */
  typedef enum {
    THROTTLE = 0, // len:1
    BRAKE = 1,    // len:1
    MERROR = 3,   // len:2  [motor_error_t]
    MCURRENT = 4, // len:1
    MSPEED = 6    // len:1
  } motor_t;
  typedef enum {
    MERROR_STALL = 0,
    MERROR_OVERCURRENT = 1
  } motor_error_t;

};

#endif
