#include "stdio.h"
#include <vector>
#include <list>

#define STONE_MAX 3;

class Stone
{
public:

	int s_No;	//大きさ	大きいと数字でかい
	Stone::Stone(int No)
	{
		s_No = No;
	}
	Stone::Stone()
	{
	}
	Stone::~Stone()
	{
	}

};

class Tower {

public:
	Tower::Tower(int s_No)
	{
		Tower_No = s_No;
	}

	Tower::~Tower()
	{
	}

	std::vector <Stone> stone;
	int Tower_No;
	void select();
	void draw();
};

void Tower::select() {
	printf("\n\n");
}
void Tower::draw() {
	printf("\n");

}

std::vector <Tower> Tow;


void Set_Stone(std::vector<Tower> &Tow) {

	//石の生成
	int stonemax = STONE_MAX;
	for (int i = 1; i <= stonemax; i++) {
		Stone X(i);
		Tow[0].stone.push_back(X);	//※push frontもあるよ！前から！
	}

}

void Draw_Tower(std::vector<Tower> &Tow) {

	system("cls");
	printf("\n\n\n");
	int stoneman = STONE_MAX;
	for (int i = 1; i <= stoneman; i++) {
		printf("   ");

		for (std::vector<Tower>::iterator iter = (Tow).begin(); iter != (Tow).end();) {
			int count = 0;
			int depth = 0;
			for (std::vector<Stone>::iterator s_iter = (iter->stone).begin(); s_iter != (iter->stone).end();) {
				int depth_max = (iter->stone).size();
				int dep = (depth_max + 1) - STONE_MAX;
				if (i >= dep) {
					depth++;
					if (i == depth) {
						count = s_iter->s_No;
						break;
					}
				}
				else
					break;

				s_iter++;
			}
			if (count == NULL) {
				printf("    | ");
			}

			else {
				printf(" %d ", count);
			}

			iter++;
		}

		printf("\n");
	}
}
//どこからどこへ　何個	移動回数
void move(Tower &from, Tower &to, int const n, int &count) {



	Draw_Tower(Tow);

	//move(Tow[0], Tow[2], n, count);

}

void main() {
	//塔の生成
	for (int i = 1; i <= 3; i++) {
		Tower X(i);
		Tow.push_back(X);	//※push frontもあるよ！前から！
	}

	//塔に石を刺す♂
	Set_Stone(Tow);

	int n = STONE_MAX;
	int count = 0;
	move(Tow[0], Tow[2], n, count);

	printf("\n\n\n   count %d", count);
	getchar();

}