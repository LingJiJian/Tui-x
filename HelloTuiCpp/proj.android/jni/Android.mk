LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
$(call import-add-path,$(LOCAL_PATH)/../..)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
../../../CocosBase/CCBundle.cpp\
../../../CocosBase/CCMsgDelegate.cpp\
../../../CocosBase/CCMsgManager.cpp\
../../../CocosBase/CCSceneExTransition.cpp\
../../../CocosBase/CCSceneExtension.cpp\
../../../CocosBase/CCSceneManager.cpp\
../../../CocosNet/CCBuffer.cpp\
../../../CocosNet/CCInetAddress.cpp\
../../../CocosNet/CCNetDelegate.cpp\
../../../CocosNet/CCSocket.cpp\
../../../CocosWidget/ArmatureBtn.cpp\
../../../CocosWidget/Button.cpp\
../../../CocosWidget/CEditBox/CEditBox.cpp\
../../../CocosWidget/CEditBox/CEditBoxImplNone.cpp\
../../../CocosWidget/CEditBox/CEditBoxImplAndroid.cpp\
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
../../../CocosWidget/MapView.cpp\
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
../../../dragonbones/animation/Animation.cpp\
../../../dragonbones/animation/AnimationState.cpp\
../../../dragonbones/animation/TimelineState.cpp\
../../../dragonbones/animation/WorldClock.cpp\
../../../dragonbones/core/Armature.cpp\
../../../dragonbones/core/Bone.cpp\
../../../dragonbones/core/Object.cpp\
../../../dragonbones/core/Slot.cpp\
../../../dragonbones/events/EventData.cpp\
../../../dragonbones/factories/BaseFactory.cpp\
../../../dragonbones/parsers/BaseDataParser.cpp\
../../../dragonbones/parsers/ConstValues.cpp\
../../../dragonbones/parsers/XMLDataParser.cpp\
../../../dragonbones/parsers/dbtinyxml2.cpp\
../../../dragonbones/renderer/cocos2d-x-3.2/DBCCArmature.cpp\
../../../dragonbones/renderer/cocos2d-x-3.2/DBCCArmatureNode.cpp\
../../../dragonbones/renderer/cocos2d-x-3.2/DBCCFactory.cpp\
../../../dragonbones/renderer/cocos2d-x-3.2/DBCCSlot.cpp\
../../Classes/AppDelegate.cpp\
../../Classes/module/ResoureMgr.cpp\
../../Classes/scene/Bag/Bagui.cpp\
../../Classes/scene/Guide/Guideui.cpp\
../../Classes/scene/Main/Mainui.cpp\
../../Classes/scene/Main/dialog/MsgBox.cpp\
../../Classes/scene/Map/Mapui.cpp\
../../Classes/scene/Recombine/Recombineui.cpp\
../../Classes/scene/ShowPhone/ShowPhoneui.cpp\
../../Classes/scene/Store/Storeui.cpp\
../../Classes/scene/Welcome/Welcomeui.cpp\
../../Classes/tui/TuiBase.cpp\
../../Classes/tui/TuiManager.cpp\
../../Classes/tui/TuiUtil.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../..
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../CocosNet
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../CocosWidget
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../CocosWidget/CEditBox
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../dragonbones
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../dragonbones/animation
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../dragonbones/core
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../dragonbones/events
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../dragonbones/factories
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../dragonbones/geoms
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../dragonbones/objects
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../dragonbones/parsers
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../dragonbones/renderer/cocos2d-x-3.2
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../dragonbones/textures
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../rapidXml
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/module
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/Bag
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/Guide
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/Main
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/Main/dialog
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/Map
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/Recombine
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/ShowPhone
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/Store
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/scene/Welcome
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/tui
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/tui/tagMap

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
