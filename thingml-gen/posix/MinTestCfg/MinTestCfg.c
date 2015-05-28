/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application MinTestCfg
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
#include "test.h"


// NO C_HEADERS Annotation


/*****************************************************************************
 * Definitions for configuration : MinTestCfg
 *****************************************************************************/

//Declaration of instance variables
struct test_Instance MinTestCfg_t_var;
struct LinuxSerial_Instance MinTestCfg_sp_var;


// Dispatch for messages test::serial::serial_open
void dispatch_test_send_serial_serial_open(struct test_Instance *_instance, char * device, int baudrate){
if (_instance == &MinTestCfg_t_var) {
LinuxSerial_handle_serial_serial_open(&MinTestCfg_sp_var, device, baudrate);
}
}
// Dispatch for messages test::serial::serial_tx
void dispatch_test_send_serial_serial_tx(struct test_Instance *_instance, uint8_t b){
if (_instance == &MinTestCfg_t_var) {
LinuxSerial_handle_serial_serial_tx(&MinTestCfg_sp_var, b);
}
}
// Dispatch for messages test::serial::serial_close
void dispatch_test_send_serial_serial_close(struct test_Instance *_instance){
if (_instance == &MinTestCfg_t_var) {
}
}
// Dispatch for messages LinuxSerial::serial::serial_rx
void dispatch_LinuxSerial_send_serial_serial_rx(struct LinuxSerial_Instance *_instance, uint8_t b){
if (_instance == &MinTestCfg_sp_var) {
test_handle_serial_serial_rx(&MinTestCfg_t_var, b);
}
}
// Dispatch for messages LinuxSerial::serial::serial_opened
void dispatch_LinuxSerial_send_serial_serial_opened(struct LinuxSerial_Instance *_instance){
if (_instance == &MinTestCfg_sp_var) {
test_handle_serial_serial_opened(&MinTestCfg_t_var);
}
}
// Dispatch for messages LinuxSerial::serial::serial_closed
void dispatch_LinuxSerial_send_serial_serial_closed(struct LinuxSerial_Instance *_instance){
if (_instance == &MinTestCfg_sp_var) {
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

void initialize_configuration_MinTestCfg() {
// Initialize connectors
register_LinuxSerial_send_serial_serial_rx_listener(dispatch_LinuxSerial_send_serial_serial_rx);
register_LinuxSerial_send_serial_serial_closed_listener(dispatch_LinuxSerial_send_serial_serial_closed);
register_LinuxSerial_send_serial_serial_opened_listener(dispatch_LinuxSerial_send_serial_serial_opened);
register_test_send_serial_serial_open_listener(dispatch_test_send_serial_serial_open);
register_test_send_serial_serial_close_listener(dispatch_test_send_serial_serial_close);
register_test_send_serial_serial_tx_listener(dispatch_test_send_serial_serial_tx);

// Init the ID, state variables and properties for instance MinTestCfg_sp
MinTestCfg_sp_var.id = add_instance( (void*) &MinTestCfg_sp_var);
MinTestCfg_sp_var.LinuxSerial_LinuxSerialImpl_State = LINUXSERIAL_LINUXSERIALIMPL_RUNNING_STATE;

// Init the ID, state variables and properties for instance MinTestCfg_t
MinTestCfg_t_var.id = add_instance( (void*) &MinTestCfg_t_var);
MinTestCfg_t_var.test_TestChart_State = TEST_TESTCHART_INIT_STATE;

test_TestChart_OnEntry(TEST_TESTCHART_STATE, &MinTestCfg_t_var);
LinuxSerial_LinuxSerialImpl_OnEntry(LINUXSERIAL_LINUXSERIALIMPL_STATE, &MinTestCfg_sp_var);
}


// NO C_GLOBALS Annotation

int main(int argc, char *argv[]) {
  init_runtime();
  // NO C_MAIN Annotation
  initialize_configuration_MinTestCfg();

  while (1) {
    
    processMessageQueue();
  }
}