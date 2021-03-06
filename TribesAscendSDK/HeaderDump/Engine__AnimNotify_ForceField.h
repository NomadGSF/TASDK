#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNotify_ForceField." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNotify_ForceField." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNotify_ForceField." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNotify_ForceField : public AnimNotify
	{
	public:
			ADD_VAR( ::NameProperty, SocketName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BoneName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAttach, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
