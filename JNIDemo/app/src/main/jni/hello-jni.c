//
// Created by lb6905 on 2017/6/21.
//
#include <jni.h>
#include <string.h>

#ifndef _Included_com_lb6905_jnidemo_MainActivity
#define _Included_com_lb6905_jnidemo_MainActivity

int lutData[5] = {0,10,12,3,4};

jstring
Java_com_lb6905_jnidemo_MainActivity_stringFromJNI( JNIEnv* env,
                                                  jobject thiz )
{
    return (*env)->NewStringUTF(env, "Hello from JNI !");
}

/*
 * Class:     com_lb6905_jnidemo_MainActivity
 * Method:    setArray
 * Signature: ([I)V
 */
JNIEXPORT void JNICALL Java_com_lb6905_jnidemo_MainActivity_setArray
  (JNIEnv *env, jobject thiz, jintArray array)
  {

  }

/*
 * Class:     com_lb6905_jnidemo_MainActivity
 * Method:    getArray
 * Signature: ()[I
 */
JNIEXPORT jintArray JNICALL Java_com_lb6905_jnidemo_MainActivity_getArray
  (JNIEnv *env, jobject thiz)
  {
    jintArray array = (*env)->NewIntArray(env, 5);
    (*env)->SetIntArrayRegion(env, array, 0, 5, lutData);
    return array;
  }

  JNIEXPORT void JNICALL Java_com_lb6905_jnidemo_MainActivity_JNIReflect
    (JNIEnv *env, jobject thiz)
    {
        //实例化Test类
        jclass testclass = (*env)->FindClass(env, "com/lb6905/jnidemo/TestClass");
        jmethodID testcontruct = (*env)->GetMethodID(env, testclass, "<init>", "()V");
        jobject testobject = (*env)->NewObject(env, testclass, testcontruct);

        //调用成员方法
        jmethodID test = (*env)->GetMethodID(env, testclass, "test", "(I)V");
        (*env)->CallVoidMethod(env, testobject, test, 1);

        //调用静态方法
        jmethodID testStatic = (*env)->GetStaticMethodID(env, testclass, "testStatic", "(Ljava/lang/String;)V");
        jstring str = (*env)->NewStringUTF(env, "hello world!");
        (*env)->CallStaticVoidMethod(env, testclass, testStatic, str);

        //实例化InnerClass子类
        jclass innerclass = (*env)->FindClass(env, "com/lb6905/jnidemo/TestClass$InnerClass");
        jmethodID innercontruct = (*env)->GetMethodID(env, innerclass, "<init>", "()V");
        jobject innerobject = (*env)->NewObject(env, innerclass, innercontruct);

        jmethodID setInt = (*env)->GetMethodID(env, innerclass, "setInt", "(I)V");
        (*env)->CallVoidMethod(env, innerobject, setInt, 2);
    }
  #endif