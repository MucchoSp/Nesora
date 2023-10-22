
//Copyright (c) 2023 Gabuniku(https://github.com/Gabuniku) & MucchoSP

#include <cstdint>
#include "Normalization_to_Nesora.h"
namespace Normalization_to_Nesora {
    std::string hiraganaToRomaji(const std::string& str) {
        std::string out;
        uint32_t temp_char;
        size_t len = str.length();
        int index = 0;
        int char_count = 0;
        int char_bytes = 0;
        bool in_tag = false;
        while (index < len) {
            temp_char = 0x00;
            char_count = 0;
            char_bytes = 0;

            while (index < len) {
                uint8_t c = str[index++];
                char_count++;
                if (0x00 <= c && c <= 0x7F) {
                    // ASCII (BMP)
                    temp_char = c;
                    char_bytes = 1;
                    break;
                }
                else if (char_count == 1) {
                    switch (c & 0xF0) {
                    case 0xC0:
                    case 0xD0:
                        char_bytes = 2;
                        break;
                    case 0xE0:
                        char_bytes = 3;
                        break;

                    default:
                        break;
                    }
                    temp_char = c;

                }
                else {
                    temp_char <<= 8;
                    temp_char |= c;
                    if (char_count == char_bytes) {
                        break;
                    }
                }
            }
            // ひらがな & カタカナ 0xE38180 <= c && c <= E383BF
            // match
            switch (char_bytes) {
            case 1:
                if (temp_char == '<')in_tag = true;
                if (temp_char == '>')in_tag = false;

                if ('0' <= temp_char && temp_char <= '9' && !in_tag)
                    out += getDigitCodeToRomaji((char)temp_char);
                else
                    out += temp_char;
                break;

            case 2:
                break;
            case 3:
                // TODO match hira
                out += getCharCodeToRomaji(temp_char);
                break;
            default:
                break;
            }
        }
        return out;
    }

    std::string getCharCodeToRomaji(const uint32_t code) {
        std::string out;
        switch (code) {
            //平仮名と片仮名
        case HIRA_A:
        case HIRA_A + KATA_OFFSET:
            out = "a";
            break;
        case HIRA_I:
        case HIRA_I + KATA_OFFSET:
            out = "i";
            break;
        case HIRA_U:
        case HIRA_U + KATA_OFFSET:
            out = "u";
            break;
        case HIRA_E:
        case HIRA_E + KATA_OFFSET:
            out = "e";
            break;
        case HIRA_O:
        case HIRA_O + KATA_OFFSET:
            out = "o";
            break;

        case HIRA_KA:
        case HIRA_KA + KATA_OFFSET:
            out = "ka";
            break;
        case HIRA_KI:
        case HIRA_KI + KATA_OFFSET:
            out = "ki";
            break;
        case HIRA_KU:
        case HIRA_KU + KATA_OFFSET:
            out = "ku";
            break;
        case HIRA_KE:
        case HIRA_KE + KATA_OFFSET:
            out = "ke";
            break;
        case HIRA_KO:
        case HIRA_KO + KATA_OFFSET:
            out = "ko";
            break;

        case HIRA_SA:
        case HIRA_SA + KATA_OFFSET:
            out = "sa";
            break;
        case HIRA_SI:
        case HIRA_SI + KATA_OFFSET:
            out = "si";
            break;
        case HIRA_SU:
        case HIRA_SU + KATA_OFFSET:
            out = "su";
            break;
        case HIRA_SE:
        case HIRA_SE + KATA_OFFSET:
            out = "se";
            break;
        case HIRA_SO:
        case HIRA_SO + KATA_OFFSET:
            out = "so";
            break;

        case HIRA_TA:
        case HIRA_TA + KATA_OFFSET:
            out = "ta";
            break;
        case HIRA_TI:
        case HIRA_TI + KATA_OFFSET2:
            out = "ti";
            break;
        case HIRA_TU:
        case HIRA_TU + KATA_OFFSET2:
            out = "tu";
            break;
        case HIRA_TE:
        case HIRA_TE + KATA_OFFSET2:
            out = "te";
            break;
        case HIRA_TO:
        case HIRA_TO + KATA_OFFSET2:
            out = "to";
            break;

        case HIRA_NA:
        case HIRA_NA + KATA_OFFSET2:
            out = "na";
            break;
        case HIRA_NI:
        case HIRA_NI + KATA_OFFSET2:
            out = "ni";
            break;
        case HIRA_NU:
        case HIRA_NU + KATA_OFFSET2:
            out = "nu";
            break;
        case HIRA_NE:
        case HIRA_NE + KATA_OFFSET2:
            out = "ne";
            break;
        case HIRA_NO:
        case HIRA_NO + KATA_OFFSET2:
            out = "no";
            break;

        case HIRA_HA:
        case HIRA_HA + KATA_OFFSET2:
            out = "ha";
            break;
        case HIRA_HI:
        case HIRA_HI + KATA_OFFSET2:
            out = "hi";
            break;
        case HIRA_HU:
        case HIRA_HU + KATA_OFFSET2:
            out = "hu";
            break;
        case HIRA_HE:
        case HIRA_HE + KATA_OFFSET2:
            out = "he";
            break;
        case HIRA_HO:
        case HIRA_HO + KATA_OFFSET2:
            out = "ho";
            break;

        case HIRA_MA:
        case HIRA_MA + KATA_OFFSET2:
            out = "ma";
            break;
        case HIRA_MI:
        case HIRA_MI + KATA_OFFSET2:
            out = "mi";
            break;
        case HIRA_MU:
        case HIRA_MU + KATA_OFFSET:
            out = "mu";
            break;
        case HIRA_ME:
        case HIRA_ME + KATA_OFFSET:
            out = "me";
            break;
        case HIRA_MO:
        case HIRA_MO + KATA_OFFSET:
            out = "mo";
            break;

        case HIRA_YA:
        case HIRA_YA + KATA_OFFSET:
            out = "ya";
            break;

        case HIRA_YU:
        case HIRA_YU + KATA_OFFSET:
            out = "yu";
            break;

        case HIRA_YO:
        case HIRA_YO + KATA_OFFSET:
            out = "yo";
            break;

        case HIRA_RA:
        case HIRA_RA + KATA_OFFSET:
            out = "ra";
            break;
        case HIRA_RI:
        case HIRA_RI + KATA_OFFSET:
            out = "ri";
            break;
        case HIRA_RU:
        case HIRA_RU + KATA_OFFSET:
            out = "ru";
            break;
        case HIRA_RE:
        case HIRA_RE + KATA_OFFSET:
            out = "re";
            break;
        case HIRA_RO:
        case HIRA_RO + KATA_OFFSET:
            out = "ro";
            break;

        case HIRA_WA:
        case HIRA_WA + KATA_OFFSET:
            out = "wa";
            break;
        case HIRA_WI:
        case HIRA_WI + KATA_OFFSET:
            out = "wi";
            break;
        case HIRA_WE:
        case HIRA_WE + KATA_OFFSET:
            out = "we";
            break;
        case HIRA_WO:
        case HIRA_WO + KATA_OFFSET:
            out = "wo";
            break;

        case HIRA_GA:
        case HIRA_GA + KATA_OFFSET:
            out = "ga";
            break;
        case HIRA_GI:
        case HIRA_GI + KATA_OFFSET:
            out = "gi";
            break;
        case HIRA_GU:
        case HIRA_GU + KATA_OFFSET:
            out = "gu";
            break;
        case HIRA_GE:
        case HIRA_GE + KATA_OFFSET:
            out = "ge";
            break;
        case HIRA_GO:
        case HIRA_GO + KATA_OFFSET:
            out = "go";
            break;

        case HIRA_ZA:
        case HIRA_ZA + KATA_OFFSET:
            out = "za";
            break;
        case HIRA_ZI:
        case HIRA_ZI + KATA_OFFSET:
            out = "zi";
            break;
        case HIRA_ZU:
        case HIRA_ZU + KATA_OFFSET:
            out = "zu";
            break;
        case HIRA_ZE:
        case HIRA_ZE + KATA_OFFSET:
            out = "ze";
            break;
        case HIRA_ZO:
        case HIRA_ZO + KATA_OFFSET:
            out = "zo";
            break;

        case HIRA_DA:
        case HIRA_DA + KATA_OFFSET2:
            out = "da";
            break;
        case HIRA_DI:
        case HIRA_DI + KATA_OFFSET2:
            out = "di";
            break;
        case HIRA_DU:
        case HIRA_DU + KATA_OFFSET2:
            out = "du";
            break;
        case HIRA_DE:
        case HIRA_DE + KATA_OFFSET2:
            out = "de";
            break;
        case HIRA_DO:
        case HIRA_DO + KATA_OFFSET2:
            out = "do";
            break;

        case HIRA_BA:
        case HIRA_BA + KATA_OFFSET2:
            out = "ba";
            break;
        case HIRA_BI:
        case HIRA_BI + KATA_OFFSET2:
            out = "bi";
            break;
        case HIRA_BU:
        case HIRA_BU + KATA_OFFSET2:
            out = "bu";
            break;
        case HIRA_BE:
        case HIRA_BE + KATA_OFFSET2:
            out = "be";
            break;
        case HIRA_BO:
        case HIRA_BO + KATA_OFFSET2:
            out = "bo";
            break;

        case HIRA_PA:
        case HIRA_PA + KATA_OFFSET2:
            out = "pa";
            break;
        case HIRA_PI:
        case HIRA_PI + KATA_OFFSET2:
            out = "pi";
            break;
        case HIRA_PU:
        case HIRA_PU + KATA_OFFSET2:
            out = "pu";
            break;
        case HIRA_PE:
        case HIRA_PE + KATA_OFFSET2:
            out = "pe";
            break;
        case HIRA_PO:
        case HIRA_PO + KATA_OFFSET2:
            out = "po";
            break;

        case HIRA_XA:
        case HIRA_XA + KATA_OFFSET:
            out = "xa";
            break;
        case HIRA_XI:
        case HIRA_XI + KATA_OFFSET:
            out = "xi";
            break;
        case HIRA_XU:
        case HIRA_XU + KATA_OFFSET:
            out = "xu";
            break;
            break;
        case HIRA_XE:
        case HIRA_XE + KATA_OFFSET:
            out = "xe";
            break;
        case HIRA_XO:
        case HIRA_XO + KATA_OFFSET:
            out = "xo";
            break;

        case HIRA_XYA:
        case HIRA_XYA + KATA_OFFSET:
            out = "xya";
            break;
        case HIRA_XYU:
        case HIRA_XYU + KATA_OFFSET:
            out = "xyi";
            break;
        case HIRA_XYO:
        case HIRA_XYO + KATA_OFFSET:
            out = "xyo";
            break;

        case HIRA_XTU:
        case HIRA_XTU + KATA_OFFSET2:
            out = "ltu";
            break;

        case HIRA_VU:
        case HIRA_VU + KATA_OFFSET:
            out = "bu";
            break;

        case HIRA_NN:
        case HIRA_NN + KATA_OFFSET:
            out = "nn";
            break;


        case HIRA_KUTEN:
            out = ",";
            break;

        case HIRA_KUTOUTEN:
            out = ".";
            break;

        case HIRA_NOBASHI:
            out = "-";
            break;



        case CJK_SYMBOLS_AND_PUNCTUATION_LEFT_ANGLE_BRACKET:
            out = "yamakaltyko";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_ANGLE_BRACKET:
            out = "yamakaltukotozi";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_LEFT_DOUBLE_ANGLE_BRACKET:
            out = "nizyuuyamakaltuko";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_DOUBLE_ANGLE_BRACKET:
            out = "nizyuuyamakaltukotozi";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_LEFT_CORNER_BRACKET:
            out = "kagikaltuko";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_CORNER_BRACKET:
            out = "kagikaltukotozi";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_LEFT_WHITE_CORNER_BRACKET:
            out = "nizyuukagikaltuko";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_WHITE_CORNER_BRACKET:
            out = "nizyuukagikaltukotozi";
            break;

        case CJK_SYMBOLS_AND_PUNCTUATION_LEFT_BLACK_LENTICULAR_BRACKET:
            out = "sumitukikaltuko";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_BLACK_LENTICULAR_BRACKET:
            out = "sumitukikaltukotozi";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_POSTAL_MARK:
            out = "yuubinnkigou";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_GETA_MARK:
            out = "getakigou";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_LEFT_TORTOISE_SHELL_BRACKET:
            out = "kiltukoukaltuko";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_TORTOISE_SHELL_BRACKET:
            out = "kiltukoukaltukotozi";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_LEFT_WHITE_LENTICULAR_BRACKET:
            out = "nizyuusumitukikaltuko";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_WHITE_LENTICULAR_BRACKET:
            out = "nizyuusumitukikaltukotozi";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_LEFT_WHITE_TORTOISE_SHELL_BRACKET:
            out = "nizyuukiltukoukaltuko";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_WHITE_TORTOISE_SHELL_BRACKET:
            out = "nizyuukiltukoukaltukotozi";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_LEFT_WHITE_SQUARE_BRACKET:
            out = "nizyuukakukaltuko";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_RIGHT_WHITE_SQUARE_BRACKET:
            out = "nizyuukakukaltukotozi";
            break;
        case CJK_SYMBOLS_AND_PUNCTUATION_WAVE_DASH:
            out = "-";
            break;


        case IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_JANUARY:
            out = "itigatu";
            break;
        case IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_FEBRUARY:
            out = "nigatu";
            break;
        case IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_MARCH:
            out = "sanngatu";
            break;
        case IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_APRIL:
            out = "sigatu";
            break;
        case IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_MAY:
            out = "gogatu";
            break;
        case IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_JUNE:
            out = "rokugatu";
            break;
        case IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_JULY:
            out = "sitigatu";
            break;
        case IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_AUGUST:
            out = "hatigatu";
            break;
        case IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_SEPTEMBER:
            out = "kugatu";
            break;
        case IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_OCTOBER:
            out = "zyuugatu";
            break;
        case IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_NOVEMBER:
            out = "zyuuitigatu";
            break;
        case IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DECEMBER:
            out = "zyuunigatu";
            break;


        case CJK_COMPATIBILITY_SQUARE_APAATO:
            out = "apaato";
            break;
        case CJK_COMPATIBILITY_SQUARE_ARUHUA:
            out = "aruha";
            break;
        case CJK_COMPATIBILITY_SQUARE_ANPEA:
            out = "annpea";
            break;
        case CJK_COMPATIBILITY_SQUARE_AARU:
            out = "aaru";
            break;
        case CJK_COMPATIBILITY_SQUARE_ININGU:
            out = "ininngu";
            break;
        case CJK_COMPATIBILITY_SQUARE_INTI:
            out = "innti";
            break;
        case CJK_COMPATIBILITY_SQUARE_UON:
            out = "wonn";
            break;
        case CJK_COMPATIBILITY_SQUARE_ESUKUUDO:
            out = "esukuudo";
            break;
        case CJK_COMPATIBILITY_SQUARE_EEKAA:
            out = "eekaa";
            break;
        case CJK_COMPATIBILITY_SQUARE_ONSU:
            out = "onnsu";
            break;
        case CJK_COMPATIBILITY_SQUARE_OOMU:
            out = "oomu";
            break;
        case CJK_COMPATIBILITY_SQUARE_KAIRI:
            out = "kairi";
            break;
        case CJK_COMPATIBILITY_SQUARE_KARATTO:
            out = "karaltuto";
            break;
        case CJK_COMPATIBILITY_SQUARE_KARORII:
            out = "karorii";
            break;
        case CJK_COMPATIBILITY_SQUARE_GARON:
            out = "garonn";
            break;
        case CJK_COMPATIBILITY_SQUARE_GANMA:
            out = "gannma";
            break;

        case CJK_COMPATIBILITY_SQUARE_GIGA:
            out = "giga";
            break;
        case CJK_COMPATIBILITY_SQUARE_GINII:
            out = "ginii";
            break;
        case CJK_COMPATIBILITY_SQUARE_KYURII:
            out = "kyurii";
            break;
        case CJK_COMPATIBILITY_SQUARE_GIRUDAA:
            out = "girudaa";
            break;
        case CJK_COMPATIBILITY_SQUARE_KIRO:
            out = "kiro";
            break;
        case CJK_COMPATIBILITY_SQUARE_KIROGURAMU:
            out = "kiroguramu";
            break;
        case CJK_COMPATIBILITY_SQUARE_KIROMEETORU:
            out = "kiromeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_KIROWATTO:
            out = "kirowatto";
            break;
        case CJK_COMPATIBILITY_SQUARE_GURAMU:
            out = "guramu";
            break;
        case CJK_COMPATIBILITY_SQUARE_GURAMUTON:
            out = "guramutonn";
            break;
        case CJK_COMPATIBILITY_SQUARE_KURUZEIRO:
            out = "kuruzeiro";
            break;
        case CJK_COMPATIBILITY_SQUARE_KUROONE:
            out = "kuroone";
            break;
        case CJK_COMPATIBILITY_SQUARE_KEESU:
            out = "keesu";
            break;
        case CJK_COMPATIBILITY_SQUARE_KORUNA:
            out = "koruna";
            break;
        case CJK_COMPATIBILITY_SQUARE_KOOPO:
            out = "koopo";
            break;
        case CJK_COMPATIBILITY_SQUARE_SAIKURU:
            out = "saikuru";
            break;

        case CJK_COMPATIBILITY_SQUARE_SANTIIMU:
            out = "sanntiimu";
            break;
        case CJK_COMPATIBILITY_SQUARE_SIRINGU:
            out = "sirinngu";
            break;
        case CJK_COMPATIBILITY_SQUARE_SENTI:
            out = "sennti";
            break;
        case CJK_COMPATIBILITY_SQUARE_SENTO:
            out = "sennto";
            break;
        case CJK_COMPATIBILITY_SQUARE_DAASU:
            out = "saasu";
            break;
        case CJK_COMPATIBILITY_SQUARE_DESI:
            out = "sesi";
            break;
        case CJK_COMPATIBILITY_SQUARE_SORU:
            out = "soru";
            break;
        case CJK_COMPATIBILITY_SQUARE_TON:
            out = "tonn";
            break;
        case CJK_COMPATIBILITY_SQUARE_NANO:
            out = "nano";
            break;
        case CJK_COMPATIBILITY_SQUARE_NOTTO:
            out = "noltuto";
            break;
        case CJK_COMPATIBILITY_SQUARE_HAITU:
            out = "haitu";
            break;
        case CJK_COMPATIBILITY_SQUARE_PAASENTO:
            out = "paasennto";
            break;
        case CJK_COMPATIBILITY_SQUARE_PAATU:
            out = "paatu";
            break;
        case CJK_COMPATIBILITY_SQUARE_BAARERU:
            out = "bareru";
            break;
        case CJK_COMPATIBILITY_SQUARE_PIASUTORU:
            out = "piasutoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_PIKURU:
            out = "pikuru";
            break;

        case CJK_COMPATIBILITY_SQUARE_PIKO:
            out = "piko";
            break;
        case CJK_COMPATIBILITY_SQUARE_BIRU:
            out = "biru";
            break;
        case CJK_COMPATIBILITY_SQUARE_HUARADDO:
            out = "haraltudo";
            break;
        case CJK_COMPATIBILITY_SQUARE_HUIITO:
            out = "hwiito";
            break;
        case CJK_COMPATIBILITY_SQUARE_BUSSYERU:
            out = "bultusyeru";
            break;
        case CJK_COMPATIBILITY_SQUARE_HURAN:
            out = "hurann";
            break;
        case CJK_COMPATIBILITY_SQUARE_HEKUTAARU:
            out = "hekutaaru";
            break;
        case CJK_COMPATIBILITY_SQUARE_PESO:
            out = "peso";
            break;
        case CJK_COMPATIBILITY_SQUARE_PENIHI:
            out = "penihi";
            break;
        case CJK_COMPATIBILITY_SQUARE_HERUTU:
            out = "herutu";
            break;
        case CJK_COMPATIBILITY_SQUARE_PENSU:
            out = "pennsu";
            break;
        case CJK_COMPATIBILITY_SQUARE_PEEZI:
            out = "peezi";
            break;
        case CJK_COMPATIBILITY_SQUARE_BEETA:
            out = "beeta";
            break;
        case CJK_COMPATIBILITY_SQUARE_POINTO:
            out = "poinnto";
            break;
        case CJK_COMPATIBILITY_SQUARE_BORUTO:
            out = "boruto";
            break;
        case CJK_COMPATIBILITY_SQUARE_HON:
            out = "honn";
            break;

        case CJK_COMPATIBILITY_SQUARE_PONDO:
            out = "ponndo";
            break;
        case CJK_COMPATIBILITY_SQUARE_HOORU:
            out = "hooru";
            break;
        case CJK_COMPATIBILITY_SQUARE_HOON:
            out = "hoonn";
            break;
        case CJK_COMPATIBILITY_SQUARE_MAIKURO:
            out = "maikuro";
            break;
        case CJK_COMPATIBILITY_SQUARE_MAIRU:
            out = "mairu";
            break;
        case CJK_COMPATIBILITY_SQUARE_MAHHA:
            out = "maltuha";
            break;
        case CJK_COMPATIBILITY_SQUARE_MARUKU:
            out = "maruku";
            break;
        case CJK_COMPATIBILITY_SQUARE_MANSYON:
            out = "mannsyonn";
            break;
        case CJK_COMPATIBILITY_SQUARE_MIKURON:
            out = "mikuronn";
            break;
        case CJK_COMPATIBILITY_SQUARE_MIRI:
            out = "miri";
            break;
        case CJK_COMPATIBILITY_SQUARE_MIRIBAARU:
            out = "miribaaru";
            break;
        case CJK_COMPATIBILITY_SQUARE_MEGA:
            out = "mega";
            break;
        case CJK_COMPATIBILITY_SQUARE_MEGATON:
            out = "megatonn";
            break;
        case CJK_COMPATIBILITY_SQUARE_MEETORU:
            out = "meetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_YAADO:
            out = "yaado";
            break;
        case CJK_COMPATIBILITY_SQUARE_YAARU:
            out = "yaaru";
            break;

        case CJK_COMPATIBILITY_SQUARE_YUAN:
            out = "yuann";
            break;
        case CJK_COMPATIBILITY_SQUARE_RITTORU:
            out = "riltutoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_RIRA:
            out = "rira";
            break;
        case CJK_COMPATIBILITY_SQUARE_RUPII:
            out = "rupii";
            break;
        case CJK_COMPATIBILITY_SQUARE_RUUBURU:
            out = "ruuburu";
            break;
        case CJK_COMPATIBILITY_SQUARE_REMU:
            out = "remu";
            break;
        case CJK_COMPATIBILITY_SQUARE_RENTOGEN:
            out = "renntogenn";
            break;
        case CJK_COMPATIBILITY_SQUARE_WATTO:
            out = "waltuto";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_ZERO:
            out = "reitenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_ONE:
            out = "iltutenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TWO:
            out = "nitenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_THREE:
            out = "sanntenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_FOUR:
            out = "yonntenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_FIVE:
            out = "gotenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_SIX:
            out = "rokutenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_SEVEN:
            out = "nanatenn";
            break;

        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_EIGHT:
            out = "haltutenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_NINE:
            out = "kyuutenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TEN:
            out = "zyultutenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_ELEVEN:
            out = "zyuuititenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TWELVE:
            out = "zyuunitenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_THIRTEEN:
            out = "zyuusanntenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_FOURTEEN:
            out = "zyuuyonntenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_FIFTEEN:
            out = "zyuugotenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_SIXTEEN:
            out = "zyuurokutenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_SEVENTEEN:
            out = "zyuunanatenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_EIGHTEEN:
            out = "zyuuhaltutenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_NINETEEN:
            out = "zyuukyuutenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TWENTY:
            out = "nizyuttenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TWENTY_ONE:
            out = "nizyuuititenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TWENTY_TWO:
            out = "nizyuunitenn";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TWENTY_THREE:
            out = "nizyuusanntenn";
            break;

        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_HOUR_TWENTY_FOUR:
            out = "nizyuuyonntenn";
            break;
        case CJK_COMPATIBILITY_SQUARE_HPA:
            out = "hekitopasukaru";
            break;
        case CJK_COMPATIBILITY_SQUARE_DA:
            out = "deka";
            break;
        case CJK_COMPATIBILITY_SQUARE_AU:
            out = "tennmonntanni";
            break;
        case CJK_COMPATIBILITY_SQUARE_BAR:
            out = "baaru";
            break;
        case CJK_COMPATIBILITY_SQUARE_OV:
            out = "oobui";
            break;
        case CJK_COMPATIBILITY_SQUARE_PC:
            out = "paaseku";
            break;
        case CJK_COMPATIBILITY_SQUARE_DM:
            out = "desimeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_DM_SQUARED:
            out = "heihoudesimeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_DM_CUBED:
            out = "riltupoudesimeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_IU:
            out = "aiyuu";
            break;
        case CJK_COMPATIBILITY_SQUARE_EAR_NAME_HEISEI:
            out = "heisei";
            break;
        case CJK_COMPATIBILITY_SQUARE_EAR_NAME_SYOUWA:
            out = "syouwa";
            break;
        case CJK_COMPATIBILITY_SQUARE_EAR_NAME_TAISYOU:
            out = "taisyou";
            break;
        case CJK_COMPATIBILITY_SQUARE_EAR_NAME_MEIZI:
            out = "meizi";
            break;
        case CJK_COMPATIBILITY_SQUARE_CORPORATION:
            out = "kabusikigaisya";
            break;

        case CJK_COMPATIBILITY_SQUARE_PA_AMPS:
            out = "pikoannpea";
            break;
        case CJK_COMPATIBILITY_SQUARE_NA:
            out = "nanoannpea";
            break;
        case CJK_COMPATIBILITY_SQUARE_MU_A:
            out = "maikuroannpea";
            break;
        case CJK_COMPATIBILITY_SQUARE_MA:
            out = "miriannpea";
            break;
        case CJK_COMPATIBILITY_SQUARE_KA:
            out = "kiroannpea";
            break;
        case CJK_COMPATIBILITY_SQUARE_KB:
            out = "kirobaito";
            break;
        case CJK_COMPATIBILITY_SQUARE_MB:
            out = "megabaito";
            break;
        case CJK_COMPATIBILITY_SQUARE_GB:
            out = "gigabaito";
            break;
        case CJK_COMPATIBILITY_SQUARE_CAL:
            out = "karorii";
            break;
        case CJK_COMPATIBILITY_SQUARE_KCAL:
            out = "kirokarorii";
            break;
        case CJK_COMPATIBILITY_SQUARE_PF:
            out = "pikoharaltudo";
            break;
        case CJK_COMPATIBILITY_SQUARE_NF:
            out = "nanoharaltudo";
            break;
        case CJK_COMPATIBILITY_SQUARE_MU_F:
            out = "maikuroharaltudo";
            break;
        case CJK_COMPATIBILITY_SQUARE_MU_G:
            out = "maikuroguramu";
            break;
        case CJK_COMPATIBILITY_SQUARE_MG:
            out = "miriguramu";
            break;
        case CJK_COMPATIBILITY_SQUARE_KG:
            out = "kiroguramu";
            break;

        case CJK_COMPATIBILITY_SQUARE_HZ:
            out = "herutu";
            break;
        case CJK_COMPATIBILITY_SQUARE_KHZ:
            out = "kiroherutu";
            break;
        case CJK_COMPATIBILITY_SQUARE_MHZ:
            out = "megaherutu";
            break;
        case CJK_COMPATIBILITY_SQUARE_GHZ:
            out = "gigaherutu";
            break;
        case CJK_COMPATIBILITY_SQUARE_THZ:
            out = "teraherutu";
            break;
        case CJK_COMPATIBILITY_SQUARE_MU_L:
            out = "maikuroriltutoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_ML:
            out = "miririltutoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_DL:
            out = "desiriltutoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_KL:
            out = "kiroriltutoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_FM:
            out = "hwemutomeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_NM:
            out = "nanomeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_MU_M:
            out = "maikuromeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_MM:
            out = "mirimeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_CM:
            out = "senntimeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_KM:
            out = "kiromeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_MM_SQUARED:
            out = "heihoumirimeetoru";
            break;

        case CJK_COMPATIBILITY_SQUARE_CM_SQUARED:
            out = "heihousenntimeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_M_SQUARED:
            out = "heihoumeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_KM_SQUARED:
            out = "heihoukiromeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_MM_CUBED:
            out = "riltupoumirimeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_CM_CUBED:
            out = "riltupousenntimeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_M_CUBED:
            out = "riltupoumeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_KM_CUBED:
            out = "riltupoukiromeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_M_OVER_S:
            out = "meetorumaibyou";
            break;
        case CJK_COMPATIBILITY_SQUARE_M_OVER_S_SQUARED:
            out = "meetorumaibyoumaibyou";
            break;
        case CJK_COMPATIBILITY_SQUARE_PA:
            out = "pasukaru";
            break;
        case CJK_COMPATIBILITY_SQUARE_KPA:
            out = "kiropasukaru";
            break;
        case CJK_COMPATIBILITY_SQUARE_MPA:
            out = "megapasukaru";
            break;
        case CJK_COMPATIBILITY_SQUARE_GPA:
            out = "gigapasukaru";
            break;
        case CJK_COMPATIBILITY_SQUARE_RAD:
            out = "raziann";
            break;
        case CJK_COMPATIBILITY_SQUARE_RAD_OVER_S:
            out = "raziannmaibyou";
            break;
        case CJK_COMPATIBILITY_SQUARE_RAD_OVER_S_SQUARED:
            out = "raziannmaibyoumaibyou";
            break;

        case CJK_COMPATIBILITY_SQUARE_PS:
            out = "pikobyou";
            break;
        case CJK_COMPATIBILITY_SQUARE_NS:
            out = "nanobyou";
            break;
        case CJK_COMPATIBILITY_SQUARE_MU_S:
            out = "maikurobyou";
            break;
        case CJK_COMPATIBILITY_SQUARE_MS:
            out = "megabyou";
            break;
        case CJK_COMPATIBILITY_SQUARE_PV:
            out = "pikoboruto";
            break;
        case CJK_COMPATIBILITY_SQUARE_NV:
            out = "nanoboruto";
            break;
        case CJK_COMPATIBILITY_SQUARE_MU_V:
            out = "maikuroboruto";
            break;
        case CJK_COMPATIBILITY_SQUARE_MV:
            out = "miriboruto";
            break;
        case CJK_COMPATIBILITY_SQUARE_KV:
            out = "kiroboruto";
            break;
        case CJK_COMPATIBILITY_SQUARE_MV_MEGA:
            out = "megaboruto";
            break;
        case CJK_COMPATIBILITY_SQUARE_PW:
            out = "pikowaltuto";
            break;
        case CJK_COMPATIBILITY_SQUARE_NW:
            out = "nanowaltuto";
            break;
        case CJK_COMPATIBILITY_SQUARE_MU_W:
            out = "maikurowaltuto";
            break;
        case CJK_COMPATIBILITY_SQUARE_MW:
            out = "miriwaltuto";
            break;
        case CJK_COMPATIBILITY_SQUARE_KW:
            out = "kirowaltuto";
            break;
        case CJK_COMPATIBILITY_SQUARE_MW_MWGA:
            out = "megawaltuto";
            break;

        case CJK_COMPATIBILITY_SQUARE_K_OHM:
            out = "kirooomu";
            break;
        case CJK_COMPATIBILITY_SQUARE_M_OHM:
            out = "megaoomu";
            break;
        case CJK_COMPATIBILITY_SQUARE_AM:
            out = "gozenn";
            break;
        case CJK_COMPATIBILITY_SQUARE_BQ:
            out = "bekureru";
            break;
        case CJK_COMPATIBILITY_SQUARE_CC:
            out = "riltupousenntimeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_CD:
            out = "kanndera";
            break;
        case CJK_COMPATIBILITY_SQUARE_C_OVER_KG:
            out = "kuuronnmaikiroguramu";
            break;
        case CJK_COMPATIBILITY_SQUARE_CO:
            out = "kaisya";
            break;
        case CJK_COMPATIBILITY_SQUARE_DB:
            out = "desiberu";
            break;
        case CJK_COMPATIBILITY_SQUARE_GY:
            out = "gurei";
            break;
        case CJK_COMPATIBILITY_SQUARE_HA:
            out = "hekutaaru";
            break;
        case CJK_COMPATIBILITY_SQUARE_HP:
            out = "bariki";
            break;
        case CJK_COMPATIBILITY_SQUARE_IN:
            out = "innti";
            break;
        case CJK_COMPATIBILITY_SQUARE_KK:
            out = "kabusikigaisya";
            break;
        case CJK_COMPATIBILITY_SQUARE_KM_CAPITAL:
            out = "keeemu";
            break;
        case CJK_COMPATIBILITY_SQUARE_KT:
            out = "noltuto";
            break;

        case CJK_COMPATIBILITY_SQUARE_LM:
            out = "ruumenn";
            break;
        case CJK_COMPATIBILITY_SQUARE_LN:
            out = "eruenu";
            break;
        case CJK_COMPATIBILITY_SQUARE_LOG:
            out = "rogu";
            break;
        case CJK_COMPATIBILITY_SQUARE_LX:
            out = "rukusu";
            break;
        case CJK_COMPATIBILITY_SQUARE_MB_SMALL:
            out = "miribaaru";
            break;
        case CJK_COMPATIBILITY_SQUARE_MIL:
            out = "mairu";
            break;
        case CJK_COMPATIBILITY_SQUARE_MOL:
            out = "moru";
            break;
        case CJK_COMPATIBILITY_SQUARE_PH:
            out = "peehaa";
            break;
        case CJK_COMPATIBILITY_SQUARE_PM:
            out = "gogo";
            break;
        case CJK_COMPATIBILITY_SQUARE_PPM:
            out = "paatupaamirionn";
            break;
        case CJK_COMPATIBILITY_SQUARE_PR:
            out = "piiaaru";
            break;
        case CJK_COMPATIBILITY_SQUARE_SR:
            out = "suterazuann";
            break;
        case CJK_COMPATIBILITY_SQUARE_SV:
            out = "siiberuto";
            break;
        case CJK_COMPATIBILITY_SQUARE_WB:
            out = "weebaa";
            break;
        case CJK_COMPATIBILITY_SQUARE_V_OVER_M:
            out = "borutomaimeetoru";
            break;
        case CJK_COMPATIBILITY_SQUARE_A_OVER_M:
            out = "annpeamaimeetoru";
            break;

        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_ONE:
            out = "tuitati";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWO:
            out = "futuka";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_THREE:
            out = "miltuka";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_FOUR:
            out = "yoltuka";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_FIVE:
            out = "ituka";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_SIX:
            out = "muika";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_SEVEN:
            out = "nanoka";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_EIGHT:
            out = "youka";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_NINE:
            out = "kokonoka";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TEN:
            out = "tooka";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_ELEVEN:
            out = "zyuuitiniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWELVE:
            out = "zyuuniniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_THIRTEEN:
            out = "zyuusannniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_FOURTEEN:
            out = "zyuuyonltyka";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_FIFTEEN:
            out = "zyuugoniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_SIXTEEN:
            out = "zyuurokuniti";
            break;

        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_SEVENTEEN:
            out = "zyuusitiniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_EIGHTEEN:
            out = "zyuuhatiniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_NINETEEN:
            out = "zyuukuniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY:
            out = "hatuka";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_ONE:
            out = "nizyuuitiniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_TWO:
            out = "nizyuuniniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_THREE:
            out = "nizyuusannniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_FOUR:
            out = "nizyuuyoltyka";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_FIVE:
            out = "nizyuugoniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_SIX:
            out = "nizyuurokuniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_SEVEN:
            out = "nizyuunananiti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_EIGHT:
            out = "nizyuuhatiniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_TWENTY_NINE:
            out = "nizyuukuniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_THIRTY:
            out = "sannzyuuniti";
            break;
        case CJK_COMPATIBILITY_IDEOGRAPHIC_TELEGRAPH_SYMBOL_FOR_DAY_THIRTY_ONE:
            out = "sannzyuuitiniti";
            break;
        case CJK_COMPATIBILITY_SQUARE_GAL:
            out = "garu";
            break;






        default:
            out = "";
            break;
        }
        return out;
    }

    std::string getDigitCodeToRomaji(const char code) {
        std::string out;
        switch (code) {
        case '0':
            out = "zero";
            break;
        case '1':
            out = "iti";
            break;
        case '2':
            out = "ni";
            break;
        case '3':
            out = "sann";
            break;
        case '4':
            out = "yonn";
            break;
        case '5':
            out = "go";
            break;
        case '6':
            out = "roku";
            break;
        case '7':
            out = "nana";
            break;
        case '8':
            out = "hati";
            break;
        case '9':
            out = "kuu";
            break;

        default:
            break;
        }
        return out;
    }



    std::string number_to_Nesora(const std::string& str) {
        std::string out;

        out = fraction_to_Nesora(str);

        return out;
    }

    std::string integer_to_Nesora(const std::string& str) {
        if (str == "0")return "zero";

        std::string out;

        if (str.front() == '-')out += "mainasu";
        else if (str.front() == '+')out += "purasu";

        for (size_t i = 0;i < str.length();i++) {
            int nowketasu = str.size() - i - 1;
            switch (str[i]) {
            case '0':
                break;
            case '1':
                if (nowketasu % 4 == 0)
                    out += "iti";
                else if (nowketasu % 4 == 1)
                    out += "zyuu";
                else if (nowketasu % 4 == 2)
                    out += "hyaku";
                else if (nowketasu % 4 == 3)
                    out += "senn";
                break;
            case '2':
                out += "ni";
                if (nowketasu % 4 == 1)
                    out += "zyuu";
                else if (nowketasu % 4 == 2)
                    out += "hyaku";
                else if (nowketasu % 4 == 3)
                    out += "senn";
                break;
            case '3':
                out += "sann";
                if (nowketasu % 4 == 1)
                    out += "zyuu";
                else if (nowketasu % 4 == 2)
                    out += "byaku";
                else if (nowketasu % 4 == 3)
                    out += "zenn";
                break;
            case '4':
                out += "yonn";
                if (nowketasu % 4 == 1)
                    out += "zyuu";
                else if (nowketasu % 4 == 2)
                    out += "hyaku";
                else if (nowketasu % 4 == 3)
                    out += "senn";
                break;
            case '5':
                out += "go";
                if (nowketasu % 4 == 1)
                    out += "zyuu";
                else if (nowketasu % 4 == 2)
                    out += "hyaku";
                else if (nowketasu % 4 == 3)
                    out += "senn";
                break;
            case '6':
                if (nowketasu % 4 == 0)
                    out += "roku";
                if (nowketasu % 4 == 1)
                    out += "rokuzyuu";
                else if (nowketasu % 4 == 2)
                    out += "ro,pyaku";
                else if (nowketasu % 4 == 3)
                    out += "rokusenn";
                break;
            case '7':
                out += "nana";
                if (nowketasu % 4 == 1)
                    out += "zyuu";
                else if (nowketasu % 4 == 2)
                    out += "hyaku";
                else if (nowketasu % 4 == 3)
                    out += "senn";
                break;
            case '8':
                if (nowketasu % 4 == 0)
                    out += "hati";
                if (nowketasu % 4 == 1)
                    out += "hatizyuu";
                else if (nowketasu % 4 == 2)
                    out += "ha,pyaku";
                else if (nowketasu % 4 == 3)
                    out += "ha,senn";
                break;
            case '9':
                out += "kyuu";
                if (nowketasu % 4 == 1)
                    out += "zyuu";
                else if (nowketasu % 4 == 2)
                    out += "hyaku";
                else if (nowketasu % 4 == 3)
                    out += "senn";
                break;
            }

            if (nowketasu % 4 == 0) {
                if (nowketasu * 0.25 == 1)
                    out += "mann,";
                else if (nowketasu * 0.25 == 2)
                    out += "oku,";
                else if (nowketasu * 0.25 == 3)
                    out += "tyou,";
                else if (nowketasu * 0.25 == 4)
                    out += "kei,";
                else if (nowketasu * 0.25 == 5)
                    out += "gai,";
                else if (nowketasu * 0.25 == 6)
                    out += "zyo,";
                else if (nowketasu * 0.25 == 7)
                    out += "zyou,";
                else if (nowketasu * 0.25 == 8)
                    out += "kou,";
                else if (nowketasu * 0.25 == 9)
                    out += "kann,";
                else if (nowketasu * 0.25 == 10)
                    out += "sei,";
                else if (nowketasu * 0.25 == 11)
                    out += "sai,";
                else if (nowketasu * 0.25 == 12)
                    out += "goku,";
                else if (nowketasu * 0.25 == 13)
                    out += "gougasya,";
                else if (nowketasu * 0.25 == 14)
                    out += "asougi,";
                else if (nowketasu * 0.25 == 15)
                    out += "nayuta,";
                else if (nowketasu * 0.25 == 16)
                    out += "fukasigi,";
                else if (nowketasu * 0.25 == 17)
                    out += "muryoutaisuu,";
            }
        }

        return out;
    }
    std::string decimal_to_Nesora(const std::string& str) {
        std::string out, integer;

        size_t decimal_point = str.find(".");
        if (decimal_point == std::string::npos) return integer_to_Nesora(str);
        integer += str.substr(0, decimal_point);
        if (integer == "0")
            out += "rei";
        else {
            out += integer_to_Nesora(integer);

            if (str[decimal_point - 1] == '2')out += "i";
            if (str[decimal_point - 1] == '5')out += "o";
        }
        out += "tenn";
        if (str.size() - decimal_point > 2)out += ",";

        for (int i = 0;i < str.size() - decimal_point;i++) {
            switch (str[i + decimal_point + 1]) {
            case '0':
                out += "zero";
                break;
            case '1':
                out += "iti";
                break;
            case '2':
                out += "nii";
                break;
            case '3':
                out += "sann";
                break;
            case '4':
                out += "yonn";
                break;
            case '5':
                out += "goo";
                break;
            case '6':
                out += "roku";
                break;
            case '7':
                out += "nana";
                break;
            case '8':
                out += "hati";
                break;
            case '9':
                out += "kyuu";
                break;
            }

        }

        return out;
    }
    std::string power_to_Nesora(const std::string& str) {
        std::string out, mantissa, expoonent;

        size_t power_point = str.find("e");
        if (power_point == std::string::npos) return decimal_to_Nesora(str);
        mantissa += str.substr(0, power_point);
        expoonent += str.substr(power_point + 1);

        out += power_to_Nesora(mantissa);
        out += "kakeru,zyuuno";
        out += power_to_Nesora(expoonent);
        out += "zyou";

        return out;
    }
    std::string fraction_to_Nesora(const std::string& str) {
        std::string out, numerator, denominator;

        size_t line_point = str.find("/");
        if (line_point == std::string::npos) return power_to_Nesora(str);
        numerator += str.substr(0, line_point);
        denominator += str.substr(line_point + 1);

        out += power_to_Nesora(denominator);
        out += "bunnno,";
        out += power_to_Nesora(numerator);

        return out;
    }

}; // namespace ConvertHiragana