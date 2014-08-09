//
//  framework.h
//  Framework
//
//  Created by wp_g4 on 13-7-15.
//
//

#ifndef Framework_framework_h
#define Framework_framework_h

#define FrameworkVersion 0.10

#include "json/JSONElement.h"

#include "net/NetCenter.h"
#include "net/NetFilter.h"
#include "net/NetHandler.h"
#include "net/NetProtocol.h"
#include "net/NetRequest.h"
#include "net/NetResponse.h"
#include "net/NetService.h"

//#include "net/utils/Socket.h"
#include "net/utils/HttpForm.h"
#include "net/utils/HttpDownloader.h"

#include "notification/notification.h"

#include "scene/GameScene.h"
#include "scene/ViewController.h"
#include "scene/UIManager.h"
#include "scene/SceneManager.h"

#include "sqlite/SQLite.h"

#include "utils/base64/Base64Util.h"

#include "utils/encrypt/DESUtil.h"
#include "utils/encrypt/DBDecryptUtil.h"
#include "utils/encrypt/FileDecryptUtil.h"

#include "utils/FileManager.h"
#include "utils/LuaUtil.h"
#include "utils/md5.h"

#include "utils/NetStatus/NetStatusUtil.h"

//#include "utils/RegexUtil.h"
#include "utils/ResourceManager.h"

#include "utils/uuid/UUIDGenerator.h"

#include "Game.h"

#endif
