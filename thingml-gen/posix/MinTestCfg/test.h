/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing test
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef test_H_
#define test_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : test
 *****************************************************************************/

// Definition of the instance stuct:
struct test_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int test_TestChart_State;
// Variables for the properties of the instance
};

// Declaration of prototypes outgoing messages:
void test_TestChart_OnEntry(int state, struct test_Instance *_instance);
void test_handle_serial_serial_rx(struct test_Instance *_instance, uint8_t b);
void test_handle_serial_serial_opened(struct test_Instance *_instance);
// Declaration of callbacks for incomming messages:
void register_test_send_serial_serial_open_listener(void (*_listener)(struct test_Instance*, char *, int));
void register_test_send_serial_serial_close_listener(void (*_listener)(struct test_Instance*));
void register_test_send_serial_serial_tx_listener(void (*_listener)(struct test_Instance*, uint8_t));

// Definition of the states:
#define TEST_TESTCHART_STATE 0
#define TEST_TESTCHART_INIT_STATE 1
#define TEST_TESTCHART_PARLE_STATE 2



#ifdef __cplusplus
}
#endif

#endif //test_H_