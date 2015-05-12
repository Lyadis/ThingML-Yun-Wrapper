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
#include "Bridge.h"
#include "LinuxSerial.h"


// NO C_HEADERS Annotation


/*****************************************************************************
 * Definitions for configuration : TestCfg
 *****************************************************************************/

//Declaration of instance variables
struct Bridge_Instance TestCfg_bridge_var;
struct LinuxSerial_Instance TestCfg_sp_var;


// Dispatch for messages Bridge::serial::serial_open
void dispatch_Bridge_send_serial_serial_open(struct Bridge_Instance *_instance, char * device, int baudrate){
if (_instance == &TestCfg_bridge_var) {
LinuxSerial_handle_serial_serial_open(&TestCfg_sp_var, device, baudrate);
}
}
// Dispatch for messages Bridge::serial::serial_tx
void dispatch_Bridge_send_serial_serial_tx(struct Bridge_Instance *_instance, uint8_t b){
if (_instance == &TestCfg_bridge_var) {
LinuxSerial_handle_serial_serial_tx(&TestCfg_sp_var, b);
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
// Dispatch for messages LinuxSerial::serial::serial_rx
void dispatch_LinuxSerial_send_serial_serial_rx(struct LinuxSerial_Instance *_instance, uint8_t b){
if (_instance == &TestCfg_sp_var) {
Bridge_handle_serial_serial_rx(&TestCfg_bridge_var, b);
}
}
// Dispatch for messages LinuxSerial::serial::serial_opened
void dispatch_LinuxSerial_send_serial_serial_opened(struct LinuxSerial_Instance *_instance){
if (_instance == &TestCfg_sp_var) {
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
register_Bridge_send_serial_serial_open_listener(dispatch_Bridge_send_serial_serial_open);
register_Bridge_send_serial_serial_close_listener(dispatch_Bridge_send_serial_serial_close);
register_Bridge_send_serial_serial_tx_listener(dispatch_Bridge_send_serial_serial_tx);
register_LinuxSerial_send_serial_serial_rx_listener(dispatch_LinuxSerial_send_serial_serial_rx);
register_LinuxSerial_send_serial_serial_closed_listener(dispatch_LinuxSerial_send_serial_serial_closed);
register_LinuxSerial_send_serial_serial_opened_listener(dispatch_LinuxSerial_send_serial_serial_opened);

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

Bridge_BridgeChart_OnEntry(BRIDGE_BRIDGECHART_STATE, &TestCfg_bridge_var);
LinuxSerial_LinuxSerialImpl_OnEntry(LINUXSERIAL_LINUXSERIALIMPL_STATE, &TestCfg_sp_var);
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