#include <iostream>
#include <vector>
#include <time.h>
#include <thread>
#include <chrono>

const int mineIterations = 100000;

using namespace std;

void mineXryuCoin(float* coin){
    while(*coin <=1){
        for(int i = 0; i < mineIterations; i++);
        *coin+=0.01;
    }
}

int main(){
    // ���������� �������� �� ������ ��������
    float xryu_coin = 0.0;
    
    //������ ���������� ����� �������
    vector<int> threadsAmount = {1, 2, 4};
    
    return 0;
}