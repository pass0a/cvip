#include "cvip.h"

Value _cvipMatch(const Napi::CallbackInfo& info) {
    auto env = info.Env();
    auto obj = Napi::Object::New(env);
    stPos pos;
    if (info[0].IsString() && info[1].IsString()) {
        pos = cvipMatch(info[0].ToString().Utf8Value(), info[1].ToString().Utf8Value());
        obj.Set("valid", pos.status);
        obj.Set("x", pos.x);
        obj.Set("y", pos.y);
        obj.Set("val", pos.val);
    }
    return obj;
}
Value _cvipEncode(const Napi::CallbackInfo& info) {
    auto env = info.Env();
    int ret = -2;
    if (info[0].IsString() && info[1].IsString() && info[2].IsNumber()) {
        ret = cvipEncode(info[0].ToString().Utf8Value(), info[1].ToString().Utf8Value(), info[2].ToNumber().Int32Value());
    }
    return Napi::Number::New(env, ret);
}
Value _cvipCut(const Napi::CallbackInfo& info) {
    auto env = info.Env();
    int ret = -2;
    if (info[0].IsString() && info[1].IsString() && info[2].IsNumber() && info[3].IsNumber() && info[4].IsNumber() && info[5].IsNumber() && info[6].IsNumber()) {
        ret = cvipCut(info[0].ToString().Utf8Value(), info[1].ToString().Utf8Value(), info[2].ToNumber().Int32Value(), info[3].ToNumber().Int32Value(), info[4].ToNumber().Int32Value(), info[5].ToNumber().Int32Value(), info[6].ToNumber().Int32Value());
    }
    return Napi::Number::New(env, ret);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "cvipMatch"),
        Napi::Function::New(env, _cvipMatch));
    exports.Set(Napi::String::New(env, "cvipEncode"),
        Napi::Function::New(env, _cvipEncode));
    exports.Set(Napi::String::New(env, "cvipCut"),
        Napi::Function::New(env, _cvipCut));
    exports.Set(Napi::String::New(env, "cameraCount"),
        Napi::Function::New(env, _cvipCameraCount));
    exports.Set(Napi::String::New(env, "cameraOpen"),
        Napi::Function::New(env, _cvipCameraOpen));
    exports.Set(Napi::String::New(env, "cameraClose"),
        Napi::Function::New(env, _cvipCameraClose));
    exports.Set(Napi::String::New(env, "cameraIsOpened"),
        Napi::Function::New(env, _cvipCamereIsOpened));
    exports.Set(Napi::String::New(env, "cameraRead"),
        Napi::Function::New(env, _cvipCamereRead));
    exports.Set(Napi::String::New(env, "cameraTake"),
        Napi::Function::New(env, _cvipCamereTake));
    exports.Set(Napi::String::New(env, "cameraRecord"),
        Napi::Function::New(env, _cvipCamereRecord));
    return exports;
}

NODE_API_MODULE(cvip, Init)