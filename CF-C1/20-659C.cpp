#include <bits/stdc++.h>

using namespace std;

const int MAX_TYPE = 1000000000;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w",stderr);
    #endif

    int type, types, money;
    scanf("%d %d", &types, &money);

    vector <int> has, purchased;
    for (int i = 0; i < types; i++) {
        scanf("%d", &type);
        has.push_back(type);
    }
    sort (has.begin(), has.end());

    // greedily choose the toys starting from type 1 if its not already 
    // present, so as to maximize the types with us
    // and also spend the money in that way

    int spent = 0, current_type = 1;
    for (int i = 0; i < types; i ++) {
        bool done = false;
        while (has[i] > current_type) {
            spent += current_type;
            if (spent > money) {
                done = true;
                spent -= current_type;
                break;
            }
            purchased.push_back(current_type);
            current_type ++;
        }
        // now has[i] equals current_type, so increment by 1 for next i
        current_type ++;
    }   

    while (money > spent) {
        spent += current_type;
        if (spent > money) {
            spent -= current_type;
            break;
        }
        purchased.push_back(current_type);
        current_type ++;
    }

    int qty_purchased = purchased.size();
    printf("%d\n", qty_purchased);
    for (int i = 0; i < qty_purchased; i++) {
        printf("%d ", purchased[i]);
    }
    return 0;
}