#include "../Nesora/Nesora_for_embedded_systems.h"
#include "../Nesora/Normalization_to_Nesora.h"


#include <fstream>
#include <iostream>


// Copyright (c) MucchoSP

// PC用のテスト用の関数です。
inline int NesoraWave(std::string filename, std::vector<nsfloat> wave) {
	std::ofstream file(filename, std::ios::out | std::ios::binary);
	if (!file) return 1;

	const int smpl = Nesora::SMPL;

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

int main() {

	// --------------------------------------------------------------------------------------------------------------------------------------------------------
	// 声の本体となるインスタンスです。
	// ここに声のデータや台本のデータ、声の生成に使うクラスのインスタンスなんかが入っています。
	Nesora::makeVoiseFromFile MVFF;


	// --------------------------------------------------------------------------------------------------------------------------------------------------------
	// この関数で声を初期化できます。
	// 音諳は、様々な声を使えるように声をパラメータとして持つように設計されており、
	// windows版ではファイルとして読み込みますが、組み込み用なのでこれで声を初期化してください。
	// 声の追加はいつかやります。

	//音諳 風鈴
	//ちょっとミクっぽい声
	MVFF.setDefaulFurin();

	//音諳 詞音
	//ちょっとレイっぽい声
	//MVFF.setShion();
	


	// --------------------------------------------------------------------------------------------------------------------------------------------------------
	// ここに喋らせたい文章を入力します。
	// ひらがなを使う場合は、Normalization_to_Nesora::hiraganaToRomaji()を使って、UTF-8で渡してください。
	// 例:MVFF.textread(Normalization_to_Nesora::hiraganaToRomaji(u8"こんにちわあ"));
	//
	// 
	// ここからは、音諳の台本の文法である「音諳書式」について説明します。
	// とはいっても難しいことはなく、だいたいxmlみたいなものです。
	// 
	// 基本的にローマ字(あるいは平仮名)で書かれた台本の文字と文字の間にタグを入れるイメージです。
	// タグは以下の二つ
	// <s> ...速さの制御
	// <p> ...高さの制御
	// 
	// 速さの制御
	// <sxx>のxxの部分に時間を指定してあげると、それ以降、一文字をその長さで話すようになります。単位は[cs](センチ秒 = 0.01s)
	// <s20>とすれば、それ以降、一文字を0.20秒の長さでしゃべるようになります。
	// 初期値は0.25秒です。(<s25>)
	// 
	// 高さの制御
	// <p±xx>の±xx部分に、相対的な周波数値を符号付きで入力することで声の高さを変えることができます。単位は[Hz]、基準値は使っている声の基底周波数です。
	// 基底周波数は声によって異なり、風鈴の場合440Hz(A4)、詞音の場合392Hz(G4)です。
	// 風鈴を使っている場合、<p+54>で494Hz(B4)、<p-48>で392Hz(G4)になります。
	// 初期値は+0Hzです。(<p440>)
	// 
	// 
	// ---以下追記---
	// 
	// 高さの制御に新しい機能が付きました。
	// まず、読ませたい文章の最初に<bf>タグを挿入します。<bf>タグには、使っている声の基底周波数を渡す機能があります。
	// <bf440>で風鈴、<bf392>で詞音の基底周波数になります。
	// 
	// そして、このタグを使った後では、高さの制御を絶対的な周波数値を入力できるようになります。絶対的な周波数で入力するには、<p>タグの符号をなくします。
	// 以下の例では、どちらも262Hz(C4)の音で「あ」といいます。
	// 
	// 風鈴の声で "<bf440><p262>a"
	// 詞音の声で "<bf392><p262>a"
	// 
	// 上の例は、それぞれ以下のようにしたものと同義です。
	// 
	// 風鈴の声で "<p-178>a"
	// 詞音の声で "<p-130>a"
	// 
	// このタグがあることで、歌声の変更が比較的簡単になります。
	// 茶摘みの歌で使っているので、見てみてください。
	// 
	// ---追記ここまで---
	// 
	// 
	// これらのタグを使って台本を作ることになります。
	// 
	// 
	// ひらがなを使っている場合、「、」で一文字分の休符、「。」で二文字分の休符になります。
	// ローマ字で書かれている場合には、「,」で一文字分の休符、「.」で二文字分の休符になります。
	// 
	// 半角括弧()で囲まれた部分はコメントになり、実際の読み上げ時には反映されません。
	// 
	// また、数字を読ませたい場合、Normalization_to_Nesora::number_to_Nesora()が使えます。
	// 
	// 以下、例です。試したいものをコメントアウトして試してみてください。
	
	// 茶摘みの歌
	MVFF.textread("(Chatumi - Monbusho shoka for third year of elementary school)(1)<bf440><s60>,<p392>Na<p523>tu<p587>mo<s90><p659>ti<s30>ka<s60>duku<s90><p784>ha<s30>ti<s60>zu<p659>u<p587>ha<p523>ti<p587>ya,,<p784>noni<p659>mo<s90><p587>ya<s30>ma<s60><p523>ni<p440>mo<s90><p659>wa<s30>ka<s60><p587>ba<p523>ga<p440>sige<p392>ru,,a<p523>re<p587>ni<s90><p659>mi<s30>e<s60>ruwa<s90><p784>tya<s30>tu<s60>mi<p659>zya<p587>na<p523>i<p587>ka,,<p784>aka<p659>ne<s90><p587>da<s30>su<s60><p523>ki<p440>ni<p392>su<p523>ge<s90><p587>no<s30><p659>ka<s180><p523>sa<s60>,,(2)<p392>hi<p523>yo<p587>ri<s90><p659>tu<s30>du<s60>kino<s90><p784>kyo<s30>u<s60>ko<p659>no<p587>go<p523>ro<p587>wo,,<p784>koko<p659>ro<s90><p587>no<s30>do<s60><p523>ka<p440>ni<s90><p659>tu<s30>mi<s60><p587>tu<p523>tu<p440>uta<p392>u,,tu<p523>me<p587>yo<s90><p659>tu<s30>me<s60>tume<s90><p784>tu<s30>ma<s60>ne<p659>ba<p587>na<p523>ra<p587>nu,,<p784>tuma<p659>nya<s90><p587>ni<s30>ho<s60><p523>nn<p440>no<p392>tya<p523>ni<s90><p587>na<s30><p659>ra<s180><p523>nu<s60>,");
	
	// 数字の読み上げ
	//MVFF.textread(("<s17>," + Normalization_to_Nesora::number_to_Nesora("234567890123456789012345678901234567890123456789012345678901234567890") + ".").c_str());
	
	// 数字の読み上げ(符号、小数、分数、10の指数)
	//MVFF.textread(("<s15>," + Normalization_to_Nesora::number_to_Nesora("1.2345e9/-2.0e8") + ".").c_str());
	
	// UTF-8を使った単位の読み上げ
	//MVFF.textread(Normalization_to_Nesora::hiraganaToRomaji(u8"<s12>," + Normalization_to_Nesora::number_to_Nesora("0.1") + u8"㎌" + Normalization_to_Nesora::number_to_Nesora("50") + u8"㌾のコンデンサ.").c_str());
	


	// --------------------------------------------------------------------------------------------------------------------------------------------------------
	// これで実際に生成された波形を取得できます。
	// -1.0~1.0の範囲で出力されますので、煮るなり焼くなりしてください。
	// なお、標本化周波数は44100Hzです。
	// ほかの周波数を使いたい場合、ヘッダーファイルの下の方にある"SMPL"という定数を変えることで変更可能です。(たしか)
	std::vector<nsfloat> wave = MVFF.textreading();


	// --------------------------------------------------------------------------------------------------------------------------------------------------------
	// wav.ファイルに出力する関数です。
	// windowsの方用。
	// しれっといますが、音諳の一部ではありません。
	// 定義はこのファイルの上の方にいます。
	NesoraWave("NesoraWave.wav", wave);

	return 0;
}


