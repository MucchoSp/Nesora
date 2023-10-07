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
	constexpr uint32_t KATA_OFFSET2 = 0x0001E0;//ダ(E38380)～ミ(E3838F)はずれています。(くそが)

	constexpr uint32_t HIRA_KUTEN = 0xE38081;//、
	constexpr uint32_t HIRA_KUTOUTEN = 0xE38082;//。
	constexpr uint32_t HIRA_NOBASHI = 0xE383BC;//ー

	constexpr uint32_t JPMONTH_1 = 0xE38B80;//㋀
	constexpr uint32_t JPMONTH_2 = 0xE38B81;//㋁
	constexpr uint32_t JPMONTH_3 = 0xE38B82;//㋂
	constexpr uint32_t JPMONTH_4 = 0xE38B83;//㋃
	constexpr uint32_t JPMONTH_5 = 0xE38B84;//㋄
	constexpr uint32_t JPMONTH_6 = 0xE38B85;//㋅
	constexpr uint32_t JPMONTH_7 = 0xE38B86;//㋆
	constexpr uint32_t JPMONTH_8 = 0xE38B87;//㋇
	constexpr uint32_t JPMONTH_9 = 0xE38B88;//㋈
	constexpr uint32_t JPMONTH_10 = 0xE38B89;//㋉
	constexpr uint32_t JPMONTH_11 = 0xE38B8A;//㋊
	constexpr uint32_t JPMONTH_12 = 0xE38B8B;//㋋

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
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_EAR_NAME_HEISEI = 0xE38DBB;//㍻
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_EAR_NAME_SYOUWA = 0xE38DBC;//㍼
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_EAR_NAME_TAISYOU = 0xE38DBD;//㍽
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_EAR_NAME_MEIZI = 0xE38DBE;//㍾
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

	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C90;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C91;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C92;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C93;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C94;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C95;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C96;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C97;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C98;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C99;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9A;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9B;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9C;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9D;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9E;//
	constexpr uint32_t CJK_COMPATIBILITY_SQUARE_ = 0xE38C9F;//

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

}; // namespace Normalization_to_Nesora

#endif