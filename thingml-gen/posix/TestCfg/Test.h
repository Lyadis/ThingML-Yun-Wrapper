/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing Test
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef Test_H_
#define Test_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : Test
 *****************************************************************************/

// Definition of the instance stuct:
struct Test_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int Test_testChart_State;
// Variables for the properties of the instance
uint8_t Test_On__var;
uint16_t Test_time__var;
uint8_t Test_timerID__var;
uint8_t Test_Led__var;
};

// Declaration of prototypes outgoing messages:
void Test_testChart_OnEntry(int state, struct Test_Instance *_instance);
void Test_handle_bridge_timeout(struct Test_Instance *_instance, uint8_t id);
void Test_handle_bridge_CPUBridgeReady(struct Test_Instance *_instance);
// Declaration of callbacks for incomming messages:
void register_Test_send_bridge_setDigitalHigh_listener(void (*_listener)(struct Test_Instance*, uint8_t));
void register_Test_send_bridge_setDigitalLow_listener(void (*_listener)(struct Test_Instance*, uint8_t));
void register_Test_send_bridge_setOutput_listener(void (*_listener)(struct Test_Instance*, uint8_t));
void register_Test_send_bridge_setInput_listener(void (*_listener)(struct Test_Instance*, uint8_t));
void register_Test_send_bridge_readDigital_listener(void (*_listener)(struct Test_Instance*, uint8_t));
void register_Test_send_bridge_readAnalog_listener(void (*_listener)(struct Test_Instance*, uint8_t));
void register_Test_send_bridge_timer_start_listener(void (*_listener)(struct Test_Instance*, uint8_t, int16_t));
void register_Test_send_bridge_timer_cancel_listener(void (*_listener)(struct Test_Instance*, uint8_t));

// Definition of the states:
#define TEST_TESTCHART_STATE 0
#define TEST_TESTCHART_INIT_STATE 1
#define TEST_TESTCHART_BLINK_STATE 2



#ifdef __cplusplus
}
#endif

#endif //Test_H_