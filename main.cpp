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
    
    // ������ ������ ������� ����� �������
    for(size_t j = 0; j < threadsAmount.size(); j++){
        vector<thread> threads;
        // ��������� ������
        for(int k = 0; k <threadsAmount[j]; k++){
            threads.emplace_back(mineXryuCoin, &(xryu_coin));
        }

        // ����� �������
        clock_t startTime = clock();
        // ����������� �������
        for(thread& th: threads){
            th.join();
        }
        // ����� �������
        clock_t endTime = clock();
        // ����� ��� �������� 1 ��������
        double deltaTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
        
        cout << "���-�� �������: " << threadsAmount[j] << ", ������ ��� �������� 1 ��������: " << deltaTime << " ������." << endl;
        cout << "���� �� �������-�������������: " << deltaTime*1000000 << endl;
        xryu_coin = 0.0;
    }
    
    return 0;
}