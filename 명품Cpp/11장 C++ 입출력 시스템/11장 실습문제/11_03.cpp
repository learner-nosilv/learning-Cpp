/* 3. �����;�ѱ۹��� �������� �Էµ� ��, ; ���Ŀ� �Էµ� ���ڿ��� ���, ctrl+Z�� ^Z�� �Է����Ḧ ��Ÿ����.
cin.ignore()��, cin.get() ����ϱ�*/
#include <iostream>

int main() {
	int ch;
	while ((ch=std::cin.get()) != EOF) {	// ctrl+Z �� �ԷµǸ� ��, �� ���� �ԷµǾ� ���۷� �� ��
		std::cin.ignore(99, ';');			// delimiter �ձ��� ���ۺ��� & delimter�� ����
		char arr[31];
		std::cin.get(arr, 31, '\n');		// delimiter �ձ��� or �ѱ� 15���ڸ� �迭�� ����
		std::cout << arr << (char)std::cin.get();
	}
	return 0;
}

// ��: �迭����ؼ� cin.get(�迭��, ���ڰ���, delimiter) �ߴµ�, �ַ���� �ǰ� ������

/* �ٽ� �� ��!
#include <iostream>

int main() {
	int ch;
	std::cin.ignore(100, ';');				// ���۰� ����������� �Է¹ް�, �ִ� 100���� ����, ���� delimiter ;�� ������ delimiter������ ����
	while ((ch = std::cin.get()) != EOF) {	// ���ۿ� �����ִ� ���ڰ� ��� get�� �Ұ��ϸ� ctrl+Z �� �ԷµǸ� ��, �� ���� �ԷµǾ� ���۷� �� ��
		std::cout << (char)ch;				// ; ������ �ѱ� ���(�ѱ��� 2byte�̹Ƿ� cout<< �ι��� �ѱ��ھ� ��µ�-������ ������� ��µ�
		if (ch == '\n') std::cin.ignore(100, ';');
	}
	return 0;
}
*/