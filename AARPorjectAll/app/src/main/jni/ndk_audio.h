#include "common.h"


//#include <assert.h>
//#include <jni.h>
//#include <string.h>
#include <pthread.h>

// for native audio
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>

short TEMP_AUDIBLE_PILOT[] = {-453,676,-854,972,-1023,999,-903,739,-518,256,27,-310,570,-786,940,-1017,1009,-917,745,-508,225,79,-379,646,-854,985,-1023,965,-812,580,-289,-32,352,-638,859,-992,1021,-941,758,-492,170,172,-497,767,-950,1023,-976,813,-551,221,138,-482,767,-956,1024,-960,770,-478,121,254,-597,859,-1003,1008,-871,609,-258,-132,504,-804,984,-1018,896,-636,277,128,-514,819,-995,1010,-860,567,-178,-242,622,-898,1021,-966,741,-385,-42,463,-801,995,-1005,828,-496,68,375,-747,976,-1014,853,-522,85,371,-753,982,-1009,826,-468,11,451,-817,1008,-979,735,-327,-155,605,-919,1024,-894,556,-87,-404,800,-1008,973,-703,260,248,-696,973,-1006,785,-363,-153,631,-947,1016,-817,400,124,-617,945,-1015,807,-375,-163,656,-966,1003,-753,285,267,-742,1001,-965,642,-126,-430,857,-1024,877,-458,-104,635,-968,995,-704,187,392,-846,1024,-866,421,166,-698,997,-958,592,-22,-557,944,-1003,709,-164,-441,890,-1020,781,-257,-363,850,-1024,816,-303,-326,833,-1024,823,-304,-334,844,-1023,800,-259,-386,879,-1018,745,-168,-479,931,-998,650,-29,-606,986,-947,504,157,-752,1021,-845,297,383,-895,1009,-671,30,626,-998,915,-410,-285,849,-1018,710,-66,-611,998,-908,381,331,-884,1006,-635,-50,712,-1021,819,-205,-514,973,-937,420,314,-887,1000,-591,-130,783,-1023,718,-29,-677,1019,-809,157,582,-1002,870,-254,-505,982,-908,320,450,-965,928,-356,-422,957,-935,365,421,-959,929,-344,-447,972,-909,295,500,-991,873,-216,-576,1011,-814,106,670,-1023,726,36,-776,1017,-601,-206,880,-979,434,399,-968,894,-222,-600,1019,-749,-31,791,-1010,535,311,-942,918,-252,-592,1020,-727,-82,835,-991,435,435,-992,828,-59,-754,1013,-525,-354,970,-863,108,729,-1016,533,357,-975,846,-65,-767,1006,-461,-445,1003,-772,-69,857,-963,300,605,-1024,616,292,-964,849,-37,-806,984,-348,-579,1024,-611,-316,978,-812,-44,863,-945,215,701,-1012,445,510,-1021,637,308,-982,787,108,-908,896,-79,-810,967,-247,-699,1008,-392,-585,1023,-515,-473,1020,-614,-369,1006,-693,-277,985,-754,-199,962,-799,-136,940,-830,-90,923,-850,-61,913,-860,-48,910,-861,-53,914,-852,-74,926,-834,-112,944,-804,-167,966,-761,-238,989,-703,-323,1009,-627,-422,1022,-530,-530,1022,-411,-645,1002,-269,-759,956,-104,-864,878,81,-951,762,279,-1008,604,482,-1023,404,675,-985,168,843,-884,-95,965,-715,-368,1022,-480,-626,996,-189,-842,874,135,-984,655,461,-1022,349,748,-937,-15,949,-721,-393,1024,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

// this is near inaudible version
short NDK_AUDIO_PILOT_080_VOL[] = {0,38,-153,342,-604,935,-1333,1791,-2304,2866,-3468,4103,-4761,5431,-6102,6763,-7401,8002,-8552,9039,-9447,9762,-9971,10061,-10019,9836,-9500,9006,-8347,7521,-6529,5373,-4060,2600,-1008,-700,2502,-4375,6290,-8218,10127,-12020,13881,-15690,17429,-19075,20607,-22001,23236,-24287,25131,-25747,26113,-26210,26022,-25533,24734,-23618,22182,-20430,18371,-16019,13396,-10530,7455,-4213,851,2576,-6009,9384,-12635,15690,-18481,20937,-22992,24585,-25661,26174,-26089,25386,-24057,22113,-19580,16505,-12950,8998,-4747,310,4187,-8609,12815,-16665,20020,-22753,24751,-25921,26194,-25533,23933,-21423,18074,-13990,9312,-4213,-1109,6435,-11536,16182,-20152,23248,-25300,26184,-25826,24208,-21379,17448,-12590,7033,-1057,-5025,10883,-16182,20607,-23880,25780,-26162,24964,-22223,18074,-12748,6560,103,-6809,13107,-18554,22753,-25379,26210,-25146,22223,-17621,11652,-4747,-2576,9745,-16182,21349,-24793,26192,-25386,22399,-17448,10930,-3396,-4493,12020,-18481,23248,-25835,25951,-23539,18789,-12135,4213,4187,-12203,18986,-23794,26074,-25533,22182,-16344,8633,103,-8877,16665,-22532,25747,-25877,22855,-17001,8998,181,-9384,17429,-23248,26040,-25386,21319,-14337,5354,4416,-13617,20937,-25300,26031,-22968,16505,-7554,-2576,12363,-20300,25131,-26055,22867,-16019,6560,4009,-13968,21659,-25761,25533,-20953,12748,-2293,-8609,18037,-24287,26190,-23342,16202,-6034,-5304,15690,-23140,26184,-24179,17448,-7257,-4416,15253,-23054,26192,-23964,16764,-6034,-6009,16823,-24078,26162,-22558,13990,-2293,-9960,20020,-25579,25314,-19216,8633,4009,-15752,23794,-26163,22223,-12860,310,12363,-22001,26153,-23706,15211,-2781,-10412,20937,-26003,24208,-15958,3396,10127,-20937,26040,-23964,15211,-2165,-11536,22001,-26200,22855,-12860,-929,14488,-23794,26022,-20430,8633,5833,-18554,25579,-24665,16019,-2293,-12203,22842,-26162,21015,-8998,-6009,19075,-25835,23964,-14012,-722,15253,-24585,25443,-17448,3319,12020,-23140,26031,-19580,6034,9745,-22001,26190,-20686,7455,8609,-21468,26210,-20953,7628,8682,-21659,26194,-20430,6560,9960,-22532,26055,-19022,4213,12363,-23880,25516,-16505,542,15690,-25300,24128,-12590,-4416,19546,-26174,21319,-7033,-10412,23248,-25671,16505,181,-16823,25780,-22855,9312,8609,-22532,25856,-16922,-103,17118,-25839,21972,-7484,-10360,22683,-23512,12787,3728,-17545,21892,-15132,1375,11954,-18163,14729,-4308,-7083,13533,-12350,5141,3540,-9005,8967,-4423,-1404,5217,-5477,2909,386,-2450,2561,-1331,-52,741,-658,260,1,-29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


short NDK_AUDIO_PULSE_080_VOL[] = {0,-1,0,5,-12,13,0,-25,46,-42,2,59,-104,91,-9,-106,184,-160,25,161,-285,254,-55,-218,406,-375,106,271,-543,525,-187,-311,691,-707,305,327,-842,920,-468,-306,984,-1161,684,234,-1105,1423,-956,-97,1185,-1694,1287,-122,-1204,1956,-1671,433,1136,-2186,2098,-844,-959,2353,-2546,1358,646,-2421,2986,-1965,-180,2350,-3375,2642,-452,-2098,3662,-3354,1246,1629,-3784,4043,-2182,-917,3678,-4638,3215,-49,-3282,5051,-4275,1252,2544,-5184,5263,-2641,-1439,4942,-6056,4126,-25,-4241,6515,-5576,1791,3030,-6496,6822,-3744,-1309,5876,-7669,5710,-857,-4572,7914,-7458,3319,2573,-7381,8720,-5842,36,5954,-9222,8116,-3056,-3616,8726,-9778,6168,488,-7082,10466,-8955,3152,4287,-9878,10939,-6870,-527,7848,-11660,10105,-3799,-4417,10760,-12247,8095,-113,-8090,12737,-11627,5162,3797,-11199,13640,-9921,1625,7566,-13507,13459,-7344,-2185,10904,-14894,12293,-4161,-5964,13610,-15346,10316,-644,-9469,15576,-14938,7739,2958,-12527,16781,-13799,4781,6440,-15038,17269,-12093,1645,9652,-16970,17135,-9994,-1495,12498,-18343,16501,-7668,-4506,14932,-19217,15502,-5262,-7291,16952,-19677,14271,-2899,-9793,18585,-19822,12934,-675,-11983,19878,-19754,11599,1338,-13855,20891,-19568,10360,3090,-15419,21687,-19354,9293,4544,-16690,22326,-19185,8458,5678,-17689,22857,-19125,7904,6472,-18430,23320,-19218,7668,6909,-18919,23740,-19497,7778,6974,-19152,24122,-19976,8252,6645,-19112,24456,-20652,9100,5901,-18768,24708,-21502,10320,4719,-18074,24825,-22483,11894,3079,-16975,24733,-23526,13785,969,-15411,24337,-24534,15931,-1607,-13319,23526,-25385,18237,-4620,-10648,22183,-25926,20572,-8006,-7369,20186,-25985,22764,-11653,-3490,17432,-25374,24600,-15394,926,13853,-23908,25834,-19002,5748,9434,-21424,26205,-22195,10764,4248,-17831,25474,-24661,15689,-1545,-13094,23414,-26043,20144,-7673,-7286,19861,-25980,23682,-13736,-627,14773,-24165,25811,-19209,6491,8278,-20406,26060,-23475,13494,721,-14695,24054,-25889,19653,-7311,-7286,19613,-25868,24145,-15000,1262,12848,-23019,26166,-21355,10071,4248,-17270,25075,-25337,18000,-5287,-8992,20577,-26037,23773,-14481,927,12886,-22899,26193,-21827,11100,2845,-15949,24420,-25827,19788,-8066,-5957,18261,-25337,25188,-17881,5513,8400,-19929,25834,-24479,16267,-3518,-10198,21062,-26070,23855,-15056,2118,11387,-21755,26162,-23425,14316,-1330,-12002,22075,-26188,23254,-14085,1159,12063,-22057,26181,-23364,14374,-1604,-11572,21698,-26133,23740,-15168,2665,10513,-20959,25989,-24328,16428,-4333,-8854,19772,-25654,25030,-18081,6583,6558,-18038,24991,-25701,20012,-9362,-3595,15647,-23830,26147,-22052,12570,-34,-12495,21978,-26131,23971,-16044,4274,8506,-19238,25374,-25472,19533,-8984,-3671,15447,-23585,26196,-22692,13911,-1913,-10513,20497,-25749,25080,-18669,8001,4477,-15921,23744,-26190,22730,-14165,2435,9825,-19878,25498,-25456,19783,-9753,-2409,14027,-22562,26162,-24064,16747,-5815,-6358,17147,-24241,26137,-22452,13991,-2572,-9378,19331,-25202,25774,-20949,11757,-129,-11510,20751,-25696,25343,-19788,10190,1476,-12826,21557,-25913,25033,-19115,9370,2238,-13383,21851,-25971,24947,-19003,9329,2161,-13213,21673,-25908,25113,-19464,10071,1244,-12306,21000,-25682,25478,-20449,11564,-515,-10615,19743,-25173,25911,-21841,13736,-3109,-8074,17762,-24189,26198,-23445,16448,-6491,-4621,14887,-22474,26040,-24968,19470,-10537,-240,10960,-19743,25065,-26015,22447,-15000,4975,5890,-15730,22866,-26095,24886,-19464,10764,-266,-10261,19056,-24661,26159,-23321,16635,-7220,-3365,13383,-21204,25566,-25779,21827,-14367,4612,5865,-15391,22456,-25952,25343,-20746,12901,-3050,-7262,16428,-23036,26077,-25100,20276,-12359,2572,7591,-16588,23069,-26070,25159,-20492,12781,-3186,-6865,15887,-22562,25922,-25494,21360,-14136,4882,5059,-14259,21404,-25488,25946,-22730,16314,-7616,-2135,11572,-19383,24494,-26212,24319,-19092,11263,-1913,-7681,16220,-22557,25853,-25682,22085,-15558,6981,2503,-11641,19238,-24309,26208,-24705,20012,-12751,3867,5497,-14143,20980,-25152,26147,-23859,18590,-11014,2084,7088,-15370,21750,-25458,26055,-23487,18081,-10505,1682,7328,-15447,21717,-25406,26093,-23715,18566,-11263,2665,6225,-14381,20871,-24963,26203,-24467,19968,-13228,5017,3739,-12063,19033,-23887,26104,-25456,22029,-16213,8652,-172,-8311,15887,-21755,25301,-26163,24267,-19828,13324,-5446,-2981,11084,-18031,23117,-25834,25921,-23383,18493,-11757,3858,4409,-12222,18813,-23540,25952,-25827,23194,-18322,11695,-3960,-4138,11826,-18377,23182,-25799,25997,-23773,19349,-13146,5748,2161,-9857,16641,-21907,25190,-26208,24886,-21355,15942,-9137,1545,6166,-13324,19314,-23626,25902,-25961,23813,-19653,13846,-6890,-627,8074,-14837,20362,-24205,26062,-25797,23445,-19209,13442,-6616,-721,7984,-14603,20062,-23944,25958,-25961,23968,-20144,14795,-8335,1262,5890,-12585,18328,-22700,25389,-26208,25113,-22195,17679,-11902,5287,1690,-8530,14752,-19923,23689,-25799,26118,-24638,21473,-16853,11100,-4612,-2170,8790,-14809,19833,-23540,25696,-26172,24950,-22122,17881,-12510,6358,180,-6691,12766,-18031,22168,-24928,26156,-25786,23855,-20492,15908,-10387,4265,2093,-8311,14027,-18914,22696,-25164,26188,-25721,23802,-20550,16159,-10882,5017,1107,-7154,12796,-17730,21698,-24494,25981,-26091,24828,-22272,18566,-13911,8555,-2776,-3126,8854,-14122,18669,-22277,24776,-26052,26055,-24795,22344,-18831,14431,-9362,3867,1793,-7352,12555,-17166,20980,-23830,25598,-26213,25659,-23971,21234,-17578,13169,-8205,2905,2503,-7788,12728,-17121,20788,-23585,25406,-26185,25901,-24576,22272,-19092,15168,-10663,5757,-644,-4477,9409,-13967,17982,-21308,23829,-25459,26148,-25881,24678,-22593,19711,-16144,12025,-7506,2750,2077,-6807,11280,-15348,18878,-21759,23905,-25254,25773,-25455,24322,-22422,19826,-16625,12929,-8858,4545,-125,-4266,8496,-12441,15987,-19036,21506,-23335,24480,-24918,24650,-23694,22088,-19887,17162,-13997,10485,-6726,2825,1113,-4982,8684,-12125,15222,-17903,20108,-21790,22917,-23473,23454,-22872,21753,-20133,18061,-15594,12798,-9744,6507,-3164,-207,3531,-6735,9752,-12520,14985,-17102,18832,-20149,21035,-21480,21487,-21065,20232,-19016,17448,-15568,13420,-11052,8513,-5857,3134,-399,-2300,4915,-7399,9714,-11821,13691,-15296,16617,-17638,18351,-18753,18845,-18634,18133,-17357,16327,-15066,13600,-11959,10172,-8270,6286,-4251,2196,-152,-1852,3789,-5634,7364,-8959,10402,-11678,12775,-13686,14403,-14925,15252,-15385,15330,-15094,14686,-14117,13399,-12547,11576,-10500,9336,-8100,6809,-5480,4127,-2768,1417,-87,-1208,2455,-3645,4767,-5812,6774,-7646,8424,-9104,9683,-10160,10536,-10811,10987,-11066,11053,-10951,10765,-10501,10164,-9760,9297,-8780,8216,-7612,6974,-6310,5625,-4926,4218,-3509,2802,-2103,1417,-748,99,525,-1121,1688,-2223,2723,-3188,3616,-4006,4358,-4672,4948,-5186,5388,-5553,5684,-5780,5844,-5878,5882,-5859,5810,-5737,5642,-5528,5395,-5245,5082,-4905,4718,-4521,4317,-4107,3893,-3675,3456,-3236,3017,-2800,2585,-2374,2167,-1966,1770,-1581,1398,-1223,1055,-895,742,-598,463,-335,216,-105,2,92,-179,259,-330,395,-453,504,-548,587,-619,647,-668,685,-698,706,-710,710,-707,701,-692,680,-666,650,-632,612,-591,569,-546,522,-497,472,-447,421,-396,370,-345,320,-296,272,-249,226,-205,184,-164,145,-127,110,-94,79,-66,53,-42,32,-24,17,-11,6,-3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


