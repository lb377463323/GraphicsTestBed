package com.lb6905.jnidemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private TextView mTextView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mTextView = (TextView) findViewById(R.id.tv_jni);
        int[] arr = getArray();
        mTextView.setText(stringFromJNI());
        JNIReflect();
    }

    public native String stringFromJNI();
    public native void setArray(int[] array);
    public native int[] getArray();
    public native void JNIReflect();

    static {
        System.loadLibrary("hello-jni");
    }
}
