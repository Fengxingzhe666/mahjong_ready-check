//check_win.h
#ifndef  CHECK_WIN
#define CHECK_WIN
#include <iostream>
#include <vector>
#include<algorithm>//包含sort()函数
#include<unordered_map>

const int combo_num = 4;
const std::vector<std::vector<int>> combo = 
{
			{1,1,1} ,{2,2,2} ,{3,3,3} ,{4,4,4},
			{5,5,5} ,{6,6,6} ,{7,7,7} ,{8,8,8},
			{9,9,9} ,{1,2,3} ,{2,3,4} ,{3,4,5},
			{4,5,6} ,{5,6,7} ,{6,7,8} ,{7,8,9},
			{10,10,10} ,{11,11,11} ,{12,12,12}, {13,13,13} ,
			{14,14,14} ,{15,15,15} ,{16,16,16},{17,17,17} ,
			{18,18,18} ,{10,11,12} ,{11,12,13},{12,13,14} ,
			{13,14,15} ,{14,15,16} ,{15,16,17},{16,17,18} ,
			{19,19,19} ,{20,20,20} ,{21,21,21},{22,22,22} ,
			{23,23,23} ,{24,24,24} ,{25,25,25},{26,26,26} ,
			{27,27,27} ,{19,20,21} ,{20,21,22},{21,22,23} ,
			{22,23,24} ,{23,24,25} ,{24,25,26},{25,26,27} ,
			{28,28,28} ,{29,29,29} ,{30,30,30},{31,31,31} ,
			{32,32,32} ,{33,33,33} ,{34,34,34},{35,35,35} ,
			{36,36,36} ,{37,37,37} ,{38,38,38}
};
const std::unordered_map<int, std::string> tileMapping =
{
	{1, "1m"}, {2, "2m"}, {3, "3m"}, {4, "4m"}, {5, "5m"}, {6, "6m"}, {7, "7m"}, {8, "8m"}, {9, "9m"},
	{10, "1p"}, {11, "2p"}, {12, "3p"}, {13, "4p"}, {14, "5p"}, {15, "6p"}, {16, "7p"}, {17, "8p"}, {18, "9p"},
	{19, "1s"}, {20, "2s"}, {21, "3s"}, {22, "4s"}, {23, "5s"}, {24, "6s"}, {25, "7s"}, {26, "8s"}, {27, "9s"},
	{28, "1z"}, {29, "2z"}, {30, "3z"}, {31, "4z"}, {32, "5z"}, {33, "6z"}, {34, "7z"}, {35, "x"}, {36, "x"},
	{37, "x" }, {38, "x"}
};
const std::vector<std::vector<int>> tile_pair = 
{
	{ 1,1 },{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8},{9,9},
	{ 10,10 },{11,11},{12,12},{13,13},{14,14},{15,15},{16,16},{17,17},{18,18},
	{ 19,19 },{20,20},{21,21},{22,22},{23,23},{24,24},{25,25},{26,26},{27,27},
	{ 28,28 },{29,29},{30,30},{31,31},{32,32},{33,33},{34,34}
};


class Check_Win
{
private:
	bool win_state;
	std::vector<int> matched_combo;
	std::vector<int> matched_pair;
	std::vector<std::vector<int>> ax;
	std::vector<std::vector<int>> win_group;
	std::vector<int> v_14;
	std::vector<int> v_13;
public:
	
	Check_Win()
	{
		//类的构造函数 
		win_group = { {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0} };
		win_state = false;
	}
	void check_if_win(const std::vector<int>& x);
	std::vector<std::string> check_if_ready(const std::vector<int>& x);
	int is_subset(std::vector<int> x, std::vector<int> y);
	long long C(int n, int m);
	std::vector<std::vector<int>> every_subset(const std::vector<int>& x,const int& n,const bool& f);
	void show_group(const std::vector<int>& x);
};

#endif // ! CHECK_WIN