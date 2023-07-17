#include "MinigolfPlayerState.h"

AMinigolfPlayerState::AMinigolfPlayerState()
{
	ResetStrokes();
}

void AMinigolfPlayerState::AddStroke()
{
	strokes += 1;
}

void AMinigolfPlayerState::ResetStrokes()
{
	strokes = 0;
}