#include <iostream>
#include <vector>
using namespace std;
class txt
{
public:
	txt(vector<char> cha){ch = cha;}
	void cword(); //ͳ�Ƶ���������	
	void cline(); //ͳ�ƾ�������
	void cch(); //ͳ���ַ�������
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
	cout << "�ܾ�����" << count <<endl;
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
	cout << "��������" << count <<endl;
}
void txt::cch()
{
	int count = 0;
	for (int i=0;i < ch.size();i++)
	{
		if ('\012' != ch[i])
			count++;
	}
	cout << "�ַ�����" << count <<endl;
}
int main()
{
	vector<char> words;
	cout << "�����룺" <<endl;
	char word;//�����ı�
	cin.unsetf( ios::skipws );
	while (cin >> word )
	{
		//�ж��Ƿ�Ϊ���֣�����������������ô����
		if (word >= '0' && word <= '9')
		{
			cout << "������ַ��к�����" << endl;
			return -1;
		}
		words.push_back(word);
		int i = words.size();
		if (words[i-2] == '\012' && words[i-1] == '\012')
		{
			break;
		}
	}//ɾ�����һ������,����д������
	words.pop_back();//���������
	txt t(words);
	t.cline();
	t.cword();
	t.cch();
	return 0;
} 
