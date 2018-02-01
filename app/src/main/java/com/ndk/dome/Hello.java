package com.ndk.dome;

import android.util.Log;

/**
 * @author: 苏虎
 * @email: suhu0824@gmail.com
 * @data: 2018/1/31 16:20
 * @description:
 */

public class Hello {
    private static String name="suhu";
    private String message = "车到山前必有路";

    static {
        System.loadLibrary("Hello");
    }

    public static native String getString();

    public static void showLog(String str){
        Log.i("JNI_静态",str);
    }

    public static native String jniShowLog(String str);

    public void logMessage(String str){
        Log.i("JNI_非静态",str);
    }


    public static native void fun();

}
