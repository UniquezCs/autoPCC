// autoPCC.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream> 

using namespace std;
int main()
{
	string command;
	clock_t start, end;   //clock_t 是clock()的返回变量类型
	int time;
	int n=2;
	int m=2;
	int tile_number = n * n*m;
	string ns = to_string(n);
	string ms = to_string(m);

	string uncompressedDataPath="D:/dataset3/loot_"+ns+"_"+ms+"_tiles/";

	string compressedStreamPath="D:/pcc_dataset/loot/loot_"+ns+"_"+ms+"/";
	string reconstructedDataPath = compressedStreamPath;
	int startFrameNumber=1000;
	string startFrameNumbers = to_string(startFrameNumber);
	string frameCount="30";
	string groupOfFramesSize="30";
	string representation;
	string tiles;
	string segs;
	string tile_name;
	for (int seg = 1; seg< 11; seg++) {

		startFrameNumber = 1000+(seg-1)*30;
		startFrameNumbers = to_string(startFrameNumber);

		segs = to_string(seg);
		for (int tile = 1; tile < tile_number; tile++) {
			tiles = to_string(tile);
			for (int r = 4; r < 6; r++) {
				representation = to_string(r);
				tile_name = "loot_" + ns + "_" + ms + "_seg_" + segs + "_r_" + representation + "_tile_" + tiles;
				string plypath=reconstructedDataPath + "loot_" + ns + "_" + ms + "_seg_" + segs + "/r" + representation + "/tile_" + tiles + "/" + tile_name + "%04d" + ".ply";
				string binpath= reconstructedDataPath + "loot_" + ns + "_" + ms + "_seg_" + segs + "/r" + representation + "/tile_" + tiles + "/" + tile_name + ".bin";
				string uncompath= uncompressedDataPath+ "tile_"+tiles+"/loot_"+ns+"-"+ms+"_%04i_tile_"+tiles+".ply";
				
				start = clock();
				command = "F:/pcc/tmc2_4/bin/PccAppEncoder.exe --configurationFolder=F:/pcc/tmc2_4/bin/cfg/ --config=F:/pcc/tmc2_4/bin/cfg/common/ctc-common.cfg --config=F:/pcc/tmc2_4/bin/cfg/condition/ctc-low-delay.cfg   --config=F:/pcc/tmc2_4/bin/cfg/rate/ctc-r"+representation+".cfg --nbThread=2 --startFrameNumber="+startFrameNumbers+" --uncompressedDataPath="+uncompath+" --frameCount=30 --videoEncoderPath=F:/Download/HM-16.16/bin/vc2015/x64/Release/TAppEncoder.exe --colorSpaceConversionPath=F:/pcc/tcm2/external/HDRTools/bin/HDRConvert.exe --reconstructedDataPath="+ plypath+" --compressedStreamPath="+binpath;
				system(command.c_str());
				end = clock();
				time = (end - start);
				cout << time << endl;

			}
		}
	}


	
	

	

}


