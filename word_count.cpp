#include <iostream>
#include <vector>
using namespace std;
class txt
{
public:
	txt(vector<char> cha){ch = cha;}
	void cword(); //统计单词数函数	
	void cline(); //统计句数函数
	void cch(); //统计字符数函数
private:
	vector<char> ch;
};
void txt::cline()
{
	int count = 0;
	for (int i=0;i < ch.size();i++)
	{
		if ('\012' == ch[i])
			count++;
	}
	cout << "总句数：" << count <<endl;
}
void txt::cword()
{
	int count = 0;
	bool v=true;
	for (int i=0;i < ch.size();i++)
	{
		if (!(ch[i]>='a'&&ch[i]<='z')||(ch[i]>='A'&&ch[i]<='Z'))
		{
			if (v)
				count++;
			v=false;
		}
		else
			v=true;
	}
	cout << "单词数：" << count <<endl;
}
void txt::cch()
{
	int count = 0;
	for (int i=0;i < ch.size();i++)
	{
		if ('\012' != ch[i])
			count++;
	}
	cout << "字符数：" << count <<endl;
}
int main()
{
	vector<char> words;
	cout << "请输入：" <<endl;
	char word;//输入文本
	cin.unsetf( ios::skipws );
	while (cin >> word )
	{
		//判断是否为数字，如果输入的是数字那么返回
		if (word >= '0' && word <= '9')
		{
			cout << "输入的字符中含数字" << endl;
			return -1;
		}
		words.push_back(word);
		int i = words.size();
		if (words[i-2] == '\012' && words[i-1] == '\012')
		{
			break;
		}
	}//删除最后一个空行,因空行代表结束
	words.pop_back();//定义类对象
	txt t(words);
	t.cline();
	t.cword();
	t.cch();
	return 0;
} 
