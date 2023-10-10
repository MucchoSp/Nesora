#pragma once

//Copyright Ⓒ 2023 Gabuniku(https://github.com/Gabuniku) & MucchoSP

#ifndef NORMALIZATION_TO_NESORA_H
#define NORMALIZATION_TO_NESORA_H

#include <string>

namespace Normalization_to_Nesora {

	// あ行
	constexpr uint32_t HIRA_XA = 0xE38181;
	constexpr uint32_t HIRA_A = 0xE38182;
	constexpr uint32_t HIRA_XI = 0xE38183;
	constexpr uint32_t HIRA_I = 0xE38184;
	constexpr uint32_t HIRA_XU = 0xE38185;
	constexpr uint32_t HIRA_U = 0xE38186;
	constexpr uint32_t HIRA_XE = 0xE38187;
	constexpr uint32_t HIRA_E = 0xE38188;
	constexpr uint32_t HIRA_XO = 0xE38189;
	constexpr uint32_t HIRA_O = 0xE3818A;
	// か行
	constexpr uint32_t HIRA_KA = 0xE3818B;
	constexpr uint32_t HIRA_GA = 0xE3818C;
	constexpr uint32_t HIRA_KI = 0xE3818D;
	constexpr uint32_t HIRA_GI = 0xE3818E;
	constexpr uint32_t HIRA_KU = 0xE3818F;
	constexpr uint32_t HIRA_GU = 0xE38190;
	constexpr uint32_t HIRA_KE = 0xE38191;
	constexpr uint32_t HIRA_GE = 0xE38192;
	constexpr uint32_t HIRA_KO = 0xE38193;
	constexpr uint32_t HIRA_GO = 0xE38194;
	// さ行
	constexpr uint32_t HIRA_SA = 0xE38195;
	constexpr uint32_t HIRA_ZA = 0xE38196;
	constexpr uint32_t HIRA_SI = 0xE38197;
	constexpr uint32_t HIRA_ZI = 0xE38198;
	constexpr uint32_t HIRA_SU = 0xE38199;
	constexpr uint32_t HIRA_ZU = 0xE3819A;
	constexpr uint32_t HIRA_SE = 0xE3819B;
	constexpr uint32_t HIRA_ZE = 0xE3819C;
	constexpr uint32_t HIRA_SO = 0xE3819D;
	constexpr uint32_t HIRA_ZO = 0xE3819E;
	// た行
	constexpr uint32_t HIRA_TA = 0xE3819F;
	constexpr uint32_t HIRA_DA = 0xE381A0;
	constexpr uint32_t HIRA_TI = 0xE381A1;
	constexpr uint32_t HIRA_DI = 0xE381A2;
	constexpr uint32_t HIRA_XTU = 0xE381A3;
	constexpr uint32_t HIRA_TU = 0xE381A4;
	constexpr uint32_t HIRA_DU = 0xE381A5;
	constexpr uint32_t HIRA_TE = 0xE381A6;
	constexpr uint32_t HIRA_DE = 0xE381A7;
	constexpr uint32_t HIRA_TO = 0xE381A8;
	constexpr uint32_t HIRA_DO = 0xE381A9;
	// な行
	constexpr uint32_t HIRA_NA = 0xE381AA;
	constexpr uint32_t HIRA_NI = 0xE381AB;
	constexpr uint32_t HIRA_NU = 0xE381AC;
	constexpr uint32_t HIRA_NE = 0xE381AD;
	constexpr uint32_t HIRA_NO = 0xE381AE;
	// た行
	constexpr uint32_t HIRA_HA = 0xE381AF;
	constexpr uint32_t HIRA_BA = 0xE381B0;
	constexpr uint32_t HIRA_PA = 0xE381B1;
	constexpr uint32_t HIRA_HI = 0xE381B2;
	constexpr uint32_t HIRA_BI = 0xE381B3;
	constexpr uint32_t HIRA_PI = 0xE381B4;
	constexpr uint32_t HIRA_HU = 0xE381B5;
	constexpr uint32_t HIRA_BU = 0xE381B6;
	constexpr uint32_t HIRA_PU = 0xE381B7;
	constexpr uint32_t HIRA_HE = 0xE381B8;
	constexpr uint32_t HIRA_BE = 0xE381B9;
	constexpr uint32_t HIRA_PE = 0xE381BA;
	constexpr uint32_t HIRA_HO = 0xE381BB;
	constexpr uint32_t HIRA_BO = 0xE381BC;
	constexpr uint32_t HIRA_PO = 0xE381BD;
	// ま行
	constexpr uint32_t HIRA_MA = 0xE381BE;
	constexpr uint32_t HIRA_MI = 0xE381BF;
	constexpr uint32_t HIRA_MU = 0xE38280;
	constexpr uint32_t HIRA_ME = 0xE38281;
	constexpr uint32_t HIRA_MO = 0xE38282;
	// や行
	constexpr uint32_t HIRA_XYA = 0xE38283;
	constexpr uint32_t HIRA_YA = 0xE38284;
	constexpr uint32_t HIRA_XYU = 0xE38285;
	constexpr uint32_t HIRA_YU = 0xE38286;
	constexpr uint32_t HIRA_XYO = 0xE38287;
	constexpr uint32_t HIRA_YO = 0xE38288;
	// ら行
	constexpr uint32_t HIRA_RA = 0xE38289;
	constexpr uint32_t HIRA_RI = 0xE3828A;
	constexpr uint32_t HIRA_RU = 0xE3828B;
	constexpr uint32_t HIRA_RE = 0xE3828C;
	constexpr uint32_t HIRA_RO = 0xE3828D;
	// わ行
	constexpr uint32_t HIRA_WA = 0xE3828F;
	constexpr uint32_t HIRA_WI = 0xE38290;
	constexpr uint32_t HIRA_WE = 0xE38291;
	constexpr uint32_t HIRA_WO = 0xE38292;
	// ん
	constexpr uint32_t HIRA_NN = 0xE38293;
	// ゔヵヶ
	constexpr uint32_t HIRA_VU = 0xE38294;
	constexpr uint32_t HIRA_XKA = 0xE38295;
	constexpr uint32_t HIRA_XKE = 0xE38296;
	// カタカナオフセット
	constexpr uint32_t KATA_OFFSET = 0x000120;
	constexpr uint32_t KATA_OFFSET2 = 0x0001E0;//ダ(E38380)～ミ(E3838F)はずれています。くそが

	constexpr uint32_t HIRA_KUTEN = 0xE38081;//、
	constexpr uint32_t HIRA_KUTOUTEN = 0xE38082;//。
	constexpr uint32_t HIRA_NOBASHI = 0xE383BC;//ー

	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_LEFT_ANGLE_BRACKET			= 0xE38088;//〈
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_ANGLE_BRACKET			= 0xE38089;//〉
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_LEFT_DOUBLE_ANGLE_BRACKET	= 0xE3808A;//《
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_DOUBLE_ANGLE_BRACKET	= 0xE3808B;//》
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_LEFT_CORNER_BRACKET			= 0xE3808C;//「
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_CORNER_BRACKET			= 0xE3808D;//」
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_LEFT_WHITE_CORNER_BRACKET	= 0xE3808E;//『
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_WHITE_CORNER_BRACKET	= 0xE3808F;//』
	
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_LEFT_BLACK_LENTICULAR_BRACKET		= 0xE38090;//【
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_BLACK_LENTICULAR_BRACKET		= 0xE38091;//】
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_POSTAL_MARK							= 0xE38092;//〒
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_GETA_MARK							= 0xE38093;//〓
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_LEFT_TORTOISE_SHELL_BRACKET			= 0xE38094;//〔
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_TORTOISE_SHELL_BRACKET			= 0xE38095;//〕
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_LEFT_WHITE_LENTICULAR_BRACKET		= 0xE38096;//〖
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_WHITE_LENTICULAR_BRACKET		= 0xE38097;//〗
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_LEFT_WHITE_TORTOISE_SHELL_BRACKET	= 0xE38098;//〘
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_WHITE_TORTOISE_SHELL_BRACKET	= 0xE38099;//〙
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_LEFT_WHITE_SQUARE_BRACKET			= 0xE3809A;//〚
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_WHITE_SQUARE_BRACKET			= 0xE3809B;//〛
	constexpr uint32_t CJK_SYMBOLS_AND_PUNCTUATION_WAVE_DASH							= 0xE3809C;//〜

	constexpr uint32_t IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_JANUARY		= 0xE38B80;//㋀
	constexpr uint32_t IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_FEBRUARY	= 0xE38B81;//㋁
	constexpr uint32_t IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_MARCH		= 0xE38B82;//㋂
	constexpr uint32_t IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_APRIL		= 0xE38B83;//㋃
	constexpr uint32_t IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_MAY			= 0xE38B84;//㋄
	constexpr uint32_t IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_JUNE		= 0xE38B85;//㋅
	constexpr uint32_t IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_JULY		= 0xE38B86;//㋆
	constexpr uint32_t IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_AUGUST		= 0xE38B87;//㋇
	constexpr uint32_t IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_SEPTEMBER	= 0xE38B88;//㋈
	constexpr uint32_t IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_OCTOBER		= 0xE38B89;//㋉
	constexpr uint32_t IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_NOVEMBER	= 0xE38B8A;//㋊
	constexpr uint32_t IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DECEMBER	= 0xE38B8B;//㋋

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_APAATO		= 0xE38C80;//㌀
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ARUHUA		= 0xE38C81;//㌁
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ANPEA		= 0xE38C82;//㌂
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_AARU		= 0xE38C83;//㌃
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ININGU		= 0xE38C84;//㌄
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_INTI		= 0xE38C85;//㌅
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_UON			= 0xE38C86;//㌆
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ESUKUUDO	= 0xE38C87;//㌇
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_EEKAA		= 0xE38C88;//㌈
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ONSU		= 0xE38C89;//㌉
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_OOMU		= 0xE38C8A;//㌊
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KAIRI		= 0xE38C8B;//㌋
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KARATTO		= 0xE38C8C;//㌌
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KARORII		= 0xE38C8D;//㌍
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_GARON		= 0xE38C8E;//㌎
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_GANMA		= 0xE38C8F;//㌏

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_GIGA		= 0xE38C90;//㌐
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_GINII		= 0xE38C91;//㌑
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KYURII		= 0xE38C92;//㌒
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_GIRUDAA		= 0xE38C93;//㌓
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KIRO		= 0xE38C94;//㌔
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KIROGURAMU	= 0xE38C95;//㌕
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KIROMEETORU = 0xE38C96;//㌖
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KIROWATTO	= 0xE38C97;//㌗
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_GURAMU		= 0xE38C98;//㌘
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_GURAMUTON	= 0xE38C99;//㌙
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KURUZEIRO	= 0xE38C9A;//㌚
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KUROONE		= 0xE38C9B;//㌛
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KEESU		= 0xE38C9C;//㌜
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KORUNA		= 0xE38C9D;//㌝
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KOOPO		= 0xE38C9E;//㌞
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_SAIKURU		= 0xE38C9F;//㌟

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_SANTIIMU	= 0xE38CA0;//㌠
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_SIRINGU		= 0xE38CA1;//㌡
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_SENTI		= 0xE38CA2;//㌢
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_SENTO		= 0xE38CA3;//㌣
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_DAASU		= 0xE38CA4;//㌤
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_DESI		= 0xE38CA5;//㌥
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_SORU		= 0xE38CA6;//㌦
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_TON			= 0xE38CA7;//㌧
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_NANO		= 0xE38CA8;//㌨
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_NOTTO		= 0xE38CA9;//㌩
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_HAITU		= 0xE38CAA;//㌪
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PAASENTO	= 0xE38CAB;//㌫
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PAATU		= 0xE38CAC;//㌬
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_BAARERU		= 0xE38CAD;//㌭
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PIASUTORU	= 0xE38CAE;//㌮
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PIKURU		= 0xE38CAF;//㌯

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PIKO		= 0xE38CB0;//㌰
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_BIRU		= 0xE38CB1;//㌱
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_HUARADDO	= 0xE38CB2;//㌲
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_HUIITO		= 0xE38CB3;//㌳
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_BUSSYERU	= 0xE38CB4;//㌴
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_HURAN		= 0xE38CB5;//㌵
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_HEKUTAARU	= 0xE38CB6;//㌶
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PESO		= 0xE38CB7;//㌷
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PENIHI		= 0xE38CB8;//㌸
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_HERUTU		= 0xE38CB9;//㌹
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PENSU		= 0xE38CBA;//㌺
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PEEZI		= 0xE38CBB;//㌻
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_BEETA		= 0xE38CBC;//㌼
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_POINTO		= 0xE38CBD;//㌽
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_BORUTO		= 0xE38CBE;//㌾
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_HON			= 0xE38CBF;//㌿

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PONDO		= 0xE38D80;//㍀
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_HOORU		= 0xE38D81;//㍁
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_HOON		= 0xE38D82;//㍂
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MAIKURO		= 0xE38D83;//㍃
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MAIRU		= 0xE38D84;//㍄
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MAHHA		= 0xE38D85;//㍅
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MARUKU		= 0xE38D86;//㍆
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MANSYON		= 0xE38D87;//㍇
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MIKURON		= 0xE38D88;//㍈
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MIRI		= 0xE38D89;//㍉
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MIRIBAARU	= 0xE38D8A;//㍊
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MEGA		= 0xE38D8B;//㍋
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MEGATON		= 0xE38D8C;//㍌
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MEETORU		= 0xE38D8D;//㍍
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_YAADO		= 0xE38D8E;//㍎
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_YAARU		= 0xE38D8F;//㍏

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_YUAN		= 0xE38D90;//㍐
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_RITTORU		= 0xE38D91;//㍑
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_RIRA		= 0xE38D92;//㍒
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_RUPII		= 0xE38D93;//㍓
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_RUUBURU		= 0xE38D94;//㍔
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_REMU		= 0xE38D95;//㍕
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_RENTOGEN	= 0xE38D96;//㍖
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_WATTO		= 0xE38D97;//㍗
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_ZERO		= 0xE38D98;//㍘
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_ONE		= 0xE38D99;//㍙
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TWO		= 0xE38D9A;//㍚
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_THREE	= 0xE38D9B;//㍛
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_FOUR		= 0xE38D9C;//㍜
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_FIVE		= 0xE38D9D;//㍝
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_SIX		= 0xE38D9E;//㍞
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_SEVEN	= 0xE38D9F;//㍟

	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_EIGHT	= 0xE38DA0;//㍠
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_NINE		= 0xE38DA1;//㍡
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TEN		= 0xE38DA2;//㍢
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_ELEVEN	= 0xE38DA3;//㍣
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TWELVE	= 0xE38DA4;//㍤
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_THIRTEEN = 0xE38DA5;//㍥
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_FOURTEEN = 0xE38DA6;//㍦
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_FIFTEEN	= 0xE38DA7;//㍧
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_SIXTEEN	= 0xE38DA8;//㍨
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_SEVENTEEN	= 0xE38DA9;//㍩
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_EIGHTEEN		= 0xE38DAA;//㍪
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_NINETEEN		= 0xE38DAB;//㍫
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TWENTY		= 0xE38DAC;//㍬
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TWENTY_ONE	= 0xE38DAD;//㍭
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TWENTY_TWO	= 0xE38DAE;//㍮
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TWENTY_THREE = 0xE38DAF;//㍯

	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TWENTY_FOUR	= 0xE38DB0;//㍰
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_HPA			= 0xE38DB1;//㍱
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_DA			= 0xE38DB2;//㍲
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_AU			= 0xE38DB3;//㍳
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_BAR			= 0xE38DB4;//㍴
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_OV			= 0xE38DB5;//㍵
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PC			= 0xE38DB6;//㍶
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_DM			= 0xE38DB7;//㍷
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_DM_SQUARED	= 0xE38DB8;//㍸
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_DM_CUBED	= 0xE38DB9;//㍹
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_IU			= 0xE38DBA;//㍺
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_EAR_NAME_HEISEI		= 0xE38DBB;//㍻
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_EAR_NAME_SYOUWA		= 0xE38DBC;//㍼
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_EAR_NAME_TAISYOU	= 0xE38DBD;//㍽
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_EAR_NAME_MEIZI		= 0xE38DBE;//㍾
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_CORPORATION = 0xE38DBF;//㍿

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PA_AMPS		= 0xE38E80;//㎀
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_NA			= 0xE38E81;//㎁
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MU_A		= 0xE38E82;//㎂
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MA			= 0xE38E83;//㎃
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KA			= 0xE38E84;//㎄
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KB			= 0xE38E85;//㎅
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MB			= 0xE38E86;//㎆
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_GB			= 0xE38E87;//㎇
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_CAL			= 0xE38E88;//㎈
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KCAL		= 0xE38E89;//㎉
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PF			= 0xE38E8A;//㎊
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_NF			= 0xE38E8B;//㎋
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MU_F		= 0xE38E8C;//㎌
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MU_G		= 0xE38E8D;//㎍
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MG			= 0xE38E8E;//㎎
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KG			= 0xE38E8F;//㎏

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_HZ			= 0xE38E90;//㎐
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KHZ			= 0xE38E91;//㎑
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MHZ			= 0xE38E92;//㎒
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_GHZ			= 0xE38E93;//㎓
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_THZ			= 0xE38E94;//㎔
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MU_L		= 0xE38E95;//㎕
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ML			= 0xE38E96;//㎖
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_DL			= 0xE38E97;//㎗
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KL			= 0xE38E98;//㎘
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_FM			= 0xE38E99;//㎙
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_NM			= 0xE38E9A;//㎚
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MU_M		= 0xE38E9B;//㎛
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MM			= 0xE38E9C;//㎜
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_CM			= 0xE38E9D;//㎝
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KM			= 0xE38E9E;//㎞
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MM_SQUARED	= 0xE38E9F;//㎟

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_CM_SQUARED	= 0xE38EA0;//㎠
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_M_SQUARED	= 0xE38EA1;//㎡
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KM_SQUARED	= 0xE38EA2;//㎢
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MM_CUBED	= 0xE38EA3;//㎣
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_CM_CUBED	= 0xE38EA4;//㎤
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_M_CUBED		= 0xE38EA5;//㎥
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KM_CUBED	= 0xE38EA6;//㎦
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_M_OVER_S	= 0xE38EA7;//㎧
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_M_OVER_S_SQUARED	= 0xE38EA8;//㎨
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PA			= 0xE38EA9;//㎩
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KPA			= 0xE38EAA;//㎪
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MPA			= 0xE38EAB;//㎫
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_GPA			= 0xE38EAC;//㎬
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_RAD			= 0xE38EAD;//㎭
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_RAD_OVER_S	= 0xE38EAE;//㎮
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_RAD_OVER_S_SQUARED	= 0xE38EAF;//㎯

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PS			= 0xE38EB0;//㎰
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_NS			= 0xE38EB1;//㎱
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MU_S		= 0xE38EB2;//㎲
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MS			= 0xE38EB3;//㎳
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PV			= 0xE38EB4;//㎴
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_NV			= 0xE38EB5;//㎵
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MU_V		= 0xE38EB6;//㎶
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MV			= 0xE38EB7;//㎷
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KV			= 0xE38EB8;//㎸
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MV_MEGA		= 0xE38EB9;//㎹
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PW			= 0xE38EBA;//㎺
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_NW			= 0xE38EBB;//㎻
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MU_W		= 0xE38EBC;//㎼
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MW			= 0xE38EBD;//㎽
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KW			= 0xE38EBE;//㎾
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MW_MWGA		= 0xE38EBF;//㎿

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_K_OHM		= 0xE38F80;//㏀
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_M_OHM		= 0xE38F81;//㏁
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_AM			= 0xE38F82;//㏂
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_BQ			= 0xE38F83;//㏃
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_CC			= 0xE38F84;//㏄
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_CD			= 0xE38F85;//㏅
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_C_OVER_KG	= 0xE38F86;//㏆
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_CO			= 0xE38F87;//㏇
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_DB			= 0xE38F88;//㏈
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_GY			= 0xE38F89;//㏉
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_HA			= 0xE38F8A;//㏊
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_HP			= 0xE38F8B;//㏋
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_IN			= 0xE38F8C;//㏌
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KK			= 0xE38F8D;//㏍
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KM_CAPITAL	= 0xE38F8E;//㏎
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_KT			= 0xE38F8F;//㏏

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_LM			= 0xE38F90;//㏐
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_LN			= 0xE38F91;//㏑
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_LOG			= 0xE38F92;//㏒
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_LX			= 0xE38F93;//㏓
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MB_SMALL	= 0xE38F94;//㏔
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MIL			= 0xE38F95;//㏕
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_MOL			= 0xE38F96;//㏖
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PH			= 0xE38F97;//㏗
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PM			= 0xE38F98;//㏘
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PPM			= 0xE38F99;//㏙
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_PR			= 0xE38F9A;//㏚
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_SR			= 0xE38F9B;//㏛
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_SV			= 0xE38F9C;//㏜
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_WB			= 0xE38F9D;//㏝
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_V_OVER_M	= 0xE38F9E;//㏞
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_A_OVER_M	= 0xE38F9F;//㏟
	
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_ONE			= 0xE38FA0;//㏠
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWO			= 0xE38FA1;//㏡
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_THREE			= 0xE38FA2;//㏢
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_FOUR			= 0xE38FA3;//㏣
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_FIVE			= 0xE38FA4;//㏤
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_SIX			= 0xE38FA5;//㏥
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_SEVEN			= 0xE38FA6;//㏦
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_EIGHT			= 0xE38FA7;//㏧
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_NINE			= 0xE38FA8;//㏨
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TEN			= 0xE38FA9;//㏩
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_ELEVEN		= 0xE38FAA;//㏪
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWELVE		= 0xE38FAB;//㏫
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_THIRTEEN		= 0xE38FAC;//㏬
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_FOURTEEN		= 0xE38FAD;//㏭
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_FIFTEEN		= 0xE38FAE;//㏮
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_SIXTEEN		= 0xE38FAF;//㏯

	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_SEVENTEEN		= 0xE38FB0;//㏰
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_EIGHTEEN		= 0xE38FB1;//㏱
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_NINETEEN		= 0xE38FB2;//㏲
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY		= 0xE38FB3;//㏳
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_ONE	= 0xE38FB4;//㏴
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_TWO	= 0xE38FB5;//㏵
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_THREE	= 0xE38FB6;//㏶
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_FOUR	= 0xE38FB7;//㏷
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_FIVE	= 0xE38FB8;//㏸
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_SIX	= 0xE38FB9;//㏹
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_SEVEN	= 0xE38FBA;//㏺
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_EIGHT	= 0xE38FBB;//㏻
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_NINE	= 0xE38FBC;//㏼
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_THIRTY		= 0xE38FBD;//㏽
	constexpr uint32_t CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_THIRTY_ONE	= 0xE38FBE;//㏾
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_GAL											= 0xE38FBF;//㏿

	/*//TODO:やれ
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C90;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C91;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C92;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C93;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C94;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C95;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C96;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C97;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C98;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C99;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9A;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9B;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9C;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9D;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9E;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9F;//㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C90;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C91;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C92;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C93;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C94;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C95;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C96;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C97;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C98;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C99;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9A;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9B;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9C;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9D;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9E;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9F;//㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C90;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C91;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C92;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C93;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C94;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C95;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C96;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C97;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C98;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C99;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9A;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9B;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9C;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9D;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9E;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9F;//㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C90;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C91;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C92;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C93;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C94;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C95;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C96;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C97;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C98;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C99;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9A;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9B;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9C;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9D;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9E;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9F;//㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
	//*/



	/*
	㌀	㌁	㌂	㌃	㌄	㌅	㌆	㌇	㌈	㌉	㌊	㌋	㌌	㌍	㌎	㌏
	㌐	㌑	㌒	㌓	㌔	㌕	㌖	㌗	㌘	㌙	㌚	㌛	㌜	㌝	㌞	㌟
	㌠	㌡	㌢	㌣	㌤	㌥	㌦	㌧	㌨	㌩	㌪	㌫	㌬	㌭	㌮	㌯
	㌰	㌱	㌲	㌳	㌴	㌵	㌶	㌷	㌸	㌹	㌺	㌻	㌼	㌽	㌾	㌿
	㍀	㍁	㍂	㍃	㍄	㍅	㍆	㍇	㍈	㍉	㍊	㍋	㍌	㍍	㍎	㍏
	㍐	㍑	㍒	㍓	㍔	㍕	㍖	㍗	㍘	㍙	㍚	㍛	㍜	㍝	㍞	㍟
	㍠	㍡	㍢	㍣	㍤	㍥	㍦	㍧	㍨	㍩	㍪	㍫	㍬	㍭	㍮	㍯
	㍰	㍱	㍲	㍳	㍴	㍵	㍶	㍷	㍸	㍹	㍺	㍻	㍼	㍽	㍾	㍿
	㎀	㎁	㎂	㎃	㎄	㎅	㎆	㎇	㎈	㎉	㎊	㎋	㎌	㎍	㎎	㎏
	㎐	㎑	㎒	㎓	㎔	㎕	㎖	㎗	㎘	㎙	㎚	㎛	㎜	㎝	㎞	㎟
	㎠	㎡	㎢	㎣	㎤	㎥	㎦	㎧	㎨	㎩	㎪	㎫	㎬	㎭	㎮	㎯
	㎰	㎱	㎲	㎳	㎴	㎵	㎶	㎷	㎸	㎹	㎺	㎻	㎼	㎽	㎾	㎿
	㏀	㏁	㏂	㏃	㏄	㏅	㏆	㏇	㏈	㏉	㏊	㏋	㏌	㏍	㏎	㏏
	㏐	㏑	㏒	㏓	㏔	㏕	㏖	㏗	㏘	㏙	㏚	㏛	㏜	㏝	㏞	㏟
	㏠	㏡	㏢	㏣	㏤	㏥	㏦	㏧	㏨	㏩	㏪	㏫	㏬	㏭	㏮	㏯
	㏰	㏱	㏲	㏳	㏴	㏵	㏶	㏷	㏸	㏹	㏺	㏻	㏼	㏽	㏾	㏿

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C90;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C91;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C92;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C93;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C94;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C95;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C96;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C97;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C98;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C99;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C9A;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C9B;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C9C;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C9D;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C9E;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_	= 0xE38C9F;//

U+322x	㈠	㈡	㈢	㈣	㈤	㈥	㈦	㈧	㈨	㈩	㈪	㈫	㈬	㈭	㈮	㈯
U+323x	㈰	㈱	㈲	㈳	㈴	㈵	㈶	㈷	㈸	㈹	㈺	㈻	㈼	㈽	㈾	㈿
U+324x	㉀	㉁	㉂	㉃	㉄	㉅	㉆	㉇	㉈	㉉	㉊	㉋	㉌	㉍	㉎	㉏
U+325x	㉐	㉑	㉒	㉓	㉔	㉕	㉖	㉗	㉘	㉙	㉚	㉛	㉜	㉝	㉞	㉟
U+328x	㊀	㊁	㊂	㊃	㊄	㊅	㊆	㊇	㊈	㊉	㊊	㊋	㊌	㊍	㊎	㊏
U+329x	㊐	㊑	㊒	㊓	㊔	㊕	㊖	㊗	㊘	㊙	㊚	㊛	㊜	㊝	㊞	㊟
U+32Ax	㊠	㊡	㊢	㊣	㊤	㊥	㊦	㊧	㊨	㊩	㊪	㊫	㊬	㊭	㊮	㊯
U+32Bx	㊰	㊱	㊲	㊳	㊴	㊵	㊶	㊷	㊸	㊹	㊺	㊻	㊼	㊽	㊾	㊿
U+32Cx	㋀	㋁	㋂	㋃	㋄	㋅	㋆	㋇	㋈	㋉	㋊	㋋	㋌	㋍	㋎	㋏
U+32Dx	㋐	㋑	㋒	㋓	㋔	㋕	㋖	㋗	㋘	㋙	㋚	㋛	㋜	㋝	㋞	㋟
U+32Ex	㋠	㋡	㋢	㋣	㋤	㋥	㋦	㋧	㋨	㋩	㋪	㋫	㋬	㋭	㋮	㋯
U+32Fx	㋰	㋱	㋲	㋳	㋴	㋵	㋶	㋷	㋸	㋹	㋺	㋻	㋼	㋽	㋾	㋿

U+246x	①	②	③	④	⑤	⑥	⑦	⑧	⑨	⑩	⑪	⑫	⑬	⑭	⑮	⑯
U+247x	⑰	⑱	⑲	⑳	⑴	⑵	⑶	⑷	⑸	⑹	⑺	⑻	⑼	⑽	⑾	⑿
U+248x	⒀	⒁	⒂	⒃	⒄	⒅	⒆	⒇	⒈	⒉	⒊	⒋	⒌	⒍	⒎	⒏
U+249x	⒐	⒑	⒒	⒓	⒔	⒕	⒖	⒗	⒘	⒙	⒚	⒛	⒜	⒝	⒞	⒟
U+24Ax	⒠	⒡	⒢	⒣	⒤	⒥	⒦	⒧	⒨	⒩	⒪	⒫	⒬	⒭	⒮	⒯
U+24Bx	⒰	⒱	⒲	⒳	⒴	⒵	Ⓐ	Ⓑ	Ⓒ	Ⓓ	Ⓔ	Ⓕ	Ⓖ	Ⓗ	Ⓘ	Ⓙ
U+24Cx	Ⓚ	Ⓛ	Ⓜ	Ⓝ	Ⓞ	Ⓟ	Ⓠ	Ⓡ	Ⓢ	Ⓣ	Ⓤ	Ⓥ	Ⓦ	Ⓧ	Ⓨ	Ⓩ
U+24Dx	ⓐ	ⓑ	ⓒ	ⓓ	ⓔ	ⓕ	ⓖ	ⓗ	ⓘ	ⓙ	ⓚ	ⓛ	ⓜ	ⓝ	ⓞ	ⓟ
U+24Ex	ⓠ	ⓡ	ⓢ	ⓣ	ⓤ	ⓥ	ⓦ	ⓧ	ⓨ	ⓩ

	//*/

	/* FUNCTION */
	std::string hiraganaToRomaji(const std::string& str);
	std::string getCharCodeToRomaji(const uint32_t code);
	std::string getDigitCodeToRomaji(const char code);

	/* 数字 */
	std::string number_to_Nesora(const std::string& str);
	/* 整数 */
	std::string integer_to_Nesora(const std::string& str);
	/* 小数 */
	std::string decimal_to_Nesora(const std::string& str);
	/* 指数 */
	std::string power_to_Nesora(const std::string& str);
	/* 分数 */
	std::string fraction_to_Nesora(const std::string& str);

}; // namespace Normalization_to_Nesora

#endif