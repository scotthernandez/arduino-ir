#include "mgos_arduino_ir_remote.h"
#include <string>
// Recv IR command
std::string mgos_arduino_ir_rec(IRrecv *ir) {
	if(!ir) {
		return "";
	}
	return "";
}

// Send IR Command
void mgos_arduino_ir_send(IRsend *ir, int code) {
	if(!ir) {
		return;
	}

	if (code > 0) {
		return;
	}

}
