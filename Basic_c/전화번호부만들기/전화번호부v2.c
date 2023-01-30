#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAPACITY 100
#define BUFFER_SIZE 20

struct directory {
	char* names[CAPACITY];
	char* numbers[CAPACITY];
}dirt;
int n = 0;
void add() {
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	scanf("%s", buf1);
	scanf("%s", buf2);
	int i = n - 1;
	while (i >= 0 && strcmp(dirt.names[i], buf1) > 0) {
		dirt.names[i + 1] = dirt.names[i];
		dirt.numbers[i + 1] = dirt.numbers[i];
		i--;
	}
	dirt.names[i+1] = strdup(buf1);
	dirt.numbers[i+1] = strdup(buf2);

	printf("'%s' was added successfully.\n", dirt.names[n]);
	n++;
}
void find() {
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	int index = search(buf);
	if (index == -1)printf("No person named '%s' exists.\n", buf);
	else printf("%s\n", dirt.numbers[index]);
}
void remove() {
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	int index = search(buf); // returns -1 if not exists
	if (index == -1) {
		printf("No person named '%s' exists.\n", buf);
		return;
	}
	
	for (int j = index; j < n - 1; j++) {
		dirt.names[j] = dirt.names[j + 1];
		dirt.numbers[j] = dirt.numbers[j + 1];
	}
	n--;
	printf("'%s' was deleted successfully.\n", buf);
}
int search(char* name) {
	int i;
	for (i = 0; i < n; i++) {
		if (strcmp(name, dirt.names[i]) == 0) {
			return i;
		}
	}
	return -1;
}
void status() {
	int i;
	for (i = 0; i < n; i++)printf("%s %s\n", dirt.names[i], dirt.numbers[i]);
}
void read() {

}
void load() {
	char fileName[BUFFER_SIZE];
	char buf1[BUFFER_SIZE];
	char buf2[BUFFER_SIZE];

	scanf("%s", fileName);
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}

	while ((fscanf(fp, "%s", buf1) != EOF)) {
		fscanf(fp, "%s", buf2);
		dirt.names[n] = strdup(buf1);
		dirt.numbers[n] = strdup(buf2);
		n++;
	}
	fclose(fp);
}
void save() {
	char fileName[BUFFER_SIZE];
	char tmp[BUFFER_SIZE];

	scanf("%s", tmp);
	scanf("%s", fileName);
	FILE* fp = fopen(fileName, "w");
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%s %s\n", dirt.names[i], dirt.numbers[i]);
	}
	fclose(fp);
}
int main() {
	char command[BUFFER_SIZE];

	while (1) {
		scanf("%s", command);
		if (strcmp(command, "add") == 0)add();
		else if (strcmp(command, "find") == 0)find();
		else if (strcmp(command, "delete") == 0)remove();
		else if (strcmp(command, "status") == 0)status();
		else if (strcmp(command, "save") == 0)save();
		else if (strcmp(command, "read") == 0)load();
		else if (strcmp(command, "exit") == 0)break;
	}
}

//bubble sort 등의 정렬 알고리즘을 사용하는 방법
//새로운 데이터가 계속적으로 추가되는 우리의 상황에서는 부적절
//새로운 데이터가 추가될 때마다 제자리를 찾아서 삽입하는 방법
