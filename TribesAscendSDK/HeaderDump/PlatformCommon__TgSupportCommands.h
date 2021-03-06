#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " PlatformCommon.TgSupportCommands." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty PlatformCommon.TgSupportCommands." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty PlatformCommon.TgSupportCommands." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TgSupportCommands : public Object
	{
	public:
			ADD_OBJECT( WorldInfo, WorldInfo )
			ADD_OBJECT( PlayerController, PC )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
