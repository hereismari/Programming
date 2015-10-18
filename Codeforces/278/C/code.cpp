#include <bits/stdc++.h> 

using namespace std; 

int n, m, x, y;
int h, a, d, HPm, ATKm, DEFm;
int HPy, ATKy, DEFy;


bool verify(int hp, int atk, int deff) {
    int rm = max(0, atk - DEFm);
    int ry = max(0, ATKm - deff);
    if(rm == 0) return false;
    else if(ry == 0) return true;
    else {
        int tm = ceil(HPm / (rm * 1.0));
        int ty = ceil(hp / (ry * 1.0));
        return tm < ty;
    }

}

int ans() {

    int result = INT_MAX;
    for(int hp = 0; hp <= 1000; hp++) {
        for(int atk = 0; atk <= 200; atk++) {
            for(int deff = 0; deff <= 100; deff++){
                int newHP = HPy + hp;
                int newATK = ATKy + atk;
                int newDEF = DEFy + deff;
                int value = hp * h + atk * a + deff * d;
                if(value < result && verify(newHP, newATK, newDEF))
                    result = value;
            }
        }
    }
    return result;
}

int main() {

    scanf("%d %d %d", &HPy, &ATKy, &DEFy);
    scanf("%d %d %d", &HPm, &ATKm, &DEFm);
    scanf("%d %d %d", &h, &a, &d);

    printf("%d\n", ans());

	return 0; 
}
