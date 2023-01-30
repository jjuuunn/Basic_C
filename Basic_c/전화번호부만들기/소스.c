#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100
#define BUFFER_SIZE 100
//전역변수
//함수의 외부에 선언된 변수들
//프로그램이 시작될 때 메모리가 할당되며 프로그램이 종료될 때까지 유지된다.
//data section이라고 부르는 메모리 영역에 위치한다.

//지역변수
//함수의 내부에 선언된 변수들
//자신이 속한 함수가 호출될 때 메모리가 할당되며 함수가 return될 대 소멸된다
//stack이라고 부르는 영역에 위치한다.

//동적메모리할당
//아무때나 malloc 등의 함수를 호출하여 필요한 크기의 메모리를 할당할 수 있다.
//이것을 동적 메모리 할당이라고 부른다.
//동적으로 할당된 메모리는 힙이라고 부르는 영역에 위치한다.
//동적으로 할당된 메모리는 명시적으로 free()함수를 호출하여 반환하지 않는 한 계속 유지된다.
char* names[CAPACITY];
char* numbers[CAPACITY];
int n = 0;

void add() {
	char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
	scanf("%s", buf1);
	scanf("%s", buf2);
	names[n] = strdup(buf1);
	numbers[n] = strdup(buf2);
	n++;
	printf("%s was added successfully.\n", buf1);
	//buf1은 스택에 할당된 메모리이므로 add함수가 return되고나면
	//소멸된다. 따라서 buf1에 저장된 문자열을 복제한 후 배열 names[0]
	//에 복제된 배열의 주소를 저장해야 한다. 복제된 배열은 strdup 함수 내에서
	//malloc으로 heap에 할당된 메모리이므로 add 함수가 종료된 후에도 소멸하지 않는다.
};
void find() {
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	for (int i = 0; i < n; i++) {
		if (strcmp(buf, names[i]) == 0) {
			printf("%s\n", numbers[i]);
			return;
		}
	}
	printf("No person named '%s' exists.\n", buf);
};
void status() {
	int i;
	for (i = 0; i < n; i++)
		printf("%s %s\n", names[i], numbers[i]);
	printf("Total %d persons.\n", n);
};
void remove() {
	char buf[BUFFER_SIZE];
	scanf("%s", buf);
	for (int i = 0; i < n; i++) {
		if (strcmp(buf, names[i]) == 0) {
			names[i] = names[n - 1];
			numbers[i] = numbers[n - 1];
			n--;
			printf("'%s' was deleted successfully.\n", buf);
			return;
		}
	}
	printf("No person named '%s' exists.\n", buf);
};
int main(void) {
	char command[BUFFER_SIZE];
	while (1) {
		printf("$ ");
		scanf("%s", command);
		//scanf 띄어쓰기 기준으로 입력
		//fget(

		if (strcmp(command, "add") == 0) add();
		else if (strcmp(command, "find") == 0)find();
		else if (strcmp(command, "status") == 0)status();
		else if (strcmp(command, "delete") == 0)remove();
		else if (strcmp(command, "exit") == 0)break;
	}
	return 0;
}
