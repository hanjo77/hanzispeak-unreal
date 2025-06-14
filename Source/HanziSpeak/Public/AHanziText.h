#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Text3DComponent.h"

#include "AHanziText.generated.h"

UCLASS()
class HANZISPEAK_API AAHanziText : public AActor
{
    GENERATED_BODY()

public:
    AAHanziText();

    virtual void Tick(float DeltaTime) override;

    void SetText(const FString& NewText);
    void SetSpeed(float Speed);

protected:
    virtual void BeginPlay() override;

private:
    UText3DComponent* Text3D;
    float MoveSpeed = 100.f;
};