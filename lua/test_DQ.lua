-- DAG definition: it is encoded as an array of stages.
Stages = {{ name="S216", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S216.txt")}}, pre={"S213"}, post={"S219"}},{ name="S212", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S212.txt")}}, pre={"S211"}, post={"S213"}},{ name="S213", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S213.txt")}}, pre={"S212"}, post={"S216"}},{ name="S210", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S210.txt")}}, pre={"S207"}, post={"S211"}},{ name="S211", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S211.txt")}}, pre={"S210"}, post={"S212"}},{ name="S264", tasks="11", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S264.txt")}}, pre={"S263"}, post={"S265"}},{ name="S265", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S265.txt")}}, pre={"S264"}, post={"S266"}},{ name="S219", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S219.txt")}}, pre={"S216"}, post={"S220"}},{ name="S133", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S133.txt")}}, pre={"S132"}, post={"S134"}},{ name="S132", tasks="7", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S132.txt")}}, pre={"S131"}, post={"S133"}},{ name="S131", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S131.txt")}}, pre={"S130"}, post={"S132"}},{ name="S130", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S130.txt")}}, pre={"S129"}, post={"S131"}},{ name="S137", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S137.txt")}}, pre={"S136"}, post={"S138"}},{ name="S136", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S136.txt")}}, pre={"S135"}, post={"S137"}},{ name="S135", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S135.txt")}}, pre={"S134"}, post={"S136"}},{ name="S134", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S134.txt")}}, pre={"S133"}, post={"S135"}},{ name="S139", tasks="856", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S139.txt")}}, pre={"S138"}, post={"S140"}},{ name="S138", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S138.txt")}}, pre={"S137"}, post={"S139"}},{ name="S93", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S93.txt")}}, pre={"S91"}, post={"S94"}},{ name="S24", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S24.txt")}}, pre={"S23"}, post={"S25"}},{ name="S25", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S25.txt")}}, pre={"S24"}, post={"S27"}},{ name="S27", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S27.txt")}}, pre={"S25"}, post={"S28"}},{ name="S20", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S20.txt")}}, pre={"S19"}, post={"S21"}},{ name="S21", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S21.txt")}}, pre={"S20"}, post={"S22"}},{ name="S22", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S22.txt")}}, pre={"S21"}, post={"S23"}},{ name="S23", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S23.txt")}}, pre={"S22"}, post={"S24"}},{ name="S95", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S95.txt")}}, pre={"S94"}, post={"S97"}},{ name="S28", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S28.txt")}}, pre={"S27"}, post={"S29"}},{ name="S29", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S29.txt")}}, pre={"S28"}, post={"S30"}},{ name="S161", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S161.txt")}}, pre={"S160"}, post={"S165"}},{ name="S0", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S0.txt")}}, pre={}, post={"S1"}},{ name="S4", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S4.txt")}}, pre={"S3"}, post={"S5"}},{ name="S8", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S8.txt")}}, pre={"S7"}, post={"S9"}},{ name="S263", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S263.txt")}}, pre={"S262"}, post={"S264"}},{ name="S262", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S262.txt")}}, pre={"S261"}, post={"S263"}},{ name="S122", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S122.txt")}}, pre={"S119"}, post={"S123"}},{ name="S123", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S123.txt")}}, pre={"S122"}, post={"S124"}},{ name="S124", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S124.txt")}}, pre={"S123"}, post={"S125"}},{ name="S125", tasks="19", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S125.txt")}}, pre={"S124"}, post={"S126"}},{ name="S126", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S126.txt")}}, pre={"S125"}, post={"S127"}},{ name="S127", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S127.txt")}}, pre={"S126"}, post={"S128"}},{ name="S128", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S128.txt")}}, pre={"S127"}, post={"S129"}},{ name="S129", tasks="7", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S129.txt")}}, pre={"S128"}, post={"S130"}},{ name="S59", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S59.txt")}}, pre={"S58"}, post={"S60"}},{ name="S58", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S58.txt")}}, pre={"S57"}, post={"S59"}},{ name="S55", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S55.txt")}}, pre={"S54"}, post={"S56"}},{ name="S54", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S54.txt")}}, pre={"S53"}, post={"S55"}},{ name="S57", tasks="7", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S57.txt")}}, pre={"S56"}, post={"S58"}},{ name="S56", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S56.txt")}}, pre={"S55"}, post={"S57"}},{ name="S51", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S51.txt")}}, pre={"S50"}, post={"S52"}},{ name="S50", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S50.txt")}}, pre={"S49"}, post={"S51"}},{ name="S53", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S53.txt")}}, pre={"S52"}, post={"S54"}},{ name="S52", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S52.txt")}}, pre={"S51"}, post={"S53"}},{ name="S63", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S63.txt")}}, pre={"S62"}, post={"S64"}},{ name="S199", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S199.txt")}}, pre={"S198"}, post={"S200"}},{ name="S198", tasks="25", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S198.txt")}}, pre={"S197"}, post={"S199"}},{ name="S194", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S194.txt")}}, pre={"S192"}, post={"S196"}},{ name="S197", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S197.txt")}}, pre={"S196"}, post={"S198"}},{ name="S196", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S196.txt")}}, pre={"S194"}, post={"S197"}},{ name="S191", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S191.txt")}}, pre={"S190"}, post={"S192"}},{ name="S190", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S190.txt")}}, pre={"S188"}, post={"S191"}},{ name="S192", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S192.txt")}}, pre={"S191"}, post={"S194"}},{ name="S252", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S252.txt")}}, pre={"S250"}, post={"S254"}},{ name="S116", tasks="440", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S116.txt")}}, pre={"S113"}, post={"S119"}},{ name="S110", tasks="440", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S110.txt")}}, pre={"S107"}, post={"S113"}},{ name="S113", tasks="440", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S113.txt")}}, pre={"S110"}, post={"S116"}},{ name="S83", tasks="315", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S83.txt")}}, pre={"S81"}, post={"S84"}},{ name="S81", tasks="100", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S81.txt")}}, pre={"S79"}, post={"S83"}},{ name="S119", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S119.txt")}}, pre={"S116"}, post={"S122"}},{ name="S87", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S87.txt")}}, pre={"S85"}, post={"S89"}},{ name="S84", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S84.txt")}}, pre={"S83"}, post={"S85"}},{ name="S85", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S85.txt")}}, pre={"S84"}, post={"S87"}},{ name="S140", tasks="856", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S140.txt")}}, pre={"S139"}, post={"S141"}},{ name="S256", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S256.txt")}}, pre={"S254"}, post={"S258"}},{ name="S3", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S3.txt")}}, pre={"S2"}, post={"S4"}},{ name="S7", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S7.txt")}}, pre={"S6"}, post={"S8"}},{ name="S244", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S244.txt")}}, pre={"S242"}, post={"S246"}},{ name="S247", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S247.txt")}}, pre={"S246"}, post={"S248"}},{ name="S246", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S246.txt")}}, pre={"S244"}, post={"S247"}},{ name="S240", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S240.txt")}}, pre={"S238"}, post={"S242"}},{ name="S242", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S242.txt")}}, pre={"S240"}, post={"S244"}},{ name="S101", tasks="440", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S101.txt")}}, pre={"S98"}, post={"S104"}},{ name="S107", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S107.txt")}}, pre={"S104"}, post={"S110"}},{ name="S104", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S104.txt")}}, pre={"S101"}, post={"S107"}},{ name="S39", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S39.txt")}}, pre={"S38"}, post={"S40"}},{ name="S38", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S38.txt")}}, pre={"S37"}, post={"S39"}},{ name="S33", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S33.txt")}}, pre={"S31"}, post={"S35"}},{ name="S31", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S31.txt")}}, pre={"S30"}, post={"S33"}},{ name="S30", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S30.txt")}}, pre={"S29"}, post={"S31"}},{ name="S37", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S37.txt")}}, pre={"S36"}, post={"S38"}},{ name="S36", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S36.txt")}}, pre={"S35"}, post={"S37"}},{ name="S35", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S35.txt")}}, pre={"S33"}, post={"S36"}},{ name="S94", tasks="440", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S94.txt")}}, pre={"S93"}, post={"S95"}},{ name="S60", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S60.txt")}}, pre={"S59"}, post={"S61"}},{ name="S61", tasks="19", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S61.txt")}}, pre={"S60"}, post={"S62"}},{ name="S258", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S258.txt")}}, pre={"S256"}, post={"S259"}},{ name="S259", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S259.txt")}}, pre={"S258"}, post={"S260"}},{ name="S64", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S64.txt")}}, pre={"S63"}, post={"S65"}},{ name="S65", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S65.txt")}}, pre={"S64"}, post={"S66"}},{ name="S66", tasks="429", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S66.txt")}}, pre={"S65"}, post={"S67"}},{ name="S67", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S67.txt")}}, pre={"S66"}, post={"S70"}},{ name="S177", tasks="856", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S177.txt")}}, pre={"S173"}, post={"S181"}},{ name="S250", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S250.txt")}}, pre={"S248"}, post={"S252"}},{ name="S173", tasks="856", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S173.txt")}}, pre={"S169"}, post={"S177"}},{ name="S254", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S254.txt")}}, pre={"S252"}, post={"S256"}},{ name="S248", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S248.txt")}}, pre={"S247"}, post={"S250"}},{ name="S182", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S182.txt")}}, pre={"S181"}, post={"S183"}},{ name="S183", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S183.txt")}}, pre={"S182"}, post={"S184"}},{ name="S181", tasks="856", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S181.txt")}}, pre={"S177"}, post={"S182"}},{ name="S186", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S186.txt")}}, pre={"S185"}, post={"S187"}},{ name="S187", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S187.txt")}}, pre={"S186"}, post={"S188"}},{ name="S184", tasks="19", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S184.txt")}}, pre={"S183"}, post={"S185"}},{ name="S185", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S185.txt")}}, pre={"S184"}, post={"S186"}},{ name="S188", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S188.txt")}}, pre={"S187"}, post={"S190"}},{ name="S97", tasks="440", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S97.txt")}}, pre={"S95"}, post={"S98"}},{ name="S6", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S6.txt")}}, pre={"S5"}, post={"S7"}},{ name="S98", tasks="440", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S98.txt")}}, pre={"S97"}, post={"S101"}},{ name="S169", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S169.txt")}}, pre={"S165"}, post={"S173"}},{ name="S228", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S228.txt")}}, pre={"S225"}, post={"S231"}},{ name="S91", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S91.txt")}}, pre={"S89"}, post={"S93"}},{ name="S165", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S165.txt")}}, pre={"S161"}, post={"S169"}},{ name="S225", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S225.txt")}}, pre={"S222"}, post={"S228"}},{ name="S160", tasks="856", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S160.txt")}}, pre={"S159"}, post={"S161"}},{ name="S222", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S222.txt")}}, pre={"S221"}, post={"S225"}},{ name="S221", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S221.txt")}}, pre={"S220"}, post={"S222"}},{ name="S220", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S220.txt")}}, pre={"S219"}, post={"S221"}},{ name="S11", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S11.txt")}}, pre={"S10"}, post={"S12"}},{ name="S10", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S10.txt")}}, pre={"S9"}, post={"S11"}},{ name="S13", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S13.txt")}}, pre={"S12"}, post={"S14"}},{ name="S12", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S12.txt")}}, pre={"S11"}, post={"S13"}},{ name="S15", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S15.txt")}}, pre={"S14"}, post={"S16"}},{ name="S14", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S14.txt")}}, pre={"S13"}, post={"S15"}},{ name="S17", tasks="12", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S17.txt")}}, pre={"S16"}, post={"S18"}},{ name="S16", tasks="216", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S16.txt")}}, pre={"S15"}, post={"S17"}},{ name="S19", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S19.txt")}}, pre={"S18"}, post={"S20"}},{ name="S18", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S18.txt")}}, pre={"S17"}, post={"S19"}},{ name="S89", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S89.txt")}}, pre={"S87"}, post={"S91"}},{ name="S153", tasks="856", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S153.txt")}}, pre={"S149"}, post={"S157"}},{ name="S157", tasks="856", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S157.txt")}}, pre={"S153"}, post={"S158"}},{ name="S159", tasks="856", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S159.txt")}}, pre={"S158"}, post={"S160"}},{ name="S158", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S158.txt")}}, pre={"S157"}, post={"S159"}},{ name="S62", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S62.txt")}}, pre={"S61"}, post={"S63"}},{ name="S238", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S238.txt")}}, pre={"S237"}, post={"S240"}},{ name="S234", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S234.txt")}}, pre={"S233"}, post={"S235"}},{ name="S235", tasks="20", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S235.txt")}}, pre={"S234"}, post={"S236"}},{ name="S236", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S236.txt")}}, pre={"S235"}, post={"S237"}},{ name="S237", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S237.txt")}}, pre={"S236"}, post={"S238"}},{ name="S231", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S231.txt")}}, pre={"S228"}, post={"S232"}},{ name="S232", tasks="36", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S232.txt")}}, pre={"S231"}, post={"S233"}},{ name="S233", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S233.txt")}}, pre={"S232"}, post={"S234"}},{ name="S48", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S48.txt")}}, pre={"S46"}, post={"S49"}},{ name="S49", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S49.txt")}}, pre={"S48"}, post={"S50"}},{ name="S46", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S46.txt")}}, pre={"S45"}, post={"S48"}},{ name="S44", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S44.txt")}}, pre={"S43"}, post={"S45"}},{ name="S45", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S45.txt")}}, pre={"S44"}, post={"S46"}},{ name="S42", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S42.txt")}}, pre={"S41"}, post={"S43"}},{ name="S43", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S43.txt")}}, pre={"S42"}, post={"S44"}},{ name="S40", tasks="19", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S40.txt")}}, pre={"S39"}, post={"S41"}},{ name="S41", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S41.txt")}}, pre={"S40"}, post={"S42"}},{ name="S1", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S1.txt")}}, pre={"S0"}, post={"S2"}},{ name="S5", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S5.txt")}}, pre={"S4"}, post={"S6"}},{ name="S9", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S9.txt")}}, pre={"S8"}, post={"S10"}},{ name="S201", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S201.txt")}}, pre={"S200"}, post={"S204"}},{ name="S200", tasks="428", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S200.txt")}}, pre={"S199"}, post={"S201"}},{ name="S145", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S145.txt")}}, pre={"S141"}, post={"S149"}},{ name="S204", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S204.txt")}}, pre={"S201"}, post={"S207"}},{ name="S207", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S207.txt")}}, pre={"S204"}, post={"S210"}},{ name="S141", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S141.txt")}}, pre={"S140"}, post={"S145"}},{ name="S149", tasks="856", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S149.txt")}}, pre={"S145"}, post={"S153"}},{ name="S77", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S77.txt")}}, pre={"S75"}, post={"S79"}},{ name="S75", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S75.txt")}}, pre={"S74"}, post={"S77"}},{ name="S74", tasks="440", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S74.txt")}}, pre={"S73"}, post={"S75"}},{ name="S73", tasks="429", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S73.txt")}}, pre={"S70"}, post={"S74"}},{ name="S70", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S70.txt")}}, pre={"S67"}, post={"S73"}},{ name="S79", tasks="20", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S79.txt")}}, pre={"S77"}, post={"S81"}},{ name="S2", tasks="2", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S2.txt")}}, pre={"S1"}, post={"S3"}},{ name="S261", tasks="19", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S261.txt")}}, pre={"S260"}, post={"S262"}},{ name="S260", tasks="4", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S260.txt")}}, pre={"S259"}, post={"S261"}},{ name="S266", tasks="1", distr={type="replay", params={samples=solver.fileToArray("/Users/ardagna/Desktop/VescoviniZaninelli/lua/testDQ/S266.txt")}}, pre={"S265"}, post={}}};

-- Number of computation nodes in the system
Nodes = @@nodes@@;

-- Number of users accessing the system
Users = 1;

-- Distribution of the think time for the users
UThinkTimeDistr = {type = "exp", params = {rate = 0.001}};

-- Total number of jobs to simulate
maxJobs = 1000;

-- Coefficient for the Confidence Intervals
confIntCoeff = 1.96;
