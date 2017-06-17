let IR = {

  _newRecv: ffi('void *mgos_ir_remote_recv_create(int)'),
  _newSend: ffi('void *mgos_ir_remote_send_create(int)'),
  _send:    ffi('void mgos_arduino_ir_send(void *, int)'),
  _close:   ffi('void mgos_arduino_ir_send_close(void *)'),
  _recv:    ffi('char* mgos_arduino_ir_rec(void*)'),
  _proto: {
    send: function(data) {
      IR._send(this.ir, data);
    }
  },
  _new: function(pin, send) {
    let obj = Object.create(_proto);
    obj.ir = send ? _newSend(pin) : _newRecv(pin);
    return obj;
  },
  new_sender: function(pin) {
    return _new(pin, true);
  },
  new_receiver: function(pin) {
    return _new(pin, false);
  },

}
