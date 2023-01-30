#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100
#define BUFFER_SIZE 100
//��������
//�Լ��� �ܺο� ����� ������
//���α׷��� ���۵� �� �޸𸮰� �Ҵ�Ǹ� ���α׷��� ����� ������ �����ȴ�.
//data section�̶�� �θ��� �޸� ������ ��ġ�Ѵ�.

//��������
//�Լ��� ���ο� ����� ������
//�ڽ��� ���� �Լ��� ȣ��� �� �޸𸮰� �Ҵ�Ǹ� �Լ��� return�� �� �Ҹ�ȴ�
//stack�̶�� �θ��� ������ ��ġ�Ѵ�.

//�����޸��Ҵ�
//�ƹ����� malloc ���� �Լ��� ȣ���Ͽ� �ʿ��� ũ���� �޸𸮸� �Ҵ��� �� �ִ�.
//�̰��� ���� �޸� �Ҵ��̶�� �θ���.
//�������� �Ҵ�� �޸𸮴� ���̶�� �θ��� ������ ��ġ�Ѵ�.
//�������� �Ҵ�� �޸𸮴� ��������� free()�Լ��� ȣ���Ͽ� ��ȯ���� �ʴ� �� ��� �����ȴ�.
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
	//buf1�� ���ÿ� �Ҵ�� �޸��̹Ƿ� add�Լ��� return�ǰ���
	//�Ҹ�ȴ�. ���� buf1�� ����� ���ڿ��� ������ �� �迭 names[0]
	//�� ������ �迭�� �ּҸ� �����ؾ� �Ѵ�. ������ �迭�� strdup �Լ� ������
	//malloc���� heap�� �Ҵ�� �޸��̹Ƿ� add �Լ��� ����� �Ŀ��� �Ҹ����� �ʴ´�.
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
		//scanf ���� �������� �Է�
		//fget(

		if (strcmp(command, "add") == 0) add();
		else if (strcmp(command, "find") == 0)find();
		else if (strcmp(command, "status") == 0)status();
		else if (strcmp(command, "delete") == 0)remove();
		else if (strcmp(command, "exit") == 0)break;
	}
	return 0;
}
