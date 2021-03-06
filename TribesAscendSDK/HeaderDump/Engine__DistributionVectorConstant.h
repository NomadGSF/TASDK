#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.DistributionVectorConstant." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.DistributionVectorConstant." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.DistributionVectorConstant." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DistributionVectorConstant : public DistributionVector
	{
	public:
			ADD_VAR( ::ByteProperty, LockedAxes, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bLockAxes, 0x1 )
			ADD_STRUCT( ::VectorProperty, Constant, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
