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
#include "MinTest.h"
#include "LinuxSerial.h"


// NO C_HEADERS Annotation


/*****************************************************************************
 * Definitions for configuration : TestCfg
 *****************************************************************************/

//Declaration of instance variables
struct LinuxSerial_Instance TestCfg_sp_var;
struct MinTest_Instance TestCfg_t_var;


// Dispatch for messages LinuxSerial::serial::serial_opened
void dispatch_LinuxSerial_send_serial_serial_opened(struct LinuxSerial_Instance *_instance){
if (_instance == &TestCfg_sp_var) {
MinTest_handle_serial_serial_opened(&TestCfg_t_var);
}
}
// Dispatch for messages LinuxSerial::serial::serial_closed
void dispatch_LinuxSerial_send_serial_serial_closed(struct LinuxSerial_Instance *_instance){
if (_instance == &TestCfg_sp_var) {
}
}
// Dispatch for messages LinuxSerial::serial::serial_rx
void dispatch_LinuxSerial_send_serial_serial_rx(struct LinuxSerial_Instance *_instance, uint8_t b){
if (_instance == &TestCfg_sp_var) {
MinTest_handle_serial_serial_rx(&TestCfg_t_var, b);
}
}
// Dispatch for messages MinTest::serial::serial_close
void dispatch_MinTest_send_serial_serial_close(struct MinTest_Instance *_instance){
if (_instance == &TestCfg_t_var) {
}
}
// Dispatch for messages MinTest::serial::serial_tx
void dispatch_MinTest_send_serial_serial_tx(struct MinTest_Instance *_instance, uint8_t b){
if (_instance == &TestCfg_t_var) {
LinuxSerial_handle_serial_serial_tx(&TestCfg_sp_var, b);
}
}
// Dispatch for messages MinTest::serial::serial_open
void dispatch_MinTest_send_serial_serial_open(struct MinTest_Instance *_instance, char * device, int baudrate){
if (_instance == &TestCfg_t_var) {
LinuxSerial_handle_serial_serial_open(&TestCfg_sp_var, device, baudrate);
}
}

void processMessageQueue() {
fifo_lock();
while (fifo_empty()) fifo_wait();
byte mbuf[2];
uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
}
}

void initialize_configuration_TestCfg() {
// Initialize connectors
register_MinTest_send_serial_serial_open_listener(dispatch_MinTest_send_serial_serial_open);
register_MinTest_send_serial_serial_close_listener(dispatch_MinTest_send_serial_serial_close);
register_MinTest_send_serial_serial_tx_listener(dispatch_MinTest_send_serial_serial_tx);
register_LinuxSerial_send_serial_serial_rx_listener(dispatch_LinuxSerial_send_serial_serial_rx);
register_LinuxSerial_send_serial_serial_closed_listener(dispatch_LinuxSerial_send_serial_serial_closed);
register_LinuxSerial_send_serial_serial_opened_listener(dispatch_LinuxSerial_send_serial_serial_opened);

// Init the ID, state variables and properties for instance TestCfg_sp
TestCfg_sp_var.id = add_instance( (void*) &TestCfg_sp_var);
TestCfg_sp_var.LinuxSerial_LinuxSerialImpl_State = LINUXSERIAL_LINUXSERIALIMPL_RUNNING_STATE;

// Init the ID, state variables and properties for instance TestCfg_t
TestCfg_t_var.id = add_instance( (void*) &TestCfg_t_var);
TestCfg_t_var.MinTest_TestChart_State = MINTEST_TESTCHART_INIT_STATE;

LinuxSerial_LinuxSerialImpl_OnEntry(LINUXSERIAL_LINUXSERIALIMPL_STATE, &TestCfg_sp_var);
MinTest_TestChart_OnEntry(MINTEST_TESTCHART_STATE, &TestCfg_t_var);
}


// NO C_GLOBALS Annotation

int main(int argc, char *argv[]) {
  init_runtime();
  // NO C_MAIN Annotation
  initialize_configuration_TestCfg();

  while (1) {
    
    processMessageQueue();
  }
}