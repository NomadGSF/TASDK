#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.MaterialExpressionScreenPosition." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.MaterialExpressionScreenPosition." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.MaterialExpressionScreenPosition." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MaterialExpressionScreenPosition : public MaterialExpression
	{
	public:
			ADD_VAR( ::BoolProperty, ScreenAlign, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
