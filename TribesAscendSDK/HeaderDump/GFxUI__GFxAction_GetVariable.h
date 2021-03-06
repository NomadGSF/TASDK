#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GFxUI.GFxAction_GetVariable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GFxUI.GFxAction_GetVariable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GFxUI.GFxAction_GetVariable." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxAction_GetVariable : public SequenceAction
	{
	public:
			ADD_VAR( ::StrProperty, Variable, 0xFFFFFFFF )
			ADD_OBJECT( GFxMoviePlayer, Movie )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
