#pragma once
#include <cstdint>

namespace Offsets {
    namespace Globals {
        inline uintptr_t UWorld = 0x17D2F6C8; // UWorld
        inline uintptr_t GNames = 0x17DC6F40; // GNames
        inline uintptr_t GEngine = 0x17B70440; // GEngine
        inline uintptr_t CameraLocation = 0x178; // CameraLocation
        inline uintptr_t CameraRotation = 0x188; // CameraRotation
        inline uintptr_t AActors = 0x208; // AActors
    }

    namespace AActor {
        inline uintptr_t CustomTimeDilation = 0x68; // AActor::CustomTimeDilation
        inline uintptr_t Children = 0x1A0; // AActor::Children
        inline uintptr_t RootComponent = 0x1B0; // AActor::RootComponent
    }

    namespace ABuildingContainer {
        inline uintptr_t SpawnSourceOverride = 0xC68; // ABuildingContainer::SpawnSourceOverride
        inline uintptr_t HighestRarity = 0xDD0; // ABuildingContainer::HighestRarity
        inline uintptr_t bAlreadySearched = 0xDD2; // ABuildingContainer::bAlreadySearched ( BitField Index -> 2 )
        inline uintptr_t SearchText = 0xE28; // ABuildingContainer::SearchText
    }

    namespace ABuildingWeakSpot {
        inline uintptr_t bActive = 0x2D8; // ABuildingWeakSpot::bActive ( BitField Index -> 2 )
        inline uintptr_t HitCount = 0x2DC; // ABuildingWeakSpot::HitCount
    }

    namespace ACharacter {
        inline uintptr_t Mesh = 0x328; // ACharacter::Mesh
        inline uintptr_t CharacterMovement = 0x330; // ACharacter::CharacterMovement
    }

    namespace AFortAthenaSKPushVehicle {
        inline uintptr_t ForwardForceTractionScale = 0x2224; // AFortAthenaSKPushVehicle::ForwardForceTractionScale
    }

    namespace AFortAthenaVehicle {
        inline uintptr_t CustomName = 0x658; // AFortAthenaVehicle::CustomName
        inline uintptr_t WaterEffectsVehicleMaxSpeedKmh = 0x9E8; // AFortAthenaVehicle::WaterEffectsVehicleMaxSpeedKmh
        inline uintptr_t TopSpeedCurrentMultiplier = 0xB58; // AFortAthenaVehicle::TopSpeedCurrentMultiplier
        inline uintptr_t PushForceCurrentMultiplier = 0xB5C; // AFortAthenaVehicle::PushForceCurrentMultiplier
        inline uintptr_t CachedSpeed = 0xF38; // AFortAthenaVehicle::CachedSpeed
        inline uintptr_t VehicleAttributes = 0x1350; // AFortAthenaVehicle::VehicleAttributes
        inline uintptr_t CachedFuelComponent = 0x1378; // AFortAthenaVehicle::CachedFuelComponent
        inline uintptr_t HealthSet = 0x1808; // AFortAthenaVehicle::HealthSet
    }

    namespace AFortPawn {
        inline uintptr_t bIsDying = 0x728; // AFortPawn::bIsDying ( BitField Index -> 5 )
        inline uintptr_t bIsInvulnerable = 0x72A; // AFortPawn::bIsInvulnerable ( BitField Index -> 2 )
        inline uintptr_t bIsDBNO = 0x841; // AFortPawn::bIsDBNO ( BitField Index -> 7 )
        inline uintptr_t CurrentWeapon = 0x990; // AFortPawn::CurrentWeapon
        inline uintptr_t PreviousWeapon = 0x9C0; // AFortPawn::PreviousWeapon
        inline uintptr_t CurrentWeaponList = 0x9C8; // AFortPawn::CurrentWeaponList
        inline uintptr_t LastDamagedTime = 0xCD0; // AFortPawn::LastDamagedTime
    }

    namespace AFortPickup {
        inline uintptr_t SimulatingTooLongLength = 0x2C8; // AFortPickup::SimulatingTooLongLength
        inline uintptr_t PrimaryPickupItemEntry = 0x3A0; // AFortPickup::PrimaryPickupItemEntry
        inline uintptr_t DefaultFlyTime = 0x604; // AFortPickup::DefaultFlyTime
    }

    namespace AFortPlayerController {
        inline uintptr_t bAutoRunOn = 0x1069; // AFortPlayerController::bAutoRunOn ( BitField Index -> 3 )
        inline uintptr_t OnSetFirstPersonCamera = 0x10C0; // AFortPlayerController::OnSetFirstPersonCamera
        inline uintptr_t TargetedFortPawn = 0x1900; // AFortPlayerController::TargetedFortPawn
        inline uintptr_t LocationUnderReticle = 0x2BD0; // AFortPlayerController::LocationUnderReticle
        inline uintptr_t AdditionalAimOffset = 0x2D20; // AFortPlayerController::AdditionalAimOffset
        inline uintptr_t PlayerAimOffset = 0x2D38; // AFortPlayerController::PlayerAimOffset
        inline uintptr_t WeaponRecoilOffset = 0x2D50; // AFortPlayerController::WeaponRecoilOffset
    }

    namespace AFortPlayerControllerGameplay {
        inline uintptr_t bIsCreativeModeratorModeEnabled = 0x3942; // AFortPlayerControllerGameplay::bIsCreativeModeratorModeEnabled ( BitField Index -> 5 )
    }

    namespace AFortPlayerPawn {
        inline uintptr_t BuildingState = 0x20B0; // AFortPlayerPawn::BuildingState
        inline uintptr_t bIsSkydiving = 0x227F; // AFortPlayerPawn::bIsSkydiving
        inline uintptr_t bIsParachuteOpen = 0x2280; // AFortPlayerPawn::bIsParachuteOpen
        inline uintptr_t CurrentVehicle = 0x2C08; // AFortPlayerPawn::CurrentVehicle
    }

    namespace AFortPlayerPawnAthena {
        inline uintptr_t ReviveFromDBNOTime = 0x4DE0; // AFortPlayerPawnAthena::ReviveFromDBNOTime
        inline uintptr_t CustomDepthComponent = 0x4E40; // AFortPlayerPawnAthena::CustomDepthComponent
        inline uintptr_t LastFiredLocation = 0x59B0; // AFortPlayerPawnAthena::LastFiredLocation
        inline uintptr_t LastFiredDirection = 0x59C8; // AFortPlayerPawnAthena::LastFiredDirection
        inline uintptr_t LastFiredTime = 0x59E0; // AFortPlayerPawnAthena::LastFiredTime
        inline uintptr_t bCanBeMarkedAsTeammate = 0x5EB8; // AFortPlayerPawnAthena::bCanBeMarkedAsTeammate
    }

    namespace AFortPlayerState {
        inline uintptr_t Platform = 0x438; // AFortPlayerState::Platform
    }

    namespace AFortPlayerStateAthena {
        inline uintptr_t TeamKillScore = 0x10EC; // AFortPlayerStateAthena::TeamKillScore
        inline uintptr_t AlwaysIncludeTeamAsAllies = 0x1190; // AFortPlayerStateAthena::AlwaysIncludeTeamAsAllies
        inline uintptr_t TeamIndex = 0x1191; // AFortPlayerStateAthena::TeamIndex
        inline uintptr_t KillScore = 0x11A8; // AFortPlayerStateAthena::KillScore
        inline uintptr_t SeasonLevelUIDisplay = 0x11AC; // AFortPlayerStateAthena::SeasonLevelUIDisplay
        inline uintptr_t bThankedBusDriver = 0x132D; // AFortPlayerStateAthena::bThankedBusDriver ( BitField Index -> 0 )
        inline uintptr_t bIsTalking = 0x13B0; // AFortPlayerStateAthena::bIsTalking
        inline uintptr_t bIsMuted = 0x13B1; // AFortPlayerStateAthena::bIsMuted
        inline uintptr_t bIsDisconnected = 0x16A8; // AFortPlayerStateAthena::bIsDisconnected
        inline uintptr_t RebootCounter = 0x187C; // AFortPlayerStateAthena::RebootCounter
    }

    namespace AFortPlayerStateZone {
        inline uintptr_t Spectators = 0xA88; // AFortPlayerStateZone::Spectators
        inline uintptr_t CurrentHealth = 0xD8C; // AFortPlayerStateZone::CurrentHealth
        inline uintptr_t MaxHealth = 0xD90; // AFortPlayerStateZone::MaxHealth
        inline uintptr_t CurrentShield = 0xD94; // AFortPlayerStateZone::CurrentShield
        inline uintptr_t MaxShield = 0xD98; // AFortPlayerStateZone::MaxShield
    }

    namespace AFortProjectileBase {
        inline uintptr_t MaxLifespanOnStop = 0xB24; // AFortProjectileBase::MaxLifespanOnStop
    }

    namespace AFortSafeZoneIndicator {
        inline uintptr_t SafeZonePhases = 0x4F0; // AFortSafeZoneIndicator::SafeZonePhases
    }

    namespace AFortWeapon {
        inline uintptr_t TimeToEquip = 0x364; // AFortWeapon::TimeToEquip
        inline uintptr_t bIsEquippingWeapon = 0x380; // AFortWeapon::bIsEquippingWeapon
        inline uintptr_t bIsChargingWeapon = 0x398; // AFortWeapon::bIsChargingWeapon
        inline uintptr_t bIsReloadingWeapon = 0x399; // AFortWeapon::bIsReloadingWeapon ( BitField Index -> 0 )
        inline uintptr_t WeaponData = 0x5B0; // AFortWeapon::WeaponData
        inline uintptr_t CurrentReticleColor = 0x1058; // AFortWeapon::CurrentReticleColor
        inline uintptr_t CurrentProjectedImpactDistance = 0x1098; // AFortWeapon::CurrentProjectedImpactDistance
        inline uintptr_t LastFireTimeVerified = 0x10B8; // AFortWeapon::LastFireTimeVerified
        inline uintptr_t bAllowTargeting = 0x10C8; // AFortWeapon::bAllowTargeting ( BitField Index -> 4 )
        inline uintptr_t AmmoCount = 0x1174; // AFortWeapon::AmmoCount
        inline uintptr_t ChargeTime = 0x1194; // AFortWeapon::ChargeTime
        inline uintptr_t AccumulatedChargeTime = 0x1198; // AFortWeapon::AccumulatedChargeTime
        inline uintptr_t LastChargeTime = 0x119C; // AFortWeapon::LastChargeTime
        inline uintptr_t WeaponCoreAnimation = 0x1698; // AFortWeapon::WeaponCoreAnimation
        inline uintptr_t bIgnoreTryToFireSlotCooldownRestriction = 0x1851; // AFortWeapon::bIgnoreTryToFireSlotCooldownRestriction
    }

    namespace AFortWeaponRanged {
        inline uintptr_t AimPitchMin = 0x2110; // AFortWeaponRanged::AimPitchMin
        inline uintptr_t AimPitchMax = 0x2114; // AFortWeaponRanged::AimPitchMax
    }

    namespace AGameStateBase {
        inline uintptr_t PlayerArray = 0x2C0; // AGameStateBase::PlayerArray
        inline uintptr_t ServerWorldTimeSecondsDelta = 0x2E0; // AGameStateBase::ServerWorldTimeSecondsDelta
    }

    namespace APawn {
        inline uintptr_t PlayerState = 0x2C8; // APawn::PlayerState
    }

    namespace APlayerCameraManager {
        inline uintptr_t DefaultFOV = 0x2BC; // APlayerCameraManager::DefaultFOV
        inline uintptr_t ViewTarget = 0x340; // APlayerCameraManager::ViewTarget
        inline uintptr_t CameraCachePrivate = 0x1530; // APlayerCameraManager::CameraCachePrivate
        inline uintptr_t ViewPitchMin = 0x27AC; // APlayerCameraManager::ViewPitchMin
        inline uintptr_t ViewPitchMax = 0x27B0; // APlayerCameraManager::ViewPitchMax
        inline uintptr_t ViewYawMin = 0x27B4; // APlayerCameraManager::ViewYawMin
        inline uintptr_t ViewYawMax = 0x27B8; // APlayerCameraManager::ViewYawMax
        inline uintptr_t ViewRollMin = 0x27BC; // APlayerCameraManager::ViewRollMin
        inline uintptr_t ViewRollMax = 0x27C0; // APlayerCameraManager::ViewRollMax
    }

    namespace APlayerController {
        inline uintptr_t AcknowledgedPawn = 0x350; // APlayerController::AcknowledgedPawn
        inline uintptr_t PlayerCameraManager = 0x360; // APlayerController::PlayerCameraManager
        inline uintptr_t SmoothTargetViewRotationSpeed = 0x3A8; // APlayerController::SmoothTargetViewRotationSpeed
        inline uintptr_t NetConnection = 0x520; // APlayerController::NetConnection
        inline uintptr_t InputYawScale = 0x540; // APlayerController::InputYawScale
        inline uintptr_t InputPitchScale = 0x544; // APlayerController::InputPitchScale
        inline uintptr_t InputRollScale = 0x548; // APlayerController::InputRollScale
        inline uintptr_t PlayerCameraFov = 0x3AC; // APlayerController::PlayerCameraFov 
    }

    namespace APlayerState {
        inline uintptr_t PlayerId = 0x2AC; // APlayerState::PlayerId
        inline uintptr_t CompressedPing = 0x2B0; // APlayerState::CompressedPing
        inline uintptr_t bIsABot = 0x2B2; // APlayerState::bIsABot ( BitField Index -> 3 )
        inline uintptr_t PawnPrivate = 0x320; // APlayerState::PawnPrivate
        inline uintptr_t PlayerNamePrivate = 0x340; // APlayerState::PlayerNamePrivate
    }

    namespace AWorldSettings {
        inline uintptr_t WorldGravityZ = 0x328; // AWorldSettings::WorldGravityZ
    }

    namespace FCameraCacheEntry {
        inline uintptr_t POV = 0x10; // FCameraCacheEntry::POV
    }

    namespace FCustomHighlighting {
        inline uintptr_t FriendlyStencilValue = 0x1; // FCustomHighlighting::FriendlyStencilValue
        inline uintptr_t EnemyStencilValue = 0x2; // FCustomHighlighting::EnemyStencilValue
        inline uintptr_t TeamDisplayOverride = 0x3; // FCustomHighlighting::TeamDisplayOverride
    }

    namespace FFortBaseWeaponStats {
        inline uintptr_t ReloadTime = 0x174; // FFortBaseWeaponStats::ReloadTime
    }

    namespace FFortRangedWeaponStats {
        inline uintptr_t Spread = 0x210; // FFortRangedWeaponStats::Spread
        inline uintptr_t OverrideBaseSpread = 0x214; // FFortRangedWeaponStats::OverrideBaseSpread
        inline uintptr_t SpreadDownsights = 0x218; // FFortRangedWeaponStats::SpreadDownsights
        inline uintptr_t OverrideSpreadDownsights = 0x21C; // FFortRangedWeaponStats::OverrideSpreadDownsights
        inline uintptr_t StandingStillSpreadMultiplier = 0x220; // FFortRangedWeaponStats::StandingStillSpreadMultiplier
        inline uintptr_t AthenaCrouchingSpreadMultiplier = 0x224; // FFortRangedWeaponStats::AthenaCrouchingSpreadMultiplier
        inline uintptr_t AthenaSlidingSpreadMultiplier = 0x228; // FFortRangedWeaponStats::AthenaSlidingSpreadMultiplier
        inline uintptr_t AthenaJumpingFallingSpreadMultiplier = 0x22C; // FFortRangedWeaponStats::AthenaJumpingFallingSpreadMultiplier
        inline uintptr_t AthenaSprintingSpreadMultiplier = 0x230; // FFortRangedWeaponStats::AthenaSprintingSpreadMultiplier
        inline uintptr_t MinSpeedForSpreadMultiplier = 0x234; // FFortRangedWeaponStats::MinSpeedForSpreadMultiplier
        inline uintptr_t MaxSpeedForSpreadMultiplier = 0x238; // FFortRangedWeaponStats::MaxSpeedForSpreadMultiplier
        inline uintptr_t SpreadDownsightsAdditionalCooldownTime = 0x23C; // FFortRangedWeaponStats::SpreadDownsightsAdditionalCooldownTime
        inline uintptr_t SpreadExponent = 0x240; // FFortRangedWeaponStats::SpreadExponent
        inline uintptr_t FiringRate = 0x29C; // FFortRangedWeaponStats::FiringRate
        inline uintptr_t RecoilVert = 0x2BC; // FFortRangedWeaponStats::RecoilVert
        inline uintptr_t RecoilHoriz = 0x2CC; // FFortRangedWeaponStats::RecoilHoriz
    }

    namespace FFortSpectatorZoneArray {
        inline uintptr_t SpectatorArray = 0x108; // FFortSpectatorZoneArray::SpectatorArray
    }

    namespace FFortSpectatorZoneItem {
        inline uintptr_t PlayerState = 0x10; // FFortSpectatorZoneItem::PlayerState
    }

    namespace FFortTrapStats {
        inline uintptr_t ArmTime = 0x210; // FFortTrapStats::ArmTime
        inline uintptr_t FireDelay = 0x214; // FFortTrapStats::FireDelay
        inline uintptr_t DamageDelay = 0x218; // FFortTrapStats::DamageDelay
    }

    namespace FItemEntry {
        inline uintptr_t ItemDefinition = 0x10; // FItemEntry::ItemDefinition
    }

    namespace FMinimalViewInfo {
        inline uintptr_t Rotation = 0x18; // FMinimalViewInfo::Rotation
        inline uintptr_t FOV = 0x30; // FMinimalViewInfo::FOV
        inline uintptr_t DesiredFOV = 0x34; // FMinimalViewInfo::DesiredFOV
        inline uintptr_t AspectRatio = 0x5C; // FMinimalViewInfo::AspectRatio
    }

    namespace UCharacterMovementComponent {
        inline uintptr_t LastUpdateLocation = 0x360; // UCharacterMovementComponent::LastUpdateLocation
    }

    namespace UEngine {
        inline uintptr_t TinyFont = 0x30; // UEngine::TinyFont
        inline uintptr_t SmallFont = 0x50; // UEngine::SmallFont
        inline uintptr_t LargeFont = 0x90; // UEngine::LargeFont
        inline uintptr_t GameViewport = 0xA90; // UEngine::GameViewport
    }

    namespace UFortClientSettingsRecord {
        inline uintptr_t HUDScale = 0x6C8; // UFortClientSettingsRecord::HUDScale
        inline uintptr_t InitialHUDScale = 0x6D0; // UFortClientSettingsRecord::InitialHUDScale
        inline uintptr_t TargetingSlow = 0x76C; // UFortClientSettingsRecord::TargetingSlow
        inline uintptr_t ScopedSlow = 0x770; // UFortClientSettingsRecord::ScopedSlow
        inline uintptr_t MouseSensitivity = 0x7A4; // UFortClientSettingsRecord::MouseSensitivity
        inline uintptr_t MouseSensitivityX = 0x7A8; // UFortClientSettingsRecord::MouseSensitivityX
        inline uintptr_t MouseSensitivityY = 0x7AC; // UFortClientSettingsRecord::MouseSensitivityY
        inline uintptr_t MasterVolume = 0xB4C; // UFortClientSettingsRecord::MasterVolume
        inline uintptr_t MusicVolume = 0xB50; // UFortClientSettingsRecord::MusicVolume
        inline uintptr_t bAnonymousMode = 0xB75; // UFortClientSettingsRecord::bAnonymousMode
        inline uintptr_t FOVMinimum = 0xBFC; // UFortClientSettingsRecord::FOVMinimum
        inline uintptr_t FOVMaximum = 0xC00; // UFortClientSettingsRecord::FOVMaximum
    }

    namespace UFortItemDefinition {
        inline uintptr_t Rarity = 0xAA; // UFortItemDefinition::Rarity
    }

    namespace UFortLocalPlayer {
        inline uintptr_t ClientSettingsRecord = 0x380; // UFortLocalPlayer::ClientSettingsRecord
    }

    namespace UFortPawnComponent_CustomDepth {
        inline uintptr_t DefaultHighlightingData = 0xF0; // UFortPawnComponent_CustomDepth::DefaultHighlightingData
    }

    namespace UFortVehicleFuelComponent {
        inline uintptr_t ServerFuel = 0x130; // UFortVehicleFuelComponent::ServerFuel
    }

    namespace UFortWeaponItemDefinition {
        inline uintptr_t TriggerType = 0x294; // UFortWeaponItemDefinition::TriggerType
        inline uintptr_t bAllowTargetingDuringReload = 0x298; // UFortWeaponItemDefinition::bAllowTargetingDuringReload ( BitField Index -> 0 )
        inline uintptr_t HitNotifyDuration = 0x29C; // UFortWeaponItemDefinition::HitNotifyDuration
    }

    namespace UGameInstance {
        inline uintptr_t LocalPlayers = 0x38; // UGameInstance::LocalPlayers
    }

    namespace UGameViewportClient {
        inline uintptr_t World = 0x78; // UGameViewportClient::World
    }

    namespace UItemDefinitionBase {
        inline uintptr_t ItemName = 0x40; // UItemDefinitionBase::ItemName
    }

    namespace ULevel {
        inline uintptr_t OwningWorld = 0x90; // ULevel::OwningWorld
        inline uintptr_t WorldSettings = 0x2B8; // ULevel::WorldSettings
    }

    namespace ULocalPlayer {
        inline uintptr_t ViewportClient = 0x78; // ULocalPlayer::ViewportClient
    }

    namespace UMaterial {
        inline uintptr_t Wireframe = 0x1D8; // UMaterial::Wireframe ( BitField Index -> 7 )
    }

    namespace UMaterialInstance {
        inline uintptr_t Parent = 0x128; // UMaterialInstance::Parent
        inline uintptr_t ScalarParameterValues = 0x190; // UMaterialInstance::ScalarParameterValues
        inline uintptr_t VectorParameterValues = 0x1A0; // UMaterialInstance::VectorParameterValues
        inline uintptr_t TextureParameterValues = 0x1C0; // UMaterialInstance::TextureParameterValues
    }

    namespace UMovementComponent {
        inline uintptr_t Velocity = 0xD8; // UMovementComponent::Velocity
    }

    namespace UPlayer {
        inline uintptr_t PlayerController = 0x30; // UPlayer::PlayerController
    }

    namespace USceneComponent {
        inline uintptr_t PhysicsVolume = 0xC8; // USceneComponent::PhysicsVolume
        inline uintptr_t RelativeLocation = 0x140; // USceneComponent::RelativeLocation
        inline uintptr_t RelativeRotation = 0x158; // USceneComponent::RelativeRotation
        inline uintptr_t RelativeScale3D = 0x170; // USceneComponent::RelativeScale3D
        inline uintptr_t ComponentVelocity = 0x188; // USceneComponent::ComponentVelocity
        inline uintptr_t bComponentToWorldUpdated = 0x1A0; // USceneComponent::bComponentToWorldUpdated ( BitField Index -> 0 )
        inline uintptr_t bAbsoluteLocation = 0x1A0; // USceneComponent::bAbsoluteLocation ( BitField Index -> 2 )
    }

    namespace USkeletalMeshComponent {
        inline uintptr_t GlobalAnimRateScale = 0xA58; // USkeletalMeshComponent::GlobalAnimRateScale
    }

    namespace USkinnedMeshComponent {
        inline uintptr_t SkeletalMesh = 0x570; // USkinnedMeshComponent::SkeletalMesh
        inline uintptr_t MeshDeformerInstances = 0x5B8; // USkinnedMeshComponent::MeshDeformerInstances
        inline uintptr_t bForceWireframe = 0x7B7; // USkinnedMeshComponent::bForceWireframe ( BitField Index -> 6 )
    }

    namespace UWorld {
        inline uintptr_t PersistentLevel = 0x40; // UWorld::PersistentLevel
        inline uintptr_t GameState = 0x1D0; // UWorld::GameState
        inline uintptr_t Levels = 0x1E8; // UWorld::Levels
        inline uintptr_t OwningGameInstance = 0x248; // UWorld::OwningGameInstance
    }

    namespace Calculated {
        inline uintptr_t Bounds = 0x108; // USceneComponent::Bounds (Calculated)
        inline uintptr_t LastRenderTime = 0x198; // UWorld::LastRenderTime (Calculated)
        inline uintptr_t LastRenderTimeOnScreen = 0x32C; // UPrimitiveComponent::LastRenderTimeOnScreen (Calculated)
        inline uintptr_t LocalPlayerCachedLODDistanceFactor = 0x3AC; // APlayerController::LocalPlayerCachedLODDistanceFactor (Calculated)
    }

    namespace BitfieldIndexs {
        inline int bComponentToWorldUpdated = 0;
        inline int bAbsoluteLocation = 2;
        inline int Wireframe = 7;
        inline int bAllowTargetingDuringReload = 0;
        inline int bIsABot = 3;
        inline int bActive = 2;
        inline int bIsReloadingWeapon = 0;
        inline int bIsDying = 5;
        inline int bIsInvulnerable = 2;
        inline int bForceWireframe = 6;
        inline int bIsDBNO = 7;
        inline int bAlreadySearched = 2;
        inline int bAutoRunOn = 3;
        inline int bAllowTargeting = 4;
        inline int bThankedBusDriver = 0;
        inline int bIsCreativeModeratorModeEnabled = 5;
    }
}