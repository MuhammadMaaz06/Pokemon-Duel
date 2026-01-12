//MuhammadMaaz_25i-3066_assignment_03

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	cout<< "--- Pokemon Game ---"<<endl;
	
	//creating all of the required variables 
	srand(time(0));
	string name[2][3] {{"Arceus", "Mimikyu", "Zygarde"},{"Chimecho","Shedinja","Porygon"}};
	int hp [2][3] = {{100, 100, 100},{100, 100, 100}};
	bool defend[2][3] = {{false, false,false} , {false, false, false}};
	
	
	char player= 'A';
	int player0 = 0;
	int pok;
	int action;
	int opok;
	
	//Dislplaying the staring status of the pokemons
	cout<< "Player A "<<endl;
	cout<< "Names    : "<< name[0][0]<<"  "<< name[0][1]<<"  "<<name[0][2]<<endl;
	cout<< "Hp       : "<<hp[0][0]<<"      "<<hp[0][1]<<"     "<<hp[0][2]<<endl;
	cout<< "Status   : Alive"<<endl<<endl; 
	
	cout<< "Player B "<<endl;
	cout<< "Names    : "<< name[1][0]<<"  "<< name[1][1]<<"  "<<name[1][2]<<endl;
	cout<< "Hp       : "<<hp[1][0]<<"      "<<hp[1][1]<<"        "<<hp[1][2]<<endl;
	cout<< "Status   : Alive"<<endl; 
	cout<<"---------------------------"<<endl<<endl;
	
	
	
	//loop starts here for all of the conditions
	while(true)
	{
		cout<<"PLAYER "<<player <<" Turn : "<<endl; 
		cout<<"Choose your Pokemon (1-3) : ";
		cin>> pok;
		pok = pok-1;
		cout<<endl;
		
		if (hp[player0][pok] <= 0)
		{
    cout << "This Pokémon has fainted and cannot be used!" << endl;
    continue;
		}
		
		if(pok<0 || pok>3)
	{
		cout<<"Invalid Input!"<<endl;
		continue;
	}
	
	cout<<"Enter the action you want to choose : "<<endl;
	cout<<" 1 = Attack"<< " "<< "2 = Defend"<<" "<<"3 = Recharge  :  ";
	cin>> action;
	cout<<endl;
	
	//adding a check
	if(action<1 || action>3)
	{
		cout<<"Invalid Input!"<<endl;
		continue;
	}
	
	if(action==1)	//attacking condition
	{
		
		cout<<"Choose your opponent Pokemon (1-3) :  ";
		cin>>opok;
		opok = opok-1;
		cout<<endl;
		if(opok<0 || opok>3)
	{
		cout<<"Invalid Input!"<<endl;
		continue;
	}
	
	int damage = rand()%11 + 10;
	
	
	
	if(defend[1 - player0][opok]) 
	{
                damage /= 2;
                defend[1 - player0][opok] = false;
            }
	
	hp[1-player0][opok] -= damage;
	
	cout<<name[player0][pok]<<"  attacked "<<name[1-player0][opok]<<" for "<<damage<<" damage!"<<endl;
	if(hp[1-player0][opok]<0)
	{
		cout<<" pokemon fainted : "<<endl;
	}
	}
	if(action==2)	 //contion for the defence 
	{
	defend[player0][pok] = true;
	cout<<name[player0][pok]<<"  is defending! "<<endl;
	}

	if(action==3)	//condition for the recharge of the pokemon
	{
		if(hp[player0][pok]<=0)
		{
			cout<<"The pokemon already fainted so it can not be healed!" << endl;
			continue;
		}
	int heal = rand()%11 + 10;
	hp[player0][pok] += heal;
	if(hp[player0][pok]>100)
	{
		hp[player0][pok] = 100;
	}
	cout<< hp[player0][pok] << " healed " << heal <<endl;
		
	}
	
	//printing the status of both of the players after each iteration
	cout<<endl;
	cout<<"--- Current Status ---"<<endl;
	for(int i=0; i<2; i++)
	{
		cout<<"PLAYER : "<<(i==0? "A" : "B") <<endl;
	 for(int j=0; j<3; j++)
		{
			if(hp[i][j] > 0)
			{
			cout << "  " << name[i][j] << " - HP: " << hp[i][j];
			}
        if (hp[i][j] <= 0) 
		{
		cout << "The Pokemon Fainted! ";
	}
                cout << endl;
		}
	}
	cout<<"------------------"<<endl;
	
	//checking for the winning conditions 
	if(((hp[0][0]<=0) && (hp[0][1]<=0) && (hp[0][2])<=0) || ((hp[1][0]<=0) && (hp[1][1]<=0) && (hp[1][2])<=0))
	{
		char playerw;
		if(((hp[0][0]<=0) && (hp[0][1]<=0) && (hp[0][2])<=0))
		{
			playerw = 'B';
		}
		else
		{
			playerw = 'A';
		}
		cout<<"PLAYER : "<<playerw << "   Wins the Pokemon duel! " <<endl;
		return 0;
	}
	//switching the two players
	if(player=='A')
	{
		player='B';
		player0 = 1;
	}
	else 
	{
		player = 'A';
		player0 = 0;
	}
	
}
return 0;
	
	}

	
	

