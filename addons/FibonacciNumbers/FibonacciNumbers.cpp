#include <nan.h>

double firstValue__ = 0;
double secondValue__ = 1;

void NextNumber(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  double temp = firstValue__;
  firstValue__ = secondValue__;
  secondValue__ = temp + firstValue__;
  info.GetReturnValue().Set(Nan::New(temp));
}

void Init(v8::Local<v8::Object> exports) {
  v8::Local<v8::Context> context = exports->CreationContext();
  exports->Set(context,
               Nan::New("nextNumber").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(NextNumber)
                   ->GetFunction(context)
                   .ToLocalChecked());
}

NODE_MODULE(nextNumber, Init)