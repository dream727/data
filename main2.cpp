#include<fstream>
#include<string>
#include<io.h>
#include<ctime>
#include<iostream>
#include<vector>
#pragma warning( disable : 4996 )

using namespace std;

void getTime(string& _string);
void menu();

//������
class Data
{
public:
	//����
	string time;
	//�¼�
	string things;
};

class Save
{
public:
	//���õ�����
	int SelectedLine = 0;
	//���õ�·��
	string setPathTime;
	string setPathThings;
};

int main()
{
	//�����ļ���
	string folderPath = "D:\\databyDream";
	if (_access(folderPath.c_str(), 0) == -1)
	{
		string command;
		command = "mkdir -p " + folderPath;
		system(command.c_str());
		cout << "�����ɹ�" << endl;
	}
	Data dataObj;
	dataObj.time = "\0";
	dataObj.things = "\0";

	string tempInput1 = "\0";//��ʱ���������ַ���
	string tempInput2 = "\0";//��ʱ���������ַ���

	char inputY[4];
	char inputYM[7];
	char inputM[2];
	char inputYMD[10];

	int lineNum = 1;

	Save save;

	save.setPathTime = "D://databyDream//Time.txt";
	save.setPathThings = "D://databyDream//Things.txt";
	save.SelectedLine = 0;

	char key1 = '0';//ָ��

	ifstream ifs;
	ifstream SelectedIfs;
	ifstream SelectedDatIfs;
	ofstream ofs;
	ofstream ofs2;

	string& s = dataObj.time;

	//����string������
	vector<string> timeV;
	vector<string> thingsV;

	ifs.open("D://databyDream//setdata.txt", ios::in);
	if (!ifs.is_open())
	{
		ofs.open("D://databyDream//setdata.txt", ios::out);
		ofs << save.SelectedLine << endl;
		ofs << save.setPathTime << endl;
		ofs << save.setPathThings << endl;
		ofs.close();
	}
	else
	{
		ifs >> save.SelectedLine;
		ifs >> save.setPathTime;
		ifs >> save.setPathThings;
	}
	ifs.close();

	while (true)
	{
		menu();
		key1 = 0;
		cin >> key1;
		if (key1 == '1')
		{
			cout << "���������ڸ�ʽ20xx.xx.xx.xx:xx������1��ȡ��ǰʱ�䣩" << endl;
			cin >> dataObj.time;
			cout << "�������¼�" << endl;
			cin >> dataObj.things;
			if (dataObj.time == "1")
			{
				getTime(s);
			}
			cout << "�����" << endl;
			//�洢��־����
			ofs.open(save.setPathTime, ios::app);
			ofs << dataObj.time << endl;
			ofs.close();

			ofs.open(save.setPathThings, ios::app);
			ofs << dataObj.things << endl;
			ofs.close();
			save.SelectedLine++;
			system("pause");
			system("cls");
		}
		else if (key1 == '2')
		{
			cout << "�޸�ʱ��/�¼�/���޸�(1/2/3)" << endl;
			cin >> key1;
			lineNum = 1;
			ifs.open(save.setPathTime, ios::in);
			SelectedIfs.open(save.setPathThings, ios::in);
			while (getline(ifs , tempInput1))
			{
				getline(SelectedIfs,tempInput2);
				timeV.push_back(tempInput1);
				thingsV.push_back(tempInput2);
			}
			if (key1 == '1')
			{
				cout << "�������޸�����" << endl;
				cin >> lineNum;
				cout << "�������޸����� ��ʽ20xx.xx.xx.xx:xx(����1��ȡ��ǰʱ��)" << endl;
				cin >> tempInput1;
				if (tempInput1 == "1")
				{
					getTime(tempInput1);
				}
				timeV[lineNum - 1] = tempInput1;
			}
			else if (key1 == '2')
			{
				cout << "�������޸�����" << endl;
				cin >> lineNum;
				cout << "�������޸�����" << endl;
				cin >> tempInput2;
				thingsV[lineNum - 1] = tempInput2;
			}
			else if (key1 == '3')
			{
				cout << "�������޸�����" << endl;
				cin >> lineNum;
				cout << "�������޸�ʱ�� ��ʽ20xx.xx.xx.xx:xx(����1��ȡ��ǰʱ��)" << endl;
				cin >> tempInput1;
				if (tempInput1 == "1")
				{
					getTime(tempInput1);
				}
				cout << "�������޸�����" << endl;
				cin >> tempInput2;
				timeV[lineNum - 1] = tempInput1;
				thingsV[lineNum - 1] = tempInput2;
			}
			else
			{
				cout << "ָ�����" << endl;
			}
			cout << "���Ե�" << endl;
			ofs.open(save.setPathTime, ios::out);
			ofs2.open(save.setPathThings, ios::out);
			for (vector<string>::iterator i = timeV.begin(), end = timeV.end(); i != end; ++i)
			{
				ofs << (*i) << endl;
			}
			for (vector<string>::iterator i = thingsV.begin(), end = thingsV.end(); i != end; ++i)
			{
				ofs2 << (*i) << endl;
			}
			ofs.close();
			ofs2.close();
			vector<string>().swap(timeV);
			vector<string>().swap(thingsV);
			lineNum = 1;
			tempInput1 = '\0';
			tempInput2 = '\0';
			cout << "�����" << endl;
			system("pause");
			system("cls");
		}
		else if (key1 == '3')
		{
			lineNum = 1;
			ifs.open(save.setPathTime,ios::in);
			SelectedIfs.open(save.setPathThings, ios::in);
			while (getline(ifs , tempInput1))
			{
				getline(SelectedIfs , tempInput2);
				timeV.push_back(tempInput1);
				thingsV.push_back(tempInput2);
			}
			cout << "������Ҫɾ��������" << endl;
			cin >> lineNum;
			cout << "���Ե�" << endl;
			timeV.erase(timeV.begin() + (lineNum-1));
			thingsV.erase(thingsV.begin() + (lineNum - 1));
			//��������
			//for (vector<string>::iterator iter = timeV.begin(); iter != timeV.end(); iter++)
			//{
			//	cout << *iter<< endl;
			//}
			ifs.close();
			SelectedIfs.close();
			ofs.open(save.setPathTime, ios::out);
			ofs2.open(save.setPathThings, ios::out);
			
			for (vector<string>::iterator i = timeV.begin(), end = timeV.end(); i != end; ++i)
			{
				ofs << (*i) << endl;
			}
			for (vector<string>::iterator i = thingsV.begin(), end = thingsV.end(); i != end; ++i)
			{
				ofs2 << (*i) << endl;
			}
			ofs.close();
			ofs2.close();
			vector<string>().swap(timeV);
			vector<string>().swap(thingsV);
			lineNum = 1;
			tempInput1 = '\0';
			tempInput2 = '\0';
			cout << "�����" << endl;
			system("pause");
			system("cls");
		}
		else if (key1 == '4')
		{
			cout << "�鿴ȫ��/�鿴������1/2��" << endl;
			cin >> key1;
			if (key1 == '1')
			{
				system("cls");
				lineNum = 1;
				ifs.open(save.setPathTime, ios::in);
				SelectedIfs.open(save.setPathThings, ios::in);
				while (getline(ifs , tempInput1))
				{
					getline(SelectedIfs , tempInput2);
					cout << lineNum << ".ʱ��[" << tempInput1 << "]����:" << tempInput2 << endl;
					lineNum++;
				}
				ifs.close();
				SelectedIfs.close();
				lineNum = 1;
				tempInput1 = '\0';
				tempInput2 = '\0';
			}
			else if (key1 == '2')
			{
				int a;
				cout << "����������" << endl;
				cin >> a;
				lineNum = 1;
				ifs.open(save.setPathTime, ios::in);
				SelectedIfs.open(save.setPathThings, ios::in);
				while (getline(ifs , tempInput1))
				{
					getline(SelectedIfs , tempInput2);
					if (lineNum == a)
					{
						cout << lineNum << ".ʱ��[" << tempInput1 << "]����:" << tempInput2 << endl;
					}
					lineNum++;
				}
				ifs.close();
				SelectedIfs.close();
				lineNum = 1;
				tempInput1 = '\0';
				tempInput2 = '\0';
			}
			else
			{
				cout << "ָ������" << endl;
			}
			system("pause");
			system("cls");
		}
		else if (key1 == '5')
		{

			cout << "��ʱ��·����Ҫ�Ȱ�data�ļ�����ָ��·����" << endl;
			cin >> save.setPathTime;
			save.setPathThings = save.setPathTime;
			cout << "�����" << endl;
			ofs.open("D://databyDream//setdata.txt", ios::out);
			ofs << save.SelectedLine << endl;
			ofs << save.setPathTime << endl;
			ofs << save.setPathThings << endl;
			ofs.close();
			system("pause");
			system("cls");
		}
		else if (key1 == '6')
		{
			cout << "����ʱ�� �������/����/�����·�/������(1/2/3/4)" << endl;
			cin >> key1;
			SelectedDatIfs.open(save.setPathThings, ios::in);
			SelectedIfs.open(save.setPathTime, ios::in);
			if (key1 == '1')
			{
				cout << "������� 20xx" << endl;
				//��ʱ�����ݴ����tempInput1Ȼ����tempInput1�����ж�
				cin >> inputY;
				while (getline(SelectedIfs , tempInput1))
				{
					getline(SelectedDatIfs , tempInput2);
					if ((inputY[0] == tempInput1[0]) && (inputY[1] == tempInput1[1]) && (inputY[2] == tempInput1[2]) && (inputY[3] == tempInput1[3]))
					{
						cout << "����" << lineNum << "��־ʱ��[" << tempInput1 << "]����:" << tempInput2 << endl;
					}
					lineNum++;
				}
				lineNum = 1;
				tempInput1 = '\0';
				tempInput2 = '\0';

				system("pause");
				system("cls");
			}
			else if (key1 == '2')
			{
				cout << "�������� 20xx.xx" << endl;
				//��ʱ�����ݴ����tempInput1Ȼ����tempInput1�����ж�
				cin >> inputYM;
				while (getline(SelectedIfs , tempInput1))
				{
					getline(SelectedDatIfs , tempInput2);
					if ((inputYM[0] == tempInput1[0]) && (inputYM[1] == tempInput1[1]) && (inputYM[2] == tempInput1[2]) && (inputYM[3] == tempInput1[3]) && (inputYM[5] == tempInput1[5]) && (inputYM[6] == tempInput1[6]))
					{
						cout << "����" << lineNum << "��־ʱ��[" << tempInput1 << "]����:" << tempInput2 << endl;
					}
					lineNum++;
				}
				lineNum = 1;
				tempInput1 = '\0';
				tempInput2 = '\0';
				system("pause");
				system("cls");
			}
			else if (key1 == '3')
			{
				cout << "�����·� xx" << endl;
				//��ʱ�����ݴ����tempInput1Ȼ����tempInput1�����ж�
				cin >> inputM;
				while (getline(SelectedIfs , tempInput1))
				{
					getline(SelectedDatIfs , tempInput2);
					if ((inputM[0] == tempInput1[5]) && (inputM[1] == tempInput1[6]))
					{
						cout << "����" << lineNum << "��־ʱ��[" << tempInput1 << "]����:" << tempInput2 << endl;
					}
					lineNum++;
				}
				lineNum = 1;
				tempInput1 = '\0';
				tempInput2 = '\0';
				system("pause");
				system("cls");
			}
			else if (key1 == '4')
			{
				cout << "���������� 20xx.xx.xx" << endl;
				//��ʱ�����ݴ����tempInput1Ȼ����tempInput1�����ж�
				cin >> inputYMD;
				while (getline(SelectedIfs , tempInput1))
				{
					getline(SelectedDatIfs , tempInput2);
					if ((inputYMD[0] == tempInput1[0]) && (inputYMD[1] == tempInput1[1]) && (inputYMD[2] == tempInput1[2]) && (inputYMD[3] == tempInput1[3]) && (inputYMD[5] == tempInput1[5]) && (inputYMD[6] == tempInput1[6]) && (inputYMD[8] == tempInput1[8]) && (inputYMD[9] == tempInput1[9]))
					{
						cout << "����" << lineNum << "��־ʱ��[" << tempInput1 << "]����:" << tempInput2 << endl;
					}
					lineNum++;
				}
				lineNum = 1;
				tempInput1 = '\0';
				tempInput2 = '\0';
				system("pause");
				system("cls");
			}
			else
			{
				cout << "ָ�����" << endl;
				system("pause");
				system("cls");
			}
			SelectedDatIfs.close();
			SelectedIfs.close();
		}
		else if (key1 == 'c')
		{
			return 0;
		}
		else
		{
			cout << "ָ�����" << endl;
			system("pause");
			system("cls");
		}
	}

	return 0;
}

//��ȡʱ��
void getTime(string& _string)
{
	time_t nowtime;
	struct tm* p;
	time(&nowtime);
	p = localtime(&nowtime);
	//����·�Ϊ��λ��Ϊ�˸�ʽ��ͬ����ǰ���һ��0
	if (p->tm_mon <= 9)
	{
		_string = to_string(p->tm_year + 1900) + '.' + '0' + to_string(p->tm_mon + 1) + '.';
	}
	else
	{
		_string = to_string(p->tm_year + 1900) + '.' + to_string(p->tm_mon + 1) + '.';
	}
	//�������Ϊ��λ��Ϊ�˸�ʽ��ͬ����ǰ���һ��0
	if (p->tm_mday <= 9)
	{
		_string = _string + '.' + '0' + to_string(p->tm_mday) + '.';
	}
	else
	{
		_string = _string + '.' + to_string(p->tm_mday) + '.';
	}
	//���СʱΪ��λ��Ϊ�˸�ʽ��ͬ����ǰ���һ��0
	if (p->tm_hour <= 9)
	{
		_string = _string + '0' + to_string(p->tm_hour) + ':';
	}
	else
	{
		_string = _string + to_string(p->tm_hour) + ':';
	}
	//�������Ϊ��λ��Ϊ�˸�ʽ��ͬ����ǰ���һ��0
	if (p->tm_min <= 9)
	{
		_string = _string + '0' + to_string(p->tm_min);
	}
	else
	{
		_string = _string + to_string(p->tm_min);
	}
	//cout << p->tm_year << '.' << p->tm_mon << '.' << p->tm_mday << '.' << p->tm_hour << ':' << p->tm_min<<endl;
	//cout << _string << endl;
}

//�˵���ʾ
void menu()
{
	cout << "*1.������־" << endl;
	cout << "*2.�޸���־" << endl;
	cout << "*3.ɾ����־" << endl;
	cout << "*4.�鿴��־" << endl;
	cout << "*5.����·��" << endl;
	cout << "*6.��������" << endl;
	cout << "*c.�˳�" << endl;
}
