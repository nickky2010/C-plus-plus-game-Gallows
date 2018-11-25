//                          ����. �������� - ��������������� ���������������� �� C++.
//                                             ���� "��������"
#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
class Gallows
{
private:
	struct Data // ��������� ������
	{
		char* w;
		Gallows *next;
	} word;
public:
	static int score;
	Gallows()                      // ����������� �� ���������
	{
	}
	~Gallows()                     // ����������
	{
	}
	void clear(Gallows *&head) {               // ������������ ������ ��� �������
		while (head != NULL) {
			Gallows *tmp = head;
			head = head->word.next;
			delete tmp;
		}
	}
	void creatArray(Gallows *&head, Gallows **&mas, int kol) {// �������� ������� ���������� �� �������� ������
		mas = new Gallows*[kol];                              // �������� ������ ��� ������ ����������
		int i = kol - 1;
		while (head != NULL) {
			mas[i] = head;
			i--;
			head = head->word.next;
		}
		clear(head);                                            // ������� ������
	}
	void readData(FILE *in, Gallows *&head, Gallows **&mas, int &kol) {          // ������ ������ �� ����� � ������
		const int BUFFER = 128;
		char filename[BUFFER] = "1.TXT";
		cout << "������� ��� ����� ��� ������: ";
		cin >> filename;
		if (fopen_s(&in, filename, "r") != 0) {
			cout << "�� ������� ������� ���� " << filename << " ��� ������\n";
			system("pause");
			exit(1);
		}
		char buffer[BUFFER];
		kol = 0;
		while (fgets(buffer, BUFFER, in) != NULL) {
			char *word, *next;
			word = strtok_s(buffer, ",. ", &next);
			int len = strlen(word) + 1;
			Gallows *tmp = new Gallows;
			tmp->word.w = new char[len];
			strcpy_s(tmp->word.w, len, word);
			tmp->word.next = head;
			head = tmp;
			kol++;
			while (*next != NULL) {
				word = strtok_s(NULL, ",. ", &next);
				int len = strlen(word) + 1;
				if (word[len] == '\n') word[len] = '\0';
				if (*word != '\n') {
					Gallows *tmp = new Gallows;
					tmp->word.w = new char[len];
					strcpy_s(tmp->word.w, len, word);
					tmp->word.next = head;
					head = tmp;
					kol++;
				}
			}
		}
		head->creatArray(head, mas, kol);
		if (fclose(in) != 0)
		{
			cout << "������ �������� ����� ��� ������\n";
			system("pause");
			exit(2);
		}
		cout << "������ ������� ��������� �� ����� " << filename << "\n";
		system("pause");
	}
	int init_Rand(int max, int min) {                             // �������, ��������������� ������������� ��������� ����� 
		int number = rand() % max + min;
		return number;
	}
	void terra_incognita(Gallows **mas, int kol, char*&word, int &len) {    // �������� ��������� �����
		word = mas[init_Rand(kol, 0)]->word.w;
		len = strlen(word);
	}
	void print_win() {
		cout << endl;
		cout << "\\\\\\                            ///        |||        |||\\\\\\        |||\n";
		cout << " \\\\\\                          ///                    ||| \\\\\\       |||\n";
		cout << "  \\\\\\                        ///                     |||  \\\\\\      |||\n";
		cout << "   \\\\\\                      ///           |||        |||   \\\\\\     |||\n";
		cout << "    \\\\\\                    ///            |||        |||    \\\\\\    |||\n";
		cout << "     \\\\\\      ///\\\\\\      ///             |||        |||     \\\\\\   |||\n";
		cout << "      \\\\\\    ///  \\\\\\    ///              |||        |||      \\\\\\  |||\n";
		cout << "       \\\\\\  ///    \\\\\\  ///               |||        |||       \\\\\\ |||\n";
		cout << "        \\\\\\///      \\\\\\///                |||        |||        \\\\\\|||\n";
	}
	void print_gallows(int kol) {                                 // ������ ��������
		if (kol == 0) {
			cout << "                 ============\n";
			cout << "                 |          |\n";
			cout << "                            |\n";
			cout << "                            |\n";
			cout << "                            |\n";
			cout << "                            |\n";
			cout << "                            |\n";
			cout << "                            |\n";
			cout << "                         ======\n";
		}
		if (kol == 1) {
			cout << "                 ============\n";
			cout << "                 |          |\n";
			cout << "                 O          |\n";
			cout << "                            |\n";
			cout << "                            |\n";
			cout << "                            |\n";
			cout << "                            |\n";
			cout << "                            |\n";
			cout << "                         ======\n";
		}
		if (kol == 2) {
			cout << "                 ============\n";
			cout << "                 |          |\n";
			cout << "                 O          |\n";
			cout << "                 |          |\n";
			cout << "                 |          |\n";
			cout << "                 |          |\n";
			cout << "                            |\n";
			cout << "                            |\n";
			cout << "                         ======\n";
		}
		if (kol == 3) {
			cout << "                 ============\n";
			cout << "                 |          |\n";
			cout << "                 O          |\n";
			cout << "                 |/         |\n";
			cout << "                 |          |\n";
			cout << "                 |          |\n";
			cout << "                            |\n";
			cout << "                            |\n";
			cout << "                         ======\n";
		}
		if (kol == 4) {
			cout << "                 ============\n";
			cout << "                 |          |\n";
			cout << "                 O          |\n";
			cout << "                \\\|/         |\n";
			cout << "                 |          |\n";
			cout << "                 |          |\n";
			cout << "                            |\n";
			cout << "                            |\n";
			cout << "                         ======\n";
		}
		if (kol == 5) {
			cout << "                 ============\n";
			cout << "                 |          |\n";
			cout << "                 O          |\n";
			cout << "                \\|/         |\n";
			cout << "                 |          |\n";
			cout << "                 |\\         |\n";
			cout << "                            |\n";
			cout << "                            |\n";
			cout << "                         ======\n";
		}
		if (kol == 6) {
			cout << "                 ============\n";
			cout << "                 |          |\n";
			cout << "                 O          |\n";
			cout << "                \\|/         |\n";
			cout << "                 |          |\n";
			cout << "                /|\\         |\n";
			cout << "                            |\n";
			cout << "                            |\n";
			cout << "                         ======\n";
		}
	}
	void print_alphabet() {
		char alphabet[33] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
			'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
		for (int i = 0; i < 33; i++) {
			if (i<32)
				cout << alphabet[i] << " ";
			else
				cout << alphabet[i] << endl;
		}
	}
	void init_tmp_alphabet(char tmp[], char tmp_used_char[]) {
		char alphabet[33] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
			'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
		for (int i = 0; i < 33; i++) {
			tmp[i] = alphabet[i];
			tmp_used_char[i] = ' ';
		}
	}
	void print_alphabet(char simv, char tmp[], char tmp_used_char[]) {
		for (int i = 0; i < 33; i++) {
			if (tmp[i] == simv || tmp[i] == simv - 32) {
				tmp_used_char[i] = tmp[i];
				tmp[i] = ' ';
			}
			if (i<32)
				cout << tmp[i] << " ";
			else
				cout << tmp[i] << endl;
		}
	}
	void print_tmp_used_char(char tmp_used_char[]) {
		bool f = false;
		for (int i = 0; i < 33; i++) {
			if (tmp_used_char[i] == ' ') {
				continue;
			}
			else
				if (f) cout << ", " << tmp_used_char[i];
				else {
					cout << tmp_used_char[i];
					f = true;
				}
		}
		cout << endl;
	}
	void init_tmp_incognita_word(char tmp[], int len) {
		for (int i = 0; i < len+1; i++) {
			if (i != len) tmp[i] = '*';
			else tmp[i] = '\0';
		}
	}
	void check_error_win(char*word, char tmp_word[], char simv, int len, int &error, bool &win, int &score_tmp, bool tmp_check[]) {
		bool f = false;
		for (int i = 0; i < len; i++) {
			if (simv == word[i] || simv+32 == word[i] || simv - 32 == word[i]) {
				tmp_word[i] = simv;
				if (tmp_check[i] == false) {
					score++;
					score_tmp++;
					tmp_check[i] = true;
				}
				f = true;
			}
		}
		if (f == false) error++;
		for (int i = 0; i < len; i++) {
			if (tmp_word[i] == word[i] || tmp_word[i] + 32 == word[i] || tmp_word[i] - 32 == word[i]) {
				win = true;
			}
			else {
				win = false;
				break;
			}
		}
	}
	void show_tmp_word(char tmp[], int len) {
		for (int i = 0; i < len; i++) {
			cout << tmp[i];
		}
		cout << endl;
	}
};
int Gallows::score = 0;
void quit() {                          // ������� ������
	cout << "���������� ������!\n";
	system("pause");
	exit(0);
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	FILE *in;
	Gallows **mas;
	Gallows *head = NULL;
	char* word, tmp_word[41], simv, tmp_alphabet[33], tmp_used_char[33];
	int kol = 0, error = 0, len, v, score_tmp = 0;
	bool win = false, tmp_check[40] = { 0 };
	cout << "\t\t\t���� ��������\n\n";
	cout << "���������� ������ ������ � ����\n";
	head->readData(in, head, mas, kol);                  // ��������� ������ �� �����
	system("cls");
	while (v) {
		head->terra_incognita(mas, kol, word, len);      // �������� ��������� �����
		head->init_tmp_incognita_word(tmp_word, len);
		head->init_tmp_alphabet(tmp_alphabet, tmp_used_char);
		while (error != 6) {
			system("cls");
			cout << "\t\t\t���� ��������\n\n";
			if (error == 0) {
				if(score_tmp==0)head->print_alphabet();
				else head->print_alphabet(simv, tmp_alphabet, tmp_used_char);
			}
			else {
				head->print_alphabet(simv, tmp_alphabet, tmp_used_char);
			}
			head->print_gallows(error);
			cout << "\n\n���������� �����: "; head->show_tmp_word(tmp_word, len);
			cout << "����: " << score_tmp << endl;
			cout << "���������� ������: " << error << endl;
			if (error != 0 || score_tmp!=0) { 
				cout << "��������� �����: "; 
				head->print_tmp_used_char(tmp_used_char); 
			}
			cout << "������� �����: ";
			cin >> simv;
			head->check_error_win(word, tmp_word, simv, len, error, win, score_tmp, tmp_check);
			if (win) {
				system("cls");
				cout << "\t\t\t���� ��������\n\n";
				head->print_alphabet(simv, tmp_alphabet, tmp_used_char);
				head->print_win();
				cout << "\n\n���������� �����: "; head->show_tmp_word(tmp_word, len);
				cout << "����: " << score_tmp << endl;
				cout << "���������� ������: " << error << endl;
				cout << "��������� �����: "; head->print_tmp_used_char(tmp_used_char);
				cout << "\n����������� ��� �������!!!!\n";
				cout << "����� ��������� ����� �� ������: " << head->score << endl;
				break;
			}
			else if (error == 6) {
				system("cls");
				cout << "\t\t\t���� ��������\n\n";
				head->print_alphabet(simv, tmp_alphabet, tmp_used_char);
				head->print_gallows(error);
				cout << "\n\n���������� �����: " << word << endl;
				cout << "����: " << score_tmp << endl;
				cout << "���������� ������: " << error << endl;
				cout << "��������� �����: "; head->print_tmp_used_char(tmp_used_char);
				cout << "\n�� ��������� � ��� ��������!\n";
				cout << "����� ��������� ����� �� ������: " << head->score << endl;
			}
		}
		error = 0;
		win = false;
		score_tmp = 0;
		for (int i = 0; i < 40; i++) 
			tmp_check[i] = false;
		cout << "\n\n������� ���������� ����???\n";
		do {
			cout << "1 - ��\t0 - ���\n";
			cout << "��� �����: ";
			cin >> v;
			if (v != 0 && v != 1)
				cout << "\n������! �������� ����! ������� 0 ��� 1!\n";
		} while (v != 0 && v != 1);
	}
	cout << "\n�� ����� ������!\n";
	system("pause");
	return 0;
}
