# 音諳零号機二型
音諳零号機二型です。
私が足立レイに触発されて作った合成音声ライブラリのテスト版です。

Nesora_for_embedded_systemsのディレクトリの中にあるやつが組み込み用の本体。

Visual studio 2019 のプロジェクトファイルごとｴｲ!しちゃったからいろいろ余計なものがあると思うけど、気にしないでね。

## うさげ
使い方です。
ライブラリは以下のコードのようにヘッダーファイルを呼び出して使います。
```
#include "Nesora_for_embedded_systems/Nesora/Nesora_for_embedded_systems.h"
```

まあ、Example見てもらった方が早いと思いますが、基本的に以下のようにインスタンスにして使います。
```
Nesora::makeVoiseFromFile MVFF;
```

以下のコードで使う声を選択
```
MVFF.setDefaulFurin();
```

以下の関数でしゃべらせたいセリフを渡して
```
MVFF.textread("konnnitiwaa");
```

以下の関数で波形を生成します。
```
std::vector<nsfloat> wave = MVFF.textreading();
```

-1~1の範囲で出力されますので、煮るなり焼くなりしてください。

## 音諳書式
セリフの書き方です。

基本的にローマ字で入力します。
ひらがなを使う場合は、Normalization_to_Nesora::hiraganaToRomaji()を使って、UTF-8で渡してください。

ひらがなを使っている場合、「、」で一文字分の休符、「。」で二文字分の休符になります。
ローマ字で書かれている場合には、「,」で一文字分の休符、「.」で二文字分の休符になります。


続いて、声の高さや速さについて説明します。
とはいっても難しいことはなく、基本的にxmlみたいなものです。

基本的に平仮名(あるいはローマ字)で書かれた台本の文字と文字の間にタグを挟むイメージです。
タグは以下の二つ
```
<s> ...速さの制御
<p> ...高さの制御
```
### 速さの制御
```<sxx>```のxxの部分に時間を指定してあげると、それ以降、一文字をその長さで話すようになります。単位は[cs](センチ秒 = 0.01s)です。
```<s20>```とすれば、それ以降、一文字を0.2秒の長さでしゃべるようになります。
初期値は0.25秒です。(```<s25>```)

### 高さの制御
```<p±xx>```の±xx部分に、相対的な周波数値を符号付きで入力することで声の高さを変えることができます。単位は[Hz]、基準値は使っている声の基底周波数です。
基底周波数は声によって異なり、風鈴の場合440Hz(A4)、詞音の場合392Hz(G4)です。
風鈴を使っている場合、```<p+54>```で494Hz(B4)、```<p-48>```で392Hz(G4)になります。
初期値は+0Hzです。(```<p+0>```)

また、```<pu>```や```<pd>```などを使うことで、10Hzごとに変移さえることもできます。
```<pu>```で10Hz上がり、```<pd>```で10Hz下がります。

### ---以下追記---

高さの制御に新しい機能が付きました。
まず、読ませたい文章の最初に```<bf>```タグを挿入します。```<bf>```タグには、使っている声の基底周波数を渡す機能があります。
```<bf440>```で風鈴、```<bf392>```で詞音の基底周波数になります。

そして、このタグを使った後では、高さの制御を絶対的な周波数値を入力できるようになります。絶対的な周波数で入力するには、```<p>```タグの符号をなくします。
以下の例では、どちらも262Hz(C4)の音で「あ」といいます。

```
風鈴の声で "<bf440><p262>a"
詞音の声で "<bf392><p262>a"
```

上の例は、それぞれ以下のようにしたものと同義です。

```
風鈴の声で "<p-178>a"
詞音の声で "<p-130>a"
```

このタグがあることで、歌声の変更が比較的簡単になります。
ローマ字の茶摘みの歌で使っているので、見てみてください。

---追記ここまで---

これらのタグを使って台本を作ることになります。

半角括弧()で囲まれた部分はコメントになり、実際の読み上げ時には反映されません。

## 例

以下、茶摘の歌の例です。
```
//平仮名
makeVoiseFromFile MVFF;
MVFF.setDefaulFurin();
MVFF.textread(Normalization_to_Nesora::hiraganaToRomaji(u8"(茶摘　文部省唱歌　尋常小学校唱歌　三学年用)(一番)<s60>、<p-48>な<p+83>つ<p+147>も<s90><p+219>ち<s30>か<s60>づく<s90><p+344>は<s30>ち<s60>じゅ<p+219>う<p+147>は<p+83>ち<p+147>や、、<p+344>のに<p+219>も<s90><p+147>や<s30>ま<s60><p+83>に<p+0>も<s90><p+219>わ<s30>か<s60><p+147>ば<p+83>が<p+0>しげ<p-48>る、、あ<p+83>れ<p+147>に<s90><p+219>み<s30>え<s60>るわ<s90><p+344>ちゃ<s30>つ<s60>み<p+219>じゃ<p+147>な<p+83>い<p+147>か、、<p+344>あか<p+219>ね<s90><p+147>だ<s30>す<s60><p+83>き<p+0>に<p-48>す<p+83>げ<s90><p+147>の<s30><p+219>か<s180><p+83>さ<s60>、、(二番)<p-48>ひ<p+83>よ<p+147>り<s90><p+219>つ<s30>づ<s60>きの<s90><p+344>きょ<s30>う<s60>こ<p+219>の<p+147>ご<p+83>ろ<p+147>を、、<p+344>ここ<p+219>ろ<s90><p+147>の<s30>ど<s60><p+83>か<p+0>に<s90><p+219>つ<s30>み<s60><p+147>つ<p+83>つ<p+0>うた<p-48>う、、つ<p+83>め<p+147>よ<s90><p+219>つ<s30>め<s60>つめ<s90><p+344>つ<s30>ま<s60>ね<p+219>ば<p+147>な<p+83>ら<p+147>ぬ、、<p+344>つま<p+219>にゃ<s90><p+147>に<s30>ほ<s60><p+83>ん<p+0>の<p-48>ちゃ<p+83>に<s90><p+147>な<s30><p+219>ら<s180><p+83>ぬ<s60>、"));
std::vector<nsfloat> wave = MVFF.textreading();
```
```
//ローマ字
makeVoiseFromFile MVFF;
MVFF.setDefaulFurin();
MVFF.textread("(Chatumi - Monbusho shoka for third year of elementary school)(1)<bf440><s60>,<p392>Na<p523>tu<p587>mo<s90><p659>ti<s30>ka<s60>duku<s90><p784>ha<s30>ti<s60>zu<p659>u<p587>ha<p523>ti<p587>ya,,<p784>noni<p659>mo<s90><p587>ya<s30>ma<s60><p523>ni<p440>mo<s90><p659>wa<s30>ka<s60><p587>ba<p523>ga<p440>sige<p392>ru,,a<p523>re<p587>ni<s90><p659>mi<s30>e<s60>ruwa<s90><p784>tya<s30>tu<s60>mi<p659>zya<p587>na<p523>i<p587>ka,,<p784>aka<p659>ne<s90><p587>da<s30>su<s60><p523>ki<p440>ni<p392>su<p523>ge<s90><p587>no<s30><p659>ka<s180><p523>sa<s60>,,(2)<p392>hi<p523>yo<p587>ri<s90><p659>tu<s30>du<s60>kino<s90><p784>kyo<s30>u<s60>ko<p659>no<p587>go<p523>ro<p587>wo,,<p784>koko<p659>ro<s90><p587>no<s30>do<s60><p523>ka<p440>ni<s90><p659>tu<s30>mi<s60><p587>tu<p523>tu<p440>uta<p392>u,,tu<p523>me<p587>yo<s90><p659>tu<s30>me<s60>tume<s90><p784>tu<s30>ma<s60>ne<p659>ba<p587>na<p523>ra<p587>nu,,<p784>tuma<p659>nya<s90><p587>ni<s30>ho<s60><p523>nn<p440>no<p392>tya<p523>ni<s90><p587>na<s30><p659>ra<s180><p523>nu<s60>,");
std::vector<nsfloat> wave = MVFF.textreading();
```

次に、銀河鉄道の夜の冒頭部分の例です。
```
//平仮名
makeVoiseFromFile MVFF;
MVFF.setDefaulFurin();
MVFF.textread(Normalization_to_Nesora::hiraganaToRomaji(u8"<s17>ぎ<pu>んがてつ<pd>どうの<pu>よ<pd>る。。<pu>で<pd>わみ<pu>な<pd>さんわ、そ<pu>ういうふ<pd>うにか<pu>わ<pd>だとい<pu>われた<pd>り、<pu>ちち<pd>のな<pu>が<pd>れた<pu>あと<pd>だとい<pu>われた<pd>りし<pu>ていた<pd>こ<pu>の<pd>ぼ<pu>んや<pd>りとし<pu>ろ<pd>いも<pu>の<pd>が、ほ<pu>んとうわな<pd>にかご<pu>しょうちで<pd>す<pu>か。<pd>せ<pu>んせ<pd>いわ、こ<pu>くばんにつるしたおお<pd>きなく<pu>ろ<pd>いせ<pu>いざのずの、<pd>う<pu>えからしたえし<pd>ろくけ<pu>ぶっ<pd>た<pu>ぎんが<pd>おびの<pu>よう<pd>なと<pu>ころ<pd>をさ<pu>しな<pd>がら、み<pu>んな<pd>にと<pu>い<pd>をか<pu>けま<pd>した。か<pu>んぱね<pd>るらが<pu>て<pd>をあ<pu>げま<pd>した。そ<pu>れから、<pd>し<pu>ごにんて<pd>をあ<pu>げま<pd>した。じょ<pu>ばん<pd>にも<pu>て<pd>をあ<pu>げようとして、<pd>い<pu>そい<pd>でそ<pu>のまま<pd>や<pu>めま<pd>した。<pu>たし<pd>かにあ<pu>れが<pd>み<pu>んな<pd>ほ<pu>しだ<pd>と、<pu>い<pd>つかざっ<pu>しでよん<pd>だのでしたが、こ<pu>のごろわ<pd>じょ<pu>ばん<pd>にわ、ま<pu>るでまい<pd>にちきょ<pu>うしつで<pd>もね<pu>むく、ほん<pd>を<pu>よ<pd>むひ<pu>まもよ<pd>む<pu>ほん<pd>も<pu>ない<pd>ので、<pu>なん<pd>だか<pu>どん<pd>なこ<pu>と<pd>も<pu>よ<pd>くわ<pu>から<pd>ないというき<pu>もちがするの<pd>でした。"));
std::vector<nsfloat> wave = MVFF.textreading();
```
```
//ローマ字
makeVoiseFromFile MVFF;
MVFF.setDefaulFurin();
MVFF.textread("<s17>gi<pu>nngatetu<pd>douno<pu>yo<pd>ru...<pu>de<pd>wami<pu>na<pd>sannwa,so<pu>uiuhu<pd>unika<pu>wa<pd>datoi<pu>wareta<pd>ri,<pu>titi<pd>nona<pu>ga<pd>reta<pu>ato<pd>datoi<pu>wareta<pd>risi<pu>teita<pd>ko<pu>no<pd>bo<pu>nnya<pd>ritosi<pu>ro<pd>imo<pu>no<pd>ga,ho<pu>nntouwana<pd>nikago<pu>syoutide<pd>su<pu>ka.<pd>se<pu>nnse<pd>iwa,ko<pu>kubannniturusitaoo<pd>kinaku<pu>ro<pd>ise<pu>izanozuno,<pd>u<pu>ekarasitaesi<pd>rokuke<pu>bu,<pd>ta<pu>ginnga<pd>obino<pu>you<pd>nato<pu>koro<pd>wosa<pu>sina<pd>gara,mi<pu>nnna<pd>nito<pu>i<pd>woka<pu>kema<pd>sita.ka<pu>nnpane<pd>ruraga<pu>te<pd>woa<pu>gema<pd>sita.so<pu>rekara,<pd>si<pu>goninnte<pd>woa<pu>gema<pd>sita.zyo<pu>bann<pd>nimo<pu>te<pd>woa<pu>geyoutosite,<pd>i<pu>soi<pd>deso<pu>nomama<pd>ya<pu>mema<pd>sita.<pu>tasi<pd>kania<pu>rega<pd>mi<pu>nnna<pd>ho<pu>sida<pd>to,<pu>i<pd>tukaza,<pu>sideyonn<pd>danodesitaga,ko<pu>nogorowa<pd>zyo<pu>bann<pd>niwa,ma<pu>rudemai<pd>nitikyo<pu>usitude<pd>mone<pu>muku,honn<pd>wo<pu>yo<pd>muhi<pu>mamoyo<pd>mu<pu>honn<pd>mo<pu>nai<pd>node,<pu>nann<pd>daka<pu>donn<pd>nako<pu>to<pd>mo<pu>yo<pd>kuwa<pu>kara<pd>naitoiuki<pu>motigasuruno<pd>desita.");
std::vector<nsfloat> wave = MVFF.textreading();
```

そんな感じ。


## 声
最後に声の種類だけ書いておきます。

これが音諳 風鈴
```
MVFF.setDefaulFurin();
```

そしてこれが音諳 詞音
```
MVFF.setShion();
```

いまのところ二人だけです。
仲良くしてあげてくださいね。
以上！
