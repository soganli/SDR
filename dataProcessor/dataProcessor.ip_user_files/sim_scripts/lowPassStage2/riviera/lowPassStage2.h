
//------------------------------------------------------------------------------
// (c) Copyright 2014 Xilinx, Inc. All rights reserved.
//
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
//
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
//
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
//
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
//------------------------------------------------------------------------------ 
//
// C Model configuration for the "lowPassStage2" instance.
//
//------------------------------------------------------------------------------
//
// coefficients: -1,-1,-1,-1,-1,-2,-2,-2,-2,-3,-3,-4,-4,-4,-5,-5,-6,-6,-7,-8,-8,-9,-10,-10,-11,-12,-13,-14,-15,-16,-17,-18,-20,-21,-22,-24,-25,-27,-28,-30,-32,-34,-36,-38,-40,-42,-44,-47,-49,-52,-55,-57,-60,-63,-66,-69,-73,-76,-80,-83,-87,-91,-95,-99,-103,-107,-112,-117,-121,-126,-131,-136,-142,-147,-152,-158,-164,-170,-176,-182,-189,-195,-202,-209,-216,-223,-230,-238,-245,-253,-261,-269,-277,-285,-294,-302,-311,-320,-329,-338,-347,-357,-366,-376,-386,-396,-406,-416,-426,-436,-447,-457,-468,-479,-490,-501,-512,-523,-534,-545,-556,-567,-579,-590,-602,-613,-624,-636,-647,-659,-670,-681,-693,-704,-715,-727,-738,-749,-760,-771,-781,-792,-802,-813,-823,-833,-843,-852,-862,-871,-880,-889,-897,-906,-914,-921,-929,-936,-942,-949,-955,-960,-966,-970,-975,-979,-982,-985,-988,-990,-991,-992,-993,-993,-992,-991,-989,-987,-983,-980,-975,-970,-964,-958,-950,-942,-933,-924,-913,-902,-890,-877,-863,-849,-833,-817,-799,-781,-762,-742,-720,-698,-675,-651,-626,-599,-572,-544,-514,-484,-452,-419,-385,-350,-314,-277,-238,-198,-158,-116,-72,-28,18,65,113,162,213,264,317,372,427,484,542,601,662,724,787,851,917,984,1052,1121,1191,1263,1336,1410,1486,1563,1640,1719,1800,1881,1964,2048,2132,2219,2306,2394,2483,2574,2665,2758,2852,2946,3042,3138,3236,3335,3434,3534,3636,3738,3841,3944,4049,4154,4260,4367,4475,4583,4692,4801,4911,5022,5133,5244,5356,5469,5582,5695,5809,5923,6037,6151,6266,6381,6496,6611,6726,6842,6957,7072,7187,7302,7417,7532,7647,7761,7875,7989,8102,8215,8328,8440,8552,8663,8773,8883,8992,9101,9209,9316,9422,9528,9632,9736,9839,9940,10041,10141,10239,10337,10433,10528,10622,10714,10806,10896,10984,11071,11157,11241,11324,11406,11485,11563,11640,11715,11788,11860,11929,11997,12064,12128,12191,12251,12310,12367,12422,12476,12527,12576,12623,12668,12712,12753,12792,12829,12863,12896,12927,12955,12982,13006,13028,13048,13065,13081,13094,13105,13114,13120,13125,13127,13127,13125,13120,13114,13105,13094,13081,13065,13048,13028,13006,12982,12955,12927,12896,12863,12829,12792,12753,12712,12668,12623,12576,12527,12476,12422,12367,12310,12251,12191,12128,12064,11997,11929,11860,11788,11715,11640,11563,11485,11406,11324,11241,11157,11071,10984,10896,10806,10714,10622,10528,10433,10337,10239,10141,10041,9940,9839,9736,9632,9528,9422,9316,9209,9101,8992,8883,8773,8663,8552,8440,8328,8215,8102,7989,7875,7761,7647,7532,7417,7302,7187,7072,6957,6842,6726,6611,6496,6381,6266,6151,6037,5923,5809,5695,5582,5469,5356,5244,5133,5022,4911,4801,4692,4583,4475,4367,4260,4154,4049,3944,3841,3738,3636,3534,3434,3335,3236,3138,3042,2946,2852,2758,2665,2574,2483,2394,2306,2219,2132,2048,1964,1881,1800,1719,1640,1563,1486,1410,1336,1263,1191,1121,1052,984,917,851,787,724,662,601,542,484,427,372,317,264,213,162,113,65,18,-28,-72,-116,-158,-198,-238,-277,-314,-350,-385,-419,-452,-484,-514,-544,-572,-599,-626,-651,-675,-698,-720,-742,-762,-781,-799,-817,-833,-849,-863,-877,-890,-902,-913,-924,-933,-942,-950,-958,-964,-970,-975,-980,-983,-987,-989,-991,-992,-993,-993,-992,-991,-990,-988,-985,-982,-979,-975,-970,-966,-960,-955,-949,-942,-936,-929,-921,-914,-906,-897,-889,-880,-871,-862,-852,-843,-833,-823,-813,-802,-792,-781,-771,-760,-749,-738,-727,-715,-704,-693,-681,-670,-659,-647,-636,-624,-613,-602,-590,-579,-567,-556,-545,-534,-523,-512,-501,-490,-479,-468,-457,-447,-436,-426,-416,-406,-396,-386,-376,-366,-357,-347,-338,-329,-320,-311,-302,-294,-285,-277,-269,-261,-253,-245,-238,-230,-223,-216,-209,-202,-195,-189,-182,-176,-170,-164,-158,-152,-147,-142,-136,-131,-126,-121,-117,-112,-107,-103,-99,-95,-91,-87,-83,-80,-76,-73,-69,-66,-63,-60,-57,-55,-52,-49,-47,-44,-42,-40,-38,-36,-34,-32,-30,-28,-27,-25,-24,-22,-21,-20,-18,-17,-16,-15,-14,-13,-12,-11,-10,-10,-9,-8,-8,-7,-6,-6,-5,-5,-4,-4,-4,-3,-3,-2,-2,-2,-2,-1,-1,-1,-1,-1,6,6,7,8,9,10,10,11,12,13,14,15,17,18,19,20,21,23,24,25,27,28,30,31,33,34,36,37,39,41,42,44,46,48,49,51,53,55,56,58,60,62,64,65,67,69,71,72,74,76,77,79,80,82,83,85,86,87,88,90,91,91,92,93,94,94,95,95,95,95,95,95,94,94,93,92,91,90,88,87,85,83,80,78,75,72,69,66,62,58,54,50,45,40,35,29,23,17,11,4,-3,-11,-18,-26,-35,-43,-52,-62,-72,-82,-92,-103,-114,-126,-137,-150,-162,-175,-188,-202,-216,-230,-245,-260,-276,-291,-307,-324,-341,-358,-375,-393,-411,-430,-448,-467,-487,-506,-526,-546,-567,-588,-609,-630,-651,-673,-695,-717,-739,-761,-783,-806,-829,-852,-874,-897,-920,-943,-967,-990,-1013,-1036,-1058,-1081,-1104,-1127,-1149,-1171,-1193,-1215,-1237,-1258,-1279,-1300,-1320,-1340,-1360,-1379,-1398,-1416,-1434,-1452,-1468,-1484,-1500,-1515,-1529,-1543,-1556,-1568,-1579,-1589,-1599,-1608,-1615,-1622,-1628,-1633,-1637,-1640,-1642,-1642,-1642,-1640,-1637,-1633,-1628,-1621,-1613,-1604,-1593,-1581,-1568,-1553,-1536,-1518,-1499,-1478,-1455,-1431,-1405,-1377,-1348,-1317,-1284,-1250,-1213,-1175,-1136,-1094,-1050,-1005,-958,-909,-858,-805,-750,-693,-634,-573,-510,-446,-379,-310,-239,-167,-92,-15,64,144,227,312,399,488,579,671,766,863,962,1062,1165,1270,1376,1484,1595,1707,1821,1936,2054,2173,2294,2417,2541,2668,2795,2925,3056,3188,3322,3458,3594,3733,3872,4013,4155,4299,4444,4589,4736,4884,5033,5183,5334,5486,5638,5792,5946,6100,6256,6412,6568,6725,6882,7039,7197,7355,7513,7671,7830,7988,8146,8304,8462,8619,8776,8933,9089,9245,9400,9555,9709,9862,10014,10165,10315,10465,10613,10760,10906,11050,11193,11335,11476,11614,11752,11887,12021,12153,12283,12412,12538,12663,12785,12905,13023,13139,13253,13364,13473,13580,13684,13785,13884,13981,14074,14165,14254,14339,14422,14502,14579,14653,14724,14792,14857,14919,14978,15033,15086,15135,15182,15225,15265,15301,15334,15364,15391,15415,15435,15451,15465,15475,15482,15485,15485,15482,15475,15465,15451,15435,15415,15391,15364,15334,15301,15265,15225,15182,15135,15086,15033,14978,14919,14857,14792,14724,14653,14579,14502,14422,14339,14254,14165,14074,13981,13884,13785,13684,13580,13473,13364,13253,13139,13023,12905,12785,12663,12538,12412,12283,12153,12021,11887,11752,11614,11476,11335,11193,11050,10906,10760,10613,10465,10315,10165,10014,9862,9709,9555,9400,9245,9089,8933,8776,8619,8462,8304,8146,7988,7830,7671,7513,7355,7197,7039,6882,6725,6568,6412,6256,6100,5946,5792,5638,5486,5334,5183,5033,4884,4736,4589,4444,4299,4155,4013,3872,3733,3594,3458,3322,3188,3056,2925,2795,2668,2541,2417,2294,2173,2054,1936,1821,1707,1595,1484,1376,1270,1165,1062,962,863,766,671,579,488,399,312,227,144,64,-15,-92,-167,-239,-310,-379,-446,-510,-573,-634,-693,-750,-805,-858,-909,-958,-1005,-1050,-1094,-1136,-1175,-1213,-1250,-1284,-1317,-1348,-1377,-1405,-1431,-1455,-1478,-1499,-1518,-1536,-1553,-1568,-1581,-1593,-1604,-1613,-1621,-1628,-1633,-1637,-1640,-1642,-1642,-1642,-1640,-1637,-1633,-1628,-1622,-1615,-1608,-1599,-1589,-1579,-1568,-1556,-1543,-1529,-1515,-1500,-1484,-1468,-1452,-1434,-1416,-1398,-1379,-1360,-1340,-1320,-1300,-1279,-1258,-1237,-1215,-1193,-1171,-1149,-1127,-1104,-1081,-1058,-1036,-1013,-990,-967,-943,-920,-897,-874,-852,-829,-806,-783,-761,-739,-717,-695,-673,-651,-630,-609,-588,-567,-546,-526,-506,-487,-467,-448,-430,-411,-393,-375,-358,-341,-324,-307,-291,-276,-260,-245,-230,-216,-202,-188,-175,-162,-150,-137,-126,-114,-103,-92,-82,-72,-62,-52,-43,-35,-26,-18,-11,-3,4,11,17,23,29,35,40,45,50,54,58,62,66,69,72,75,78,80,83,85,87,88,90,91,92,93,94,94,95,95,95,95,95,95,94,94,93,92,91,91,90,88,87,86,85,83,82,80,79,77,76,74,72,71,69,67,65,64,62,60,58,56,55,53,51,49,48,46,44,42,41,39,37,36,34,33,31,30,28,27,25,24,23,21,20,19,18,17,15,14,13,12,11,10,10,9,8,7,6,6,14,16,18,20,23,25,28,30,33,36,39,42,46,49,53,56,60,64,69,73,78,82,87,92,97,103,108,114,119,125,132,138,144,151,158,164,171,179,186,193,201,209,217,224,233,241,249,258,266,275,284,292,301,310,319,328,337,347,356,365,374,384,393,402,411,421,430,439,448,457,466,475,483,492,500,509,517,525,532,540,547,554,561,568,574,580,586,592,597,602,606,610,614,617,620,622,624,626,627,628,628,627,626,625,623,620,617,613,609,604,598,592,585,578,569,560,551,540,529,517,505,491,477,463,447,431,414,396,377,358,337,316,295,272,249,225,200,174,147,120,92,63,34,3,-28,-60,-92,-125,-159,-194,-229,-265,-302,-339,-377,-416,-455,-494,-534,-575,-616,-658,-700,-742,-785,-828,-872,-916,-960,-1004,-1049,-1094,-1139,-1184,-1229,-1274,-1319,-1364,-1409,-1454,-1499,-1543,-1588,-1632,-1676,-1719,-1762,-1805,-1847,-1888,-1929,-1969,-2009,-2048,-2086,-2123,-2159,-2195,-2229,-2263,-2295,-2327,-2357,-2386,-2413,-2440,-2465,-2488,-2510,-2531,-2550,-2567,-2583,-2597,-2609,-2619,-2628,-2634,-2639,-2642,-2642,-2641,-2637,-2631,-2623,-2613,-2600,-2585,-2568,-2548,-2526,-2501,-2474,-2444,-2412,-2377,-2339,-2298,-2255,-2209,-2161,-2109,-2055,-1998,-1937,-1875,-1809,-1740,-1668,-1594,-1516,-1435,-1352,-1265,-1176,-1083,-988,-889,-788,-684,-576,-466,-353,-237,-117,5,130,257,388,521,658,797,938,1083,1230,1379,1532,1687,1844,2004,2166,2331,2497,2667,2838,3012,3187,3365,3545,3727,3910,4095,4283,4471,4662,4854,5047,5242,5438,5635,5833,6033,6233,6434,6637,6840,7043,7247,7452,7657,7862,8068,8274,8479,8685,8891,9096,9301,9505,9710,9913,10116,10318,10519,10719,10918,11115,11312,11507,11701,11893,12083,12272,12459,12644,12827,13008,13186,13362,13536,13708,13877,14043,14207,14368,14526,14681,14833,14981,15127,15269,15408,15544,15676,15805,15930,16051,16168,16282,16392,16498,16600,16698,16791,16881,16966,17048,17125,17197,17266,17330,17389,17444,17495,17541,17582,17619,17652,17679,17702,17721,17735,17744,17749,17749,17744,17735,17721,17702,17679,17652,17619,17582,17541,17495,17444,17389,17330,17266,17197,17125,17048,16966,16881,16791,16698,16600,16498,16392,16282,16168,16051,15930,15805,15676,15544,15408,15269,15127,14981,14833,14681,14526,14368,14207,14043,13877,13708,13536,13362,13186,13008,12827,12644,12459,12272,12083,11893,11701,11507,11312,11115,10918,10719,10519,10318,10116,9913,9710,9505,9301,9096,8891,8685,8479,8274,8068,7862,7657,7452,7247,7043,6840,6637,6434,6233,6033,5833,5635,5438,5242,5047,4854,4662,4471,4283,4095,3910,3727,3545,3365,3187,3012,2838,2667,2497,2331,2166,2004,1844,1687,1532,1379,1230,1083,938,797,658,521,388,257,130,5,-117,-237,-353,-466,-576,-684,-788,-889,-988,-1083,-1176,-1265,-1352,-1435,-1516,-1594,-1668,-1740,-1809,-1875,-1937,-1998,-2055,-2109,-2161,-2209,-2255,-2298,-2339,-2377,-2412,-2444,-2474,-2501,-2526,-2548,-2568,-2585,-2600,-2613,-2623,-2631,-2637,-2641,-2642,-2642,-2639,-2634,-2628,-2619,-2609,-2597,-2583,-2567,-2550,-2531,-2510,-2488,-2465,-2440,-2413,-2386,-2357,-2327,-2295,-2263,-2229,-2195,-2159,-2123,-2086,-2048,-2009,-1969,-1929,-1888,-1847,-1805,-1762,-1719,-1676,-1632,-1588,-1543,-1499,-1454,-1409,-1364,-1319,-1274,-1229,-1184,-1139,-1094,-1049,-1004,-960,-916,-872,-828,-785,-742,-700,-658,-616,-575,-534,-494,-455,-416,-377,-339,-302,-265,-229,-194,-159,-125,-92,-60,-28,3,34,63,92,120,147,174,200,225,249,272,295,316,337,358,377,396,414,431,447,463,477,491,505,517,529,540,551,560,569,578,585,592,598,604,609,613,617,620,623,625,626,627,628,628,627,626,624,622,620,617,614,610,606,602,597,592,586,580,574,568,561,554,547,540,532,525,517,509,500,492,483,475,466,457,448,439,430,421,411,402,393,384,374,365,356,347,337,328,319,310,301,292,284,275,266,258,249,241,233,224,217,209,201,193,186,179,171,164,158,151,144,138,132,125,119,114,108,103,97,92,87,82,78,73,69,64,60,56,53,49,46,42,39,36,33,30,28,25,23,20,18,16,14,8,10,12,15,17,20,23,26,30,33,37,41,45,49,54,59,64,69,75,81,87,93,100,107,114,122,129,137,146,154,163,172,182,192,202,212,223,234,245,257,268,281,293,306,319,332,345,359,373,388,402,417,432,448,463,479,495,511,528,544,561,578,595,613,630,648,665,683,701,719,737,755,773,791,809,827,845,862,880,898,915,933,950,967,984,1001,1017,1033,1049,1065,1080,1095,1110,1124,1138,1151,1164,1176,1188,1199,1210,1220,1230,1239,1247,1254,1261,1268,1273,1278,1282,1285,1287,1288,1289,1288,1287,1285,1282,1278,1272,1266,1259,1251,1242,1231,1220,1207,1193,1178,1162,1145,1127,1107,1087,1065,1042,1017,992,965,937,908,878,846,813,779,744,707,670,631,591,549,507,463,419,373,326,278,229,178,127,75,22,-32,-88,-144,-200,-258,-317,-376,-436,-497,-558,-620,-683,-746,-809,-873,-938,-1003,-1068,-1133,-1199,-1265,-1331,-1397,-1463,-1528,-1594,-1660,-1725,-1790,-1855,-1919,-1983,-2047,-2109,-2171,-2233,-2293,-2353,-2412,-2469,-2526,-2582,-2636,-2689,-2741,-2791,-2840,-2887,-2933,-2977,-3019,-3060,-3098,-3135,-3169,-3202,-3232,-3260,-3286,-3309,-3330,-3349,-3365,-3378,-3389,-3397,-3402,-3404,-3404,-3400,-3394,-3384,-3371,-3355,-3336,-3314,-3288,-3259,-3226,-3190,-3151,-3108,-3061,-3011,-2958,-2900,-2839,-2774,-2706,-2633,-2557,-2478,-2394,-2307,-2215,-2120,-2022,-1919,-1812,-1702,-1588,-1470,-1348,-1222,-1093,-960,-823,-683,-538,-390,-239,-84,75,237,403,572,744,920,1099,1281,1467,1655,1847,2041,2239,2439,2642,2848,3056,3267,3480,3696,3914,4134,4356,4580,4806,5034,5264,5495,5728,5962,6198,6435,6673,6912,7151,7392,7633,7875,8117,8359,8602,8844,9087,9329,9571,9813,10054,10295,10535,10773,11011,11248,11483,11717,11950,12181,12410,12637,12862,13085,13306,13525,13741,13954,14165,14373,14578,14780,14978,15174,15366,15555,15740,15921,16099,16272,16442,16608,16769,16926,17079,17228,17371,17511,17645,17775,17900,18020,18135,18245,18350,18450,18544,18634,18718,18796,18869,18937,18999,19056,19107,19152,19192,19226,19255,19278,19295,19306,19312,19312,19306,19295,19278,19255,19226,19192,19152,19107,19056,18999,18937,18869,18796,18718,18634,18544,18450,18350,18245,18135,18020,17900,17775,17645,17511,17371,17228,17079,16926,16769,16608,16442,16272,16099,15921,15740,15555,15366,15174,14978,14780,14578,14373,14165,13954,13741,13525,13306,13085,12862,12637,12410,12181,11950,11717,11483,11248,11011,10773,10535,10295,10054,9813,9571,9329,9087,8844,8602,8359,8117,7875,7633,7392,7151,6912,6673,6435,6198,5962,5728,5495,5264,5034,4806,4580,4356,4134,3914,3696,3480,3267,3056,2848,2642,2439,2239,2041,1847,1655,1467,1281,1099,920,744,572,403,237,75,-84,-239,-390,-538,-683,-823,-960,-1093,-1222,-1348,-1470,-1588,-1702,-1812,-1919,-2022,-2120,-2215,-2307,-2394,-2478,-2557,-2633,-2706,-2774,-2839,-2900,-2958,-3011,-3061,-3108,-3151,-3190,-3226,-3259,-3288,-3314,-3336,-3355,-3371,-3384,-3394,-3400,-3404,-3404,-3402,-3397,-3389,-3378,-3365,-3349,-3330,-3309,-3286,-3260,-3232,-3202,-3169,-3135,-3098,-3060,-3019,-2977,-2933,-2887,-2840,-2791,-2741,-2689,-2636,-2582,-2526,-2469,-2412,-2353,-2293,-2233,-2171,-2109,-2047,-1983,-1919,-1855,-1790,-1725,-1660,-1594,-1528,-1463,-1397,-1331,-1265,-1199,-1133,-1068,-1003,-938,-873,-809,-746,-683,-620,-558,-497,-436,-376,-317,-258,-200,-144,-88,-32,22,75,127,178,229,278,326,373,419,463,507,549,591,631,670,707,744,779,813,846,878,908,937,965,992,1017,1042,1065,1087,1107,1127,1145,1162,1178,1193,1207,1220,1231,1242,1251,1259,1266,1272,1278,1282,1285,1287,1288,1289,1288,1287,1285,1282,1278,1273,1268,1261,1254,1247,1239,1230,1220,1210,1199,1188,1176,1164,1151,1138,1124,1110,1095,1080,1065,1049,1033,1017,1001,984,967,950,933,915,898,880,862,845,827,809,791,773,755,737,719,701,683,665,648,630,613,595,578,561,544,528,511,495,479,463,448,432,417,402,388,373,359,345,332,319,306,293,281,268,257,245,234,223,212,202,192,182,172,163,154,146,137,129,122,114,107,100,93,87,81,75,69,64,59,54,49,45,41,37,33,30,26,23,20,17,15,12,10,8
// chanpats: 173
// name: lowPassStage2
// filter_type: 2
// rate_change: 0
// interp_rate: 1
// decim_rate: 64
// zero_pack_factor: 1
// coeff_padding: 0
// num_coeffs: 768
// coeff_sets: 4
// reloadable: 0
// is_halfband: 0
// quantization: 0
// coeff_width: 16
// coeff_fract_width: 0
// chan_seq: 0
// num_channels: 1
// num_paths: 1
// data_width: 16
// data_fract_width: 0
// output_rounding_mode: 6
// output_width: 17
// output_fract_width: 0
// config_method: 0

const double lowPassStage2_coefficients[3072] = {-1,-1,-1,-1,-1,-2,-2,-2,-2,-3,-3,-4,-4,-4,-5,-5,-6,-6,-7,-8,-8,-9,-10,-10,-11,-12,-13,-14,-15,-16,-17,-18,-20,-21,-22,-24,-25,-27,-28,-30,-32,-34,-36,-38,-40,-42,-44,-47,-49,-52,-55,-57,-60,-63,-66,-69,-73,-76,-80,-83,-87,-91,-95,-99,-103,-107,-112,-117,-121,-126,-131,-136,-142,-147,-152,-158,-164,-170,-176,-182,-189,-195,-202,-209,-216,-223,-230,-238,-245,-253,-261,-269,-277,-285,-294,-302,-311,-320,-329,-338,-347,-357,-366,-376,-386,-396,-406,-416,-426,-436,-447,-457,-468,-479,-490,-501,-512,-523,-534,-545,-556,-567,-579,-590,-602,-613,-624,-636,-647,-659,-670,-681,-693,-704,-715,-727,-738,-749,-760,-771,-781,-792,-802,-813,-823,-833,-843,-852,-862,-871,-880,-889,-897,-906,-914,-921,-929,-936,-942,-949,-955,-960,-966,-970,-975,-979,-982,-985,-988,-990,-991,-992,-993,-993,-992,-991,-989,-987,-983,-980,-975,-970,-964,-958,-950,-942,-933,-924,-913,-902,-890,-877,-863,-849,-833,-817,-799,-781,-762,-742,-720,-698,-675,-651,-626,-599,-572,-544,-514,-484,-452,-419,-385,-350,-314,-277,-238,-198,-158,-116,-72,-28,18,65,113,162,213,264,317,372,427,484,542,601,662,724,787,851,917,984,1052,1121,1191,1263,1336,1410,1486,1563,1640,1719,1800,1881,1964,2048,2132,2219,2306,2394,2483,2574,2665,2758,2852,2946,3042,3138,3236,3335,3434,3534,3636,3738,3841,3944,4049,4154,4260,4367,4475,4583,4692,4801,4911,5022,5133,5244,5356,5469,5582,5695,5809,5923,6037,6151,6266,6381,6496,6611,6726,6842,6957,7072,7187,7302,7417,7532,7647,7761,7875,7989,8102,8215,8328,8440,8552,8663,8773,8883,8992,9101,9209,9316,9422,9528,9632,9736,9839,9940,10041,10141,10239,10337,10433,10528,10622,10714,10806,10896,10984,11071,11157,11241,11324,11406,11485,11563,11640,11715,11788,11860,11929,11997,12064,12128,12191,12251,12310,12367,12422,12476,12527,12576,12623,12668,12712,12753,12792,12829,12863,12896,12927,12955,12982,13006,13028,13048,13065,13081,13094,13105,13114,13120,13125,13127,13127,13125,13120,13114,13105,13094,13081,13065,13048,13028,13006,12982,12955,12927,12896,12863,12829,12792,12753,12712,12668,12623,12576,12527,12476,12422,12367,12310,12251,12191,12128,12064,11997,11929,11860,11788,11715,11640,11563,11485,11406,11324,11241,11157,11071,10984,10896,10806,10714,10622,10528,10433,10337,10239,10141,10041,9940,9839,9736,9632,9528,9422,9316,9209,9101,8992,8883,8773,8663,8552,8440,8328,8215,8102,7989,7875,7761,7647,7532,7417,7302,7187,7072,6957,6842,6726,6611,6496,6381,6266,6151,6037,5923,5809,5695,5582,5469,5356,5244,5133,5022,4911,4801,4692,4583,4475,4367,4260,4154,4049,3944,3841,3738,3636,3534,3434,3335,3236,3138,3042,2946,2852,2758,2665,2574,2483,2394,2306,2219,2132,2048,1964,1881,1800,1719,1640,1563,1486,1410,1336,1263,1191,1121,1052,984,917,851,787,724,662,601,542,484,427,372,317,264,213,162,113,65,18,-28,-72,-116,-158,-198,-238,-277,-314,-350,-385,-419,-452,-484,-514,-544,-572,-599,-626,-651,-675,-698,-720,-742,-762,-781,-799,-817,-833,-849,-863,-877,-890,-902,-913,-924,-933,-942,-950,-958,-964,-970,-975,-980,-983,-987,-989,-991,-992,-993,-993,-992,-991,-990,-988,-985,-982,-979,-975,-970,-966,-960,-955,-949,-942,-936,-929,-921,-914,-906,-897,-889,-880,-871,-862,-852,-843,-833,-823,-813,-802,-792,-781,-771,-760,-749,-738,-727,-715,-704,-693,-681,-670,-659,-647,-636,-624,-613,-602,-590,-579,-567,-556,-545,-534,-523,-512,-501,-490,-479,-468,-457,-447,-436,-426,-416,-406,-396,-386,-376,-366,-357,-347,-338,-329,-320,-311,-302,-294,-285,-277,-269,-261,-253,-245,-238,-230,-223,-216,-209,-202,-195,-189,-182,-176,-170,-164,-158,-152,-147,-142,-136,-131,-126,-121,-117,-112,-107,-103,-99,-95,-91,-87,-83,-80,-76,-73,-69,-66,-63,-60,-57,-55,-52,-49,-47,-44,-42,-40,-38,-36,-34,-32,-30,-28,-27,-25,-24,-22,-21,-20,-18,-17,-16,-15,-14,-13,-12,-11,-10,-10,-9,-8,-8,-7,-6,-6,-5,-5,-4,-4,-4,-3,-3,-2,-2,-2,-2,-1,-1,-1,-1,-1,6,6,7,8,9,10,10,11,12,13,14,15,17,18,19,20,21,23,24,25,27,28,30,31,33,34,36,37,39,41,42,44,46,48,49,51,53,55,56,58,60,62,64,65,67,69,71,72,74,76,77,79,80,82,83,85,86,87,88,90,91,91,92,93,94,94,95,95,95,95,95,95,94,94,93,92,91,90,88,87,85,83,80,78,75,72,69,66,62,58,54,50,45,40,35,29,23,17,11,4,-3,-11,-18,-26,-35,-43,-52,-62,-72,-82,-92,-103,-114,-126,-137,-150,-162,-175,-188,-202,-216,-230,-245,-260,-276,-291,-307,-324,-341,-358,-375,-393,-411,-430,-448,-467,-487,-506,-526,-546,-567,-588,-609,-630,-651,-673,-695,-717,-739,-761,-783,-806,-829,-852,-874,-897,-920,-943,-967,-990,-1013,-1036,-1058,-1081,-1104,-1127,-1149,-1171,-1193,-1215,-1237,-1258,-1279,-1300,-1320,-1340,-1360,-1379,-1398,-1416,-1434,-1452,-1468,-1484,-1500,-1515,-1529,-1543,-1556,-1568,-1579,-1589,-1599,-1608,-1615,-1622,-1628,-1633,-1637,-1640,-1642,-1642,-1642,-1640,-1637,-1633,-1628,-1621,-1613,-1604,-1593,-1581,-1568,-1553,-1536,-1518,-1499,-1478,-1455,-1431,-1405,-1377,-1348,-1317,-1284,-1250,-1213,-1175,-1136,-1094,-1050,-1005,-958,-909,-858,-805,-750,-693,-634,-573,-510,-446,-379,-310,-239,-167,-92,-15,64,144,227,312,399,488,579,671,766,863,962,1062,1165,1270,1376,1484,1595,1707,1821,1936,2054,2173,2294,2417,2541,2668,2795,2925,3056,3188,3322,3458,3594,3733,3872,4013,4155,4299,4444,4589,4736,4884,5033,5183,5334,5486,5638,5792,5946,6100,6256,6412,6568,6725,6882,7039,7197,7355,7513,7671,7830,7988,8146,8304,8462,8619,8776,8933,9089,9245,9400,9555,9709,9862,10014,10165,10315,10465,10613,10760,10906,11050,11193,11335,11476,11614,11752,11887,12021,12153,12283,12412,12538,12663,12785,12905,13023,13139,13253,13364,13473,13580,13684,13785,13884,13981,14074,14165,14254,14339,14422,14502,14579,14653,14724,14792,14857,14919,14978,15033,15086,15135,15182,15225,15265,15301,15334,15364,15391,15415,15435,15451,15465,15475,15482,15485,15485,15482,15475,15465,15451,15435,15415,15391,15364,15334,15301,15265,15225,15182,15135,15086,15033,14978,14919,14857,14792,14724,14653,14579,14502,14422,14339,14254,14165,14074,13981,13884,13785,13684,13580,13473,13364,13253,13139,13023,12905,12785,12663,12538,12412,12283,12153,12021,11887,11752,11614,11476,11335,11193,11050,10906,10760,10613,10465,10315,10165,10014,9862,9709,9555,9400,9245,9089,8933,8776,8619,8462,8304,8146,7988,7830,7671,7513,7355,7197,7039,6882,6725,6568,6412,6256,6100,5946,5792,5638,5486,5334,5183,5033,4884,4736,4589,4444,4299,4155,4013,3872,3733,3594,3458,3322,3188,3056,2925,2795,2668,2541,2417,2294,2173,2054,1936,1821,1707,1595,1484,1376,1270,1165,1062,962,863,766,671,579,488,399,312,227,144,64,-15,-92,-167,-239,-310,-379,-446,-510,-573,-634,-693,-750,-805,-858,-909,-958,-1005,-1050,-1094,-1136,-1175,-1213,-1250,-1284,-1317,-1348,-1377,-1405,-1431,-1455,-1478,-1499,-1518,-1536,-1553,-1568,-1581,-1593,-1604,-1613,-1621,-1628,-1633,-1637,-1640,-1642,-1642,-1642,-1640,-1637,-1633,-1628,-1622,-1615,-1608,-1599,-1589,-1579,-1568,-1556,-1543,-1529,-1515,-1500,-1484,-1468,-1452,-1434,-1416,-1398,-1379,-1360,-1340,-1320,-1300,-1279,-1258,-1237,-1215,-1193,-1171,-1149,-1127,-1104,-1081,-1058,-1036,-1013,-990,-967,-943,-920,-897,-874,-852,-829,-806,-783,-761,-739,-717,-695,-673,-651,-630,-609,-588,-567,-546,-526,-506,-487,-467,-448,-430,-411,-393,-375,-358,-341,-324,-307,-291,-276,-260,-245,-230,-216,-202,-188,-175,-162,-150,-137,-126,-114,-103,-92,-82,-72,-62,-52,-43,-35,-26,-18,-11,-3,4,11,17,23,29,35,40,45,50,54,58,62,66,69,72,75,78,80,83,85,87,88,90,91,92,93,94,94,95,95,95,95,95,95,94,94,93,92,91,91,90,88,87,86,85,83,82,80,79,77,76,74,72,71,69,67,65,64,62,60,58,56,55,53,51,49,48,46,44,42,41,39,37,36,34,33,31,30,28,27,25,24,23,21,20,19,18,17,15,14,13,12,11,10,10,9,8,7,6,6,14,16,18,20,23,25,28,30,33,36,39,42,46,49,53,56,60,64,69,73,78,82,87,92,97,103,108,114,119,125,132,138,144,151,158,164,171,179,186,193,201,209,217,224,233,241,249,258,266,275,284,292,301,310,319,328,337,347,356,365,374,384,393,402,411,421,430,439,448,457,466,475,483,492,500,509,517,525,532,540,547,554,561,568,574,580,586,592,597,602,606,610,614,617,620,622,624,626,627,628,628,627,626,625,623,620,617,613,609,604,598,592,585,578,569,560,551,540,529,517,505,491,477,463,447,431,414,396,377,358,337,316,295,272,249,225,200,174,147,120,92,63,34,3,-28,-60,-92,-125,-159,-194,-229,-265,-302,-339,-377,-416,-455,-494,-534,-575,-616,-658,-700,-742,-785,-828,-872,-916,-960,-1004,-1049,-1094,-1139,-1184,-1229,-1274,-1319,-1364,-1409,-1454,-1499,-1543,-1588,-1632,-1676,-1719,-1762,-1805,-1847,-1888,-1929,-1969,-2009,-2048,-2086,-2123,-2159,-2195,-2229,-2263,-2295,-2327,-2357,-2386,-2413,-2440,-2465,-2488,-2510,-2531,-2550,-2567,-2583,-2597,-2609,-2619,-2628,-2634,-2639,-2642,-2642,-2641,-2637,-2631,-2623,-2613,-2600,-2585,-2568,-2548,-2526,-2501,-2474,-2444,-2412,-2377,-2339,-2298,-2255,-2209,-2161,-2109,-2055,-1998,-1937,-1875,-1809,-1740,-1668,-1594,-1516,-1435,-1352,-1265,-1176,-1083,-988,-889,-788,-684,-576,-466,-353,-237,-117,5,130,257,388,521,658,797,938,1083,1230,1379,1532,1687,1844,2004,2166,2331,2497,2667,2838,3012,3187,3365,3545,3727,3910,4095,4283,4471,4662,4854,5047,5242,5438,5635,5833,6033,6233,6434,6637,6840,7043,7247,7452,7657,7862,8068,8274,8479,8685,8891,9096,9301,9505,9710,9913,10116,10318,10519,10719,10918,11115,11312,11507,11701,11893,12083,12272,12459,12644,12827,13008,13186,13362,13536,13708,13877,14043,14207,14368,14526,14681,14833,14981,15127,15269,15408,15544,15676,15805,15930,16051,16168,16282,16392,16498,16600,16698,16791,16881,16966,17048,17125,17197,17266,17330,17389,17444,17495,17541,17582,17619,17652,17679,17702,17721,17735,17744,17749,17749,17744,17735,17721,17702,17679,17652,17619,17582,17541,17495,17444,17389,17330,17266,17197,17125,17048,16966,16881,16791,16698,16600,16498,16392,16282,16168,16051,15930,15805,15676,15544,15408,15269,15127,14981,14833,14681,14526,14368,14207,14043,13877,13708,13536,13362,13186,13008,12827,12644,12459,12272,12083,11893,11701,11507,11312,11115,10918,10719,10519,10318,10116,9913,9710,9505,9301,9096,8891,8685,8479,8274,8068,7862,7657,7452,7247,7043,6840,6637,6434,6233,6033,5833,5635,5438,5242,5047,4854,4662,4471,4283,4095,3910,3727,3545,3365,3187,3012,2838,2667,2497,2331,2166,2004,1844,1687,1532,1379,1230,1083,938,797,658,521,388,257,130,5,-117,-237,-353,-466,-576,-684,-788,-889,-988,-1083,-1176,-1265,-1352,-1435,-1516,-1594,-1668,-1740,-1809,-1875,-1937,-1998,-2055,-2109,-2161,-2209,-2255,-2298,-2339,-2377,-2412,-2444,-2474,-2501,-2526,-2548,-2568,-2585,-2600,-2613,-2623,-2631,-2637,-2641,-2642,-2642,-2639,-2634,-2628,-2619,-2609,-2597,-2583,-2567,-2550,-2531,-2510,-2488,-2465,-2440,-2413,-2386,-2357,-2327,-2295,-2263,-2229,-2195,-2159,-2123,-2086,-2048,-2009,-1969,-1929,-1888,-1847,-1805,-1762,-1719,-1676,-1632,-1588,-1543,-1499,-1454,-1409,-1364,-1319,-1274,-1229,-1184,-1139,-1094,-1049,-1004,-960,-916,-872,-828,-785,-742,-700,-658,-616,-575,-534,-494,-455,-416,-377,-339,-302,-265,-229,-194,-159,-125,-92,-60,-28,3,34,63,92,120,147,174,200,225,249,272,295,316,337,358,377,396,414,431,447,463,477,491,505,517,529,540,551,560,569,578,585,592,598,604,609,613,617,620,623,625,626,627,628,628,627,626,624,622,620,617,614,610,606,602,597,592,586,580,574,568,561,554,547,540,532,525,517,509,500,492,483,475,466,457,448,439,430,421,411,402,393,384,374,365,356,347,337,328,319,310,301,292,284,275,266,258,249,241,233,224,217,209,201,193,186,179,171,164,158,151,144,138,132,125,119,114,108,103,97,92,87,82,78,73,69,64,60,56,53,49,46,42,39,36,33,30,28,25,23,20,18,16,14,8,10,12,15,17,20,23,26,30,33,37,41,45,49,54,59,64,69,75,81,87,93,100,107,114,122,129,137,146,154,163,172,182,192,202,212,223,234,245,257,268,281,293,306,319,332,345,359,373,388,402,417,432,448,463,479,495,511,528,544,561,578,595,613,630,648,665,683,701,719,737,755,773,791,809,827,845,862,880,898,915,933,950,967,984,1001,1017,1033,1049,1065,1080,1095,1110,1124,1138,1151,1164,1176,1188,1199,1210,1220,1230,1239,1247,1254,1261,1268,1273,1278,1282,1285,1287,1288,1289,1288,1287,1285,1282,1278,1272,1266,1259,1251,1242,1231,1220,1207,1193,1178,1162,1145,1127,1107,1087,1065,1042,1017,992,965,937,908,878,846,813,779,744,707,670,631,591,549,507,463,419,373,326,278,229,178,127,75,22,-32,-88,-144,-200,-258,-317,-376,-436,-497,-558,-620,-683,-746,-809,-873,-938,-1003,-1068,-1133,-1199,-1265,-1331,-1397,-1463,-1528,-1594,-1660,-1725,-1790,-1855,-1919,-1983,-2047,-2109,-2171,-2233,-2293,-2353,-2412,-2469,-2526,-2582,-2636,-2689,-2741,-2791,-2840,-2887,-2933,-2977,-3019,-3060,-3098,-3135,-3169,-3202,-3232,-3260,-3286,-3309,-3330,-3349,-3365,-3378,-3389,-3397,-3402,-3404,-3404,-3400,-3394,-3384,-3371,-3355,-3336,-3314,-3288,-3259,-3226,-3190,-3151,-3108,-3061,-3011,-2958,-2900,-2839,-2774,-2706,-2633,-2557,-2478,-2394,-2307,-2215,-2120,-2022,-1919,-1812,-1702,-1588,-1470,-1348,-1222,-1093,-960,-823,-683,-538,-390,-239,-84,75,237,403,572,744,920,1099,1281,1467,1655,1847,2041,2239,2439,2642,2848,3056,3267,3480,3696,3914,4134,4356,4580,4806,5034,5264,5495,5728,5962,6198,6435,6673,6912,7151,7392,7633,7875,8117,8359,8602,8844,9087,9329,9571,9813,10054,10295,10535,10773,11011,11248,11483,11717,11950,12181,12410,12637,12862,13085,13306,13525,13741,13954,14165,14373,14578,14780,14978,15174,15366,15555,15740,15921,16099,16272,16442,16608,16769,16926,17079,17228,17371,17511,17645,17775,17900,18020,18135,18245,18350,18450,18544,18634,18718,18796,18869,18937,18999,19056,19107,19152,19192,19226,19255,19278,19295,19306,19312,19312,19306,19295,19278,19255,19226,19192,19152,19107,19056,18999,18937,18869,18796,18718,18634,18544,18450,18350,18245,18135,18020,17900,17775,17645,17511,17371,17228,17079,16926,16769,16608,16442,16272,16099,15921,15740,15555,15366,15174,14978,14780,14578,14373,14165,13954,13741,13525,13306,13085,12862,12637,12410,12181,11950,11717,11483,11248,11011,10773,10535,10295,10054,9813,9571,9329,9087,8844,8602,8359,8117,7875,7633,7392,7151,6912,6673,6435,6198,5962,5728,5495,5264,5034,4806,4580,4356,4134,3914,3696,3480,3267,3056,2848,2642,2439,2239,2041,1847,1655,1467,1281,1099,920,744,572,403,237,75,-84,-239,-390,-538,-683,-823,-960,-1093,-1222,-1348,-1470,-1588,-1702,-1812,-1919,-2022,-2120,-2215,-2307,-2394,-2478,-2557,-2633,-2706,-2774,-2839,-2900,-2958,-3011,-3061,-3108,-3151,-3190,-3226,-3259,-3288,-3314,-3336,-3355,-3371,-3384,-3394,-3400,-3404,-3404,-3402,-3397,-3389,-3378,-3365,-3349,-3330,-3309,-3286,-3260,-3232,-3202,-3169,-3135,-3098,-3060,-3019,-2977,-2933,-2887,-2840,-2791,-2741,-2689,-2636,-2582,-2526,-2469,-2412,-2353,-2293,-2233,-2171,-2109,-2047,-1983,-1919,-1855,-1790,-1725,-1660,-1594,-1528,-1463,-1397,-1331,-1265,-1199,-1133,-1068,-1003,-938,-873,-809,-746,-683,-620,-558,-497,-436,-376,-317,-258,-200,-144,-88,-32,22,75,127,178,229,278,326,373,419,463,507,549,591,631,670,707,744,779,813,846,878,908,937,965,992,1017,1042,1065,1087,1107,1127,1145,1162,1178,1193,1207,1220,1231,1242,1251,1259,1266,1272,1278,1282,1285,1287,1288,1289,1288,1287,1285,1282,1278,1273,1268,1261,1254,1247,1239,1230,1220,1210,1199,1188,1176,1164,1151,1138,1124,1110,1095,1080,1065,1049,1033,1017,1001,984,967,950,933,915,898,880,862,845,827,809,791,773,755,737,719,701,683,665,648,630,613,595,578,561,544,528,511,495,479,463,448,432,417,402,388,373,359,345,332,319,306,293,281,268,257,245,234,223,212,202,192,182,172,163,154,146,137,129,122,114,107,100,93,87,81,75,69,64,59,54,49,45,41,37,33,30,26,23,20,17,15,12,10,8};

const xip_fir_v7_2_pattern lowPassStage2_chanpats[1] = {P_BASIC};

static xip_fir_v7_2_config gen_lowPassStage2_config() {
  xip_fir_v7_2_config config;
  config.name                = "lowPassStage2";
  config.filter_type         = 2;
  config.rate_change         = XIP_FIR_INTEGER_RATE;
  config.interp_rate         = 1;
  config.decim_rate          = 64;
  config.zero_pack_factor    = 1;
  config.coeff               = &lowPassStage2_coefficients[0];
  config.coeff_padding       = 0;
  config.num_coeffs          = 768;
  config.coeff_sets          = 4;
  config.reloadable          = 0;
  config.is_halfband         = 0;
  config.quantization        = XIP_FIR_INTEGER_COEFF;
  config.coeff_width         = 16;
  config.coeff_fract_width   = 0;
  config.chan_seq            = XIP_FIR_BASIC_CHAN_SEQ;
  config.num_channels        = 1;
  config.init_pattern        = lowPassStage2_chanpats[0];
  config.num_paths           = 1;
  config.data_width          = 16;
  config.data_fract_width    = 0;
  config.output_rounding_mode= XIP_FIR_NON_SYMMETRIC_DOWN;
  config.output_width        = 17;
  config.output_fract_width  = 0,
  config.config_method       = XIP_FIR_CONFIG_SINGLE;
  return config;
}

const xip_fir_v7_2_config lowPassStage2_config = gen_lowPassStage2_config();

