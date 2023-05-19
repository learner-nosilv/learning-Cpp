#include "AirlineBook.h"

void AirlineBook::book() {
	cout << "***** �Ѽ��װ��� ���� ���� ȯ���մϴ� *****" << '\n' << '\n';
	while(true){
		int menu = Console::chooseMenu();
		switch (menu) {
			case 1: {									// 1. ����
				int time = Console::chooseTime();		// �ð� ����
				time--;
				plain[time].showReservation();			// �ش� �ð��� ������
				int seat = Console::chooseSeat();		// �¼� ����
				seat--;
				string name = Console::chooseName();	// �̸� �Է�
				plain[time].reservation(seat, name);	// ���� ����
				break;
			}
			case 2: {									// 2. ���
				int time = Console::chooseTime();		// �ð� ����
				time--;
				plain[time].showReservation();			// �ش� �ð��� ������
				int seat = Console::chooseSeat();		// �¼� ����
				seat--;
				string name = Console::chooseName();	// �̸� �Է�
				plain[time].cancle(seat, name);			// ��� ����
				break;
			}
			case 3:										// 3. ����
				for (int i = 0; i < 3; i++)
					plain[i].showReservation();
				break;
			case 4:										// 4. ������
				cout << "���� �ý����� �����մϴ�." << endl;
				return;
		}
		cout << endl;
	}
}