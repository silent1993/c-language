#include <iostream>
#include "QueueChain.h"

using std::cout;
using std::endl;
using std::cin;


int main()
{
	int num_song;
	LinkedQueue<char> Girl, Boy;
	cout << "Please input the number of the song!" << endl;
	cin >> num_song;
	int choice;
	cout << "If you want to input a girl name,input 1\n" << "If you want to input a boy name,input 2\n"
		<< "If you finish input,press 3\n" <<"If you want to exit press 0" <<endl;
	while (cin>>choice)
	{
        switch (choice)
		{
		case 1:
			char name;
			cout << "The name:";
			cin >> name;
			Girl.Add(name);
			break;
		case 2:
			cout << "The name:";
			cin >> name;
			Boy.Add(name);
			break;
		case 3:
			int i;
			for (i = 1; i <= num_song&&!(Girl.IsEmpty())&&!Boy.IsEmpty(); i++)
			{
				char name_g, name_b;
				Girl.Delete(name_g);
				Boy.Delete(name_b);
				cout << "The i partner are " << name_g << " and " << name_b;

			}
			num_song -= i;
			if (Girl.IsEmpty() && num_song&&!Boy.IsEmpty())
				cout << "You can still input the Girl's name!" << endl;
			else if (Boy.IsEmpty() && num_song&&!Girl.IsEmpty())
				cout << "You can still input the Boy's name!" << endl;
			else if (Boy.IsEmpty() && num_song&&Girl.IsEmpty())
				cout << "You can still input the Boy and girl's name!" << endl;
			else
			{
				cout << "There no song!" << endl;
				return 0;
			}

		case 0:
			return 0;
		default:
			break;
		}
	}


}
