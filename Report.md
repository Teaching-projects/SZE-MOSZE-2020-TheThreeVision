# Tagok

| Név | Github azonosito  | Javasolt relatív érdemjegy | Becsült óra | Indoklás  | 
| --- | ---- | --- | ------------------ | --------- |
| Borbély Tamás | @borbelytomii | +1 | 50-60 | Projekt managerként ügyesen összefogta a csapatot.Szépen csinálta a dolgát, a rá kiadott feladatokat igyekezett a legrövidebb határidőn belül szépen megoldani ami többnyire sikerült is. Voltak részek amikben besegített magában a feladatokban, és volt ahol leginkább a hibakezelésekben vette ki a részét. A tananyaghoz kapcsolódó feladatok megoldását érti és átlátja valamint alkalmazni is tudja.A getTeamName csapatnak a bírálatok zömét ő csinálta.|
| Polócz Máté | @poloczmate | +1 | 50-60 | Mindent megcsinált,elvállalta a rábizott feladadokat, határidőn belül sikerült teljesítenie azokat.A hibakezelésekben is kivette a részét.Valamint a getTeamName csapatnak a bírálatokat Ő is csinálta. A google testek zömét Ő végezte el, azonban a többi részben is szintén kivette a maga részét a feladatok megoldása során. Így azokat ő is alkalmazni tudja. |
| Radvánszky István | @radvanszkyI | +1 | 50-60 | Mindent megcsinált,elvállalta a feladadokat,határidőn belül sikerült teljesítenie azokat .A hibakezelésekben is kivette a részét. A dokumentációt zömét Ő készítette el, a tananyag további részét is amit más végzett érdeklődően szemlélte , így alkalmazni is tudja azokat.  |

Megjegyzés: Az esetek 60-70%ában besegítettünk egymásnak, ha valaki nagyon elakadt.
Valamint kódok  bugfixelésében , memória szivárgás kezelésében is egyaránt igyekeztünk egymásnak segítséget nyújtani.
Ezért is ugyanannyi a becsült óraszám. 

# Videók

 - [Gameplay](/videos/gameplay.mp4)
 - [CodeBaseDefense](/videos/codebasedefense.mp4)

# Befejezett feladatok

| Feladat | Merge ideje a határidóhöz (nap) | Change request körök | Reviewer | 
| ------- | ------------------------------- | -------------------- | -------- |
| Feladat 1 | -2 | 2 | @oliverosz | 
| Feladat 2 | -1 | 2 | @wajzy |
| jsonparser | -7 | 3 | @wajzy |
| levelup | -4 | 1 | @oliverosz |
| attackspeed | -2 | 0 | @vizvezetek |
| documentation | -1 | 1 | @radvanszkyI/ @beszedics ,@kristofelo|
| unittest | -1 | 2 | @poloczmate /@AlmasiSzabolcs, @kristofelo |
| makefile | -1 | 1 | @hegyhati |
| refactor | 0 | 0 | @hegyhati |
| docker | -4 | 1 | @hegyhati |
| jsonpimp | Merge: 11.16 | 1 | @poloczmate /@AlmasiSzabolcs, @kristofelo |
| map | Merge: 11.22 | 0 | @radvanszkyI / @AlmasiSzabolcs |
| game | Merge: 12.02. | 0 | @borbelytomii/ @AlmasiSzabolcs |
| defense | Merge: 11.24 | 0 | @poloczmate /@AlmasiSzabolcs |
| damage | Merge: 11.24 | 0 | @poloczmate /@AlmasiSzabolcs  |
| markedmap | Merge: 12.03 | 0 | @poloczmate /@AlmasiSzabolcs |
| preparedgame | Merge: 12.03 | 0 |@poloczmate /@AlmasiSzabolcs|
| light radius | Merge: 12.03 | 0 | @radvanszkyI / @AlmasiSzabolcs  |
| rendering | Merge: 12.10 | ... |  @borbelytomii / @AlmasiSzabolcs |

# Unit tesztek

| Osztály | Publikus metódusok száma | Unit tesztelt metódusok száma | Unit tesztek száma |
| --- | --- | --- | --- |
| `Hero` | 24 | 16 | 7 | 
| `Game` | 10 | 0 | 0 |
| `JSON` | 9| 5 | 4 |
| `Map` | 7 | 2 | 2 |
| `Monster` | 13 | 8 | 4 |
| `MarkedMap` | 9 | 0 | 0 |


# Kód dokumentáció

| Teljesen dokumentált osztályok | Részben dokumentált osztályok | Nem dokumentált osztályok |
| --- | --- | --- | 
| `Hero` | ... | ... |  
| `Game` | ... | ... |
| `JSON` | ... | ... |
| `Damage` | ... | ... |
| `Map` | ... | ... | 
| `Monster` | ... | ... | 
| `SVGRenderer` | ... | ... |
| `TextRenderer` | ... | ... |
| `ObserverTextRenderer` | ... | ... |
| `HeroTextRenderer` | ... | ... |
| `ObserverSVGRenderer` | ... | ... |
| `CharacterSVGRenderer` | ... | ... |
| `Renderer` | ... | ... |   
| `MarkedMap` | ... | ... |
| `PreparedGame` | ... | ... | 



# Mindenféle számok

 - Összes cpp kódsor : 1213
 - Egyéb kódsor :
  - Dockerfile-ok: 18 
  - Makefile: 61
  - Python: 9
  - Doxconf:2613 
 - cppcheck
   - warning : 2
   - style : 30
   - performance : 14
   - unusedFunction : 4
   - missingInclude : 1
 
# Implicit megtanult dolgok
Olyanok, amik nem a tárgy anyaga, de muszáj/hasznos volt elsajátítani:
 - alapvető python scripting
 - `std::variant`
 - svg renderer

# Feedback (optional)
 
Melyik részt találtátok a leghasznosabbnak, miért?

- Számomra a dockeres rész volt igazán hasznos, mivel a virtualizáció engem nagyon érdekel.- B.T.
- Az egyik leghasznosabb számomra gites verziókezelés volt amit csináltam. -P.M.
- A git-es tananyag a legnélkülözhetettlenebb. -R.I

Használtátok-e az itt megszerzett dolgokat esetleg közben máskor?
- Még nem de biztosak vagyunk benne , hogy fogjuk tudni alkalmazni, az egyes projekteinkben.

Volt-e olyan, amit hiányoltatok a tárgyból?
- Semmit, igazán részletes volt a számunkra.

Utólag visszagondolva is jó volt-e az online videósdi?
- Számunkra igen, remek videók voltak, nagyon hasznosak amiket akár később is szívesen újranézünk.


# Üzenet a jövőbe (optional)

Így, hogy túlvagytok rajta, mi az, aminek örültetek volna, ha első héten elmondom, avagy: jövőre mit lenne jó, ha elmondanék majd?

- Sokat fogtok rajta melózni , azonban megéri mivel hasznos tudást szereztek, valamint az oopben tanultakat is tudjátok itt kamatoztatni.
