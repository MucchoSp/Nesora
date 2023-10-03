// 音諳零号機.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
// 
// 音諳零号機弐型(CUI)のユーザーインターフェース関係のメインプログラムです。
// コマンドなどの変更は、このファイル内の'mainLoop'関数で行ってください。
// 
// Copyright (c) 2021 - 2022  MucchoSP

#include "Nesora.h"

makeVoiseFromFile MVFF;

//ファイルチェッカー
bool checkFileExistence(const std::string& str)
{
    std::ifstream ifs(str);
    return ifs.is_open();
}

//ファイル読み込み
int fileload() {

    char filename[256] = { 0 };
    (void)scanf("%s", filename);
    if (checkFileExistence(filename)) {
        printf("\n音声ファイル %s を読み込んでいます...\n", filename);
        if (MVFF.loadVoise(filename))
            printf("\n音声ファイル %s を読み込めませんでした。\n", filename);
        else
            printf("\n音声ファイル %s を読み込みました！\n", filename);
    }
    else
        printf("音声ファイル %s がありません。\n", filename);

    return 0;
}

//テキスト読み上げ
int speak() {

    char* texts = new char[MAXTEXTS];
    (void)scanf("%s", texts);

    MVFF.textread(texts);
    MVFF.textreading("音諳speak");

    return 0;
}

//テキスト読み上げ&ファイル保存
int talk() {

    char* texts = new char[MAXTEXTS];
    (void)scanf("%s", texts);

    char* filename = new char[MAXTEXTS];
    (void)scanf("%s", filename);

    MVFF.textread(texts);
    MVFF.textreading(filename);

    return 0;
}

//デバッグ表示変更
int debug() {

    char ch = 't';
    (void)scanf("%c", &ch);
    (void)scanf("%c", &ch);

    if (ch == 't') {
        MVFF.debugtf(true);
        printf("デバッグ表示\n");
    }
    else if (ch == 'f') {
        MVFF.debugtf(false);
        printf("デバッグ非表示\n");
    }
    else
        printf("デバッグを表示する場合は't'を、非表示にする場合は'f'を入力してください。( %c , %d )\n", ch, ch);

    return 0;
}

//音諳零号機零番メインループ
int mainLoop() {

    char option[256] = { 0 };
    while (1) {
        printf("何をしますか?: ");
        (void)scanf("%s", option);
        printf("\n");

        //終了
        if (strstr(option, "fin")) {
            break;
        }
        //ヘルプ
        else if (strstr(option, "help") || strstr(option, "HELP") || strstr(option, "Help") || strstr(option, "hElp") || strstr(option, "heLp") || strstr(option, "helP") || strstr(option, "HElp") || strstr(option, "hELp") || strstr(option, "heLP") || strstr(option, "HeLp") || strstr(option, "hElP") || strstr(option, "HelP") || strstr(option, "HELp") || strstr(option, "HElP") || strstr(option, "HeLP") || strstr(option, "hELP")) {
            if (!strstr(option, "help"))printf("※コマンドはすべて半角の小文字で入力してください。\n");
            printf("debug ['t','f']     デバッグ表示変更\n");
            printf("fin                 終了\n");
            printf("loadv [file]        声(.nsvo)を読み込む\n");
            printf("speak [text]        テキストを読み上げ\n");
            printf("talk [text] [file]  テキストを読み上げ&ファイル保存\n");
        }
        else if (strstr(option, "loadv")) {
            fileload();
        }
        else if (strstr(option, "speak")) {
            speak();
        }
        else if (strstr(option, "talk")) {
            talk();
        }
        else if (strstr(option, "debug")) {
            debug();
        }
        else if (option[0] == '/') {
            unprocessed;
        }
        else
            printf("%s というコマンドはありません。\nコマンドが分からない時は help を参照してください。\n", option);

        //ループ終端
        printf("\n");
    }

    return 0;
}

//main関数
int main()
{
    //speak ｱｲｳｴｵ

    //デバッグするかどうか
    bool debugmode = false;
    if (debugmode) {
        MVFF.debugtf(false);

        double bf = 440;
        /*double formant[5][4] = { { bf * 2.50000,bf * 3.86363,bf * 9.09090,bf * 10.68181 },
                                { bf * 1.45454,bf * 8.29545,bf * 9.09090,bf * 10.68181 },
                                { bf * 1.36363,bf * 3.86363,bf * 9.09090,bf * 10.68181 },
                                { bf * 1.77272,bf * 6.59090,bf * 9.09090,bf * 10.68181 },
                                { bf * 1.81818,bf * 3.40909,bf * 9.09090,bf * 10.68181 } };*/
                                /*double formant[5][4] = { { bf * 2.5,bf * 3.9,bf * 9.1,bf * 10.7 },
                                                        { bf * 1.5,bf * 8.3,bf * 9.1,bf * 10.7 },
                                                        { bf * 1.4,bf * 3.9,bf * 9.1,bf * 10.7 },
                                                        { bf * 1.8,bf * 6.6,bf * 9.1,bf * 10.7 },
                                                        { bf * 1.8,bf * 3.4,bf * 9.1,bf * 10.7 } };*/
        double formant[5][4] = { { bf * 2.5  ,bf * 4.0   ,bf * 9 ,bf * 11 },
                                    { bf * 1.5  ,bf * 8.5   ,bf * 9 ,bf * 11 },
                                    { bf * 1.5  ,bf * 4.0   ,bf * 9 ,bf * 11 },
                                    { bf * 2.0  ,bf * 7.5   ,bf * 9 ,bf * 11 },
                                    { bf * 2.0  ,bf * 3.5   ,bf * 9 ,bf * 11 } };

        char formantc[5][8] = { 0 };
        for (int i = 0;i < 5;i++)
            for (int j = 0; j < 4; j++) {
                formantc[i][j * 2] = (char)((short)formant[i][j] >> 0 & 0xff);
                formantc[i][j * 2 + 1] = (char)((short)formant[i][j] >> 8 & 0xff);
            }

        const size_t filesize = 4096 + 2;char otherdata[filesize] = { 0 };
        {
            //allmojiFormant初期化
            double**** allmojiFormant = new double*** [2];																	//文字のフォルマントの保管庫
            for (int i = 0;i < 2;i++) {
                allmojiFormant[i] = new double** [16];
                for (int j = 0;j < 16;j++) {
                    allmojiFormant[i][j] = new double* [16];
                    for (int k = 0;k < 16;k++) {
                        allmojiFormant[i][j][k] = new double[4];
                        for (int l = 0;l < 4;l++)allmojiFormant[i][j][k][l] = 0;
                    }
                }
            }

            if (false) {

                //NULL
                for (int i = 0; i < 4; i++) {
                    allmojiFormant[0][0][0][i] = 0;
                    allmojiFormant[1][0][0][i] = 0;
                }

                //母音フォルマント
                for (int i = 0; i < 2;i++) {
                    //あ
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[i][0][1][k] = formant[0][k];
                    //い
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[i][0][2][k] = formant[1][k];
                    //う
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[i][0][7][k] = formant[2][k];
                    //え
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[i][0][12][k] = formant[3][k];
                    //お
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[i][0][13][k] = formant[4][k];
                }

                //半母音
                if (true) {
                    //や
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][3][k] = formant[1][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][3][k] = formant[0][k];
                    //ゆ
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][4][k] = formant[1][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][4][k] = formant[2][k];
                    //江
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][5][k] = formant[1][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][5][k] = formant[3][k];
                    //よ
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][6][k] = formant[1][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][6][k] = formant[4][k];

                    //わ
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][8][k] = formant[2][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][8][k] = formant[0][k];
                    //ゐ
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][9][k] = formant[2][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][9][k] = formant[1][k];
                    //ゑ
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][10][k] = formant[2][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][10][k] = formant[3][k];
                    //を
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][11][k] = formant[2][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][11][k] = formant[4][k];
                }

                //軟口蓋破裂音(か～ご)(1x,2x)
                if (true) {
                    //無声軟口蓋破裂音(か)
                    allmojiFormant[0][1][1][0] = formant[0][0];
                    allmojiFormant[0][1][1][1] = formant[0][1];
                    allmojiFormant[0][1][1][2] = formant[0][2] / 2.0;
                    allmojiFormant[0][1][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][1][1][k] = allmojiFormant[1][0][1][k];
                    //無声軟口蓋破裂音(硬口より)(き)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][1][i][0] = formant[1][0];
                        allmojiFormant[0][1][i][1] = formant[1][1];
                        allmojiFormant[0][1][i][2] = formant[1][2] / 2.0;
                        allmojiFormant[0][1][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][1][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声軟口蓋破裂音(く)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][1][i][0] = formant[2][0];
                        allmojiFormant[0][1][i][1] = formant[2][1];
                        allmojiFormant[0][1][i][2] = formant[2][2] / 2.0;
                        allmojiFormant[0][1][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][1][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声軟口蓋破裂音(け)
                    allmojiFormant[0][1][12][0] = formant[3][0];
                    allmojiFormant[0][1][12][1] = formant[3][1];
                    allmojiFormant[0][1][12][2] = formant[3][2] / 2.0;
                    allmojiFormant[0][1][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][1][12][k] = allmojiFormant[1][0][12][k];
                    //無声軟口蓋破裂音(こ)
                    allmojiFormant[0][1][13][0] = formant[4][0];
                    allmojiFormant[0][1][13][1] = formant[4][1];
                    allmojiFormant[0][1][13][2] = formant[4][2] / 2.0;
                    allmojiFormant[0][1][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][1][13][k] = allmojiFormant[1][0][13][k];


                    //有声軟口蓋破裂音(が)
                    allmojiFormant[0][2][1][0] = formant[0][0];
                    allmojiFormant[0][2][1][1] = formant[0][1];
                    allmojiFormant[0][2][1][2] = formant[0][2] / 2.0;
                    allmojiFormant[0][2][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][2][1][k] = allmojiFormant[1][0][1][k];
                    //有声軟口蓋破裂音(硬口より)(ぎ)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][2][i][0] = formant[1][0];
                        allmojiFormant[0][2][i][1] = formant[1][1];
                        allmojiFormant[0][2][i][2] = formant[1][2] / 2.0;
                        allmojiFormant[0][2][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][2][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声軟口蓋破裂音(ぐ)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][2][i][0] = formant[2][0];
                        allmojiFormant[0][2][i][1] = formant[2][1];
                        allmojiFormant[0][2][i][2] = formant[2][2] / 2.0;
                        allmojiFormant[0][2][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][2][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声軟口蓋破裂音(げ)
                    allmojiFormant[0][2][12][0] = formant[3][0];
                    allmojiFormant[0][2][12][1] = formant[3][1];
                    allmojiFormant[0][2][12][2] = formant[3][2] / 2.0;
                    allmojiFormant[0][2][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][2][12][k] = allmojiFormant[1][0][12][k];
                    //有声軟口蓋破裂音(ご)
                    allmojiFormant[0][2][13][0] = formant[4][0];
                    allmojiFormant[0][2][13][1] = formant[4][1];
                    allmojiFormant[0][2][13][2] = formant[4][2] / 2.0;
                    allmojiFormant[0][2][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][2][13][k] = allmojiFormant[1][0][13][k];
                }

                //歯茎摩擦音(さ～ぞ)(3x,4x)
                if (true) {
                    //無声歯茎摩擦音(さ)
                    allmojiFormant[0][3][1][0] = formant[0][0] / 1.5;
                    allmojiFormant[0][3][1][1] = formant[0][1] / 2.3;
                    allmojiFormant[0][3][1][2] = formant[0][2];
                    allmojiFormant[0][3][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][3][1][k] = allmojiFormant[1][0][1][k];
                    //無声歯茎硬口蓋摩擦音(し)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][3][i][0] = formant[1][0] / 1.5;
                        allmojiFormant[0][3][i][1] = formant[1][1] / 2.3;
                        allmojiFormant[0][3][i][2] = formant[1][2];
                        allmojiFormant[0][3][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][3][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声歯茎摩擦音(す)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][3][i][0] = formant[2][0] / 1.5;
                        allmojiFormant[0][3][i][1] = formant[2][1] / 2.3;
                        allmojiFormant[0][3][i][2] = formant[2][2];
                        allmojiFormant[0][3][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][3][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声歯茎摩擦音(せ)
                    allmojiFormant[0][3][12][0] = formant[3][0] / 1.5;
                    allmojiFormant[0][3][12][1] = formant[3][1] / 2.3;
                    allmojiFormant[0][3][12][2] = formant[3][2];
                    allmojiFormant[0][3][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][3][12][k] = allmojiFormant[1][0][12][k];
                    //無声歯茎摩擦音(そ)
                    allmojiFormant[0][3][13][0] = formant[4][0] / 1.5;
                    allmojiFormant[0][3][13][1] = formant[4][1] / 2.3;
                    allmojiFormant[0][3][13][2] = formant[4][2];
                    allmojiFormant[0][3][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][3][13][k] = allmojiFormant[1][0][13][k];


                    //有声歯茎摩擦音(ざ)
                    allmojiFormant[0][4][1][0] = formant[0][0] / 1.5;
                    allmojiFormant[0][4][1][1] = formant[0][1] / 2.3;
                    allmojiFormant[0][4][1][2] = formant[0][2];
                    allmojiFormant[0][4][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][4][1][k] = allmojiFormant[1][0][1][k];
                    //有声歯茎硬口蓋摩擦音(じ)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][4][i][0] = formant[1][0] / 1.5;
                        allmojiFormant[0][4][i][1] = formant[1][1] / 2.3;
                        allmojiFormant[0][4][i][2] = formant[1][2];
                        allmojiFormant[0][4][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][4][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声歯茎摩擦音(ず)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][4][i][0] = formant[2][0] / 1.5;
                        allmojiFormant[0][4][i][1] = formant[2][1] / 2.3;
                        allmojiFormant[0][4][i][2] = formant[2][2];
                        allmojiFormant[0][4][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][4][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声歯茎摩擦音(ぜ)
                    allmojiFormant[0][4][12][0] = formant[3][0] / 1.5;
                    allmojiFormant[0][4][12][1] = formant[3][1] / 2.3;
                    allmojiFormant[0][4][12][2] = formant[3][2];
                    allmojiFormant[0][4][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][4][12][k] = allmojiFormant[1][0][12][k];
                    //有声歯茎摩擦音(ぞ)
                    allmojiFormant[0][4][13][0] = formant[4][0] / 1.5;
                    allmojiFormant[0][4][13][1] = formant[4][1] / 2.3;
                    allmojiFormant[0][4][13][2] = formant[4][2];
                    allmojiFormant[0][4][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][4][13][k] = allmojiFormant[1][0][13][k];
                }

                //歯茎破裂音(た～ど)(5x,6x)
                if (true) {
                    //無声歯茎破裂音(た)
                    allmojiFormant[0][5][1][0] = formant[0][0] / 1.5;
                    allmojiFormant[0][5][1][1] = formant[0][1] / 2.3;
                    allmojiFormant[0][5][1][2] = formant[0][2];
                    allmojiFormant[0][5][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][5][1][k] = allmojiFormant[1][0][1][k];
                    //無声歯茎硬口蓋破擦音(ち)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][5][i][0] = formant[1][0] / 1.5;
                        allmojiFormant[0][5][i][1] = formant[1][1] / 2.3;
                        allmojiFormant[0][5][i][2] = formant[1][2];
                        allmojiFormant[0][5][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][5][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声歯茎破擦音(つ)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][5][i][0] = formant[2][0] / 1.5;
                        allmojiFormant[0][5][i][1] = formant[2][1] / 2.3;
                        allmojiFormant[0][5][i][2] = formant[2][2];
                        allmojiFormant[0][5][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][5][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声歯茎破裂音(て)
                    allmojiFormant[0][5][12][0] = formant[3][0] / 1.5;
                    allmojiFormant[0][5][12][1] = formant[3][1] / 2.3;
                    allmojiFormant[0][5][12][2] = formant[3][2];
                    allmojiFormant[0][5][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][5][12][k] = allmojiFormant[1][0][12][k];
                    //無声歯茎破裂音(と)
                    allmojiFormant[0][5][13][0] = formant[4][0] / 1.5;
                    allmojiFormant[0][5][13][1] = formant[4][1] / 2.3;
                    allmojiFormant[0][5][13][2] = formant[4][2];
                    allmojiFormant[0][5][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][5][13][k] = allmojiFormant[1][0][13][k];


                    //有声歯茎破裂音(だ)
                    allmojiFormant[0][6][1][0] = formant[0][0] / 1.5;
                    allmojiFormant[0][6][1][1] = formant[0][1] / 2.3;
                    allmojiFormant[0][6][1][2] = formant[0][2];
                    allmojiFormant[0][6][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][6][1][k] = allmojiFormant[1][0][1][k];
                    //有声歯茎硬口蓋破擦音(ぢ)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][6][i][0] = formant[1][0] / 1.5;
                        allmojiFormant[0][6][i][1] = formant[1][1] / 2.3;
                        allmojiFormant[0][6][i][2] = formant[1][2];
                        allmojiFormant[0][6][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][6][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声歯茎破擦音(づ)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][6][i][0] = formant[2][0] / 1.5;
                        allmojiFormant[0][6][i][1] = formant[2][1] / 2.3;
                        allmojiFormant[0][6][i][2] = formant[2][2];
                        allmojiFormant[0][6][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][6][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声歯茎破裂音(で)
                    allmojiFormant[0][6][12][0] = formant[3][0] / 1.5;
                    allmojiFormant[0][6][12][1] = formant[3][1] / 2.3;
                    allmojiFormant[0][6][12][2] = formant[3][2];
                    allmojiFormant[0][6][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][6][12][k] = allmojiFormant[1][0][12][k];
                    //有声歯茎破裂音(ど)
                    allmojiFormant[0][6][13][0] = formant[4][0] / 1.5;
                    allmojiFormant[0][6][13][1] = formant[4][1] / 2.3;
                    allmojiFormant[0][6][13][2] = formant[4][2];
                    allmojiFormant[0][6][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][6][13][k] = allmojiFormant[1][0][13][k];
                }

                //両唇破裂音(ぱ～ぼ)(7x,8x)
                if (true) {
                    //無声両唇破裂音(ぱ)
                    allmojiFormant[0][7][1][0] = formant[0][0];
                    allmojiFormant[0][7][1][1] = formant[0][1] / 2.0;
                    allmojiFormant[0][7][1][2] = formant[0][2];
                    allmojiFormant[0][7][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][7][1][k] = allmojiFormant[1][0][1][k];
                    //有声両唇硬口蓋接近音(ぴ)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][7][i][0] = formant[1][0];
                        allmojiFormant[0][7][i][1] = formant[1][1] / 2.0;
                        allmojiFormant[0][7][i][2] = formant[1][2];
                        allmojiFormant[0][7][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][7][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声両唇破裂音(ぷ)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][7][i][0] = formant[2][0];
                        allmojiFormant[0][7][i][1] = formant[2][1] / 2.0;
                        allmojiFormant[0][7][i][2] = formant[2][2];
                        allmojiFormant[0][7][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][7][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声両唇破裂音(ぺ)
                    allmojiFormant[0][7][12][0] = formant[3][0];
                    allmojiFormant[0][7][12][1] = formant[3][1] / 2.0;
                    allmojiFormant[0][7][12][2] = formant[3][2];
                    allmojiFormant[0][7][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][7][12][k] = allmojiFormant[1][0][12][k];
                    //無声両唇破裂音(ぽ)
                    allmojiFormant[0][7][13][0] = formant[4][0];
                    allmojiFormant[0][7][13][1] = formant[4][1] / 2.0;
                    allmojiFormant[0][7][13][2] = formant[4][2];
                    allmojiFormant[0][7][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][7][13][k] = allmojiFormant[1][0][13][k];


                    //有声両唇破裂音(ば)
                    allmojiFormant[0][8][1][0] = formant[0][0];
                    allmojiFormant[0][8][1][1] = formant[0][1] / 2.0;
                    allmojiFormant[0][8][1][2] = formant[0][2];
                    allmojiFormant[0][8][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][8][1][k] = allmojiFormant[1][0][1][k];
                    //有声両唇硬口蓋破裂音(び)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][8][i][0] = formant[1][0];
                        allmojiFormant[0][8][i][1] = formant[1][1] / 2.0;
                        allmojiFormant[0][8][i][2] = formant[1][2];
                        allmojiFormant[0][8][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][8][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声両唇破裂音(ぶ)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][8][i][0] = formant[2][0];
                        allmojiFormant[0][8][i][1] = formant[2][1] / 2.0;
                        allmojiFormant[0][8][i][2] = formant[2][2];
                        allmojiFormant[0][8][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][8][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声両唇破裂音(べ)
                    allmojiFormant[0][8][12][0] = formant[3][0];
                    allmojiFormant[0][8][12][1] = formant[3][1] / 2.0;
                    allmojiFormant[0][8][12][2] = formant[3][2];
                    allmojiFormant[0][8][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][8][12][k] = allmojiFormant[1][0][12][k];
                    //有声両唇破裂音(ぼ)
                    allmojiFormant[0][8][13][0] = formant[4][0];
                    allmojiFormant[0][8][13][1] = formant[4][1] / 2.0;
                    allmojiFormant[0][8][13][2] = formant[4][2];
                    allmojiFormant[0][8][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][8][13][k] = allmojiFormant[1][0][13][k];
                }

                //摩殺音(笑)(は～ほ)(9x)
                if (true) {
                    //無声声門摩擦音(は)
                    //無声硬口蓋摩擦音(ひ)
                    //無声両唇摩擦音(ふ)
                    //無声声門摩擦音(へ)
                    //無声声門摩擦音(ほ)
                    for (int i = 0;i < 15;i++)
                        for (int j = 0; j < 2;j++)
                            for (int k = 0; k < 4;k++)
                                allmojiFormant[j][9][i][k] = allmojiFormant[j][0][i][k];
                }

                //歯茎鼻音(な～の)(ax)
                if (true) {
                    //歯茎鼻音(な)
                    allmojiFormant[0][10][1][0] = formant[0][0] / 2.0;
                    allmojiFormant[0][10][1][1] = formant[0][1] / 3.0;
                    allmojiFormant[0][10][1][2] = formant[0][2];
                    allmojiFormant[0][10][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][10][1][k] = allmojiFormant[1][0][1][k];
                    //硬口蓋鼻音(に)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][10][i][0] = formant[1][0] / 2.0;
                        allmojiFormant[0][10][i][1] = formant[1][1] / 3.0;
                        allmojiFormant[0][10][i][2] = formant[1][2];
                        allmojiFormant[0][10][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][10][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //歯茎鼻音(ぬ)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][10][i][0] = formant[2][0] / 2.0;
                        allmojiFormant[0][10][i][1] = formant[2][1] / 3.0;
                        allmojiFormant[0][10][i][2] = formant[2][2];
                        allmojiFormant[0][10][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][10][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //歯茎鼻音(ね)
                    allmojiFormant[0][10][12][0] = formant[3][0] / 2.0;
                    allmojiFormant[0][10][12][1] = formant[3][1] / 3.0;
                    allmojiFormant[0][10][12][2] = formant[3][2];
                    allmojiFormant[0][10][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][10][12][k] = allmojiFormant[1][0][12][k];
                    //歯茎鼻音(の)
                    allmojiFormant[0][10][13][0] = formant[4][0] / 2.0;
                    allmojiFormant[0][10][13][1] = formant[4][1] / 3.0;
                    allmojiFormant[0][10][13][2] = formant[4][2];
                    allmojiFormant[0][10][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][10][13][k] = allmojiFormant[1][0][13][k];
                }

                //両唇鼻音(ま～も)(bx)
                if (true) {
                    //両唇鼻音(ま)
                    allmojiFormant[0][11][1][0] = formant[0][0] / 3.0;
                    allmojiFormant[0][11][1][1] = formant[0][1] / 2.0;
                    allmojiFormant[0][11][1][2] = formant[0][2];
                    allmojiFormant[0][11][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][11][1][k] = allmojiFormant[1][0][1][k];
                    //両唇鼻音(み)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][11][i][0] = formant[1][0] / 3.0;
                        allmojiFormant[0][11][i][1] = formant[1][1] / 2.0;
                        allmojiFormant[0][11][i][2] = formant[1][2];
                        allmojiFormant[0][11][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][11][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //両唇鼻音(む)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][11][i][0] = formant[2][0] / 3.0;
                        allmojiFormant[0][11][i][1] = formant[2][1] / 2.0;
                        allmojiFormant[0][11][i][2] = formant[2][2];
                        allmojiFormant[0][11][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][11][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //両唇鼻音(め)
                    allmojiFormant[0][11][12][0] = formant[3][0] / 3.0;
                    allmojiFormant[0][11][12][1] = formant[3][1] / 2.0;
                    allmojiFormant[0][11][12][2] = formant[3][2];
                    allmojiFormant[0][11][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][11][12][k] = allmojiFormant[1][0][12][k];
                    //両唇鼻音(も)
                    allmojiFormant[0][11][13][0] = formant[4][0] / 3.0;
                    allmojiFormant[0][11][13][1] = formant[4][1] / 2.0;
                    allmojiFormant[0][11][13][2] = formant[4][2];
                    allmojiFormant[0][11][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][11][13][k] = allmojiFormant[1][0][13][k];
                }

                //有声歯茎はじき音(ら～ろ)(cx)
                if (true) {
                    //有声歯茎はじき音(ら)
                    allmojiFormant[0][12][1][0] = formant[0][0] / 1.5;
                    allmojiFormant[0][12][1][1] = formant[0][1] / 2.3;
                    allmojiFormant[0][12][1][2] = formant[0][2];
                    allmojiFormant[0][12][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][12][1][k] = allmojiFormant[1][0][1][k];
                    //歯茎硬口蓋はじき音(り)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][12][i][0] = formant[1][0] / 1.5;
                        allmojiFormant[0][12][i][1] = formant[1][1] / 2.3;
                        allmojiFormant[0][12][i][2] = formant[1][2];
                        allmojiFormant[0][12][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][12][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声歯茎はじき音(る)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][12][i][0] = formant[2][0] / 1.5;
                        allmojiFormant[0][12][i][1] = formant[2][1] / 2.3;
                        allmojiFormant[0][12][i][2] = formant[2][2];
                        allmojiFormant[0][12][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][12][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声歯茎はじき音(れ)
                    allmojiFormant[0][12][12][0] = formant[3][0] / 1.5;
                    allmojiFormant[0][12][12][1] = formant[3][1] / 2.3;
                    allmojiFormant[0][12][12][2] = formant[3][2];
                    allmojiFormant[0][12][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][12][12][k] = allmojiFormant[1][0][12][k];
                    //有声歯茎はじき音(ろ)
                    allmojiFormant[0][12][13][0] = formant[4][0] / 1.5;
                    allmojiFormant[0][12][13][1] = formant[4][1] / 2.3;
                    allmojiFormant[0][12][13][2] = formant[4][2];
                    allmojiFormant[0][12][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][12][13][k] = allmojiFormant[1][0][13][k];
                }

                //ん
                if (true) {
                    //口蓋垂鼻音(ん)
                    allmojiFormant[0][13][1][0] = allmojiFormant[1][13][1][0] = formant[2][0] / 2.0;
                    allmojiFormant[0][13][1][1] = allmojiFormant[1][13][1][1] = formant[2][1] / 3.0;
                    allmojiFormant[0][13][1][2] = allmojiFormant[1][13][1][2] = formant[2][2];
                    allmojiFormant[0][13][1][3] = allmojiFormant[1][13][1][3] = formant[2][3];
                }

            }
            else
            {

                //NULL
                for (int i = 0; i < 4; i++) {
                    allmojiFormant[0][0][0][i] = 0;
                    allmojiFormant[1][0][0][i] = 0;
                }

                //母音フォルマント
                for (int i = 0; i < 2;i++) {
                    //あ
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[i][0][1][k] = formant[0][k];
                    //い
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[i][0][2][k] = formant[1][k];
                    //う
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[i][0][7][k] = formant[2][k];
                    //え
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[i][0][12][k] = formant[3][k];
                    //お
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[i][0][13][k] = formant[4][k];
                }

                //半母音
                if (true) {
                    //や
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][3][k] = formant[1][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][3][k] = formant[0][k];
                    //ゆ
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][4][k] = formant[1][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][4][k] = formant[2][k];
                    //江
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][5][k] = formant[1][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][5][k] = formant[3][k];
                    //よ
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][6][k] = formant[1][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][6][k] = formant[4][k];

                    //わ
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][8][k] = formant[2][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][8][k] = formant[0][k];
                    //ゐ
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][9][k] = formant[2][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][9][k] = formant[1][k];
                    //ゑ
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][10][k] = formant[2][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][10][k] = formant[3][k];
                    //を
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[0][0][11][k] = formant[2][k];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][0][11][k] = formant[4][k];
                }

                //軟口蓋破裂音(か～ご)(1x,2x)
                if (true) {
                    //無声軟口蓋破裂音(か)
                    allmojiFormant[0][1][1][0] = formant[0][1];
                    allmojiFormant[0][1][1][1] = formant[0][1];
                    allmojiFormant[0][1][1][2] = formant[0][1];
                    allmojiFormant[0][1][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][1][1][k] = allmojiFormant[1][0][1][k];
                    //無声軟口蓋破裂音(硬口より)(き)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][1][i][0] = formant[1][1] / 2.5;
                        allmojiFormant[0][1][i][1] = formant[1][1];
                        allmojiFormant[0][1][i][2] = formant[1][1];
                        allmojiFormant[0][1][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][1][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声軟口蓋破裂音(く)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][1][i][0] = formant[2][1];
                        allmojiFormant[0][1][i][1] = formant[2][1];
                        allmojiFormant[0][1][i][2] = formant[2][1];
                        allmojiFormant[0][1][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][1][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声軟口蓋破裂音(け)
                    allmojiFormant[0][1][12][0] = formant[3][1] / 2.5;
                    allmojiFormant[0][1][12][1] = formant[3][1];
                    allmojiFormant[0][1][12][2] = formant[3][1];
                    allmojiFormant[0][1][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][1][12][k] = allmojiFormant[1][0][12][k];
                    //無声軟口蓋破裂音(こ)
                    allmojiFormant[0][1][13][0] = formant[4][1];
                    allmojiFormant[0][1][13][1] = formant[4][1];
                    allmojiFormant[0][1][13][2] = formant[4][1];
                    allmojiFormant[0][1][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][1][13][k] = allmojiFormant[1][0][13][k];


                    //有声軟口蓋破裂音(が)
                    allmojiFormant[0][2][1][0] = formant[0][1];
                    allmojiFormant[0][2][1][1] = formant[0][1];
                    allmojiFormant[0][2][1][2] = formant[0][1];
                    allmojiFormant[0][2][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][2][1][k] = allmojiFormant[1][0][1][k];
                    //有声軟口蓋破裂音(硬口より)(ぎ)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][2][i][0] = formant[1][1] / 2.5;
                        allmojiFormant[0][2][i][1] = formant[1][1];
                        allmojiFormant[0][2][i][2] = formant[1][1];
                        allmojiFormant[0][2][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][2][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声軟口蓋破裂音(ぐ)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][2][i][0] = formant[2][1];
                        allmojiFormant[0][2][i][1] = formant[2][1];
                        allmojiFormant[0][2][i][2] = formant[2][1];
                        allmojiFormant[0][2][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][2][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声軟口蓋破裂音(げ)
                    allmojiFormant[0][2][12][0] = formant[3][1] / 2.5;
                    allmojiFormant[0][2][12][1] = formant[3][1];
                    allmojiFormant[0][2][12][2] = formant[3][1];
                    allmojiFormant[0][2][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][2][12][k] = allmojiFormant[1][0][12][k];
                    //有声軟口蓋破裂音(ご)
                    allmojiFormant[0][2][13][0] = formant[4][1];
                    allmojiFormant[0][2][13][1] = formant[4][1];
                    allmojiFormant[0][2][13][2] = formant[4][1];
                    allmojiFormant[0][2][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][2][13][k] = allmojiFormant[1][0][13][k];
                }

                //歯茎破裂音(た～ど)(3x,4x)
                if (true) {
                    //無声歯茎破裂音(た)
                    allmojiFormant[0][3][1][0] = formant[0][0];
                    allmojiFormant[0][3][1][1] = formant[0][0];
                    allmojiFormant[0][3][1][2] = formant[0][2];
                    allmojiFormant[0][3][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][3][1][k] = allmojiFormant[1][0][1][k];
                    //無声歯茎硬口蓋破擦音(ち)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][3][i][0] = formant[1][0];
                        allmojiFormant[0][3][i][1] = formant[1][0];
                        allmojiFormant[0][3][i][2] = formant[1][2];
                        allmojiFormant[0][3][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][3][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声歯茎破擦音(つ)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][3][i][0] = formant[2][0];
                        allmojiFormant[0][3][i][1] = formant[2][0];
                        allmojiFormant[0][3][i][2] = formant[2][2];
                        allmojiFormant[0][3][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][3][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声歯茎破裂音(て)
                    allmojiFormant[0][3][12][0] = formant[3][0];
                    allmojiFormant[0][3][12][1] = formant[3][0];
                    allmojiFormant[0][3][12][2] = formant[3][2];
                    allmojiFormant[0][3][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][3][12][k] = allmojiFormant[1][0][12][k];
                    //無声歯茎破裂音(と)
                    allmojiFormant[0][3][13][0] = formant[4][0];
                    allmojiFormant[0][3][13][1] = formant[4][0];
                    allmojiFormant[0][3][13][2] = formant[4][2];
                    allmojiFormant[0][3][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][3][13][k] = allmojiFormant[1][0][13][k];


                    //有声歯茎破裂音(だ)
                    allmojiFormant[0][4][1][0] = formant[0][0];
                    allmojiFormant[0][4][1][1] = formant[0][0];
                    allmojiFormant[0][4][1][2] = formant[0][2];
                    allmojiFormant[0][4][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][4][1][k] = allmojiFormant[1][0][1][k];
                    //有声歯茎硬口蓋破擦音(ぢ)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][4][i][0] = formant[1][0];
                        allmojiFormant[0][4][i][1] = formant[1][0];
                        allmojiFormant[0][4][i][2] = formant[1][2];
                        allmojiFormant[0][4][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][4][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声歯茎破擦音(づ)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][4][i][0] = formant[2][0];
                        allmojiFormant[0][4][i][1] = formant[2][0];
                        allmojiFormant[0][4][i][2] = formant[2][2];
                        allmojiFormant[0][4][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][4][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声歯茎破裂音(で)
                    allmojiFormant[0][4][12][0] = formant[3][0];
                    allmojiFormant[0][4][12][1] = formant[3][0];
                    allmojiFormant[0][4][12][2] = formant[3][2];
                    allmojiFormant[0][4][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][4][12][k] = allmojiFormant[1][0][12][k];
                    //有声歯茎破裂音(ど)
                    allmojiFormant[0][4][13][0] = formant[4][0];
                    allmojiFormant[0][4][13][1] = formant[4][0];
                    allmojiFormant[0][4][13][2] = formant[4][2];
                    allmojiFormant[0][4][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][4][13][k] = allmojiFormant[1][0][13][k];
                }

                //両唇破裂音(ぱ～ぼ)(5x,6x)
                if (true) {
                    //無声両唇破裂音(ぱ)
                    allmojiFormant[0][5][1][0] = formant[0][0];
                    allmojiFormant[0][5][1][1] = formant[0][1] / 2.0;
                    allmojiFormant[0][5][1][2] = formant[0][3];
                    allmojiFormant[0][5][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][5][1][k] = allmojiFormant[1][0][1][k];
                    //有声両唇硬口蓋接近音(ぴ)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][5][i][0] = formant[1][0];
                        allmojiFormant[0][5][i][1] = formant[1][1] / 2.0;
                        allmojiFormant[0][5][i][2] = formant[1][3];
                        allmojiFormant[0][5][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][5][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声両唇破裂音(ぷ)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][5][i][0] = formant[2][0];
                        allmojiFormant[0][5][i][1] = formant[2][1] / 2.0;
                        allmojiFormant[0][5][i][2] = formant[2][3];
                        allmojiFormant[0][5][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][5][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声両唇破裂音(ぺ)
                    allmojiFormant[0][5][12][0] = formant[3][0];
                    allmojiFormant[0][5][12][1] = formant[3][1] / 2.0;
                    allmojiFormant[0][5][12][2] = formant[3][3];
                    allmojiFormant[0][5][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][5][12][k] = allmojiFormant[1][0][12][k];
                    //無声両唇破裂音(ぽ)
                    allmojiFormant[0][5][13][0] = formant[4][0];
                    allmojiFormant[0][5][13][1] = formant[4][1] / 2.0;
                    allmojiFormant[0][5][13][2] = formant[4][3];
                    allmojiFormant[0][5][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][5][13][k] = allmojiFormant[1][0][13][k];


                    //有声両唇破裂音(ば)
                    allmojiFormant[0][6][1][0] = formant[0][0];
                    allmojiFormant[0][6][1][1] = formant[0][1] / 2.0;
                    allmojiFormant[0][6][1][2] = formant[0][3];
                    allmojiFormant[0][6][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][6][1][k] = allmojiFormant[1][0][1][k];
                    //有声両唇硬口蓋破裂音(び)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][6][i][0] = formant[1][0];
                        allmojiFormant[0][6][i][1] = formant[1][1] / 2.0;
                        allmojiFormant[0][6][i][2] = formant[1][3];
                        allmojiFormant[0][6][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][6][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声両唇破裂音(ぶ)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][6][i][0] = formant[2][0];
                        allmojiFormant[0][6][i][1] = formant[2][1] / 2.0;
                        allmojiFormant[0][6][i][2] = formant[2][3];
                        allmojiFormant[0][6][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][6][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声両唇破裂音(べ)
                    allmojiFormant[0][6][12][0] = formant[3][0];
                    allmojiFormant[0][6][12][1] = formant[3][1] / 2.0;
                    allmojiFormant[0][6][12][2] = formant[3][3];
                    allmojiFormant[0][6][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][6][12][k] = allmojiFormant[1][0][12][k];
                    //有声両唇破裂音(ぼ)
                    allmojiFormant[0][6][13][0] = formant[4][0];
                    allmojiFormant[0][6][13][1] = formant[4][1] / 2.0;
                    allmojiFormant[0][6][13][2] = formant[4][3];
                    allmojiFormant[0][6][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][6][13][k] = allmojiFormant[1][0][13][k];
                }

                //歯茎摩擦音(さ～ぞ)(7x,8x)
                if (true) {
                    //無声歯茎摩擦音(さ)
                    allmojiFormant[0][7][1][0] = formant[0][1];
                    allmojiFormant[0][7][1][1] = formant[0][1] / 2.0;
                    allmojiFormant[0][7][1][2] = formant[0][2];
                    allmojiFormant[0][7][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][7][1][k] = allmojiFormant[1][0][1][k];
                    //無声歯茎硬口蓋摩擦音(し)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][7][i][0] = formant[1][1];
                        allmojiFormant[0][7][i][1] = formant[1][1] / 2.0;
                        allmojiFormant[0][7][i][2] = formant[1][2];
                        allmojiFormant[0][7][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][7][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声歯茎摩擦音(す)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][7][i][0] = formant[2][1];
                        allmojiFormant[0][7][i][1] = formant[2][1] / 2.0;
                        allmojiFormant[0][7][i][2] = formant[2][2];
                        allmojiFormant[0][7][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][7][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声歯茎摩擦音(せ)
                    allmojiFormant[0][7][12][0] = formant[3][1];
                    allmojiFormant[0][7][12][1] = formant[3][1] / 2.0;
                    allmojiFormant[0][7][12][2] = formant[3][2];
                    allmojiFormant[0][7][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][7][12][k] = allmojiFormant[1][0][12][k];
                    //無声歯茎摩擦音(そ)
                    allmojiFormant[0][7][13][0] = formant[4][1];
                    allmojiFormant[0][7][13][1] = formant[4][1] / 2.0;
                    allmojiFormant[0][7][13][2] = formant[4][2];
                    allmojiFormant[0][7][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][7][13][k] = allmojiFormant[1][0][13][k];


                    //有声歯茎摩擦音(ざ)
                    allmojiFormant[0][8][1][0] = formant[0][0];
                    allmojiFormant[0][8][1][1] = formant[0][0];
                    allmojiFormant[0][8][1][2] = formant[0][2];
                    allmojiFormant[0][8][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][8][1][k] = allmojiFormant[1][0][1][k];
                    //有声歯茎硬口蓋摩擦音(じ)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][8][i][0] = formant[1][0];
                        allmojiFormant[0][8][i][1] = formant[1][0];
                        allmojiFormant[0][8][i][2] = formant[1][2];
                        allmojiFormant[0][8][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][8][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声歯茎摩擦音(ず)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][8][i][0] = formant[2][0];
                        allmojiFormant[0][8][i][1] = formant[2][0];
                        allmojiFormant[0][8][i][2] = formant[2][2];
                        allmojiFormant[0][8][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][8][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声歯茎摩擦音(ぜ)
                    allmojiFormant[0][8][12][0] = formant[3][0];
                    allmojiFormant[0][8][12][1] = formant[3][0];
                    allmojiFormant[0][8][12][2] = formant[3][2];
                    allmojiFormant[0][8][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][8][12][k] = allmojiFormant[1][0][12][k];
                    //有声歯茎摩擦音(ぞ)
                    allmojiFormant[0][8][13][0] = formant[4][0];
                    allmojiFormant[0][8][13][1] = formant[4][0];
                    allmojiFormant[0][8][13][2] = formant[4][2];
                    allmojiFormant[0][8][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][8][13][k] = allmojiFormant[1][0][13][k];
                }

                //摩殺音(笑)(は～ほ)(9x)
                if (true) {
                    //無声声門摩擦音(は)
                    //無声硬口蓋摩擦音(ひ)
                    //無声両唇摩擦音(ふ)
                    //無声声門摩擦音(へ)
                    //無声声門摩擦音(ほ)
                    for (int i = 0;i < 15;i++)
                        for (int j = 0; j < 2;j++)
                            for (int k = 0; k < 4;k++)
                                allmojiFormant[j][9][i][k] = allmojiFormant[j][0][i][k];
                }

                //歯茎鼻音(な～の)(ax)
                if (true) {
                    //歯茎鼻音(な)
                    allmojiFormant[0][10][1][0] = formant[0][0] / 2.0;
                    allmojiFormant[0][10][1][1] = formant[0][1] / 3.0;
                    allmojiFormant[0][10][1][2] = formant[0][2];
                    allmojiFormant[0][10][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][10][1][k] = allmojiFormant[1][0][1][k];
                    //硬口蓋鼻音(に)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][10][i][0] = formant[1][0] / 2.0;
                        allmojiFormant[0][10][i][1] = formant[1][1] / 3.0;
                        allmojiFormant[0][10][i][2] = formant[1][2];
                        allmojiFormant[0][10][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][10][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //歯茎鼻音(ぬ)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][10][i][0] = formant[2][0] / 2.0;
                        allmojiFormant[0][10][i][1] = formant[2][1] / 3.0;
                        allmojiFormant[0][10][i][2] = formant[2][2];
                        allmojiFormant[0][10][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][10][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //歯茎鼻音(ね)
                    allmojiFormant[0][10][12][0] = formant[3][0] / 2.0;
                    allmojiFormant[0][10][12][1] = formant[3][1] / 3.0;
                    allmojiFormant[0][10][12][2] = formant[3][2];
                    allmojiFormant[0][10][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][10][12][k] = allmojiFormant[1][0][12][k];
                    //歯茎鼻音(の)
                    allmojiFormant[0][10][13][0] = formant[4][0] / 2.0;
                    allmojiFormant[0][10][13][1] = formant[4][1] / 3.0;
                    allmojiFormant[0][10][13][2] = formant[4][2];
                    allmojiFormant[0][10][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][10][13][k] = allmojiFormant[1][0][13][k];
                }

                //両唇鼻音(ま～も)(bx)
                if (true) {
                    //両唇鼻音(ま)
                    allmojiFormant[0][11][1][0] = formant[0][0] / 3.0;
                    allmojiFormant[0][11][1][1] = formant[0][1] / 2.0;
                    allmojiFormant[0][11][1][2] = formant[0][2];
                    allmojiFormant[0][11][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][11][1][k] = allmojiFormant[1][0][1][k];
                    //両唇鼻音(み)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][11][i][0] = formant[1][0] / 3.0;
                        allmojiFormant[0][11][i][1] = formant[1][1] / 2.0;
                        allmojiFormant[0][11][i][2] = formant[1][2];
                        allmojiFormant[0][11][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][11][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //両唇鼻音(む)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][11][i][0] = formant[2][0] / 3.0;
                        allmojiFormant[0][11][i][1] = formant[2][1] / 2.0;
                        allmojiFormant[0][11][i][2] = formant[2][2];
                        allmojiFormant[0][11][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][11][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //両唇鼻音(め)
                    allmojiFormant[0][11][12][0] = formant[3][0] / 3.0;
                    allmojiFormant[0][11][12][1] = formant[3][1] / 2.0;
                    allmojiFormant[0][11][12][2] = formant[3][2];
                    allmojiFormant[0][11][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][11][12][k] = allmojiFormant[1][0][12][k];
                    //両唇鼻音(も)
                    allmojiFormant[0][11][13][0] = formant[4][0] / 3.0;
                    allmojiFormant[0][11][13][1] = formant[4][1] / 2.0;
                    allmojiFormant[0][11][13][2] = formant[4][2];
                    allmojiFormant[0][11][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][11][13][k] = allmojiFormant[1][0][13][k];
                }

                //有声歯茎はじき音(ら～ろ)(cx)
                if (true) {
                    //有声歯茎はじき音(ら)
                    allmojiFormant[0][12][1][0] = formant[0][0];
                    allmojiFormant[0][12][1][1] = formant[0][0];
                    allmojiFormant[0][12][1][2] = formant[0][2];
                    allmojiFormant[0][12][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][12][1][k] = allmojiFormant[1][0][1][k];
                    //歯茎硬口蓋はじき音(り)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][12][i][0] = formant[1][0];
                        allmojiFormant[0][12][i][1] = formant[1][0];
                        allmojiFormant[0][12][i][2] = formant[1][2];
                        allmojiFormant[0][12][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][12][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声歯茎はじき音(る)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][12][i][0] = formant[2][0];
                        allmojiFormant[0][12][i][1] = formant[2][0];
                        allmojiFormant[0][12][i][2] = formant[2][2];
                        allmojiFormant[0][12][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][12][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //有声歯茎はじき音(れ)
                    allmojiFormant[0][12][12][0] = formant[3][0];
                    allmojiFormant[0][12][12][1] = formant[3][0];
                    allmojiFormant[0][12][12][2] = formant[3][2];
                    allmojiFormant[0][12][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][12][12][k] = allmojiFormant[1][0][12][k];
                    //有声歯茎はじき音(ろ)
                    allmojiFormant[0][12][13][0] = formant[4][0];
                    allmojiFormant[0][12][13][1] = formant[4][0];
                    allmojiFormant[0][12][13][2] = formant[4][2];
                    allmojiFormant[0][12][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][12][13][k] = allmojiFormant[1][0][13][k];
                }

                //ん
                if (true) {
                    //口蓋垂鼻音(ん)
                    allmojiFormant[0][13][1][0] = allmojiFormant[1][13][1][0] = formant[2][0] / 2.0;
                    allmojiFormant[0][13][1][1] = allmojiFormant[1][13][1][1] = formant[2][1] / 3.0;
                    allmojiFormant[0][13][1][2] = allmojiFormant[1][13][1][2] = formant[2][2];
                    allmojiFormant[0][13][1][3] = allmojiFormant[1][13][1][3] = formant[2][3];
                }


                //テスト用(両唇破裂音(ぱ～ぼ)(5x,6x))(没)
                if (false) {
                    double xt = 1.0;
                    //無声歯茎破裂音(た)
                    allmojiFormant[0][3][1][0] = formant[0][0] / xt;
                    allmojiFormant[0][3][1][1] = formant[0][0] / xt;
                    allmojiFormant[0][3][1][2] = formant[0][2];
                    allmojiFormant[0][3][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][3][1][k] = allmojiFormant[1][0][1][k];
                    //無声歯茎硬口蓋破擦音(ち)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][3][i][0] = formant[1][0] / xt;
                        allmojiFormant[0][3][i][1] = formant[1][0] / xt;
                        allmojiFormant[0][3][i][2] = formant[1][2];
                        allmojiFormant[0][3][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][3][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声歯茎破擦音(つ)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][3][i][0] = formant[2][0] / xt;
                        allmojiFormant[0][3][i][1] = formant[2][0] / xt;
                        allmojiFormant[0][3][i][2] = formant[2][2];
                        allmojiFormant[0][3][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][3][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声歯茎破裂音(て)
                    allmojiFormant[0][3][12][0] = formant[3][0] / xt;
                    allmojiFormant[0][3][12][1] = formant[3][0] / xt;
                    allmojiFormant[0][3][12][2] = formant[3][2];
                    allmojiFormant[0][3][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][3][12][k] = allmojiFormant[1][0][12][k];
                    //無声歯茎破裂音(と)
                    allmojiFormant[0][3][13][0] = formant[4][0] / xt;
                    allmojiFormant[0][3][13][1] = formant[4][0] / xt;
                    allmojiFormant[0][3][13][2] = formant[4][2];
                    allmojiFormant[0][3][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][3][13][k] = allmojiFormant[1][0][13][k];

                    for (int i = 1;i < 14;i++) {
                        printf("\n%d\t", i);
                        for (int j = 0;j < 4;j++)
                            printf("%f\t", allmojiFormant[0][3][i][j]);
                    }

                    double xp = 4.0;
                    //無声両唇破裂音(ぱ)
                    allmojiFormant[0][5][1][0] = formant[0][0];
                    allmojiFormant[0][5][1][1] = formant[0][1] / xp;
                    allmojiFormant[0][5][1][2] = formant[0][2];
                    allmojiFormant[0][5][1][3] = formant[0][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][5][1][k] = allmojiFormant[1][0][1][k];
                    //有声両唇硬口蓋接近音(ぴ)
                    for (int i = 2;i <= 6; i++) {
                        allmojiFormant[0][5][i][0] = formant[1][0];
                        allmojiFormant[0][5][i][1] = formant[1][1] / xp;
                        allmojiFormant[0][5][i][2] = formant[1][2];
                        allmojiFormant[0][5][i][3] = formant[1][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][5][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声両唇破裂音(ぷ)
                    for (int i = 7;i <= 11; i++) {
                        allmojiFormant[0][5][i][0] = formant[2][0];
                        allmojiFormant[0][5][i][1] = formant[2][1] / xp;
                        allmojiFormant[0][5][i][2] = formant[2][2];
                        allmojiFormant[0][5][i][3] = formant[2][3];
                        for (int k = 0; k < 4;k++)
                            allmojiFormant[1][5][i][k] = allmojiFormant[1][0][i][k];
                    }
                    //無声両唇破裂音(ぺ)
                    allmojiFormant[0][5][12][0] = formant[3][0];
                    allmojiFormant[0][5][12][1] = formant[3][1] / xp;
                    allmojiFormant[0][5][12][2] = formant[3][2];
                    allmojiFormant[0][5][12][3] = formant[3][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][5][12][k] = allmojiFormant[1][0][12][k];
                    //無声両唇破裂音(ぽ)
                    allmojiFormant[0][5][13][0] = formant[4][0];
                    allmojiFormant[0][5][13][1] = formant[4][1] / xp;
                    allmojiFormant[0][5][13][2] = formant[4][2];
                    allmojiFormant[0][5][13][3] = formant[4][3];
                    for (int k = 0; k < 4;k++)
                        allmojiFormant[1][5][13][k] = allmojiFormant[1][0][13][k];

                    for (int i = 1;i < 14;i++) {
                        printf("\n%d\t", i);
                        for (int j = 0;j < 4;j++)
                            printf("%f\t", allmojiFormant[0][5][i][j]);
                    }
                }

            }

            for (int i = 0;i < 2;i++) {
                for (int j = 0;j < 16;j++) {
                    for (int k = 0;k < 16;k++) {
                        for (int l = 0;l < 4;l++) {
                            otherdata[(l + k * 4 + j * 4 * 16 + i * 4 * 16 * 16) * 2] = (char)((short)allmojiFormant[i][j][k][l] >> 0 & 0xff);
                            otherdata[(l + k * 4 + j * 4 * 16 + i * 4 * 16 * 16) * 2 + 1] = (char)((short)allmojiFormant[i][j][k][l] >> 8 & 0xff);
                        }
                    }
                }
            }

            //allmojiFormant削除
            for (int i = 0;i < 2;i++) {
                for (int j = 0;j < 16;j++) {
                    for (int k = 0;k < 16;k++)
                        delete[] allmojiFormant[i][j][k];
                    delete[] allmojiFormant[i][j];
                }
                delete[] allmojiFormant[i];
            }
            delete[] allmojiFormant;

            short softness = 0;
            otherdata[4096] = (char)(softness >> 0 & 0xff);
            otherdata[4097] = (char)(softness >> 8 & 0xff);
        }

        //MVFF.saveData("defaultfurin2.nsvo", bf, formantc, 0, { 0 }, 0);
        MVFF.saveData("defaultfurin-Vr2-2.nsvo", bf, { 0 }, filesize, otherdata, 2);
        /*
        MVFF.loadVoise("defaultfurin2.nsvo");
        MVFF.textread("あいうえお");
        MVFF.textreading("hello");
        MVFF.loadVoise("defaultfurin-Vr2-2.nsvo");
        MVFF.textread("あいうえお");
        MVFF.textreading("hello");
        MVFF.loadVoise("defaultfurin2.nsvo");
        MVFF.textread("かきくけこ");
        MVFF.textreading("hello");
        MVFF.loadVoise("defaultfurin-Vr2-2.nsvo");
        MVFF.textread("かきくけこ");
        MVFF.textreading("hello");
        MVFF.loadVoise("defaultfurin2.nsvo");
        MVFF.textread("たちつてと");
        MVFF.textreading("hello");
        MVFF.loadVoise("defaultfurin-Vr2-2.nsvo");
        MVFF.textread("たちつてと");
        MVFF.textreading("hello");
        MVFF.loadVoise("defaultfurin2.nsvo");
        MVFF.textread("ぱぴぷぺぽ");
        MVFF.textreading("hello");
        MVFF.loadVoise("defaultfurin-Vr2-2.nsvo");
        MVFF.textread("ぱぴぷぺぽ");
        MVFF.textreading("hello");//*/
        /*
        MVFF.loadVoise("defaultfurin2.nsvo");
        MVFF.textread("さしすせそ");
        MVFF.textreading("hello");
        MVFF.loadVoise("defaultfurin-Vr2-2.nsvo");
        MVFF.textread("さしすせそ");
        MVFF.textreading("hello");
        MVFF.loadVoise("defaultfurin2.nsvo");
        MVFF.textread("はひふへほ");
        MVFF.textreading("hello");
        MVFF.loadVoise("defaultfurin-Vr2-2.nsvo");
        MVFF.textread("はひふへほ");
        MVFF.textreading("hello");
        MVFF.loadVoise("defaultfurin2.nsvo");
        MVFF.textread("らりるれろ");
        MVFF.textreading("hello");
        MVFF.loadVoise("defaultfurin-Vr2-2.nsvo");
        MVFF.textread("らりるれろ");
        MVFF.textreading("hello");//*/

        {
            const int mojisuu = 10;
            std::srand(time(NULL));
            char* randstr = new char[mojisuu * 2 + 1];
            for (int i = 0;i < mojisuu * 2 + 1;i++)randstr[i] = 0;
            for (int i = 0;i < mojisuu;i++) {
                randstr[i * 2] = 0x82;
                int moji = 0;
                do {
                    moji = rand() % 82 + 0xa0;
                } while (moji == 0xa1 or moji == 0xa3 or moji == 0xa5 or moji == 0xa7 or moji == 0xe1 or moji == 0xe3 or moji == 0xe5 or moji == 0xec);
                randstr[i * 2 + 1] = moji;
            }
            MVFF.loadVoise("defaultfurin-Vr2-2.nsvo");
            MVFF.textread(randstr);
            MVFF.textreading("hello");
            MVFF.textread(randstr);
            MVFF.textreading("hello");
            printf(randstr);
            delete[] randstr;
        }

        /*
        MVFF.textread("こんにちわ");
        MVFF.textreading("hello");
        MVFF.textread("ねそら、");
        MVFF.textreading("hello");//*/
    }
    else {
        //デフォルト音声
        MVFF.debugtf(false);
        MVFF.loadVoise("defaultfurin2.nsvo");
        printf("音諳零号機二型\nCopyright (c) 2021 - 2022 MucchoSP\n\n");

        mainLoop();

        printf("\n\nご利用ありがとうございました。\n");
        printf("\n音諳零号機二型\nCopyright (c) 2021 - 2022 MucchoSP\n\n");
        (void)getchar();
    }
    return 0;
}



/*メモ
* このファイルは音諳零号機のデバッグ用のエントリー・ポイントを含むc++プログラム用のソースファイルです。同ディレクトリにあるNesora.hとNesora.cppを使用します。
* Windowsでの動作を確認しています。
* 
*/