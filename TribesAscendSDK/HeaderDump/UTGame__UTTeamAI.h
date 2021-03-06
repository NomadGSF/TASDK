#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTTeamAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTTeamAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTTeamAI." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTTeamAI : public UDKTeamOwnedInfo
	{
	public:
			ADD_OBJECT( UTTeamInfo, EnemyTeam )
			ADD_OBJECT( UTGameObjective, Objectives )
			ADD_OBJECT( UTSquadAI, Squads )
			ADD_VAR( ::BoolProperty, bFoundSuperItems, 0x1 )
			ADD_VAR( ::IntProperty, NumSuperPickups, 0xFFFFFFFF )
			ADD_OBJECT( UTPickupFactory, SuperPickups )
			ADD_VAR( ::NameProperty, OrderList, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, OrderOffset, 0xFFFFFFFF )
			ADD_OBJECT( UTSquadAI, FreelanceSquad )
			ADD_OBJECT( UTSquadAI, AttackSquad )
			ADD_OBJECT( UTGameObjective, PickedStandaloneObjective )
			ADD_OBJECT( UTGameObjective, PickedObjective )
			ADD_VAR( ::IntProperty, NumSupportingPlayer, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
