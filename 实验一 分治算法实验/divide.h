#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<Windows.h>

using namespace std;

bool readfile(vector<int>& T);

void merge_sort(vector<int>& T, int head, int tail);
void merge(vector<int>& T, int head, int mid, int tail);


