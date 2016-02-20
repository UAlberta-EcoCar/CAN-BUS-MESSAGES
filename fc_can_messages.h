#ifndef FC_CAN_MESSAGES_H
#define FC_CAN_MESSAGES_H

void send_fc_error(unsigned int val);

void send_fc_state(unsigned char val);

void send_fc_purge_count(unsigned char val);

void send_fc_time_between_last_purges(unsigned long val);

void send_fc_energy_since_last_purge(unsigned long val);

void send_fc_total_energy(unsigned long val);

#endif