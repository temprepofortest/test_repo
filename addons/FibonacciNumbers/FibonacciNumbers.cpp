#include <nan.h>

double firstValue = 0;
double secondValue = 1;

void NextNumber(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  double temp = firstValue;
  firstValue = secondValue;
  secondValue = temp + firstValue;
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
