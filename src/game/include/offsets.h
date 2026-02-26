#pragma once
#include <cstdint>

inline namespace Offsets {
    namespace Globals {
        inline uintptr_t UWorld = 0x178D5418; // UWorld
        inline uintptr_t UWorldXorKey = 0xFFFFFFFFDF234856uLL;
        inline uintptr_t GNames = 0x17722E80; // GNames
        inline uintptr_t GEngine = 0x178D6D90; // GEngine
        inline uintptr_t Actors = 0x48; // Actors
        inline uintptr_t CameraLocation = 0x180; // CameraLocation
        inline uintptr_t CameraRotation = CameraLocation + 0x10; // CameraRotation
        inline uintptr_t CameraFov = 0x3B4; // CameraFov
    }

    namespace UWorld {
        inline uintptr_t OwningGameInstance = 0x250; // UWorld::OwningGameInstance (SDK: 0x248)
        inline uintptr_t GameState = 0x1D8; // UWorld::GameState (SDK: 0x1d0)
        inline uintptr_t Levels = 0x1E8; // UWorld::Levels (SDK: 0x1e8)
    }

    namespace ACharacter {
        inline uintptr_t Mesh = 0x330; // ACharacter::Mesh
        inline uintptr_t CharacterMovement = 0x338; // ACharacter::CharacterMovement
    }

    namespace AFortPawn {
        inline uintptr_t bIsDying = 0x728; // AFortPawn::bIsDying ( BitField Index -> 5 )
        inline uintptr_t CurrentWeapon = 0x990; // AFortPawn::CurrentWeapon
    }

    namespace AFortPlayerState {
        inline uintptr_t Platform = 0x440; // AFortPlayerState::Platform (SDK: 0x440)
        inline uintptr_t HabaneroComponent = 0x948; // AFortPlayerState::HabaneroComponent (SDK: 0x948)
    }

    namespace AFortPlayerStateAthena {
        inline uintptr_t TeamIndex = 0x11B1; // AFortPlayerStateAthena::TeamIndex (SDK: 0x11b1)
        inline uintptr_t KillScore = 0x11C8; // AFortPlayerStateAthena::KillScore (SDK: 0x11c8)
    }

    namespace AFortWeapon {
        inline uintptr_t WeaponData = 0x5A0; // AFortWeapon::WeaponData (SDK: 0x600)
        inline uintptr_t ProjectileSpeed = 0x24AC; // AFortWeapon::ProjectileSpeed
        inline uintptr_t ProjectileGravity = 0x24B0; // AFortWeapon::ProjectileGravity
    }

    namespace AGameStateBase {
        inline uintptr_t PlayerArray = 0x2C8; // AGameStateBase::PlayerArray
    }

    namespace APawn {
        inline uintptr_t PlayerState = 0x2D0; // APawn::PlayerState
    }

    namespace UPlayer {
        inline uintptr_t PlayerController = 0x30; // UPlayer::PlayerController
    }

    namespace APlayerController {
        inline uintptr_t AcknowledgedPawn = 0x358; // APlayerController::AcknowledgedPawn
        inline uintptr_t NetConnection = 0x528; // APlayerController::NetConnection
    }

    namespace APlayerState {
        inline uintptr_t PawnPrivate = 0x328; // APlayerState::PawnPrivate
    }

    namespace AActor {
        inline uintptr_t RootComponent = 0x1b0; // AActor::RootComponent (SDK: 0x1b0)
    }

    namespace USceneComponent {
        inline uintptr_t RelativeLocation = 0x140; // USceneComponent::RelativeLocation (SDK: 0x140)
        inline uintptr_t ComponentVelocity = 0x188; // USceneComponent::ComponentVelocity (SDK: 0x188)
    }

    namespace UCharacterMovementComponent {
        inline uintptr_t MovementMode = 0x231; // UCharacterMovementComponent::MovementMode
    }

    namespace UGameInstance {
        inline uintptr_t LocalPlayers = 0x38; // UGameInstance::LocalPlayers
    }

    namespace UItemDefinitionBase {
        inline uintptr_t ItemName = 0x40; // UItemDefinitionBase::ItemName
        inline uintptr_t Rarity = 0x78; // UItemDefinitionBase::Rarity
    }

    namespace AFortPickup {
        inline uintptr_t PrimaryPickupItemEntry = 0x3A8; // AFortPickup::PrimaryPickupItemEntry
        inline uintptr_t SimulatingTooLongLength = 0x2D0; // AFortPickup::SimulatingTooLongLength
    }

    namespace FFortItemEntry {
        inline uintptr_t ItemDefinition = 0x10; // FFortItemEntry::ItemDefinition
    }

    namespace USkeletalMesh {
        inline uintptr_t BoneArray = 0x5F0; // USkeletalMesh*
        inline uintptr_t BoneArray_cache = 0x600; // USkeletalMesh*
    }
}
