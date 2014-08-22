LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dlua_shared

LOCAL_MODULE_FILENAME := libcocos2dlua

LOCAL_SRC_FILES :=  \
../../Classes/AppDelegate.cpp \
../../Classes/net/service/http/HttpService.cpp \
../../Classes/net/service/socket/SocketService.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes/const
					
LOCAL_STATIC_LIBRARIES := curl_static_prebuilt
LOCAL_STATIC_LIBRARIES := CocosLua_static
LOCAL_STATIC_LIBRARIES += cocos_network_static

LOCAL_WHOLE_STATIC_LIBRARIES := cocos_lua_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,../libProj/android)
