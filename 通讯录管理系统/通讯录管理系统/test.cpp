#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
using namespace std;

#define MAX 50

void menu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

enum LEVEL { IRON, BRONZE, SILVER, GOLD, DIAMOND,ZERO };
enum GENDER { MALE, FEMALE,UNKONWN };

class Person
{
private:
	string name, tel, id_num, address;
	unsigned short int age;
	LEVEL level;
	GENDER sex;
public:
	Person(){}
	Person(string id,string name,GENDER sex,unsigned short int age,LEVEL level,string tel,string address)
		:id_num(id),name(name),sex(sex),age(age),level(level),tel(tel),address(address){ }
	string getName() { return name; }
	string getTel() { return tel; }
	string getId() { return id_num; }
	string getAddress() { return address; }
	unsigned short int getAge() { return age; }
	LEVEL getLevel() { return level; }
	GENDER getSex() { return sex; }

	void showId()
	{
		cout << id_num ;
	}
	void showName()
	{
		cout << name ;
	}
	void showTel()
	{
		cout << tel ;
	}
	void showAddress()
	{
		cout << address ;
	}
	void showSex()
	{
		switch (getSex())
		{
		case 0:
			cout << "男";
			break;
		case 1:
			cout << "女";
			break;
		case 2:
			cout << "--";
		}
	}
	void showLevel()
	{
		switch (getLevel())
		{
		case 0:
			cout << "黑铁";
			break;
		case 1:
			cout << "青铜";
			break;
		case 2:
			cout << "白银";
			break;
		case 3:
			cout << "黄金";
			break;
		case 4:
			cout << "钻石";
			break;
		case 5:
			cout << "----";
		}
	}

	void setId()
	{
		cout << "联系人证件号：";
		cin >> id_num;
	}
	void setName()
	{
		cout << "联系人姓名：";
		cin >> name;
	}
	void setSex()
	{
		short int enm;
		cout << "联系人性别（1、男 2、女 3、未知）：";
		cin >> enm;
		while (1)
		{
			switch (enm)
			{
			case 1:
				sex = MALE;
				return;
			case 2:
				sex = FEMALE;
				return;
			case 3:
				sex = UNKONWN;
				return;
			default:
				cout << "非法输入！" << endl;
				break;
			}
		}
	}
	void setAge()
	{
		cout << "联系人年龄：";
		cin >> age;
	}
	void setLevel()
	{
		short int enm;
		cout << "联系人等级（1、黑铁 2、青铜 3、白银 4、黄金 5、钻石 0、其他）：";
		cin >> enm;
		while (1)
		{
			switch (enm)
			{
			case 1:
				level = IRON;
				return;
			case 2:
				level = BRONZE;
				return;
			case 3:
				level = SILVER;
				return;
			case 4:
				level = GOLD;
				return;
			case 5:
				level = DIAMOND;
				return;
			case 0:
				level = ZERO;
			default:
				cout << "非法输入！" << endl;
				break;
			}
		}
	}
	void setTel()
	{
		cout << "联系人电话：";
		cin >> tel;
	}
	void setAddress()
	{
		cout << "联系人地址：";
		cin >> address;
	}

	void showPerson()
	{
		cout << left;
		cout << '#' << setw(20) << getId() << setw(10) << getName() << setw(4);
		showSex();
		cout << setw(4) << getAge() << setw(6);
		showLevel();
		cout << setw(13) << getTel() << setw(24) << getAddress() << endl;
	}

};

class Addressbooks
{
private:
	Person personArr[MAX];
	int m_Size=0;
public:
	void AddPerson(Person Jack)
	{
		personArr[m_Size] = Jack;
		m_Size++;
	}
	bool NameRepeat(Person Jack)
	{
		for (int i = 0;i < m_Size;i++)
		{
			if (Jack.getName() == personArr[i].getName())
				return true;
		}
		return false;
	}
	bool IdRepeat(Person Jack)
	{
		for (int i = 0;i < m_Size;i++)
		{
			if (Jack.getId() == personArr[i].getId())
				return true;
		}
		return false;
	}
	bool TelRepeat(Person Jack)
	{
		for (int i = 0;i < m_Size;i++)
		{
			if (Jack.getTel() == personArr[i].getTel())
				return true;
		}
		return false;
	}

	void addPerson()
	{
		if (m_Size == MAX)
		{
			cout << "通讯录已满，无法添加！" << endl;
			return;
		}
		else
		{
			Person Jack("-", "-", UNKONWN, 0, ZERO, "-", "-");
			while (1)
			{
				Jack.setId();
				if (IdRepeat(Jack))
				{
					cout << "重复证件号，请重新输入！";
					continue;
				}
				break;
			}
			while (1)
			{
				Jack.setName();
				if (NameRepeat(Jack))
				{
					cout << "重复姓名，请重新输入！";
					continue;
				}
				break;
			}
			Jack.setSex();
			Jack.setAge();
			Jack.setLevel();
			Jack.setTel();
			Jack.setAddress();
			personArr[m_Size++] = Jack;
			cout << "已创建联系人！" << endl;
			Jack.showPerson();
		}
	}
	void showList()
	{
		if (m_Size == 0)cout << "无联系人！" << endl;
		else
		{
			for (int i = 0;i < m_Size;i++)
			{
				personArr[i].showPerson();
			}
		}
	}
	void searchPerson()
	{
		short int choice;
		string id = " ", name = " ", tel = " ", address = " ", str_sex = " ", str_level = " ";
		GENDER sex;
		LEVEL level;
		unsigned short int age = 0;
		do 
		{
			cout << "请输入检索标准（1、证件号 2、姓名 3、性别 4、年龄 5、等级 6、电话 7、地址 0、退出）：";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cin >> id;
				int i;
				for (i = 0;i < m_Size;i++)
				{
					if (personArr[i].getId() == id)
					{
						personArr[i].showPerson();
						break;
					}
				}
				break;
			case 2:
				cin >> name;
				int i;
				for (i = 0;i < m_Size;i++)
				{
					if (personArr[i].getName() == name)
					{
						personArr[i].showPerson();
						break;
					}
				}
				break;
			case 3:
				cin >> str_sex;
				if (str_sex == "男")sex = MALE;
				else if (str_sex == "女")sex = FEMALE;
				else sex = UNKONWN;
				for (int i = 0;i < m_Size;i++)
				{
					if (personArr[i].getSex() == sex)personArr[i].showPerson();
					cout << endl;
				}
				break;
			case 4:
				cin >> age;
				for (int i = 0;i < m_Size;i++)
				{
					if (personArr[i].getAge() == age)personArr[i].showPerson();
					cout << endl;
				}
				break;
			case 5:
				cin >> str_level;
				if (str_level == "黑铁")level = IRON;
				else if (str_level == "青铜")level = BRONZE;
				else if (str_level == "白银")level = SILVER;
				else if (str_level == "黄金")level = GOLD;
				else if (str_level == "钻石")level = DIAMOND;
				else level = ZERO;
				for (int i = 0;i < m_Size;i++)
				{
					if (personArr[i].getLevel() == level)personArr[i].showPerson();
					cout << endl;
				}
				break;
			case 6:
				cin >> tel;
				for (int i = 0;i < m_Size;i++)
				{
					if (personArr[i].getTel() == tel)
					{
						personArr[i].showPerson();
						break;
					}
				}
				break;
			case 7:
				cin >> address;
				for (int i = 0;i < m_Size;i++)
				{
					if (personArr[i].getAddress() == address)personArr[i].showPerson();
					cout << endl;
				}
				break;
			case 0:
				cout << "退出搜索！" << endl;
				break;
			default:
				cout << "非法输入！" << endl;
				break;
			}
		} while (choice);
	}
	void deletePerson()
	{
		if (m_Size == 0)
		{
			cout << "无联系人！" << endl;
		}
		else
		{
			int choice;
			string id = " ", name = " ", tel = " ";
			do
			{
				short int person = -1;
				cout << "检索标准（1、证件号 2、姓名 3、电话 0、退出）：";
				cin >> choice;
				switch (choice)
				{
				case 1:
					cin >> id;
					for (int i = 0;i < m_Size;i++)
					{
						if (personArr[i].getId() == id)
						{
							person = i;
							break;
						}
					}
					break;
				case 2:
					cin >> name;
					for (int i = 0;i < m_Size;i++)
					{
						if (personArr[i].getName() == name)
						{
							person = i;
							break;
						}
					}
					break;
				case 3:
					cin >> tel;
					for (int i = 0;i < m_Size;i++)
					{
						if (personArr[i].getTel() == tel)
						{
							person = i;
							break;
						}
					}
					break;
				case 0:
					cout << "退出修改！" << endl;
					break;
				default:
					cout << "非法输入！" << endl;
					break;
				}
				if (person == -1) { cout << "不存在此联系人！" << endl;continue; }
				personArr[person].showPerson();
				while (1)
				{
					cout << "确认删除此联系人吗？（Y/N）" << endl;
					char YorN;
					cin >> YorN;
					if ('Y' == toupper(YorN))
					{
						Person Jack("-", "-", UNKONWN, 0, ZERO, "-", "-");
						personArr[person] = Jack;
						m_Size--;
						cout << "删除成功！" << endl;
						break;
					}
					else if ('N' == toupper(YorN))
					{
						break;
					}
					else continue;
				}
			} while (choice);
			
		}
	}
	void changePerson()
	{
		int choice;
		string id = " ", name = " ", tel = " ";
		cout << "检索标准（1、证件号 2、姓名 3、电话 0、退出）：";
		do {
			short int person = -1;
			cin >> choice;
			switch (choice)
			{
			case 1:
				cin >> id;
				for (int i = 0;i < m_Size;i++)
				{
					if (personArr[i].getId() == id)
					{
						person = i;
						break;
					}
				}
				break;
			case 2:
				cin >> name;
				for (int i = 0;i < m_Size;i++)
				{
					if (personArr[i].getName() == name)
					{
						person = i;
						break;
					}
				}
				break;
			case 3:
				cin >> tel;
				for (int i = 0;i < m_Size;i++)
				{
					if (personArr[i].getTel() == tel)
					{
						person = i;
						break;
					}
				}
				break;
			case 0:
				cout << "退出修改！" << endl;
				return;
			default:
				cout << "非法输入！" << endl;
				break;
			}
			if (person == -1) { cout << "不存在此联系人！" << endl;continue; }
			int label = 0;
			do
			{
				personArr[person].showPerson();
				cout << "请选择要修改的信息(1、证件号 2、姓名 3、性别 4、年龄 5、等级 6、电话 7、地址 0、退出)：";
				cin >> label;
				switch (label)
				{
				case 1:
					personArr[person].setId();
					cout << "修改成功！" << endl;
					break;
				case 2:
					personArr[person].setName();
					cout << "修改成功！" << endl;
					break;
				case 3:
					personArr[person].setSex();
					cout << "修改成功！" << endl;
					break;
				case 4:
					personArr[person].setAge();
					cout << "修改成功！" << endl;
					break;
				case 5:
					personArr[person].setLevel();
					cout << "修改成功！" << endl;
					break;
				case 6:
					personArr[person].setTel();
					cout << "修改成功！" << endl;
					break;
				case 7:
					personArr[person].setAddress();
					cout << "修改成功！" << endl;
					break;
				case 0:
					cout << "退出修改！" << endl;
					break;
				default:
					cout << "非法输入！" << endl;
					break;
				}
			} while (label);
		} while (choice);
	}
	void emptyList()
	{
		char YN;
		while (1)
		{
			cout << "确认清空通讯录吗？（Y/N）";
			cin >> YN;
			if (toupper(YN) == 'Y')
			{
				Person Jack("-", "-", UNKONWN, 0, ZERO, "-", "-");
				for (int i = 0;i < m_Size;i++)
				{
					personArr[i] = Jack;
				}
				m_Size = 0;
				cout << "通讯录已清空！" << endl;
				return;
			}
			else if (toupper(YN) == 'N')
			{
				cout << "退出清空！" << endl;
				return;
			}
			else
			{
				cout << "非法输入！" << endl;
				continue;
			}
		}
	}
};

int main()
{

	int choice = 0;
	Addressbooks list;
	void menu();
	do
	{
		
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1://添加
			list.addPerson();
			break;
		case 2://显示
			list.showList();
			break;
		case 3://删除
			list.deletePerson();
			break;
		case 4://查找
			list.searchPerson();
			break;
		case 5://修改
			list.changePerson();
			break;
		case 6://清空
			list.emptyList();
			break;
		case 0:
			cout << "欢迎下次使用！" << endl;
			break;
		default:
			cout << "非法输入！" << endl;
			break;
		}
	} while (choice);
	return 0;
}