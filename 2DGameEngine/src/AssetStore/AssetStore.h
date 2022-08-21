#pragma once

#ifndef ASSETSTORE_H
#define ASSETSTORE_H

#include <map>
#include <string>
#include <SDL.h>

class AssetStore {
private:
	std::map<std::string, SDL_Texture*> textures;
	// TODO: create a map for fonts
	// TODO: create a map for audio files

public:
	AssetStore();
	~AssetStore();

	void ClearAssets();
	void AddTexture(SDL_Renderer* renderer, const std::string& assetId, const std::string& filePath);
	SDL_Texture* GetTexture(const std::string& assetId);
};

#endif