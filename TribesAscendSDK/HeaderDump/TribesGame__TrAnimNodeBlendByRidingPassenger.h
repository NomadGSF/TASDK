#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrAnimNodeBlendByRidingPassenger." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrAnimNodeBlendByRidingPassenger." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrAnimNodeBlendByRidingPassenger." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAnimNodeBlendByRidingPassenger : public TrAnimNodeBlendList
	{
	public:
			ADD_OBJECT( AnimNodeSequence, m_FireAnimSeqNode )
			ADD_VAR( ::NameProperty, m_nmFireAnimSeqNodeName, 0xFFFFFFFF )
			ADD_OBJECT( TrPawn, m_TrPawn )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
