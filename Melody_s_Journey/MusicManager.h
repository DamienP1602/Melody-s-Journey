#pragma once

#include "IManager.h"
#include "MusicData.h"
#include "Singleton.h"

class MusicManager : public Singleton<MusicManager>, public IManager<string, MusicData>
{

public:
	void Play(const string& _path, const bool _isLoop = true);
	void StopAndPlay(const string& _path, const bool _isLoop = true);

	void StopAll();
	void SmoothVolumeUp(const float _value);
	void SmoothVolumeDown(const float _value);

};