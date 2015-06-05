/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing Bridge
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "Bridge.h"

/*****************************************************************************
 * Implementation for type : Bridge
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void Bridge_BridgeChart_OnExit(int state, struct Bridge_Instance *_instance);
void Bridge_send_Serial1_readDigitalResponse(struct Bridge_Instance *_instance, uint8_t pin, uint8_t DigitalState);
void Bridge_send_Serial1_readAnalogResponse(struct Bridge_Instance *_instance, uint8_t pin, int res);
void Bridge_send_Serial1_timeout(struct Bridge_Instance *_instance, uint8_t id);
void Bridge_send_Serial1_CPUBridgeReady(struct Bridge_Instance *_instance);
void Bridge_send_serial_serial_open(struct Bridge_Instance *_instance, char * device, int baudrate);
void Bridge_send_serial_serial_close(struct Bridge_Instance *_instance);
void Bridge_send_serial_serial_tx(struct Bridge_Instance *_instance, uint8_t b);
void f_Bridge_SerialSend(struct Bridge_Instance *_instance, uint8_t b);
void f_Bridge_SerialStart(struct Bridge_Instance *_instance);
void f_Bridge_SerialStop(struct Bridge_Instance *_instance);
void f_Bridge_parse(struct Bridge_Instance *_instance);
#ifdef __cplusplus
}
#endif

// Declaration of functions:
// Definition of function SerialSend
void f_Bridge_SerialSend(struct Bridge_Instance *_instance, uint8_t b) {
{
if((b == _instance->Bridge_START_BYTE__var) || (b == _instance->Bridge_STOP_BYTE__var) || (b == _instance->Bridge_ESCAPE_BYTE__var)) {
Bridge_send_serial_serial_tx(_instance, _instance->Bridge_ESCAPE_BYTE__var);
}
Bridge_send_serial_serial_tx(_instance, b);
}
}

// Definition of function SerialStart
void f_Bridge_SerialStart(struct Bridge_Instance *_instance) {
{
Bridge_send_serial_serial_tx(_instance, _instance->Bridge_START_BYTE__var);
}
}

// Definition of function SerialStop
void f_Bridge_SerialStop(struct Bridge_Instance *_instance) {
{
Bridge_send_serial_serial_tx(_instance, _instance->Bridge_STOP_BYTE__var);
}
}

// Definition of function parse
void f_Bridge_parse(struct Bridge_Instance *_instance) {
{
uint16_t msgID = 256 * _instance->Bridge_Buffer__var[0] + _instance->Bridge_Buffer__var[1];
		switch(msgID){
			case 2://readDigitalResponse
				if(_instance->Bridge_Buffer__var[5] == 0) {
					
Bridge_send_Serial1_readDigitalResponse(_instance, _instance->Bridge_Buffer__var[4], DIGITALSTATE_LOW);

				} else {
					
Bridge_send_Serial1_readDigitalResponse(_instance, _instance->Bridge_Buffer__var[4], DIGITALSTATE_HIGH);

				}
			break;
			
			case 9://readAnalogResponse
				
Bridge_send_Serial1_readAnalogResponse(_instance, _instance->Bridge_Buffer__var[4], _instance->Bridge_Buffer__var[5] * 256 + _instance->Bridge_Buffer__var[6]);

			break;
			
			case 8://timeout
				
Bridge_send_Serial1_timeout(_instance, _instance->Bridge_Buffer__var[4]);

			break;
		}
}
}


// On Entry Actions:
void Bridge_BridgeChart_OnEntry(int state, struct Bridge_Instance *_instance) {
switch(state) {
case BRIDGE_BRIDGECHART_STATE:
_instance->Bridge_BridgeChart_State = BRIDGE_BRIDGECHART_INIT_STATE;
Bridge_BridgeChart_OnEntry(_instance->Bridge_BridgeChart_State, _instance);
break;
case BRIDGE_BRIDGECHART_INIT_STATE:
{
Bridge_send_serial_serial_open(_instance, "/dev/ttyATH0", _instance->Bridge_bps__var);
}
break;
case BRIDGE_BRIDGECHART_ACTIVE_STATE:
_instance->Bridge_BridgeChart_Active_State = BRIDGE_BRIDGECHART_ACTIVE_IDLE_STATE;
Bridge_BridgeChart_OnEntry(_instance->Bridge_BridgeChart_Active_State, _instance);
break;
case BRIDGE_BRIDGECHART_ACTIVE_IDLE_STATE:
break;
case BRIDGE_BRIDGECHART_ACTIVE_READING_STATE:
break;
case BRIDGE_BRIDGECHART_ACTIVE_ESCAPING_STATE:
break;
case BRIDGE_BRIDGECHART_ACTIVE_ERROR_STATE:
break;
default: break;
}
}

// On Exit Actions:
void Bridge_BridgeChart_OnExit(int state, struct Bridge_Instance *_instance) {
switch(state) {
case BRIDGE_BRIDGECHART_STATE:
Bridge_BridgeChart_OnExit(_instance->Bridge_BridgeChart_State, _instance);
break;
case BRIDGE_BRIDGECHART_INIT_STATE:
break;
case BRIDGE_BRIDGECHART_ACTIVE_STATE:
Bridge_BridgeChart_OnExit(_instance->Bridge_BridgeChart_Active_State, _instance);
break;
case BRIDGE_BRIDGECHART_ACTIVE_IDLE_STATE:
break;
case BRIDGE_BRIDGECHART_ACTIVE_READING_STATE:
break;
case BRIDGE_BRIDGECHART_ACTIVE_ESCAPING_STATE:
break;
case BRIDGE_BRIDGECHART_ACTIVE_ERROR_STATE:
break;
default: break;
}
}

// Event Handlers for incoming messages:
void Bridge_handle_Serial1_timer_start(struct Bridge_Instance *_instance, uint8_t id, int16_t time) {
uint8_t Bridge_BridgeChart_State_event_consumed = 0;
if (_instance->Bridge_BridgeChart_State == BRIDGE_BRIDGECHART_ACTIVE_STATE) {
uint8_t Bridge_BridgeChart_Active_State_event_consumed = 0;
Bridge_BridgeChart_State_event_consumed = 0 | Bridge_BridgeChart_Active_State_event_consumed ;
if (Bridge_BridgeChart_State_event_consumed == 0 && 1) {
{
f_Bridge_SerialStart(_instance);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 16);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 1);
f_Bridge_SerialSend(_instance, id);
f_Bridge_SerialSend(_instance, (time>>8) & 0xFF);
f_Bridge_SerialSend(_instance, time & 0xFF);
f_Bridge_SerialStop(_instance);
}
Bridge_BridgeChart_State_event_consumed = 1;
}
}
}
void Bridge_handle_Serial1_readAnalog(struct Bridge_Instance *_instance, uint8_t pin) {
uint8_t Bridge_BridgeChart_State_event_consumed = 0;
if (_instance->Bridge_BridgeChart_State == BRIDGE_BRIDGECHART_ACTIVE_STATE) {
uint8_t Bridge_BridgeChart_Active_State_event_consumed = 0;
Bridge_BridgeChart_State_event_consumed = 0 | Bridge_BridgeChart_Active_State_event_consumed ;
if (Bridge_BridgeChart_State_event_consumed == 0 && 1) {
{
f_Bridge_SerialStart(_instance);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 10);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 1);
f_Bridge_SerialSend(_instance, pin);
f_Bridge_SerialStop(_instance);
}
Bridge_BridgeChart_State_event_consumed = 1;
}
}
}
void Bridge_handle_Serial1_setInput(struct Bridge_Instance *_instance, uint8_t pin) {
uint8_t Bridge_BridgeChart_State_event_consumed = 0;
if (_instance->Bridge_BridgeChart_State == BRIDGE_BRIDGECHART_ACTIVE_STATE) {
uint8_t Bridge_BridgeChart_Active_State_event_consumed = 0;
Bridge_BridgeChart_State_event_consumed = 0 | Bridge_BridgeChart_Active_State_event_consumed ;
if (Bridge_BridgeChart_State_event_consumed == 0 && 1) {
{
f_Bridge_SerialStart(_instance);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 15);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 1);
f_Bridge_SerialSend(_instance, pin);
f_Bridge_SerialStop(_instance);
}
Bridge_BridgeChart_State_event_consumed = 1;
}
}
}
void Bridge_handle_Serial1_setDigitalLow(struct Bridge_Instance *_instance, uint8_t pin) {
uint8_t Bridge_BridgeChart_State_event_consumed = 0;
if (_instance->Bridge_BridgeChart_State == BRIDGE_BRIDGECHART_ACTIVE_STATE) {
uint8_t Bridge_BridgeChart_Active_State_event_consumed = 0;
Bridge_BridgeChart_State_event_consumed = 0 | Bridge_BridgeChart_Active_State_event_consumed ;
if (Bridge_BridgeChart_State_event_consumed == 0 && 1) {
{
f_Bridge_SerialStart(_instance);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 13);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 1);
f_Bridge_SerialSend(_instance, pin);
f_Bridge_SerialStop(_instance);
}
Bridge_BridgeChart_State_event_consumed = 1;
}
}
}
void Bridge_handle_Serial1_setDigitalHigh(struct Bridge_Instance *_instance, uint8_t pin) {
uint8_t Bridge_BridgeChart_State_event_consumed = 0;
if (_instance->Bridge_BridgeChart_State == BRIDGE_BRIDGECHART_ACTIVE_STATE) {
uint8_t Bridge_BridgeChart_Active_State_event_consumed = 0;
Bridge_BridgeChart_State_event_consumed = 0 | Bridge_BridgeChart_Active_State_event_consumed ;
if (Bridge_BridgeChart_State_event_consumed == 0 && 1) {
{
f_Bridge_SerialStart(_instance);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 11);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 1);
f_Bridge_SerialSend(_instance, pin);
f_Bridge_SerialStop(_instance);
}
Bridge_BridgeChart_State_event_consumed = 1;
}
}
}
void Bridge_handle_Serial1_setOutput(struct Bridge_Instance *_instance, uint8_t pin) {
uint8_t Bridge_BridgeChart_State_event_consumed = 0;
if (_instance->Bridge_BridgeChart_State == BRIDGE_BRIDGECHART_ACTIVE_STATE) {
uint8_t Bridge_BridgeChart_Active_State_event_consumed = 0;
Bridge_BridgeChart_State_event_consumed = 0 | Bridge_BridgeChart_Active_State_event_consumed ;
if (Bridge_BridgeChart_State_event_consumed == 0 && 1) {
{
f_Bridge_SerialStart(_instance);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 12);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 1);
f_Bridge_SerialSend(_instance, pin);
f_Bridge_SerialStop(_instance);
}
Bridge_BridgeChart_State_event_consumed = 1;
}
}
}
void Bridge_handle_Serial1_readDigital(struct Bridge_Instance *_instance, uint8_t pin) {
uint8_t Bridge_BridgeChart_State_event_consumed = 0;
if (_instance->Bridge_BridgeChart_State == BRIDGE_BRIDGECHART_ACTIVE_STATE) {
uint8_t Bridge_BridgeChart_Active_State_event_consumed = 0;
Bridge_BridgeChart_State_event_consumed = 0 | Bridge_BridgeChart_Active_State_event_consumed ;
if (Bridge_BridgeChart_State_event_consumed == 0 && 1) {
{
f_Bridge_SerialStart(_instance);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 14);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 1);
f_Bridge_SerialSend(_instance, pin);
f_Bridge_SerialStop(_instance);
}
Bridge_BridgeChart_State_event_consumed = 1;
}
}
}
void Bridge_handle_Serial1_timer_cancel(struct Bridge_Instance *_instance, uint8_t id) {
uint8_t Bridge_BridgeChart_State_event_consumed = 0;
if (_instance->Bridge_BridgeChart_State == BRIDGE_BRIDGECHART_ACTIVE_STATE) {
uint8_t Bridge_BridgeChart_Active_State_event_consumed = 0;
Bridge_BridgeChart_State_event_consumed = 0 | Bridge_BridgeChart_Active_State_event_consumed ;
if (Bridge_BridgeChart_State_event_consumed == 0 && 1) {
{
f_Bridge_SerialStart(_instance);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 17);
f_Bridge_SerialSend(_instance, 0);
f_Bridge_SerialSend(_instance, 1);
f_Bridge_SerialSend(_instance, id);
f_Bridge_SerialStop(_instance);
}
Bridge_BridgeChart_State_event_consumed = 1;
}
}
}
void Bridge_handle_serial_serial_rx(struct Bridge_Instance *_instance, uint8_t b) {
uint8_t Bridge_BridgeChart_State_event_consumed = 0;
if (_instance->Bridge_BridgeChart_State == BRIDGE_BRIDGECHART_ACTIVE_STATE) {
uint8_t Bridge_BridgeChart_Active_State_event_consumed = 0;
if (_instance->Bridge_BridgeChart_Active_State == BRIDGE_BRIDGECHART_ACTIVE_IDLE_STATE) {
if (Bridge_BridgeChart_Active_State_event_consumed == 0 && b == _instance->Bridge_START_BYTE__var) {
Bridge_BridgeChart_OnExit(BRIDGE_BRIDGECHART_ACTIVE_IDLE_STATE, _instance);
_instance->Bridge_BridgeChart_Active_State = BRIDGE_BRIDGECHART_ACTIVE_READING_STATE;
Bridge_BridgeChart_OnEntry(BRIDGE_BRIDGECHART_ACTIVE_READING_STATE, _instance);
Bridge_BridgeChart_Active_State_event_consumed = 1;
}
}
else if (_instance->Bridge_BridgeChart_Active_State == BRIDGE_BRIDGECHART_ACTIVE_READING_STATE) {
if (Bridge_BridgeChart_Active_State_event_consumed == 0 && _instance->Bridge_MsgSize__var > 31) {
Bridge_BridgeChart_OnExit(BRIDGE_BRIDGECHART_ACTIVE_READING_STATE, _instance);
_instance->Bridge_BridgeChart_Active_State = BRIDGE_BRIDGECHART_ACTIVE_ERROR_STATE;
Bridge_BridgeChart_OnEntry(BRIDGE_BRIDGECHART_ACTIVE_ERROR_STATE, _instance);
Bridge_BridgeChart_Active_State_event_consumed = 1;
}
else if (Bridge_BridgeChart_Active_State_event_consumed == 0 && b == _instance->Bridge_ESCAPE_BYTE__var) {
Bridge_BridgeChart_OnExit(BRIDGE_BRIDGECHART_ACTIVE_READING_STATE, _instance);
_instance->Bridge_BridgeChart_Active_State = BRIDGE_BRIDGECHART_ACTIVE_ESCAPING_STATE;
Bridge_BridgeChart_OnEntry(BRIDGE_BRIDGECHART_ACTIVE_ESCAPING_STATE, _instance);
Bridge_BridgeChart_Active_State_event_consumed = 1;
}
else if (Bridge_BridgeChart_Active_State_event_consumed == 0 && b == _instance->Bridge_STOP_BYTE__var) {
Bridge_BridgeChart_OnExit(BRIDGE_BRIDGECHART_ACTIVE_READING_STATE, _instance);
_instance->Bridge_BridgeChart_Active_State = BRIDGE_BRIDGECHART_ACTIVE_IDLE_STATE;
{
f_Bridge_parse(_instance);
_instance->Bridge_MsgSize__var = 0;
}
Bridge_BridgeChart_OnEntry(BRIDGE_BRIDGECHART_ACTIVE_IDLE_STATE, _instance);
Bridge_BridgeChart_Active_State_event_consumed = 1;
}
else if (Bridge_BridgeChart_Active_State_event_consumed == 0 && 1) {
Bridge_BridgeChart_OnExit(BRIDGE_BRIDGECHART_ACTIVE_READING_STATE, _instance);
_instance->Bridge_BridgeChart_Active_State = BRIDGE_BRIDGECHART_ACTIVE_READING_STATE;
{
_instance->Bridge_Buffer__var[_instance->Bridge_MsgSize__var] = b;
_instance->Bridge_MsgSize__var = _instance->Bridge_MsgSize__var + 1;
}
Bridge_BridgeChart_OnEntry(BRIDGE_BRIDGECHART_ACTIVE_READING_STATE, _instance);
Bridge_BridgeChart_Active_State_event_consumed = 1;
}
}
else if (_instance->Bridge_BridgeChart_Active_State == BRIDGE_BRIDGECHART_ACTIVE_ESCAPING_STATE) {
if (Bridge_BridgeChart_Active_State_event_consumed == 0 && _instance->Bridge_MsgSize__var > 31) {
Bridge_BridgeChart_OnExit(BRIDGE_BRIDGECHART_ACTIVE_ESCAPING_STATE, _instance);
_instance->Bridge_BridgeChart_Active_State = BRIDGE_BRIDGECHART_ACTIVE_ERROR_STATE;
Bridge_BridgeChart_OnEntry(BRIDGE_BRIDGECHART_ACTIVE_ERROR_STATE, _instance);
Bridge_BridgeChart_Active_State_event_consumed = 1;
}
else if (Bridge_BridgeChart_Active_State_event_consumed == 0 && 1) {
Bridge_BridgeChart_OnExit(BRIDGE_BRIDGECHART_ACTIVE_ESCAPING_STATE, _instance);
_instance->Bridge_BridgeChart_Active_State = BRIDGE_BRIDGECHART_ACTIVE_READING_STATE;
{
_instance->Bridge_Buffer__var[_instance->Bridge_MsgSize__var] = b;
_instance->Bridge_MsgSize__var = _instance->Bridge_MsgSize__var + 1;
}
Bridge_BridgeChart_OnEntry(BRIDGE_BRIDGECHART_ACTIVE_READING_STATE, _instance);
Bridge_BridgeChart_Active_State_event_consumed = 1;
}
}
Bridge_BridgeChart_State_event_consumed = 0 | Bridge_BridgeChart_Active_State_event_consumed ;
if (Bridge_BridgeChart_State_event_consumed == 0 && 1) {
{
}
Bridge_BridgeChart_State_event_consumed = 1;
}
}
}
void Bridge_handle_serial_serial_opened(struct Bridge_Instance *_instance) {
uint8_t Bridge_BridgeChart_State_event_consumed = 0;
if (_instance->Bridge_BridgeChart_State == BRIDGE_BRIDGECHART_INIT_STATE) {
if (Bridge_BridgeChart_State_event_consumed == 0 && 1) {
Bridge_BridgeChart_OnExit(BRIDGE_BRIDGECHART_INIT_STATE, _instance);
_instance->Bridge_BridgeChart_State = BRIDGE_BRIDGECHART_ACTIVE_STATE;
{
Bridge_send_Serial1_CPUBridgeReady(_instance);
}
Bridge_BridgeChart_OnEntry(BRIDGE_BRIDGECHART_ACTIVE_STATE, _instance);
Bridge_BridgeChart_State_event_consumed = 1;
}
}
}
void Bridge_handle_empty_event(struct Bridge_Instance *_instance) {
if (_instance->Bridge_BridgeChart_State == BRIDGE_BRIDGECHART_ACTIVE_STATE) {
if (_instance->Bridge_BridgeChart_Active_State == BRIDGE_BRIDGECHART_ACTIVE_ERROR_STATE) {
if (1) {
Bridge_BridgeChart_OnExit(BRIDGE_BRIDGECHART_ACTIVE_ERROR_STATE, _instance);
_instance->Bridge_BridgeChart_Active_State = BRIDGE_BRIDGECHART_ACTIVE_IDLE_STATE;
{
_instance->Bridge_MsgSize__var = 0;
}
Bridge_BridgeChart_OnEntry(BRIDGE_BRIDGECHART_ACTIVE_IDLE_STATE, _instance);
}
}
}
}

// Observers for outgoing messages:
void (*Bridge_send_Serial1_readDigitalResponse_listener)(struct Bridge_Instance*, uint8_t, uint8_t)= 0x0;
void register_Bridge_send_Serial1_readDigitalResponse_listener(void (*_listener)(struct Bridge_Instance*, uint8_t, uint8_t)){
Bridge_send_Serial1_readDigitalResponse_listener = _listener;
}
void Bridge_send_Serial1_readDigitalResponse(struct Bridge_Instance *_instance, uint8_t pin, uint8_t DigitalState){
if (Bridge_send_Serial1_readDigitalResponse_listener != 0x0) Bridge_send_Serial1_readDigitalResponse_listener(_instance, pin, DigitalState);
}
void (*Bridge_send_Serial1_readAnalogResponse_listener)(struct Bridge_Instance*, uint8_t, int)= 0x0;
void register_Bridge_send_Serial1_readAnalogResponse_listener(void (*_listener)(struct Bridge_Instance*, uint8_t, int)){
Bridge_send_Serial1_readAnalogResponse_listener = _listener;
}
void Bridge_send_Serial1_readAnalogResponse(struct Bridge_Instance *_instance, uint8_t pin, int res){
if (Bridge_send_Serial1_readAnalogResponse_listener != 0x0) Bridge_send_Serial1_readAnalogResponse_listener(_instance, pin, res);
}
void (*Bridge_send_Serial1_timeout_listener)(struct Bridge_Instance*, uint8_t)= 0x0;
void register_Bridge_send_Serial1_timeout_listener(void (*_listener)(struct Bridge_Instance*, uint8_t)){
Bridge_send_Serial1_timeout_listener = _listener;
}
void Bridge_send_Serial1_timeout(struct Bridge_Instance *_instance, uint8_t id){
if (Bridge_send_Serial1_timeout_listener != 0x0) Bridge_send_Serial1_timeout_listener(_instance, id);
}
void (*Bridge_send_Serial1_CPUBridgeReady_listener)(struct Bridge_Instance*)= 0x0;
void register_Bridge_send_Serial1_CPUBridgeReady_listener(void (*_listener)(struct Bridge_Instance*)){
Bridge_send_Serial1_CPUBridgeReady_listener = _listener;
}
void Bridge_send_Serial1_CPUBridgeReady(struct Bridge_Instance *_instance){
if (Bridge_send_Serial1_CPUBridgeReady_listener != 0x0) Bridge_send_Serial1_CPUBridgeReady_listener(_instance);
}
void (*Bridge_send_serial_serial_open_listener)(struct Bridge_Instance*, char *, int)= 0x0;
void register_Bridge_send_serial_serial_open_listener(void (*_listener)(struct Bridge_Instance*, char *, int)){
Bridge_send_serial_serial_open_listener = _listener;
}
void Bridge_send_serial_serial_open(struct Bridge_Instance *_instance, char * device, int baudrate){
if (Bridge_send_serial_serial_open_listener != 0x0) Bridge_send_serial_serial_open_listener(_instance, device, baudrate);
}
void (*Bridge_send_serial_serial_close_listener)(struct Bridge_Instance*)= 0x0;
void register_Bridge_send_serial_serial_close_listener(void (*_listener)(struct Bridge_Instance*)){
Bridge_send_serial_serial_close_listener = _listener;
}
void Bridge_send_serial_serial_close(struct Bridge_Instance *_instance){
if (Bridge_send_serial_serial_close_listener != 0x0) Bridge_send_serial_serial_close_listener(_instance);
}
void (*Bridge_send_serial_serial_tx_listener)(struct Bridge_Instance*, uint8_t)= 0x0;
void register_Bridge_send_serial_serial_tx_listener(void (*_listener)(struct Bridge_Instance*, uint8_t)){
Bridge_send_serial_serial_tx_listener = _listener;
}
void Bridge_send_serial_serial_tx(struct Bridge_Instance *_instance, uint8_t b){
if (Bridge_send_serial_serial_tx_listener != 0x0) Bridge_send_serial_serial_tx_listener(_instance, b);
}

