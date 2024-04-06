#include "MusicManager.h"
#include <iostream>

void MusicManager::Play(const string& _path, const bool _isLoop)
{
	if (_path == "") return;

	MusicData* _musicData = Get(_path);

	if (!_musicData)
	{
		_musicData = new MusicData(_path);
		if (!_musicData->openFromFile("Assets/Songs/" + _path))
		{
			cerr << "Le son n'a pas été correctement chargée !" << endl;
			return;
		}
	}
	if (_musicData)
	{
		_musicData->play();
		_musicData->setVolume(5.0f);
		if (_isLoop) _musicData->setLoop(_isLoop);
		SetCurrent(_musicData->GetID());
	}
}

void MusicManager::StopAndPlay(const string& _path, const bool _isLoop)
{
	StopAll();

	if (_path == "") return;

	MusicData* _musicData = Get(_path);

	if (!_musicData)
	{
		_musicData = new MusicData(_path);
		if (!_musicData->openFromFile("Assets/Songs/" + _path))
		{
			cerr << "Le son n'a pas été correctement chargée !" << endl;
			return;
		}
	}
	if (_musicData)
	{
		_musicData->play();
		_musicData->setVolume(5.0f);
		if (_isLoop) _musicData->setLoop(_isLoop);
		SetCurrent(_musicData->GetID());
	}
}


void MusicManager::StopAll()
{
	for (MusicData* _music : GetAllValues())
	{
		_music->stop();
	}
}

void MusicManager::SmoothVolumeUp(const float _value)
{
	const float _initial = GetCurrent()->getVolume();

	if (_initial != _value)
	{
		GetCurrent()->setVolume(_initial + 1);
	}
}

void MusicManager::SmoothVolumeDown(const float _value)
{
	const int _initial = static_cast<int>(GetCurrent()->getVolume());

	if (_initial != _value)
	{
		GetCurrent()->setVolume(static_cast<float>(_initial - 1.0f));
	}
}