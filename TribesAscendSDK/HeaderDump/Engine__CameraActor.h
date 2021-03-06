#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.CameraActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.CameraActor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.CameraActor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class CameraActor : public Actor
	{
	public:
			ADD_VAR( ::BoolProperty, bConstrainAspectRatio, 0x1 )
			ADD_VAR( ::FloatProperty, AspectRatio, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CamOverridePostProcessAlpha, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FOVAngle, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCamOverridePostProcess, 0x2 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
