#include <iostream>
#include <random>
#include <vector>
using namespace std;

int simulation();

int main(){
	int count;
	int one_count = 0;
	int two_count = 0;
	int three_count = 0;
	int four_count = 0;
	int five_count = 0;
	int six_count = 0;
	int seven_count = 0;
	int eight_count = 0;
	int nine_count = 0;
	for (int i = 0; i < 200; i++)
	{
		count = simulation();
		if (count == 1)
			one_count++;
		else if (count == 2)
			two_count++;
		else if (count == 3)
			three_count++;
		else if (count == 4)
			four_count++;
		else if (count == 5)
			five_count++;
		else if (count == 6)
			six_count++;
		else if (count == 7)
			seven_count++;
		else if (count == 8)
			eight_count++;
		else if (count == 9)
			nine_count++;
		cout << "count " << count << endl;
	}
		cout << "two count " << two_count << endl;
		cout << "three count " << three_count << endl;
		cout << "four count " << four_count << endl;
		cout << "five count " << five_count << endl;
		cout << "six count " << six_count << endl;
		cout << "seven count " << seven_count << endl;
		cout << "eight count " << eight_count << endl;
		cout << "nine count " << nine_count << endl;
	return 0;
}

int roll(){
	random_device rd;
    mt19937 gen(rd());
    
    uniform_int_distribution<int> distribution(1, 6);

    int roll = distribution(gen);
    
	return roll;
}


int run(int col_1, int col_2, int col_3){
	int num = 0;
	double prob;
	for (int dice_1 = 1; dice_1 < 7; dice_1++){
		for (int dice_2 = 1; dice_2 < 7; dice_2++){
			for (int dice_3 = 1; dice_3 < 7; dice_3++){
				for (int dice_4 = 1; dice_4 < 7; dice_4++){
					if (((dice_1 + dice_2 != col_1 && dice_1 + dice_2 != col_2 && dice_1 + dice_2 != col_3) && (dice_3 + dice_4 != col_1 && dice_3 + dice_4 != col_2 && dice_3 + dice_4 != col_3)) &&
						((dice_1 + dice_3 != col_1 && dice_1 + dice_3 != col_2 && dice_1 + dice_3 != col_3) && (dice_2 + dice_4 != col_1 && dice_2 + dice_4 != col_2 && dice_2 + dice_4 != col_3)) &&
						((dice_1 + dice_4 != col_1 && dice_1 + dice_4 != col_2 && dice_1 + dice_4 != col_3) && (dice_2 + dice_3 != col_1 && dice_2 + dice_3 != col_2 && dice_2 + dice_3 != col_3)))
						num++;
				}
			}
		}
	}
	return num;
}

int same(int dice_1, int dice_2, int dice_3, int dice_4){
	int res = 0;

	if (dice_1 + dice_2 == dice_3 + dice_4)
		res = 12;
	else if (dice_1 + dice_3 == dice_3 + dice_4)
		res = 13;
	else if (dice_1 + dice_4 == dice_2 + dice_3)
		res = 14;
	
	return res;
}

int pick_sum(int sum_onetwo, int sum_onethree, int sum_onefour, int sum_twothree, int sum_twofour, int sum_threefour){

	vector<int> results;
	results.push_back(sum_onetwo);
	results.push_back(sum_onethree);
	results.push_back(sum_onefour);
	results.push_back(sum_twothree);
	results.push_back(sum_twofour);
	results.push_back(sum_threefour);
    
	random_device rd;
   	mt19937 gen(rd());
    
    uniform_int_distribution<int> distribution(0, results.size() - 1);
    
    int randomIndex = distribution(gen);
    
    int random = results[randomIndex];

	return random;
}

int simulation(){
	int dice_1;
	int dice_2;
	int dice_3;
	int dice_4;
	
	int col_1 = 0;
	int col_2 = 0;
	int col_3 = 0;

	int duo;
	int tmp;
	int bust_prob = 0;

	int sum_onetwo;
	int sum_onethree;
	int sum_onefour;
	int sum_twothree;
	int sum_twofour;
	int sum_threefour;

	int zero_count = 0;

	for (int i = 0; i < 9; i++){
		dice_1 = roll();
		dice_2 = roll();
		dice_3 = roll();
		dice_4 = roll();

		//game begin;
		sum_onetwo = dice_1 + dice_2;
		sum_onethree = dice_1 + dice_3;
		sum_onefour = dice_1 + dice_4;
		sum_twothree = dice_2 + dice_3;
		sum_twofour = dice_2 + dice_4;
		sum_threefour = dice_3 + dice_4;


		//set the columns if not already set;
		duo = same(dice_1, dice_2, dice_3, dice_4);
		if (duo != 0){
			if (duo == 12){
				if (col_1 == 0)
					col_1 = sum_onetwo;
				else if (col_2 == 0)
					col_2 = sum_onetwo;
				else if (col_3 == 0)
					col_3 = sum_onetwo;
			}
			if (duo == 13){
				if (col_1 == 0)
					col_1 = sum_onethree;
				else if (col_2 == 0)
					col_2 = sum_onethree;
				else if (col_3 == 0)
					col_3 = sum_onethree;
			}
			if (duo == 14){
				if (col_1 == 0)
					col_1 = sum_onefour;
				else if (col_2 == 0)
					col_2 = sum_onefour;
				else if (col_3 == 0)
					col_3 = sum_onefour;
			}
		}

		//picking columns at random from my results;
		if (col_1 == 0)
			col_1 = pick_sum(sum_onetwo, sum_onethree, sum_onefour, sum_twothree, sum_twofour, sum_threefour);
		if (col_2 == 0){
			col_2 = pick_sum(sum_onetwo, sum_onethree, sum_onefour, sum_twothree, sum_twofour, sum_threefour);
			while (col_2 == col_1)
				col_2 = pick_sum(sum_onetwo, sum_onethree, sum_onefour, sum_twothree, sum_twofour, sum_threefour);
		}
		if (col_3 == 0 && (col_1 == 0 || col_2 == 0)){
			col_3 = pick_sum(sum_onetwo, sum_onethree, sum_onefour, sum_twothree, sum_twofour, sum_threefour);
			while (col_3 == col_2 || col_3 == col_2)
				col_3 = pick_sum(sum_onetwo, sum_onethree, sum_onefour, sum_twothree, sum_twofour, sum_threefour);
		}

		if (col_1 == 0 || col_2 == 0 || col_3 == 0)
			zero_count++;
		//cout << col_1 << "  " << col_2 << "  " << col_3 << endl;
		bust_prob = run(col_1, col_2, col_3);
		//cout << i  << ":  " << "bust prob:" << bust_prob << endl;
	}
	return zero_count;
}