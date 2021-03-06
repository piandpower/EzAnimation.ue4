#include "EzAnimPlugin.h"
#include "EzRotationAnimationComponent.h"

UEzRotationAnimationComponent::UEzRotationAnimationComponent() {
}

void UEzRotationAnimationComponent::BeginPlay() {
	Super::BeginPlay();

	if (IsValid(GetTargetComponent())) {
		SetStartAndEndValue(GetTargetComponent()->RelativeRotation.Vector(), rotateTo);
	}
}

void UEzRotationAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto rotation = GetEaseValue();
	GetTargetComponent()->SetRelativeRotation(
		FQuat::MakeFromEuler(FVector(rotation.X, rotation.Y, rotation.Z)));
}

