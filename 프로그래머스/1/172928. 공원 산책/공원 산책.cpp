#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace  std;

struct Point {
	int row, col;
};

int D[4][2] = {
	{-1,0}, //North
	{1,0},  //South
	{0,-1},	//West
	{0,1}	//East
};

vector<int> solution(vector<string> park, vector<string> routes) {
	int parkRowSize = 0;
	int parkColSize = 0;
	parkRowSize = park.size()-1; //park row length
	parkColSize = park[0].length()-1; //park col length	

	int sr = 0, sc = 0; //Start Node coordinates	
	Point cur{0,0}; //Current Node

	bool endFlag = false;
	for (int i = 0; i < parkRowSize+1; i++) {
		if (endFlag) break;
		for (int j = 0; j < parkColSize+1; j++) {
			if (park[i][j] == 'S') {
				cur.row = i;	//Get Start Node Coordinates
				cur.col = j;					
				endFlag = true;
				break;
			}
		}
	}	

	int routesRowSize = routes.size();	
	for (int i = 0; i < routesRowSize; i++) {
		istringstream  iss(routes[i]); //routes[i] parsing
		char op;	//Direction
		int n=0;	//Num
		iss >> op >> n;		

		int cr = 0, cc = 0; //Current Coordinates
		cr = cur.row;
		cc = cur.col;

		if (op == 'E') { //East
			for (int j = 0; j < n; j++) {
				cc += D[3][1];
				if (cc > parkColSize || park[cr][cc] == 'X') {
					cc = cur.col;
					break;
				}
			}			
		}
		else if (op=='W') { //West
			for (int j = 0; j < n; j++) {
				cc += D[2][1];
				if (cc < 0 || park[cr][cc] == 'X') {
					cc = cur.col;
					break;
				}
			}			
		}
		else if (op == 'N') { //North
			for (int j = 0; j < n; j++) {
				cr += D[0][0];
				if (cr < 0 || park[cr][cc] == 'X') {
					cr = cur.row;
					break;
				}
			}			
		}
		else { //South
			for (int j = 0; j < n; j++) {
				cr += D[1][0];
				if (cr > parkRowSize || park[cr][cc] == 'X') {
					cr = cur.row;
					break;
				}
			}			
		}
		cur.row = cr;
		cur.col = cc;
	}

	vector<int> answer={cur.row, cur.col};
	return answer;	
}