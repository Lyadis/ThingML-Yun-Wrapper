/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing test
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "test.h"

/*****************************************************************************
 * Implementation for type : test
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void test_TestChart_OnExit(int state, struct test_Instance *_instance);
void test_send_serial_serial_open(struct test_Instance *_instance, char * device, int baudrate);
void test_send_serial_serial_close(struct test_Instance *_instance);
void test_send_serial_serial_tx(struct test_Instance *_instance, uint8_t b);
#ifdef __cplusplus
}
#endif

// Declaration of functions:

// On Entry Actions:
void test_TestChart_OnEntry(int state, struct test_Instance *_instance) {
switch(state) {
case TEST_TESTCHART_STATE:
_instance->test_TestChart_State = TEST_TESTCHART_INIT_STATE;
test_TestChart_OnEntry(_instance->test_TestChart_State, _instance);
break;
case TEST_TESTCHART_INIT_STATE:
{
fprintf(stdout, "[Test] Start\n");

test_send_serial_serial_open(_instance, "/dev/ttyATH0", 115200);
}
break;
case TEST_TESTCHART_PARLE_STATE:
{
fprintf(stdout, "[Test] Parle\n");

test_send_serial_serial_tx(_instance, 0xff);
}
break;
default: break;
}
}

// On Exit Actions:
void test_TestChart_OnExit(int state, struct test_Instance *_instance) {
switch(state) {
case TEST_TESTCHART_STATE:
test_TestChart_OnExit(_instance->test_TestChart_State, _instance);
break;
case TEST_TESTCHART_INIT_STATE:
break;
case TEST_TESTCHART_PARLE_STATE:
break;
default: break;
}
}

// Event Handlers for incoming messages:
void test_handle_serial_serial_rx(struct test_Instance *_instance, uint8_t b) {
uint8_t test_TestChart_State_event_consumed = 0;
if (_instance->test_TestChart_State == TEST_TESTCHART_PARLE_STATE) {
if (test_TestChart_State_event_consumed == 0 && 1) {
{
fprintf(stdout, [Test] rx: \"b\"\n);

}
test_TestChart_State_event_consumed = 1;
}
}
}
void test_handle_serial_serial_opened(struct test_Instance *_instance) {
uint8_t test_TestChart_State_event_consumed = 0;
if (_instance->test_TestChart_State == TEST_TESTCHART_INIT_STATE) {
if (test_TestChart_State_event_consumed == 0 && 1) {
test_TestChart_OnExit(TEST_TESTCHART_INIT_STATE, _instance);
_instance->test_TestChart_State = TEST_TESTCHART_PARLE_STATE;
test_TestChart_OnEntry(TEST_TESTCHART_PARLE_STATE, _instance);
test_TestChart_State_event_consumed = 1;
}
}
}

// Observers for outgoing messages:
void (*test_send_serial_serial_open_listener)(struct test_Instance*, char *, int)= 0x0;
void register_test_send_serial_serial_open_listener(void (*_listener)(struct test_Instance*, char *, int)){
test_send_serial_serial_open_listener = _listener;
}
void test_send_serial_serial_open(struct test_Instance *_instance, char * device, int baudrate){
if (test_send_serial_serial_open_listener != 0x0) test_send_serial_serial_open_listener(_instance, device, baudrate);
}
void (*test_send_serial_serial_close_listener)(struct test_Instance*)= 0x0;
void register_test_send_serial_serial_close_listener(void (*_listener)(struct test_Instance*)){
test_send_serial_serial_close_listener = _listener;
}
void test_send_serial_serial_close(struct test_Instance *_instance){
if (test_send_serial_serial_close_listener != 0x0) test_send_serial_serial_close_listener(_instance);
}
void (*test_send_serial_serial_tx_listener)(struct test_Instance*, uint8_t)= 0x0;
void register_test_send_serial_serial_tx_listener(void (*_listener)(struct test_Instance*, uint8_t)){
test_send_serial_serial_tx_listener = _listener;
}
void test_send_serial_serial_tx(struct test_Instance *_instance, uint8_t b){
if (test_send_serial_serial_tx_listener != 0x0) test_send_serial_serial_tx_listener(_instance, b);
}

