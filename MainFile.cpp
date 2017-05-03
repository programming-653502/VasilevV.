#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
# include <iostream.h>
# include <conio.h>

using namespace std;

//----------------------------------- Вспомогательные функции
bool CheckL(char A[3])
{
	if (A[1] != '\0')
	{
		printf("Error.\n\n(Press any key to return)");
		getch();
		clrscr();
		return true;
	}
	if (A[0] != '1' && A[0] != '2')
	{
		printf("Error.\n\n(Press any key to return)");
		getch();
		clrscr();
		return true;
	}
	return false;
}
bool CheckNumber(char Num[16])
{
	if (Num[0] == '\0')
	{
		printf("\nError\n(Press any key to return)");
		getch();
		return true;
	}
	for (int i = 0; i < 16; i++)
	{
		if (Num[i] == '\0')
		{
			break;
		}
		if (Num[i] != '0' && Num[i] != '1' && Num[i] != '2' && Num[i] != '3' && Num[i] != '4' && Num[i] != '5' && Num[i] != '6' && Num[i] != '7' && Num[i] != '8' && Num[i] != '9')
		{
			printf("\nError\n(Press any key to return)");
			getch();
			return true;
		}
	}
	return false;
}
int Char16ToInt(char Num[16])
{
	int Res = 0, a = strlen(Num);
	for (int i = 0; i < strlen(Num); i++)
	{
		Res += (Num[strlen(Num) - i - 1] - 48)*pow(10.,i);
	}
	return Res;
}
//----------------------------------- Класс Дерева
struct TreeElement
{
	int value;
	TreeElement *left;
	TreeElement *right;
};
class Tree
{
	TreeElement *Root;
	public:
		Tree(){Root = NULL;};
		void AddElement(int input)
		{
			if (Root == NULL)
			{
				TreeElement *temp = new TreeElement;
				temp->value = input;
				temp->left = NULL;
				temp->right = NULL;
				Root = temp;
			}
			else
			{
				TreeElement *temp = new TreeElement;
				temp = Root;
				while (1)
				{
					if (temp->value > input)
					{
						if (temp->left == NULL)
						{
							TreeElement *tempNew = new TreeElement;
							tempNew->value = input;
							tempNew->left = NULL;
							tempNew->right = NULL;
							temp->left = tempNew;
							break;
						}
						else
						{
							temp = temp->left;
						}
					}
					else
					{
						if (temp->value == input)
						{
							break;
						}
						else
						{
							if (temp->right == NULL)
							{
								TreeElement *tempNew = new TreeElement;
								tempNew->value = input;
								tempNew->left = NULL;
								tempNew->right = NULL;
								temp->right = tempNew;
								break;
							}
							else
							{
								temp = temp->right;
							}
						}
					}
				}
			}
		};
		void ShowMax()
		{
			TreeElement *temp = new TreeElement;
			temp = Root;
			if (temp == NULL)
			{
				printf("Empty");
			}
			else
			{
				while (temp->right != NULL)
				{
					temp = temp->right;
				}
				printf("%d",temp->value);

			}
		};
};
//----------------------------------- Класс Списка Деревьев
struct TreeInfo
{
	Tree tree;
	TreeInfo *next;
};
class TreesList
{
	TreeInfo *Head;
	public:
		TreesList(){Head = NULL;};
		void AddTree()
		{
			TreeInfo *temp = new TreeInfo;
			temp->next = Head;
			Head = temp;
		};
		int CountTrees()
		{
			int counter = 0;
			TreeInfo *temp = new TreeInfo;
			if (Head != NULL)
			{
				counter++;
				temp = Head->next;
				while (1)
				{
					counter++;
					if (temp->next == NULL)
					{
						break;
					}
					temp = temp->next;
				}
			}
			return counter;
		};
		void ModifyTree(int number, int value)
		{
			if (number == 1)
			{
				Head->tree.AddElement(value);
			}
			else
			{
				TreeInfo *temp = new TreeInfo;
				temp = Head->next;
				for (int i = 3; i <= number; i++)
				{
					temp = temp->next;
				}
				temp->tree.AddElement(value);
			}
		};
		void ShowTree(int number)
		{
			if (number == 1)
			{
				Head->tree.ShowMax();
			}
			else
			{
				TreeInfo *temp = new TreeInfo;
				temp = Head->next;
				for (int i = 3; i <= number; i++)
				{
					temp = temp->next;
				}
				temp->tree.ShowMax();
			}
		};
};
//----------------------------------- Класс Списка Добавления
struct Add
{
	int number;
	int value;
	Add *next;
	Add *prev;
};
class AddList
{
	Add *Head;
	Add *Tail;
	public:
		AddList(){Head = NULL; Tail = NULL;};
		void AddHeadElement(int TreeNumber, int InputValue)
		{
			Add *temp = new Add;
			temp->next = Head;
			temp->prev = Tail;
			temp->value = InputValue;
			temp->number = TreeNumber;
			Head = temp;
		}
		int CountElemnts()
		{
        	int counter = 0;
			Add *temp = new Add;
			if (Head != NULL)
			{
				counter++;
				temp = Head->next;
				while (1)
				{
					if (temp == NULL)
					{
						break;
					}
					counter++;
					temp = temp->next;
				}
			}
			return counter;
		};
		Add* LoadAdd(int number)
		{
			if (number == 1)
			{
				return Head;
			}
			else
			{
				Add *temp = new Add;
				temp = Head->next;
				for (int i = 1; i < number - 1; i++)
				{
                	temp = temp->next;
				}
				return temp;
			}
		}
};
//----------------------------------- Main
int _tmain(int argc, _TCHAR* argv[])
{
	char Num[16], L[3];		 // L - рычаг
	bool B;
	while (1)
	{
		B = true;
		while (B)
		{
			clrscr();
			printf("Choose:\n1.Perform.\n2.Exit.\n\n");
			gets(L);
			B = CheckL(L);
		}
		if (L[0] == '1')
		{
			TreesList MainTreesList;
			AddList MainAddList;
			while (1)
			{
				B = true;
				while (B)
				{
					clrscr();
					printf("Choose:\n1.Add tree.\n2.Continue.\n\n");
					gets(L);
					B = CheckL(L);
				}
				if (L[0] == '1')
				{
					MainTreesList.AddTree();
				}
				else
				{
					break;
				}
			}
            while (1)
			{
				int treesnumber, value;
				B = true;
				while (B)
				{
					clrscr();
					printf("Choose:\n1.Add operation.\n2.Continue.\n\n");
					gets(L);
					B = CheckL(L);
				}
				if (L[0] == '1')
				{
					int treenumber, value;
					B = true;
					while (B)
					{
						clrscr();
						printf("Enter the number of tree:");
						gets(Num);
						B = CheckNumber(Num);
					}
					treenumber = Char16ToInt(Num);
					B = true;
					while (B)
					{
						clrscr();
						printf("Enter the value:");
						gets(Num);
						B = CheckNumber(Num);
					}
					value = Char16ToInt(Num);
                    MainAddList.AddHeadElement(treenumber,value);
				}
				else
				{
					break;
				}
			}
            int treesnumber = MainTreesList.CountTrees(), value, number;
			clrscr();
			if (MainAddList.CountElemnts() > 0)
			{
				Add *tempAdd = new Add;
				for (int i = 1; i <= MainAddList.CountElemnts(); i++)
				{
					tempAdd = MainAddList.LoadAdd(i);
					value = tempAdd->value;
					number = tempAdd->number;
					if (treesnumber >= number)
					{
						MainTreesList.ModifyTree(number, value);
					}
				}
				for (int i = 1; i <= treesnumber; i++)
				{
					printf("%d:",i);
					MainTreesList.ShowTree(i);
					printf(".\n");
				}
				getch();
			}
			else
			{
				printf("Empty trees.\n\n(Press any key to go to menu.)");
				getch();
            }
		}
		else
		{
			break;
		}
	}
}
