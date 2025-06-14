#include "AHanziText.h"
#include "Text3DComponent.h"
#include "Kismet/GameplayStatics.h"

// Constructor
AAHanziText::AAHanziText()
{
    PrimaryActorTick.bCanEverTick = true;

    // Create the 3D text component and set as root
    Text3D = CreateDefaultSubobject<UText3DComponent>(TEXT("Text3D"));
    RootComponent = Text3D;

    // Optional text appearance defaults
    if (Text3D)
    {
        Text3D->SetText(FText::FromString(TEXT("初")));  // Just a placeholder Hanzi
        Text3D->SetHorizontalAlignment(EText3DHorizontalTextAlignment::Center);
        Text3D->SetVerticalAlignment(EText3DVerticalTextAlignment::FirstLine);
        Text3D->SetWordSpacing(2.f);
        Text3D->SetLineSpacing(1.f);
        Text3D->SetExtrude(1.f); // Slight 3D depth
    }
}

void AAHanziText::BeginPlay()
{
    Super::BeginPlay();
}

void AAHanziText::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Get camera location
    APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
    if (!CameraManager) return;

    FVector CurrentLocation = GetActorLocation();
    FVector TargetLocation = CameraManager->GetCameraLocation();
    FVector Direction = (TargetLocation - CurrentLocation).GetSafeNormal();

    // Move toward the camera
    SetActorLocation(CurrentLocation + Direction * MoveSpeed * DeltaTime);
}

void AAHanziText::SetText(const FString& NewText)
{
    if (Text3D)
    {
        Text3D->SetText(FText::FromString(NewText));
    }
}

void AAHanziText::SetSpeed(float NewSpeed)
{
    MoveSpeed = NewSpeed;
}
