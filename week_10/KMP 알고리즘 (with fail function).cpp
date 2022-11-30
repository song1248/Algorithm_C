#include <iostream>
#include <stdio.h>

using namespace std;
int* f;
int* answer;
int answer_len;


int getFail(char* pattern, int pattern_len){
    int j=0;
    for(int i=1; i<pattern_len; i++){
        while(j>0 && pattern[i] != pattern[j]){
            j = f[j-1];
        }
        if (pattern[i] == pattern[j]){
            f[i] = ++j;
        }
    }
    return 0;
}

int kmp(char* text, char* pattern, int text_len, int pattern_len){
    int ans_num = 0;
    int n = text_len;
	int m = pattern_len;
    int j = 0;

    for (int i=0; i<n; i++){
        while(j>0 && text[i] != pattern[j]){
            j = f[j-1];
        }
        if (text[i] == pattern[j]){
            if (j==m-1){
            	answer_len++;
                j = f[j];
            }
            else
                j++;
        }
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        char* text = new char[1000]();
		char* pattern = new char[1000]();

        cin >> pattern >> text;
		
		int i = 0;
		int text_len = 0;
		while (text[i++]) text_len = i;
		i = 0;
		int pattern_len = 0;
		while (pattern[i++]) pattern_len = i;	
		
		f = new int[pattern_len]();
		
		answer_len = 0;
		
        getFail(pattern, pattern_len);
        kmp(text, pattern, text_len, pattern_len);
		
		
        for(int i=0; i< pattern_len; i++){
            cout << f[i] << " ";
        }
        cout << endl;

        cout << answer_len << endl;
    }
}
