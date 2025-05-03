#pragma once
#include "ResourceBase.h"

struct Tile
{
	int32 value = 0;
};

class Tilemap : public ResourceBase
{
public:
	Tilemap();
	virtual ~Tilemap() override;

	void LoadFile(const wstring& path) override;
	void SaveFile(const wstring& path) override;

	Vec2Int GetMapSize() const { return _mapSize; }
	int32 GetTileSize() const { return _tileSize; }
	Tile* GetTile(Vec2Int pos);

	vector<vector<Tile>>& GetTiles() { return _tiles; }

	void SetMapSize(Vec2Int size);
	void SetTileSize(int32 size);

private:
	Vec2Int _mapSize = {};
	int32 _tileSize = 0;
	vector<vector<Tile>> _tiles;
};

