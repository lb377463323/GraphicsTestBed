package com.liubing.filtertestbed.CameraV2GLSurfaceView;

import android.app.Activity;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.util.DisplayMetrics;

import com.liubing.filtertestbed.CameraV2;

/**
 * Created by lb6905 on 2017/7/19.
 */

public class CameraV2GLSurfaceViewActivity extends Activity {
    private CameraV2GLSurfaceView mCameraV2GLSurfaceView;
    private CameraV2 mCamera;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        mCameraV2GLSurfaceView = new CameraV2GLSurfaceView(this);
        DisplayMetrics dm = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(dm);
        mCamera = new CameraV2(this);
        mCamera.setupCamera(dm.widthPixels, dm.heightPixels);
        if (!mCamera.openCamera()) {
            return;
        }
        mCameraV2GLSurfaceView.init(mCamera, false, CameraV2GLSurfaceViewActivity.this);
        setContentView(mCameraV2GLSurfaceView);
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
    }
}
