#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_ndk_dome_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
JNIEXPORT jstring JNICALL Java_com_ndk_dome_MainActivity_getString(JNIEnv * env, jclass jclass1){
    jstring str = env->NewStringUTF("from jni");
    return str;
}