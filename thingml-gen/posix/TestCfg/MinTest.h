/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing MinTest
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef MinTest_H_
#define MinTest_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : MinTest
 *****************************************************************************/

// Definition of the instance stuct:
struct MinTest_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int MinTest_TestChart_State;
// Variables for the properties of the instance
};

// Declaration of prototypes outgoing messages:
void MinTest_TestChart_OnEntry(int state, struct MinTest_Instance *_instance);
void MinTest_handle_serial_serial_opened(struct MinTest_Instance *_instance);
void MinTest_handle_serial_serial_rx(struct MinTest_Instance *_instance, uint8_t b);
// Declaration of callbacks for incomming messages:
void register_MinTest_send_serial_serial_open_listener(void (*_listener)(struct MinTest_Instance*, char *, int));
void register_MinTest_send_serial_serial_close_listener(void (*_listener)(struct MinTest_Instance*));
void register_MinTest_send_serial_serial_tx_listener(void (*_listener)(struct MinTest_Instance*, uint8_t));

// Definition of the states:
#define MINTEST_TESTCHART_STATE 0
#define MINTEST_TESTCHART_INIT_STATE 1
#define MINTEST_TESTCHART_PARLE_STATE 2



#ifdef __cplusplus
}
#endif

#endif //MinTest_H_