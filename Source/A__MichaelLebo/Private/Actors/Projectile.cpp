// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Projectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "../../A__MichaelLebo.h"
#include "UObject/ConstructorHelpers.h"// This is for the bad habit

// Sets default values
AProjectile::AProjectile() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	//Just like dragging gthe root
	SetRootComponent(SphereCollision);
	// This is the part like Create Event in Blueprint 
	// this, &AProjectile::HandleHit

	//OnComponentHit.AddDynamic is like bind the event
	SphereCollision->OnComponentHit.AddDynamic(this, &AProjectile::HandleHit);
	//SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::HandleHit);

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>("SphereMesh");
	SphereMesh->SetupAttachment(SphereCollision);
	SphereMesh->SetCollisionProfileName("NoCollision");

	//Start BAH Habit
	// Only allowed once and here only
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Asset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	SphereMesh->SetStaticMesh(Asset.Object);
	//Only showing the difference between C++ and blueprint for the creation of this objects
	//End Bad habit
}
// Called when the game starts or when spawned
void AProjectile::BeginPlay() {
	Super::BeginPlay();
	//Use 5 out of 6
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AProjectile::K2_DestroyActor, 3.f);
}
// Called every frame
void AProjectile::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}
void AProjectile::HandleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
	//This will never get called
	UE_LOG(Game, Warning, TEXT("Hello"));
}