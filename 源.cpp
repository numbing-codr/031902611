#include<iostream>
#include<fstream>
#include<sstream>
#include<list>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string>

using namespace std;

class mgc//敏感词类
{
public:
	string ge[1000];//存入匹配成功的关键词
}Mgc;

class jg//结果类
{
public:
	int hg[1000];//敏感词所在的行
	int tou[1000];//敏感词的开头位置
	int chang[1000];//敏感词的长度
}hl;
string a[1000];//存入文本的一行
string b[1000];//存入所有的检测词
string d[1000];//存入敏感词的数组
int main()
{
	
	int n = 0, m = 0;
	system("chcp 65001");
	int j = 0;
	int hang = 0;
	int i = 0;

	string lujing;//打开文本文件
	cin >> lujing;
	ifstream  fin;
	fin.open(lujing, ios::in);
	if (!fin.is_open())
	{
		std::cerr << "cannot open the file";

	}
	while (getline(fin, a[i++]))//按行遍历
	{
		hang = i;//记录行数
	}	//cout << a[i++] << endl;//测试


		//cout << "111111" << endl;//


	string lujing2;//打开检测词文件
	cin >> lujing2;
	ifstream  fin2;
	fin2.open(lujing2, ios::in);
	if (!fin2.is_open())
	{
		std::cerr << "cannot open the file";

	}
	fin2 >> b[j];//按词遍历



	while (b[j][0])
	{

		j++;
		fin2 >> b[j];
	}
	m = j;//记录检测词个数
	//cout << m<< endl;输出关键词的个数
	
		/*
		d:/org.txt
		d:/words.txt
		d:/ans.txt
		*/



	
	

	//cout << hang << endl;输出文章的行数
	int s = 0, t = 0;
	for (i = 0; i < hang; i++)
	{
		s = 0;
		if (a[i][s] < 0)//汉字
		{
			for (j = 0; j < m; j++)
			{
				for (s ; s < sizeof(a[i]); s++)
				{
					if ((a[i][s] == b[j][t]) && (a[i][s + 1] == b[j][t + 1]) && (a[i][s + 2] == b[j][t + 2]))//汉字是三个一组
					{
						if (t == 0)//首字匹配成功，记录头位置
							hl.tou[n] = s;
						t += 3;
						s += 2;
						if (t == sizeof(b[j]))//完全匹配成功，记录行、长度和对应的关键词
						{
							hl.hg[n] = i;
							hl.chang[n] = s-hl.tou[n]+1;
							Mgc.ge[n] = b[j];
							n++;

						}
					}

				}
			}
		}
		else//字符
		{
			for (j = 0; j < m; j++)
			{
				for (s = 0; s < sizeof(a[i]); s++)
				{
					if (a[i][s] == b[j][t] || (a[i][s] - b[j][t] == 32) || (b[j][t] - a[i][s] == 32))//字母相同或互为大小写
						if (t == 0)//首字母匹配成功
							hl.tou[n] = s;
					t++;
					if (t == sizeof(b[j]))//完全匹配成功
					{
						hl.hg[n] = i;
						hl.chang[n] = s-hl.tou[n];
						Mgc.ge[n] = b[j];
						n++;
					}
				}
			}

		}

	}
	
	t = 0;
	string lujing3;
	cin >> lujing3;
	ofstream fout;
	fout.open(lujing3, ios::out);//打开储存答案的文件，进行写操作
	fout << "Total" << ':' <<n+1<< endl;
	for (i = 0; i <hang; i++)//遍历行和字
	{
		for (t = 0; t <= n; t++)
		{
			if (i == hl.hg[t])
			{
				d[t] = a[i].substr(hl.tou[t], hl.chang[t]);//将找到的敏感词复制到另一个字符串数组中
			}
		}
	}
	for (t = 0; t <= n; t++)
	{
		cout << "line" << hl.hg[t] << ':' << '<' << Mgc.ge[t] << '>' << d[t] << endl;//输出
	}
	fout.close();



}