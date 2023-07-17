#include "MinigolfPlayerState.h"

AMinigolfPlayerState::AMinigolfPlayerState()
{
	ResetStrokes();
	SetIsMoving(false);
}

void AMinigolfPlayerState::AddStroke()
{
	strokes += 1;
}

void AMinigolfPlayerState::ResetStrokes()
{
	strokes = 0;
}

void AMinigolfPlayerState::SetIsMoving(bool moving)
{
	isMoving = moving;
}

bool AMinigolfPlayerState::GetIsMoving()
{
	return isMoving;
}