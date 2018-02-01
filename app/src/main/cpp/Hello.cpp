//
// Created by 苏虎 on 2018/1/31.
//

#include "com_ndk_dome_Hello.h"
JNIEXPORT jstring JNICALL Java_com_ndk_dome_Hello_getString(JNIEnv * env, jclass jclass1){
    jstring str = env->NewStringUTF("from jni");
    return str;
}



/**
 *c++代码调用java 静态方法，修改静态成员变量
 *
 * @return String
 */
JNIEXPORT jstring JNICALL Java_com_ndk_dome_Hello_jniShowLog(JNIEnv *env, jclass jclass1, jstring jstring1){
    jclass class_hello = env->FindClass("com/ndk/dome/Hello");
    if (class_hello==NULL){
        return NULL;
    }
    jmethodID method_id = env->GetStaticMethodID(class_hello,"showLog","(Ljava/lang/String;)V");
    if (method_id==NULL){
        return NULL;
    }
    //打印
    env->CallStaticVoidMethod(class_hello,method_id,jstring1);
    //获取成员变量
    jfieldID field_id = env->GetStaticFieldID(class_hello,"name","Ljava/lang/String;");
    if (field_id==NULL){
        return NULL;
    }

    jstring name_str = env->NewStringUTF("tome");

    //修改成员变量
    env->SetStaticObjectField(class_hello,field_id,name_str);

    //获取成员变量的值
    jobject name = env->GetStaticObjectField(class_hello,field_id);
    if(name==NULL){
        return NULL;
    }
    //打印成员变量
    env->CallStaticVoidMethod(class_hello,method_id,name);

    jstring str = env->NewStringUTF("打印LOG日志后返回字符串");
    env->DeleteLocalRef(class_hello);
    env->DeleteLocalRef(name_str);
    env->DeleteLocalRef(name);
    return str;


}


/**
 *
 * 调用非静态方法
 *
 *
 */
JNIEXPORT void JNICALL Java_com_ndk_dome_Hello_fun(JNIEnv * env, jclass jclass1){
    //获得class对象
    jclass hello_class = env->FindClass("com/ndk/dome/Hello");
    if (hello_class==NULL){
        return;
    }
    //获得构造函数的methodID
    jmethodID const_method = env->GetMethodID(hello_class,"<init>","()V");
    if (const_method==NULL) return;

    //获得类的对象
    jobject hello_obj = env->NewObject(hello_class,const_method);
    if (hello_obj==NULL)return;


    //获得成员函数id
    jmethodID method_id = env->GetMethodID(hello_class,"logMessage","(Ljava/lang/String;)V");
    if (method_id==NULL)return;

    //获得成员变量id
    jfieldID file_id = env->GetFieldID(hello_class,"message","Ljava/lang/String;");
    if (file_id==NULL)return;

    //获得成员变量的值
    jobject message = env->GetObjectField(hello_obj,file_id);

    //调用成员函数,打印值
    env->CallVoidMethod(hello_obj,method_id,message);


    //创建字符串对成员变量赋值
    jstring str = env->NewStringUTF("海纳百川，有容乃大");
    env->SetObjectField(hello_obj,file_id,str);


    //再次获得更还后的值
    jobject message_after = env->GetObjectField(hello_obj,file_id);
    env->CallVoidMethod(hello_obj,method_id,message_after);

    env->DeleteLocalRef(hello_class);
    env->DeleteLocalRef(hello_obj);
    env->DeleteLocalRef(message_after);
    env->DeleteLocalRef(message);
    env->DeleteLocalRef(str);




}


















