#include "../Nesora/Nesora_for_embedded_systems.h"
#include "../Nesora/Number_to_Nesora.hpp"

// Copyright (c) MucchoSP

// PC用のテスト用の関数です。🐹
inline int NesoraWave(std::string filename, std::vector<nsfloat> wave) {
	std::ofstream file(filename, std::ios::out | std::ios::binary);
	if (!file) return 1;

	const int smpl = SMPL;

	size_t waveChankSize = 4 + 24 + (wave.size() * sizeof(nsfloat) + 8);
	file.write("RIFF", 4);
	file.write((char*)&(waveChankSize), 4);

	// 4byte
	file.write("WAVE", 4);

	// 24 bytes
	int work = 0;
	file.write("fmt ", 4);											//fmt
	file.write((char*)&(work = 16), 4);								//size
	file.write((char*)&(work = 3), 2);								//format(32bit float)
	file.write((char*)&(work = 1), 2);								//channel(monaural)
	file.write((char*)&(work = smpl), 4);								//sampling frequency
	file.write((char*)&(work = smpl * sizeof(nsfloat)), 4);	//bytes per sec
	file.write((char*)&(work = sizeof(nsfloat)), 2);				//block size
	file.write((char*)&(work = sizeof(nsfloat) * 8), 2);			//bits per sample

	// wave.mainWave.size() * sizeof(nsfloat) + 8 bytes
	file.write("data", 4);
	file.write((char*)&(work = wave.size() * sizeof(nsfloat)), 4);	//size
	nsfloat* out = new nsfloat[wave.size()];
	nsfloat* workout = out;
	for (auto workWave : wave)
		*workout++ = workWave;
	file.write((char*)out, static_cast<std::streamsize>(wave.size()) * sizeof(nsfloat));

	file.close();
}

int ___main() {
	// 声の本体となるインスタンスです。
	// ここに声のデータや台本のデータ、声の生成に使うクラスのインスタンスなんかが入っています。
	// 詳細は同ディレクトリにあるspeak.cppを参照。
	makeVoiseFromFile MVFF;
	MVFF.setDefaulFurin();
	

	// ここに喋らせたい文章を入力します。
	// ひらがなを使う場合、shift-jisを使ってください。
	// shift-jisが使えない場合は、Encoder_for_Nesora.hpp 内のｴｲﾔｰできる関数を使う(非推奨)かローマ字で入力してください。
	// 詳細は同ディレクトリにあるsing.cppを参照。
	MVFF.textread(number_to_Nesora((float)0.0056).c_str());


	std::vector<nsfloat> wave = MVFF.textreading();
	NesoraWave("NesoraWave.wav", wave);

	return 0;
}
