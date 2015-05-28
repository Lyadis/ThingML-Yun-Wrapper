/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing MinTest
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "MinTest.h"

/*****************************************************************************
 * Implementation for type : MinTest
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void MinTest_TestChart_OnExit(int state, struct MinTest_Instance *_instance);
void MinTest_send_serial_serial_open(struct MinTest_Instance *_instance, char * device, int baudrate);
void MinTest_send_serial_serial_close(struct MinTest_Instance *_instance);
void MinTest_send_serial_serial_tx(struct MinTest_Instance *_instance, uint8_t b);
#ifdef __cplusplus
}
#endif

// Declaration of functions:

// On Entry Actions:
void MinTest_TestChart_OnEntry(int state, struct MinTest_Instance *_instance) {
switch(state) {
case MINTEST_TESTCHART_STATE:
_instance->MinTest_TestChart_State = MINTEST_TESTCHART_INIT_STATE;
MinTest_TestChart_OnEntry(_instance->MinTest_TestChart_State, _instance);
break;
case MINTEST_TESTCHART_INIT_STATE:
{
fprintf(stdout, "[Test] Start \n");

MinTest_send_serial_serial_open(_instance, "/dev/ttyACM0", 115200);
}
break;
case MINTEST_TESTCHART_PARLE_STATE:
{
fprintf(stdout, "[Test] Parle \n");

MinTest_send_serial_serial_tx(_instance, 255);
MinTest_send_serial_serial_tx(_instance, 255);
MinTest_send_serial_serial_tx(_instance, 255);
MinTest_send_serial_serial_tx(_instance, 255);
}
break;
default: break;
}
}

// On Exit Actions:
void MinTest_TestChart_OnExit(int state, struct MinTest_Instance *_instance) {
switch(state) {
case MINTEST_TESTCHART_STATE:
MinTest_TestChart_OnExit(_instance->MinTest_TestChart_State, _instance);
break;
case MINTEST_TESTCHART_INIT_STATE:
break;
case MINTEST_TESTCHART_PARLE_STATE:
break;
default: break;
}
}

// Event Handlers for incoming messages:
void MinTest_handle_serial_serial_opened(struct MinTest_Instance *_instance) {
uint8_t MinTest_TestChart_State_event_consumed = 0;
if (_instance->MinTest_TestChart_State == MINTEST_TESTCHART_INIT_STATE) {
if (MinTest_TestChart_State_event_consumed == 0 && 1) {
MinTest_TestChart_OnExit(MINTEST_TESTCHART_INIT_STATE, _instance);
_instance->MinTest_TestChart_State = MINTEST_TESTCHART_PARLE_STATE;
MinTest_TestChart_OnEntry(MINTEST_TESTCHART_PARLE_STATE, _instance);
MinTest_TestChart_State_event_consumed = 1;
}
}
}
void MinTest_handle_serial_serial_rx(struct MinTest_Instance *_instance, uint8_t b) {
uint8_t MinTest_TestChart_State_event_consumed = 0;
if (_instance->MinTest_TestChart_State == MINTEST_TESTCHART_PARLE_STATE) {
if (MinTest_TestChart_State_event_consumed == 0 && 1) {
{
printf("[Test] rx: <%i>\n", b);

}
MinTest_TestChart_State_event_consumed = 1;
}
}
}

// Observers for outgoing messages:
void (*MinTest_send_serial_serial_open_listener)(struct MinTest_Instance*, char *, int)= 0x0;
void register_MinTest_send_serial_serial_open_listener(void (*_listener)(struct MinTest_Instance*, char *, int)){
MinTest_send_serial_serial_open_listener = _listener;
}
void MinTest_send_serial_serial_open(struct MinTest_Instance *_instance, char * device, int baudrate){
if (MinTest_send_serial_serial_open_listener != 0x0) MinTest_send_serial_serial_open_listener(_instance, device, baudrate);
}
void (*MinTest_send_serial_serial_close_listener)(struct MinTest_Instance*)= 0x0;
void register_MinTest_send_serial_serial_close_listener(void (*_listener)(struct MinTest_Instance*)){
MinTest_send_serial_serial_close_listener = _listener;
}
void MinTest_send_serial_serial_close(struct MinTest_Instance *_instance){
if (MinTest_send_serial_serial_close_listener != 0x0) MinTest_send_serial_serial_close_listener(_instance);
}
void (*MinTest_send_serial_serial_tx_listener)(struct MinTest_Instance*, uint8_t)= 0x0;
void register_MinTest_send_serial_serial_tx_listener(void (*_listener)(struct MinTest_Instance*, uint8_t)){
MinTest_send_serial_serial_tx_listener = _listener;
}
void MinTest_send_serial_serial_tx(struct MinTest_Instance *_instance, uint8_t b){
if (MinTest_send_serial_serial_tx_listener != 0x0) MinTest_send_serial_serial_tx_listener(_instance, b);
}

