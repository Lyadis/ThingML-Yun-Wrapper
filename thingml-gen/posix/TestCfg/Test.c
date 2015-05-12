/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing Test
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "Test.h"

/*****************************************************************************
 * Implementation for type : Test
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void Test_testChart_OnExit(int state, struct Test_Instance *_instance);
void Test_send_bridge_setDigitalHigh(struct Test_Instance *_instance, uint8_t pin);
void Test_send_bridge_setDigitalLow(struct Test_Instance *_instance, uint8_t pin);
void Test_send_bridge_setOutput(struct Test_Instance *_instance, uint8_t pin);
void Test_send_bridge_setInput(struct Test_Instance *_instance, uint8_t pin);
void Test_send_bridge_readDigital(struct Test_Instance *_instance, uint8_t pin);
void Test_send_bridge_readAnalog(struct Test_Instance *_instance, uint8_t pin);
void Test_send_bridge_timer_start(struct Test_Instance *_instance, uint8_t id, int16_t time);
void Test_send_bridge_timer_cancel(struct Test_Instance *_instance, uint8_t id);
#ifdef __cplusplus
}
#endif

// Declaration of functions:

// On Entry Actions:
void Test_testChart_OnEntry(int state, struct Test_Instance *_instance) {
switch(state) {
case TEST_TESTCHART_STATE:
_instance->Test_testChart_State = TEST_TESTCHART_INIT_STATE;
Test_testChart_OnEntry(_instance->Test_testChart_State, _instance);
break;
case TEST_TESTCHART_INIT_STATE:
{
fprintf(stdout, "Test Init");

}
break;
case TEST_TESTCHART_BLINK_STATE:
{
fprintf(stdout, "Blink");

Test_send_bridge_timer_start(_instance, _instance->Test_timerID__var, _instance->Test_time__var);
if(_instance->Test_On__var) {
Test_send_bridge_setDigitalLow(_instance, _instance->Test_Led__var);
}
if( !(_instance->Test_On__var)) {
Test_send_bridge_setDigitalHigh(_instance, _instance->Test_Led__var);
}
_instance->Test_On__var =  !(_instance->Test_On__var);
}
break;
default: break;
}
}

// On Exit Actions:
void Test_testChart_OnExit(int state, struct Test_Instance *_instance) {
switch(state) {
case TEST_TESTCHART_STATE:
Test_testChart_OnExit(_instance->Test_testChart_State, _instance);
break;
case TEST_TESTCHART_INIT_STATE:
break;
case TEST_TESTCHART_BLINK_STATE:
break;
default: break;
}
}

// Event Handlers for incoming messages:
void Test_handle_bridge_CPUBridgeReady(struct Test_Instance *_instance) {
uint8_t Test_testChart_State_event_consumed = 0;
if (_instance->Test_testChart_State == TEST_TESTCHART_INIT_STATE) {
if (Test_testChart_State_event_consumed == 0 && 1) {
Test_testChart_OnExit(TEST_TESTCHART_INIT_STATE, _instance);
_instance->Test_testChart_State = TEST_TESTCHART_BLINK_STATE;
{
Test_send_bridge_setOutput(_instance, _instance->Test_Led__var);
}
Test_testChart_OnEntry(TEST_TESTCHART_BLINK_STATE, _instance);
Test_testChart_State_event_consumed = 1;
}
}
}
void Test_handle_bridge_timeout(struct Test_Instance *_instance, uint8_t id) {
uint8_t Test_testChart_State_event_consumed = 0;
if (_instance->Test_testChart_State == TEST_TESTCHART_BLINK_STATE) {
if (Test_testChart_State_event_consumed == 0 && 1) {
Test_testChart_OnExit(TEST_TESTCHART_BLINK_STATE, _instance);
_instance->Test_testChart_State = TEST_TESTCHART_BLINK_STATE;
Test_testChart_OnEntry(TEST_TESTCHART_BLINK_STATE, _instance);
Test_testChart_State_event_consumed = 1;
}
}
}

// Observers for outgoing messages:
void (*Test_send_bridge_setDigitalHigh_listener)(struct Test_Instance*, uint8_t)= 0x0;
void register_Test_send_bridge_setDigitalHigh_listener(void (*_listener)(struct Test_Instance*, uint8_t)){
Test_send_bridge_setDigitalHigh_listener = _listener;
}
void Test_send_bridge_setDigitalHigh(struct Test_Instance *_instance, uint8_t pin){
if (Test_send_bridge_setDigitalHigh_listener != 0x0) Test_send_bridge_setDigitalHigh_listener(_instance, pin);
}
void (*Test_send_bridge_setDigitalLow_listener)(struct Test_Instance*, uint8_t)= 0x0;
void register_Test_send_bridge_setDigitalLow_listener(void (*_listener)(struct Test_Instance*, uint8_t)){
Test_send_bridge_setDigitalLow_listener = _listener;
}
void Test_send_bridge_setDigitalLow(struct Test_Instance *_instance, uint8_t pin){
if (Test_send_bridge_setDigitalLow_listener != 0x0) Test_send_bridge_setDigitalLow_listener(_instance, pin);
}
void (*Test_send_bridge_setOutput_listener)(struct Test_Instance*, uint8_t)= 0x0;
void register_Test_send_bridge_setOutput_listener(void (*_listener)(struct Test_Instance*, uint8_t)){
Test_send_bridge_setOutput_listener = _listener;
}
void Test_send_bridge_setOutput(struct Test_Instance *_instance, uint8_t pin){
if (Test_send_bridge_setOutput_listener != 0x0) Test_send_bridge_setOutput_listener(_instance, pin);
}
void (*Test_send_bridge_setInput_listener)(struct Test_Instance*, uint8_t)= 0x0;
void register_Test_send_bridge_setInput_listener(void (*_listener)(struct Test_Instance*, uint8_t)){
Test_send_bridge_setInput_listener = _listener;
}
void Test_send_bridge_setInput(struct Test_Instance *_instance, uint8_t pin){
if (Test_send_bridge_setInput_listener != 0x0) Test_send_bridge_setInput_listener(_instance, pin);
}
void (*Test_send_bridge_readDigital_listener)(struct Test_Instance*, uint8_t)= 0x0;
void register_Test_send_bridge_readDigital_listener(void (*_listener)(struct Test_Instance*, uint8_t)){
Test_send_bridge_readDigital_listener = _listener;
}
void Test_send_bridge_readDigital(struct Test_Instance *_instance, uint8_t pin){
if (Test_send_bridge_readDigital_listener != 0x0) Test_send_bridge_readDigital_listener(_instance, pin);
}
void (*Test_send_bridge_readAnalog_listener)(struct Test_Instance*, uint8_t)= 0x0;
void register_Test_send_bridge_readAnalog_listener(void (*_listener)(struct Test_Instance*, uint8_t)){
Test_send_bridge_readAnalog_listener = _listener;
}
void Test_send_bridge_readAnalog(struct Test_Instance *_instance, uint8_t pin){
if (Test_send_bridge_readAnalog_listener != 0x0) Test_send_bridge_readAnalog_listener(_instance, pin);
}
void (*Test_send_bridge_timer_start_listener)(struct Test_Instance*, uint8_t, int16_t)= 0x0;
void register_Test_send_bridge_timer_start_listener(void (*_listener)(struct Test_Instance*, uint8_t, int16_t)){
Test_send_bridge_timer_start_listener = _listener;
}
void Test_send_bridge_timer_start(struct Test_Instance *_instance, uint8_t id, int16_t time){
if (Test_send_bridge_timer_start_listener != 0x0) Test_send_bridge_timer_start_listener(_instance, id, time);
}
void (*Test_send_bridge_timer_cancel_listener)(struct Test_Instance*, uint8_t)= 0x0;
void register_Test_send_bridge_timer_cancel_listener(void (*_listener)(struct Test_Instance*, uint8_t)){
Test_send_bridge_timer_cancel_listener = _listener;
}
void Test_send_bridge_timer_cancel(struct Test_Instance *_instance, uint8_t id){
if (Test_send_bridge_timer_cancel_listener != 0x0) Test_send_bridge_timer_cancel_listener(_instance, id);
}

