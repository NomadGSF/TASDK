#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.GameExplosion." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.GameExplosion." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.GameExplosion." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameExplosion : public Object
	{
	public:
			ADD_VAR( ::FloatProperty, CameraLensEffectRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CamShakeFalloff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CamShakeOuterRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CamShakeInnerRadius, 0xFFFFFFFF )
			ADD_OBJECT( CameraShake, CamShake_Rear )
			ADD_OBJECT( CameraShake, CamShake_Right )
			ADD_OBJECT( CameraShake, CamShake_Left )
			ADD_OBJECT( CameraShake, CamShake )
			ADD_VAR( ::FloatProperty, FracturePartVel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FractureMeshRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExploRadialBlurMaxBlur, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExploRadialBlurFadeOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExploLightFadeOutTime, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, ExplosionSound )
			ADD_STRUCT( ::VectorProperty, HitNormal, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, HitLocation, 0xFFFFFFFF )
			ADD_OBJECT( Actor, HitActor )
			ADD_VAR( ::FloatProperty, ExplosionEmitterScale, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, ParticleEmitterTemplate )
			ADD_VAR( ::FloatProperty, MomentumTransferScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CringeRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, KnockDownStrength, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, KnockDownRadius, 0xFFFFFFFF )
			ADD_OBJECT( Actor, ActorToIgnoreForDamage )
			ADD_VAR( ::FloatProperty, DamageFalloffExponent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DamageRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Damage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DamageDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DirectionalExplosionAngleDeg, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAutoControllerVibration, 0x400 )
			ADD_VAR( ::BoolProperty, bOrientCameraShakeTowardsEpicenter, 0x200 )
			ADD_VAR( ::BoolProperty, bUseOverlapCheck, 0x100 )
			ADD_VAR( ::BoolProperty, bUseMapSpecificValues, 0x80 )
			ADD_VAR( ::BoolProperty, bParticleSystemIsBeingOverriddenDontUsePhysMatVersion, 0x40 )
			ADD_VAR( ::BoolProperty, bAllowPerMaterialFX, 0x20 )
			ADD_VAR( ::BoolProperty, bCausesFracture, 0x10 )
			ADD_VAR( ::BoolProperty, bAttachExplosionEmitterToAttachee, 0x8 )
			ADD_VAR( ::BoolProperty, bFullDamageToAttachee, 0x4 )
			ADD_VAR( ::BoolProperty, bAllowTeammateCringes, 0x2 )
			ADD_VAR( ::BoolProperty, bDirectionalExplosion, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
