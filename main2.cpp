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

//数据类
class Data
{
public:
	//日期
	string time;
	//事件
	string things;
};

class Save
{
public:
	//设置的数据
	int SelectedLine = 0;
	//设置的路径
	string setPathTime;
	string setPathThings;
};

int main()
{
	//创建文件夹
	string folderPath = "D:\\databyDream";
	if (_access(folderPath.c_str(), 0) == -1)
	{
		string command;
		command = "mkdir -p " + folderPath;
		system(command.c_str());
		cout << "创建成功" << endl;
	}
	Data dataObj;
	dataObj.time = "\0";
	dataObj.things = "\0";

	string tempInput1 = "\0";//临时接收数据字符串
	string tempInput2 = "\0";//临时接收数据字符串

	char inputY[4];
	char inputYM[7];
	char inputM[2];
	char inputYMD[10];

	int lineNum = 1;

	Save save;

	save.setPathTime = "D://databyDream//Time.txt";
	save.setPathThings = "D://databyDream//Things.txt";
	save.SelectedLine = 0;

	char key1 = '0';//指令

	ifstream ifs;
	ifstream SelectedIfs;
	ifstream SelectedDatIfs;
	ofstream ofs;
	ofstream ofs2;

	string& s = dataObj.time;

	//创建string的容器
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
			cout << "请输入日期格式20xx.xx.xx.xx:xx（输入1获取当前时间）" << endl;
			cin >> dataObj.time;
			cout << "请输入事件" << endl;
			cin >> dataObj.things;
			if (dataObj.time == "1")
			{
				getTime(s);
			}
			cout << "已完成" << endl;
			//存储日志数据
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
			cout << "修改时间/事件/都修改(1/2/3)" << endl;
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
				cout << "请输入修改行数" << endl;
				cin >> lineNum;
				cout << "请输入修改内容 格式20xx.xx.xx.xx:xx(输入1获取当前时间)" << endl;
				cin >> tempInput1;
				if (tempInput1 == "1")
				{
					getTime(tempInput1);
				}
				timeV[lineNum - 1] = tempInput1;
			}
			else if (key1 == '2')
			{
				cout << "请输入修改行数" << endl;
				cin >> lineNum;
				cout << "请输入修改内容" << endl;
				cin >> tempInput2;
				thingsV[lineNum - 1] = tempInput2;
			}
			else if (key1 == '3')
			{
				cout << "请输入修改行数" << endl;
				cin >> lineNum;
				cout << "请输入修改时间 格式20xx.xx.xx.xx:xx(输入1获取当前时间)" << endl;
				cin >> tempInput1;
				if (tempInput1 == "1")
				{
					getTime(tempInput1);
				}
				cout << "请输入修改内容" << endl;
				cin >> tempInput2;
				timeV[lineNum - 1] = tempInput1;
				thingsV[lineNum - 1] = tempInput2;
			}
			else
			{
				cout << "指令出错" << endl;
			}
			cout << "请稍等" << endl;
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
			cout << "已完成" << endl;
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
			cout << "请输入要删除的行数" << endl;
			cin >> lineNum;
			cout << "请稍等" << endl;
			timeV.erase(timeV.begin() + (lineNum-1));
			thingsV.erase(thingsV.begin() + (lineNum - 1));
			//遍历容器
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
			cout << "已完成" << endl;
			system("pause");
			system("cls");
		}
		else if (key1 == '4')
		{
			cout << "查看全部/查看单个（1/2）" << endl;
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
					cout << lineNum << ".时间[" << tempInput1 << "]内容:" << tempInput2 << endl;
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
				cout << "请输入行数" << endl;
				cin >> a;
				lineNum = 1;
				ifs.open(save.setPathTime, ios::in);
				SelectedIfs.open(save.setPathThings, ios::in);
				while (getline(ifs , tempInput1))
				{
					getline(SelectedIfs , tempInput2);
					if (lineNum == a)
					{
						cout << lineNum << ".时间[" << tempInput1 << "]内容:" << tempInput2 << endl;
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
				cout << "指令有误" << endl;
			}
			system("pause");
			system("cls");
		}
		else if (key1 == '5')
		{

			cout << "请时间路径（要先把data文件移至指定路径）" << endl;
			cin >> save.setPathTime;
			save.setPathThings = save.setPathTime;
			cout << "已完成" << endl;
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
			cout << "输入时间 单独年份/年月/单独月份/年月日(1/2/3/4)" << endl;
			cin >> key1;
			SelectedDatIfs.open(save.setPathThings, ios::in);
			SelectedIfs.open(save.setPathTime, ios::in);
			if (key1 == '1')
			{
				cout << "输入年份 20xx" << endl;
				//暂时将数据存放在tempInput1然后用tempInput1进行判断
				cin >> inputY;
				while (getline(SelectedIfs , tempInput1))
				{
					getline(SelectedDatIfs , tempInput2);
					if ((inputY[0] == tempInput1[0]) && (inputY[1] == tempInput1[1]) && (inputY[2] == tempInput1[2]) && (inputY[3] == tempInput1[3]))
					{
						cout << "行数" << lineNum << "日志时间[" << tempInput1 << "]内容:" << tempInput2 << endl;
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
				cout << "输入年月 20xx.xx" << endl;
				//暂时将数据存放在tempInput1然后用tempInput1进行判断
				cin >> inputYM;
				while (getline(SelectedIfs , tempInput1))
				{
					getline(SelectedDatIfs , tempInput2);
					if ((inputYM[0] == tempInput1[0]) && (inputYM[1] == tempInput1[1]) && (inputYM[2] == tempInput1[2]) && (inputYM[3] == tempInput1[3]) && (inputYM[5] == tempInput1[5]) && (inputYM[6] == tempInput1[6]))
					{
						cout << "行数" << lineNum << "日志时间[" << tempInput1 << "]内容:" << tempInput2 << endl;
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
				cout << "输入月份 xx" << endl;
				//暂时将数据存放在tempInput1然后用tempInput1进行判断
				cin >> inputM;
				while (getline(SelectedIfs , tempInput1))
				{
					getline(SelectedDatIfs , tempInput2);
					if ((inputM[0] == tempInput1[5]) && (inputM[1] == tempInput1[6]))
					{
						cout << "行数" << lineNum << "日志时间[" << tempInput1 << "]内容:" << tempInput2 << endl;
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
				cout << "输入年月日 20xx.xx.xx" << endl;
				//暂时将数据存放在tempInput1然后用tempInput1进行判断
				cin >> inputYMD;
				while (getline(SelectedIfs , tempInput1))
				{
					getline(SelectedDatIfs , tempInput2);
					if ((inputYMD[0] == tempInput1[0]) && (inputYMD[1] == tempInput1[1]) && (inputYMD[2] == tempInput1[2]) && (inputYMD[3] == tempInput1[3]) && (inputYMD[5] == tempInput1[5]) && (inputYMD[6] == tempInput1[6]) && (inputYMD[8] == tempInput1[8]) && (inputYMD[9] == tempInput1[9]))
					{
						cout << "行数" << lineNum << "日志时间[" << tempInput1 << "]内容:" << tempInput2 << endl;
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
				cout << "指令出错" << endl;
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
			cout << "指令错误" << endl;
			system("pause");
			system("cls");
		}
	}

	return 0;
}

//获取时间
void getTime(string& _string)
{
	time_t nowtime;
	struct tm* p;
	time(&nowtime);
	p = localtime(&nowtime);
	//如果月份为个位，为了格式相同会在前面加一个0
	if (p->tm_mon <= 9)
	{
		_string = to_string(p->tm_year + 1900) + '.' + '0' + to_string(p->tm_mon + 1) + '.';
	}
	else
	{
		_string = to_string(p->tm_year + 1900) + '.' + to_string(p->tm_mon + 1) + '.';
	}
	//如果天数为个位，为了格式相同会在前面加一个0
	if (p->tm_mday <= 9)
	{
		_string = _string + '.' + '0' + to_string(p->tm_mday) + '.';
	}
	else
	{
		_string = _string + '.' + to_string(p->tm_mday) + '.';
	}
	//如果小时为个位，为了格式相同会在前面加一个0
	if (p->tm_hour <= 9)
	{
		_string = _string + '0' + to_string(p->tm_hour) + ':';
	}
	else
	{
		_string = _string + to_string(p->tm_hour) + ':';
	}
	//如果分钟为个位，为了格式相同会在前面加一个0
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

//菜单显示
void menu()
{
	cout << "*1.增加日志" << endl;
	cout << "*2.修改日志" << endl;
	cout << "*3.删除日志" << endl;
	cout << "*4.查看日志" << endl;
	cout << "*5.设置路径" << endl;
	cout << "*6.查找行数" << endl;
	cout << "*c.退出" << endl;
}
