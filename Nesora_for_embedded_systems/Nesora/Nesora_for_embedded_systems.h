#pragma once

// Copyright (c) MucchoSP
//🐹

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <vector>


// +--------------------------------------------------------------------------------------------+
// |	音諳コード関係																			|
// +--------------------------------------------------------------------------------------------+


//音諳コードの定数群
// 
//NS[平仮名文字]
// 
//で使うことができます。

//母音
#define NSNULL			0x00			//音諳コードNULL・終端文字

//追記:諸事情により削除されました。


// +--------------------------------------------------------------------------------------------+
// |	ここから下は、ローマ字の定数です。														|
// |	NS[ローマ字]で使うことができます。														|
// |	コンパイラーによっては平仮名使えないからね。											|
// |	後、上のやつとは関連付けされてないから、コード変えたいなら両方変えてね☆				|
// +--------------------------------------------------------------------------------------------+


//母音
#define NSNUL			0x00			//音諳コードNULL・終端文字
#define NSa				0x01			//音諳コードあ
#define NSi				0x02			//音諳コードい
#define NSya			0x03			//音諳コードや
#define NSyu			0x04			//音諳コードゆ
#define NSye			0x05			//音諳コードいぇ
#define NSyo			0x06			//音諳コードよ
#define NSu				0x07			//音諳コードう
#define NSwa			0x08			//音諳コードわ
#define NSwi			0x09			//音諳コードゐ
#define NSwe			0x0a			//音諳コードゑ
#define NSwo			0x0b			//音諳コードを
#define NSe				0x0c			//音諳コードえ
#define NSo				0x0d			//音諳コードお
#define NS_0e			0x0e			//音諳コード未定義
#define NS_0f			0x0f			//音諳コード未定義

//破裂音
#define NSk				0x10			//音諳コードk
#define NSka			0x11			//音諳コードか
#define NSki			0x12			//音諳コードき
#define NSkya			0x13			//音諳コードきゃ
#define NSkyu			0x14			//音諳コードきゅ
#define NSkye			0x15			//音諳コードきぇ
#define NSkyo			0x16			//音諳コードきょ
#define NSku			0x17			//音諳コードく
#define NSkwa			0x18			//音諳コードくゎ
#define NSkwi			0x19			//音諳コードくぃ
#define NSkwe			0x1a			//音諳コードくぇ
#define NSkwo			0x1b			//音諳コードくぉ
#define NSke			0x1c			//音諳コードけ
#define NSko			0x1d			//音諳コードこ
#define NS_1e			0x1e			//音諳コード未定義
#define NS_1f			0x1f			//音諳コード未定義

#define NSg				0x20			//音諳コードg
#define NSga			0x21			//音諳コードが
#define NSgi			0x22			//音諳コードぎ
#define NSgya			0x23			//音諳コードぎゃ
#define NSgyu			0x24			//音諳コードぎゅ
#define NSgye			0x25			//音諳コードぎぇ
#define NSgyo			0x26			//音諳コードぎょ
#define NSgu			0x27			//音諳コードぐ
#define NSgwa			0x28			//音諳コードぐゎ
#define NSgwi			0x29			//音諳コードぐぃ
#define NSgwe			0x2a			//音諳コードぐぇ
#define NSgwo			0x2b			//音諳コードぐぉ
#define NSge			0x2c			//音諳コードげ
#define NSgo			0x2d			//音諳コードご
#define NS_2e			0x2e			//音諳コード未定義
#define NS_2f			0x2f			//音諳コード未定義

#define NSt				0x30			//音諳コードt
#define NSta			0x31			//音諳コードた
#define NSti			0x32			//音諳コードち
#define NStya			0x33			//音諳コードちゃ
#define NStyu			0x34			//音諳コードちゅ
#define NStye			0x35			//音諳コードちぇ
#define NStyo			0x36			//音諳コードちょ
#define NSchi			NSti			//音諳コードち
#define NScha			NStya			//音諳コードちゃ
#define NSchu			NStyu			//音諳コードちゅ
#define NSche			NStye			//音諳コードちぇ
#define NScho			NStyo			//音諳コードちょ
#define NStu			0x37			//音諳コードつ
#define NStwa			0x38			//音諳コードつゎ
#define NStwi			0x39			//音諳コードつぃ
#define NStwe			0x3a			//音諳コードつぇ
#define NStwo			0x3b			//音諳コードつぉ
#define NStsu			NStu			//音諳コードつ
#define NStsa			NStwa			//音諳コードつゎ
#define NStsi			NStwi			//音諳コードつぃ
#define NStse			NStwe			//音諳コードつぇ
#define NStso			NStwo			//音諳コードつぉ
#define NSte			0x3c			//音諳コードて
#define NSto			0x3d			//音諳コードと
#define NS_3e			0x3e			//音諳コード未定義
#define NS_3f			0x3f			//音諳コード未定義

#define NSd				0x40			//音諳コードd
#define NSda			0x41			//音諳コードだ
#define NSdi			0x42			//音諳コードぢ
#define NSdya			0x43			//音諳コードぢゃ
#define NSdyu			0x44			//音諳コードぢゅ
#define NSdye			0x45			//音諳コードぢぇ
#define NSdyo			0x46			//音諳コードぢょ
#define NSdu			0x47			//音諳コードづ
#define NSdwa			0x48			//音諳コードづゎ
#define NSdwi			0x49			//音諳コードづぃ
#define NSdwe			0x4a			//音諳コードづぇ
#define NSdwo			0x4b			//音諳コードづぉ
#define NSde			0x4c			//音諳コードで
#define NSdo			0x4d			//音諳コードど
#define NS_4e			0x4e			//音諳コード未定義
#define NS_4f			0x4f			//音諳コード未定義

#define NSp				0x50			//音諳コードp
#define NSpa			0x51			//音諳コードぱ
#define NSpi			0x52			//音諳コードぴ
#define NSpya			0x53			//音諳コードぴゃ
#define NSpyu			0x54			//音諳コードぴゅ
#define NSpye			0x55			//音諳コードぴぇ
#define NSpyo			0x56			//音諳コードぴょ
#define NSpu			0x57			//音諳コードぷ
#define NSpwa			0x58			//音諳コードぷゎ
#define NSpwi			0x59			//音諳コードぷぃ
#define NSpwe			0x5a			//音諳コードぷぇ
#define NSpwo			0x5b			//音諳コードぷぉ
#define NSpe			0x5c			//音諳コードぺ
#define NSpo			0x5d			//音諳コードぽ
#define NS_5e			0x5e			//音諳コード未定義
#define NS_5f			0x5f			//音諳コード未定義

#define NSb				0x60			//音諳コードb
#define NSba			0x61			//音諳コードば
#define NSbi			0x62			//音諳コードび
#define NSbya			0x63			//音諳コードびゃ
#define NSbyu			0x64			//音諳コードびゅ
#define NSbye			0x65			//音諳コードびぇ
#define NSbyo			0x66			//音諳コードびょ
#define NSbu			0x67			//音諳コードぶ
#define NSbwa			0x68			//音諳コードぶゎ
#define NSbwi			0x69			//音諳コードぶぃ
#define NSbwe			0x6a			//音諳コードぶぇ
#define NSbwo			0x6b			//音諳コードぶぉ
#define NSbe			0x6c			//音諳コードべ
#define NSbo			0x6d			//音諳コードぼ
#define NS_6e			0x6e			//音諳コード未定義
#define NS_6f			0x6f			//音諳コード未定義

//摩擦音
#define NSs				0x70			//音諳コードs
#define NSsa			0x71			//音諳コードさ
#define NSsi			0x72			//音諳コードし
#define NSsya			0x73			//音諳コードしゃ
#define NSsyu			0x74			//音諳コードしゅ
#define NSsye			0x75			//音諳コードしぇ
#define NSsyo			0x76			//音諳コードしょ
#define NSshi			NSsi			//音諳コードし
#define NSsha			NSsya			//音諳コードしゃ
#define NSshu			NSsyu			//音諳コードしゅ
#define NSshe			NSsye			//音諳コードしぇ
#define NSsho			NSsyo			//音諳コードしょ
#define NSsu			0x77			//音諳コードす
#define NSswa			0x78			//音諳コードすゎ
#define NSswi			0x79			//音諳コードすぃ
#define NSswe			0x7a			//音諳コードすぇ
#define NSswo			0x7b			//音諳コードすぉ
#define NSse			0x7c			//音諳コードせ
#define NSso			0x7d			//音諳コードそ
#define NS_7e			0x7e			//音諳コード未定義
#define NS_7f			0x7f			//音諳コード未定義

#define NSz				0x80			//音諳コードz
#define NSza			0x81			//音諳コードざ
#define NSzi			0x82			//音諳コードじ
#define NSzya			0x83			//音諳コードじゃ
#define NSzyu			0x84			//音諳コードじゅ
#define NSzye			0x85			//音諳コードじぇ
#define NSzyo			0x86			//音諳コードじょ
#define NSji			NSzi			//音諳コードじ
#define NSja			NSzya			//音諳コードじゃ
#define NSju			NSzyu			//音諳コードじゅ
#define NSje			NSzye			//音諳コードじぇ
#define NSjo			NSzyo			//音諳コードじょ
#define NSzu			0x87			//音諳コードず
#define NSzwa			0x88			//音諳コードずゎ
#define NSzwi			0x89			//音諳コードずぃ
#define NSzwe			0x8a			//音諳コードずぇ
#define NSzwo			0x8b			//音諳コードずぉ
#define NSze			0x8c			//音諳コードぜ
#define NSzo			0x8d			//音諳コードぞ
#define NS_8e			0x8e			//音諳コード未定義
#define NS_8f			0x8f			//音諳コード未定義

#define NSh				0x90			//音諳コードh
#define NSha			0x91			//音諳コードは
#define NShi			0x92			//音諳コードひ
#define NShya			0x93			//音諳コードひゃ
#define NShyu			0x94			//音諳コードひゅ
#define NShye			0x95			//音諳コードひぇ
#define NShyo			0x96			//音諳コードひょ
#define NShu			0x97			//音諳コードふ
#define NShwa			0x98			//音諳コードふゎ
#define NShwi			0x99			//音諳コードふぃ
#define NShwe			0x9a			//音諳コードふぇ
#define NShwo			0x9b			//音諳コードふぉ
#define NSfu			NShu			//音諳コードふ
#define NSfa			NShwa			//音諳コードふゎ
#define NSfi			NShwi			//音諳コードふぃ
#define NSfe			NShwe			//音諳コードふぇ
#define NSfo			NShwo			//音諳コードふぉ
#define NShe			0x9c			//音諳コードへ
#define NSho			0x9d			//音諳コードほ
#define NS_9e			0x9e			//音諳コード未定義
#define NS_9f			0x9f			//音諳コード未定義

//鼻音
#define NSn				0xa0			//音諳コードn
#define NSna			0xa1			//音諳コードな
#define NSni			0xa2			//音諳コードに
#define NSnya			0xa3			//音諳コードにゃ
#define NSnyu			0xa4			//音諳コードにゅ
#define NSnye			0xa5			//音諳コードにぇ
#define NSnyo			0xa6			//音諳コードにょ
#define NSnu			0xa7			//音諳コードぬ
#define NSnwa			0xa8			//音諳コードぬゎ
#define NSnwi			0xa9			//音諳コードぬぃ
#define NSnwe			0xaa			//音諳コードぬぇ
#define NSnwo			0xab			//音諳コードぬぉ
#define NSne			0xac			//音諳コードね
#define NSno			0xad			//音諳コードの
#define NS_ae			0xae			//音諳コード未定義
#define NS_af			0xaf			//音諳コード未定義

#define NSm				0xb0			//音諳コードm
#define NSma			0xb1			//音諳コードま
#define NSmi			0xb2			//音諳コードみ
#define NSmya			0xb3			//音諳コードみゃ
#define NSmyu			0xb4			//音諳コードみゅ
#define NSmye			0xb5			//音諳コードみぇ
#define NSmyo			0xb6			//音諳コードみょ
#define NSmu			0xb7			//音諳コードむ
#define NSmwa			0xb8			//音諳コードむゎ
#define NSmwi			0xb9			//音諳コードむぃ
#define NSmwe			0xba			//音諳コードむぇ
#define NSmwo			0xbb			//音諳コードむぉ
#define NSme			0xbc			//音諳コードめ
#define NSmo			0xbd			//音諳コードも
#define NS_be			0xbe			//音諳コード未定義
#define NS_bf			0xbf			//音諳コード未定義

//はじき音
#define NSr				0xc0			//音諳コードr
#define NSra			0xc1			//音諳コードら
#define NSri			0xc2			//音諳コードり
#define NSrya			0xc3			//音諳コードりゃ
#define NSryu			0xc4			//音諳コードりゅ
#define NSrye			0xc5			//音諳コードりぇ
#define NSryo			0xc6			//音諳コードりょ
#define NSru			0xc7			//音諳コードる
#define NSrwa			0xc8			//音諳コードるゎ
#define NSrwi			0xc9			//音諳コードるぃ
#define NSrwe			0xca			//音諳コードるぇ
#define NSrwo			0xcb			//音諳コードるぉ
#define NSre			0xcc			//音諳コードれ
#define NSro			0xcd			//音諳コードろ
#define NS_ce			0xce			//音諳コード未定義
#define NS_cf			0xcf			//音諳コード未定義

//ん
#define NSnn			0xd0			//音諳コードnn
#define NSnn1			0xd1			//音諳コードん1
#define NSnn2			0xd2			//音諳コードん2
#define NS_d3			0xd3			//音諳コード未定義
#define NS_d4			0xd4			//音諳コード未定義
#define NS_d5			0xd5			//音諳コード未定義
#define NS_d6			0xd6			//音諳コード未定義
#define NS_d7			0xd7			//音諳コード未定義
#define NS_d8			0xd8			//音諳コード未定義
#define NS_d9			0xd9			//音諳コード未定義
#define NS_da			0xda			//音諳コード未定義
#define NS_db			0xdb			//音諳コード未定義
#define NS_dc			0xdc			//音諳コード未定義
#define NS_dd			0xdd			//音諳コード未定義
#define NS_de			0xde			//音諳コード未定義
#define NS_df			0xdf			//音諳コード未定義

//その他
#define NS_e0			0xe0			//音諳コード未定義
#define NSspc			0xe1			//音諳コード空白
#define NSvls			0xe2			//音諳コード息継
#define NS_e3			0xe3			//音諳コード未定義
#define NS_e4			0xe4			//音諳コード未定義
#define NS_e5			0xe5			//音諳コード未定義
#define NS_e6			0xe6			//音諳コード未定義
#define NS_e7			0xe7			//音諳コード未定義
#define NS_e8			0xe8			//音諳コード未定義
#define NS_e9			0xe9			//音諳コード未定義
#define NS_ea			0xea			//音諳コード未定義
#define NS_eb			0xeb			//音諳コード未定義
#define NS_ec			0xec			//音諳コード未定義
#define NS_ed			0xed			//音諳コード未定義
#define NS_ee			0xee			//音諳コード未定義
#define NS_ef			0xef			//音諳コード未定義

#define NS_f0			0xf0			//音諳コード未定義
#define NSp1			0xf1			//音諳コード拗+1
#define NSp2			0xf2			//音諳コード拗+2
#define NSp3			0xf3			//音諳コード拗+3
#define NSp4			0xf4			//音諳コード拗+4
#define NStt			0xf5			//音諳コード促音
#define NS_f6			0xf6			//音諳コード未定義
#define NS_f7			0xf7			//音諳コード未定義
#define NS_f8			0xf8			//音諳コード未定義
#define NS_f9			0xf9			//音諳コード未定義
#define NS_fa			0xfa			//音諳コード未定義
#define NS_fb			0xfb			//音諳コード未定義
#define NS_fc			0xfc			//音諳コード未定義
#define NS_fd			0xfd			//音諳コード未定義
#define NS_fe			0xfe			//音諳コード未定義
#define NS_ff			0xff			//音諳コード未定義


#define NSDATAINIT_P	0				//音諳データのピッチの初期値
#define NSDATAINIT_T	25				//音諳データの速さの初期値


typedef float nsfloat;

typedef unsigned char NSCHAR;							//音諳コード用の変数
typedef NSCHAR* NSSTRING;								//音諳コードの文字列用の変数

// 音諳の声のデータ構造体
// 
// 一文字9byte
// 
// 原稿用紙(400字)300枚 = 120,000文字で
// 1.08Mbyte
// 
typedef struct NSCHARDATA {

	uint32_t time;										//全体での時間(0.01秒)(0~4,294,967,295)
	uint16_t ctime;										//文字の時間(0.01秒)(0~65,535)
	NSCHAR c;											//文字(0~255)
	int16_t pitch;										//Hz単位でのピッチ(Hz)(-32,768~32,767)

} NSCHARDATA;

typedef NSCHARDATA* NSSTRINGDATA;						//NSCHARDATAの配列


//音諳コード関係
namespace nsc {

	//---- エンコード関係 ----

	//音諳書式で書かれたマルチバイト文字列を音諳コードにエンコード
	NSSTRINGDATA nsstrencode(const char* str);
	//音諳書式で書かれたマルチバイト文字列を音諳コードにエンコード
	NSSTRINGDATA nsstrencode(const unsigned char* str);
	//shift-jisの上位ビット0x82を音諳コードにエンコード
	NSCHAR nscharencode(unsigned char c);

	//音諳書式で書かれたローマ字文字列を音諳コードにエンコード
	NSSTRINGDATA nsromajiencode(const char* str);
	//音諳書式で書かれたローマ字文字列を音諳コードにエンコード
	NSSTRINGDATA nsromajiencode(const unsigned char* str);

	//----- デコード関数 -----

	const char* nsstrdecode(NSSTRINGDATA str);
	const char* nsstrdecode(NSSTRING str);
	const char* nschardecode(NSCHAR c);

	//NSSTRINGDATA型の変数をコピー
	void nsstrcpy(NSSTRINGDATA destination, const NSSTRINGDATA source);

	//NSCHARDATA型の変数を作成
	NSCHARDATA nscreateCharData(uint32_t time, uint16_t ctime, NSCHAR c, int16_t pitch);

	size_t nsstrlen(NSSTRINGDATA str);
	size_t nsstrlen(NSSTRING str);
	size_t nsstrlen(const unsigned char* str);

};

//音諳文字列型
class NSString {

	size_t n_size;										//データサイズ
	size_t n_capacity;									//最大データサイズ
	size_t n_wsize;										//文字数
	size_t n_wcapacity;									//最大文字数
	NSSTRINGDATA n_string;								//文字列

public:

	NSString();
	NSString(const char* c);
	NSString(const NSSTRING c);
	NSString(const NSSTRINGDATA c);
	NSString(const NSString& s);
	//デストラクタ
	~NSString();
	//演算子
	NSCHARDATA& operator [](const size_t n);
	const NSCHARDATA& operator [](const size_t n) const;
	NSString operator +(const char* c);
	NSString operator +(const NSString& str);
	NSString& operator +=(const char* c);
	NSString& operator +=(const NSString& str);
	//メンバ関数
	bool empty() const;
	size_t size() const;
	size_t length() const;
	size_t capacity() const;
	const NSCHARDATA& front() const;
	const NSCHARDATA& back() const;
	NSCHARDATA& front();
	NSCHARDATA& back();
	const char* c_str() const;
	size_t alltime() const;

};



//	+-------------------------------------------------------------------------------------------+
//	|	音諳零号機																				|
//	+-------------------------------------------------------------------------------------------+



#define SMPL		44100										//サンプリング周波数
#define TRANSTIME	5											//?
#define MAXFREQ		20000										//最大周波数
#define PI			3.141592653589793238462643					//円周率
#define DB			1.0											//wavファイルの上限、下限
#define MAXTEXTS	65536										//最大文字列

#define BIT 8													//wavファイル作成用
#define FILTERWIDTH 1000										//フィルターの幅(フォルマント周波数からどの範囲までを通すか)

#define GETSIZE(a)  (sizeof(a)/sizeof(a[0]))					//変数のサイズを取得
#define POW2(a)     ((a) * (a))									//二乗
#define MAX(a,b)    (((a)<(b))?(b):(a))							//どちらが大きいか
#define MIN(a,b)    (((a)<(b))?(a):(b))							//どっちが小さいか

#define unprocessed	0											//処理なし

#define TESTPLAYVOISEFILENAME		"NesoraTestVoiseFromMvff.wav"	//生成したwavファイルの標準の名前

#define GEMINATE_CONSONANT_SPEED	2							//「っ」の長さ
#define GEMINATE_CONSONANT_TMAG		1.5							//「っ」のあとの長さの倍率
#define MAXSHIONSPEED				4410						//子音の長さ
#define MAXBYOUONSPEED				2200						//拗音の前の母音の長さ
#define MAXYOUONSPEED				2200						//拗音の長さ
#define SEMIVOWELSPEED				882							//声の後半の変化するところの長さ
#define PLOSIVESPEED				220							//破裂音の長さ
#define PLOSIVEPOWER				2							//破裂音の強さ
#define NASALSPEED					331							//鼻音の長さ
#define TAPSPEED					331							//はじき音の長さ
#define FRICATIVENOISESCOPE			50							//摩擦音の雑音の範囲
#define FRICATIVENOISEACC			200							//摩擦音の雑音の精度
#define PLOSIVEPOWER				2							//摩殺音の強さ
#define CTIME						4410						//特定の長さの音を切り取るときの前後の余白

#define SPACE						0xd3						//空白
#define SPARETIME					441000						//予備時間
#define CHANGETIMEMAGN				0.01 * SMPL					//時間の比率

struct FriKILLive {
	std::vector<nsfloat> Hz, s;
	size_t size;
};


class mainMakeVoiseF {
public:

	int makeSinWave(int num, std::vector<nsfloat> Hz, std::vector<nsfloat> s, std::vector<nsfloat>& out, nsfloat a = 0.0, bool doformant = true);	//リストから合成されたsin波を生成
	int makeSinha(nsfloat Hz, nsfloat s, std::vector<nsfloat>& out);													//単純なsin波を生成

	int makeHarmonicOvertone(nsfloat bf);																			//基本倍音設定
	int setFormants(nsfloat F1, nsfloat F2, nsfloat F3, nsfloat F4);													//フォルマントリストに周波数を設定
	int makeFilter();																								//基本倍音の大きさを自動生成
	int makeSinWaveFromClass(std::vector<nsfloat>& out, nsfloat a = 0.0);												//クラス内のパラメータからsin波を合成

	nsfloat makeMomentSinWave(int num, std::vector<nsfloat> Hz, std::vector<nsfloat> s, int gets);												//特定の時間の周波数を取得
	nsfloat makeMomentSinWaveFromClass(int t);																		//クラス内のパラメータから特定の時間の周波数を取得


	nsfloat mostMax(std::vector<nsfloat> list);																	//配列内の最も大きい値を返す関数

	int hipassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat q);				//ハイパスフィルター
	int lowpassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat q);				//ローパスフィルター
	int notchpassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat bw);			//ノッチパスフィルター

	int getstate(int state);																						//現在のmainMakeVoiseF.cppの状態を取得する。
	int setSoftness(nsfloat sn);																						//softness変数を変更
private:

	int fsize = 4, hosize = 0;																						//フォルマントの数、倍音の数
	std::vector<nsfloat> formants = { 0.0,0.0,0.0,0.0 }, harmonicOvertones = { 0.0 }, harmonictoneFilters = { 0.0 };	//データ配列
	nsfloat bf = 0;																									//基底周波数
	nsfloat softness = 0;																							//柔らかさ

};


class makeVoiseFromFile {
public:

	int setDefaulFurin();																							//音諳 風鈴を使う
	int setShion();																									//音諳 詞音を使う

	//新
	int textread(const char* text);																					//音諳書式で書かれた文章を読み込み
	std::vector<nsfloat> textreading();																				//textreadで読み込んだ文章を読み上げ

	int loadFromChar(char* data);																					//文字列からデータを読み込み

	nsfloat getPrivatebf();																							//データ保管庫から基音データを読み込む
	nsfloat getPrivatebFormant(int b, int f);																		//データ保管庫からフォルマントデータを読み込む

	int decodeVoise0(unsigned char* data);																					//零号機のデータを読み込む
	int decodeVoise2(unsigned char* data);																					//零号機のデータを読み込む

private:

	int makeWhitenoise(std::vector<nsfloat> out, int time, nsfloat hz, nsfloat um);									//ホワイトノイズを作成
	int makeWhitenoise1(std::vector<nsfloat> out, int time, nsfloat hz);												//ホワイトノイズを作成

	int hipassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat q);				//ハイパスフィルター
	int lowpassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat q);				//ローパスフィルター
	int notchpassFilter(std::vector<nsfloat> input, std::vector<nsfloat>& out, nsfloat samplerate, nsfloat freq, nsfloat bw);			//ノッチパスフィルター

	nsfloat privatebf = 0, privateFormant[5][4] = { 0 };																//makeVoiseFromFileのデータ保管庫
	nsfloat allmojiFormant[2][16][16][4] = { 0 };																	//文字のフォルマントの保管庫
	nsfloat softness = 0;																							//柔らかさの保管庫

	int createAllMojiFromantFromClass();																			//privateFormantからallmojiFormantを作成
	nsfloat getMojiFormant(int f, int moji, int formant);															//allmojiFormantからフォルマントを取得

	bool doVoiselessPlosive(NSCHAR moji);																			//無声破裂音
	bool doVoisedPlosive(NSCHAR moji);																				//有声破裂音
	bool doNasal(NSCHAR moji);																						//鼻音
	bool doTap(NSCHAR moji);																						//はじき音
	bool doVoiselessFricative(NSCHAR moji);																			//無声摩擦音
	bool doVoisedFricative(NSCHAR moji);																			//有声摩擦音
	bool doFriKILLive(NSCHAR moji);																					//摩殺音

	int ftInit(int size);																							//破擦音の角度の初期化
	nsfloat* ft;																										//破擦音の角度の保管庫

	int getTimeFromSpeed(char speed, char moji = 0x00);																//音諳形式の時間単位から声の長さ[秒]へ変換

	//新
	NSString pstringdata = NSString();																				//読み上げ用のデータ保管庫

	time_t nextplaytime = 0;

	//音諳合成関数群

	void textreadingHanboin(std::vector<nsfloat>& out, NSCHAR nowmoji, nsfloat pitch, int targettime);
	void textreadingHaretuon(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, nsfloat pitch, int targettime);
	void textreadingYuuseiHaretuon(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, nsfloat pitch, int targettime, bool select = true);
	void textreadingMasatuon(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, nsfloat pitch, int targettime);
	void textreadingYuuseiMasatuon(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, nsfloat pitch, int targettime);
	void textreadingMASATUON(std::vector<nsfloat>& out, NSCHAR nowmoji, nsfloat pitch, int targettime);
	void textreadingBion(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, NSCHAR oldmoji, nsfloat pitch, int targettime);
	void textreadingHajikion(std::vector<nsfloat>& out, NSCHAR nowmoji1, NSCHAR nowmoji2, NSCHAR oldmoji, nsfloat pitch, int targettime);

	void textreadingBoin1(std::vector<nsfloat>& out, NSCHAR nowmoji, nsfloat pitch, int targettime);
	void textreadingBoin2(std::vector<nsfloat>& out, NSCHAR nowmoji, NSCHAR nextmoji, nsfloat pitch, nsfloat nextpitch, int targettime);

};

