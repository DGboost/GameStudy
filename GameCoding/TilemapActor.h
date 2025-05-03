#pragma once
#include "Actor.h"

class Tilemap;

enum TILE_SIZE
{
	TILE_WIDTH = 63,
	TILE_HEIGHT = 43,
	TILE_SIZEX = 48,
	TILE_SIZEY = 48,
};

class TilemapActor : public Actor
{
	using Super = Actor;

public:
	TilemapActor();
	virtual ~TilemapActor() override;

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

	void SetTilemap(Tilemap* tilemap) { _tilemap = tilemap; }
	Tilemap* GetTilemap() { return _tilemap; }

	void SetShowDebug(bool show) { _showDebug = show; }	

protected:
	Tilemap* _tilemap = nullptr;
	bool _showDebug = false;
};

