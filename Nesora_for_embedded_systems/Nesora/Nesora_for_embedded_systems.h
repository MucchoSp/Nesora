#pragma once

// Copyright (c) MucchoSP

#ifndef NESORA_H
#define NESORA_H

#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>


//音諳で使う浮動小数点数型の定義
//「doubleやlong doubleを使って音諳の計算精度をよくしてやるぜ!!」ってやりたい奴はここを変えれば一発です。
using nsfloat = float;

namespace Nesora {

	// +--------------------------------------------------------------------------------------------+
	// |	音諳コード関係																			|
	// +--------------------------------------------------------------------------------------------+

	using nschar = uint8_t;							//音諳コード用の変数
	using nsstring = nschar*;						//音諳コードの文字列用の変数


	//音諳コードの定数群
	// 
	//NS[平仮名文字]
	// 
	//で使うことができます。

	//母音
	constexpr nschar NSNULL = 0x00;			//音諳コードNULL・終端文字

	//追記:諸事情により削除されました。


	// +--------------------------------------------------------------------------------------------+
	// |	ここから下は、ローマ字の定数です。														|
	// |	NS[ローマ字]で使うことができます。														|
	// |	コンパイラーによっては平仮名使えないからね。											|
	// |	後、上のやつとは関連付けされてないから、コード変えたいなら両方変えてね☆				|
	// +--------------------------------------------------------------------------------------------+


	//母音
	constexpr nschar NSNUL = 0x00;			//音諳コードNULL・終端文字
	constexpr nschar NSa = 0x01;			//音諳コードあ
	constexpr nschar NSi = 0x02;			//音諳コードい
	constexpr nschar NSya = 0x03;			//音諳コードや
	constexpr nschar NSyu = 0x04;			//音諳コードゆ
	constexpr nschar NSye = 0x05;			//音諳コードいぇ
	constexpr nschar NSyo = 0x06;			//音諳コードよ
	constexpr nschar NSu = 0x07;			//音諳コードう
	constexpr nschar NSwa = 0x08;			//音諳コードわ
	constexpr nschar NSwi = 0x09;			//音諳コードゐ
	constexpr nschar NSwe = 0x0a;			//音諳コードゑ
	constexpr nschar NSwo = 0x0b;			//音諳コードを
	constexpr nschar NSe = 0x0c;			//音諳コードえ
	constexpr nschar NSo = 0x0d;			//音諳コードお
	constexpr nschar NS_0e = 0x0e;			//音諳コード未定義
	constexpr nschar NS_0f = 0x0f;			//音諳コード未定義

	//破裂音
	constexpr nschar NSk = 0x10;			//音諳コードk
	constexpr nschar NSka = 0x11;			//音諳コードか
	constexpr nschar NSki = 0x12;			//音諳コードき
	constexpr nschar NSkya = 0x13;			//音諳コードきゃ
	constexpr nschar NSkyu = 0x14;			//音諳コードきゅ
	constexpr nschar NSkye = 0x15;			//音諳コードきぇ
	constexpr nschar NSkyo = 0x16;			//音諳コードきょ
	constexpr nschar NSku = 0x17;			//音諳コードく
	constexpr nschar NSkwa = 0x18;			//音諳コードくゎ
	constexpr nschar NSkwi = 0x19;			//音諳コードくぃ
	constexpr nschar NSkwe = 0x1a;			//音諳コードくぇ
	constexpr nschar NSkwo = 0x1b;			//音諳コードくぉ
	constexpr nschar NSke = 0x1c;			//音諳コードけ
	constexpr nschar NSko = 0x1d;			//音諳コードこ
	constexpr nschar NS_1e = 0x1e;			//音諳コード未定義
	constexpr nschar NS_1f = 0x1f;			//音諳コード未定義

	constexpr nschar NSg = 0x20;			//音諳コードg
	constexpr nschar NSga = 0x21;			//音諳コードが
	constexpr nschar NSgi = 0x22;			//音諳コードぎ
	constexpr nschar NSgya = 0x23;			//音諳コードぎゃ
	constexpr nschar NSgyu = 0x24;			//音諳コードぎゅ
	constexpr nschar NSgye = 0x25;			//音諳コードぎぇ
	constexpr nschar NSgyo = 0x26;			//音諳コードぎょ
	constexpr nschar NSgu = 0x27;			//音諳コードぐ
	constexpr nschar NSgwa = 0x28;			//音諳コードぐゎ
	constexpr nschar NSgwi = 0x29;			//音諳コードぐぃ
	constexpr nschar NSgwe = 0x2a;			//音諳コードぐぇ
	constexpr nschar NSgwo = 0x2b;			//音諳コードぐぉ
	constexpr nschar NSge = 0x2c;			//音諳コードげ
	constexpr nschar NSgo = 0x2d;			//音諳コードご
	constexpr nschar NS_2e = 0x2e;			//音諳コード未定義
	constexpr nschar NS_2f = 0x2f;			//音諳コード未定義

	constexpr nschar NSt = 0x30;			//音諳コードt
	constexpr nschar NSta = 0x31;			//音諳コードた
	constexpr nschar NSti = 0x32;			//音諳コードち
	constexpr nschar NStya = 0x33;			//音諳コードちゃ
	constexpr nschar NStyu = 0x34;			//音諳コードちゅ
	constexpr nschar NStye = 0x35;			//音諳コードちぇ
	constexpr nschar NStyo = 0x36;			//音諳コードちょ
	constexpr nschar NSchi = NSti;			//音諳コードち
	constexpr nschar NScha = NStya;		//音諳コードちゃ
	constexpr nschar NSchu = NStyu;		//音諳コードちゅ
	constexpr nschar NSche = NStye;		//音諳コードちぇ
	constexpr nschar NScho = NStyo;		//音諳コードちょ
	constexpr nschar NStu = 0x37;			//音諳コードつ
	constexpr nschar NStwa = 0x38;			//音諳コードつゎ
	constexpr nschar NStwi = 0x39;			//音諳コードつぃ
	constexpr nschar NStwe = 0x3a;			//音諳コードつぇ
	constexpr nschar NStwo = 0x3b;			//音諳コードつぉ
	constexpr nschar NStsu = NStu;			//音諳コードつ
	constexpr nschar NStsa = NStwa;		//音諳コードつゎ
	constexpr nschar NStsi = NStwi;		//音諳コードつぃ
	constexpr nschar NStse = NStwe;		//音諳コードつぇ
	constexpr nschar NStso = NStwo;		//音諳コードつぉ
	constexpr nschar NSte = 0x3c;			//音諳コードて
	constexpr nschar NSto = 0x3d;			//音諳コードと
	constexpr nschar NS_3e = 0x3e;			//音諳コード未定義
	constexpr nschar NS_3f = 0x3f;			//音諳コード未定義

	constexpr nschar NSd = 0x40;			//音諳コードd
	constexpr nschar NSda = 0x41;			//音諳コードだ
	constexpr nschar NSdi = 0x42;			//音諳コードぢ
	constexpr nschar NSdya = 0x43;			//音諳コードぢゃ
	constexpr nschar NSdyu = 0x44;			//音諳コードぢゅ
	constexpr nschar NSdye = 0x45;			//音諳コードぢぇ
	constexpr nschar NSdyo = 0x46;			//音諳コードぢょ
	constexpr nschar NSdu = 0x47;			//音諳コードづ
	constexpr nschar NSdwa = 0x48;			//音諳コードづゎ
	constexpr nschar NSdwi = 0x49;			//音諳コードづぃ
	constexpr nschar NSdwe = 0x4a;			//音諳コードづぇ
	constexpr nschar NSdwo = 0x4b;			//音諳コードづぉ
	constexpr nschar NSde = 0x4c;			//音諳コードで
	constexpr nschar NSdo = 0x4d;			//音諳コードど
	constexpr nschar NS_4e = 0x4e;			//音諳コード未定義
	constexpr nschar NS_4f = 0x4f;			//音諳コード未定義

	constexpr nschar NSp = 0x50;			//音諳コードp
	constexpr nschar NSpa = 0x51;			//音諳コードぱ
	constexpr nschar NSpi = 0x52;			//音諳コードぴ
	constexpr nschar NSpya = 0x53;			//音諳コードぴゃ
	constexpr nschar NSpyu = 0x54;			//音諳コードぴゅ
	constexpr nschar NSpye = 0x55;			//音諳コードぴぇ
	constexpr nschar NSpyo = 0x56;			//音諳コードぴょ
	constexpr nschar NSpu = 0x57;			//音諳コードぷ
	constexpr nschar NSpwa = 0x58;			//音諳コードぷゎ
	constexpr nschar NSpwi = 0x59;			//音諳コードぷぃ
	constexpr nschar NSpwe = 0x5a;			//音諳コードぷぇ
	constexpr nschar NSpwo = 0x5b;			//音諳コードぷぉ
	constexpr nschar NSpe = 0x5c;			//音諳コードぺ
	constexpr nschar NSpo = 0x5d;			//音諳コードぽ
	constexpr nschar NS_5e = 0x5e;			//音諳コード未定義
	constexpr nschar NS_5f = 0x5f;			//音諳コード未定義

	constexpr nschar NSb = 0x60;			//音諳コードb
	constexpr nschar NSba = 0x61;			//音諳コードば
	constexpr nschar NSbi = 0x62;			//音諳コードび
	constexpr nschar NSbya = 0x63;			//音諳コードびゃ
	constexpr nschar NSbyu = 0x64;			//音諳コードびゅ
	constexpr nschar NSbye = 0x65;			//音諳コードびぇ
	constexpr nschar NSbyo = 0x66;			//音諳コードびょ
	constexpr nschar NSbu = 0x67;			//音諳コードぶ
	constexpr nschar NSbwa = 0x68;			//音諳コードぶゎ
	constexpr nschar NSbwi = 0x69;			//音諳コードぶぃ
	constexpr nschar NSbwe = 0x6a;			//音諳コードぶぇ
	constexpr nschar NSbwo = 0x6b;			//音諳コードぶぉ
	constexpr nschar NSbe = 0x6c;			//音諳コードべ
	constexpr nschar NSbo = 0x6d;			//音諳コードぼ
	constexpr nschar NS_6e = 0x6e;			//音諳コード未定義
	constexpr nschar NS_6f = 0x6f;			//音諳コード未定義

	//摩擦音
	constexpr nschar NSs = 0x70;			//音諳コードs
	constexpr nschar NSsa = 0x71;			//音諳コードさ
	constexpr nschar NSsi = 0x72;			//音諳コードし
	constexpr nschar NSsya = 0x73;			//音諳コードしゃ
	constexpr nschar NSsyu = 0x74;			//音諳コードしゅ
	constexpr nschar NSsye = 0x75;			//音諳コードしぇ
	constexpr nschar NSsyo = 0x76;			//音諳コードしょ
	constexpr nschar NSshi = NSsi;			//音諳コードし
	constexpr nschar NSsha = NSsya;		//音諳コードしゃ
	constexpr nschar NSshu = NSsyu;		//音諳コードしゅ
	constexpr nschar NSshe = NSsye;		//音諳コードしぇ
	constexpr nschar NSsho = NSsyo;		//音諳コードしょ
	constexpr nschar NSsu = 0x77;			//音諳コードす
	constexpr nschar NSswa = 0x78;			//音諳コードすゎ
	constexpr nschar NSswi = 0x79;			//音諳コードすぃ
	constexpr nschar NSswe = 0x7a;			//音諳コードすぇ
	constexpr nschar NSswo = 0x7b;			//音諳コードすぉ
	constexpr nschar NSse = 0x7c;			//音諳コードせ
	constexpr nschar NSso = 0x7d;			//音諳コードそ
	constexpr nschar NS_7e = 0x7e;			//音諳コード未定義
	constexpr nschar NS_7f = 0x7f;			//音諳コード未定義

	constexpr nschar NSz = 0x80;			//音諳コードz
	constexpr nschar NSza = 0x81;			//音諳コードざ
	constexpr nschar NSzi = 0x82;			//音諳コードじ
	constexpr nschar NSzya = 0x83;			//音諳コードじゃ
	constexpr nschar NSzyu = 0x84;			//音諳コードじゅ
	constexpr nschar NSzye = 0x85;			//音諳コードじぇ
	constexpr nschar NSzyo = 0x86;			//音諳コードじょ
	constexpr nschar NSji = NSzi;			//音諳コードじ
	constexpr nschar NSja = NSzya;			//音諳コードじゃ
	constexpr nschar NSju = NSzyu;			//音諳コードじゅ
	constexpr nschar NSje = NSzye;			//音諳コードじぇ
	constexpr nschar NSjo = NSzyo;			//音諳コードじょ
	constexpr nschar NSzu = 0x87;			//音諳コードず
	constexpr nschar NSzwa = 0x88;			//音諳コードずゎ
	constexpr nschar NSzwi = 0x89;			//音諳コードずぃ
	constexpr nschar NSzwe = 0x8a;			//音諳コードずぇ
	constexpr nschar NSzwo = 0x8b;			//音諳コードずぉ
	constexpr nschar NSze = 0x8c;			//音諳コードぜ
	constexpr nschar NSzo = 0x8d;			//音諳コードぞ
	constexpr nschar NS_8e = 0x8e;			//音諳コード未定義
	constexpr nschar NS_8f = 0x8f;			//音諳コード未定義

	constexpr nschar NSh = 0x90;			//音諳コードh
	constexpr nschar NSha = 0x91;			//音諳コードは
	constexpr nschar NShi = 0x92;			//音諳コードひ
	constexpr nschar NShya = 0x93;			//音諳コードひゃ
	constexpr nschar NShyu = 0x94;			//音諳コードひゅ
	constexpr nschar NShye = 0x95;			//音諳コードひぇ
	constexpr nschar NShyo = 0x96;			//音諳コードひょ
	constexpr nschar NShu = 0x97;			//音諳コードふ
	constexpr nschar NShwa = 0x98;			//音諳コードふゎ
	constexpr nschar NShwi = 0x99;			//音諳コードふぃ
	constexpr nschar NShwe = 0x9a;			//音諳コードふぇ
	constexpr nschar NShwo = 0x9b;			//音諳コードふぉ
	constexpr nschar NSfu = NShu;			//音諳コードふ
	constexpr nschar NSfa = NShwa;			//音諳コードふゎ
	constexpr nschar NSfi = NShwi;			//音諳コードふぃ
	constexpr nschar NSfe = NShwe;			//音諳コードふぇ
	constexpr nschar NSfo = NShwo;			//音諳コードふぉ
	constexpr nschar NShe = 0x9c;			//音諳コードへ
	constexpr nschar NSho = 0x9d;			//音諳コードほ
	constexpr nschar NS_9e = 0x9e;			//音諳コード未定義
	constexpr nschar NS_9f = 0x9f;			//音諳コード未定義

	//鼻音
	constexpr nschar NSn = 0xa0;			//音諳コードn
	constexpr nschar NSna = 0xa1;			//音諳コードな
	constexpr nschar NSni = 0xa2;			//音諳コードに
	constexpr nschar NSnya = 0xa3;			//音諳コードにゃ
	constexpr nschar NSnyu = 0xa4;			//音諳コードにゅ
	constexpr nschar NSnye = 0xa5;			//音諳コードにぇ
	constexpr nschar NSnyo = 0xa6;			//音諳コードにょ
	constexpr nschar NSnu = 0xa7;			//音諳コードぬ
	constexpr nschar NSnwa = 0xa8;			//音諳コードぬゎ
	constexpr nschar NSnwi = 0xa9;			//音諳コードぬぃ
	constexpr nschar NSnwe = 0xaa;			//音諳コードぬぇ
	constexpr nschar NSnwo = 0xab;			//音諳コードぬぉ
	constexpr nschar NSne = 0xac;			//音諳コードね
	constexpr nschar NSno = 0xad;			//音諳コードの
	constexpr nschar NS_ae = 0xae;			//音諳コード未定義
	constexpr nschar NS_af = 0xaf;			//音諳コード未定義

	constexpr nschar NSm = 0xb0;			//音諳コードm
	constexpr nschar NSma = 0xb1;			//音諳コードま
	constexpr nschar NSmi = 0xb2;			//音諳コードみ
	constexpr nschar NSmya = 0xb3;			//音諳コードみゃ
	constexpr nschar NSmyu = 0xb4;			//音諳コードみゅ
	constexpr nschar NSmye = 0xb5;			//音諳コードみぇ
	constexpr nschar NSmyo = 0xb6;			//音諳コードみょ
	constexpr nschar NSmu = 0xb7;			//音諳コードむ
	constexpr nschar NSmwa = 0xb8;			//音諳コードむゎ
	constexpr nschar NSmwi = 0xb9;			//音諳コードむぃ
	constexpr nschar NSmwe = 0xba;			//音諳コードむぇ
	constexpr nschar NSmwo = 0xbb;			//音諳コードむぉ
	constexpr nschar NSme = 0xbc;			//音諳コードめ
	constexpr nschar NSmo = 0xbd;			//音諳コードも
	constexpr nschar NS_be = 0xbe;			//音諳コード未定義
	constexpr nschar NS_bf = 0xbf;			//音諳コード未定義

	//はじき音
	constexpr nschar NSr = 0xc0;			//音諳コードr
	constexpr nschar NSra = 0xc1;			//音諳コードら
	constexpr nschar NSri = 0xc2;			//音諳コードり
	constexpr nschar NSrya = 0xc3;			//音諳コードりゃ
	constexpr nschar NSryu = 0xc4;			//音諳コードりゅ
	constexpr nschar NSrye = 0xc5;			//音諳コードりぇ
	constexpr nschar NSryo = 0xc6;			//音諳コードりょ
	constexpr nschar NSru = 0xc7;			//音諳コードる
	constexpr nschar NSrwa = 0xc8;			//音諳コードるゎ
	constexpr nschar NSrwi = 0xc9;			//音諳コードるぃ
	constexpr nschar NSrwe = 0xca;			//音諳コードるぇ
	constexpr nschar NSrwo = 0xcb;			//音諳コードるぉ
	constexpr nschar NSre = 0xcc;			//音諳コードれ
	constexpr nschar NSro = 0xcd;			//音諳コードろ
	constexpr nschar NS_ce = 0xce;			//音諳コード未定義
	constexpr nschar NS_cf = 0xcf;			//音諳コード未定義

	//ん
	constexpr nschar NSnn = 0xd0;			//音諳コードnn
	constexpr nschar NSnn1 = 0xd1;			//音諳コードん1
	constexpr nschar NSnn2 = 0xd2;			//音諳コードん2
	constexpr nschar NS_d3 = 0xd3;			//音諳コード未定義
	constexpr nschar NS_d4 = 0xd4;			//音諳コード未定義
	constexpr nschar NS_d5 = 0xd5;			//音諳コード未定義
	constexpr nschar NS_d6 = 0xd6;			//音諳コード未定義
	constexpr nschar NS_d7 = 0xd7;			//音諳コード未定義
	constexpr nschar NS_d8 = 0xd8;			//音諳コード未定義
	constexpr nschar NS_d9 = 0xd9;			//音諳コード未定義
	constexpr nschar NS_da = 0xda;			//音諳コード未定義
	constexpr nschar NS_db = 0xdb;			//音諳コード未定義
	constexpr nschar NS_dc = 0xdc;			//音諳コード未定義
	constexpr nschar NS_dd = 0xdd;			//音諳コード未定義
	constexpr nschar NS_de = 0xde;			//音諳コード未定義
	constexpr nschar NS_df = 0xdf;			//音諳コード未定義

	//その他
	constexpr nschar NS_e0 = 0xe0;			//音諳コード未定義
	constexpr nschar NSspc = 0xe1;			//音諳コード空白
	constexpr nschar NSvls = 0xe2;			//音諳コード息継
	constexpr nschar NS_e3 = 0xe3;			//音諳コード未定義
	constexpr nschar NS_e4 = 0xe4;			//音諳コード未定義
	constexpr nschar NS_e5 = 0xe5;			//音諳コード未定義
	constexpr nschar NS_e6 = 0xe6;			//音諳コード未定義
	constexpr nschar NS_e7 = 0xe7;			//音諳コード未定義
	constexpr nschar NS_e8 = 0xe8;			//音諳コード未定義
	constexpr nschar NS_e9 = 0xe9;			//音諳コード未定義
	constexpr nschar NS_ea = 0xea;			//音諳コード未定義
	constexpr nschar NS_eb = 0xeb;			//音諳コード未定義
	constexpr nschar NS_ec = 0xec;			//音諳コード未定義
	constexpr nschar NS_ed = 0xed;			//音諳コード未定義
	constexpr nschar NS_ee = 0xee;			//音諳コード未定義
	constexpr nschar NS_ef = 0xef;			//音諳コード未定義

	constexpr nschar NS_f0 = 0xf0;			//音諳コード未定義
	constexpr nschar NSp1 = 0xf1;			//音諳コード拗+1
	constexpr nschar NSp2 = 0xf2;			//音諳コード拗+2
	constexpr nschar NSp3 = 0xf3;			//音諳コード拗+3
	constexpr nschar NSp4 = 0xf4;			//音諳コード拗+4
	constexpr nschar NStt = 0xf5;			//音諳コード促音
	constexpr nschar NS_f6 = 0xf6;			//音諳コード未定義
	constexpr nschar NS_f7 = 0xf7;			//音諳コード未定義
	constexpr nschar NS_f8 = 0xf8;			//音諳コード未定義
	constexpr nschar NS_f9 = 0xf9;			//音諳コード未定義
	constexpr nschar NS_fa = 0xfa;			//音諳コード未定義
	constexpr nschar NS_fb = 0xfb;			//音諳コード未定義
	constexpr nschar NS_fc = 0xfc;			//音諳コード未定義
	constexpr nschar NS_fd = 0xfd;			//音諳コード未定義
	constexpr nschar NS_fe = 0xfe;			//音諳コード未定義
	constexpr nschar NS_ff = 0xff;			//音諳コード未定義


	constexpr nschar NSDATAINIT_P = 0;				//音諳データのピッチの初期値
	constexpr nschar NSDATAINIT_T = 25;			//音諳データの速さの初期値


	// 音諳の声のデータ構造体
	// 
	// 一文字9byte
	// 
	// 原稿用紙(400字)300枚 = 120,000文字で
	// 1.08Mbyte
	// 
	typedef struct nscharData {

		uint32_t time;										//全体での時間(0.01秒)(0~4,294,967,295)
		uint16_t ctime;										//文字の時間(0.01秒)(0~65,535)
		nschar c;											//文字(0~255)
		int16_t pitch;										//Hz単位でのピッチ(Hz)(-32,768~32,767)

	} nscharData;

	using nsstringData = nscharData*;						//nscharDataの配列


	//音諳コード関係
	namespace nsc {

		//---- エンコード関係 ----

		//音諳書式で書かれたローマ字文字列を音諳コードにエンコード
		nsstringData nsromajiencode(const char* str);
		//音諳書式で書かれたローマ字文字列を音諳コードにエンコード
		nsstringData nsromajiencode(const unsigned char* str);

		//nsstringData型の変数をコピー
		void nsstrcpy(nsstringData destination, const nsstringData& source);

		//nscharData型の変数を作成
		nscharData nscreateCharData(uint32_t time, uint16_t ctime, nschar c, int16_t pitch);

		size_t nsstrlen(const nsstringData& str);
		size_t nsstrlen(const nsstring& str);
		size_t nsstrlen(const unsigned char* str);

	};

	//音諳文字列型
	class NSString {

		size_t n_size;										//データサイズ
		size_t n_capacity;									//最大データサイズ
		size_t n_wsize;										//文字数
		size_t n_wcapacity;									//最大文字数
		nsstringData n_string;								//文字列

	public:

		NSString();
		NSString(const char* c);
		NSString(const nsstring c);
		NSString(const nsstringData c);
		NSString(const NSString& s);
		//デストラクタ
		~NSString();
		//演算子
		nscharData& operator [](const size_t n);
		const nscharData& operator [](const size_t n) const;
		NSString operator +(const char* c);
		NSString operator +(const NSString& str);
		NSString& operator +=(const char* c);
		NSString& operator +=(const NSString& str);
		//メンバ関数
		bool empty() const;
		size_t size() const;
		size_t length() const;
		size_t capacity() const;
		const nscharData& front() const;
		const nscharData& back() const;
		nscharData& front();
		nscharData& back();
		size_t alltime() const;

	};



	//	+-------------------------------------------------------------------------------------------+
	//	|	音諳零号機																				|
	//	+-------------------------------------------------------------------------------------------+



	constexpr int SMPL = 44100;										//サンプリング周波数
	constexpr nsfloat SMPL_INV = 1.0 / 44100.0;						//サンプリング周波数
	constexpr int TRANSTIME = 5;									//?
	constexpr int MAXFREQ = 20000;									//最大周波数
	constexpr nsfloat DB = 1.0;										//wavファイルの上限、下限
	constexpr int MAXTEXTS = 65536;									//最大文字列

	constexpr int BIT = 8;											//wavファイル作成用
	constexpr int FILTERWIDTH = 1000;								//フィルターの幅(フォルマント周波数からどの範囲までを通すか)
	constexpr nsfloat FILTERWIDTH_INV = (nsfloat)(1.0 / FILTERWIDTH);

	//処理なし
	constexpr void unprocessed() {}

	//constexpr TESTPLAYVOISEFILENAME		"NesoraTestVoiseFromMvff.wav"	//生成したwavファイルの標準の名前

	//constexpr GEMINATE_CONSONANT_SPEED	2							//「っ」の長さ
	//constexpr GEMINATE_CONSONANT_TMAG		1.5							//「っ」のあとの長さの倍率
	constexpr int MAXSHIONSPEED = 4410 / 2;								//子音の長さ
	constexpr int MAXBYOUONSPEED = 2200;							//拗音の前の母音の長さ
	constexpr int MAXYOUONSPEED = 2200;								//拗音の長さ
	constexpr int SEMIVOWELSPEED = 882;								//声の後半の変化するところの長さ
	constexpr int PLOSIVESPEED = 220 * 2;								//破裂音の長さ
	constexpr nsfloat PLOSIVEPOWER = 1.0;							//破裂音の強さ
	constexpr int NASALSPEED = 331 * 2;									//鼻音の長さ
	constexpr int TAPSPEED = 331 * 2;									//はじき音の長さ
	constexpr int FRICATIVENOISESCOPE = 50;							//摩擦音の雑音の範囲
	constexpr nsfloat FRICATIVENOISEACC = 200;						//摩擦音の雑音の精度
	constexpr nsfloat FRICATIVEPOWER = 1.0;							//摩殺音の強さ
	constexpr int CTIME = 4410;										//特定の長さの音を切り取るときの前後の余白

	//constexpr SPACE			  0xd3								//空白
	//constexpr SPARETIME					441000					//予備時間
	constexpr int CHANGETIMEMAGN = (0.01 * SMPL);					//時間の比率

	struct FriKILLive {
		std::vector<nsfloat> Hz, s;
		size_t size;
	};


	class mainMakeVoiseF {
	public:

		int makeSinWave(int num, const std::vector<nsfloat>& Hz, const std::vector<nsfloat>& s, std::vector<nsfloat>& out, nsfloat a = 0.0, bool doformant = true);	//リストから合成されたsin波を生成
		int makeSinha(nsfloat Hz, nsfloat s, std::vector<nsfloat>& out);													//単純なsin波を生成

		int makeHarmonicOvertone(nsfloat bf);																			//基本倍音設定
		int setFormants(nsfloat F1, nsfloat F2, nsfloat F3, nsfloat F4);													//フォルマントリストに周波数を設定
		int makeFilter();																								//基本倍音の大きさを自動生成
		int makeSinWaveFromClass(std::vector<nsfloat>& out, nsfloat a = 0.0);												//クラス内のパラメータからsin波を合成

		nsfloat makeMomentSinWave(int num, const std::vector<nsfloat>& Hz, const std::vector<nsfloat>& s, int gets);												//特定の時間の周波数を取得
		nsfloat makeMomentSinWaveFromClass(int t);																		//クラス内のパラメータから特定の時間の周波数を取得


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

		bool doVoiselessPlosive(nschar moji);																			//無声破裂音
		bool doVoisedPlosive(nschar moji);																				//有声破裂音
		bool doNasal(nschar moji);																						//鼻音
		bool doTap(nschar moji);																						//はじき音
		bool doVoiselessFricative(nschar moji);																			//無声摩擦音
		bool doVoisedFricative(nschar moji);																			//有声摩擦音
		bool doFriKILLive(nschar moji);																					//摩殺音

		int ftInit(int size);																							//破擦音の角度の初期化
		nsfloat* ft;																										//破擦音の角度の保管庫

		int getTimeFromSpeed(char speed, char moji = 0x00);																//音諳形式の時間単位から声の長さ[秒]へ変換

		//新
		NSString pstringdata = NSString();																				//読み上げ用のデータ保管庫

		time_t nextplaytime = 0;

		nsfloat maxVolume = 1;

		//音諳合成関数群

		void textreadingHanboin(std::vector<nsfloat>& out, nschar nowmoji, nsfloat pitch, int targettime);
		void textreadingHaretuon(std::vector<nsfloat>& out, nschar nowmoji1, nschar nowmoji2, nsfloat pitch, int targettime);
		void textreadingYuuseiHaretuon(std::vector<nsfloat>& out, nschar nowmoji1, nschar nowmoji2, nsfloat pitch, int targettime, bool select = true);
		void textreadingMasatuon(std::vector<nsfloat>& out, nschar nowmoji1, nschar nowmoji2, nsfloat pitch, int targettime);
		void textreadingYuuseiMasatuon(std::vector<nsfloat>& out, nschar nowmoji1, nschar nowmoji2, nsfloat pitch, int targettime);
		void textreadingMASATUON(std::vector<nsfloat>& out, nschar nowmoji, nsfloat pitch, int targettime);
		void textreadingBion(std::vector<nsfloat>& out, nschar nowmoji1, nschar nowmoji2, nschar oldmoji, nsfloat pitch, int targettime);
		void textreadingHajikion(std::vector<nsfloat>& out, nschar nowmoji1, nschar nowmoji2, nschar oldmoji, nsfloat pitch, int targettime);

		void textreadingBoin1(std::vector<nsfloat>& out, nschar nowmoji, nsfloat pitch, int targettime);
		void textreadingBoin2(std::vector<nsfloat>& out, nschar nowmoji, nschar nextmoji, nsfloat pitch, nsfloat nextpitch, int targettime);

	};

	constexpr nsfloat PI = 3.141592653589793238462643;				//円周率
	constexpr nsfloat PI_INV = 1.0 / 3.141592653589793238462643;	//円周率の逆数

#ifndef NS_USE_STD_SIN//std::sin()を使うかnsSinTabl()を使うか。

#ifndef PROGMEM
#define PROGMEM //RP2040の場合、PROGMEMは配列をフラッシュメモリ側に持つということを示す。
#endif

	//標本化周波数44100Hzのサイン波(0からπ/2まで)
	const nsfloat sinTabel_44100[] PROGMEM = { 0,
0.000142476, 0.000284952, 0.000427428, 0.000569903, 0.000712379, 0.000854855, 0.000997331, 0.00113981, 0.00128228, 0.00142476, 0.00156723, 0.00170971, 0.00185219, 0.00199466, 0.00213714, 0.00227961, 0.00242209, 0.00256456, 0.00270704, 0.00284951, 0.00299199, 0.00313446, 0.00327694, 0.00341941, 0.00356189, 0.00370436, 0.00384684, 0.00398931, 0.00413179, 0.00427426, 0.00441674, 0.00455921, 0.00470169, 0.00484416, 0.00498663, 0.00512911, 0.00527158, 0.00541406, 0.00555653, 0.005699, 0.00584148, 0.00598395, 0.00612642, 0.0062689, 0.00641137, 0.00655384, 0.00669632, 0.00683879, 0.00698126, 0.00712373, 0.0072662, 0.00740868, 0.00755115, 0.00769362, 0.00783609, 0.00797856, 0.00812103, 0.00826351, 0.00840598, 0.00854845, 0.00869092, 0.00883339, 0.00897586, 0.00911833, 0.0092608, 0.00940327, 0.00954574, 0.00968821, 0.00983068, 0.00997314, 0.0101156, 0.0102581, 0.0104006, 0.010543, 0.0106855, 0.010828, 0.0109704, 0.0111129, 0.0112554, 0.0113978, 0.0115403, 0.0116828, 0.0118252, 0.0119677, 0.0121102, 0.0122526, 0.0123951, 0.0125375, 0.01268, 0.0128225, 0.0129649, 0.0131074, 0.0132499, 0.0133923, 0.0135348, 0.0136773, 0.0138197, 0.0139622, 0.0141046, 0.0142471,
0.0143896, 0.014532, 0.0146745, 0.0148169, 0.0149594, 0.0151019, 0.0152443, 0.0153868, 0.0155292, 0.0156717, 0.0158142, 0.0159566, 0.0160991, 0.0162415, 0.016384, 0.0165264, 0.0166689, 0.0168114, 0.0169538, 0.0170963, 0.0172387, 0.0173812, 0.0175236, 0.0176661, 0.0178085, 0.017951, 0.0180934, 0.0182359, 0.0183784, 0.0185208, 0.0186633, 0.0188057, 0.0189482, 0.0190906, 0.0192331, 0.0193755, 0.019518, 0.0196604, 0.0198029, 0.0199453, 0.0200877, 0.0202302, 0.0203726, 0.0205151, 0.0206575, 0.0208, 0.0209424, 0.0210849, 0.0212273, 0.0213698, 0.0215122, 0.0216546, 0.0217971, 0.0219395, 0.022082, 0.0222244, 0.0223668, 0.0225093, 0.0226517, 0.0227942, 0.0229366, 0.023079, 0.0232215, 0.0233639, 0.0235064, 0.0236488, 0.0237912, 0.0239337, 0.0240761, 0.0242185, 0.024361, 0.0245034, 0.0246458, 0.0247883, 0.0249307, 0.0250731, 0.0252156, 0.025358, 0.0255004, 0.0256428, 0.0257853, 0.0259277, 0.0260701, 0.0262126, 0.026355, 0.0264974, 0.0266398, 0.0267823, 0.0269247, 0.0270671, 0.0272095, 0.027352, 0.0274944, 0.0276368, 0.0277792, 0.0279216, 0.0280641, 0.0282065, 0.0283489, 0.0284913,
0.0286337, 0.0287762, 0.0289186, 0.029061, 0.0292034, 0.0293458, 0.0294882, 0.0296306, 0.0297731, 0.0299155, 0.0300579, 0.0302003, 0.0303427, 0.0304851, 0.0306275, 0.0307699, 0.0309123, 0.0310547, 0.0311972, 0.0313396, 0.031482, 0.0316244, 0.0317668, 0.0319092, 0.0320516, 0.032194, 0.0323364, 0.0324788, 0.0326212, 0.0327636, 0.032906, 0.0330484, 0.0331908, 0.0333332, 0.0334756, 0.033618, 0.0337604, 0.0339028, 0.0340452, 0.0341875, 0.0343299, 0.0344723, 0.0346147, 0.0347571, 0.0348995, 0.0350419, 0.0351843, 0.0353267, 0.035469, 0.0356114, 0.0357538, 0.0358962, 0.0360386, 0.036181, 0.0363234, 0.0364657, 0.0366081, 0.0367505, 0.0368929, 0.0370353, 0.0371776, 0.03732, 0.0374624, 0.0376048, 0.0377471, 0.0378895, 0.0380319, 0.0381743, 0.0383166, 0.038459, 0.0386014, 0.0387437, 0.0388861, 0.0390285, 0.0391708, 0.0393132, 0.0394556, 0.0395979, 0.0397403, 0.0398827, 0.040025, 0.0401674, 0.0403097, 0.0404521, 0.0405945, 0.0407368, 0.0408792, 0.0410215, 0.0411639, 0.0413062, 0.0414486, 0.041591, 0.0417333, 0.0418757, 0.042018, 0.0421604, 0.0423027, 0.0424451, 0.0425874, 0.0427297,
0.0428721, 0.0430144, 0.0431568, 0.0432991, 0.0434415, 0.0435838, 0.0437261, 0.0438685, 0.0440108, 0.0441532, 0.0442955, 0.0444378, 0.0445802, 0.0447225, 0.0448648, 0.0450072, 0.0451495, 0.0452918, 0.0454342, 0.0455765, 0.0457188, 0.0458611, 0.0460035, 0.0461458, 0.0462881, 0.0464304, 0.0465728, 0.0467151, 0.0468574, 0.0469997, 0.047142, 0.0472843, 0.0474267, 0.047569, 0.0477113, 0.0478536, 0.0479959, 0.0481382, 0.0482805, 0.0484228, 0.0485652, 0.0487075, 0.0488498, 0.0489921, 0.0491344, 0.0492767, 0.049419, 0.0495613, 0.0497036, 0.0498459, 0.0499882, 0.0501305, 0.0502728, 0.0504151, 0.0505574, 0.0506997, 0.050842, 0.0509842, 0.0511265, 0.0512688, 0.0514111, 0.0515534, 0.0516957, 0.051838, 0.0519803, 0.0521225, 0.0522648, 0.0524071, 0.0525494, 0.0526917, 0.0528339, 0.0529762, 0.0531185, 0.0532608, 0.053403, 0.0535453, 0.0536876, 0.0538298, 0.0539721, 0.0541144, 0.0542566, 0.0543989, 0.0545412, 0.0546834, 0.0548257, 0.054968, 0.0551102, 0.0552525, 0.0553947, 0.055537, 0.0556793, 0.0558215, 0.0559638, 0.056106, 0.0562483, 0.0563905, 0.0565328, 0.056675, 0.0568173, 0.0569595,
0.0571017, 0.057244, 0.0573862, 0.0575285, 0.0576707, 0.0578129, 0.0579552, 0.0580974, 0.0582397, 0.0583819, 0.0585241, 0.0586664, 0.0588086, 0.0589508, 0.059093, 0.0592353, 0.0593775, 0.0595197, 0.0596619, 0.0598042, 0.0599464, 0.0600886, 0.0602308, 0.060373, 0.0605152, 0.0606575, 0.0607997, 0.0609419, 0.0610841, 0.0612263, 0.0613685, 0.0615107, 0.0616529, 0.0617951, 0.0619373, 0.0620795, 0.0622217, 0.0623639, 0.0625061, 0.0626483, 0.0627905, 0.0629327, 0.0630749, 0.0632171, 0.0633593, 0.0635015, 0.0636437, 0.0637859, 0.063928, 0.0640702, 0.0642124, 0.0643546, 0.0644968, 0.0646389, 0.0647811, 0.0649233, 0.0650655, 0.0652076, 0.0653498, 0.065492, 0.0656342, 0.0657763, 0.0659185, 0.0660607, 0.0662028, 0.066345, 0.0664871, 0.0666293, 0.0667715, 0.0669136, 0.0670558, 0.0671979, 0.0673401, 0.0674822, 0.0676244, 0.0677665, 0.0679087, 0.0680508, 0.068193, 0.0683351, 0.0684773, 0.0686194, 0.0687615, 0.0689037, 0.0690458, 0.0691879, 0.0693301, 0.0694722, 0.0696143, 0.0697565, 0.0698986, 0.0700407, 0.0701829, 0.070325, 0.0704671, 0.0706092, 0.0707513, 0.0708935, 0.0710356, 0.0711777,
0.0713198, 0.0714619, 0.071604, 0.0717461, 0.0718882, 0.0720304, 0.0721725, 0.0723146, 0.0724567, 0.0725988, 0.0727409, 0.072883, 0.0730251, 0.0731672, 0.0733092, 0.0734513, 0.0735934, 0.0737355, 0.0738776, 0.0740197, 0.0741618, 0.0743039, 0.0744459, 0.074588, 0.0747301, 0.0748722, 0.0750142, 0.0751563, 0.0752984, 0.0754405, 0.0755825, 0.0757246, 0.0758667, 0.0760087, 0.0761508, 0.0762929, 0.0764349, 0.076577, 0.076719, 0.0768611, 0.0770031, 0.0771452, 0.0772872, 0.0774293, 0.0775713, 0.0777134, 0.0778554, 0.0779975, 0.0781395, 0.0782816, 0.0784236, 0.0785656, 0.0787077, 0.0788497, 0.0789917, 0.0791338, 0.0792758, 0.0794178, 0.0795598, 0.0797019, 0.0798439, 0.0799859, 0.0801279, 0.0802699, 0.080412, 0.080554, 0.080696, 0.080838, 0.08098, 0.081122, 0.081264, 0.081406, 0.081548, 0.08169, 0.081832, 0.081974, 0.082116, 0.082258, 0.0824, 0.082542, 0.082684, 0.082826, 0.0829679, 0.0831099, 0.0832519, 0.0833939, 0.0835359, 0.0836778, 0.0838198, 0.0839618, 0.0841038, 0.0842457, 0.0843877, 0.0845297, 0.0846716, 0.0848136, 0.0849556, 0.0850975, 0.0852395, 0.0853814,
0.0855234, 0.0856653, 0.0858073, 0.0859492, 0.0860912, 0.0862331, 0.0863751, 0.086517, 0.086659, 0.0868009, 0.0869428, 0.0870848, 0.0872267, 0.0873686, 0.0875106, 0.0876525, 0.0877944, 0.0879364, 0.0880783, 0.0882202, 0.0883621, 0.088504, 0.088646, 0.0887879, 0.0889298, 0.0890717, 0.0892136, 0.0893555, 0.0894974, 0.0896393, 0.0897812, 0.0899231, 0.090065, 0.0902069, 0.0903488, 0.0904907, 0.0906326, 0.0907745, 0.0909164, 0.0910582, 0.0912001, 0.091342, 0.0914839, 0.0916258, 0.0917676, 0.0919095, 0.0920514, 0.0921933, 0.0923351, 0.092477, 0.0926189, 0.0927607, 0.0929026, 0.0930444, 0.0931863, 0.0933281, 0.09347, 0.0936119, 0.0937537, 0.0938955, 0.0940374, 0.0941792, 0.0943211, 0.0944629, 0.0946048, 0.0947466, 0.0948884, 0.0950303, 0.0951721, 0.0953139, 0.0954557, 0.0955976, 0.0957394, 0.0958812, 0.096023, 0.0961648, 0.0963067, 0.0964485, 0.0965903, 0.0967321, 0.0968739, 0.0970157, 0.0971575, 0.0972993, 0.0974411, 0.0975829, 0.0977247, 0.0978665, 0.0980083, 0.0981501, 0.0982919, 0.0984336, 0.0985754, 0.0987172, 0.098859, 0.0990008, 0.0991425, 0.0992843, 0.0994261, 0.0995678,
0.0997096, 0.0998514, 0.0999931, 0.100135, 0.100277, 0.100418, 0.10056, 0.100702, 0.100844, 0.100985, 0.101127, 0.101269, 0.101411, 0.101552, 0.101694, 0.101836, 0.101978, 0.102119, 0.102261, 0.102403, 0.102545, 0.102686, 0.102828, 0.10297, 0.103111, 0.103253, 0.103395, 0.103537, 0.103678, 0.10382, 0.103962, 0.104103, 0.104245, 0.104387, 0.104528, 0.10467, 0.104812, 0.104954, 0.105095, 0.105237, 0.105379, 0.10552, 0.105662, 0.105804, 0.105945, 0.106087, 0.106229, 0.10637, 0.106512, 0.106654, 0.106795, 0.106937, 0.107079, 0.10722, 0.107362, 0.107504, 0.107645, 0.107787, 0.107929, 0.10807, 0.108212, 0.108353, 0.108495, 0.108637, 0.108778, 0.10892, 0.109062, 0.109203, 0.109345, 0.109486, 0.109628, 0.10977, 0.109911, 0.110053, 0.110195, 0.110336, 0.110478, 0.110619, 0.110761, 0.110903, 0.111044, 0.111186, 0.111327, 0.111469, 0.111611, 0.111752, 0.111894, 0.112035, 0.112177, 0.112318, 0.11246, 0.112602, 0.112743, 0.112885, 0.113026, 0.113168, 0.113309, 0.113451, 0.113592, 0.113734,
0.113876, 0.114017, 0.114159, 0.1143, 0.114442, 0.114583, 0.114725, 0.114866, 0.115008, 0.115149, 0.115291, 0.115433, 0.115574, 0.115716, 0.115857, 0.115999, 0.11614, 0.116282, 0.116423, 0.116565, 0.116706, 0.116848, 0.116989, 0.117131, 0.117272, 0.117414, 0.117555, 0.117697, 0.117838, 0.11798, 0.118121, 0.118262, 0.118404, 0.118545, 0.118687, 0.118828, 0.11897, 0.119111, 0.119253, 0.119394, 0.119536, 0.119677, 0.119819, 0.11996, 0.120101, 0.120243, 0.120384, 0.120526, 0.120667, 0.120809, 0.12095, 0.121092, 0.121233, 0.121374, 0.121516, 0.121657, 0.121799, 0.12194, 0.122081, 0.122223, 0.122364, 0.122506, 0.122647, 0.122788, 0.12293, 0.123071, 0.123213, 0.123354, 0.123495, 0.123637, 0.123778, 0.12392, 0.124061, 0.124202, 0.124344, 0.124485, 0.124626, 0.124768, 0.124909, 0.125051, 0.125192, 0.125333, 0.125475, 0.125616, 0.125757, 0.125899, 0.12604, 0.126181, 0.126323, 0.126464, 0.126605, 0.126747, 0.126888, 0.127029, 0.127171, 0.127312, 0.127453, 0.127595, 0.127736, 0.127877,
0.128018, 0.12816, 0.128301, 0.128442, 0.128584, 0.128725, 0.128866, 0.129008, 0.129149, 0.12929, 0.129431, 0.129573, 0.129714, 0.129855, 0.129996, 0.130138, 0.130279, 0.13042, 0.130562, 0.130703, 0.130844, 0.130985, 0.131127, 0.131268, 0.131409, 0.13155, 0.131691, 0.131833, 0.131974, 0.132115, 0.132256, 0.132398, 0.132539, 0.13268, 0.132821, 0.132962, 0.133104, 0.133245, 0.133386, 0.133527, 0.133669, 0.13381, 0.133951, 0.134092, 0.134233, 0.134374, 0.134516, 0.134657, 0.134798, 0.134939, 0.13508, 0.135222, 0.135363, 0.135504, 0.135645, 0.135786, 0.135927, 0.136068, 0.13621, 0.136351, 0.136492, 0.136633, 0.136774, 0.136915, 0.137056, 0.137198, 0.137339, 0.13748, 0.137621, 0.137762, 0.137903, 0.138044, 0.138185, 0.138327, 0.138468, 0.138609, 0.13875, 0.138891, 0.139032, 0.139173, 0.139314, 0.139455, 0.139596, 0.139737, 0.139879, 0.14002, 0.140161, 0.140302, 0.140443, 0.140584, 0.140725, 0.140866, 0.141007, 0.141148, 0.141289, 0.14143, 0.141571, 0.141712, 0.141853, 0.141994,
0.142135, 0.142276, 0.142417, 0.142558, 0.142699, 0.14284, 0.142981, 0.143122, 0.143263, 0.143404, 0.143546, 0.143687, 0.143827, 0.143968, 0.144109, 0.14425, 0.144391, 0.144532, 0.144673, 0.144814, 0.144955, 0.145096, 0.145237, 0.145378, 0.145519, 0.14566, 0.145801, 0.145942, 0.146083, 0.146224, 0.146365, 0.146506, 0.146647, 0.146788, 0.146929, 0.14707, 0.147211, 0.147351, 0.147492, 0.147633, 0.147774, 0.147915, 0.148056, 0.148197, 0.148338, 0.148479, 0.14862, 0.14876, 0.148901, 0.149042, 0.149183, 0.149324, 0.149465, 0.149606, 0.149747, 0.149888, 0.150028, 0.150169, 0.15031, 0.150451, 0.150592, 0.150733, 0.150874, 0.151014, 0.151155, 0.151296, 0.151437, 0.151578, 0.151719, 0.151859, 0.152, 0.152141, 0.152282, 0.152423, 0.152563, 0.152704, 0.152845, 0.152986, 0.153127, 0.153267, 0.153408, 0.153549, 0.15369, 0.153831, 0.153971, 0.154112, 0.154253, 0.154394, 0.154534, 0.154675, 0.154816, 0.154957, 0.155097, 0.155238, 0.155379, 0.15552, 0.15566, 0.155801, 0.155942, 0.156083,
0.156223, 0.156364, 0.156505, 0.156646, 0.156786, 0.156927, 0.157068, 0.157208, 0.157349, 0.15749, 0.15763, 0.157771, 0.157912, 0.158053, 0.158193, 0.158334, 0.158475, 0.158615, 0.158756, 0.158897, 0.159037, 0.159178, 0.159319, 0.159459, 0.1596, 0.159741, 0.159881, 0.160022, 0.160162, 0.160303, 0.160444, 0.160584, 0.160725, 0.160866, 0.161006, 0.161147, 0.161287, 0.161428, 0.161569, 0.161709, 0.16185, 0.16199, 0.162131, 0.162272, 0.162412, 0.162553, 0.162693, 0.162834, 0.162975, 0.163115, 0.163256, 0.163396, 0.163537, 0.163677, 0.163818, 0.163958, 0.164099, 0.16424, 0.16438, 0.164521, 0.164661, 0.164802, 0.164942, 0.165083, 0.165223, 0.165364, 0.165504, 0.165645, 0.165785, 0.165926, 0.166066, 0.166207, 0.166347, 0.166488, 0.166628, 0.166769, 0.166909, 0.16705, 0.16719, 0.167331, 0.167471, 0.167612, 0.167752, 0.167892, 0.168033, 0.168173, 0.168314, 0.168454, 0.168595, 0.168735, 0.168876, 0.169016, 0.169156, 0.169297, 0.169437, 0.169578, 0.169718, 0.169859, 0.169999, 0.170139,
0.17028, 0.17042, 0.17056, 0.170701, 0.170841, 0.170982, 0.171122, 0.171262, 0.171403, 0.171543, 0.171683, 0.171824, 0.171964, 0.172105, 0.172245, 0.172385, 0.172526, 0.172666, 0.172806, 0.172947, 0.173087, 0.173227, 0.173368, 0.173508, 0.173648, 0.173788, 0.173929, 0.174069, 0.174209, 0.17435, 0.17449, 0.17463, 0.174771, 0.174911, 0.175051, 0.175191, 0.175332, 0.175472, 0.175612, 0.175752, 0.175893, 0.176033, 0.176173, 0.176313, 0.176454, 0.176594, 0.176734, 0.176874, 0.177015, 0.177155, 0.177295, 0.177435, 0.177576, 0.177716, 0.177856, 0.177996, 0.178136, 0.178277, 0.178417, 0.178557, 0.178697, 0.178837, 0.178977, 0.179118, 0.179258, 0.179398, 0.179538, 0.179678, 0.179818, 0.179959, 0.180099, 0.180239, 0.180379, 0.180519, 0.180659, 0.180799, 0.18094, 0.18108, 0.18122, 0.18136, 0.1815, 0.18164, 0.18178, 0.18192, 0.18206, 0.182201, 0.182341, 0.182481, 0.182621, 0.182761, 0.182901, 0.183041, 0.183181, 0.183321, 0.183461, 0.183601, 0.183741, 0.183881, 0.184021, 0.184161,
0.184301, 0.184441, 0.184582, 0.184722, 0.184862, 0.185002, 0.185142, 0.185282, 0.185422, 0.185562, 0.185702, 0.185842, 0.185982, 0.186122, 0.186262, 0.186402, 0.186542, 0.186682, 0.186821, 0.186961, 0.187101, 0.187241, 0.187381, 0.187521, 0.187661, 0.187801, 0.187941, 0.188081, 0.188221, 0.188361, 0.188501, 0.188641, 0.188781, 0.188921, 0.18906, 0.1892, 0.18934, 0.18948, 0.18962, 0.18976, 0.1899, 0.19004, 0.19018, 0.190319, 0.190459, 0.190599, 0.190739, 0.190879, 0.191019, 0.191159, 0.191298, 0.191438, 0.191578, 0.191718, 0.191858, 0.191998, 0.192137, 0.192277, 0.192417, 0.192557, 0.192697, 0.192837, 0.192976, 0.193116, 0.193256, 0.193396, 0.193535, 0.193675, 0.193815, 0.193955, 0.194095, 0.194234, 0.194374, 0.194514, 0.194654, 0.194793, 0.194933, 0.195073, 0.195213, 0.195352, 0.195492, 0.195632, 0.195772, 0.195911, 0.196051, 0.196191, 0.19633, 0.19647, 0.19661, 0.196749, 0.196889, 0.197029, 0.197168, 0.197308, 0.197448, 0.197588, 0.197727, 0.197867, 0.198006, 0.198146,
0.198286, 0.198425, 0.198565, 0.198705, 0.198844, 0.198984, 0.199124, 0.199263, 0.199403, 0.199542, 0.199682, 0.199822, 0.199961, 0.200101, 0.20024, 0.20038, 0.20052, 0.200659, 0.200799, 0.200938, 0.201078, 0.201217, 0.201357, 0.201497, 0.201636, 0.201776, 0.201915, 0.202055, 0.202194, 0.202334, 0.202473, 0.202613, 0.202752, 0.202892, 0.203031, 0.203171, 0.20331, 0.20345, 0.203589, 0.203729, 0.203868, 0.204008, 0.204147, 0.204287, 0.204426, 0.204566, 0.204705, 0.204845, 0.204984, 0.205124, 0.205263, 0.205402, 0.205542, 0.205681, 0.205821, 0.20596, 0.2061, 0.206239, 0.206378, 0.206518, 0.206657, 0.206797, 0.206936, 0.207075, 0.207215, 0.207354, 0.207494, 0.207633, 0.207772, 0.207912, 0.208051, 0.20819, 0.20833, 0.208469, 0.208608, 0.208748, 0.208887, 0.209026, 0.209166, 0.209305, 0.209444, 0.209584, 0.209723, 0.209862, 0.210002, 0.210141, 0.21028, 0.21042, 0.210559, 0.210698, 0.210837, 0.210977, 0.211116, 0.211255, 0.211394, 0.211534, 0.211673, 0.211812, 0.211951, 0.212091,
0.21223, 0.212369, 0.212508, 0.212648, 0.212787, 0.212926, 0.213065, 0.213204, 0.213344, 0.213483, 0.213622, 0.213761, 0.2139, 0.21404, 0.214179, 0.214318, 0.214457, 0.214596, 0.214735, 0.214874, 0.215014, 0.215153, 0.215292, 0.215431, 0.21557, 0.215709, 0.215848, 0.215988, 0.216127, 0.216266, 0.216405, 0.216544, 0.216683, 0.216822, 0.216961, 0.2171, 0.217239, 0.217378, 0.217518, 0.217657, 0.217796, 0.217935, 0.218074, 0.218213, 0.218352, 0.218491, 0.21863, 0.218769, 0.218908, 0.219047, 0.219186, 0.219325, 0.219464, 0.219603, 0.219742, 0.219881, 0.22002, 0.220159, 0.220298, 0.220437, 0.220576, 0.220715, 0.220854, 0.220993, 0.221132, 0.221271, 0.22141, 0.221549, 0.221687, 0.221826, 0.221965, 0.222104, 0.222243, 0.222382, 0.222521, 0.22266, 0.222799, 0.222938, 0.223077, 0.223215, 0.223354, 0.223493, 0.223632, 0.223771, 0.22391, 0.224049, 0.224187, 0.224326, 0.224465, 0.224604, 0.224743, 0.224882, 0.22502, 0.225159, 0.225298, 0.225437, 0.225576, 0.225715, 0.225853, 0.225992,
0.226131, 0.22627, 0.226408, 0.226547, 0.226686, 0.226825, 0.226964, 0.227102, 0.227241, 0.22738, 0.227519, 0.227657, 0.227796, 0.227935, 0.228073, 0.228212, 0.228351, 0.22849, 0.228628, 0.228767, 0.228906, 0.229044, 0.229183, 0.229322, 0.22946, 0.229599, 0.229738, 0.229876, 0.230015, 0.230154, 0.230292, 0.230431, 0.23057, 0.230708, 0.230847, 0.230986, 0.231124, 0.231263, 0.231401, 0.23154, 0.231679, 0.231817, 0.231956, 0.232094, 0.232233, 0.232372, 0.23251, 0.232649, 0.232787, 0.232926, 0.233064, 0.233203, 0.233341, 0.23348, 0.233619, 0.233757, 0.233896, 0.234034, 0.234173, 0.234311, 0.23445, 0.234588, 0.234727, 0.234865, 0.235004, 0.235142, 0.235281, 0.235419, 0.235558, 0.235696, 0.235834, 0.235973, 0.236111, 0.23625, 0.236388, 0.236527, 0.236665, 0.236804, 0.236942, 0.23708, 0.237219, 0.237357, 0.237496, 0.237634, 0.237772, 0.237911, 0.238049, 0.238188, 0.238326, 0.238464, 0.238603, 0.238741, 0.238879, 0.239018, 0.239156, 0.239294, 0.239433, 0.239571, 0.239709, 0.239848,
0.239986, 0.240124, 0.240263, 0.240401, 0.240539, 0.240678, 0.240816, 0.240954, 0.241092, 0.241231, 0.241369, 0.241507, 0.241645, 0.241784, 0.241922, 0.24206, 0.242198, 0.242337, 0.242475, 0.242613, 0.242751, 0.242889, 0.243028, 0.243166, 0.243304, 0.243442, 0.24358, 0.243719, 0.243857, 0.243995, 0.244133, 0.244271, 0.244409, 0.244548, 0.244686, 0.244824, 0.244962, 0.2451, 0.245238, 0.245376, 0.245515, 0.245653, 0.245791, 0.245929, 0.246067, 0.246205, 0.246343, 0.246481, 0.246619, 0.246757, 0.246895, 0.247034, 0.247172, 0.24731, 0.247448, 0.247586, 0.247724, 0.247862, 0.248, 0.248138, 0.248276, 0.248414, 0.248552, 0.24869, 0.248828, 0.248966, 0.249104, 0.249242, 0.24938, 0.249518, 0.249656, 0.249794, 0.249932, 0.25007, 0.250208, 0.250346, 0.250483, 0.250621, 0.250759, 0.250897, 0.251035, 0.251173, 0.251311, 0.251449, 0.251587, 0.251725, 0.251863, 0.252, 0.252138, 0.252276, 0.252414, 0.252552, 0.25269, 0.252828, 0.252965, 0.253103, 0.253241, 0.253379, 0.253517, 0.253655,
0.253792, 0.25393, 0.254068, 0.254206, 0.254344, 0.254481, 0.254619, 0.254757, 0.254895, 0.255032, 0.25517, 0.255308, 0.255446, 0.255584, 0.255721, 0.255859, 0.255997, 0.256134, 0.256272, 0.25641, 0.256548, 0.256685, 0.256823, 0.256961, 0.257098, 0.257236, 0.257374, 0.257511, 0.257649, 0.257787, 0.257924, 0.258062, 0.2582, 0.258337, 0.258475, 0.258613, 0.25875, 0.258888, 0.259025, 0.259163, 0.259301, 0.259438, 0.259576, 0.259713, 0.259851, 0.259989, 0.260126, 0.260264, 0.260401, 0.260539, 0.260676, 0.260814, 0.260952, 0.261089, 0.261227, 0.261364, 0.261502, 0.261639, 0.261777, 0.261914, 0.262052, 0.262189, 0.262327, 0.262464, 0.262602, 0.262739, 0.262877, 0.263014, 0.263151, 0.263289, 0.263426, 0.263564, 0.263701, 0.263839, 0.263976, 0.264114, 0.264251, 0.264388, 0.264526, 0.264663, 0.264801, 0.264938, 0.265075, 0.265213, 0.26535, 0.265487, 0.265625, 0.265762, 0.2659, 0.266037, 0.266174, 0.266312, 0.266449, 0.266586, 0.266723, 0.266861, 0.266998, 0.267135, 0.267273, 0.26741,
0.267547, 0.267685, 0.267822, 0.267959, 0.268096, 0.268234, 0.268371, 0.268508, 0.268645, 0.268783, 0.26892, 0.269057, 0.269194, 0.269331, 0.269469, 0.269606, 0.269743, 0.26988, 0.270017, 0.270155, 0.270292, 0.270429, 0.270566, 0.270703, 0.27084, 0.270978, 0.271115, 0.271252, 0.271389, 0.271526, 0.271663, 0.2718, 0.271938, 0.272075, 0.272212, 0.272349, 0.272486, 0.272623, 0.27276, 0.272897, 0.273034, 0.273171, 0.273308, 0.273445, 0.273582, 0.273719, 0.273856, 0.273993, 0.274131, 0.274268, 0.274405, 0.274542, 0.274679, 0.274816, 0.274953, 0.275089, 0.275226, 0.275363, 0.2755, 0.275637, 0.275774, 0.275911, 0.276048, 0.276185, 0.276322, 0.276459, 0.276596, 0.276733, 0.27687, 0.277007, 0.277144, 0.27728, 0.277417, 0.277554, 0.277691, 0.277828, 0.277965, 0.278102, 0.278239, 0.278375, 0.278512, 0.278649, 0.278786, 0.278923, 0.27906, 0.279196, 0.279333, 0.27947, 0.279607, 0.279744, 0.27988, 0.280017, 0.280154, 0.280291, 0.280427, 0.280564, 0.280701, 0.280838, 0.280974, 0.281111,
0.281248, 0.281385, 0.281521, 0.281658, 0.281795, 0.281931, 0.282068, 0.282205, 0.282341, 0.282478, 0.282615, 0.282751, 0.282888, 0.283025, 0.283161, 0.283298, 0.283435, 0.283571, 0.283708, 0.283845, 0.283981, 0.284118, 0.284254, 0.284391, 0.284528, 0.284664, 0.284801, 0.284937, 0.285074, 0.28521, 0.285347, 0.285484, 0.28562, 0.285757, 0.285893, 0.28603, 0.286166, 0.286303, 0.286439, 0.286576, 0.286712, 0.286849, 0.286985, 0.287122, 0.287258, 0.287395, 0.287531, 0.287668, 0.287804, 0.28794, 0.288077, 0.288213, 0.28835, 0.288486, 0.288623, 0.288759, 0.288895, 0.289032, 0.289168, 0.289305, 0.289441, 0.289577, 0.289714, 0.28985, 0.289986, 0.290123, 0.290259, 0.290395, 0.290532, 0.290668, 0.290804, 0.290941, 0.291077, 0.291213, 0.29135, 0.291486, 0.291622, 0.291759, 0.291895, 0.292031, 0.292167, 0.292304, 0.29244, 0.292576, 0.292712, 0.292849, 0.292985, 0.293121, 0.293257, 0.293393, 0.29353, 0.293666, 0.293802, 0.293938, 0.294074, 0.294211, 0.294347, 0.294483, 0.294619, 0.294755,
0.294891, 0.295027, 0.295164, 0.2953, 0.295436, 0.295572, 0.295708, 0.295844, 0.29598, 0.296116, 0.296252, 0.296389, 0.296525, 0.296661, 0.296797, 0.296933, 0.297069, 0.297205, 0.297341, 0.297477, 0.297613, 0.297749, 0.297885, 0.298021, 0.298157, 0.298293, 0.298429, 0.298565, 0.298701, 0.298837, 0.298973, 0.299109, 0.299245, 0.299381, 0.299517, 0.299653, 0.299788, 0.299924, 0.30006, 0.300196, 0.300332, 0.300468, 0.300604, 0.30074, 0.300876, 0.301012, 0.301147, 0.301283, 0.301419, 0.301555, 0.301691, 0.301827, 0.301962, 0.302098, 0.302234, 0.30237, 0.302506, 0.302641, 0.302777, 0.302913, 0.303049, 0.303185, 0.30332, 0.303456, 0.303592, 0.303728, 0.303863, 0.303999, 0.304135, 0.304271, 0.304406, 0.304542, 0.304678, 0.304813, 0.304949, 0.305085, 0.30522, 0.305356, 0.305492, 0.305627, 0.305763, 0.305899, 0.306034, 0.30617, 0.306306, 0.306441, 0.306577, 0.306713, 0.306848, 0.306984, 0.307119, 0.307255, 0.307391, 0.307526, 0.307662, 0.307797, 0.307933, 0.308068, 0.308204, 0.308339,
0.308475, 0.30861, 0.308746, 0.308881, 0.309017, 0.309153, 0.309288, 0.309423, 0.309559, 0.309694, 0.30983, 0.309965, 0.310101, 0.310236, 0.310372, 0.310507, 0.310643, 0.310778, 0.310913, 0.311049, 0.311184, 0.31132, 0.311455, 0.31159, 0.311726, 0.311861, 0.311997, 0.312132, 0.312267, 0.312403, 0.312538, 0.312673, 0.312809, 0.312944, 0.313079, 0.313215, 0.31335, 0.313485, 0.31362, 0.313756, 0.313891, 0.314026, 0.314162, 0.314297, 0.314432, 0.314567, 0.314703, 0.314838, 0.314973, 0.315108, 0.315243, 0.315379, 0.315514, 0.315649, 0.315784, 0.315919, 0.316055, 0.31619, 0.316325, 0.31646, 0.316595, 0.31673, 0.316866, 0.317001, 0.317136, 0.317271, 0.317406, 0.317541, 0.317676, 0.317811, 0.317946, 0.318081, 0.318217, 0.318352, 0.318487, 0.318622, 0.318757, 0.318892, 0.319027, 0.319162, 0.319297, 0.319432, 0.319567, 0.319702, 0.319837, 0.319972, 0.320107, 0.320242, 0.320377, 0.320512, 0.320647, 0.320782, 0.320917, 0.321052, 0.321186, 0.321321, 0.321456, 0.321591, 0.321726, 0.321861,
0.321996, 0.322131, 0.322266, 0.322401, 0.322535, 0.32267, 0.322805, 0.32294, 0.323075, 0.32321, 0.323344, 0.323479, 0.323614, 0.323749, 0.323884, 0.324019, 0.324153, 0.324288, 0.324423, 0.324558, 0.324692, 0.324827, 0.324962, 0.325097, 0.325231, 0.325366, 0.325501, 0.325636, 0.32577, 0.325905, 0.32604, 0.326174, 0.326309, 0.326444, 0.326578, 0.326713, 0.326848, 0.326982, 0.327117, 0.327252, 0.327386, 0.327521, 0.327655, 0.32779, 0.327925, 0.328059, 0.328194, 0.328328, 0.328463, 0.328598, 0.328732, 0.328867, 0.329001, 0.329136, 0.32927, 0.329405, 0.329539, 0.329674, 0.329808, 0.329943, 0.330077, 0.330212, 0.330346, 0.330481, 0.330615, 0.33075, 0.330884, 0.331019, 0.331153, 0.331287, 0.331422, 0.331556, 0.331691, 0.331825, 0.33196, 0.332094, 0.332228, 0.332363, 0.332497, 0.332631, 0.332766, 0.3329, 0.333035, 0.333169, 0.333303, 0.333438, 0.333572, 0.333706, 0.33384, 0.333975, 0.334109, 0.334243, 0.334378, 0.334512, 0.334646, 0.33478, 0.334915, 0.335049, 0.335183, 0.335317,
0.335452, 0.335586, 0.33572, 0.335854, 0.335988, 0.336123, 0.336257, 0.336391, 0.336525, 0.336659, 0.336793, 0.336928, 0.337062, 0.337196, 0.33733, 0.337464, 0.337598, 0.337732, 0.337866, 0.338001, 0.338135, 0.338269, 0.338403, 0.338537, 0.338671, 0.338805, 0.338939, 0.339073, 0.339207, 0.339341, 0.339475, 0.339609, 0.339743, 0.339877, 0.340011, 0.340145, 0.340279, 0.340413, 0.340547, 0.340681, 0.340815, 0.340949, 0.341083, 0.341217, 0.341351, 0.341485, 0.341618, 0.341752, 0.341886, 0.34202, 0.342154, 0.342288, 0.342422, 0.342556, 0.342689, 0.342823, 0.342957, 0.343091, 0.343225, 0.343359, 0.343492, 0.343626, 0.34376, 0.343894, 0.344028, 0.344161, 0.344295, 0.344429, 0.344563, 0.344696, 0.34483, 0.344964, 0.345098, 0.345231, 0.345365, 0.345499, 0.345632, 0.345766, 0.3459, 0.346034, 0.346167, 0.346301, 0.346435, 0.346568, 0.346702, 0.346835, 0.346969, 0.347103, 0.347236, 0.34737, 0.347504, 0.347637, 0.347771, 0.347904, 0.348038, 0.348171, 0.348305, 0.348439, 0.348572, 0.348706,
0.348839, 0.348973, 0.349106, 0.34924, 0.349373, 0.349507, 0.34964, 0.349774, 0.349907, 0.350041, 0.350174, 0.350307, 0.350441, 0.350574, 0.350708, 0.350841, 0.350975, 0.351108, 0.351241, 0.351375, 0.351508, 0.351642, 0.351775, 0.351908, 0.352042, 0.352175, 0.352308, 0.352442, 0.352575, 0.352708, 0.352842, 0.352975, 0.353108, 0.353242, 0.353375, 0.353508, 0.353641, 0.353775, 0.353908, 0.354041, 0.354174, 0.354308, 0.354441, 0.354574, 0.354707, 0.354841, 0.354974, 0.355107, 0.35524, 0.355373, 0.355507, 0.35564, 0.355773, 0.355906, 0.356039, 0.356172, 0.356305, 0.356439, 0.356572, 0.356705, 0.356838, 0.356971, 0.357104, 0.357237, 0.35737, 0.357503, 0.357636, 0.357769, 0.357902, 0.358035, 0.358168, 0.358301, 0.358434, 0.358567, 0.3587, 0.358833, 0.358966, 0.359099, 0.359232, 0.359365, 0.359498, 0.359631, 0.359764, 0.359897, 0.36003, 0.360163, 0.360296, 0.360429, 0.360562, 0.360695, 0.360827, 0.36096, 0.361093, 0.361226, 0.361359, 0.361492, 0.361625, 0.361757, 0.36189, 0.362023,
0.362156, 0.362289, 0.362421, 0.362554, 0.362687, 0.36282, 0.362953, 0.363085, 0.363218, 0.363351, 0.363484, 0.363616, 0.363749, 0.363882, 0.364014, 0.364147, 0.36428, 0.364412, 0.364545, 0.364678, 0.36481, 0.364943, 0.365076, 0.365208, 0.365341, 0.365474, 0.365606, 0.365739, 0.365871, 0.366004, 0.366137, 0.366269, 0.366402, 0.366534, 0.366667, 0.366799, 0.366932, 0.367065, 0.367197, 0.36733, 0.367462, 0.367595, 0.367727, 0.36786, 0.367992, 0.368125, 0.368257, 0.368389, 0.368522, 0.368654, 0.368787, 0.368919, 0.369052, 0.369184, 0.369316, 0.369449, 0.369581, 0.369714, 0.369846, 0.369978, 0.370111, 0.370243, 0.370375, 0.370508, 0.37064, 0.370772, 0.370905, 0.371037, 0.371169, 0.371302, 0.371434, 0.371566, 0.371699, 0.371831, 0.371963, 0.372095, 0.372228, 0.37236, 0.372492, 0.372624, 0.372756, 0.372889, 0.373021, 0.373153, 0.373285, 0.373417, 0.37355, 0.373682, 0.373814, 0.373946, 0.374078, 0.37421, 0.374342, 0.374474, 0.374607, 0.374739, 0.374871, 0.375003, 0.375135, 0.375267,
0.375399, 0.375531, 0.375663, 0.375795, 0.375927, 0.376059, 0.376191, 0.376323, 0.376455, 0.376587, 0.376719, 0.376851, 0.376983, 0.377115, 0.377247, 0.377379, 0.377511, 0.377643, 0.377775, 0.377907, 0.378039, 0.378171, 0.378302, 0.378434, 0.378566, 0.378698, 0.37883, 0.378962, 0.379094, 0.379225, 0.379357, 0.379489, 0.379621, 0.379753, 0.379885, 0.380016, 0.380148, 0.38028, 0.380412, 0.380543, 0.380675, 0.380807, 0.380939, 0.38107, 0.381202, 0.381334, 0.381466, 0.381597, 0.381729, 0.381861, 0.381992, 0.382124, 0.382256, 0.382387, 0.382519, 0.382651, 0.382782, 0.382914, 0.383045, 0.383177, 0.383309, 0.38344, 0.383572, 0.383703, 0.383835, 0.383966, 0.384098, 0.38423, 0.384361, 0.384493, 0.384624, 0.384756, 0.384887, 0.385019, 0.38515, 0.385282, 0.385413, 0.385545, 0.385676, 0.385807, 0.385939, 0.38607, 0.386202, 0.386333, 0.386465, 0.386596, 0.386727, 0.386859, 0.38699, 0.387122, 0.387253, 0.387384, 0.387516, 0.387647, 0.387778, 0.38791, 0.388041, 0.388172, 0.388304, 0.388435,
0.388566, 0.388697, 0.388829, 0.38896, 0.389091, 0.389222, 0.389354, 0.389485, 0.389616, 0.389747, 0.389878, 0.39001, 0.390141, 0.390272, 0.390403, 0.390534, 0.390666, 0.390797, 0.390928, 0.391059, 0.39119, 0.391321, 0.391452, 0.391583, 0.391715, 0.391846, 0.391977, 0.392108, 0.392239, 0.39237, 0.392501, 0.392632, 0.392763, 0.392894, 0.393025, 0.393156, 0.393287, 0.393418, 0.393549, 0.39368, 0.393811, 0.393942, 0.394073, 0.394204, 0.394335, 0.394466, 0.394597, 0.394728, 0.394858, 0.394989, 0.39512, 0.395251, 0.395382, 0.395513, 0.395644, 0.395774, 0.395905, 0.396036, 0.396167, 0.396298, 0.396429, 0.396559, 0.39669, 0.396821, 0.396952, 0.397083, 0.397213, 0.397344, 0.397475, 0.397606, 0.397736, 0.397867, 0.397998, 0.398128, 0.398259, 0.39839, 0.39852, 0.398651, 0.398782, 0.398912, 0.399043, 0.399174, 0.399304, 0.399435, 0.399566, 0.399696, 0.399827, 0.399957, 0.400088, 0.400218, 0.400349, 0.40048, 0.40061, 0.400741, 0.400871, 0.401002, 0.401132, 0.401263, 0.401393, 0.401524,
0.401654, 0.401785, 0.401915, 0.402046, 0.402176, 0.402307, 0.402437, 0.402567, 0.402698, 0.402828, 0.402959, 0.403089, 0.403219, 0.40335, 0.40348, 0.40361, 0.403741, 0.403871, 0.404002, 0.404132, 0.404262, 0.404392, 0.404523, 0.404653, 0.404783, 0.404914, 0.405044, 0.405174, 0.405304, 0.405435, 0.405565, 0.405695, 0.405825, 0.405956, 0.406086, 0.406216, 0.406346, 0.406476, 0.406606, 0.406737, 0.406867, 0.406997, 0.407127, 0.407257, 0.407387, 0.407517, 0.407648, 0.407778, 0.407908, 0.408038, 0.408168, 0.408298, 0.408428, 0.408558, 0.408688, 0.408818, 0.408948, 0.409078, 0.409208, 0.409338, 0.409468, 0.409598, 0.409728, 0.409858, 0.409988, 0.410118, 0.410248, 0.410378, 0.410508, 0.410638, 0.410768, 0.410897, 0.411027, 0.411157, 0.411287, 0.411417, 0.411547, 0.411677, 0.411807, 0.411936, 0.412066, 0.412196, 0.412326, 0.412456, 0.412585, 0.412715, 0.412845, 0.412975, 0.413104, 0.413234, 0.413364, 0.413494, 0.413623, 0.413753, 0.413883, 0.414012, 0.414142, 0.414272, 0.414402, 0.414531,
0.414661, 0.41479, 0.41492, 0.41505, 0.415179, 0.415309, 0.415439, 0.415568, 0.415698, 0.415827, 0.415957, 0.416086, 0.416216, 0.416346, 0.416475, 0.416605, 0.416734, 0.416864, 0.416993, 0.417123, 0.417252, 0.417382, 0.417511, 0.417641, 0.41777, 0.417899, 0.418029, 0.418158, 0.418288, 0.418417, 0.418547, 0.418676, 0.418805, 0.418935, 0.419064, 0.419193, 0.419323, 0.419452, 0.419581, 0.419711, 0.41984, 0.419969, 0.420099, 0.420228, 0.420357, 0.420487, 0.420616, 0.420745, 0.420874, 0.421004, 0.421133, 0.421262, 0.421391, 0.42152, 0.42165, 0.421779, 0.421908, 0.422037, 0.422166, 0.422295, 0.422425, 0.422554, 0.422683, 0.422812, 0.422941, 0.42307, 0.423199, 0.423328, 0.423457, 0.423586, 0.423716, 0.423845, 0.423974, 0.424103, 0.424232, 0.424361, 0.42449, 0.424619, 0.424748, 0.424877, 0.425006, 0.425135, 0.425264, 0.425393, 0.425521, 0.42565, 0.425779, 0.425908, 0.426037, 0.426166, 0.426295, 0.426424, 0.426553, 0.426682, 0.42681, 0.426939, 0.427068, 0.427197, 0.427326, 0.427454,
0.427583, 0.427712, 0.427841, 0.42797, 0.428098, 0.428227, 0.428356, 0.428485, 0.428613, 0.428742, 0.428871, 0.428999, 0.429128, 0.429257, 0.429386, 0.429514, 0.429643, 0.429772, 0.4299, 0.430029, 0.430157, 0.430286, 0.430415, 0.430543, 0.430672, 0.4308, 0.430929, 0.431058, 0.431186, 0.431315, 0.431443, 0.431572, 0.4317, 0.431829, 0.431957, 0.432086, 0.432214, 0.432343, 0.432471, 0.4326, 0.432728, 0.432857, 0.432985, 0.433113, 0.433242, 0.43337, 0.433499, 0.433627, 0.433755, 0.433884, 0.434012, 0.43414, 0.434269, 0.434397, 0.434525, 0.434654, 0.434782, 0.43491, 0.435039, 0.435167, 0.435295, 0.435424, 0.435552, 0.43568, 0.435808, 0.435936, 0.436065, 0.436193, 0.436321, 0.436449, 0.436577, 0.436706, 0.436834, 0.436962, 0.43709, 0.437218, 0.437346, 0.437475, 0.437603, 0.437731, 0.437859, 0.437987, 0.438115, 0.438243, 0.438371, 0.438499, 0.438627, 0.438755, 0.438883, 0.439011, 0.439139, 0.439267, 0.439395, 0.439523, 0.439651, 0.439779, 0.439907, 0.440035, 0.440163, 0.440291,
0.440419, 0.440547, 0.440675, 0.440803, 0.440931, 0.441058, 0.441186, 0.441314, 0.441442, 0.44157, 0.441698, 0.441825, 0.441953, 0.442081, 0.442209, 0.442337, 0.442464, 0.442592, 0.44272, 0.442848, 0.442975, 0.443103, 0.443231, 0.443359, 0.443486, 0.443614, 0.443742, 0.443869, 0.443997, 0.444125, 0.444252, 0.44438, 0.444508, 0.444635, 0.444763, 0.44489, 0.445018, 0.445146, 0.445273, 0.445401, 0.445528, 0.445656, 0.445783, 0.445911, 0.446038, 0.446166, 0.446293, 0.446421, 0.446548, 0.446676, 0.446803, 0.446931, 0.447058, 0.447186, 0.447313, 0.447441, 0.447568, 0.447695, 0.447823, 0.44795, 0.448078, 0.448205, 0.448332, 0.44846, 0.448587, 0.448714, 0.448842, 0.448969, 0.449096, 0.449224, 0.449351, 0.449478, 0.449605, 0.449733, 0.44986, 0.449987, 0.450114, 0.450242, 0.450369, 0.450496, 0.450623, 0.45075, 0.450878, 0.451005, 0.451132, 0.451259, 0.451386, 0.451513, 0.45164, 0.451768, 0.451895, 0.452022, 0.452149, 0.452276, 0.452403, 0.45253, 0.452657, 0.452784, 0.452911, 0.453038,
0.453165, 0.453292, 0.453419, 0.453546, 0.453673, 0.4538, 0.453927, 0.454054, 0.454181, 0.454308, 0.454435, 0.454562, 0.454689, 0.454815, 0.454942, 0.455069, 0.455196, 0.455323, 0.45545, 0.455577, 0.455703, 0.45583, 0.455957, 0.456084, 0.456211, 0.456337, 0.456464, 0.456591, 0.456718, 0.456844, 0.456971, 0.457098, 0.457225, 0.457351, 0.457478, 0.457605, 0.457731, 0.457858, 0.457985, 0.458111, 0.458238, 0.458365, 0.458491, 0.458618, 0.458745, 0.458871, 0.458998, 0.459124, 0.459251, 0.459377, 0.459504, 0.45963, 0.459757, 0.459884, 0.46001, 0.460137, 0.460263, 0.46039, 0.460516, 0.460642, 0.460769, 0.460895, 0.461022, 0.461148, 0.461275, 0.461401, 0.461527, 0.461654, 0.46178, 0.461907, 0.462033, 0.462159, 0.462286, 0.462412, 0.462538, 0.462665, 0.462791, 0.462917, 0.463044, 0.46317, 0.463296, 0.463422, 0.463549, 0.463675, 0.463801, 0.463927, 0.464053, 0.46418, 0.464306, 0.464432, 0.464558, 0.464684, 0.464811, 0.464937, 0.465063, 0.465189, 0.465315, 0.465441, 0.465567, 0.465693,
0.465819, 0.465945, 0.466072, 0.466198, 0.466324, 0.46645, 0.466576, 0.466702, 0.466828, 0.466954, 0.46708, 0.467206, 0.467332, 0.467458, 0.467584, 0.467709, 0.467835, 0.467961, 0.468087, 0.468213, 0.468339, 0.468465, 0.468591, 0.468717, 0.468842, 0.468968, 0.469094, 0.46922, 0.469346, 0.469472, 0.469597, 0.469723, 0.469849, 0.469975, 0.4701, 0.470226, 0.470352, 0.470478, 0.470603, 0.470729, 0.470855, 0.47098, 0.471106, 0.471232, 0.471357, 0.471483, 0.471609, 0.471734, 0.47186, 0.471986, 0.472111, 0.472237, 0.472362, 0.472488, 0.472614, 0.472739, 0.472865, 0.47299, 0.473116, 0.473241, 0.473367, 0.473492, 0.473618, 0.473743, 0.473869, 0.473994, 0.47412, 0.474245, 0.47437, 0.474496, 0.474621, 0.474747, 0.474872, 0.474997, 0.475123, 0.475248, 0.475374, 0.475499, 0.475624, 0.47575, 0.475875, 0.476, 0.476125, 0.476251, 0.476376, 0.476501, 0.476627, 0.476752, 0.476877, 0.477002, 0.477127, 0.477253, 0.477378, 0.477503, 0.477628, 0.477753, 0.477879, 0.478004, 0.478129, 0.478254,
0.478379, 0.478504, 0.478629, 0.478754, 0.478879, 0.479005, 0.47913, 0.479255, 0.47938, 0.479505, 0.47963, 0.479755, 0.47988, 0.480005, 0.48013, 0.480255, 0.48038, 0.480505, 0.48063, 0.480755, 0.480879, 0.481004, 0.481129, 0.481254, 0.481379, 0.481504, 0.481629, 0.481754, 0.481879, 0.482003, 0.482128, 0.482253, 0.482378, 0.482503, 0.482627, 0.482752, 0.482877, 0.483002, 0.483126, 0.483251, 0.483376, 0.483501, 0.483625, 0.48375, 0.483875, 0.483999, 0.484124, 0.484249, 0.484373, 0.484498, 0.484623, 0.484747, 0.484872, 0.484997, 0.485121, 0.485246, 0.48537, 0.485495, 0.485619, 0.485744, 0.485868, 0.485993, 0.486118, 0.486242, 0.486367, 0.486491, 0.486615, 0.48674, 0.486864, 0.486989, 0.487113, 0.487238, 0.487362, 0.487487, 0.487611, 0.487735, 0.48786, 0.487984, 0.488108, 0.488233, 0.488357, 0.488481, 0.488606, 0.48873, 0.488854, 0.488979, 0.489103, 0.489227, 0.489351, 0.489476, 0.4896, 0.489724, 0.489848, 0.489973, 0.490097, 0.490221, 0.490345, 0.490469, 0.490593, 0.490718,
0.490842, 0.490966, 0.49109, 0.491214, 0.491338, 0.491462, 0.491586, 0.49171, 0.491834, 0.491958, 0.492083, 0.492207, 0.492331, 0.492455, 0.492579, 0.492703, 0.492827, 0.492951, 0.493074, 0.493198, 0.493322, 0.493446, 0.49357, 0.493694, 0.493818, 0.493942, 0.494066, 0.49419, 0.494313, 0.494437, 0.494561, 0.494685, 0.494809, 0.494933, 0.495056, 0.49518, 0.495304, 0.495428, 0.495551, 0.495675, 0.495799, 0.495923, 0.496046, 0.49617, 0.496294, 0.496418, 0.496541, 0.496665, 0.496789, 0.496912, 0.497036, 0.497159, 0.497283, 0.497407, 0.49753, 0.497654, 0.497777, 0.497901, 0.498025, 0.498148, 0.498272, 0.498395, 0.498519, 0.498642, 0.498766, 0.498889, 0.499013, 0.499136, 0.49926, 0.499383, 0.499506, 0.49963, 0.499753, 0.499877, 0.5, 0.500123, 0.500247, 0.50037, 0.500493, 0.500617, 0.50074, 0.500863, 0.500987, 0.50111, 0.501233, 0.501357, 0.50148, 0.501603, 0.501726, 0.50185, 0.501973, 0.502096, 0.502219, 0.502343, 0.502466, 0.502589, 0.502712, 0.502835, 0.502958, 0.503082,
0.503205, 0.503328, 0.503451, 0.503574, 0.503697, 0.50382, 0.503943, 0.504066, 0.504189, 0.504312, 0.504435, 0.504558, 0.504681, 0.504804, 0.504927, 0.50505, 0.505173, 0.505296, 0.505419, 0.505542, 0.505665, 0.505788, 0.505911, 0.506034, 0.506157, 0.50628, 0.506402, 0.506525, 0.506648, 0.506771, 0.506894, 0.507017, 0.507139, 0.507262, 0.507385, 0.507508, 0.50763, 0.507753, 0.507876, 0.507999, 0.508121, 0.508244, 0.508367, 0.508489, 0.508612, 0.508735, 0.508857, 0.50898, 0.509103, 0.509225, 0.509348, 0.509471, 0.509593, 0.509716, 0.509838, 0.509961, 0.510083, 0.510206, 0.510329, 0.510451, 0.510574, 0.510696, 0.510819, 0.510941, 0.511063, 0.511186, 0.511308, 0.511431, 0.511553, 0.511676, 0.511798, 0.51192, 0.512043, 0.512165, 0.512288, 0.51241, 0.512532, 0.512655, 0.512777, 0.512899, 0.513022, 0.513144, 0.513266, 0.513388, 0.513511, 0.513633, 0.513755, 0.513877, 0.514, 0.514122, 0.514244, 0.514366, 0.514488, 0.514611, 0.514733, 0.514855, 0.514977, 0.515099, 0.515221, 0.515343,
0.515465, 0.515588, 0.51571, 0.515832, 0.515954, 0.516076, 0.516198, 0.51632, 0.516442, 0.516564, 0.516686, 0.516808, 0.51693, 0.517052, 0.517174, 0.517296, 0.517418, 0.517539, 0.517661, 0.517783, 0.517905, 0.518027, 0.518149, 0.518271, 0.518393, 0.518514, 0.518636, 0.518758, 0.51888, 0.519002, 0.519123, 0.519245, 0.519367, 0.519489, 0.51961, 0.519732, 0.519854, 0.519976, 0.520097, 0.520219, 0.520341, 0.520462, 0.520584, 0.520706, 0.520827, 0.520949, 0.52107, 0.521192, 0.521314, 0.521435, 0.521557, 0.521678, 0.5218, 0.521921, 0.522043, 0.522164, 0.522286, 0.522407, 0.522529, 0.52265, 0.522772, 0.522893, 0.523015, 0.523136, 0.523258, 0.523379, 0.5235, 0.523622, 0.523743, 0.523865, 0.523986, 0.524107, 0.524229, 0.52435, 0.524471, 0.524593, 0.524714, 0.524835, 0.524956, 0.525078, 0.525199, 0.52532, 0.525441, 0.525563, 0.525684, 0.525805, 0.525926, 0.526047, 0.526169, 0.52629, 0.526411, 0.526532, 0.526653, 0.526774, 0.526895, 0.527016, 0.527137, 0.527258, 0.52738, 0.527501,
0.527622, 0.527743, 0.527864, 0.527985, 0.528106, 0.528227, 0.528348, 0.528469, 0.52859, 0.52871, 0.528831, 0.528952, 0.529073, 0.529194, 0.529315, 0.529436, 0.529557, 0.529678, 0.529798, 0.529919, 0.53004, 0.530161, 0.530282, 0.530402, 0.530523, 0.530644, 0.530765, 0.530886, 0.531006, 0.531127, 0.531248, 0.531368, 0.531489, 0.53161, 0.53173, 0.531851, 0.531972, 0.532092, 0.532213, 0.532334, 0.532454, 0.532575, 0.532695, 0.532816, 0.532937, 0.533057, 0.533178, 0.533298, 0.533419, 0.533539, 0.53366, 0.53378, 0.533901, 0.534021, 0.534142, 0.534262, 0.534382, 0.534503, 0.534623, 0.534744, 0.534864, 0.534984, 0.535105, 0.535225, 0.535346, 0.535466, 0.535586, 0.535707, 0.535827, 0.535947, 0.536067, 0.536188, 0.536308, 0.536428, 0.536548, 0.536669, 0.536789, 0.536909, 0.537029, 0.537149, 0.53727, 0.53739, 0.53751, 0.53763, 0.53775, 0.53787, 0.53799, 0.53811, 0.538231, 0.538351, 0.538471, 0.538591, 0.538711, 0.538831, 0.538951, 0.539071, 0.539191, 0.539311, 0.539431, 0.539551,
0.539671, 0.539791, 0.539911, 0.540031, 0.54015, 0.54027, 0.54039, 0.54051, 0.54063, 0.54075, 0.54087, 0.540989, 0.541109, 0.541229, 0.541349, 0.541469, 0.541588, 0.541708, 0.541828, 0.541948, 0.542067, 0.542187, 0.542307, 0.542427, 0.542546, 0.542666, 0.542786, 0.542905, 0.543025, 0.543145, 0.543264, 0.543384, 0.543503, 0.543623, 0.543743, 0.543862, 0.543982, 0.544101, 0.544221, 0.54434, 0.54446, 0.544579, 0.544699, 0.544818, 0.544938, 0.545057, 0.545177, 0.545296, 0.545416, 0.545535, 0.545654, 0.545774, 0.545893, 0.546012, 0.546132, 0.546251, 0.54637, 0.54649, 0.546609, 0.546728, 0.546848, 0.546967, 0.547086, 0.547206, 0.547325, 0.547444, 0.547563, 0.547682, 0.547802, 0.547921, 0.54804, 0.548159, 0.548278, 0.548397, 0.548517, 0.548636, 0.548755, 0.548874, 0.548993, 0.549112, 0.549231, 0.54935, 0.549469, 0.549588, 0.549707, 0.549826, 0.549945, 0.550064, 0.550183, 0.550302, 0.550421, 0.55054, 0.550659, 0.550778, 0.550897, 0.551016, 0.551135, 0.551254, 0.551373, 0.551491,
0.55161, 0.551729, 0.551848, 0.551967, 0.552086, 0.552204, 0.552323, 0.552442, 0.552561, 0.552679, 0.552798, 0.552917, 0.553035, 0.553154, 0.553273, 0.553392, 0.55351, 0.553629, 0.553748, 0.553866, 0.553985, 0.554103, 0.554222, 0.554341, 0.554459, 0.554578, 0.554696, 0.554815, 0.554933, 0.555052, 0.55517, 0.555289, 0.555407, 0.555526, 0.555644, 0.555763, 0.555881, 0.556, 0.556118, 0.556236, 0.556355, 0.556473, 0.556592, 0.55671, 0.556828, 0.556947, 0.557065, 0.557183, 0.557302, 0.55742, 0.557538, 0.557656, 0.557775, 0.557893, 0.558011, 0.558129, 0.558248, 0.558366, 0.558484, 0.558602, 0.55872, 0.558839, 0.558957, 0.559075, 0.559193, 0.559311, 0.559429, 0.559547, 0.559665, 0.559783, 0.559901, 0.560019, 0.560137, 0.560256, 0.560374, 0.560492, 0.56061, 0.560727, 0.560845, 0.560963, 0.561081, 0.561199, 0.561317, 0.561435, 0.561553, 0.561671, 0.561789, 0.561907, 0.562024, 0.562142, 0.56226, 0.562378, 0.562496, 0.562614, 0.562731, 0.562849, 0.562967, 0.563085, 0.563202, 0.56332,
0.563438, 0.563555, 0.563673, 0.563791, 0.563909, 0.564026, 0.564144, 0.564261, 0.564379, 0.564497, 0.564614, 0.564732, 0.564849, 0.564967, 0.565085, 0.565202, 0.56532, 0.565437, 0.565555, 0.565672, 0.56579, 0.565907, 0.566025, 0.566142, 0.566259, 0.566377, 0.566494, 0.566612, 0.566729, 0.566846, 0.566964, 0.567081, 0.567199, 0.567316, 0.567433, 0.567551, 0.567668, 0.567785, 0.567902, 0.56802, 0.568137, 0.568254, 0.568371, 0.568489, 0.568606, 0.568723, 0.56884, 0.568957, 0.569075, 0.569192, 0.569309, 0.569426, 0.569543, 0.56966, 0.569777, 0.569894, 0.570011, 0.570128, 0.570246, 0.570363, 0.57048, 0.570597, 0.570714, 0.570831, 0.570948, 0.571065, 0.571181, 0.571298, 0.571415, 0.571532, 0.571649, 0.571766, 0.571883, 0.572, 0.572117, 0.572234, 0.57235, 0.572467, 0.572584, 0.572701, 0.572818, 0.572934, 0.573051, 0.573168, 0.573285, 0.573401, 0.573518, 0.573635, 0.573752, 0.573868, 0.573985, 0.574102, 0.574218, 0.574335, 0.574451, 0.574568, 0.574685, 0.574801, 0.574918, 0.575034,
0.575151, 0.575268, 0.575384, 0.575501, 0.575617, 0.575734, 0.57585, 0.575967, 0.576083, 0.576199, 0.576316, 0.576432, 0.576549, 0.576665, 0.576782, 0.576898, 0.577014, 0.577131, 0.577247, 0.577363, 0.57748, 0.577596, 0.577712, 0.577829, 0.577945, 0.578061, 0.578177, 0.578294, 0.57841, 0.578526, 0.578642, 0.578758, 0.578875, 0.578991, 0.579107, 0.579223, 0.579339, 0.579455, 0.579571, 0.579688, 0.579804, 0.57992, 0.580036, 0.580152, 0.580268, 0.580384, 0.5805, 0.580616, 0.580732, 0.580848, 0.580964, 0.58108, 0.581196, 0.581312, 0.581428, 0.581544, 0.58166, 0.581775, 0.581891, 0.582007, 0.582123, 0.582239, 0.582355, 0.58247, 0.582586, 0.582702, 0.582818, 0.582934, 0.583049, 0.583165, 0.583281, 0.583397, 0.583512, 0.583628, 0.583744, 0.583859, 0.583975, 0.584091, 0.584206, 0.584322, 0.584438, 0.584553, 0.584669, 0.584784, 0.5849, 0.585015, 0.585131, 0.585247, 0.585362, 0.585478, 0.585593, 0.585709, 0.585824, 0.585939, 0.586055, 0.58617, 0.586286, 0.586401, 0.586517, 0.586632,
0.586747, 0.586863, 0.586978, 0.587093, 0.587209, 0.587324, 0.587439, 0.587555, 0.58767, 0.587785, 0.587901, 0.588016, 0.588131, 0.588246, 0.588361, 0.588477, 0.588592, 0.588707, 0.588822, 0.588937, 0.589052, 0.589168, 0.589283, 0.589398, 0.589513, 0.589628, 0.589743, 0.589858, 0.589973, 0.590088, 0.590203, 0.590318, 0.590433, 0.590548, 0.590663, 0.590778, 0.590893, 0.591008, 0.591123, 0.591238, 0.591353, 0.591468, 0.591583, 0.591697, 0.591812, 0.591927, 0.592042, 0.592157, 0.592272, 0.592386, 0.592501, 0.592616, 0.592731, 0.592845, 0.59296, 0.593075, 0.59319, 0.593304, 0.593419, 0.593534, 0.593648, 0.593763, 0.593878, 0.593992, 0.594107, 0.594221, 0.594336, 0.594451, 0.594565, 0.59468, 0.594794, 0.594909, 0.595023, 0.595138, 0.595252, 0.595367, 0.595481, 0.595596, 0.59571, 0.595824, 0.595939, 0.596053, 0.596168, 0.596282, 0.596396, 0.596511, 0.596625, 0.596739, 0.596854, 0.596968, 0.597082, 0.597197, 0.597311, 0.597425, 0.597539, 0.597654, 0.597768, 0.597882, 0.597996, 0.598111,
0.598225, 0.598339, 0.598453, 0.598567, 0.598681, 0.598795, 0.59891, 0.599024, 0.599138, 0.599252, 0.599366, 0.59948, 0.599594, 0.599708, 0.599822, 0.599936, 0.60005, 0.600164, 0.600278, 0.600392, 0.600506, 0.60062, 0.600734, 0.600847, 0.600961, 0.601075, 0.601189, 0.601303, 0.601417, 0.601531, 0.601644, 0.601758, 0.601872, 0.601986, 0.602099, 0.602213, 0.602327, 0.602441, 0.602554, 0.602668, 0.602782, 0.602895, 0.603009, 0.603123, 0.603236, 0.60335, 0.603464, 0.603577, 0.603691, 0.603804, 0.603918, 0.604032, 0.604145, 0.604259, 0.604372, 0.604486, 0.604599, 0.604713, 0.604826, 0.60494, 0.605053, 0.605166, 0.60528, 0.605393, 0.605507, 0.60562, 0.605733, 0.605847, 0.60596, 0.606073, 0.606187, 0.6063, 0.606413, 0.606527, 0.60664, 0.606753, 0.606866, 0.60698, 0.607093, 0.607206, 0.607319, 0.607432, 0.607546, 0.607659, 0.607772, 0.607885, 0.607998, 0.608111, 0.608224, 0.608337, 0.608451, 0.608564, 0.608677, 0.60879, 0.608903, 0.609016, 0.609129, 0.609242, 0.609355, 0.609468,
0.609581, 0.609694, 0.609806, 0.609919, 0.610032, 0.610145, 0.610258, 0.610371, 0.610484, 0.610597, 0.610709, 0.610822, 0.610935, 0.611048, 0.611161, 0.611273, 0.611386, 0.611499, 0.611612, 0.611724, 0.611837, 0.61195, 0.612062, 0.612175, 0.612288, 0.6124, 0.612513, 0.612626, 0.612738, 0.612851, 0.612963, 0.613076, 0.613188, 0.613301, 0.613414, 0.613526, 0.613639, 0.613751, 0.613864, 0.613976, 0.614088, 0.614201, 0.614313, 0.614426, 0.614538, 0.614651, 0.614763, 0.614875, 0.614988, 0.6151, 0.615212, 0.615325, 0.615437, 0.615549, 0.615661, 0.615774, 0.615886, 0.615998, 0.61611, 0.616223, 0.616335, 0.616447, 0.616559, 0.616671, 0.616784, 0.616896, 0.617008, 0.61712, 0.617232, 0.617344, 0.617456, 0.617568, 0.61768, 0.617792, 0.617904, 0.618016, 0.618128, 0.61824, 0.618352, 0.618464, 0.618576, 0.618688, 0.6188, 0.618912, 0.619024, 0.619136, 0.619248, 0.61936, 0.619472, 0.619583, 0.619695, 0.619807, 0.619919, 0.620031, 0.620142, 0.620254, 0.620366, 0.620478, 0.620589, 0.620701,
0.620813, 0.620924, 0.621036, 0.621148, 0.621259, 0.621371, 0.621483, 0.621594, 0.621706, 0.621818, 0.621929, 0.622041, 0.622152, 0.622264, 0.622375, 0.622487, 0.622598, 0.62271, 0.622821, 0.622933, 0.623044, 0.623156, 0.623267, 0.623378, 0.62349, 0.623601, 0.623713, 0.623824, 0.623935, 0.624047, 0.624158, 0.624269, 0.624381, 0.624492, 0.624603, 0.624714, 0.624826, 0.624937, 0.625048, 0.625159, 0.62527, 0.625382, 0.625493, 0.625604, 0.625715, 0.625826, 0.625937, 0.626048, 0.62616, 0.626271, 0.626382, 0.626493, 0.626604, 0.626715, 0.626826, 0.626937, 0.627048, 0.627159, 0.62727, 0.627381, 0.627492, 0.627603, 0.627714, 0.627824, 0.627935, 0.628046, 0.628157, 0.628268, 0.628379, 0.62849, 0.6286, 0.628711, 0.628822, 0.628933, 0.629044, 0.629154, 0.629265, 0.629376, 0.629486, 0.629597, 0.629708, 0.629819, 0.629929, 0.63004, 0.63015, 0.630261, 0.630372, 0.630482, 0.630593, 0.630703, 0.630814, 0.630925, 0.631035, 0.631146, 0.631256, 0.631367, 0.631477, 0.631588, 0.631698, 0.631808,
0.631919, 0.632029, 0.63214, 0.63225, 0.63236, 0.632471, 0.632581, 0.632692, 0.632802, 0.632912, 0.633022, 0.633133, 0.633243, 0.633353, 0.633464, 0.633574, 0.633684, 0.633794, 0.633904, 0.634015, 0.634125, 0.634235, 0.634345, 0.634455, 0.634565, 0.634675, 0.634786, 0.634896, 0.635006, 0.635116, 0.635226, 0.635336, 0.635446, 0.635556, 0.635666, 0.635776, 0.635886, 0.635996, 0.636106, 0.636216, 0.636326, 0.636435, 0.636545, 0.636655, 0.636765, 0.636875, 0.636985, 0.637095, 0.637204, 0.637314, 0.637424, 0.637534, 0.637644, 0.637753, 0.637863, 0.637973, 0.638082, 0.638192, 0.638302, 0.638411, 0.638521, 0.638631, 0.63874, 0.63885, 0.63896, 0.639069, 0.639179, 0.639288, 0.639398, 0.639507, 0.639617, 0.639727, 0.639836, 0.639946, 0.640055, 0.640164, 0.640274, 0.640383, 0.640493, 0.640602, 0.640712, 0.640821, 0.64093, 0.64104, 0.641149, 0.641258, 0.641368, 0.641477, 0.641586, 0.641696, 0.641805, 0.641914, 0.642023, 0.642133, 0.642242, 0.642351, 0.64246, 0.642569, 0.642678, 0.642788,
0.642897, 0.643006, 0.643115, 0.643224, 0.643333, 0.643442, 0.643551, 0.64366, 0.643769, 0.643878, 0.643987, 0.644096, 0.644205, 0.644314, 0.644423, 0.644532, 0.644641, 0.64475, 0.644859, 0.644968, 0.645077, 0.645186, 0.645294, 0.645403, 0.645512, 0.645621, 0.64573, 0.645839, 0.645947, 0.646056, 0.646165, 0.646274, 0.646382, 0.646491, 0.6466, 0.646708, 0.646817, 0.646926, 0.647034, 0.647143, 0.647251, 0.64736, 0.647469, 0.647577, 0.647686, 0.647794, 0.647903, 0.648011, 0.64812, 0.648228, 0.648337, 0.648445, 0.648554, 0.648662, 0.648771, 0.648879, 0.648988, 0.649096, 0.649204, 0.649313, 0.649421, 0.649529, 0.649638, 0.649746, 0.649854, 0.649963, 0.650071, 0.650179, 0.650287, 0.650396, 0.650504, 0.650612, 0.65072, 0.650828, 0.650936, 0.651045, 0.651153, 0.651261, 0.651369, 0.651477, 0.651585, 0.651693, 0.651801, 0.651909, 0.652017, 0.652125, 0.652233, 0.652341, 0.652449, 0.652557, 0.652665, 0.652773, 0.652881, 0.652989, 0.653097, 0.653205, 0.653313, 0.653421, 0.653528, 0.653636,
0.653744, 0.653852, 0.65396, 0.654068, 0.654175, 0.654283, 0.654391, 0.654498, 0.654606, 0.654714, 0.654822, 0.654929, 0.655037, 0.655145, 0.655252, 0.65536, 0.655467, 0.655575, 0.655683, 0.65579, 0.655898, 0.656005, 0.656113, 0.65622, 0.656328, 0.656435, 0.656543, 0.65665, 0.656758, 0.656865, 0.656973, 0.65708, 0.657187, 0.657295, 0.657402, 0.657509, 0.657617, 0.657724, 0.657831, 0.657939, 0.658046, 0.658153, 0.658261, 0.658368, 0.658475, 0.658582, 0.658689, 0.658797, 0.658904, 0.659011, 0.659118, 0.659225, 0.659332, 0.65944, 0.659547, 0.659654, 0.659761, 0.659868, 0.659975, 0.660082, 0.660189, 0.660296, 0.660403, 0.66051, 0.660617, 0.660724, 0.660831, 0.660938, 0.661045, 0.661152, 0.661258, 0.661365, 0.661472, 0.661579, 0.661686, 0.661793, 0.661899, 0.662006, 0.662113, 0.66222, 0.662327, 0.662433, 0.66254, 0.662647, 0.662753, 0.66286, 0.662967, 0.663073, 0.66318, 0.663287, 0.663393, 0.6635, 0.663607, 0.663713, 0.66382, 0.663926, 0.664033, 0.664139, 0.664246, 0.664352,
0.664459, 0.664565, 0.664672, 0.664778, 0.664885, 0.664991, 0.665097, 0.665204, 0.66531, 0.665417, 0.665523, 0.665629, 0.665736, 0.665842, 0.665948, 0.666054, 0.666161, 0.666267, 0.666373, 0.666479, 0.666586, 0.666692, 0.666798, 0.666904, 0.66701, 0.667116, 0.667223, 0.667329, 0.667435, 0.667541, 0.667647, 0.667753, 0.667859, 0.667965, 0.668071, 0.668177, 0.668283, 0.668389, 0.668495, 0.668601, 0.668707, 0.668813, 0.668919, 0.669025, 0.669131, 0.669236, 0.669342, 0.669448, 0.669554, 0.66966, 0.669766, 0.669871, 0.669977, 0.670083, 0.670189, 0.670294, 0.6704, 0.670506, 0.670612, 0.670717, 0.670823, 0.670929, 0.671034, 0.67114, 0.671246, 0.671351, 0.671457, 0.671562, 0.671668, 0.671773, 0.671879, 0.671984, 0.67209, 0.672195, 0.672301, 0.672406, 0.672512, 0.672617, 0.672723, 0.672828, 0.672933, 0.673039, 0.673144, 0.67325, 0.673355, 0.67346, 0.673566, 0.673671, 0.673776, 0.673881, 0.673987, 0.674092, 0.674197, 0.674302, 0.674408, 0.674513, 0.674618, 0.674723, 0.674828, 0.674933,
0.675039, 0.675144, 0.675249, 0.675354, 0.675459, 0.675564, 0.675669, 0.675774, 0.675879, 0.675984, 0.676089, 0.676194, 0.676299, 0.676404, 0.676509, 0.676614, 0.676719, 0.676824, 0.676928, 0.677033, 0.677138, 0.677243, 0.677348, 0.677453, 0.677557, 0.677662, 0.677767, 0.677872, 0.677976, 0.678081, 0.678186, 0.678291, 0.678395, 0.6785, 0.678605, 0.678709, 0.678814, 0.678918, 0.679023, 0.679128, 0.679232, 0.679337, 0.679441, 0.679546, 0.67965, 0.679755, 0.679859, 0.679964, 0.680068, 0.680173, 0.680277, 0.680382, 0.680486, 0.68059, 0.680695, 0.680799, 0.680904, 0.681008, 0.681112, 0.681216, 0.681321, 0.681425, 0.681529, 0.681634, 0.681738, 0.681842, 0.681946, 0.68205, 0.682155, 0.682259, 0.682363, 0.682467, 0.682571, 0.682675, 0.682779, 0.682884, 0.682988, 0.683092, 0.683196, 0.6833, 0.683404, 0.683508, 0.683612, 0.683716, 0.68382, 0.683924, 0.684028, 0.684132, 0.684235, 0.684339, 0.684443, 0.684547, 0.684651, 0.684755, 0.684859, 0.684962, 0.685066, 0.68517, 0.685274, 0.685378,
0.685481, 0.685585, 0.685689, 0.685792, 0.685896, 0.686, 0.686103, 0.686207, 0.686311, 0.686414, 0.686518, 0.686622, 0.686725, 0.686829, 0.686932, 0.687036, 0.687139, 0.687243, 0.687346, 0.68745, 0.687553, 0.687657, 0.68776, 0.687864, 0.687967, 0.68807, 0.688174, 0.688277, 0.68838, 0.688484, 0.688587, 0.68869, 0.688794, 0.688897, 0.689, 0.689103, 0.689207, 0.68931, 0.689413, 0.689516, 0.68962, 0.689723, 0.689826, 0.689929, 0.690032, 0.690135, 0.690238, 0.690341, 0.690445, 0.690548, 0.690651, 0.690754, 0.690857, 0.69096, 0.691063, 0.691166, 0.691269, 0.691372, 0.691474, 0.691577, 0.69168, 0.691783, 0.691886, 0.691989, 0.692092, 0.692195, 0.692297, 0.6924, 0.692503, 0.692606, 0.692709, 0.692811, 0.692914, 0.693017, 0.693119, 0.693222, 0.693325, 0.693428, 0.69353, 0.693633, 0.693735, 0.693838, 0.693941, 0.694043, 0.694146, 0.694248, 0.694351, 0.694453, 0.694556, 0.694658, 0.694761, 0.694863, 0.694966, 0.695068, 0.695171, 0.695273, 0.695375, 0.695478, 0.69558, 0.695683,
0.695785, 0.695887, 0.69599, 0.696092, 0.696194, 0.696296, 0.696399, 0.696501, 0.696603, 0.696705, 0.696808, 0.69691, 0.697012, 0.697114, 0.697216, 0.697318, 0.69742, 0.697523, 0.697625, 0.697727, 0.697829, 0.697931, 0.698033, 0.698135, 0.698237, 0.698339, 0.698441, 0.698543, 0.698645, 0.698747, 0.698849, 0.69895, 0.699052, 0.699154, 0.699256, 0.699358, 0.69946, 0.699562, 0.699663, 0.699765, 0.699867, 0.699969, 0.70007, 0.700172, 0.700274, 0.700376, 0.700477, 0.700579, 0.700681, 0.700782, 0.700884, 0.700985, 0.701087, 0.701189, 0.70129, 0.701392, 0.701493, 0.701595, 0.701696, 0.701798, 0.701899, 0.702001, 0.702102, 0.702204, 0.702305, 0.702407, 0.702508, 0.702609, 0.702711, 0.702812, 0.702914, 0.703015, 0.703116, 0.703217, 0.703319, 0.70342, 0.703521, 0.703623, 0.703724, 0.703825, 0.703926, 0.704027, 0.704129, 0.70423, 0.704331, 0.704432, 0.704533, 0.704634, 0.704735, 0.704836, 0.704937, 0.705038, 0.70514, 0.705241, 0.705342, 0.705443, 0.705544, 0.705644, 0.705745, 0.705846,
0.705947, 0.706048, 0.706149, 0.70625, 0.706351, 0.706452, 0.706552, 0.706653, 0.706754, 0.706855, 0.706956, 0.707056, 0.707157, 0.707258, 0.707359, 0.707459, 0.70756, 0.707661, 0.707761, 0.707862, 0.707963, 0.708063, 0.708164, 0.708264, 0.708365, 0.708466, 0.708566, 0.708667, 0.708767, 0.708868, 0.708968, 0.709069, 0.709169, 0.70927, 0.70937, 0.70947, 0.709571, 0.709671, 0.709772, 0.709872, 0.709972, 0.710073, 0.710173, 0.710273, 0.710373, 0.710474, 0.710574, 0.710674, 0.710774, 0.710875, 0.710975, 0.711075, 0.711175, 0.711275, 0.711375, 0.711476, 0.711576, 0.711676, 0.711776, 0.711876, 0.711976, 0.712076, 0.712176, 0.712276, 0.712376, 0.712476, 0.712576, 0.712676, 0.712776, 0.712876, 0.712976, 0.713076, 0.713176, 0.713275, 0.713375, 0.713475, 0.713575, 0.713675, 0.713775, 0.713874, 0.713974, 0.714074, 0.714174, 0.714273, 0.714373, 0.714473, 0.714572, 0.714672, 0.714772, 0.714871, 0.714971, 0.715071, 0.71517, 0.71527, 0.715369, 0.715469, 0.715568, 0.715668, 0.715767, 0.715867,
0.715966, 0.716066, 0.716165, 0.716265, 0.716364, 0.716463, 0.716563, 0.716662, 0.716762, 0.716861, 0.71696, 0.71706, 0.717159, 0.717258, 0.717357, 0.717457, 0.717556, 0.717655, 0.717754, 0.717854, 0.717953, 0.718052, 0.718151, 0.71825, 0.718349, 0.718448, 0.718548, 0.718647, 0.718746, 0.718845, 0.718944, 0.719043, 0.719142, 0.719241, 0.71934, 0.719439, 0.719538, 0.719637, 0.719736, 0.719834, 0.719933, 0.720032, 0.720131, 0.72023, 0.720329, 0.720428, 0.720526, 0.720625, 0.720724, 0.720823, 0.720921, 0.72102, 0.721119, 0.721218, 0.721316, 0.721415, 0.721514, 0.721612, 0.721711, 0.72181, 0.721908, 0.722007, 0.722105, 0.722204, 0.722302, 0.722401, 0.722499, 0.722598, 0.722696, 0.722795, 0.722893, 0.722992, 0.72309, 0.723189, 0.723287, 0.723385, 0.723484, 0.723582, 0.72368, 0.723779, 0.723877, 0.723975, 0.724074, 0.724172, 0.72427, 0.724368, 0.724467, 0.724565, 0.724663, 0.724761, 0.724859, 0.724957, 0.725056, 0.725154, 0.725252, 0.72535, 0.725448, 0.725546, 0.725644, 0.725742,
0.72584, 0.725938, 0.726036, 0.726134, 0.726232, 0.72633, 0.726428, 0.726526, 0.726624, 0.726722, 0.726819, 0.726917, 0.727015, 0.727113, 0.727211, 0.727308, 0.727406, 0.727504, 0.727602, 0.727699, 0.727797, 0.727895, 0.727993, 0.72809, 0.728188, 0.728286, 0.728383, 0.728481, 0.728578, 0.728676, 0.728774, 0.728871, 0.728969, 0.729066, 0.729164, 0.729261, 0.729359, 0.729456, 0.729554, 0.729651, 0.729748, 0.729846, 0.729943, 0.730041, 0.730138, 0.730235, 0.730333, 0.73043, 0.730527, 0.730625, 0.730722, 0.730819, 0.730916, 0.731014, 0.731111, 0.731208, 0.731305, 0.731402, 0.731499, 0.731597, 0.731694, 0.731791, 0.731888, 0.731985, 0.732082, 0.732179, 0.732276, 0.732373, 0.73247, 0.732567, 0.732664, 0.732761, 0.732858, 0.732955, 0.733052, 0.733149, 0.733246, 0.733343, 0.733439, 0.733536, 0.733633, 0.73373, 0.733827, 0.733923, 0.73402, 0.734117, 0.734214, 0.73431, 0.734407, 0.734504, 0.734601, 0.734697, 0.734794, 0.73489, 0.734987, 0.735084, 0.73518, 0.735277, 0.735373, 0.73547,
0.735566, 0.735663, 0.735759, 0.735856, 0.735952, 0.736049, 0.736145, 0.736242, 0.736338, 0.736435, 0.736531, 0.736627, 0.736724, 0.73682, 0.736916, 0.737013, 0.737109, 0.737205, 0.737301, 0.737398, 0.737494, 0.73759, 0.737686, 0.737782, 0.737879, 0.737975, 0.738071, 0.738167, 0.738263, 0.738359, 0.738455, 0.738551, 0.738647, 0.738744, 0.73884, 0.738936, 0.739032, 0.739127, 0.739223, 0.739319, 0.739415, 0.739511, 0.739607, 0.739703, 0.739799, 0.739895, 0.739991, 0.740086, 0.740182, 0.740278, 0.740374, 0.74047, 0.740565, 0.740661, 0.740757, 0.740852, 0.740948, 0.741044, 0.741139, 0.741235, 0.741331, 0.741426, 0.741522, 0.741618, 0.741713, 0.741809, 0.741904, 0.742, 0.742095, 0.742191, 0.742286, 0.742382, 0.742477, 0.742573, 0.742668, 0.742763, 0.742859, 0.742954, 0.743049, 0.743145, 0.74324, 0.743335, 0.743431, 0.743526, 0.743621, 0.743717, 0.743812, 0.743907, 0.744002, 0.744097, 0.744193, 0.744288, 0.744383, 0.744478, 0.744573, 0.744668, 0.744763, 0.744858, 0.744953, 0.745049,
0.745144, 0.745239, 0.745334, 0.745429, 0.745523, 0.745618, 0.745713, 0.745808, 0.745903, 0.745998, 0.746093, 0.746188, 0.746283, 0.746377, 0.746472, 0.746567, 0.746662, 0.746757, 0.746851, 0.746946, 0.747041, 0.747136, 0.74723, 0.747325, 0.74742, 0.747514, 0.747609, 0.747704, 0.747798, 0.747893, 0.747987, 0.748082, 0.748176, 0.748271, 0.748365, 0.74846, 0.748554, 0.748649, 0.748743, 0.748838, 0.748932, 0.749027, 0.749121, 0.749215, 0.74931, 0.749404, 0.749498, 0.749593, 0.749687, 0.749781, 0.749875, 0.74997, 0.750064, 0.750158, 0.750252, 0.750347, 0.750441, 0.750535, 0.750629, 0.750723, 0.750817, 0.750911, 0.751005, 0.7511, 0.751194, 0.751288, 0.751382, 0.751476, 0.75157, 0.751664, 0.751758, 0.751852, 0.751945, 0.752039, 0.752133, 0.752227, 0.752321, 0.752415, 0.752509, 0.752603, 0.752696, 0.75279, 0.752884, 0.752978, 0.753071, 0.753165, 0.753259, 0.753353, 0.753446, 0.75354, 0.753634, 0.753727, 0.753821, 0.753915, 0.754008, 0.754102, 0.754195, 0.754289, 0.754382, 0.754476,
0.754569, 0.754663, 0.754756, 0.75485, 0.754943, 0.755037, 0.75513, 0.755223, 0.755317, 0.75541, 0.755504, 0.755597, 0.75569, 0.755784, 0.755877, 0.75597, 0.756063, 0.756157, 0.75625, 0.756343, 0.756436, 0.756529, 0.756623, 0.756716, 0.756809, 0.756902, 0.756995, 0.757088, 0.757181, 0.757274, 0.757367, 0.75746, 0.757553, 0.757646, 0.757739, 0.757832, 0.757925, 0.758018, 0.758111, 0.758204, 0.758297, 0.75839, 0.758483, 0.758575, 0.758668, 0.758761, 0.758854, 0.758947, 0.759039, 0.759132, 0.759225, 0.759318, 0.75941, 0.759503, 0.759596, 0.759688, 0.759781, 0.759874, 0.759966, 0.760059, 0.760151, 0.760244, 0.760337, 0.760429, 0.760522, 0.760614, 0.760707, 0.760799, 0.760892, 0.760984, 0.761076, 0.761169, 0.761261, 0.761354, 0.761446, 0.761538, 0.761631, 0.761723, 0.761815, 0.761908, 0.762, 0.762092, 0.762184, 0.762277, 0.762369, 0.762461, 0.762553, 0.762645, 0.762737, 0.76283, 0.762922, 0.763014, 0.763106, 0.763198, 0.76329, 0.763382, 0.763474, 0.763566, 0.763658, 0.76375,
0.763842, 0.763934, 0.764026, 0.764118, 0.76421, 0.764302, 0.764393, 0.764485, 0.764577, 0.764669, 0.764761, 0.764853, 0.764944, 0.765036, 0.765128, 0.76522, 0.765311, 0.765403, 0.765495, 0.765586, 0.765678, 0.76577, 0.765861, 0.765953, 0.766044, 0.766136, 0.766228, 0.766319, 0.766411, 0.766502, 0.766594, 0.766685, 0.766777, 0.766868, 0.766959, 0.767051, 0.767142, 0.767234, 0.767325, 0.767416, 0.767508, 0.767599, 0.76769, 0.767782, 0.767873, 0.767964, 0.768055, 0.768147, 0.768238, 0.768329, 0.76842, 0.768511, 0.768603, 0.768694, 0.768785, 0.768876, 0.768967, 0.769058, 0.769149, 0.76924, 0.769331, 0.769422, 0.769513, 0.769604, 0.769695, 0.769786, 0.769877, 0.769968, 0.770059, 0.77015, 0.770241, 0.770332, 0.770422, 0.770513, 0.770604, 0.770695, 0.770786, 0.770876, 0.770967, 0.771058, 0.771149, 0.771239, 0.77133, 0.771421, 0.771511, 0.771602, 0.771693, 0.771783, 0.771874, 0.771964, 0.772055, 0.772145, 0.772236, 0.772326, 0.772417, 0.772507, 0.772598, 0.772688, 0.772779, 0.772869,
0.77296, 0.77305, 0.77314, 0.773231, 0.773321, 0.773411, 0.773502, 0.773592, 0.773682, 0.773773, 0.773863, 0.773953, 0.774043, 0.774133, 0.774224, 0.774314, 0.774404, 0.774494, 0.774584, 0.774674, 0.774764, 0.774854, 0.774945, 0.775035, 0.775125, 0.775215, 0.775305, 0.775395, 0.775485, 0.775574, 0.775664, 0.775754, 0.775844, 0.775934, 0.776024, 0.776114, 0.776204, 0.776293, 0.776383, 0.776473, 0.776563, 0.776653, 0.776742, 0.776832, 0.776922, 0.777011, 0.777101, 0.777191, 0.77728, 0.77737, 0.77746, 0.777549, 0.777639, 0.777728, 0.777818, 0.777908, 0.777997, 0.778087, 0.778176, 0.778266, 0.778355, 0.778444, 0.778534, 0.778623, 0.778713, 0.778802, 0.778891, 0.778981, 0.77907, 0.779159, 0.779249, 0.779338, 0.779427, 0.779517, 0.779606, 0.779695, 0.779784, 0.779873, 0.779963, 0.780052, 0.780141, 0.78023, 0.780319, 0.780408, 0.780497, 0.780586, 0.780675, 0.780764, 0.780853, 0.780942, 0.781031, 0.78112, 0.781209, 0.781298, 0.781387, 0.781476, 0.781565, 0.781654, 0.781743, 0.781831,
0.78192, 0.782009, 0.782098, 0.782187, 0.782275, 0.782364, 0.782453, 0.782542, 0.78263, 0.782719, 0.782808, 0.782896, 0.782985, 0.783074, 0.783162, 0.783251, 0.783339, 0.783428, 0.783516, 0.783605, 0.783693, 0.783782, 0.78387, 0.783959, 0.784047, 0.784136, 0.784224, 0.784313, 0.784401, 0.784489, 0.784578, 0.784666, 0.784754, 0.784843, 0.784931, 0.785019, 0.785107, 0.785196, 0.785284, 0.785372, 0.78546, 0.785548, 0.785637, 0.785725, 0.785813, 0.785901, 0.785989, 0.786077, 0.786165, 0.786253, 0.786341, 0.786429, 0.786517, 0.786605, 0.786693, 0.786781, 0.786869, 0.786957, 0.787045, 0.787133, 0.787221, 0.787309, 0.787396, 0.787484, 0.787572, 0.78766, 0.787748, 0.787835, 0.787923, 0.788011, 0.788098, 0.788186, 0.788274, 0.788362, 0.788449, 0.788537, 0.788624, 0.788712, 0.7888, 0.788887, 0.788975, 0.789062, 0.78915, 0.789237, 0.789325, 0.789412, 0.7895, 0.789587, 0.789675, 0.789762, 0.789849, 0.789937, 0.790024, 0.790111, 0.790199, 0.790286, 0.790373, 0.790461, 0.790548, 0.790635,
0.790722, 0.79081, 0.790897, 0.790984, 0.791071, 0.791158, 0.791245, 0.791332, 0.79142, 0.791507, 0.791594, 0.791681, 0.791768, 0.791855, 0.791942, 0.792029, 0.792116, 0.792203, 0.79229, 0.792377, 0.792463, 0.79255, 0.792637, 0.792724, 0.792811, 0.792898, 0.792985, 0.793071, 0.793158, 0.793245, 0.793332, 0.793418, 0.793505, 0.793592, 0.793678, 0.793765, 0.793852, 0.793938, 0.794025, 0.794112, 0.794198, 0.794285, 0.794371, 0.794458, 0.794544, 0.794631, 0.794717, 0.794804, 0.79489, 0.794977, 0.795063, 0.79515, 0.795236, 0.795322, 0.795409, 0.795495, 0.795581, 0.795668, 0.795754, 0.79584, 0.795927, 0.796013, 0.796099, 0.796185, 0.796271, 0.796358, 0.796444, 0.79653, 0.796616, 0.796702, 0.796788, 0.796874, 0.79696, 0.797046, 0.797133, 0.797219, 0.797305, 0.797391, 0.797477, 0.797562, 0.797648, 0.797734, 0.79782, 0.797906, 0.797992, 0.798078, 0.798164, 0.79825, 0.798335, 0.798421, 0.798507, 0.798593, 0.798678, 0.798764, 0.79885, 0.798936, 0.799021, 0.799107, 0.799193, 0.799278,
0.799364, 0.799449, 0.799535, 0.799621, 0.799706, 0.799792, 0.799877, 0.799963, 0.800048, 0.800134, 0.800219, 0.800304, 0.80039, 0.800475, 0.800561, 0.800646, 0.800731, 0.800817, 0.800902, 0.800987, 0.801073, 0.801158, 0.801243, 0.801328, 0.801414, 0.801499, 0.801584, 0.801669, 0.801754, 0.80184, 0.801925, 0.80201, 0.802095, 0.80218, 0.802265, 0.80235, 0.802435, 0.80252, 0.802605, 0.80269, 0.802775, 0.80286, 0.802945, 0.80303, 0.803115, 0.8032, 0.803284, 0.803369, 0.803454, 0.803539, 0.803624, 0.803709, 0.803793, 0.803878, 0.803963, 0.804048, 0.804132, 0.804217, 0.804302, 0.804386, 0.804471, 0.804555, 0.80464, 0.804725, 0.804809, 0.804894, 0.804978, 0.805063, 0.805147, 0.805232, 0.805316, 0.805401, 0.805485, 0.80557, 0.805654, 0.805738, 0.805823, 0.805907, 0.805992, 0.806076, 0.80616, 0.806244, 0.806329, 0.806413, 0.806497, 0.806582, 0.806666, 0.80675, 0.806834, 0.806918, 0.807002, 0.807087, 0.807171, 0.807255, 0.807339, 0.807423, 0.807507, 0.807591, 0.807675, 0.807759,
0.807843, 0.807927, 0.808011, 0.808095, 0.808179, 0.808263, 0.808347, 0.80843, 0.808514, 0.808598, 0.808682, 0.808766, 0.808849, 0.808933, 0.809017, 0.809101, 0.809184, 0.809268, 0.809352, 0.809436, 0.809519, 0.809603, 0.809686, 0.80977, 0.809854, 0.809937, 0.810021, 0.810104, 0.810188, 0.810271, 0.810355, 0.810438, 0.810522, 0.810605, 0.810689, 0.810772, 0.810855, 0.810939, 0.811022, 0.811106, 0.811189, 0.811272, 0.811355, 0.811439, 0.811522, 0.811605, 0.811688, 0.811772, 0.811855, 0.811938, 0.812021, 0.812104, 0.812187, 0.812271, 0.812354, 0.812437, 0.81252, 0.812603, 0.812686, 0.812769, 0.812852, 0.812935, 0.813018, 0.813101, 0.813184, 0.813267, 0.81335, 0.813432, 0.813515, 0.813598, 0.813681, 0.813764, 0.813847, 0.813929, 0.814012, 0.814095, 0.814178, 0.81426, 0.814343, 0.814426, 0.814508, 0.814591, 0.814674, 0.814756, 0.814839, 0.814921, 0.815004, 0.815087, 0.815169, 0.815252, 0.815334, 0.815417, 0.815499, 0.815581, 0.815664, 0.815746, 0.815829, 0.815911, 0.815994, 0.816076,
0.816158, 0.816241, 0.816323, 0.816405, 0.816487, 0.81657, 0.816652, 0.816734, 0.816816, 0.816898, 0.816981, 0.817063, 0.817145, 0.817227, 0.817309, 0.817391, 0.817473, 0.817555, 0.817637, 0.817719, 0.817801, 0.817883, 0.817965, 0.818047, 0.818129, 0.818211, 0.818293, 0.818375, 0.818457, 0.818539, 0.818621, 0.818702, 0.818784, 0.818866, 0.818948, 0.819029, 0.819111, 0.819193, 0.819275, 0.819356, 0.819438, 0.81952, 0.819601, 0.819683, 0.819764, 0.819846, 0.819928, 0.820009, 0.820091, 0.820172, 0.820254, 0.820335, 0.820417, 0.820498, 0.82058, 0.820661, 0.820742, 0.820824, 0.820905, 0.820987, 0.821068, 0.821149, 0.821231, 0.821312, 0.821393, 0.821474, 0.821556, 0.821637, 0.821718, 0.821799, 0.82188, 0.821962, 0.822043, 0.822124, 0.822205, 0.822286, 0.822367, 0.822448, 0.822529, 0.82261, 0.822691, 0.822772, 0.822853, 0.822934, 0.823015, 0.823096, 0.823177, 0.823258, 0.823339, 0.823419, 0.8235, 0.823581, 0.823662, 0.823743, 0.823823, 0.823904, 0.823985, 0.824066, 0.824146, 0.824227,
0.824308, 0.824388, 0.824469, 0.82455, 0.82463, 0.824711, 0.824791, 0.824872, 0.824952, 0.825033, 0.825114, 0.825194, 0.825274, 0.825355, 0.825435, 0.825516, 0.825596, 0.825677, 0.825757, 0.825837, 0.825918, 0.825998, 0.826078, 0.826159, 0.826239, 0.826319, 0.826399, 0.826479, 0.82656, 0.82664, 0.82672, 0.8268, 0.82688, 0.82696, 0.827041, 0.827121, 0.827201, 0.827281, 0.827361, 0.827441, 0.827521, 0.827601, 0.827681, 0.827761, 0.827841, 0.827921, 0.828, 0.82808, 0.82816, 0.82824, 0.82832, 0.8284, 0.828479, 0.828559, 0.828639, 0.828719, 0.828798, 0.828878, 0.828958, 0.829038, 0.829117, 0.829197, 0.829277, 0.829356, 0.829436, 0.829515, 0.829595, 0.829674, 0.829754, 0.829833, 0.829913, 0.829992, 0.830072, 0.830151, 0.830231, 0.83031, 0.83039, 0.830469, 0.830548, 0.830628, 0.830707, 0.830786, 0.830866, 0.830945, 0.831024, 0.831103, 0.831183, 0.831262, 0.831341, 0.83142, 0.831499, 0.831578, 0.831658, 0.831737, 0.831816, 0.831895, 0.831974, 0.832053, 0.832132, 0.832211,
0.83229, 0.832369, 0.832448, 0.832527, 0.832606, 0.832685, 0.832764, 0.832842, 0.832921, 0.833, 0.833079, 0.833158, 0.833237, 0.833315, 0.833394, 0.833473, 0.833551, 0.83363, 0.833709, 0.833788, 0.833866, 0.833945, 0.834023, 0.834102, 0.834181, 0.834259, 0.834338, 0.834416, 0.834495, 0.834573, 0.834652, 0.83473, 0.834809, 0.834887, 0.834966, 0.835044, 0.835122, 0.835201, 0.835279, 0.835357, 0.835436, 0.835514, 0.835592, 0.83567, 0.835749, 0.835827, 0.835905, 0.835983, 0.836062, 0.83614, 0.836218, 0.836296, 0.836374, 0.836452, 0.83653, 0.836608, 0.836686, 0.836764, 0.836842, 0.83692, 0.836998, 0.837076, 0.837154, 0.837232, 0.83731, 0.837388, 0.837466, 0.837544, 0.837621, 0.837699, 0.837777, 0.837855, 0.837933, 0.83801, 0.838088, 0.838166, 0.838244, 0.838321, 0.838399, 0.838477, 0.838554, 0.838632, 0.838709, 0.838787, 0.838865, 0.838942, 0.83902, 0.839097, 0.839175, 0.839252, 0.83933, 0.839407, 0.839484, 0.839562, 0.839639, 0.839717, 0.839794, 0.839871, 0.839949, 0.840026,
0.840103, 0.840181, 0.840258, 0.840335, 0.840412, 0.840489, 0.840567, 0.840644, 0.840721, 0.840798, 0.840875, 0.840952, 0.841029, 0.841106, 0.841184, 0.841261, 0.841338, 0.841415, 0.841492, 0.841569, 0.841645, 0.841722, 0.841799, 0.841876, 0.841953, 0.84203, 0.842107, 0.842184, 0.84226, 0.842337, 0.842414, 0.842491, 0.842568, 0.842644, 0.842721, 0.842798, 0.842874, 0.842951, 0.843028, 0.843104, 0.843181, 0.843257, 0.843334, 0.843411, 0.843487, 0.843564, 0.84364, 0.843717, 0.843793, 0.84387, 0.843946, 0.844022, 0.844099, 0.844175, 0.844252, 0.844328, 0.844404, 0.844481, 0.844557, 0.844633, 0.844709, 0.844786, 0.844862, 0.844938, 0.845014, 0.845091, 0.845167, 0.845243, 0.845319, 0.845395, 0.845471, 0.845547, 0.845623, 0.845699, 0.845775, 0.845851, 0.845927, 0.846003, 0.846079, 0.846155, 0.846231, 0.846307, 0.846383, 0.846459, 0.846535, 0.84661, 0.846686, 0.846762, 0.846838, 0.846914, 0.846989, 0.847065, 0.847141, 0.847217, 0.847292, 0.847368, 0.847444, 0.847519, 0.847595, 0.84767,
0.847746, 0.847822, 0.847897, 0.847973, 0.848048, 0.848124, 0.848199, 0.848275, 0.84835, 0.848425, 0.848501, 0.848576, 0.848652, 0.848727, 0.848802, 0.848878, 0.848953, 0.849028, 0.849103, 0.849179, 0.849254, 0.849329, 0.849404, 0.84948, 0.849555, 0.84963, 0.849705, 0.84978, 0.849855, 0.84993, 0.850005, 0.85008, 0.850155, 0.85023, 0.850305, 0.85038, 0.850455, 0.85053, 0.850605, 0.85068, 0.850755, 0.85083, 0.850905, 0.85098, 0.851054, 0.851129, 0.851204, 0.851279, 0.851353, 0.851428, 0.851503, 0.851578, 0.851652, 0.851727, 0.851802, 0.851876, 0.851951, 0.852025, 0.8521, 0.852175, 0.852249, 0.852324, 0.852398, 0.852473, 0.852547, 0.852622, 0.852696, 0.85277, 0.852845, 0.852919, 0.852994, 0.853068, 0.853142, 0.853217, 0.853291, 0.853365, 0.853439, 0.853514, 0.853588, 0.853662, 0.853736, 0.853811, 0.853885, 0.853959, 0.854033, 0.854107, 0.854181, 0.854255, 0.854329, 0.854403, 0.854477, 0.854551, 0.854625, 0.854699, 0.854773, 0.854847, 0.854921, 0.854995, 0.855069, 0.855143,
0.855217, 0.85529, 0.855364, 0.855438, 0.855512, 0.855586, 0.855659, 0.855733, 0.855807, 0.85588, 0.855954, 0.856028, 0.856101, 0.856175, 0.856249, 0.856322, 0.856396, 0.856469, 0.856543, 0.856616, 0.85669, 0.856763, 0.856837, 0.85691, 0.856984, 0.857057, 0.857131, 0.857204, 0.857277, 0.857351, 0.857424, 0.857497, 0.857571, 0.857644, 0.857717, 0.85779, 0.857864, 0.857937, 0.85801, 0.858083, 0.858156, 0.85823, 0.858303, 0.858376, 0.858449, 0.858522, 0.858595, 0.858668, 0.858741, 0.858814, 0.858887, 0.85896, 0.859033, 0.859106, 0.859179, 0.859252, 0.859324, 0.859397, 0.85947, 0.859543, 0.859616, 0.859689, 0.859761, 0.859834, 0.859907, 0.85998, 0.860052, 0.860125, 0.860198, 0.86027, 0.860343, 0.860415, 0.860488, 0.860561, 0.860633, 0.860706, 0.860778, 0.860851, 0.860923, 0.860996, 0.861068, 0.861141, 0.861213, 0.861285, 0.861358, 0.86143, 0.861503, 0.861575, 0.861647, 0.86172, 0.861792, 0.861864, 0.861936, 0.862009, 0.862081, 0.862153, 0.862225, 0.862297, 0.862369, 0.862442,
0.862514, 0.862586, 0.862658, 0.86273, 0.862802, 0.862874, 0.862946, 0.863018, 0.86309, 0.863162, 0.863234, 0.863306, 0.863378, 0.863449, 0.863521, 0.863593, 0.863665, 0.863737, 0.863809, 0.86388, 0.863952, 0.864024, 0.864096, 0.864167, 0.864239, 0.864311, 0.864382, 0.864454, 0.864526, 0.864597, 0.864669, 0.86474, 0.864812, 0.864883, 0.864955, 0.865026, 0.865098, 0.865169, 0.865241, 0.865312, 0.865384, 0.865455, 0.865526, 0.865598, 0.865669, 0.86574, 0.865812, 0.865883, 0.865954, 0.866025, 0.866097, 0.866168, 0.866239, 0.86631, 0.866381, 0.866453, 0.866524, 0.866595, 0.866666, 0.866737, 0.866808, 0.866879, 0.86695, 0.867021, 0.867092, 0.867163, 0.867234, 0.867305, 0.867376, 0.867447, 0.867518, 0.867588, 0.867659, 0.86773, 0.867801, 0.867872, 0.867942, 0.868013, 0.868084, 0.868155, 0.868225, 0.868296, 0.868367, 0.868437, 0.868508, 0.868579, 0.868649, 0.86872, 0.86879, 0.868861, 0.868931, 0.869002, 0.869072, 0.869143, 0.869213, 0.869284, 0.869354, 0.869425, 0.869495, 0.869565,
0.869636, 0.869706, 0.869776, 0.869847, 0.869917, 0.869987, 0.870057, 0.870128, 0.870198, 0.870268, 0.870338, 0.870408, 0.870478, 0.870549, 0.870619, 0.870689, 0.870759, 0.870829, 0.870899, 0.870969, 0.871039, 0.871109, 0.871179, 0.871249, 0.871319, 0.871389, 0.871459, 0.871528, 0.871598, 0.871668, 0.871738, 0.871808, 0.871877, 0.871947, 0.872017, 0.872087, 0.872156, 0.872226, 0.872296, 0.872365, 0.872435, 0.872505, 0.872574, 0.872644, 0.872713, 0.872783, 0.872853, 0.872922, 0.872992, 0.873061, 0.873131, 0.8732, 0.873269, 0.873339, 0.873408, 0.873478, 0.873547, 0.873616, 0.873686, 0.873755, 0.873824, 0.873893, 0.873963, 0.874032, 0.874101, 0.87417, 0.87424, 0.874309, 0.874378, 0.874447, 0.874516, 0.874585, 0.874654, 0.874723, 0.874792, 0.874861, 0.87493, 0.874999, 0.875068, 0.875137, 0.875206, 0.875275, 0.875344, 0.875413, 0.875482, 0.875551, 0.875619, 0.875688, 0.875757, 0.875826, 0.875895, 0.875963, 0.876032, 0.876101, 0.876169, 0.876238, 0.876307, 0.876375, 0.876444, 0.876513,
0.876581, 0.87665, 0.876718, 0.876787, 0.876855, 0.876924, 0.876992, 0.877061, 0.877129, 0.877197, 0.877266, 0.877334, 0.877403, 0.877471, 0.877539, 0.877608, 0.877676, 0.877744, 0.877812, 0.877881, 0.877949, 0.878017, 0.878085, 0.878153, 0.878222, 0.87829, 0.878358, 0.878426, 0.878494, 0.878562, 0.87863, 0.878698, 0.878766, 0.878834, 0.878902, 0.87897, 0.879038, 0.879106, 0.879174, 0.879242, 0.87931, 0.879377, 0.879445, 0.879513, 0.879581, 0.879649, 0.879716, 0.879784, 0.879852, 0.87992, 0.879987, 0.880055, 0.880123, 0.88019, 0.880258, 0.880325, 0.880393, 0.88046, 0.880528, 0.880596, 0.880663, 0.880731, 0.880798, 0.880865, 0.880933, 0.881, 0.881068, 0.881135, 0.881202, 0.88127, 0.881337, 0.881404, 0.881472, 0.881539, 0.881606, 0.881673, 0.881741, 0.881808, 0.881875, 0.881942, 0.882009, 0.882077, 0.882144, 0.882211, 0.882278, 0.882345, 0.882412, 0.882479, 0.882546, 0.882613, 0.88268, 0.882747, 0.882814, 0.882881, 0.882948, 0.883014, 0.883081, 0.883148, 0.883215, 0.883282,
0.883349, 0.883415, 0.883482, 0.883549, 0.883616, 0.883682, 0.883749, 0.883816, 0.883882, 0.883949, 0.884016, 0.884082, 0.884149, 0.884215, 0.884282, 0.884348, 0.884415, 0.884481, 0.884548, 0.884614, 0.884681, 0.884747, 0.884813, 0.88488, 0.884946, 0.885013, 0.885079, 0.885145, 0.885211, 0.885278, 0.885344, 0.88541, 0.885476, 0.885543, 0.885609, 0.885675, 0.885741, 0.885807, 0.885873, 0.885939, 0.886005, 0.886072, 0.886138, 0.886204, 0.88627, 0.886336, 0.886402, 0.886467, 0.886533, 0.886599, 0.886665, 0.886731, 0.886797, 0.886863, 0.886929, 0.886994, 0.88706, 0.887126, 0.887192, 0.887257, 0.887323, 0.887389, 0.887455, 0.88752, 0.887586, 0.887651, 0.887717, 0.887783, 0.887848, 0.887914, 0.887979, 0.888045, 0.88811, 0.888176, 0.888241, 0.888307, 0.888372, 0.888437, 0.888503, 0.888568, 0.888634, 0.888699, 0.888764, 0.88883, 0.888895, 0.88896, 0.889025, 0.889091, 0.889156, 0.889221, 0.889286, 0.889351, 0.889416, 0.889482, 0.889547, 0.889612, 0.889677, 0.889742, 0.889807, 0.889872,
0.889937, 0.890002, 0.890067, 0.890132, 0.890197, 0.890261, 0.890326, 0.890391, 0.890456, 0.890521, 0.890586, 0.890651, 0.890715, 0.89078, 0.890845, 0.890909, 0.890974, 0.891039, 0.891104, 0.891168, 0.891233, 0.891297, 0.891362, 0.891427, 0.891491, 0.891556, 0.89162, 0.891685, 0.891749, 0.891814, 0.891878, 0.891943, 0.892007, 0.892071, 0.892136, 0.8922, 0.892264, 0.892329, 0.892393, 0.892457, 0.892522, 0.892586, 0.89265, 0.892714, 0.892778, 0.892843, 0.892907, 0.892971, 0.893035, 0.893099, 0.893163, 0.893227, 0.893291, 0.893355, 0.893419, 0.893483, 0.893547, 0.893611, 0.893675, 0.893739, 0.893803, 0.893867, 0.893931, 0.893995, 0.894059, 0.894122, 0.894186, 0.89425, 0.894314, 0.894377, 0.894441, 0.894505, 0.894569, 0.894632, 0.894696, 0.894759, 0.894823, 0.894887, 0.89495, 0.895014, 0.895077, 0.895141, 0.895204, 0.895268, 0.895331, 0.895395, 0.895458, 0.895522, 0.895585, 0.895648, 0.895712, 0.895775, 0.895838, 0.895902, 0.895965, 0.896028, 0.896092, 0.896155, 0.896218, 0.896281,
0.896344, 0.896408, 0.896471, 0.896534, 0.896597, 0.89666, 0.896723, 0.896786, 0.896849, 0.896912, 0.896975, 0.897038, 0.897101, 0.897164, 0.897227, 0.89729, 0.897353, 0.897416, 0.897478, 0.897541, 0.897604, 0.897667, 0.89773, 0.897792, 0.897855, 0.897918, 0.897981, 0.898043, 0.898106, 0.898169, 0.898231, 0.898294, 0.898356, 0.898419, 0.898482, 0.898544, 0.898607, 0.898669, 0.898732, 0.898794, 0.898857, 0.898919, 0.898981, 0.899044, 0.899106, 0.899168, 0.899231, 0.899293, 0.899355, 0.899418, 0.89948, 0.899542, 0.899604, 0.899667, 0.899729, 0.899791, 0.899853, 0.899915, 0.899977, 0.90004, 0.900102, 0.900164, 0.900226, 0.900288, 0.90035, 0.900412, 0.900474, 0.900536, 0.900598, 0.90066, 0.900721, 0.900783, 0.900845, 0.900907, 0.900969, 0.901031, 0.901092, 0.901154, 0.901216, 0.901278, 0.901339, 0.901401, 0.901463, 0.901525, 0.901586, 0.901648, 0.901709, 0.901771, 0.901833, 0.901894, 0.901956, 0.902017, 0.902079, 0.90214, 0.902202, 0.902263, 0.902324, 0.902386, 0.902447, 0.902509,
0.90257, 0.902631, 0.902693, 0.902754, 0.902815, 0.902876, 0.902938, 0.902999, 0.90306, 0.903121, 0.903182, 0.903244, 0.903305, 0.903366, 0.903427, 0.903488, 0.903549, 0.90361, 0.903671, 0.903732, 0.903793, 0.903854, 0.903915, 0.903976, 0.904037, 0.904098, 0.904159, 0.90422, 0.90428, 0.904341, 0.904402, 0.904463, 0.904524, 0.904584, 0.904645, 0.904706, 0.904766, 0.904827, 0.904888, 0.904948, 0.905009, 0.90507, 0.90513, 0.905191, 0.905251, 0.905312, 0.905372, 0.905433, 0.905493, 0.905554, 0.905614, 0.905675, 0.905735, 0.905795, 0.905856, 0.905916, 0.905976, 0.906037, 0.906097, 0.906157, 0.906217, 0.906278, 0.906338, 0.906398, 0.906458, 0.906518, 0.906579, 0.906639, 0.906699, 0.906759, 0.906819, 0.906879, 0.906939, 0.906999, 0.907059, 0.907119, 0.907179, 0.907239, 0.907299, 0.907359, 0.907419, 0.907478, 0.907538, 0.907598, 0.907658, 0.907718, 0.907777, 0.907837, 0.907897, 0.907957, 0.908016, 0.908076, 0.908136, 0.908195, 0.908255, 0.908315, 0.908374, 0.908434, 0.908493, 0.908553,
0.908612, 0.908672, 0.908731, 0.908791, 0.90885, 0.90891, 0.908969, 0.909028, 0.909088, 0.909147, 0.909206, 0.909266, 0.909325, 0.909384, 0.909444, 0.909503, 0.909562, 0.909621, 0.90968, 0.90974, 0.909799, 0.909858, 0.909917, 0.909976, 0.910035, 0.910094, 0.910153, 0.910212, 0.910271, 0.91033, 0.910389, 0.910448, 0.910507, 0.910566, 0.910625, 0.910684, 0.910743, 0.910801, 0.91086, 0.910919, 0.910978, 0.911036, 0.911095, 0.911154, 0.911213, 0.911271, 0.91133, 0.911389, 0.911447, 0.911506, 0.911564, 0.911623, 0.911682, 0.91174, 0.911799, 0.911857, 0.911916, 0.911974, 0.912033, 0.912091, 0.912149, 0.912208, 0.912266, 0.912324, 0.912383, 0.912441, 0.912499, 0.912558, 0.912616, 0.912674, 0.912732, 0.912791, 0.912849, 0.912907, 0.912965, 0.913023, 0.913081, 0.913139, 0.913197, 0.913255, 0.913314, 0.913372, 0.91343, 0.913488, 0.913545, 0.913603, 0.913661, 0.913719, 0.913777, 0.913835, 0.913893, 0.913951, 0.914008, 0.914066, 0.914124, 0.914182, 0.91424, 0.914297, 0.914355, 0.914413,
0.91447, 0.914528, 0.914586, 0.914643, 0.914701, 0.914758, 0.914816, 0.914873, 0.914931, 0.914988, 0.915046, 0.915103, 0.915161, 0.915218, 0.915276, 0.915333, 0.91539, 0.915448, 0.915505, 0.915562, 0.91562, 0.915677, 0.915734, 0.915791, 0.915849, 0.915906, 0.915963, 0.91602, 0.916077, 0.916134, 0.916192, 0.916249, 0.916306, 0.916363, 0.91642, 0.916477, 0.916534, 0.916591, 0.916648, 0.916705, 0.916762, 0.916818, 0.916875, 0.916932, 0.916989, 0.917046, 0.917103, 0.917159, 0.917216, 0.917273, 0.91733, 0.917386, 0.917443, 0.9175, 0.917556, 0.917613, 0.91767, 0.917726, 0.917783, 0.917839, 0.917896, 0.917953, 0.918009, 0.918066, 0.918122, 0.918178, 0.918235, 0.918291, 0.918348, 0.918404, 0.91846, 0.918517, 0.918573, 0.918629, 0.918686, 0.918742, 0.918798, 0.918854, 0.918911, 0.918967, 0.919023, 0.919079, 0.919135, 0.919191, 0.919248, 0.919304, 0.91936, 0.919416, 0.919472, 0.919528, 0.919584, 0.91964, 0.919696, 0.919752, 0.919808, 0.919863, 0.919919, 0.919975, 0.920031, 0.920087,
0.920143, 0.920198, 0.920254, 0.92031, 0.920366, 0.920421, 0.920477, 0.920533, 0.920588, 0.920644, 0.9207, 0.920755, 0.920811, 0.920866, 0.920922, 0.920977, 0.921033, 0.921088, 0.921144, 0.921199, 0.921255, 0.92131, 0.921366, 0.921421, 0.921476, 0.921532, 0.921587, 0.921642, 0.921697, 0.921753, 0.921808, 0.921863, 0.921918, 0.921974, 0.922029, 0.922084, 0.922139, 0.922194, 0.922249, 0.922304, 0.922359, 0.922414, 0.922469, 0.922524, 0.922579, 0.922634, 0.922689, 0.922744, 0.922799, 0.922854, 0.922909, 0.922964, 0.923018, 0.923073, 0.923128, 0.923183, 0.923238, 0.923292, 0.923347, 0.923402, 0.923456, 0.923511, 0.923566, 0.92362, 0.923675, 0.92373, 0.923784, 0.923839, 0.923893, 0.923948, 0.924002, 0.924057, 0.924111, 0.924166, 0.92422, 0.924274, 0.924329, 0.924383, 0.924437, 0.924492, 0.924546, 0.9246, 0.924655, 0.924709, 0.924763, 0.924817, 0.924871, 0.924926, 0.92498, 0.925034, 0.925088, 0.925142, 0.925196, 0.92525, 0.925304, 0.925358, 0.925412, 0.925466, 0.92552, 0.925574,
0.925628, 0.925682, 0.925736, 0.92579, 0.925844, 0.925898, 0.925951, 0.926005, 0.926059, 0.926113, 0.926166, 0.92622, 0.926274, 0.926328, 0.926381, 0.926435, 0.926488, 0.926542, 0.926596, 0.926649, 0.926703, 0.926756, 0.92681, 0.926863, 0.926917, 0.92697, 0.927024, 0.927077, 0.92713, 0.927184, 0.927237, 0.927291, 0.927344, 0.927397, 0.92745, 0.927504, 0.927557, 0.92761, 0.927663, 0.927717, 0.92777, 0.927823, 0.927876, 0.927929, 0.927982, 0.928035, 0.928088, 0.928142, 0.928195, 0.928248, 0.928301, 0.928354, 0.928406, 0.928459, 0.928512, 0.928565, 0.928618, 0.928671, 0.928724, 0.928777, 0.928829, 0.928882, 0.928935, 0.928988, 0.92904, 0.929093, 0.929146, 0.929198, 0.929251, 0.929304, 0.929356, 0.929409, 0.929461, 0.929514, 0.929567, 0.929619, 0.929672, 0.929724, 0.929776, 0.929829, 0.929881, 0.929934, 0.929986, 0.930039, 0.930091, 0.930143, 0.930195, 0.930248, 0.9303, 0.930352, 0.930405, 0.930457, 0.930509, 0.930561, 0.930613, 0.930665, 0.930718, 0.93077, 0.930822, 0.930874,
0.930926, 0.930978, 0.93103, 0.931082, 0.931134, 0.931186, 0.931238, 0.93129, 0.931341, 0.931393, 0.931445, 0.931497, 0.931549, 0.931601, 0.931652, 0.931704, 0.931756, 0.931808, 0.931859, 0.931911, 0.931963, 0.932014, 0.932066, 0.932118, 0.932169, 0.932221, 0.932272, 0.932324, 0.932375, 0.932427, 0.932478, 0.93253, 0.932581, 0.932633, 0.932684, 0.932735, 0.932787, 0.932838, 0.932889, 0.932941, 0.932992, 0.933043, 0.933095, 0.933146, 0.933197, 0.933248, 0.933299, 0.93335, 0.933402, 0.933453, 0.933504, 0.933555, 0.933606, 0.933657, 0.933708, 0.933759, 0.93381, 0.933861, 0.933912, 0.933963, 0.934014, 0.934065, 0.934116, 0.934166, 0.934217, 0.934268, 0.934319, 0.93437, 0.93442, 0.934471, 0.934522, 0.934572, 0.934623, 0.934674, 0.934724, 0.934775, 0.934826, 0.934876, 0.934927, 0.934977, 0.935028, 0.935078, 0.935129, 0.935179, 0.93523, 0.93528, 0.935331, 0.935381, 0.935431, 0.935482, 0.935532, 0.935582, 0.935633, 0.935683, 0.935733, 0.935784, 0.935834, 0.935884, 0.935934, 0.935984,
0.936034, 0.936085, 0.936135, 0.936185, 0.936235, 0.936285, 0.936335, 0.936385, 0.936435, 0.936485, 0.936535, 0.936585, 0.936635, 0.936685, 0.936735, 0.936784, 0.936834, 0.936884, 0.936934, 0.936984, 0.937033, 0.937083, 0.937133, 0.937183, 0.937232, 0.937282, 0.937332, 0.937381, 0.937431, 0.937481, 0.93753, 0.93758, 0.937629, 0.937679, 0.937728, 0.937778, 0.937827, 0.937877, 0.937926, 0.937975, 0.938025, 0.938074, 0.938124, 0.938173, 0.938222, 0.938271, 0.938321, 0.93837, 0.938419, 0.938468, 0.938518, 0.938567, 0.938616, 0.938665, 0.938714, 0.938763, 0.938812, 0.938861, 0.938911, 0.93896, 0.939009, 0.939058, 0.939107, 0.939155, 0.939204, 0.939253, 0.939302, 0.939351, 0.9394, 0.939449, 0.939498, 0.939546, 0.939595, 0.939644, 0.939693, 0.939741, 0.93979, 0.939839, 0.939887, 0.939936, 0.939985, 0.940033, 0.940082, 0.94013, 0.940179, 0.940228, 0.940276, 0.940325, 0.940373, 0.940421, 0.94047, 0.940518, 0.940567, 0.940615, 0.940663, 0.940712, 0.94076, 0.940808, 0.940857, 0.940905,
0.940953, 0.941001, 0.94105, 0.941098, 0.941146, 0.941194, 0.941242, 0.94129, 0.941338, 0.941386, 0.941435, 0.941483, 0.941531, 0.941579, 0.941627, 0.941675, 0.941722, 0.94177, 0.941818, 0.941866, 0.941914, 0.941962, 0.94201, 0.942057, 0.942105, 0.942153, 0.942201, 0.942248, 0.942296, 0.942344, 0.942392, 0.942439, 0.942487, 0.942534, 0.942582, 0.94263, 0.942677, 0.942725, 0.942772, 0.94282, 0.942867, 0.942915, 0.942962, 0.94301, 0.943057, 0.943104, 0.943152, 0.943199, 0.943246, 0.943294, 0.943341, 0.943388, 0.943435, 0.943483, 0.94353, 0.943577, 0.943624, 0.943671, 0.943719, 0.943766, 0.943813, 0.94386, 0.943907, 0.943954, 0.944001, 0.944048, 0.944095, 0.944142, 0.944189, 0.944236, 0.944283, 0.94433, 0.944376, 0.944423, 0.94447, 0.944517, 0.944564, 0.94461, 0.944657, 0.944704, 0.944751, 0.944797, 0.944844, 0.944891, 0.944937, 0.944984, 0.94503, 0.945077, 0.945124, 0.94517, 0.945217, 0.945263, 0.94531, 0.945356, 0.945403, 0.945449, 0.945495, 0.945542, 0.945588, 0.945634,
0.945681, 0.945727, 0.945773, 0.94582, 0.945866, 0.945912, 0.945958, 0.946005, 0.946051, 0.946097, 0.946143, 0.946189, 0.946235, 0.946281, 0.946327, 0.946373, 0.946419, 0.946465, 0.946511, 0.946557, 0.946603, 0.946649, 0.946695, 0.946741, 0.946787, 0.946833, 0.946879, 0.946924, 0.94697, 0.947016, 0.947062, 0.947107, 0.947153, 0.947199, 0.947245, 0.94729, 0.947336, 0.947381, 0.947427, 0.947473, 0.947518, 0.947564, 0.947609, 0.947655, 0.9477, 0.947746, 0.947791, 0.947837, 0.947882, 0.947927, 0.947973, 0.948018, 0.948063, 0.948109, 0.948154, 0.948199, 0.948245, 0.94829, 0.948335, 0.94838, 0.948425, 0.94847, 0.948516, 0.948561, 0.948606, 0.948651, 0.948696, 0.948741, 0.948786, 0.948831, 0.948876, 0.948921, 0.948966, 0.949011, 0.949056, 0.949101, 0.949146, 0.94919, 0.949235, 0.94928, 0.949325, 0.94937, 0.949414, 0.949459, 0.949504, 0.949548, 0.949593, 0.949638, 0.949682, 0.949727, 0.949772, 0.949816, 0.949861, 0.949905, 0.94995, 0.949994, 0.950039, 0.950083, 0.950128, 0.950172,
0.950217, 0.950261, 0.950305, 0.95035, 0.950394, 0.950438, 0.950483, 0.950527, 0.950571, 0.950615, 0.950659, 0.950704, 0.950748, 0.950792, 0.950836, 0.95088, 0.950924, 0.950968, 0.951012, 0.951057, 0.951101, 0.951145, 0.951189, 0.951232, 0.951276, 0.95132, 0.951364, 0.951408, 0.951452, 0.951496, 0.95154, 0.951583, 0.951627, 0.951671, 0.951715, 0.951758, 0.951802, 0.951846, 0.95189, 0.951933, 0.951977, 0.95202, 0.952064, 0.952108, 0.952151, 0.952195, 0.952238, 0.952282, 0.952325, 0.952369, 0.952412, 0.952456, 0.952499, 0.952542, 0.952586, 0.952629, 0.952672, 0.952716, 0.952759, 0.952802, 0.952845, 0.952889, 0.952932, 0.952975, 0.953018, 0.953061, 0.953104, 0.953148, 0.953191, 0.953234, 0.953277, 0.95332, 0.953363, 0.953406, 0.953449, 0.953492, 0.953535, 0.953578, 0.953621, 0.953663, 0.953706, 0.953749, 0.953792, 0.953835, 0.953877, 0.95392, 0.953963, 0.954006, 0.954048, 0.954091, 0.954134, 0.954176, 0.954219, 0.954262, 0.954304, 0.954347, 0.954389, 0.954432, 0.954474, 0.954517,
0.954559, 0.954602, 0.954644, 0.954687, 0.954729, 0.954771, 0.954814, 0.954856, 0.954898, 0.954941, 0.954983, 0.955025, 0.955067, 0.95511, 0.955152, 0.955194, 0.955236, 0.955278, 0.95532, 0.955363, 0.955405, 0.955447, 0.955489, 0.955531, 0.955573, 0.955615, 0.955657, 0.955699, 0.955741, 0.955783, 0.955824, 0.955866, 0.955908, 0.95595, 0.955992, 0.956034, 0.956075, 0.956117, 0.956159, 0.956201, 0.956242, 0.956284, 0.956326, 0.956367, 0.956409, 0.95645, 0.956492, 0.956534, 0.956575, 0.956617, 0.956658, 0.9567, 0.956741, 0.956783, 0.956824, 0.956865, 0.956907, 0.956948, 0.956989, 0.957031, 0.957072, 0.957113, 0.957155, 0.957196, 0.957237, 0.957278, 0.95732, 0.957361, 0.957402, 0.957443, 0.957484, 0.957525, 0.957566, 0.957607, 0.957648, 0.957689, 0.95773, 0.957771, 0.957812, 0.957853, 0.957894, 0.957935, 0.957976, 0.958017, 0.958058, 0.958098, 0.958139, 0.95818, 0.958221, 0.958262, 0.958302, 0.958343, 0.958384, 0.958424, 0.958465, 0.958506, 0.958546, 0.958587, 0.958627, 0.958668,
0.958708, 0.958749, 0.958789, 0.95883, 0.95887, 0.958911, 0.958951, 0.958992, 0.959032, 0.959072, 0.959113, 0.959153, 0.959193, 0.959233, 0.959274, 0.959314, 0.959354, 0.959394, 0.959435, 0.959475, 0.959515, 0.959555, 0.959595, 0.959635, 0.959675, 0.959715, 0.959755, 0.959795, 0.959835, 0.959875, 0.959915, 0.959955, 0.959995, 0.960035, 0.960075, 0.960115, 0.960154, 0.960194, 0.960234, 0.960274, 0.960314, 0.960353, 0.960393, 0.960433, 0.960472, 0.960512, 0.960552, 0.960591, 0.960631, 0.96067, 0.96071, 0.96075, 0.960789, 0.960829, 0.960868, 0.960907, 0.960947, 0.960986, 0.961026, 0.961065, 0.961104, 0.961144, 0.961183, 0.961222, 0.961262, 0.961301, 0.96134, 0.961379, 0.961419, 0.961458, 0.961497, 0.961536, 0.961575, 0.961614, 0.961653, 0.961693, 0.961732, 0.961771, 0.96181, 0.961849, 0.961888, 0.961927, 0.961965, 0.962004, 0.962043, 0.962082, 0.962121, 0.96216, 0.962199, 0.962237, 0.962276, 0.962315, 0.962354, 0.962392, 0.962431, 0.96247, 0.962508, 0.962547, 0.962586, 0.962624,
0.962663, 0.962701, 0.96274, 0.962778, 0.962817, 0.962855, 0.962894, 0.962932, 0.962971, 0.963009, 0.963048, 0.963086, 0.963124, 0.963163, 0.963201, 0.963239, 0.963277, 0.963316, 0.963354, 0.963392, 0.96343, 0.963468, 0.963507, 0.963545, 0.963583, 0.963621, 0.963659, 0.963697, 0.963735, 0.963773, 0.963811, 0.963849, 0.963887, 0.963925, 0.963963, 0.964001, 0.964039, 0.964076, 0.964114, 0.964152, 0.96419, 0.964228, 0.964265, 0.964303, 0.964341, 0.964379, 0.964416, 0.964454, 0.964492, 0.964529, 0.964567, 0.964604, 0.964642, 0.96468, 0.964717, 0.964755, 0.964792, 0.964829, 0.964867, 0.964904, 0.964942, 0.964979, 0.965017, 0.965054, 0.965091, 0.965128, 0.965166, 0.965203, 0.96524, 0.965278, 0.965315, 0.965352, 0.965389, 0.965426, 0.965463, 0.9655, 0.965538, 0.965575, 0.965612, 0.965649, 0.965686, 0.965723, 0.96576, 0.965797, 0.965834, 0.965871, 0.965907, 0.965944, 0.965981, 0.966018, 0.966055, 0.966092, 0.966128, 0.966165, 0.966202, 0.966239, 0.966275, 0.966312, 0.966349, 0.966385,
0.966422, 0.966458, 0.966495, 0.966532, 0.966568, 0.966605, 0.966641, 0.966678, 0.966714, 0.966751, 0.966787, 0.966823, 0.96686, 0.966896, 0.966932, 0.966969, 0.967005, 0.967041, 0.967078, 0.967114, 0.96715, 0.967186, 0.967223, 0.967259, 0.967295, 0.967331, 0.967367, 0.967403, 0.967439, 0.967475, 0.967511, 0.967547, 0.967583, 0.967619, 0.967655, 0.967691, 0.967727, 0.967763, 0.967799, 0.967835, 0.967871, 0.967906, 0.967942, 0.967978, 0.968014, 0.968049, 0.968085, 0.968121, 0.968157, 0.968192, 0.968228, 0.968263, 0.968299, 0.968335, 0.96837, 0.968406, 0.968441, 0.968477, 0.968512, 0.968548, 0.968583, 0.968619, 0.968654, 0.968689, 0.968725, 0.96876, 0.968795, 0.968831, 0.968866, 0.968901, 0.968937, 0.968972, 0.969007, 0.969042, 0.969077, 0.969112, 0.969148, 0.969183, 0.969218, 0.969253, 0.969288, 0.969323, 0.969358, 0.969393, 0.969428, 0.969463, 0.969498, 0.969533, 0.969568, 0.969602, 0.969637, 0.969672, 0.969707, 0.969742, 0.969776, 0.969811, 0.969846, 0.969881, 0.969915, 0.96995,
0.969985, 0.970019, 0.970054, 0.970089, 0.970123, 0.970158, 0.970192, 0.970227, 0.970261, 0.970296, 0.97033, 0.970365, 0.970399, 0.970433, 0.970468, 0.970502, 0.970537, 0.970571, 0.970605, 0.970639, 0.970674, 0.970708, 0.970742, 0.970776, 0.970811, 0.970845, 0.970879, 0.970913, 0.970947, 0.970981, 0.971015, 0.971049, 0.971083, 0.971117, 0.971151, 0.971185, 0.971219, 0.971253, 0.971287, 0.971321, 0.971355, 0.971389, 0.971422, 0.971456, 0.97149, 0.971524, 0.971558, 0.971591, 0.971625, 0.971659, 0.971692, 0.971726, 0.97176, 0.971793, 0.971827, 0.97186, 0.971894, 0.971927, 0.971961, 0.971995, 0.972028, 0.972061, 0.972095, 0.972128, 0.972162, 0.972195, 0.972228, 0.972262, 0.972295, 0.972328, 0.972362, 0.972395, 0.972428, 0.972461, 0.972495, 0.972528, 0.972561, 0.972594, 0.972627, 0.97266, 0.972693, 0.972726, 0.972759, 0.972792, 0.972825, 0.972858, 0.972891, 0.972924, 0.972957, 0.97299, 0.973023, 0.973056, 0.973089, 0.973121, 0.973154, 0.973187, 0.97322, 0.973253, 0.973285, 0.973318,
0.973351, 0.973383, 0.973416, 0.973449, 0.973481, 0.973514, 0.973546, 0.973579, 0.973611, 0.973644, 0.973676, 0.973709, 0.973741, 0.973774, 0.973806, 0.973839, 0.973871, 0.973903, 0.973936, 0.973968, 0.974, 0.974032, 0.974065, 0.974097, 0.974129, 0.974161, 0.974193, 0.974226, 0.974258, 0.97429, 0.974322, 0.974354, 0.974386, 0.974418, 0.97445, 0.974482, 0.974514, 0.974546, 0.974578, 0.97461, 0.974642, 0.974674, 0.974706, 0.974737, 0.974769, 0.974801, 0.974833, 0.974864, 0.974896, 0.974928, 0.97496, 0.974991, 0.975023, 0.975055, 0.975086, 0.975118, 0.975149, 0.975181, 0.975212, 0.975244, 0.975275, 0.975307, 0.975338, 0.97537, 0.975401, 0.975433, 0.975464, 0.975495, 0.975527, 0.975558, 0.975589, 0.975621, 0.975652, 0.975683, 0.975714, 0.975746, 0.975777, 0.975808, 0.975839, 0.97587, 0.975901, 0.975932, 0.975963, 0.975994, 0.976025, 0.976056, 0.976087, 0.976118, 0.976149, 0.97618, 0.976211, 0.976242, 0.976273, 0.976304, 0.976335, 0.976365, 0.976396, 0.976427, 0.976458, 0.976488,
0.976519, 0.97655, 0.97658, 0.976611, 0.976642, 0.976672, 0.976703, 0.976733, 0.976764, 0.976795, 0.976825, 0.976855, 0.976886, 0.976916, 0.976947, 0.976977, 0.977008, 0.977038, 0.977068, 0.977099, 0.977129, 0.977159, 0.97719, 0.97722, 0.97725, 0.97728, 0.97731, 0.977341, 0.977371, 0.977401, 0.977431, 0.977461, 0.977491, 0.977521, 0.977551, 0.977581, 0.977611, 0.977641, 0.977671, 0.977701, 0.977731, 0.977761, 0.977791, 0.977821, 0.97785, 0.97788, 0.97791, 0.97794, 0.97797, 0.977999, 0.978029, 0.978059, 0.978088, 0.978118, 0.978148, 0.978177, 0.978207, 0.978236, 0.978266, 0.978295, 0.978325, 0.978354, 0.978384, 0.978413, 0.978443, 0.978472, 0.978502, 0.978531, 0.97856, 0.97859, 0.978619, 0.978648, 0.978678, 0.978707, 0.978736, 0.978765, 0.978794, 0.978824, 0.978853, 0.978882, 0.978911, 0.97894, 0.978969, 0.978998, 0.979027, 0.979056, 0.979085, 0.979114, 0.979143, 0.979172, 0.979201, 0.97923, 0.979259, 0.979288, 0.979317, 0.979345, 0.979374, 0.979403, 0.979432, 0.979461,
0.979489, 0.979518, 0.979547, 0.979575, 0.979604, 0.979633, 0.979661, 0.97969, 0.979718, 0.979747, 0.979775, 0.979804, 0.979832, 0.979861, 0.979889, 0.979918, 0.979946, 0.979974, 0.980003, 0.980031, 0.980059, 0.980088, 0.980116, 0.980144, 0.980172, 0.980201, 0.980229, 0.980257, 0.980285, 0.980313, 0.980342, 0.98037, 0.980398, 0.980426, 0.980454, 0.980482, 0.98051, 0.980538, 0.980566, 0.980594, 0.980622, 0.98065, 0.980677, 0.980705, 0.980733, 0.980761, 0.980789, 0.980817, 0.980844, 0.980872, 0.9809, 0.980927, 0.980955, 0.980983, 0.98101, 0.981038, 0.981066, 0.981093, 0.981121, 0.981148, 0.981176, 0.981203, 0.981231, 0.981258, 0.981286, 0.981313, 0.981341, 0.981368, 0.981395, 0.981423, 0.98145, 0.981477, 0.981505, 0.981532, 0.981559, 0.981586, 0.981614, 0.981641, 0.981668, 0.981695, 0.981722, 0.981749, 0.981776, 0.981803, 0.981831, 0.981858, 0.981885, 0.981912, 0.981939, 0.981965, 0.981992, 0.982019, 0.982046, 0.982073, 0.9821, 0.982127, 0.982154, 0.98218, 0.982207, 0.982234,
0.982261, 0.982287, 0.982314, 0.982341, 0.982367, 0.982394, 0.98242, 0.982447, 0.982474, 0.9825, 0.982527, 0.982553, 0.98258, 0.982606, 0.982633, 0.982659, 0.982685, 0.982712, 0.982738, 0.982765, 0.982791, 0.982817, 0.982844, 0.98287, 0.982896, 0.982922, 0.982948, 0.982975, 0.983001, 0.983027, 0.983053, 0.983079, 0.983105, 0.983131, 0.983157, 0.983183, 0.983209, 0.983235, 0.983261, 0.983287, 0.983313, 0.983339, 0.983365, 0.983391, 0.983417, 0.983443, 0.983468, 0.983494, 0.98352, 0.983546, 0.983571, 0.983597, 0.983623, 0.983649, 0.983674, 0.9837, 0.983725, 0.983751, 0.983777, 0.983802, 0.983828, 0.983853, 0.983879, 0.983904, 0.98393, 0.983955, 0.98398, 0.984006, 0.984031, 0.984057, 0.984082, 0.984107, 0.984132, 0.984158, 0.984183, 0.984208, 0.984233, 0.984259, 0.984284, 0.984309, 0.984334, 0.984359, 0.984384, 0.984409, 0.984434, 0.984459, 0.984484, 0.984509, 0.984534, 0.984559, 0.984584, 0.984609, 0.984634, 0.984659, 0.984684, 0.984709, 0.984733, 0.984758, 0.984783, 0.984808,
0.984832, 0.984857, 0.984882, 0.984907, 0.984931, 0.984956, 0.98498, 0.985005, 0.98503, 0.985054, 0.985079, 0.985103, 0.985128, 0.985152, 0.985177, 0.985201, 0.985225, 0.98525, 0.985274, 0.985299, 0.985323, 0.985347, 0.985372, 0.985396, 0.98542, 0.985444, 0.985468, 0.985493, 0.985517, 0.985541, 0.985565, 0.985589, 0.985613, 0.985637, 0.985661, 0.985685, 0.985709, 0.985733, 0.985757, 0.985781, 0.985805, 0.985829, 0.985853, 0.985877, 0.985901, 0.985925, 0.985948, 0.985972, 0.985996, 0.98602, 0.986044, 0.986067, 0.986091, 0.986115, 0.986138, 0.986162, 0.986185, 0.986209, 0.986233, 0.986256, 0.98628, 0.986303, 0.986327, 0.98635, 0.986374, 0.986397, 0.98642, 0.986444, 0.986467, 0.986491, 0.986514, 0.986537, 0.986561, 0.986584, 0.986607, 0.98663, 0.986653, 0.986677, 0.9867, 0.986723, 0.986746, 0.986769, 0.986792, 0.986815, 0.986838, 0.986861, 0.986884, 0.986907, 0.98693, 0.986953, 0.986976, 0.986999, 0.987022, 0.987045, 0.987068, 0.987091, 0.987113, 0.987136, 0.987159, 0.987182,
0.987205, 0.987227, 0.98725, 0.987273, 0.987295, 0.987318, 0.98734, 0.987363, 0.987386, 0.987408, 0.987431, 0.987453, 0.987476, 0.987498, 0.987521, 0.987543, 0.987565, 0.987588, 0.98761, 0.987633, 0.987655, 0.987677, 0.987699, 0.987722, 0.987744, 0.987766, 0.987788, 0.987811, 0.987833, 0.987855, 0.987877, 0.987899, 0.987921, 0.987943, 0.987965, 0.987987, 0.988009, 0.988031, 0.988053, 0.988075, 0.988097, 0.988119, 0.988141, 0.988163, 0.988185, 0.988207, 0.988228, 0.98825, 0.988272, 0.988294, 0.988315, 0.988337, 0.988359, 0.98838, 0.988402, 0.988424, 0.988445, 0.988467, 0.988489, 0.98851, 0.988532, 0.988553, 0.988575, 0.988596, 0.988617, 0.988639, 0.98866, 0.988682, 0.988703, 0.988724, 0.988746, 0.988767, 0.988788, 0.98881, 0.988831, 0.988852, 0.988873, 0.988894, 0.988916, 0.988937, 0.988958, 0.988979, 0.989, 0.989021, 0.989042, 0.989063, 0.989084, 0.989105, 0.989126, 0.989147, 0.989168, 0.989189, 0.98921, 0.989231, 0.989252, 0.989272, 0.989293, 0.989314, 0.989335, 0.989355,
0.989376, 0.989397, 0.989418, 0.989438, 0.989459, 0.989479, 0.9895, 0.989521, 0.989541, 0.989562, 0.989582, 0.989603, 0.989623, 0.989644, 0.989664, 0.989685, 0.989705, 0.989725, 0.989746, 0.989766, 0.989786, 0.989807, 0.989827, 0.989847, 0.989867, 0.989888, 0.989908, 0.989928, 0.989948, 0.989968, 0.989989, 0.990009, 0.990029, 0.990049, 0.990069, 0.990089, 0.990109, 0.990129, 0.990149, 0.990169, 0.990189, 0.990208, 0.990228, 0.990248, 0.990268, 0.990288, 0.990308, 0.990327, 0.990347, 0.990367, 0.990387, 0.990406, 0.990426, 0.990446, 0.990465, 0.990485, 0.990505, 0.990524, 0.990544, 0.990563, 0.990583, 0.990602, 0.990622, 0.990641, 0.990661, 0.99068, 0.990699, 0.990719, 0.990738, 0.990758, 0.990777, 0.990796, 0.990815, 0.990835, 0.990854, 0.990873, 0.990892, 0.990911, 0.990931, 0.99095, 0.990969, 0.990988, 0.991007, 0.991026, 0.991045, 0.991064, 0.991083, 0.991102, 0.991121, 0.99114, 0.991159, 0.991178, 0.991197, 0.991216, 0.991234, 0.991253, 0.991272, 0.991291, 0.99131, 0.991328,
0.991347, 0.991366, 0.991384, 0.991403, 0.991422, 0.99144, 0.991459, 0.991477, 0.991496, 0.991514, 0.991533, 0.991551, 0.99157, 0.991588, 0.991607, 0.991625, 0.991644, 0.991662, 0.99168, 0.991699, 0.991717, 0.991735, 0.991754, 0.991772, 0.99179, 0.991808, 0.991826, 0.991845, 0.991863, 0.991881, 0.991899, 0.991917, 0.991935, 0.991953, 0.991971, 0.991989, 0.992007, 0.992025, 0.992043, 0.992061, 0.992079, 0.992097, 0.992115, 0.992133, 0.99215, 0.992168, 0.992186, 0.992204, 0.992221, 0.992239, 0.992257, 0.992275, 0.992292, 0.99231, 0.992328, 0.992345, 0.992363, 0.99238, 0.992398, 0.992415, 0.992433, 0.99245, 0.992468, 0.992485, 0.992503, 0.99252, 0.992537, 0.992555, 0.992572, 0.99259, 0.992607, 0.992624, 0.992641, 0.992659, 0.992676, 0.992693, 0.99271, 0.992727, 0.992745, 0.992762, 0.992779, 0.992796, 0.992813, 0.99283, 0.992847, 0.992864, 0.992881, 0.992898, 0.992915, 0.992932, 0.992949, 0.992966, 0.992982, 0.992999, 0.993016, 0.993033, 0.99305, 0.993066, 0.993083, 0.9931,
0.993117, 0.993133, 0.99315, 0.993166, 0.993183, 0.9932, 0.993216, 0.993233, 0.993249, 0.993266, 0.993282, 0.993299, 0.993315, 0.993332, 0.993348, 0.993365, 0.993381, 0.993397, 0.993414, 0.99343, 0.993446, 0.993463, 0.993479, 0.993495, 0.993511, 0.993527, 0.993544, 0.99356, 0.993576, 0.993592, 0.993608, 0.993624, 0.99364, 0.993656, 0.993672, 0.993688, 0.993704, 0.99372, 0.993736, 0.993752, 0.993768, 0.993784, 0.9938, 0.993815, 0.993831, 0.993847, 0.993863, 0.993879, 0.993894, 0.99391, 0.993926, 0.993941, 0.993957, 0.993973, 0.993988, 0.994004, 0.994019, 0.994035, 0.994051, 0.994066, 0.994082, 0.994097, 0.994112, 0.994128, 0.994143, 0.994159, 0.994174, 0.994189, 0.994205, 0.99422, 0.994235, 0.994251, 0.994266, 0.994281, 0.994296, 0.994311, 0.994327, 0.994342, 0.994357, 0.994372, 0.994387, 0.994402, 0.994417, 0.994432, 0.994447, 0.994462, 0.994477, 0.994492, 0.994507, 0.994522, 0.994537, 0.994552, 0.994566, 0.994581, 0.994596, 0.994611, 0.994626, 0.99464, 0.994655, 0.99467,
0.994684, 0.994699, 0.994714, 0.994728, 0.994743, 0.994758, 0.994772, 0.994787, 0.994801, 0.994816, 0.99483, 0.994845, 0.994859, 0.994874, 0.994888, 0.994902, 0.994917, 0.994931, 0.994945, 0.99496, 0.994974, 0.994988, 0.995002, 0.995017, 0.995031, 0.995045, 0.995059, 0.995073, 0.995087, 0.995101, 0.995116, 0.99513, 0.995144, 0.995158, 0.995172, 0.995186, 0.9952, 0.995213, 0.995227, 0.995241, 0.995255, 0.995269, 0.995283, 0.995297, 0.99531, 0.995324, 0.995338, 0.995352, 0.995365, 0.995379, 0.995393, 0.995406, 0.99542, 0.995434, 0.995447, 0.995461, 0.995474, 0.995488, 0.995501, 0.995515, 0.995528, 0.995542, 0.995555, 0.995569, 0.995582, 0.995595, 0.995609, 0.995622, 0.995635, 0.995649, 0.995662, 0.995675, 0.995688, 0.995702, 0.995715, 0.995728, 0.995741, 0.995754, 0.995767, 0.99578, 0.995794, 0.995807, 0.99582, 0.995833, 0.995846, 0.995859, 0.995871, 0.995884, 0.995897, 0.99591, 0.995923, 0.995936, 0.995949, 0.995962, 0.995974, 0.995987, 0.996, 0.996013, 0.996025, 0.996038,
0.996051, 0.996063, 0.996076, 0.996088, 0.996101, 0.996114, 0.996126, 0.996139, 0.996151, 0.996164, 0.996176, 0.996188, 0.996201, 0.996213, 0.996226, 0.996238, 0.99625, 0.996263, 0.996275, 0.996287, 0.9963, 0.996312, 0.996324, 0.996336, 0.996348, 0.99636, 0.996373, 0.996385, 0.996397, 0.996409, 0.996421, 0.996433, 0.996445, 0.996457, 0.996469, 0.996481, 0.996493, 0.996505, 0.996517, 0.996529, 0.99654, 0.996552, 0.996564, 0.996576, 0.996588, 0.996599, 0.996611, 0.996623, 0.996634, 0.996646, 0.996658, 0.996669, 0.996681, 0.996693, 0.996704, 0.996716, 0.996727, 0.996739, 0.99675, 0.996762, 0.996773, 0.996785, 0.996796, 0.996807, 0.996819, 0.99683, 0.996841, 0.996853, 0.996864, 0.996875, 0.996887, 0.996898, 0.996909, 0.99692, 0.996931, 0.996942, 0.996954, 0.996965, 0.996976, 0.996987, 0.996998, 0.997009, 0.99702, 0.997031, 0.997042, 0.997053, 0.997064, 0.997075, 0.997085, 0.997096, 0.997107, 0.997118, 0.997129, 0.99714, 0.99715, 0.997161, 0.997172, 0.997182, 0.997193, 0.997204,
0.997214, 0.997225, 0.997236, 0.997246, 0.997257, 0.997267, 0.997278, 0.997288, 0.997299, 0.997309, 0.99732, 0.99733, 0.997341, 0.997351, 0.997361, 0.997372, 0.997382, 0.997392, 0.997402, 0.997413, 0.997423, 0.997433, 0.997443, 0.997454, 0.997464, 0.997474, 0.997484, 0.997494, 0.997504, 0.997514, 0.997524, 0.997534, 0.997544, 0.997554, 0.997564, 0.997574, 0.997584, 0.997594, 0.997604, 0.997613, 0.997623, 0.997633, 0.997643, 0.997653, 0.997662, 0.997672, 0.997682, 0.997692, 0.997701, 0.997711, 0.99772, 0.99773, 0.99774, 0.997749, 0.997759, 0.997768, 0.997778, 0.997787, 0.997797, 0.997806, 0.997816, 0.997825, 0.997834, 0.997844, 0.997853, 0.997862, 0.997872, 0.997881, 0.99789, 0.997899, 0.997909, 0.997918, 0.997927, 0.997936, 0.997945, 0.997955, 0.997964, 0.997973, 0.997982, 0.997991, 0.998, 0.998009, 0.998018, 0.998027, 0.998036, 0.998045, 0.998053, 0.998062, 0.998071, 0.99808, 0.998089, 0.998098, 0.998106, 0.998115, 0.998124, 0.998133, 0.998141, 0.99815, 0.998159, 0.998167,
0.998176, 0.998184, 0.998193, 0.998202, 0.99821, 0.998219, 0.998227, 0.998236, 0.998244, 0.998252, 0.998261, 0.998269, 0.998278, 0.998286, 0.998294, 0.998303, 0.998311, 0.998319, 0.998327, 0.998336, 0.998344, 0.998352, 0.99836, 0.998368, 0.998376, 0.998385, 0.998393, 0.998401, 0.998409, 0.998417, 0.998425, 0.998433, 0.998441, 0.998449, 0.998457, 0.998465, 0.998472, 0.99848, 0.998488, 0.998496, 0.998504, 0.998512, 0.998519, 0.998527, 0.998535, 0.998542, 0.99855, 0.998558, 0.998565, 0.998573, 0.998581, 0.998588, 0.998596, 0.998603, 0.998611, 0.998618, 0.998626, 0.998633, 0.998641, 0.998648, 0.998656, 0.998663, 0.99867, 0.998678, 0.998685, 0.998692, 0.998699, 0.998707, 0.998714, 0.998721, 0.998728, 0.998736, 0.998743, 0.99875, 0.998757, 0.998764, 0.998771, 0.998778, 0.998785, 0.998792, 0.998799, 0.998806, 0.998813, 0.99882, 0.998827, 0.998834, 0.998841, 0.998848, 0.998854, 0.998861, 0.998868, 0.998875, 0.998881, 0.998888, 0.998895, 0.998902, 0.998908, 0.998915, 0.998922, 0.998928,
0.998935, 0.998941, 0.998948, 0.998954, 0.998961, 0.998967, 0.998974, 0.99898, 0.998987, 0.998993, 0.998999, 0.999006, 0.999012, 0.999018, 0.999025, 0.999031, 0.999037, 0.999044, 0.99905, 0.999056, 0.999062, 0.999068, 0.999074, 0.999081, 0.999087, 0.999093, 0.999099, 0.999105, 0.999111, 0.999117, 0.999123, 0.999129, 0.999135, 0.999141, 0.999147, 0.999152, 0.999158, 0.999164, 0.99917, 0.999176, 0.999181, 0.999187, 0.999193, 0.999199, 0.999204, 0.99921, 0.999216, 0.999221, 0.999227, 0.999233, 0.999238, 0.999244, 0.999249, 0.999255, 0.99926, 0.999266, 0.999271, 0.999277, 0.999282, 0.999287, 0.999293, 0.999298, 0.999303, 0.999309, 0.999314, 0.999319, 0.999324, 0.99933, 0.999335, 0.99934, 0.999345, 0.99935, 0.999356, 0.999361, 0.999366, 0.999371, 0.999376, 0.999381, 0.999386, 0.999391, 0.999396, 0.999401, 0.999406, 0.999411, 0.999415, 0.99942, 0.999425, 0.99943, 0.999435, 0.99944, 0.999444, 0.999449, 0.999454, 0.999458, 0.999463, 0.999468, 0.999472, 0.999477, 0.999482, 0.999486,
0.999491, 0.999495, 0.9995, 0.999504, 0.999509, 0.999513, 0.999518, 0.999522, 0.999526, 0.999531, 0.999535, 0.99954, 0.999544, 0.999548, 0.999552, 0.999557, 0.999561, 0.999565, 0.999569, 0.999573, 0.999578, 0.999582, 0.999586, 0.99959, 0.999594, 0.999598, 0.999602, 0.999606, 0.99961, 0.999614, 0.999618, 0.999622, 0.999626, 0.99963, 0.999634, 0.999637, 0.999641, 0.999645, 0.999649, 0.999653, 0.999656, 0.99966, 0.999664, 0.999668, 0.999671, 0.999675, 0.999678, 0.999682, 0.999686, 0.999689, 0.999693, 0.999696, 0.9997, 0.999703, 0.999707, 0.99971, 0.999714, 0.999717, 0.99972, 0.999724, 0.999727, 0.99973, 0.999734, 0.999737, 0.99974, 0.999743, 0.999747, 0.99975, 0.999753, 0.999756, 0.999759, 0.999762, 0.999766, 0.999769, 0.999772, 0.999775, 0.999778, 0.999781, 0.999784, 0.999787, 0.99979, 0.999792, 0.999795, 0.999798, 0.999801, 0.999804, 0.999807, 0.99981, 0.999812, 0.999815, 0.999818, 0.99982, 0.999823, 0.999826, 0.999828, 0.999831, 0.999834, 0.999836, 0.999839, 0.999841,
0.999844, 0.999846, 0.999849, 0.999851, 0.999854, 0.999856, 0.999859, 0.999861, 0.999863, 0.999866, 0.999868, 0.99987, 0.999873, 0.999875, 0.999877, 0.999879, 0.999882, 0.999884, 0.999886, 0.999888, 0.99989, 0.999892, 0.999894, 0.999896, 0.999899, 0.999901, 0.999903, 0.999905, 0.999906, 0.999908, 0.99991, 0.999912, 0.999914, 0.999916, 0.999918, 0.99992, 0.999921, 0.999923, 0.999925, 0.999927, 0.999928, 0.99993, 0.999932, 0.999933, 0.999935, 0.999937, 0.999938, 0.99994, 0.999941, 0.999943, 0.999944, 0.999946, 0.999947, 0.999949, 0.99995, 0.999952, 0.999953, 0.999954, 0.999956, 0.999957, 0.999958, 0.99996, 0.999961, 0.999962, 0.999963, 0.999965, 0.999966, 0.999967, 0.999968, 0.999969, 0.99997, 0.999971, 0.999973, 0.999974, 0.999975, 0.999976, 0.999977, 0.999978, 0.999979, 0.999979, 0.99998, 0.999981, 0.999982, 0.999983, 0.999984, 0.999985, 0.999985, 0.999986, 0.999987, 0.999988, 0.999988, 0.999989, 0.99999, 0.99999, 0.999991, 0.999991, 0.999992, 0.999993, 0.999993, 0.999994,
0.999994, 0.999995, 0.999995, 0.999996, 0.999996, 0.999996, 0.999997, 0.999997, 0.999997, 0.999998, 0.999998, 0.999998, 0.999999, 0.999999, 0.999999, 0.999999, 0.999999, 1, 1, 1, 1, 1, 1, 1, };

	//標本化周波数8000Hzのサイン波(0からπ/2まで)
	const nsfloat sinTabel_8000[] PROGMEM = { 0,
0.000785398, 0.0015708, 0.00235619, 0.00314159, 0.00392698, 0.00471237, 0.00549776, 0.00628314, 0.00706852, 0.0078539, 0.00863927, 0.00942464, 0.01021, 0.0109954, 0.0117807, 0.012566, 0.0133514, 0.0141367, 0.014922, 0.0157073, 0.0164926, 0.0172779, 0.0180632, 0.0188484, 0.0196337, 0.0204189, 0.0212042, 0.0219894, 0.0227746, 0.0235598, 0.0243449, 0.0251301, 0.0259152, 0.0267004, 0.0274855, 0.0282706, 0.0290556, 0.0298407, 0.0306257, 0.0314108, 0.0321958, 0.0329807, 0.0337657, 0.0345506, 0.0353356, 0.0361205, 0.0369053, 0.0376902, 0.038475, 0.0392598, 0.0400446, 0.0408294, 0.0416141, 0.0423988, 0.0431835, 0.0439681, 0.0447527, 0.0455373, 0.0463219, 0.0471065, 0.047891, 0.0486754, 0.0494599, 0.0502443, 0.0510287, 0.0518131, 0.0525974, 0.0533817, 0.054166, 0.0549502, 0.0557344, 0.0565185, 0.0573027, 0.0580868, 0.0588708, 0.0596548, 0.0604388, 0.0612227, 0.0620067, 0.0627905, 0.0635744, 0.0643581, 0.0651419, 0.0659256, 0.0667093, 0.0674929, 0.0682765, 0.06906, 0.0698435, 0.070627, 0.0714104, 0.0721938, 0.0729771, 0.0737604, 0.0745436, 0.0753268, 0.07611, 0.076893, 0.0776761, 0.0784591,
0.0792421, 0.080025, 0.0808078, 0.0815906, 0.0823734, 0.0831561, 0.0839387, 0.0847213, 0.0855039, 0.0862864, 0.0870688, 0.0878512, 0.0886335, 0.0894158, 0.090198, 0.0909802, 0.0917623, 0.0925444, 0.0933264, 0.0941083, 0.0948902, 0.095672, 0.0964538, 0.0972355, 0.0980171, 0.0987987, 0.0995803, 0.100362, 0.101143, 0.101924, 0.102706, 0.103487, 0.104268, 0.105049, 0.10583, 0.106611, 0.107392, 0.108173, 0.108954, 0.109734, 0.110515, 0.111295, 0.112076, 0.112856, 0.113637, 0.114417, 0.115197, 0.115977, 0.116757, 0.117537, 0.118317, 0.119097, 0.119877, 0.120657, 0.121436, 0.122216, 0.122995, 0.123775, 0.124554, 0.125333, 0.126112, 0.126891, 0.127671, 0.128449, 0.129228, 0.130007, 0.130786, 0.131564, 0.132343, 0.133121, 0.1339, 0.134678, 0.135456, 0.136234, 0.137012, 0.13779, 0.138568, 0.139346, 0.140124, 0.140901, 0.141679, 0.142456, 0.143234, 0.144011, 0.144788, 0.145565, 0.146342, 0.147119, 0.147896, 0.148672, 0.149449, 0.150226, 0.151002, 0.151778, 0.152555, 0.153331, 0.154107, 0.154883, 0.155659, 0.156434,
0.15721, 0.157986, 0.158761, 0.159537, 0.160312, 0.161087, 0.161862, 0.162637, 0.163412, 0.164187, 0.164962, 0.165736, 0.166511, 0.167285, 0.168059, 0.168833, 0.169608, 0.170381, 0.171155, 0.171929, 0.172703, 0.173476, 0.17425, 0.175023, 0.175796, 0.176569, 0.177342, 0.178115, 0.178888, 0.179661, 0.180433, 0.181206, 0.181978, 0.18275, 0.183522, 0.184294, 0.185066, 0.185838, 0.18661, 0.187381, 0.188153, 0.188924, 0.189695, 0.190466, 0.191237, 0.192008, 0.192779, 0.193549, 0.19432, 0.19509, 0.195861, 0.196631, 0.197401, 0.198171, 0.19894, 0.19971, 0.20048, 0.201249, 0.202018, 0.202787, 0.203556, 0.204325, 0.205094, 0.205863, 0.206631, 0.2074, 0.208168, 0.208936, 0.209704, 0.210472, 0.21124, 0.212007, 0.212775, 0.213542, 0.214309, 0.215076, 0.215843, 0.21661, 0.217377, 0.218143, 0.21891, 0.219676, 0.220442, 0.221208, 0.221974, 0.22274, 0.223505, 0.224271, 0.225036, 0.225801, 0.226566, 0.227331, 0.228096, 0.228861, 0.229625, 0.230389, 0.231154, 0.231918, 0.232682, 0.233445,
0.234209, 0.234972, 0.235736, 0.236499, 0.237262, 0.238025, 0.238788, 0.23955, 0.240313, 0.241075, 0.241837, 0.242599, 0.243361, 0.244123, 0.244884, 0.245646, 0.246407, 0.247168, 0.247929, 0.24869, 0.249451, 0.250211, 0.250971, 0.251732, 0.252492, 0.253251, 0.254011, 0.254771, 0.25553, 0.256289, 0.257048, 0.257807, 0.258566, 0.259325, 0.260083, 0.260842, 0.2616, 0.262358, 0.263115, 0.263873, 0.264631, 0.265388, 0.266145, 0.266902, 0.267659, 0.268415, 0.269172, 0.269928, 0.270684, 0.27144, 0.272196, 0.272952, 0.273707, 0.274463, 0.275218, 0.275973, 0.276728, 0.277482, 0.278237, 0.278991, 0.279745, 0.280499, 0.281253, 0.282007, 0.28276, 0.283513, 0.284266, 0.285019, 0.285772, 0.286525, 0.287277, 0.288029, 0.288781, 0.289533, 0.290285, 0.291036, 0.291787, 0.292539, 0.29329, 0.29404, 0.294791, 0.295541, 0.296292, 0.297042, 0.297791, 0.298541, 0.299291, 0.30004, 0.300789, 0.301538, 0.302287, 0.303035, 0.303784, 0.304532, 0.30528, 0.306028, 0.306775, 0.307523, 0.30827, 0.309017,
0.309764, 0.310511, 0.311257, 0.312003, 0.312749, 0.313495, 0.314241, 0.314987, 0.315732, 0.316477, 0.317222, 0.317967, 0.318711, 0.319456, 0.3202, 0.320944, 0.321687, 0.322431, 0.323174, 0.323917, 0.32466, 0.325403, 0.326146, 0.326888, 0.32763, 0.328372, 0.329114, 0.329855, 0.330597, 0.331338, 0.332079, 0.33282, 0.33356, 0.3343, 0.33504, 0.33578, 0.33652, 0.33726, 0.337999, 0.338738, 0.339477, 0.340215, 0.340954, 0.341692, 0.34243, 0.343168, 0.343906, 0.344643, 0.34538, 0.346117, 0.346854, 0.34759, 0.348327, 0.349063, 0.349799, 0.350534, 0.35127, 0.352005, 0.35274, 0.353475, 0.354209, 0.354944, 0.355678, 0.356412, 0.357146, 0.357879, 0.358612, 0.359345, 0.360078, 0.360811, 0.361543, 0.362275, 0.363007, 0.363739, 0.364471, 0.365202, 0.365933, 0.366664, 0.367394, 0.368125, 0.368855, 0.369585, 0.370314, 0.371044, 0.371773, 0.372502, 0.373231, 0.373959, 0.374688, 0.375416, 0.376143, 0.376871, 0.377598, 0.378326, 0.379052, 0.379779, 0.380506, 0.381232, 0.381958, 0.382683,
0.383409, 0.384134, 0.384859, 0.385584, 0.386309, 0.387033, 0.387757, 0.388481, 0.389204, 0.389928, 0.390651, 0.391374, 0.392096, 0.392819, 0.393541, 0.394263, 0.394984, 0.395706, 0.396427, 0.397148, 0.397869, 0.398589, 0.399309, 0.400029, 0.400749, 0.401468, 0.402187, 0.402906, 0.403625, 0.404344, 0.405062, 0.40578, 0.406497, 0.407215, 0.407932, 0.408649, 0.409366, 0.410082, 0.410798, 0.411514, 0.41223, 0.412945, 0.413661, 0.414376, 0.41509, 0.415805, 0.416519, 0.417233, 0.417946, 0.41866, 0.419373, 0.420086, 0.420798, 0.421511, 0.422223, 0.422935, 0.423646, 0.424357, 0.425069, 0.425779, 0.42649, 0.4272, 0.42791, 0.42862, 0.429329, 0.430038, 0.430747, 0.431456, 0.432164, 0.432873, 0.43358, 0.434288, 0.434995, 0.435702, 0.436409, 0.437116, 0.437822, 0.438528, 0.439234, 0.439939, 0.440644, 0.441349, 0.442054, 0.442758, 0.443462, 0.444166, 0.44487, 0.445573, 0.446276, 0.446979, 0.447681, 0.448383, 0.449085, 0.449787, 0.450488, 0.451189, 0.45189, 0.45259, 0.453291, 0.453991,
0.45469, 0.45539, 0.456089, 0.456787, 0.457486, 0.458184, 0.458882, 0.45958, 0.460277, 0.460974, 0.461671, 0.462368, 0.463064, 0.46376, 0.464456, 0.465151, 0.465846, 0.466541, 0.467236, 0.46793, 0.468624, 0.469317, 0.470011, 0.470704, 0.471397, 0.472089, 0.472781, 0.473473, 0.474165, 0.474856, 0.475547, 0.476238, 0.476929, 0.477619, 0.478309, 0.478998, 0.479688, 0.480377, 0.481065, 0.481754, 0.482442, 0.48313, 0.483817, 0.484504, 0.485191, 0.485878, 0.486564, 0.48725, 0.487936, 0.488621, 0.489306, 0.489991, 0.490676, 0.49136, 0.492044, 0.492727, 0.493411, 0.494094, 0.494776, 0.495459, 0.496141, 0.496823, 0.497504, 0.498185, 0.498866, 0.499546, 0.500227, 0.500907, 0.501586, 0.502266, 0.502945, 0.503623, 0.504302, 0.50498, 0.505657, 0.506335, 0.507012, 0.507689, 0.508365, 0.509041, 0.509717, 0.510393, 0.511068, 0.511743, 0.512418, 0.513092, 0.513766, 0.51444, 0.515113, 0.515786, 0.516459, 0.517131, 0.517803, 0.518475, 0.519146, 0.519817, 0.520488, 0.521159, 0.521829, 0.522499,
0.523168, 0.523837, 0.524506, 0.525175, 0.525843, 0.526511, 0.527178, 0.527846, 0.528512, 0.529179, 0.529845, 0.530511, 0.531177, 0.531842, 0.532507, 0.533172, 0.533836, 0.5345, 0.535164, 0.535827, 0.53649, 0.537152, 0.537815, 0.538477, 0.539138, 0.5398, 0.540461, 0.541121, 0.541782, 0.542442, 0.543101, 0.54376, 0.544419, 0.545078, 0.545736, 0.546394, 0.547052, 0.547709, 0.548366, 0.549023, 0.549679, 0.550335, 0.550991, 0.551646, 0.552301, 0.552955, 0.55361, 0.554263, 0.554917, 0.55557, 0.556223, 0.556876, 0.557528, 0.55818, 0.558831, 0.559482, 0.560133, 0.560784, 0.561434, 0.562083, 0.562733, 0.563382, 0.564031, 0.564679, 0.565327, 0.565975, 0.566622, 0.567269, 0.567916, 0.568562, 0.569208, 0.569853, 0.570499, 0.571143, 0.571788, 0.572432, 0.573076, 0.573719, 0.574363, 0.575005, 0.575648, 0.57629, 0.576931, 0.577573, 0.578214, 0.578854, 0.579495, 0.580134, 0.580774, 0.581413, 0.582052, 0.58269, 0.583329, 0.583966, 0.584604, 0.585241, 0.585877, 0.586514, 0.58715, 0.587785,
0.58842, 0.589055, 0.58969, 0.590324, 0.590958, 0.591591, 0.592224, 0.592857, 0.593489, 0.594121, 0.594753, 0.595384, 0.596015, 0.596645, 0.597275, 0.597905, 0.598534, 0.599163, 0.599792, 0.60042, 0.601048, 0.601676, 0.602303, 0.60293, 0.603556, 0.604182, 0.604808, 0.605433, 0.606058, 0.606682, 0.607307, 0.60793, 0.608554, 0.609177, 0.609799, 0.610422, 0.611044, 0.611665, 0.612286, 0.612907, 0.613527, 0.614147, 0.614767, 0.615386, 0.616005, 0.616624, 0.617242, 0.61786, 0.618477, 0.619094, 0.619711, 0.620327, 0.620943, 0.621558, 0.622173, 0.622788, 0.623402, 0.624016, 0.62463, 0.625243, 0.625855, 0.626468, 0.62708, 0.627691, 0.628303, 0.628913, 0.629524, 0.630134, 0.630744, 0.631353, 0.631962, 0.63257, 0.633178, 0.633786, 0.634393, 0.635, 0.635607, 0.636213, 0.636819, 0.637424, 0.638029, 0.638634, 0.639238, 0.639841, 0.640445, 0.641048, 0.64165, 0.642253, 0.642854, 0.643456, 0.644057, 0.644658, 0.645258, 0.645858, 0.646457, 0.647056, 0.647655, 0.648253, 0.648851, 0.649448,
0.650045, 0.650642, 0.651238, 0.651834, 0.652429, 0.653024, 0.653619, 0.654213, 0.654807, 0.6554, 0.655993, 0.656586, 0.657178, 0.65777, 0.658361, 0.658952, 0.659543, 0.660133, 0.660723, 0.661312, 0.661901, 0.662489, 0.663077, 0.663665, 0.664252, 0.664839, 0.665426, 0.666012, 0.666598, 0.667183, 0.667768, 0.668352, 0.668936, 0.66952, 0.670103, 0.670686, 0.671268, 0.67185, 0.672431, 0.673013, 0.673593, 0.674174, 0.674753, 0.675333, 0.675912, 0.67649, 0.677069, 0.677646, 0.678224, 0.678801, 0.679377, 0.679953, 0.680529, 0.681104, 0.681679, 0.682254, 0.682828, 0.683401, 0.683974, 0.684547, 0.685119, 0.685691, 0.686263, 0.686834, 0.687404, 0.687975, 0.688544, 0.689114, 0.689683, 0.690251, 0.690819, 0.691387, 0.691954, 0.692521, 0.693087, 0.693653, 0.694219, 0.694784, 0.695349, 0.695913, 0.696477, 0.69704, 0.697603, 0.698165, 0.698728, 0.699289, 0.69985, 0.700411, 0.700972, 0.701531, 0.702091, 0.70265, 0.703209, 0.703767, 0.704325, 0.704882, 0.705439, 0.705995, 0.706551, 0.707107,
0.707662, 0.708217, 0.708771, 0.709325, 0.709878, 0.710431, 0.710984, 0.711536, 0.712087, 0.712639, 0.713189, 0.71374, 0.714289, 0.714839, 0.715388, 0.715936, 0.716485, 0.717032, 0.71758, 0.718126, 0.718673, 0.719219, 0.719764, 0.720309, 0.720854, 0.721398, 0.721941, 0.722485, 0.723027, 0.72357, 0.724112, 0.724653, 0.725194, 0.725735, 0.726275, 0.726814, 0.727354, 0.727892, 0.728431, 0.728969, 0.729506, 0.730043, 0.73058, 0.731116, 0.731651, 0.732186, 0.732721, 0.733255, 0.733789, 0.734323, 0.734855, 0.735388, 0.73592, 0.736451, 0.736983, 0.737513, 0.738043, 0.738573, 0.739102, 0.739631, 0.740159, 0.740687, 0.741215, 0.741742, 0.742268, 0.742794, 0.74332, 0.743845, 0.74437, 0.744894, 0.745418, 0.745941, 0.746464, 0.746986, 0.747508, 0.74803, 0.748551, 0.749071, 0.749591, 0.750111, 0.75063, 0.751149, 0.751667, 0.752185, 0.752702, 0.753219, 0.753735, 0.754251, 0.754767, 0.755282, 0.755796, 0.75631, 0.756824, 0.757337, 0.75785, 0.758362, 0.758874, 0.759385, 0.759896, 0.760406,
0.760916, 0.761425, 0.761934, 0.762443, 0.76295, 0.763458, 0.763965, 0.764472, 0.764978, 0.765483, 0.765988, 0.766493, 0.766997, 0.767501, 0.768004, 0.768507, 0.769009, 0.769511, 0.770012, 0.770513, 0.771014, 0.771514, 0.772013, 0.772512, 0.77301, 0.773508, 0.774006, 0.774503, 0.775, 0.775496, 0.775991, 0.776487, 0.776981, 0.777475, 0.777969, 0.778462, 0.778955, 0.779447, 0.779939, 0.78043, 0.780921, 0.781412, 0.781901, 0.782391, 0.78288, 0.783368, 0.783856, 0.784344, 0.78483, 0.785317, 0.785803, 0.786288, 0.786773, 0.787258, 0.787742, 0.788226, 0.788709, 0.789191, 0.789673, 0.790155, 0.790636, 0.791117, 0.791597, 0.792077, 0.792556, 0.793035, 0.793513, 0.79399, 0.794468, 0.794944, 0.795421, 0.795896, 0.796372, 0.796846, 0.797321, 0.797794, 0.798268, 0.798741, 0.799213, 0.799685, 0.800156, 0.800627, 0.801097, 0.801567, 0.802036, 0.802505, 0.802974, 0.803441, 0.803909, 0.804376, 0.804842, 0.805308, 0.805773, 0.806238, 0.806703, 0.807166, 0.80763, 0.808093, 0.808555, 0.809017,
0.809478, 0.809939, 0.8104, 0.81086, 0.811319, 0.811778, 0.812236, 0.812694, 0.813152, 0.813608, 0.814065, 0.814521, 0.814976, 0.815431, 0.815885, 0.816339, 0.816793, 0.817246, 0.817698, 0.81815, 0.818601, 0.819052, 0.819502, 0.819952, 0.820401, 0.82085, 0.821299, 0.821746, 0.822194, 0.822641, 0.823087, 0.823533, 0.823978, 0.824423, 0.824867, 0.825311, 0.825754, 0.826197, 0.826639, 0.827081, 0.827522, 0.827962, 0.828403, 0.828842, 0.829282, 0.82972, 0.830158, 0.830596, 0.831033, 0.83147, 0.831906, 0.832341, 0.832776, 0.833211, 0.833645, 0.834078, 0.834511, 0.834944, 0.835376, 0.835807, 0.836238, 0.836669, 0.837099, 0.837528, 0.837957, 0.838385, 0.838813, 0.83924, 0.839667, 0.840094, 0.840519, 0.840945, 0.841369, 0.841794, 0.842217, 0.84264, 0.843063, 0.843485, 0.843907, 0.844328, 0.844749, 0.845169, 0.845588, 0.846007, 0.846426, 0.846844, 0.847261, 0.847678, 0.848094, 0.84851, 0.848926, 0.84934, 0.849755, 0.850169, 0.850582, 0.850994, 0.851407, 0.851818, 0.85223, 0.85264,
0.85305, 0.85346, 0.853869, 0.854277, 0.854685, 0.855093, 0.8555, 0.855906, 0.856312, 0.856718, 0.857122, 0.857527, 0.85793, 0.858334, 0.858736, 0.859139, 0.85954, 0.859941, 0.860342, 0.860742, 0.861142, 0.861541, 0.861939, 0.862337, 0.862734, 0.863131, 0.863528, 0.863923, 0.864319, 0.864713, 0.865108, 0.865501, 0.865894, 0.866287, 0.866679, 0.867071, 0.867462, 0.867852, 0.868242, 0.868632, 0.86902, 0.869409, 0.869797, 0.870184, 0.87057, 0.870957, 0.871342, 0.871727, 0.872112, 0.872496, 0.87288, 0.873262, 0.873645, 0.874027, 0.874408, 0.874789, 0.875169, 0.875549, 0.875928, 0.876307, 0.876685, 0.877062, 0.877439, 0.877816, 0.878192, 0.878567, 0.878942, 0.879316, 0.87969, 0.880063, 0.880436, 0.880808, 0.88118, 0.881551, 0.881921, 0.882291, 0.882661, 0.88303, 0.883398, 0.883766, 0.884133, 0.8845, 0.884866, 0.885231, 0.885596, 0.885961, 0.886325, 0.886688, 0.887051, 0.887413, 0.887775, 0.888136, 0.888497, 0.888857, 0.889217, 0.889576, 0.889934, 0.890292, 0.89065, 0.891007,
0.891363, 0.891719, 0.892074, 0.892428, 0.892782, 0.893136, 0.893489, 0.893841, 0.894193, 0.894545, 0.894895, 0.895246, 0.895595, 0.895944, 0.896293, 0.896641, 0.896989, 0.897335, 0.897682, 0.898028, 0.898373, 0.898718, 0.899062, 0.899405, 0.899748, 0.900091, 0.900433, 0.900774, 0.901115, 0.901455, 0.901795, 0.902134, 0.902473, 0.902811, 0.903148, 0.903485, 0.903821, 0.904157, 0.904492, 0.904827, 0.905161, 0.905495, 0.905828, 0.90616, 0.906492, 0.906823, 0.907154, 0.907484, 0.907814, 0.908143, 0.908472, 0.9088, 0.909127, 0.909454, 0.90978, 0.910106, 0.910431, 0.910756, 0.91108, 0.911403, 0.911726, 0.912049, 0.91237, 0.912692, 0.913012, 0.913332, 0.913652, 0.913971, 0.914289, 0.914607, 0.914924, 0.915241, 0.915557, 0.915873, 0.916188, 0.916502, 0.916816, 0.91713, 0.917442, 0.917755, 0.918066, 0.918377, 0.918688, 0.918998, 0.919307, 0.919616, 0.919924, 0.920232, 0.920539, 0.920845, 0.921151, 0.921457, 0.921762, 0.922066, 0.92237, 0.922673, 0.922975, 0.923277, 0.923579, 0.92388,
0.92418, 0.92448, 0.924779, 0.925077, 0.925375, 0.925673, 0.925969, 0.926266, 0.926561, 0.926857, 0.927151, 0.927445, 0.927739, 0.928031, 0.928324, 0.928615, 0.928907, 0.929197, 0.929487, 0.929776, 0.930065, 0.930354, 0.930641, 0.930928, 0.931215, 0.931501, 0.931786, 0.932071, 0.932355, 0.932639, 0.932922, 0.933205, 0.933487, 0.933768, 0.934049, 0.934329, 0.934609, 0.934888, 0.935166, 0.935444, 0.935721, 0.935998, 0.936274, 0.93655, 0.936825, 0.937099, 0.937373, 0.937647, 0.937919, 0.938191, 0.938463, 0.938734, 0.939004, 0.939274, 0.939543, 0.939812, 0.94008, 0.940348, 0.940614, 0.940881, 0.941147, 0.941412, 0.941676, 0.94194, 0.942204, 0.942467, 0.942729, 0.942991, 0.943252, 0.943512, 0.943772, 0.944031, 0.94429, 0.944548, 0.944806, 0.945063, 0.94532, 0.945575, 0.945831, 0.946085, 0.946339, 0.946593, 0.946846, 0.947098, 0.94735, 0.947601, 0.947852, 0.948102, 0.948351, 0.9486, 0.948848, 0.949096, 0.949343, 0.94959, 0.949836, 0.950081, 0.950326, 0.95057, 0.950814, 0.951057,
0.951299, 0.951541, 0.951782, 0.952023, 0.952263, 0.952502, 0.952741, 0.952979, 0.953217, 0.953454, 0.953691, 0.953927, 0.954162, 0.954397, 0.954631, 0.954865, 0.955098, 0.95533, 0.955562, 0.955793, 0.956024, 0.956254, 0.956483, 0.956712, 0.95694, 0.957168, 0.957395, 0.957622, 0.957848, 0.958073, 0.958298, 0.958522, 0.958745, 0.958968, 0.959191, 0.959412, 0.959634, 0.959854, 0.960074, 0.960294, 0.960513, 0.960731, 0.960948, 0.961165, 0.961382, 0.961598, 0.961813, 0.962028, 0.962242, 0.962455, 0.962668, 0.96288, 0.963092, 0.963303, 0.963514, 0.963724, 0.963933, 0.964142, 0.96435, 0.964557, 0.964764, 0.964971, 0.965176, 0.965382, 0.965586, 0.96579, 0.965994, 0.966196, 0.966399, 0.9666, 0.966801, 0.967001, 0.967201, 0.9674, 0.967599, 0.967797, 0.967995, 0.968191, 0.968388, 0.968583, 0.968778, 0.968973, 0.969166, 0.96936, 0.969552, 0.969744, 0.969936, 0.970127, 0.970317, 0.970506, 0.970696, 0.970884, 0.971072, 0.971259, 0.971446, 0.971632, 0.971817, 0.972002, 0.972186, 0.97237,
0.972553, 0.972735, 0.972917, 0.973099, 0.973279, 0.973459, 0.973639, 0.973818, 0.973996, 0.974173, 0.97435, 0.974527, 0.974703, 0.974878, 0.975053, 0.975227, 0.9754, 0.975573, 0.975745, 0.975917, 0.976088, 0.976258, 0.976428, 0.976597, 0.976766, 0.976934, 0.977101, 0.977268, 0.977434, 0.9776, 0.977765, 0.977929, 0.978093, 0.978256, 0.978419, 0.978581, 0.978742, 0.978903, 0.979063, 0.979223, 0.979382, 0.97954, 0.979698, 0.979855, 0.980012, 0.980168, 0.980323, 0.980478, 0.980632, 0.980785, 0.980938, 0.981091, 0.981242, 0.981393, 0.981544, 0.981694, 0.981843, 0.981992, 0.98214, 0.982287, 0.982434, 0.98258, 0.982726, 0.982871, 0.983016, 0.983159, 0.983303, 0.983445, 0.983587, 0.983729, 0.983869, 0.98401, 0.984149, 0.984288, 0.984427, 0.984564, 0.984702, 0.984838, 0.984974, 0.985109, 0.985244, 0.985378, 0.985512, 0.985645, 0.985777, 0.985909, 0.98604, 0.98617, 0.9863, 0.986429, 0.986558, 0.986686, 0.986813, 0.98694, 0.987066, 0.987192, 0.987317, 0.987441, 0.987565, 0.987688,
0.987811, 0.987933, 0.988054, 0.988175, 0.988295, 0.988415, 0.988533, 0.988652, 0.988769, 0.988887, 0.989003, 0.989119, 0.989234, 0.989349, 0.989463, 0.989576, 0.989689, 0.989801, 0.989913, 0.990024, 0.990134, 0.990244, 0.990353, 0.990461, 0.990569, 0.990677, 0.990783, 0.990889, 0.990995, 0.9911, 0.991204, 0.991308, 0.991411, 0.991513, 0.991615, 0.991716, 0.991817, 0.991917, 0.992016, 0.992115, 0.992213, 0.99231, 0.992407, 0.992504, 0.992599, 0.992694, 0.992789, 0.992883, 0.992976, 0.993068, 0.99316, 0.993252, 0.993343, 0.993433, 0.993522, 0.993611, 0.9937, 0.993787, 0.993874, 0.993961, 0.994047, 0.994132, 0.994217, 0.994301, 0.994384, 0.994467, 0.994549, 0.994631, 0.994712, 0.994792, 0.994872, 0.994951, 0.99503, 0.995107, 0.995185, 0.995261, 0.995337, 0.995413, 0.995488, 0.995562, 0.995636, 0.995709, 0.995781, 0.995853, 0.995924, 0.995994, 0.996064, 0.996134, 0.996202, 0.99627, 0.996338, 0.996405, 0.996471, 0.996537, 0.996602, 0.996666, 0.99673, 0.996793, 0.996855, 0.996917,
0.996979, 0.997039, 0.997099, 0.997159, 0.997218, 0.997276, 0.997334, 0.997391, 0.997447, 0.997503, 0.997558, 0.997613, 0.997666, 0.99772, 0.997772, 0.997825, 0.997876, 0.997927, 0.997977, 0.998027, 0.998076, 0.998124, 0.998172, 0.998219, 0.998266, 0.998312, 0.998357, 0.998402, 0.998446, 0.998489, 0.998532, 0.998574, 0.998616, 0.998657, 0.998697, 0.998737, 0.998776, 0.998815, 0.998853, 0.99889, 0.998927, 0.998963, 0.998998, 0.999033, 0.999067, 0.999101, 0.999134, 0.999166, 0.999198, 0.999229, 0.99926, 0.999289, 0.999319, 0.999347, 0.999376, 0.999403, 0.99943, 0.999456, 0.999482, 0.999507, 0.999531, 0.999555, 0.999578, 0.9996, 0.999622, 0.999643, 0.999664, 0.999684, 0.999704, 0.999722, 0.999741, 0.999758, 0.999775, 0.999792, 0.999807, 0.999822, 0.999837, 0.999851, 0.999864, 0.999877, 0.999889, 0.9999, 0.999911, 0.999921, 0.999931, 0.99994, 0.999948, 0.999956, 0.999963, 0.999969, 0.999975, 0.99998, 0.999985, 0.999989, 0.999992, 0.999995, 0.999997, 0.999999, 1, };
#endif

	namespace nsMath {

		//変数のサイズを取得
		template<typename T>
		constexpr auto getSize(T* a) {
			return (sizeof(a) / sizeof(a[0]));
		}

		//二乗
		template<typename T>
		constexpr T pow2(T a) {
			return ((a) * (a));
		}

		//どちらが大きいか
		template<typename T>
		constexpr T nsMax(T a, T b) {
			return (((a) < (b)) ? (b) : (a));
		}

		//どっちが小さいか
		template<typename T>
		constexpr T nsMin(T a, T b) {
			return (((a) < (b)) ? (a) : (b));
		}

#ifndef NS_USE_STD_SIN//std::sin()を使うかnsSinTabl()を使うか。
		inline nsfloat sinTable(int t) {
			if (SMPL == 44100)
				return sinTabel_44100[t];
			else if (SMPL == 8000)
				return sinTabel_8000[t];
			else
				return sin((nsfloat)t * 2.0 * PI / 8000.0);
		}

		//テーブル化されたsin関数
		//引数には時間[s・SMPL]と周波数[Hz]を入れてください。
		//
		//nsFastSin(t,freq) == sin(t / freq * 2.0 * PI / SMPL)
		inline nsfloat nsSinTable(nsfloat t, nsfloat freq) {
			nsfloat theta = 0.0, index = 0.0, a = t * SMPL_INV * freq;
			if (a == (nsfloat)0.0)
				return (nsfloat)0.0;
			else
				//0~1の範囲に調節
				theta = a - std::floor(a) + (nsfloat)((a < (nsfloat)0.0) ? 1 : 0);
			
			//0~0.5の範囲に調節
			if (theta >= (nsfloat)0.5)
				index = theta - (nsfloat)0.5;
			else
				index = theta;

			//0~0.25の範囲に調節
			if (index >= (nsfloat)0.25)index = (nsfloat)0.5 - index;

			if (index == 0.25)return (nsfloat)((theta >= (nsfloat)0.5) ? -1 : 1);
			return sinTable((int)(index * (nsfloat)SMPL)) * (nsfloat)((theta >= (nsfloat)0.5) ? -1 : 1);
		}
		inline nsfloat nsCosTable(nsfloat t, nsfloat freq) {
			return nsSinTable(t + (nsfloat)SMPL * (nsfloat)0.25, freq);
		}
#else
		//テーブル化されたsin関数を使いたくない場合
		//引数には時間[s・SMPL]と周波数[Hz]を入れてください。
		//
		//nsFastSin(t,freq) == sin(t / freq * 2.0 * PI / SMPL)
		inline nsfloat nsSinTabel(nsfloat t, nsfloat freq) {
			return std::sin(t / freq * 2.0 * PI / SMPL);
		}
		inline nsfloat nsCosTabel(nsfloat t, nsfloat freq) {
			return std::cos(t / freq * 2.0 * PI / SMPL);
		}
#endif

	}


}//namespace Nesora


#endif//NESORA_H



