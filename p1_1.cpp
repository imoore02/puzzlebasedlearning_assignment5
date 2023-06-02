#include <iostream>
using namespace std;

void p1();

int main(){
	p1();
	return 0;
}

void p1(){
	int num = 0;
	double prob;
	for (int dice_1 = 1; dice_1 < 7; dice_1++){
		for (int dice_2 = 1; dice_2 < 7; dice_2++){
			for (int dice_3 = 1; dice_3 < 7; dice_3++){
				for (int dice_4 = 1; dice_4 < 7; dice_4++){
					if (((dice_1 + dice_2 != 3 && dice_1 + dice_2 != 8 && dice_1 + dice_2 != 11) && (dice_3 + dice_4 != 3 && dice_3 + dice_4 != 8 && dice_3 + dice_4 != 11)) &&
						((dice_1 + dice_3 != 3 && dice_1 + dice_3 != 8 && dice_1 + dice_3 != 11) && (dice_2 + dice_4 != 3 && dice_2 + dice_4 != 8 && dice_2 + dice_4 != 11)) &&
						((dice_1 + dice_4 != 3 && dice_1 + dice_4 != 8 && dice_1 + dice_4 != 11) && (dice_2 + dice_3 != 3 && dice_2 + dice_3 != 8 && dice_2 + dice_3 != 11)))
						num++;
				}
			}
		}
	}
	cout << "num:  " << num << endl;
}