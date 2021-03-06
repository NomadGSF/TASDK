#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimationCompressionAlgorithm_RemoveEverySecondKey." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimationCompressionAlgorithm_RemoveEverySecondKey." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimationCompressionAlgorithm_RemoveEverySecondKey." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimationCompressionAlgorithm_RemoveEverySecondKey : public AnimationCompressionAlgorithm
	{
	public:
			ADD_VAR( ::BoolProperty, bStartAtSecondKey, 0x1 )
			ADD_VAR( ::IntProperty, MinKeys, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
