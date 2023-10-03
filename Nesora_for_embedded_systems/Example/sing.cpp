#include "../Nesora/Nesora_for_embedded_systems.h"

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

int main() {
	// 声の本体となるインスタンスです。
	// ここに声のデータや台本のデータ、声の生成に使うクラスのインスタンスなんかが入っています。
	// 詳細は同ディレクトリにあるspeak.cppを参照。
	makeVoiseFromFile MVFF;
	MVFF.setDefaulFurin();


	// ここに喋らせたい文章を入力します。
	// ひらがなを使う場合、shift-jisを使ってください。
	// shift-jisが使えない場合は、Encoder_for_Nesora.hpp 内のｴｲﾔｰできる関数を使う(非推奨)か
	// ローマ字で入力してください。
	//
	// ここでは、音諳の台本の文法である「音諳書式」について説明します。
	// とはいっても難しいことはなく、基本的にxmlみたいなものです。
	// 
	// 基本的に平仮名(あるいはローマ字)で書かれた台本の文字と文字の間にタグを挟むイメージです。
	// タグは以下の二つ
	// <s> ...速さの制御
	// <p> ...高さの制御
	// 
	// 速さの制御
	// <sxx>のxxの部分に時間を指定してあげると、それ以降、一文字をその長さで話すようになります。単位は[cs](センチ秒 = 0.01s)
	// <s20>とすれば、それ以降、一文字を0.2秒の長さでしゃべるようになります。
	// 初期値は0.25秒です。(<s25>)
	// 
	// 高さの制御
	// <p±xx>の±xx部分に、相対的な周波数値を符号付きで入力することで声の高さを変えることができます。単位は[Hz]、基準値は使っている声の基底周波数です。
	// 基底周波数は声によって異なり、風鈴の場合440Hz(A4)、詞音の場合392Hz(G4)です。
	// 風鈴を使っている場合、<p+54>で494Hz(B4)、<p-48>で392Hz(G4)になります。
	// 初期値は+0Hzです。(<p+0>)
	// 
	// これらのタグを使って台本を作ることになります。
	// 
	// 
	// 日本語かローマ字かは自動で判定されます。具体的には、文字列中に二バイト文字のひらがな(0x82)が含まれていればひらがな、含まれていなければローマ字でエンコードを行います。
	// ひらがなとローマ字を混合させることはできません。
	// 日本語を使う場合はひらがなしか使ってはならず、ローマ字を使う場合は英数字しか使ってはなりません。
	// 
	// 日本語が含まれている場合、「、」で一文字分の休符、「。」で二文字分の休符になります。
	// ローマ字で書かれている場合には、「,」で一文字分の休符、「.」で二文字分の休符になります。
	// 
	// 半角括弧()で囲まれた部分はコメントになり、実際の読み上げ時には反映されません。しかし、日本語かローマ字かの判定には引っかかるので、そこは注意してください。
	// 
	
	//MVFF.textread("(茶摘　文部省唱歌　尋常小学校唱歌　三学年用)(一番)<s60>、<p-48>な<p+83>つ<p+147>も<s90><p+219>ち<s30>か<s60>づく<s90><p+344>は<s30>ち<s60>じゅ<p+219>う<p+147>は<p+83>ち<p+147>や、、<p+344>のに<p+219>も<s90><p+147>や<s30>ま<s60><p+83>に<p+0>も<s90><p+219>わ<s30>か<s60><p+147>ば<p+83>が<p+0>しげ<p-48>る、、あ<p+83>れ<p+147>に<s90><p+219>み<s30>え<s60>るわ<s90><p+344>ちゃ<s30>つ<s60>み<p+219>じゃ<p+147>な<p+83>い<p+147>か、、<p+344>あか<p+219>ね<s90><p+147>だ<s30>す<s60><p+83>き<p+0>に<p-48>す<p+83>げ<s90><p+147>の<s30><p+219>か<s180><p+83>さ<s60>、、(二番)<p-48>ひ<p+83>よ<p+147>り<s90><p+219>つ<s30>づ<s60>きの<s90><p+344>きょ<s30>う<s60>こ<p+219>の<p+147>ご<p+83>ろ<p+147>を、、<p+344>ここ<p+219>ろ<s90><p+147>の<s30>ど<s60><p+83>か<p+0>に<s90><p+219>つ<s30>み<s60><p+147>つ<p+83>つ<p+0>うた<p-48>う、、つ<p+83>め<p+147>よ<s90><p+219>つ<s30>め<s60>つめ<s90><p+344>つ<s30>ま<s60>ね<p+219>ば<p+147>な<p+83>ら<p+147>ぬ、、<p+344>つま<p+219>にゃ<s90><p+147>に<s30>ほ<s60><p+83>ん<p+0>の<p-48>ちゃ<p+83>に<s90><p+147>な<s30><p+219>ら<s180><p+83>ぬ<s60>、");
	MVFF.textread("(Chatumi - Monbusho shoka for third year of elementary school)(1)<s60>,<p-48>Na<p+83>tu<p+147>mo<s90><p+219>ti<s30>ka<s60>duku<s90><p+344>ha<s30>ti<s60>zu<p+219>u<p+147>ha<p+83>ti<p+147>ya,,<p+344>noni<p+219>mo<s90><p+147>ya<s30>ma<s60><p+83>ni<p+0>mo<s90><p+219>wa<s30>ka<s60><p+147>ba<p+83>ga<p+0>sige<p-48>ru,,a<p+83>re<p+147>ni<s90><p+219>mi<s30>e<s60>ruwa<s90><p+344>tya<s30>tu<s60>mi<p+219>zya<p+147>na<p+83>i<p+147>ka,,<p+344>aka<p+219>ne<s90><p+147>da<s30>su<s60><p+83>ki<p+0>ni<p-48>su<p+83>ge<s90><p+147>no<s30><p+219>ka<s180><p+83>sa<s60>,,(2)<p-48>hi<p+83>yo<p+147>ri<s90><p+219>tu<s30>du<s60>kino<s90><p+344>kyo<s30>u<s60>ko<p+219>no<p+147>go<p+83>ro<p+147>wo,,<p+344>koko<p+219>ro<s90><p+147>no<s30>do<s60><p+83>ka<p+0>ni<s90><p+219>tu<s30>mi<s60><p+147>tu<p+83>tu<p+0>uta<p-48>u,,tu<p+83>me<p+147>yo<s90><p+219>tu<s30>me<s60>tume<s90><p+344>tu<s30>ma<s60>ne<p+219>ba<p+147>na<p+83>ra<p+147>nu,,<p+344>tuma<p+219>nya<s90><p+147>ni<s30>ho<s60><p+83>nn<p+0>no<p-48>tya<p+83>ni<s90><p+147>na<s30><p+219>ra<s180><p+83>nu<s60>,");


	std::vector<nsfloat> wave = MVFF.textreading();
	NesoraWave("NesoraWave.wav", wave);

	return 0;
}

//
// 技術者用メモ
// 
// 以下のプロセッサで1分16秒の音声を生成するのに約3秒かかりました。
// 
// Intel(R) Core(TM) i7-10700K CPU @ 3.80GHz   3.79 GHz
// 
// 使用したメモリは約20MByteです。
// 
// 
// OSは以下の通り
// 
// エディション			Windows 10 Home
// バージョン			22H2
// インストール日		令和3年3月31日
// OS ビルド			19045.3448
// エクスペリエンス		Windows Feature Experience Pack 1000.19044.1000.0
// 
// 
// デバッグには以下のソフトウエアを使用しました。
// 
// Microsoft Visual Studio Community 2019
// Version 16.11.26
// VisualStudio.16.Release / 16.11.26 + 33529.622
// Microsoft.NET Framework
// Version 4.8.04084
// 
// Microsoft Visual C++ 2019
//
// 構成は以下の通りです。
//
// 構成:Release
// プラットフォーム:Win32
// 
