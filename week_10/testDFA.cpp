#include <iostream>
#define MAX_SIZE 1001
using namespace std;

int num,count;
int DFA[3][MAX_SIZE];
char pattern[MAX_SIZE], text[MAX_SIZE];
int text_len;
int pattern_len;

int wordToInt(char state){

	if (state=='A')
		return 0;
	if (state=='B')
		return 1;
	if (state=='C')
		return 2;
    else
        return -1;
}


int strlen(char* s){
    int l = 0;
    for(int i = 0; i < MAX_SIZE; i++){
        if(s[i] == '\0') break;
        else l++;
    }
    return l;
}


void constructDFA(){
    int X, j;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j <= pattern_len; j++){
            DFA[i][j] = 0;
        }
    }
    DFA[wordToInt(pattern[0])][0] = 1;
    for ( X = 0,j = 1; j < pattern_len; j++){
        for (int c = 0; c < 3; c++)
            DFA[c][j] = DFA[c][X];
      
        DFA[wordToInt(pattern[j])][j] = j + 1;
        X = DFA[wordToInt(pattern[j])][X];
    }
    for (int c = 0; c < 3; c++)
        DFA[c][j] = DFA[c][X];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j <= pattern_len; j++){
            if (DFA[i][j] != 0)
                num++;
        }
    }
}

void KMP(){
    int i, j;
    for (i = 0,j=0; i < text_len; i++){
        j = DFA[wordToInt(text[i])][j];
        if (j == pattern_len){
            count++;
        }
    }
}

int main(){
	int tc;
    cin >> tc;
    while (tc--){
    	
        cin >> pattern >> text;
        text_len = strlen(text);
        pattern_len = strlen(pattern);

        num = 0;
		count = 0;
        constructDFA();
        KMP();
        
        cout << num << " " << count << '\n';
    }
}
