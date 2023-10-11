#include <iostream>
#include <vector>
#include <time.h>
#include <thread>
#include <chrono>
#include <atomic>

const int mineIterations = 100000;

using namespace std;

void mineXryuCoin(atomic<float>* coin){
    while(*coin <=1){
        for(int i = 0; i < mineIterations; i++);
        // atomic_fetch_add(coin, 0.01);
        coin->fetch_add(0.01);
    }
}

int main(){
    // ���������� �������� �� ������ ��������
    atomic<float> xryu_coin = 0.0;
    
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
        double deltaTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
        
        cout << "���-�� �������: " << threadsAmount[j] << ", ������ ��� �������� 1 ��������: " << deltaTime << " ������." << endl;
        cout << "���� �� �������-�������������: " << deltaTime*1000000 << endl;
        xryu_coin = 0.0;
    }
    
    return 0;
}