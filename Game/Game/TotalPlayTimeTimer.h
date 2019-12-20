#pragma once
#include <Siv3D.hpp>
//総プレイ時間を数えるためのストップウォッチ
class TotalPlayTimeTimer {
private:
	static Stopwatch stopwatch;//ストップウォッチ
public:
	TotalPlayTimeTimer() = delete;
	//ストップウォッチを開始・再開する
	static void start() {
		stopwatch.start();
	}
	//ストップウォッチを開始する
	static void restart() {
		stopwatch.restart();
	}
	//ストップウォッチを一時停止する
	static void pause() {
		stopwatch.pause();
	}
	//秒数を64bit整数で返す
	static int64 getSecond() {
		return stopwatch.s64();
	}
};