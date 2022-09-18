#include<iostream>
using namespace std;

string solve(string s,string p){

	int cnt = 0;
	int start = 0;
	int min_len = INT_MAX;
	int start_index = -1;

	int fs[26] = {0}; //freq array for string s
	int fp[26] = {0}; //freq array for string p

	//first store the count of char of p string , so that we can compare the char from string s
	for(int i = 0; i<p.size(); i++){
		fp[p[i]]++;
	}
	//now traverse on the main string which is s 
	for(int i = 0; i<s.size(); i++){
		fs[s[i]]++;

		if(fp[s[i]] != 0 and fs[s[i]] <= fp[s[i]]){
			cnt++;
		}
		//if count becomes equal to the length of pattern len
		if(cnt == p.size()){

			while(fp[s[start]] == 0 or fs[s[start]] > fp[s[start]]){
				fs[s[start]]--;
				start++;
			}
			//calculate the current window length
			int currentWindow = i-start+1;
			if(currentWindow < min_len){
				min_len = currentWindow;
				start_index = start; // need of strat index is that we have to return the smallest substring
			}
		}
	}
	if(start_index == -1){
		return "NOT FOUND";
	}
	else{
		return s.substr(start_index,min_len);
	}
}

int main(){

	string s = "hello";
	string p = "lol";
	string ans = solve(s,p);
	cout<<ans;
	return 0;
}