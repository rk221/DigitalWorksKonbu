#include "Gacha.h"

Gacha::Gacha(void) {
	FontAsset::Register(U"gachafont", 70);
	FontAsset::Preload(U"gachafont");
	TextureAsset::Register(U"gachaback", U"resources/images/backs/gacha.jpg", AssetParameter::LoadAsync());

	//変数の初期化
	button[(int)BUTTON::GACHA] = new MyImageButton(U"resources/images/items/gahca/gachabutton", U"", 30, 300, 600);
	button[(int)BUTTON::EXIT] = new MyImageButton(U"resources/images/items/gahca/exitbutton", U"", 30, 1700, 600);
	selectedButton = BUTTON::GACHA;

	nowGachaing = false;
}

Gacha::~Gacha(void) {
	FontAsset::Unregister(U"gachafont");
	TextureAsset::Unregister(U"gachaback");
	for (int i = 0; i < (int)BUTTON::SIZE; i++) {
		delete button[i];
	}
	delete backAudio;
}

bool Gacha::isReady(void) {
	if (TextureAsset::IsReady(U"gachaback")) {
		for (int i = 0; i < (int)BUTTON::SIZE; i++) {
			if (!button[i]->isReady()) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void Gacha::start(void) {
	delete backAudio;
	backAudio = new Audio(U"resources/musics/backs/gacha.wav");
	backAudio->setLoop(true);
	backAudio->play();
}


void Gacha::update(void) {
	if (nowGachaing) {//現在ガチャ中かどうか

	}
	else {
		if (MyKey::getDecisionKey()) {
			switch (selectedButton)
			{
			case Gacha::BUTTON::GACHA:

				break;
			case Gacha::BUTTON::EXIT:

				break;
			}
		}
		selectedMove();//選択の移動処理,
	}
}

void Gacha::draw(void) {
	//背景の描画
	TextureAsset(U"gachaback").draw();
	switch (selectedButton)
	{
	case Gacha::BUTTON::GACHA:
		button[(int)BUTTON::GACHA]->drawNotWord(true);
		button[(int)BUTTON::EXIT]->drawNotWord();
		break;
	case Gacha::BUTTON::EXIT:
		button[(int)BUTTON::GACHA]->drawNotWord();
		button[(int)BUTTON::EXIT]->drawNotWord(true);
		break;
	}
}

void Gacha::selectedMove() {//現在選択されているものの更新処理
	if (MyKey::getRightKeyDown()) {
		selectedButton = BUTTON::GACHA;
	}
	if (MyKey::getLeftKeyDown()) {
		selectedButton = BUTTON::EXIT;
	}
}