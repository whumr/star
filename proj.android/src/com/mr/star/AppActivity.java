/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package com.mr.star;

import net.youmi.android.AdManager;
import net.youmi.android.spot.SpotManager;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.os.Bundle;

public class AppActivity extends Cocos2dxActivity {
	
private static AppActivity app;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		app = this;
		AdManager.getInstance(this).init("b3c66b7e68fb6936", "786e45158c462542", false);  
	}
	
	public static Object getActivity(){
		return app;
	}
	
	public void loadAds(){  
	    System.out.println("load ads");  
	    SpotManager.getInstance(this).loadSpotAds();  
	    //设置展示超时时间，加载超时则不展示广告，默认0，代表不设置超时时间   
        SpotManager.getInstance(this).setSpotTimeout(10000);
        //展示间隔
        SpotManager.getInstance(this).setShowInterval(60);  
        SpotManager.getInstance(this).setSpotOrientation(SpotManager.ORIENTATION_PORTRAIT);
	}  
	
	public void showAds(){  
	    System.out.println("show ads");  
	    SpotManager.getInstance(this).showSpotAds(this);  
	}  
	  
	public boolean dismissads(){  
	    return SpotManager.getInstance(this).disMiss(true);  
	}  
	
	@Override  
	protected void onStop(){  
	    SpotManager.getInstance(this).disMiss(true);  
	    super.onStop();   
	}  
	
	@Override
	protected void onDestroy() {
		SpotManager.getInstance(this).unregisterSceenReceiver();
		super.onDestroy();
	}
}
