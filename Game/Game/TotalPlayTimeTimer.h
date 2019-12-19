#pragma once
#include <Siv3D.hpp>
//���v���C���Ԃ𐔂��邽�߂̃X�g�b�v�E�H�b�`
class TotalPlayTimeTimer {
private:
	static Stopwatch stopwatch;//�X�g�b�v�E�H�b�`
public:
	TotalPlayTimeTimer() = delete;
	//�X�g�b�v�E�H�b�`���J�n�E�ĊJ����
	static void start() {
		stopwatch.start();
	}
	//�X�g�b�v�E�H�b�`���J�n����
	static void restart() {
		stopwatch.restart();
	}
	//�X�g�b�v�E�H�b�`���ꎞ��~����
	static void pause() {
		stopwatch.pause();
	}
	//�b����64bit�����ŕԂ�
	static int64 getSecond() {
		return stopwatch.s64();
	}
};