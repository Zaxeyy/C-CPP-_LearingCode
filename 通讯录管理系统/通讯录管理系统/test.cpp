#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
using namespace std;

#define MAX 50

void menu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
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
			cout << "��";
			break;
		case 1:
			cout << "Ů";
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
			cout << "����";
			break;
		case 1:
			cout << "��ͭ";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "�ƽ�";
			break;
		case 4:
			cout << "��ʯ";
			break;
		case 5:
			cout << "----";
		}
	}

	void setId()
	{
		cout << "��ϵ��֤���ţ�";
		cin >> id_num;
	}
	void setName()
	{
		cout << "��ϵ��������";
		cin >> name;
	}
	void setSex()
	{
		short int enm;
		cout << "��ϵ���Ա�1���� 2��Ů 3��δ֪����";
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
				cout << "�Ƿ����룡" << endl;
				break;
			}
		}
	}
	void setAge()
	{
		cout << "��ϵ�����䣺";
		cin >> age;
	}
	void setLevel()
	{
		short int enm;
		cout << "��ϵ�˵ȼ���1������ 2����ͭ 3������ 4���ƽ� 5����ʯ 0����������";
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
				cout << "�Ƿ����룡" << endl;
				break;
			}
		}
	}
	void setTel()
	{
		cout << "��ϵ�˵绰��";
		cin >> tel;
	}
	void setAddress()
	{
		cout << "��ϵ�˵�ַ��";
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
			cout << "ͨѶ¼�������޷���ӣ�" << endl;
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
					cout << "�ظ�֤���ţ����������룡";
					continue;
				}
				break;
			}
			while (1)
			{
				Jack.setName();
				if (NameRepeat(Jack))
				{
					cout << "�ظ����������������룡";
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
			cout << "�Ѵ�����ϵ�ˣ�" << endl;
			Jack.showPerson();
		}
	}
	void showList()
	{
		if (m_Size == 0)cout << "����ϵ�ˣ�" << endl;
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
			cout << "�����������׼��1��֤���� 2������ 3���Ա� 4������ 5���ȼ� 6���绰 7����ַ 0���˳�����";
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
				if (str_sex == "��")sex = MALE;
				else if (str_sex == "Ů")sex = FEMALE;
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
				if (str_level == "����")level = IRON;
				else if (str_level == "��ͭ")level = BRONZE;
				else if (str_level == "����")level = SILVER;
				else if (str_level == "�ƽ�")level = GOLD;
				else if (str_level == "��ʯ")level = DIAMOND;
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
				cout << "�˳�������" << endl;
				break;
			default:
				cout << "�Ƿ����룡" << endl;
				break;
			}
		} while (choice);
	}
	void deletePerson()
	{
		if (m_Size == 0)
		{
			cout << "����ϵ�ˣ�" << endl;
		}
		else
		{
			int choice;
			string id = " ", name = " ", tel = " ";
			do
			{
				short int person = -1;
				cout << "������׼��1��֤���� 2������ 3���绰 0���˳�����";
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
					cout << "�˳��޸ģ�" << endl;
					break;
				default:
					cout << "�Ƿ����룡" << endl;
					break;
				}
				if (person == -1) { cout << "�����ڴ���ϵ�ˣ�" << endl;continue; }
				personArr[person].showPerson();
				while (1)
				{
					cout << "ȷ��ɾ������ϵ���𣿣�Y/N��" << endl;
					char YorN;
					cin >> YorN;
					if ('Y' == toupper(YorN))
					{
						Person Jack("-", "-", UNKONWN, 0, ZERO, "-", "-");
						personArr[person] = Jack;
						m_Size--;
						cout << "ɾ���ɹ���" << endl;
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
		cout << "������׼��1��֤���� 2������ 3���绰 0���˳�����";
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
				cout << "�˳��޸ģ�" << endl;
				return;
			default:
				cout << "�Ƿ����룡" << endl;
				break;
			}
			if (person == -1) { cout << "�����ڴ���ϵ�ˣ�" << endl;continue; }
			int label = 0;
			do
			{
				personArr[person].showPerson();
				cout << "��ѡ��Ҫ�޸ĵ���Ϣ(1��֤���� 2������ 3���Ա� 4������ 5���ȼ� 6���绰 7����ַ 0���˳�)��";
				cin >> label;
				switch (label)
				{
				case 1:
					personArr[person].setId();
					cout << "�޸ĳɹ���" << endl;
					break;
				case 2:
					personArr[person].setName();
					cout << "�޸ĳɹ���" << endl;
					break;
				case 3:
					personArr[person].setSex();
					cout << "�޸ĳɹ���" << endl;
					break;
				case 4:
					personArr[person].setAge();
					cout << "�޸ĳɹ���" << endl;
					break;
				case 5:
					personArr[person].setLevel();
					cout << "�޸ĳɹ���" << endl;
					break;
				case 6:
					personArr[person].setTel();
					cout << "�޸ĳɹ���" << endl;
					break;
				case 7:
					personArr[person].setAddress();
					cout << "�޸ĳɹ���" << endl;
					break;
				case 0:
					cout << "�˳��޸ģ�" << endl;
					break;
				default:
					cout << "�Ƿ����룡" << endl;
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
			cout << "ȷ�����ͨѶ¼�𣿣�Y/N��";
			cin >> YN;
			if (toupper(YN) == 'Y')
			{
				Person Jack("-", "-", UNKONWN, 0, ZERO, "-", "-");
				for (int i = 0;i < m_Size;i++)
				{
					personArr[i] = Jack;
				}
				m_Size = 0;
				cout << "ͨѶ¼����գ�" << endl;
				return;
			}
			else if (toupper(YN) == 'N')
			{
				cout << "�˳���գ�" << endl;
				return;
			}
			else
			{
				cout << "�Ƿ����룡" << endl;
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
		case 1://���
			list.addPerson();
			break;
		case 2://��ʾ
			list.showList();
			break;
		case 3://ɾ��
			list.deletePerson();
			break;
		case 4://����
			list.searchPerson();
			break;
		case 5://�޸�
			list.changePerson();
			break;
		case 6://���
			list.emptyList();
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			break;
		default:
			cout << "�Ƿ����룡" << endl;
			break;
		}
	} while (choice);
	return 0;
}