#ifndef __cplusplus
#error A C++ compiler is required!
#endif

#ifndef _MGOS_ARDUINO_IR_REMOTE_H_
#define _MGOS_ARDUINO_IR_REMOTE_H_
#include <string>

#include "fw/src/mgos_features.h"

#include "IRrecv.h"
#include "IRsend.h"

#ifdef __cplusplus
extern "C" {
#endif

// Initialize instance and start listening.
// Return value: handle opaque pointer.
IRrecv *mgos_ir_remote_recv_create(int pin) {
	auto *ir = new IRrecv(pin);
	ir->enableIRIn();
	return ir;
}

// Initialize instance and start listening.
// Return value: handle opaque pointer.
IRsend *mgos_ir_remote_send_create(int pin) {
	auto *ir = new IRsend(pin);
	ir->begin();
	return ir;
}

// Close handle. Return value: none.
void mgos_arduino_ir_send_close(IRsend *ir) {
	if (nullptr != ir) {
	    delete ir;
	    ir = nullptr;
  	}
}

// Close handle. Return value: none.
void mgos_arduino_ir_recv_close(IRrecv *ir) {
	if (nullptr != ir) {
	    delete ir;
	    ir = nullptr;
  	}
}

// Recv IR command
std::string mgos_arduino_ir_rec(IRrecv *dt);

// Send IR Command
void mgos_arduino_ir_send(IRsend *dt, int code);

#ifdef __cplusplus
}
#endif

#endif /* _MGOS_ARDUINO_IR_REMOTE_H_ */
