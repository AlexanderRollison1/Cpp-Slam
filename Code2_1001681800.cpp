#include <iostream>
#include <vector>
#include <ctime>

#define dice 5
#define faces 6
#define rolls 3
#define testroll 23

using namespace std;

void RollDice(vector<int>&Dice);
void PrintRoll(vector<int>Dice);
void FillHowMany(vector<int>Dice, vector<int>&HowMany);
void PickDice(vector<int>&Dice);
std::string TestRollDice(vector<int>&Dice);
std::string PrintManyCheck(vector<int>HowMany);
void PrintMany(vector<int>HowMany);


int main(int argc, char *argv[])
{
    srand(time(0));
	vector<int> Dice(dice);
	vector<int>HowMany(faces);
    std::string TestString1;
    std::string TestString2;
	char userInput;
	int rollCount = 0;
    int flag = 0;
    int name;
    std::string comp;
    int check = 0;
    int pass = 0;
    int rerolls;
    std::vector<int> FourKind3{3,6,3,3,3}; 

	do
	{
        if(flag == 0)
        {
            for(int x: Dice)
            {
                Dice.erase(Dice.begin());
            }
            if(argc == 2)
            {
                comp = argv[1];
                name = comp.compare("TEST");
            }

            if(argc == 2 && comp.compare("TEST") == 0)
            {
				rerolls = testroll;

				TestString1 = TestRollDice(Dice);
				FillHowMany(Dice, HowMany);
				TestString2 = PrintManyCheck(HowMany);
//                  cout<<TestString1<<" and "<<TestString2<<endl;

				if(TestString2.compare(TestString1) == 0)
				{
				   pass++;
				}

				flag = 1;
				check++;
            }
            else
            {
                rerolls = rolls;
                RollDice(Dice);
		        cout<<"\nYou rolled";
		        PrintRoll(Dice);
            
		        FillHowMany(Dice, HowMany);
                PrintMany(HowMany);
            }
		}


        if(name == 0 && argc == 2)
        {
            TestString1 = TestRollDice(Dice);
            FillHowMany(Dice, HowMany);
            TestString2 = PrintManyCheck(HowMany);
            if(rollCount < rerolls-1)
            {
                cout<<"\nYou Rolled";
                PrintRoll(Dice);
                cout<<TestString1<<endl;
                
//              cout<<"Test output: "<<TestString1<<"\t\t\tAlexander's Program Output: "<<TestString2<<endl;
                if(TestString2.compare(TestString1) == 0 && rollCount < rerolls-1)
                {
                   cout<<"Test Passed"<<endl;
                   pass++;
                }
                else
                {
                    cout<<"Test Failed"<<endl;
                }
            }
            if(rollCount == rerolls-1)
            {
                cout<<"Out of "<<check<<" tests, "<< pass <<" tests passsed and "<<testroll-pass<< " tests failed."<<endl;
            }
            rollCount++;
            check++;
        }
        else
        {
	        cout<<"\nDo you want to reroll? ";
	        cin>>userInput;
	        getchar();
            flag = 1;
    //	    while(userInput != 'y' && userInput != 'Y')
    //	    {
    //            if(userInput == 'n' || userInput == 'N')
    //	        {
    //                cout<<"\nExiting..."<<endl;
    //		        exit(0);
    //	        }
    //		    cout<<"\nInput must be character y or n. Please reenter ";
    //		    cin >>userInput;
    //            getchar();
    //	    }
	        
	        if(userInput == 'n' || userInput != 'y')
	        {
		        rollCount = rerolls;
	        }
	        else if(userInput == 'y')
	        {
		        rollCount++;
		        PickDice(Dice);
	        }
        }
	}
	while(rollCount < rerolls);
	return 0;
}

void PrintMany(vector<int>HowMany)
{
    ///////////////////////
	int FullHouse = 0;
	int TwoPair = 0;
	int CPPSlam = 0;
	int LargeStraight = 0;
	int SmallStraight = 0;
	int ofAKind = 0;
    ///////////////////////
    int loopnum = 0;
    for(int w: HowMany)
    {
	    if(HowMany[loopnum] == 3)
        {
            FullHouse = FullHouse+3;
        }
        if(HowMany[loopnum] == 2)
        {
            FullHouse = FullHouse+2;
            TwoPair++;
        }
        if(HowMany[loopnum] == 5)
        {
            CPPSlam++;
        }
        
        if(HowMany[loopnum] == 1)
        {
            LargeStraight++;
        }
        else if((HowMany[loopnum] == 0) && (LargeStraight > 0) && (LargeStraight < 5))
        {
            LargeStraight = 0;
        }
        
        if(HowMany[loopnum] >= 1)
        {
            SmallStraight++;
        }
        else if((HowMany[loopnum] == 0) && (SmallStraight >= 0) && (SmallStraight < 4))
        {
            SmallStraight = 0;
        }
        
        if(HowMany[loopnum] == 4)
        {
            ofAKind = 4;
        }
        
        if(HowMany[loopnum] == 3)
        {
            ofAKind = 3;
        }
		loopnum++;
    }
    
    if(LargeStraight == 5)
    {
	    cout<<"\nLarge Straight"<<endl;
    }
    else if(SmallStraight>=4)
    {
	    cout<<"\nSmall Straight"<<endl;		
    }
    else if(FullHouse == 5)
    {
	    cout<<"\nFull House"<<endl;		
    }
    else if(CPPSlam == 1)
    {
	    cout<<"\nC++Slam!"<<endl;		
    }
    else if(ofAKind == 4)
    {
	    cout<<"\nFour of a Kind"<<endl;		
    }
    else if(ofAKind == 3)
    {
	    cout<<"\nThree of a Kind"<<endl;		
    }
    else if(TwoPair == 2)
    {
	    cout<<"\nTwo Pair"<<endl;		
    }
    else
    {
	    cout<<"\nYou have nothing"<<endl;
    }
}

std::string PrintManyCheck(vector<int>HowMany)
{
    ///////////////////////
	int FullHouse = 0;
	int TwoPair = 0;
	int CPPSlam = 0;
	int LargeStraight = 0;
	int SmallStraight = 0;
	int ofAKind = 0;
    std::string Result;
    ///////////////////////
    int loopnum = 0;
    for(int w: HowMany)
    {
	    if(HowMany[loopnum] == 3)
        {
            FullHouse = FullHouse+3;
        }
        if(HowMany[loopnum] == 2)
        {
            FullHouse = FullHouse+2;
            TwoPair++;
        }
        if(HowMany[loopnum] == 5)
        {
            CPPSlam++;
        }
        
        if(HowMany[loopnum] == 1)
        {
            LargeStraight++;
        }
        else if((HowMany[loopnum] == 0) && (LargeStraight > 0) && (LargeStraight < 5))
        {
            LargeStraight = 0;
        }
        
        if(HowMany[loopnum] >= 1)
        {
            SmallStraight++;
        }
        else if((HowMany[loopnum] == 0) && (SmallStraight >= 0) && (SmallStraight < 4))
        {
            SmallStraight = 0;
        }
        
        if(HowMany[loopnum] == 4)
        {
            ofAKind = 4;
        }
        
        if(HowMany[loopnum] == 3)
        {
            ofAKind = 3;
        }
		loopnum++;
    }
    
    if(LargeStraight == 5)
    {
	    Result = "Large Straight";
    }
    else if(SmallStraight>=4)
    {
	    Result = "Small Straight"; 		
    }
    else if(FullHouse == 5)
    {
	    Result = "Full House"; 	
    }
    else if(CPPSlam == 1)
    {
	    Result = "C++Slam!"; 	
    }
    else if(ofAKind == 4)
    {
	    Result = "Four of a Kind"; 
    }
    else if(ofAKind == 3)
    {
	    Result = "Three of a Kind"; 		
    }
    else if(TwoPair == 2)
    {
	    Result = "Two Pair"; 	
    }
    else
    {
	    Result = "You have nothing";
    }
    return Result;
}

void RollDice(vector<int>&Dice)//Generateenough random numbers to fill the vector back to the number of dice being used.  Use push_back()to add each die value to the vector.
{
    int counter = 0;
    int rand;
    for(int it:Dice)
        counter++;
	
    int i;
    for(i = 0; i < dice-counter; i++)
    {
        rand = std::rand()%faces + 1;
		Dice.push_back(rand);
    }
/*
    int i;
    for(i = dice; i > 0; i--)
    {
        Dice.erase(Dice.begin()+(i-1));
    }
        
	i = 0;
	int low = 1;
	
	int rand;
	
	while(i < dice)
	{
		rand = std::rand()%faces + 1;
		Dice.push_back(rand);
		i++;
	}
*/
}

void PrintRoll(vector<int>Dice)//Prints the value of the dice (as shown in the video)using a range based for loop.
{
    cout<< "   ";
	for(auto it:Dice)
		cout<<it<<" ";

    cout<<endl;
}

void FillHowMany(vector<int>Dice, vector<int>&HowMany)
{
/*
    int counter0 = 0;
    for(int x: HowMany)
        {
            HowMany[counter0] = 0;
        }
    cout<< "\n";
*/
/*
    for(int x: HowMany)
    {
        HowMany.erase(HowMany.begin());
        HowMany.push_back(0);
    }
*/

    for(int &x: HowMany)
    {
        x = 0;
    }

    for(int k: Dice)
    {
        HowMany[k-1]++;
    }

    
/*
    int counter0 = 0;
    for(int x: HowMany)
        {
            HowMany[counter0] = 0;
        }
    cout<< "\n";

    int counter;
    int counter1;
    int counter2 = 1;
	for(int j: HowMany)
	{
        counter = 0;
        counter1 = 0;
        if(counter2 < faces)
        {
		    for(int k: Dice)
		    {
			    if(Dice[counter1] == counter2)
			    {
                    counter++;
				    HowMany[counter2] = counter;
			    }
            counter1++;
		    }
        }
        cout<<counter2 << ": This Many --> "<<HowMany[counter2-1]<<endl;
        counter2++;
	}
*/
//    cout<< "\n";
//    for(auto it:HowMany)
//		cout<<it<<" ";
}

void PickDice(vector<int>&Dice)//Print instructions on picking which diceto keep and which to reroll.  Prompts user for each die and uses erase()to remove a die from the dice vector.
{
	int i;
	char userInput;
    vector<int>HowMany(faces);
	cout<<"\nPick which dice to reroll. Answer Y at the prompt to keep that die."<<endl;
	srand((unsigned)time(NULL));
    ///////////////////////
	int FullHouse = 0;
	int TwoPair = 0;
	int CPPSlam = 0;
	int LargeStraight = 0;
	int SmallStraight = 0;
	int ofAKind = 0;
    int j;
    ///////////////////////
	for(i = dice; i > 0; i--)
	{
		cout<<"\nKeep " << Dice.at(i-1) <<"? ";
		cin>>userInput;
		getchar();
	
		if(userInput != 'y')
		{
			Dice.erase(Dice.begin()+(i-1));
            RollDice(Dice);
//			Dice.push_back(std::rand()%faces + 1);
		}
	}
    RollDice(Dice);
    cout<<"\nYou rolled ";
    PrintRoll(Dice);
    FillHowMany(Dice, HowMany);
    cout<<"\n"<<PrintManyCheck(HowMany)<<endl;

}

