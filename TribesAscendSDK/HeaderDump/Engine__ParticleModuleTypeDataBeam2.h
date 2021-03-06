#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.ParticleModuleTypeDataBeam2." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.ParticleModuleTypeDataBeam2." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.ParticleModuleTypeDataBeam2." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class ParticleModuleTypeDataBeam2 : public ParticleModuleTypeDataBase
	{
	public:
			ADD_VAR( ::NameProperty, BranchParentName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, UpVectorStepSize, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, RenderTessellation, 0x10 )
			ADD_VAR( ::BoolProperty, RenderLines, 0x8 )
			ADD_VAR( ::BoolProperty, RenderDirectLine, 0x4 )
			ADD_VAR( ::BoolProperty, RenderGeometry, 0x2 )
			ADD_VAR( ::BoolProperty, bAlwaysOn, 0x1 )
			ADD_VAR( ::IntProperty, InterpolationPoints, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Speed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxBeamCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Sheets, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TextureTileDistance, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TextureTile, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, TaperMethod, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, BeamMethod, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
