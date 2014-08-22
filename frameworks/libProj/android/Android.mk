LOCAL_PATH := $(call my-dir)/../../CocosLua
include $(CLEAR_VARS)

LOCAL_MODULE    := CocosLua_static

MY_CPP_LIST := $(wildcard $(LOCAL_PATH)/*.cpp)
MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/utils/*.cpp)
MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/utils/base64/*.cpp)
MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/utils/encrypt/*.cpp)

MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/sqlite/libsqlite/*.c)
MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/sqlite/*.cpp)

MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/scene/*.cpp)

MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/net/*.cpp)
MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/net/utils/*.cpp)

MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/json/*.cpp)
MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/json/libjson/Source/*.cpp)
MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/json/samples/*.cpp)

MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/lua-bindings/*.cpp)


LOCAL_SRC_FILES := $(filter-out ,$(MY_CPP_LIST))

LOCAL_C_INCLUDES := $(LOCAL_PATH)

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)

LOCAL_STATIC_LIBRARIES := cocos2dx_static
LOCAL_STATIC_LIBRARIES += cocos_curl_static
LOCAL_STATIC_LIBRARIES += cocos_lua_static

       
include $(BUILD_STATIC_LIBRARY)

$(call import-module,scripting/lua-bindings)

