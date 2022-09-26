#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


bool checkLenght(char* point1[], char* point2[],int i,int j) {
	int count1;
	int count2;
	for (count1 = 0; point1[i][count1] != '\0';count1++) {}
	for (count2 = 0; point2[j][count2] != '\0';count2++) {}
	if (count1 == count2)
		return true;
	else
		return false;
}

bool checkSameWords(char* point1[], char* point2[], int i, int u) {
	for (int count = 0; point1[i][count] != '\0';count++) {
		if (point1[i][count] != point2[u][count])
			return false;
	}
	return true;
}

int main() {
	char text[256];
	char* pointer[15];
	int wordCount = 0;
	fgets(text,256,stdin);
	int i = 0;
	while (text[i] != '\n') {
		//i++;
		if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
			int countA = 0;
			for (int c = i;(text[c] >= 'A' && text[c] <= 'Z') || (text[c] >= 'a' && text[c] <= 'z');c++) {
				countA++;
			}
			pointer[wordCount] = (char*)malloc(countA + 1);
			pointer[wordCount][countA] = '\0';
			int sim = i;
			for (int c2 = 0;pointer[wordCount][c2] != '\0';c2++) {
				pointer[wordCount][c2] = text[sim];
				sim++;
			}
			i = sim;
			wordCount++;
			if (text[i] == '\n')
				break;
		}
		else {
			i++;
			continue;
		}
	}
	int k = 0;
	int u = 0;
	bool heh = false;
	for (k = 0;k < wordCount-1;k++) {
		if (heh == true) {
			free(pointer[k-1]);
			pointer[k-1] = NULL;
			heh = false;
		}

		if (pointer[k] == NULL)
			continue;
		for (u = k + 1;u < wordCount;u++) {
			if (pointer[u] == NULL)
				continue;
			if (checkLenght(pointer, pointer, k, u))
				if (checkSameWords(pointer, pointer, k, u)) {
					//free(pointer[k]);
					free(pointer[u]);
					//pointer[k] = NULL;
					pointer[u] = NULL;
					heh = true;
				}
		}
			
	}
	for (int i = 0;i < wordCount; i++) {
		if (pointer[i] == NULL)
			continue;
		printf("%s ", pointer[i]);
	}
	//checkLenght(pointer, pointer,k,u);
	for(int i = 0;i < wordCount; i++)
	free(pointer[i]);
	return 0;
}