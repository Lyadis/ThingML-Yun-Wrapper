/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application TestCfg
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include <pthread.h>
#include "thingml_typedefs.h"
#include "runtime.h"
#include "LinuxSerial.h"
#include "Bridge.h"
#include "Test.h"


// NO C_HEADERS Annotation


/*****************************************************************************
 * Definitions for configuration : TestCfg
 *****************************************************************************/

//Declaration of instance variables
struct Bridge_Instance TestCfg_bridge_var;
struct LinuxSerial_Instance TestCfg_sp_var;
struct Test_Instance TestCfg_t_var;

// Enqueue of messages Bridge::Serial1::timeout
void enqueue_Bridge_send_Serial1_timeout(struct Bridge_Instance *_instance, uint8_t id){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (1 >> 8) & 0xFF );
_fifo_enqueue( 1 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter id
_fifo_enqueue(id & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages Bridge::Serial1::readAnalogResponse
void enqueue_Bridge_send_Serial1_readAnalogResponse(struct Bridge_Instance *_instance, uint8_t pin, int res){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter pin
_fifo_enqueue(pin & 0xFF);

// parameter res
_fifo_enqueue((res>>8) & 0xFF);
_fifo_enqueue(res & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages Bridge::Serial1::readDigitalResponse
void enqueue_Bridge_send_Serial1_readDigitalResponse(struct Bridge_Instance *_instance, uint8_t pin, uint8_t DigitalState){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter pin
_fifo_enqueue(pin & 0xFF);

// parameter DigitalState
_fifo_enqueue(DigitalState & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages Bridge::Serial1::CPUBridgeReady
void enqueue_Bridge_send_Serial1_CPUBridgeReady(struct Bridge_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages Test::bridge::readDigital
void enqueue_Test_send_bridge_readDigital(struct Test_Instance *_instance, uint8_t pin){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter pin
_fifo_enqueue(pin & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages Test::bridge::setInput
void enqueue_Test_send_bridge_setInput(struct Test_Instance *_instance, uint8_t pin){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter pin
_fifo_enqueue(pin & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages Test::bridge::setDigitalLow
void enqueue_Test_send_bridge_setDigitalLow(struct Test_Instance *_instance, uint8_t pin){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter pin
_fifo_enqueue(pin & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages Test::bridge::timer_start
void enqueue_Test_send_bridge_timer_start(struct Test_Instance *_instance, uint8_t id, int16_t time){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter id
_fifo_enqueue(id & 0xFF);

// parameter time
_fifo_enqueue((time>>8) & 0xFF);
_fifo_enqueue(time & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages Test::bridge::setDigitalHigh
void enqueue_Test_send_bridge_setDigitalHigh(struct Test_Instance *_instance, uint8_t pin){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (9 >> 8) & 0xFF );
_fifo_enqueue( 9 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter pin
_fifo_enqueue(pin & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages Test::bridge::readAnalog
void enqueue_Test_send_bridge_readAnalog(struct Test_Instance *_instance, uint8_t pin){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (10 >> 8) & 0xFF );
_fifo_enqueue( 10 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter pin
_fifo_enqueue(pin & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages Test::bridge::setOutput
void enqueue_Test_send_bridge_setOutput(struct Test_Instance *_instance, uint8_t pin){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (11 >> 8) & 0xFF );
_fifo_enqueue( 11 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter pin
_fifo_enqueue(pin & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages Test::bridge::timer_cancel
void enqueue_Test_send_bridge_timer_cancel(struct Test_Instance *_instance, uint8_t id){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (12 >> 8) & 0xFF );
_fifo_enqueue( 12 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter id
_fifo_enqueue(id & 0xFF);
}
fifo_unlock_and_notify();
}

// Dispatch for messages Bridge::Serial1::timeout
void dispatch_Bridge_send_Serial1_timeout(struct Bridge_Instance *_instance, uint8_t id){
if (_instance == &TestCfg_bridge_var) {
Test_handle_bridge_timeout(&TestCfg_t_var, id);
}
}
// Dispatch for messages Bridge::Serial1::readAnalogResponse
void dispatch_Bridge_send_Serial1_readAnalogResponse(struct Bridge_Instance *_instance, uint8_t pin, int res){
if (_instance == &TestCfg_bridge_var) {
}
}
// Dispatch for messages Bridge::Serial1::readDigitalResponse
void dispatch_Bridge_send_Serial1_readDigitalResponse(struct Bridge_Instance *_instance, uint8_t pin, uint8_t DigitalState){
if (_instance == &TestCfg_bridge_var) {
}
}
// Dispatch for messages Bridge::Serial1::CPUBridgeReady
void dispatch_Bridge_send_Serial1_CPUBridgeReady(struct Bridge_Instance *_instance){
if (_instance == &TestCfg_bridge_var) {
Test_handle_bridge_CPUBridgeReady(&TestCfg_t_var);
}
}
// Dispatch for messages Bridge::serial::serial_tx
void dispatch_Bridge_send_serial_serial_tx(struct Bridge_Instance *_instance, uint8_t b){
if (_instance == &TestCfg_bridge_var) {
LinuxSerial_handle_serial_serial_tx(&TestCfg_sp_var, b);
}
}
// Dispatch for messages Bridge::serial::serial_open
void dispatch_Bridge_send_serial_serial_open(struct Bridge_Instance *_instance, char * device, int baudrate){
if (_instance == &TestCfg_bridge_var) {
LinuxSerial_handle_serial_serial_open(&TestCfg_sp_var, device, baudrate);
}
}
// Dispatch for messages Bridge::serial::serial_close
void dispatch_Bridge_send_serial_serial_close(struct Bridge_Instance *_instance){
if (_instance == &TestCfg_bridge_var) {
}
}
// Dispatch for messages LinuxSerial::serial::serial_closed
void dispatch_LinuxSerial_send_serial_serial_closed(struct LinuxSerial_Instance *_instance){
if (_instance == &TestCfg_sp_var) {
}
}
// Dispatch for messages LinuxSerial::serial::serial_opened
void dispatch_LinuxSerial_send_serial_serial_opened(struct LinuxSerial_Instance *_instance){
if (_instance == &TestCfg_sp_var) {
Bridge_handle_serial_serial_opened(&TestCfg_bridge_var);
}
}
// Dispatch for messages LinuxSerial::serial::serial_rx
void dispatch_LinuxSerial_send_serial_serial_rx(struct LinuxSerial_Instance *_instance, uint8_t b){
if (_instance == &TestCfg_sp_var) {
Bridge_handle_serial_serial_rx(&TestCfg_bridge_var, b);
}
}
// Dispatch for messages Test::bridge::readDigital
void dispatch_Test_send_bridge_readDigital(struct Test_Instance *_instance, uint8_t pin){
if (_instance == &TestCfg_t_var) {
Bridge_handle_Serial1_readDigital(&TestCfg_bridge_var, pin);
}
}
// Dispatch for messages Test::bridge::setInput
void dispatch_Test_send_bridge_setInput(struct Test_Instance *_instance, uint8_t pin){
if (_instance == &TestCfg_t_var) {
Bridge_handle_Serial1_setInput(&TestCfg_bridge_var, pin);
}
}
// Dispatch for messages Test::bridge::setDigitalLow
void dispatch_Test_send_bridge_setDigitalLow(struct Test_Instance *_instance, uint8_t pin){
if (_instance == &TestCfg_t_var) {
Bridge_handle_Serial1_setDigitalLow(&TestCfg_bridge_var, pin);
}
}
// Dispatch for messages Test::bridge::timer_start
void dispatch_Test_send_bridge_timer_start(struct Test_Instance *_instance, uint8_t id, int16_t time){
if (_instance == &TestCfg_t_var) {
Bridge_handle_Serial1_timer_start(&TestCfg_bridge_var, id, time);
}
}
// Dispatch for messages Test::bridge::setDigitalHigh
void dispatch_Test_send_bridge_setDigitalHigh(struct Test_Instance *_instance, uint8_t pin){
if (_instance == &TestCfg_t_var) {
Bridge_handle_Serial1_setDigitalHigh(&TestCfg_bridge_var, pin);
}
}
// Dispatch for messages Test::bridge::readAnalog
void dispatch_Test_send_bridge_readAnalog(struct Test_Instance *_instance, uint8_t pin){
if (_instance == &TestCfg_t_var) {
Bridge_handle_Serial1_readAnalog(&TestCfg_bridge_var, pin);
}
}
// Dispatch for messages Test::bridge::setOutput
void dispatch_Test_send_bridge_setOutput(struct Test_Instance *_instance, uint8_t pin){
if (_instance == &TestCfg_t_var) {
Bridge_handle_Serial1_setOutput(&TestCfg_bridge_var, pin);
}
}
// Dispatch for messages Test::bridge::timer_cancel
void dispatch_Test_send_bridge_timer_cancel(struct Test_Instance *_instance, uint8_t id){
if (_instance == &TestCfg_t_var) {
Bridge_handle_Serial1_timer_cancel(&TestCfg_bridge_var, id);
}
}

void processMessageQueue() {
fifo_lock();
while (fifo_empty()) fifo_wait();
byte mbuf[5];
uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 5:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_bridge_readDigital((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* pin */ );
break;
case 6:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_bridge_setInput((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* pin */ );
break;
case 7:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_bridge_setDigitalLow((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* pin */ );
break;
case 8:
while (mbufi < 5) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_bridge_timer_start((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* id */ ,
(mbuf[3]<<8) + mbuf[4] /* time */ );
break;
case 9:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_bridge_setDigitalHigh((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* pin */ );
break;
case 10:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_bridge_readAnalog((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* pin */ );
break;
case 11:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_bridge_setOutput((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* pin */ );
break;
case 12:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Test_send_bridge_timer_cancel((struct Test_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* id */ );
break;
case 1:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Bridge_send_Serial1_timeout((struct Bridge_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* id */ );
break;
case 2:
while (mbufi < 5) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Bridge_send_Serial1_readAnalogResponse((struct Bridge_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* pin */ ,
(mbuf[3]<<8) + mbuf[4] /* res */ );
break;
case 3:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Bridge_send_Serial1_readDigitalResponse((struct Bridge_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* pin */ ,
mbuf[3] /* DigitalState */ );
break;
case 4:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_Bridge_send_Serial1_CPUBridgeReady((struct Bridge_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
}
}

void initialize_configuration_TestCfg() {
// Initialize connectors
register_Test_send_bridge_setDigitalHigh_listener(enqueue_Test_send_bridge_setDigitalHigh);
register_Test_send_bridge_setDigitalLow_listener(enqueue_Test_send_bridge_setDigitalLow);
register_Test_send_bridge_setOutput_listener(enqueue_Test_send_bridge_setOutput);
register_Test_send_bridge_setInput_listener(enqueue_Test_send_bridge_setInput);
register_Test_send_bridge_readDigital_listener(enqueue_Test_send_bridge_readDigital);
register_Test_send_bridge_readAnalog_listener(enqueue_Test_send_bridge_readAnalog);
register_Test_send_bridge_timer_start_listener(enqueue_Test_send_bridge_timer_start);
register_Test_send_bridge_timer_cancel_listener(enqueue_Test_send_bridge_timer_cancel);
register_LinuxSerial_send_serial_serial_rx_listener(dispatch_LinuxSerial_send_serial_serial_rx);
register_LinuxSerial_send_serial_serial_closed_listener(dispatch_LinuxSerial_send_serial_serial_closed);
register_LinuxSerial_send_serial_serial_opened_listener(dispatch_LinuxSerial_send_serial_serial_opened);
register_Bridge_send_Serial1_readDigitalResponse_listener(enqueue_Bridge_send_Serial1_readDigitalResponse);
register_Bridge_send_Serial1_readAnalogResponse_listener(enqueue_Bridge_send_Serial1_readAnalogResponse);
register_Bridge_send_Serial1_timeout_listener(enqueue_Bridge_send_Serial1_timeout);
register_Bridge_send_Serial1_CPUBridgeReady_listener(enqueue_Bridge_send_Serial1_CPUBridgeReady);
register_Bridge_send_serial_serial_open_listener(dispatch_Bridge_send_serial_serial_open);
register_Bridge_send_serial_serial_close_listener(dispatch_Bridge_send_serial_serial_close);
register_Bridge_send_serial_serial_tx_listener(dispatch_Bridge_send_serial_serial_tx);

// Init the ID, state variables and properties for instance TestCfg_bridge
TestCfg_bridge_var.id = add_instance( (void*) &TestCfg_bridge_var);
TestCfg_bridge_var.Bridge_BridgeChart_State = BRIDGE_BRIDGECHART_INIT_STATE;
TestCfg_bridge_var.Bridge_BridgeChart_Active_State = BRIDGE_BRIDGECHART_ACTIVE_IDLE_STATE;
TestCfg_bridge_var.Bridge_START_BYTE__var = 18;
TestCfg_bridge_var.Bridge_STOP_BYTE__var = 19;
TestCfg_bridge_var.Bridge_ESCAPE_BYTE__var = 125;
TestCfg_bridge_var.Bridge_MsgSize__var = 0;

// Init the ID, state variables and properties for instance TestCfg_sp
TestCfg_sp_var.id = add_instance( (void*) &TestCfg_sp_var);
TestCfg_sp_var.LinuxSerial_LinuxSerialImpl_State = LINUXSERIAL_LINUXSERIALIMPL_RUNNING_STATE;

// Init the ID, state variables and properties for instance TestCfg_t
TestCfg_t_var.id = add_instance( (void*) &TestCfg_t_var);
TestCfg_t_var.Test_testChart_State = TEST_TESTCHART_INIT_STATE;
TestCfg_t_var.Test_On__var = 0;
TestCfg_t_var.Test_time__var = 500;
TestCfg_t_var.Test_timerID__var = 0;
TestCfg_t_var.Test_Led__var = 13;

Test_testChart_OnEntry(TEST_TESTCHART_STATE, &TestCfg_t_var);
LinuxSerial_LinuxSerialImpl_OnEntry(LINUXSERIAL_LINUXSERIALIMPL_STATE, &TestCfg_sp_var);
Bridge_BridgeChart_OnEntry(BRIDGE_BRIDGECHART_STATE, &TestCfg_bridge_var);
}


// NO C_GLOBALS Annotation

int main(int argc, char *argv[]) {
  init_runtime();
  // NO C_MAIN Annotation
  initialize_configuration_TestCfg();

  while (1) {
    Bridge_handle_empty_event(&TestCfg_bridge_var);

    processMessageQueue();
  }
}