#include "pch.h"
#include "TilemapActor.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Tilemap.h"	
#include "ResourceManager.h"
#include "Sprite.h"
#include "SpriteActor.h"

TilemapActor::TilemapActor()
{
}

TilemapActor::~TilemapActor()
{
}

void TilemapActor::BeginPlay()
{
	Super::BeginPlay();
}

void TilemapActor::Tick()
{
	Super::Tick();
}

void TilemapActor::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_tilemap == nullptr)
		return;	

	if (_showDebug == false)
		return;

	const Vec2Int mapSize = _tilemap->GetMapSize();
	const int32 tileSize = _tilemap->GetTileSize();	

	vector<vector<Tile>>& tiles = _tilemap->GetTiles();

	Sprite* spriteO = GET_SINGLE(ResourceManager)->GetSprite(L"TileO");
	Sprite* spriteX = GET_SINGLE(ResourceManager)->GetSprite(L"TileX");

	Vec2 cameraPos = GET_SINGLE(SceneManager)->GetCameraPos();

	for (int32 y = 0; y < mapSize.y; ++y)
	{
		for (int32 x = 0; x < mapSize.x; ++x)
		{
			if (x < 0 || x >= mapSize.x ||
				y < 0 || y >= mapSize.y)
				continue;

			switch (tiles[y][x].value)
			{
			case 0:
				::TransparentBlt(hdc,
					_pos.x + x * TILE_SIZEX - ((int32)cameraPos.x - GWinSizeX /2),
					_pos.y + y * TILE_SIZEY - ((int32)cameraPos.y - GWinSizeY / 2),
					TILE_SIZEX,
					TILE_SIZEY,
					spriteO->GetDC(),
					spriteO->GetPos().x,
					spriteO->GetPos().y,
					TILE_SIZEX,
					TILE_SIZEY,
					spriteO->GetTransparent()
				);
				break;
			case 1:
				::TransparentBlt(hdc,
					_pos.x + x * TILE_SIZEX - ((int32)cameraPos.x - GWinSizeX /2),
					_pos.y + y * TILE_SIZEY - ((int32)cameraPos.y - GWinSizeY / 2),
					TILE_SIZEX,
					TILE_SIZEY,
					spriteX->GetDC(),
					spriteX->GetPos().x,
					spriteX->GetPos().y,
					TILE_SIZEX,
					TILE_SIZEY,
					spriteX->GetTransparent()
				);	
				break;
			}
		}

	}
}
