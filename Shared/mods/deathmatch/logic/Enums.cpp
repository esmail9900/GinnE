/*****************************************************************************
 *
 *  PROJECT:     GninE v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        Enums.cpp
 *  PURPOSE:     Client/server shared enum definitions
 *
 *****************************************************************************/

#include "StdInc.h"
#include "Enums.h"

IMPLEMENT_ENUM_BEGIN(EEventPriority::EEventPriorityType)
ADD_ENUM(EEventPriority::LOW, "low")
ADD_ENUM(EEventPriority::NORMAL, "normal")
ADD_ENUM(EEventPriority::HIGH, "high")
IMPLEMENT_ENUM_END("event-priority")

IMPLEMENT_ENUM_BEGIN(EPlayerScreenShotResult::EPlayerScreenShotResultType)
ADD_ENUM(EPlayerScreenShotResult::NONE, "none")
ADD_ENUM(EPlayerScreenShotResult::SUCCESS, "success")
ADD_ENUM(EPlayerScreenShotResult::MINIMIZED, "minimized")
ADD_ENUM(EPlayerScreenShotResult::DISABLED, "disabled")
ADD_ENUM(EPlayerScreenShotResult::ERROR_, "error")
IMPLEMENT_ENUM_END("player-screenshot-result")

IMPLEMENT_ENUM_BEGIN(EDebugHook::EDebugHookType)
ADD_ENUM(EDebugHook::PRE_EVENT, "preEvent")
ADD_ENUM(EDebugHook::POST_EVENT, "postEvent")
ADD_ENUM(EDebugHook::PRE_FUNCTION, "preFunction")
ADD_ENUM(EDebugHook::POST_FUNCTION, "postFunction")
ADD_ENUM(EDebugHook::PRE_EVENT_FUNCTION, "preEventFunction")
ADD_ENUM(EDebugHook::POST_EVENT_FUNCTION, "postEventFunction")
IMPLEMENT_ENUM_END("debug-hook")

IMPLEMENT_ENUM_BEGIN(eEulerRotationOrder)
ADD_ENUM(EULER_DEFAULT, "default")
ADD_ENUM(EULER_ZXY, "ZXY")
ADD_ENUM(EULER_ZYX, "ZYX")
ADD_ENUM(EULER_MINUS_ZYX, "MINUS_ZYX")
IMPLEMENT_ENUM_END("rotation-order")

IMPLEMENT_ENUM_BEGIN(EHashFunction::EHashFunctionType)
ADD_ENUM(EHashFunction::MD5, "md5")
ADD_ENUM(EHashFunction::SHA1, "sha1")
ADD_ENUM(EHashFunction::SHA224, "sha224")
ADD_ENUM(EHashFunction::SHA256, "sha256")
ADD_ENUM(EHashFunction::SHA384, "sha384")
ADD_ENUM(EHashFunction::SHA512, "sha512")
IMPLEMENT_ENUM_END("hash-function")

IMPLEMENT_ENUM_CLASS_BEGIN(HashFunctionType)
ADD_ENUM(HashFunctionType::MD5, "md5")
ADD_ENUM(HashFunctionType::SHA1, "sha1")
ADD_ENUM(HashFunctionType::SHA224, "sha224")
ADD_ENUM(HashFunctionType::SHA256, "sha256")
ADD_ENUM(HashFunctionType::SHA384, "sha384")
ADD_ENUM(HashFunctionType::SHA512, "sha512")
ADD_ENUM(HashFunctionType::HMAC, "hmac")
IMPLEMENT_ENUM_CLASS_END("hash-function")

IMPLEMENT_ENUM_CLASS_BEGIN(PasswordHashFunction)
ADD_ENUM(PasswordHashFunction::Bcrypt, "bcrypt")
IMPLEMENT_ENUM_CLASS_END("password-hash-function")

IMPLEMENT_ENUM_CLASS_BEGIN(StringEncodeFunction)
ADD_ENUM(StringEncodeFunction::TEA, "tea")
ADD_ENUM(StringEncodeFunction::AES128, "aes128")
ADD_ENUM(StringEncodeFunction::RSA, "rsa")
IMPLEMENT_ENUM_CLASS_END("string-encode-function")

IMPLEMENT_ENUM_CLASS_BEGIN(KeyPairAlgorithm)
ADD_ENUM(KeyPairAlgorithm::RSA, "rsa")
IMPLEMENT_ENUM_CLASS_END("key-pair-algorithm")

IMPLEMENT_ENUM_CLASS_BEGIN(HmacAlgorithm)
ADD_ENUM(HmacAlgorithm::MD5, "md5")
ADD_ENUM(HmacAlgorithm::SHA1, "sha1")
ADD_ENUM(HmacAlgorithm::SHA224, "sha224")
ADD_ENUM(HmacAlgorithm::SHA256, "sha256")
ADD_ENUM(HmacAlgorithm::SHA384, "sha384")
ADD_ENUM(HmacAlgorithm::SHA512, "sha512")
IMPLEMENT_ENUM_CLASS_END("hmac-algorithm")

IMPLEMENT_ENUM_CLASS_BEGIN(WorldSpecialProperty)
ADD_ENUM(WorldSpecialProperty::HOVERCARS, "hovercars")
ADD_ENUM(WorldSpecialProperty::AIRCARS, "aircars")
ADD_ENUM(WorldSpecialProperty::EXTRABUNNY, "extrabunny")
ADD_ENUM(WorldSpecialProperty::EXTRAJUMP, "extrajump")
ADD_ENUM(WorldSpecialProperty::RANDOMFOLIAGE, "randomfoliage")
ADD_ENUM(WorldSpecialProperty::SNIPERMOON, "snipermoon")
ADD_ENUM(WorldSpecialProperty::EXTRAAIRRESISTANCE, "extraairresistance")
ADD_ENUM(WorldSpecialProperty::UNDERWORLDWARP, "underworldwarp")
ADD_ENUM(WorldSpecialProperty::VEHICLESUNGLARE, "vehiclesunglare")
ADD_ENUM(WorldSpecialProperty::CORONAZTEST, "coronaztest")
ADD_ENUM(WorldSpecialProperty::WATERCREATURES, "watercreatures")
ADD_ENUM(WorldSpecialProperty::BURNFLIPPEDCARS, "burnflippedcars")
ADD_ENUM(WorldSpecialProperty::FIREBALLDESTRUCT, "fireballdestruct")
IMPLEMENT_ENUM_CLASS_END("world-special-property")

IMPLEMENT_ENUM_BEGIN(ePacketID)
ADD_ENUM1(PACKET_ID_SERVER_JOIN)
ADD_ENUM1(PACKET_ID_SERVER_JOIN_DATA)
ADD_ENUM1(PACKET_ID_SERVER_JOIN_COMPLETE)
ADD_ENUM1(PACKET_ID_PLAYER_JOIN)
ADD_ENUM1(PACKET_ID_PLAYER_JOINDATA)
ADD_ENUM1(PACKET_ID_PLAYER_QUIT)
ADD_ENUM1(PACKET_ID_PLAYER_TIMEOUT)
ADD_ENUM1(PACKET_ID_MOD_NAME)
ADD_ENUM1(PACKET_ID_PACKET_PROGRESS)
ADD_ENUM1(PACKET_ID_GninE_RESERVED_03)
ADD_ENUM1(PACKET_ID_GninE_RESERVED_04)
ADD_ENUM1(PACKET_ID_GninE_RESERVED_05)
ADD_ENUM1(PACKET_ID_GninE_RESERVED_06)
ADD_ENUM1(PACKET_ID_GninE_RESERVED_07)
ADD_ENUM1(PACKET_ID_GninE_RESERVED_08)
ADD_ENUM1(PACKET_ID_GninE_RESERVED_09)
ADD_ENUM1(PACKET_ID_GninE_RESERVED_10)
ADD_ENUM1(PACKET_ID_GninE_RESERVED_11)
ADD_ENUM1(PACKET_ID_GninE_RESERVED_12)
ADD_ENUM1(PACKET_ID_GninE_RESERVED_13)
ADD_ENUM1(PACKET_ID_GninE_RESERVED_14)
ADD_ENUM1(PACKET_ID_GninE_RESERVED_15)
ADD_ENUM1(PACKET_ID_SERVER_JOINEDGAME)
ADD_ENUM1(PACKET_ID_SERVER_DISCONNECTED)
ADD_ENUM1(PACKET_ID_RPC)
ADD_ENUM1(PACKET_ID_PLAYER_LIST)
ADD_ENUM1(PACKET_ID_PLAYER_SPAWN)
ADD_ENUM1(PACKET_ID_PLAYER_WASTED)
ADD_ENUM1(PACKET_ID_PLAYER_CHANGE_NICK)
ADD_ENUM1(PACKET_ID_PLAYER_STATS)
ADD_ENUM1(PACKET_ID_PLAYER_CLOTHES)
ADD_ENUM1(PACKET_ID_PLAYER_KEYSYNC)
ADD_ENUM1(PACKET_ID_PLAYER_PURESYNC)
ADD_ENUM1(PACKET_ID_PLAYER_VEHICLE_PURESYNC)
ADD_ENUM1(PACKET_ID_LIGHTSYNC)
ADD_ENUM1(PACKET_ID_VEHICLE_RESYNC)
ADD_ENUM1(PACKET_ID_RETURN_SYNC)
ADD_ENUM1(PACKET_ID_EXPLOSION)
ADD_ENUM1(PACKET_ID_FIRE)
ADD_ENUM1(PACKET_ID_PROJECTILE)
ADD_ENUM1(PACKET_ID_DETONATE_SATCHELS)
ADD_ENUM1(PACKET_ID_DESTROY_SATCHELS)
ADD_ENUM1(PACKET_ID_COMMAND)
ADD_ENUM1(PACKET_ID_CHAT_ECHO)
ADD_ENUM1(PACKET_ID_CONSOLE_ECHO)
ADD_ENUM1(PACKET_ID_DEBUG_ECHO)
ADD_ENUM1(PACKET_ID_MAP_INFO)
ADD_ENUM1(PACKET_ID_MAP_START)
ADD_ENUM1(PACKET_ID_MAP_RESTART)
ADD_ENUM1(PACKET_ID_MAP_STOP)
ADD_ENUM1(PACKET_ID_ENTITY_ADD)
ADD_ENUM1(PACKET_ID_ENTITY_REMOVE)
ADD_ENUM1(PACKET_ID_PICKUP_HIDESHOW)
ADD_ENUM1(PACKET_ID_PICKUP_HIT_CONFIRM)
ADD_ENUM1(PACKET_ID_UNOCCUPIED_VEHICLE_STARTSYNC)
ADD_ENUM1(PACKET_ID_UNOCCUPIED_VEHICLE_STOPSYNC)
ADD_ENUM1(PACKET_ID_UNOCCUPIED_VEHICLE_SYNC)
ADD_ENUM1(PACKET_ID_VEHICLE_SPAWN)
ADD_ENUM1(PACKET_ID_VEHICLE_INOUT)
ADD_ENUM(PACKET_ID_VEHICLE_DAMAGE_SYNC, "PACKET_ID_VEHICLE_PARTS_STATE_SYNC")
ADD_ENUM1(PACKET_ID_VEHICLE_TRAILER)
ADD_ENUM1(PACKET_ID_PED_STARTSYNC)
ADD_ENUM1(PACKET_ID_PED_STOPSYNC)
ADD_ENUM1(PACKET_ID_PED_SYNC)
ADD_ENUM1(PACKET_ID_PED_WASTED)
ADD_ENUM1(PACKET_ID_PLAYER_RCON)
ADD_ENUM1(PACKET_ID_PLAYER_RCON_LOGIN)
ADD_ENUM1(PACKET_ID_PLAYER_RCON_KICK)
ADD_ENUM1(PACKET_ID_PLAYER_RCON_BAN)
ADD_ENUM1(PACKET_ID_PLAYER_RCON_MUTE)
ADD_ENUM1(PACKET_ID_PLAYER_RCON_FREEZE)
ADD_ENUM1(PACKET_ID_VOICE_DATA)
ADD_ENUM1(PACKET_ID_VOICE_END)
ADD_ENUM1(PACKET_ID_CHEAT_CHALLENGEMEMORY)
ADD_ENUM1(PACKET_ID_CHEAT_RETURN)
ADD_ENUM1(PACKET_ID_MAP_LIST)
ADD_ENUM1(PACKET_ID_LUA)
ADD_ENUM1(PACKET_ID_LUA_ELEMENT_RPC)
ADD_ENUM1(PACKET_ID_TEXT_ITEM)
ADD_ENUM1(PACKET_ID_SCOREBOARD)
ADD_ENUM1(PACKET_ID_TEAMS)
ADD_ENUM1(PACKET_ID_LUA_EVENT)
ADD_ENUM1(PACKET_ID_RESOURCE_START)
ADD_ENUM1(PACKET_ID_RESOURCE_STOP)
ADD_ENUM1(PACKET_ID_CUSTOM_DATA)
ADD_ENUM1(PACKET_ID_CAMERA_SYNC)
ADD_ENUM1(PACKET_ID_OBJECT_STARTSYNC)
ADD_ENUM1(PACKET_ID_OBJECT_STOPSYNC)
ADD_ENUM1(PACKET_ID_OBJECT_SYNC)
ADD_ENUM1(PACKET_ID_UPDATE_INFO)
ADD_ENUM1(PACKET_ID_DISCONNECT_MESSAGE)
ADD_ENUM1(PACKET_ID_PLAYER_TRANSGRESSION)
ADD_ENUM1(PACKET_ID_PLAYER_DIAGNOSTIC)
ADD_ENUM1(PACKET_ID_PLAYER_MODINFO)
ADD_ENUM1(PACKET_ID_PLAYER_SCREENSHOT)
ADD_ENUM1(PACKET_ID_RESOURCE_CLIENT_SCRIPTS)
ADD_ENUM1(PACKET_ID_LATENT_TRANSFER)
ADD_ENUM1(PACKET_ID_VEHICLE_PUSH_SYNC)
ADD_ENUM1(PACKET_ID_PLAYER_BULLETSYNC)
ADD_ENUM1(PACKET_ID_SYNC_SETTINGS)
ADD_ENUM1(PACKET_ID_WEAPON_BULLETSYNC)
ADD_ENUM1(PACKET_ID_PED_TASK)
ADD_ENUM1(PACKET_ID_PLAYER_NO_SOCKET)
ADD_ENUM1(PACKET_ID_PLAYER_NETWORK_STATUS)
ADD_ENUM1(PACKET_ID_PLAYER_ACINFO)
ADD_ENUM1(PACKET_ID_CHAT_CLEAR)
ADD_ENUM1(PACKET_ID_SERVER_INFO_SYNC)
ADD_ENUM1(PACKET_ID_DISCORD_JOIN)
ADD_ENUM1(PACKET_ID_PLAYER_RESOURCE_START)
IMPLEMENT_ENUM_END("ePacketID")
