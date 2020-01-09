#include "GeneralSoundEffects.h"

std::vector<Audio*> GeneralSoundEffects::audios;

constexpr float soundVolumes[(int)SE_NAME::SIZE] = {
	0.3,//DECISION
	0.3 //CURSOR
};

/*
enum class SE_NAME {
	DECISION,
	CURSOR,
	SIZE,
};
*/
void GeneralSoundEffects::initialize() {
	audios.push_back(new Audio(U"resources/musics/items/general/decision.wav"));
	audios.push_back(new Audio(U"resources/musics/items/general/cursor.wav"));
}
void GeneralSoundEffects::finalize() {
	for (auto& audio : audios) {
		delete audio;
	}
}
void GeneralSoundEffects::play(SE_NAME se_name) {
	audios.at((int)se_name)->setPosSec(0);
	audios.at((int)se_name)->setVolume(soundVolumes[(int)se_name]);
	audios.at((int)se_name)->play();
}