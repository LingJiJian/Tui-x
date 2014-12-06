LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
../../../CocosBase/CCBundle.cpp\
../../../CocosBase/CCMsgDelegate.cpp\
../../../CocosBase/CCMsgManager.cpp\
../../../CocosBase/CCSceneExTransition.cpp\
../../../CocosBase/CCSceneExtension.cpp\
../../../CocosBase/CCSceneManager.cpp\
../../../CocosWidget/ArmatureBtn.cpp\
../../../CocosWidget/Button.cpp\
../../../CocosWidget/CheckBox.cpp\
../../../CocosWidget/CircleMenu.cpp\
../../../CocosWidget/ColorView.cpp\
../../../CocosWidget/ControlView.cpp\
../../../CocosWidget/ExpandableListView.cpp\
../../../CocosWidget/GradientView.cpp\
../../../CocosWidget/GridPageView.cpp\
../../../CocosWidget/GridView.cpp\
../../../CocosWidget/ImageView.cpp\
../../../CocosWidget/ImageViewScale9.cpp\
../../../CocosWidget/Label.cpp\
../../../CocosWidget/LabelAtlas.cpp\
../../../CocosWidget/LabelBMFont.cpp\
../../../CocosWidget/Layout.cpp\
../../../CocosWidget/ListView.cpp\
../../../CocosWidget/NumericStepper.cpp\
../../../CocosWidget/PageView.cpp\
../../../CocosWidget/ProgressBar.cpp\
../../../CocosWidget/Scale9Sprite.cpp\
../../../CocosWidget/ScrollView.cpp\
../../../CocosWidget/Slider.cpp\
../../../CocosWidget/TableView.cpp\
../../../CocosWidget/TextRich.cpp\
../../../CocosWidget/ToggleView.cpp\
../../../CocosWidget/Widget.cpp\
../../../CocosWidget/WidgetProtocol.cpp\
../../../CocosWidget/WidgetWindow.cpp\
../../../CocosWidget/WitlsMacros.cpp\
../../Classes/AppDelegate.cpp\
../../Classes/module/ResoureMgr.cpp\
../../Classes/scene/Bag/Bagui.cpp\
../../Classes/scene/Main/Mainui.cpp\
../../Classes/scene/Main/dialog/MsgBox.cpp\
../../Classes/scene/Recombine/Recombineui.cpp\
../../Classes/scene/ShowPhone/ShowPhoneui.cpp\
../../Classes/scene/Store/Storeui.cpp\
../../Classes/scene/Welcome/Welcomeui.cpp\
../../Classes/tui/TuiBase.cpp\
../../Classes/tui/TuiManager.cpp\
../../Classes/tui/TuiUtil.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../CocosWidget
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../rapidXml
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/module
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/Bag
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/Main
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/Main/dialog
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/ShowPhone
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/Store
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/Welcome
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/tui
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/tui/tagMap
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/tui/utils
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos2d/cocos/base
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos2d/cocos/2d
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos2d/cocos/editor-support
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos2d/extensions
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos2d/external


LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static 
LOCAL_WHOLE_STATIC_LIBRARIES += cocostudio_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-module,audio/android)
$(call import-module,extensions)				
$(call import-module,editor-support/cocostudio)	